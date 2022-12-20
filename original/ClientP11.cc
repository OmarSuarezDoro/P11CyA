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
 * Archivo ClientP11.cc: Programa cliente
 */

#include "ProgramInterface.h"

int main(int argc, char* argv[]) {
  ProgramInterface program{argc, argv};
  std::cout << "Solution:" << std::endl;
  std::cout << program << std::endl;
  std::cout << " [i] EXIT PROGRAM.." << std::endl;
  return 0;
}