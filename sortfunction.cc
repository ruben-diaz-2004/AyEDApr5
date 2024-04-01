/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Computabilidad y Algoritmia 2023-2024
  *
  * @author Rubén Díaz Marrero 
  * @date 19/02/2024
  * @brief ordenación
  */



#include <iostream>
#include "nif.h"
#include "staticsequence.h"


// Plantilla de función de ordenación SortFunction<key> (staticsequence<key>, size)


template <class key>
void SelectionSortFunction(Sequence<key>& sequence, int size) {
  for (int i{0}; i < size - 1; ++i) {
    int min_index{i};
    for (int j{i + 1}; j < size; ++j) {
      if (sequence[j] < sequence[min_index]) {
        min_index = j;
      }
    }
    Nif aux = sequence[min_index];
    sequence[min_index] = sequence[i];
    sequence[i] = aux;
  }
}


// template <class key>
// void QuickSortFunction(StaticSequence<key> sequence, int size) {
//   // Implementación de la función de ordenación
// }


// template <class key>
// void HeapSortFunction(StaticSequence<key> sequence, int size) {
//   // Implementación de la función de ordenación
// }


// template <class key>
// void ShellSortFunction(StaticSequence<key> sequence, int size) {
//   // Implementación de la función de ordenación
// }


// template <class key>
// void RadixSortFunction(StaticSequence<key> sequence, int size) {
//   // Implementación de la función de ordenación
// }







