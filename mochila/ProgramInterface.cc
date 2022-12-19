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

/**
 * @brief: This method manage the erros, that the program could has
 * @param error : The message with the error that is going to be printed
 */
void ProgramInterface::error_manager(const std::string& error) const {
  std::cerr << error << std::endl;
  exit(EXIT_FAILURE);
}

/**
 * @brief: The constructor of the class.
 * @param argc: number of parameters
 * @param argv: The vector with parameters
 */
ProgramInterface::ProgramInterface(int argc, char* argv[]) {
  std::stringstream input_stream;
  std::string aux_string{argv[1]};
  try {
    std::stod(aux_string);
  } catch (const std::invalid_argument& exception) {
    error_manager("[-] Argumento introducido no numérico.");
  }
  max_weigth_ = std::stod(argv[1]);
}

/**
 * @brief: Operator << overcharge.
 * @param os: Output stream
 * @param program: The object program that is going to be printed, depend
 *                 on the option_o_ value.
 * @return The modified output stream.
 */
std::ostream& operator<<(std::ostream& os, const ProgramInterface& program) {
  std::vector<double> test1 = {10, 20, 30, 40, 50};
  std::vector<double> test2 = {20, 30, 66, 40, 60};
  int counter{0};
  for (const auto& element : program.Bag(program.max_weigth_, test1, test2)) {
    std::cout << counter << " -> " << element << std::endl;
    counter++;
  }
  return os;
}


std::vector<double> ProgramInterface::Bag(double max_weight, const std::vector<double>& weigth_vector, const std::vector<double>& value_vector) const {
  std::vector<double> result(weigth_vector.size(), 0);
  std::vector<double> value_vector_copy = value_vector;
  double weight{0};
  int i;
  int pos;
  int size_value_vector{value_vector.size()};
  double max_val;
  while (weight < max_weight) {
    max_val = 0;
    for (i = 0; i < size_value_vector; ++i) {
      if ((value_vector_copy[i] / weigth_vector[i]) > max_val) {
        pos = i;
        max_val = value_vector_copy[i] / weigth_vector[i];
      }
    }
    if (weight + weigth_vector[pos] <= max_weight) {
      result[pos] = 1; 
      weight += weigth_vector[pos];
      value_vector_copy[pos] = 0;
    } else {
      result[pos] = (max_weight - weight) / weigth_vector[pos];
      weight = max_weight;
    }
  }
  return result;
}

/*
std::vector<double> ProgramInterface::Bag(double max_weight, const std::vector<double>& weigth_vector, const std::vector<double>& value_vector) const {
  std::vector<double> result(weigth_vector.size(), 0);
  std::vector<double> value_vector_copy = value_vector;
  double weight{0};
  int i;
  int pos;
  int size_value_vector{value_vector.size()};
  double max_val;
  while (weight < max_weight) {
    max_val = 0;
    for (i = 0; i < size_value_vector; ++i) {
      if (value_vector_copy[i] > max_val) {
        pos = i;
        max_val = value_vector_copy[i];
      }
    }
    if (weight + weigth_vector[pos] <= max_weight) {
      result[pos] = 1; 
      weight += weigth_vector[pos];
      value_vector_copy[pos] = 0;
    } else {
      result[pos] = (max_weight - weight) / weigth_vector[pos];
      weight = max_weight;
    }
  }
  return result;
}
*/