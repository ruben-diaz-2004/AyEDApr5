/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Computabilidad y Algoritmia 2023-2024
  *
  * @author Rubén Díaz Marrero 
  * @date 15/03/2024
  * @brief Búsqueda mediante tablas de dispersión
  */


#ifndef STATICSEQUENCE_H
#define STATICSEQUENCE_H


#include <iostream>
#include "sequence.h"
#include <fstream>
#include <ctime>

template <class key>
class StaticSequence : public Sequence<key> {
 public:
  StaticSequence(int size, int mode);
  StaticSequence(int size, std::fstream& filename);
  ~StaticSequence();
  key operator[](const int& pos) const { return data_[pos]; }
  bool Search(const key& k) const override;
  bool Insert(const key& k) override;
  void Print() const;
  bool IsFull() const; 

  private:
  unsigned size_;
  key* data_;
};


/**
 * @brief Constructor de la clase StaticSequence
*/
template <class key>
StaticSequence<key>::StaticSequence(int size, int mode) {
  long clave;
  if (mode == 0) { // Inicializa la secuencia manualmente
    size_ = size;
    data_ = new key[size_];
    key* clave_a_introducir;
    for (unsigned i = 0; i < size_; i++) {
      std::cin >> clave;
      clave_a_introducir = new key(clave);
      data_[i] = *clave_a_introducir;
    }
  } else if (mode == 1) { // Inicializa la secuencia con números aleatorios
    size_ = size;
    data_ = new key[size_];
    key* clave_aleatoria;
    srand(time(NULL));
    for (unsigned i = 0; i < size_; i++) {
      clave = rand();
      clave_aleatoria = new key(clave);
      data_[i] = *clave_aleatoria;
    }
  } else {
    std::cerr << "Error: modo no válido" << std::endl; 
  } 
}


/**
 * @brief Constructor de la clase StaticSequence
*/
template <class key>
StaticSequence<key>::StaticSequence(int size, std::fstream& filename) {
  size_ = size;
  data_ = new key[size_];
  long clave;
  key* clave_a_introducir;
  for (unsigned i = 0; i < size_; i++) {
    filename >> clave;
    clave_a_introducir = new key(clave);
    data_[i] = *clave_a_introducir;
  }
}

/**
 * @brief Destructor de la clase StaticSequence
*/
template <class key>
StaticSequence<key>::~StaticSequence() {
  delete[] data_;
}


/**
 * @brief Busca un elemento en la secuencia
 * @param k Clave a buscar
 * @return true si se ha encontrado, false en caso contrario
*/
template <class key>
bool StaticSequence<key>::Search(const key& k) const {
  for (unsigned i = 0; i < size_; i++) {
    if (data_[i] == k) {
      return true;
    }
  }
  return false;
}


/**
 * @brief Inserta un elemento en la secuencia
 * @param k Clave a insertar
 * @return true si se ha insertado, false en caso contrario
*/
template <class key>
bool StaticSequence<key>::Insert(const key& k) {
  if (IsFull()) {
    return false;
  }
  for (unsigned i = 0; i < size_; i++) {
    if (data_[i] == k) {
      return false;
    }
  }
  for (unsigned i = 0; i < size_; i++) {
    if (long(data_[i]) == 0) {
      data_[i] = k;
      return true;
    }
  }
  return false;
}


/**
 * @brief Imprime la secuencia
*/
template <class key>
void StaticSequence<key>::Print() const {
  for (unsigned i = 0; i < size_; i++) {
    std::cout << data_[i] << " ";
  }
  std::cout << std::endl;
}


/**
 * @brief Comprueba si la secuencia está llena
 * @return true si está llena, false en caso contrario
*/
template <class key>
bool StaticSequence<key>::IsFull() const {
  for (unsigned i = 0; i < size_; i++) {
    if (long(data_[i]) == 0) {
      return false;
    }
  }
  return true;
}


#endif  // STATICSEQUENCE_H