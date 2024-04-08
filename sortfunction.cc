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


/**
 * @brief Función que intercambia dos elementos de un vector
 * @param sequence Vector de elementos
 * @param i Índice del primer elemento
 * @param j Índice del segundo elemento
*/
template <class key>
void Swap(StaticSequence<key>& sequence, int i, int j) {
  key aux = sequence[i];
  sequence.data(i, sequence[j]);
  sequence.data(j, aux);
}


/**
 * @brief Función que implementa el algoritmo de ordenación por selección
 * @param sequence Vector de elementos
 * @param size Tamaño del vector
 * @param trace Indica si se debe mostrar el vector en cada paso
*/
template <class key>
void SelectionSortFunction(StaticSequence<key>& sequence, int size, bool trace) {
  for (int i{0}; i < size - 1; ++i) {
    int min_index{i};
    for (int j{i + 1}; j < size; ++j) {
      if (sequence[j] < sequence[min_index]) {
        min_index = j;
      }
    }
    // key aux = sequence[min_index];
    // sequence.data(min_index, sequence[i]);
    // sequence.data(i, aux);
    Swap(sequence, min_index, i);
    if (trace) sequence.Print();
  }
}



/**
 * @brief Función que implementa el algoritmo de ordenación quick sort
 * @param sequence Vector de elementos
 * @param ini Índice del primer elemento
 * @param fin Índice del último elemento
 * @param trace Indica si se debe mostrar el vector en cada paso
*/
template <class key>
void QuickSortFunction(StaticSequence<key>& sequence, int ini, int fin, bool trace) {
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
      // key aux = sequence[i];
      // sequence.data(i, sequence[f]);
      // sequence.data(f, aux);
      Swap(sequence, i, f);
      ++i;
      --f;
    }
  }
  if (ini < f) {
    QuickSortFunction(sequence, ini, f, trace);
  }
  if (i < fin) {
    QuickSortFunction(sequence, i, fin, trace);
  }
  if (trace) sequence.Print();
}



/**
 * @brief Función auxiliar para el algoritmo de ordenación heap sort
 * @param sequence Vector de elementos
 * @param n Tamaño del vector
*/
template <class key>
void baja(int i, StaticSequence<key>& Sequence, int n) {
  int h1, h2, h;
  while (2*i + 1 <= n) {
    h1 = 2*i + 1;
    h2 = h1 + 1;
    if (h1 == n || Sequence[h1] > Sequence[h2]) {
      h = h1;
    } else {
      h = h2;
    }
    if (Sequence[h] <= Sequence[i]) {
      break;
    } else {
      Swap(Sequence, i, h);
      i = h;
    }
  }
}


/**
 * @brief Función que implementa el algoritmo de ordenación heap sort
 * @param sequence Vector de elementos
 * @param n Tamaño del vector
 * @param trace Indica si se debe mostrar el vector en cada paso
*/
template <class key>
void HeapSortFunction(StaticSequence<key>& sequence, int n, bool trace) {
  for (int i = n/2 - 1; i >= 0; --i) {
    baja(i, sequence, n - 1);
  }
  for (int i = n - 1; i > 0; --i) {
    Swap(sequence, 0, i);
    baja(0, sequence, i-1);
    if (trace) sequence.Print();
  }
}



/**
 * @brief Función que implementa el algoritmo de ordenación shell sort
 * @param sequence Vector de elementos
 * @param size Tamaño del vector
 * @param trace Indica si se debe mostrar el vector en cada paso
*/
template <class key>
void ShellSortFunction(StaticSequence<key>& sequence, int size, bool trace) {
  double alpha;
  std::cout << "Introduce el valor de alpha (0 < alpha < 1): ";
  std::cin >> alpha;
  if (alpha <= 0 || alpha >= 1) {
    std::cerr << "Error: alpha debe ser un valor entre 0 y 1" << std::endl;
    exit(1);
  }
  int delta = size * alpha;
  while (delta > 1) {
    delta = delta * alpha;
    DeltaSort(delta, sequence, size);
    if (trace) sequence.Print();
  }
}



/**
 * @brief Función auxiliar para el algoritmo de ordenación shell sort
 * @param delta Distancia entre los elementos a comparar
 * @param sequence Vector de elementos
 * @param n Tamaño del vector
*/
template <class key>
void DeltaSort(int delta, StaticSequence<key>& sequence, int n) {
  for (int i = delta; i < n; ++i) {
    key aux = sequence[i];
    int j = i;
    while (j >= delta && aux < sequence[j - delta]) {
      sequence.data(j, sequence[j - delta]);
      j -= delta;
    }
    sequence.data(j, aux);
  }
}



/**
 * @brief Función que implementa el algoritmo de ordenación radix sort
 * @param sequence Vector de elementos
 * @param size Tamaño del vector
 * @param trace Indica si se debe mostrar el vector en cada paso
*/
template <class key>
void RadixSortFunction(StaticSequence<key>& sequence, int size, bool trace) {
  long max;
  max = sequence[0];
  for (int i{1}; i < size; ++i) {
    if (long(sequence[i]) > max) {
      max = long(sequence[i]);
    }
  }
  for (int exp{1}; max/exp > 0; exp *= 10) {
    CountSort(sequence, size, exp);
    if (trace) sequence.Print();
  }
}



/**
 * @brief Función auxiliar para el algoritmo de ordenación radix sort
 * @param sequence Vector de elementos
 * @param size Tamaño del vector
 * @param exp Exponente
*/
template <class key>
void CountSort(StaticSequence<key>& sequence, int size, int exp) {
  key output[size];
  int count[10] = {0};

  // Count the number of times each digit appears
  for (int i{0}; i < size; ++i) {
    ++count[(sequence[i] / exp) % 10];
  }
  // Cambiar count[i] para que ahora contenga la posición real de este dígito en output
  for (int i{1}; i < 10; ++i) {
    count[i] += count[i - 1];
  }
  // Construir el array de salida
  for (int i{size - 1}; i >= 0; --i) {
    output[--count[(sequence[i] / exp) % 10]] = sequence[i];
  }
  // Copiar al vector de salida a sequence
  for (int i{0}; i < size; ++i) {
    // sequence[i] = output[i];
    sequence.data(i, output[i]);
  }
}







