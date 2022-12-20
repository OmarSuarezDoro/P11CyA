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

typedef int coin;

class ProgramInterface {
 public:
  ProgramInterface(int argc, char* argv[]);
  std::list<int> Change() const;
  std::list<int> Change2() const;
  void error_manager(const std::string& error) const;
  friend std::ostream& operator<<(std::ostream& os, const ProgramInterface& program);
 private:
  double to_exchange_;
  bool option_b_;
  bool option_o_;
};

