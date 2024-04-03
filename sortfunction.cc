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
void SelectionSortFunction(StaticSequence<key>& sequence, int size) {
  for (int i{0}; i < size - 1; ++i) {
    int min_index{i};
    for (int j{i + 1}; j < size; ++j) {
      if (sequence[j] < sequence[min_index]) {
        min_index = j;
      }
    }
    key aux = sequence[min_index];
    // sequence[min_index] = sequence[i];
    // sequence[i] = aux;
    sequence.data(min_index, sequence[i]);
    sequence.data(i, aux);
    sequence.Print();
  }
}


template <class key>
void QuickSortFunction(StaticSequence<key>& sequence, int ini, int fin) {
  int i{ini};
  int f{fin};
  key pivot = sequence[(i + f) / 2];
  while (i <= f) {
    while (sequence[i] < pivot) {
      ++i;
    }
    while (sequence[f] > pivot) {
      --f;
    }
    if (i <= f) {
      key aux = sequence[i];
      sequence.data(i, sequence[f]);
      sequence.data(f, aux);
      ++i;
      --f;
    }
  }
  if (ini < f) {
    QuickSortFunction(sequence, ini, f);
  }
  if (i < fin) {
    QuickSortFunction(sequence, i, fin);
  }


}

template <class key>
void baja(int i, StaticSequence<key>& Sequence, int n) {
  int h1, h2, h;
  while (2*i <= n) {
    h1 = 2*i;
    h2 = h1 + 1;
    if (h1 == n) {
      h = h1;
    } else if (Sequence[h1] > Sequence[h2]) {
      h = h1;
    } else {
      h = h2;
    }
    if (Sequence[h] <= Sequence[i]) {
      break;
    } else {
      key aux = Sequence[i];
      Sequence.data(i, Sequence[h]);
      Sequence.data(h, aux);
      i = h;
    }
  }
}


template <class key>
void HeapSortFunction(StaticSequence<key>& sequence, int n) {
  for (int i = n/2; i >= 0; --i) {
    baja(i, sequence, n);
  }
  for (int i = n; i >= 2; --i) {
    key aux = sequence[1];
    sequence.data(1, sequence[i]);
    sequence.data(i, aux);
    baja(1, sequence, i-1);
  }
}


// template <class key>
// void ShellSortFunction(StaticSequence<key> sequence, int size) {
//   // Implementación de la función de ordenación
// }


// template <class key>
// void RadixSortFunction(StaticSequence<key> sequence, int size) {
//   // Implementación de la función de ordenación
// }







