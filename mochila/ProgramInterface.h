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
 * Archivo ProgramInterface.h: Definición de la clase ProgramInterface
 */

#include <list>
#include <iostream>
#include <sstream>
#include <vector>

#pragma once

typedef int moneda;

class ProgramInterface {
 public:
  ProgramInterface(int argc, char* argv[]);
  void error_manager(const std::string& error) const;
  friend std::ostream& operator<<(std::ostream& os, const ProgramInterface& program);
  std::vector<double> Bag(double max_weight, const std::vector<double>& weigth_vector, const std::vector<double>& value_vector) const;
 private:
  double max_weigth_;
};

