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


#ifndef METHODS_H
#define METHODS_H

#include <iostream>
#include "nif.h"
#include "staticsequence.h"



/**
 * Clase que implementea el método de ordenación selection sort
*/
template <class key>
class SelectionSort : public SortMethod<key> {
 public:
  SelectionSort(StaticSequence<key>& sequence, const int& size, const bool& trace) : sequence_(sequence), size_(size), trace_(trace) {}
  void Sort() override {
    SelectionSortFunction(sequence_, size_, trace_);
  }
  void Print() const {
    sequence_.Print();
  }
 private:
  StaticSequence<key> sequence_;
  int size_;
  bool trace_;
};



/**
 * Clase que implementea el método de ordenación quick sort
*/
template <class key>
class QuickSort : public SortMethod<key> {
 public:
  QuickSort(StaticSequence<key>& sequence, const int& size, const bool& trace) : sequence_(sequence), size_(size), trace_(trace) {}
  void Sort() override {
    QuickSortFunction(sequence_, 0, size_-1, trace_);
  }
  void Print() const {
    sequence_.Print();
  }

 private:
  StaticSequence<key> sequence_;
  int size_;
  bool trace_;
};



/**
 * Clase que implementea el método de ordenación heap sort
*/
template <class key>
class HeapSort : public SortMethod<key> {
 public:
  HeapSort(StaticSequence<key>& sequence, const int& size, const bool& trace) : sequence_(sequence), size_(size), trace_(trace) {}
  void Sort() override {
    HeapSortFunction(sequence_, size_, trace_);
  }
  void Print() const {
    sequence_.Print();
  }

 private:
  StaticSequence<key> sequence_;
  int size_;
  bool trace_;
};



/**
 * Clase que implementea el método de ordenación shell sort
*/
template <class key>
class ShellSort : public SortMethod<key> {
 public:
  ShellSort(StaticSequence<key>& sequence, const int& size, const bool& trace) : sequence_(sequence), size_(size), trace_(trace) {}
  void Sort() override {
    ShellSortFunction(sequence_, size_, trace_);
  }
  void Print() const {
    sequence_.Print();
  }
 private:
  StaticSequence<key> sequence_;
  int size_;
  bool trace_;
};



/**
 * Clase que implementea el método de ordenación radix sort
*/
template <class key>
class RadixSort : public SortMethod<key> {
 public:
  RadixSort(StaticSequence<key>& sequence, const int& size, const bool& trace) : sequence_(sequence), size_(size), trace_(trace) {}
  void Sort() override {
    RadixSortFunction(sequence_, size_, trace_);
  }
  void Print() const {
    sequence_.Print();
  }

 private:
  StaticSequence<key> sequence_;
  int size_;
  bool trace_;
};



#endif // METHODS_H