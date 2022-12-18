#include <list>
#include <iostream>
#include <sstream>
#include <vector>

typedef int moneda;


void error_manager(const std::string& error) {
  std::cout << error << std::endl;
  exit(EXIT_FAILURE);
}

std::list<std::pair<int, int>> devolver_cambio2(int cambio, bool option_b) {
  int sum{0};
  std::vector<moneda> vector_de_monedas = {200, 100, 50, 20, 10, 5, 2, 1};
  if (option_b) {
    vector_de_monedas = {50000, 20000, 10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
  }
  int cantidad_de_monedas{0};
  std::list<std::pair<int,int>> result;  
  for (const auto& moneda : vector_de_monedas) {
    cantidad_de_monedas = (cambio - sum) / moneda;
    if (cantidad_de_monedas > 0) {
      result.push_back({moneda, cantidad_de_monedas});
      sum += cantidad_de_monedas * moneda;
    } 
  }    
  return result;
}

std::list<int> devolver_cambio(int cambio, bool option_b) {
  int sum{0};
  std::list<int> result;  
  std::vector<moneda> vector_de_monedas = {200, 100, 50, 20, 10, 5, 2, 1};
  if (option_b) {
    vector_de_monedas = {50000, 20000, 10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
  }
  while (sum != cambio) {
    int v{0};
    for (const auto& moneda : vector_de_monedas) {
      if (moneda + sum <= cambio) {
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
int main(int argc, char* argv[]) {
  std::stringstream input_stream;
  double quantity_to_change;
  int counter_param{1};
  bool option_b{false};
  bool option_o{false};
  std::vector<double> param;
  if (argc > 4) {
    error_manager("[-] Número de parámetros incorrecto.");
  }
  while (argv[counter_param] != NULL) {
    std::string aux_string = argv[counter_param];
    if (aux_string.front() == '-') {
      aux_string == "-o" ? option_o = 1 : option_o;
      aux_string == "-b" ? option_b = 1 : option_b;
      ++counter_param;
      if (!option_b && !option_o) {
        error_manager("[-] Formato de Input incorrecto.");
      }
      continue;
    }
    if (param.size() == 0) {
      input_stream << aux_string;
      input_stream >> quantity_to_change;
      param.push_back(quantity_to_change);
      ++counter_param;
      continue; 
    }
    error_manager("[-] Formato de Input incorrecto.");
  }
  if (option_o) {
    for (const auto& moneda : devolver_cambio2(quantity_to_change * 100, option_b)) {
      std::cout << ((moneda.first / 100) > 0 ? moneda.first / 100 : moneda.first) << ((moneda.first / 100) > 0 ? "€" : "c") ;
      if (moneda.second != 1) {
        std::cout << "x" << moneda.second;
      }
      std::cout << " ";
    }
    std::cout << std::endl;
  } else {
    std::list<int> aux_list = devolver_cambio(quantity_to_change * 100, option_b);
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
    std::cout << std::endl;
  }
  return 0;
}