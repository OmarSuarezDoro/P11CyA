/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 11: Cambio de monedas
 * Autor: Omar Suárez Doro
 * Correo: alu0101483474@ull.es
 * Fecha: 19/12/2022
 * Archivo ProgramInterface.cc: Definición de métodos clase ProgramInterface
 */

#include "ProgramInterface.h"

void ProgramInterface::error_manager(const std::string& error) const {
  std::cout << error << std::endl;
  exit(EXIT_FAILURE);
}

std::list<std::pair<int, int>> ProgramInterface::devolver_cambio2() const {
  int sum{0};
  std::vector<moneda> vector_de_monedas = {200, 100, 50, 20, 10, 5, 2, 1};
  if (option_b_) {
    vector_de_monedas = {50000, 20000, 10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
  }
  int cantidad_de_monedas{0};
  std::list<std::pair<int,int>> result;  
  for (const auto& moneda : vector_de_monedas) {
    cantidad_de_monedas = ((to_exchange_ * 100) - sum) / moneda;
    if (cantidad_de_monedas > 0) {
      result.push_back({moneda, cantidad_de_monedas});
      sum += cantidad_de_monedas * moneda;
    } 
  }    
  return result;
}

std::list<int> ProgramInterface::devolver_cambio() const {
  int sum{0};
  int exchange = to_exchange_ * 100;
  std::list<int> result;  
  std::vector<moneda> vector_de_monedas = {200, 100, 50, 20, 10, 5, 2, 1};
  if (option_b_) {
    vector_de_monedas = {50000, 20000, 10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
  }
  while (sum != exchange) {
    int v{0};
    for (const auto& moneda : vector_de_monedas) {
      if (moneda + sum <= exchange) {
        v = moneda;
        break;
      }
    }
    if (v == 0) {error_manager("[-] No existe solución.");}
    result.push_back(v);
    sum += v;
  }
  return result;
}


ProgramInterface::ProgramInterface(int argc, char* argv[]) {
  std::stringstream input_stream;
  to_exchange_ = 0;
  option_b_ = false;
  option_o_ = false;
  int counter_param{1};
  std::vector<double> param;
  if (argc > 4) {
    error_manager("[-] Número de parámetros incorrecto.");
  }
  std::string aux_string;
  while (argv[counter_param] != NULL) {
    aux_string = argv[counter_param];
    if (aux_string.front() == '-') {
      aux_string == "-o" ? option_o_ = 1 : option_o_;
      aux_string == "-b" ? option_b_ = 1 : option_b_;
      ++counter_param;
      if (!option_b_ && !option_o_) {
        error_manager("[-] Formato de Input incorrecto.");
      }
      continue;
    }
    if (param.size() == 0) {
      try {
        std::stod(aux_string);
      } catch (const std::invalid_argument& exception) {
        error_manager("[-] Argumento introducido no numérico.");
      }
      input_stream << aux_string;
      input_stream >> to_exchange_;
      param.push_back(to_exchange_);
      ++counter_param;
      continue; 
    }
    error_manager("[-] Formato de Input incorrecto.");
  }
}


std::ostream& operator<<(std::ostream& os, const ProgramInterface& program) {
  if (program.option_o_) {
    for (const auto& moneda : program.devolver_cambio2()) {
      std::cout << ((moneda.first / 100) > 0 ? moneda.first / 100 : moneda.first) << ((moneda.first / 100) > 0 ? "€" : "c") ;
      if (moneda.second != 1) {
        std::cout << "x" << moneda.second;
      }
      std::cout << " ";
    }
  } else {
    std::list<int> aux_list = program.devolver_cambio();
    std::list<int> aux_list_uniq = aux_list;
    aux_list_uniq.unique();
    std::vector<int> aux_vector(aux_list.size());
    for (const auto& tipo_de_moneda : aux_list_uniq) {
      int contador = 0;
      for (const auto& moneda : aux_list) {
        if (tipo_de_moneda == moneda) {
          ++contador; 
        }
      } 
      std::cout << ((tipo_de_moneda / 100) > 0 ? tipo_de_moneda / 100 : tipo_de_moneda)  << ((tipo_de_moneda / 100) > 0 ? "€" : "c");
      if (contador != 1) {
        std::cout << "x" << contador;
      }
      std::cout << " ";
    }
  }
  return os;
}
