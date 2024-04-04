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



template <class key>
class SelectionSort : public SortMethod<key> {
 public:
  SelectionSort(StaticSequence<key>& sequence, const int& size) : sequence_(sequence), size_(size) {}
  void Sort() override {
    SelectionSortFunction(sequence_, size_);
  }
  void Print() const {
    sequence_.Print();
  }
 private:
  StaticSequence<key> sequence_;
  int size_;
};


template <class key>
class QuickSort : public SortMethod<key> {
 public:
  QuickSort(StaticSequence<key>& sequence, const int& size) : sequence_(sequence), size_(size) {}
  void Sort() override {
    QuickSortFunction(sequence_, 0, size_-1);
  }
  void Print() const {
    sequence_.Print();
  }

 private:
  StaticSequence<key> sequence_;
  int size_;
};


template <class key>
class HeapSort : public SortMethod<key> {
 public:
  HeapSort(StaticSequence<key>& sequence, const int& size) : sequence_(sequence), size_(size) {}
  void Sort() override {
    HeapSortFunction(sequence_, size_);
  }
  void Print() const {
    sequence_.Print();
  }

 private:
  StaticSequence<key> sequence_;
  int size_;
};


template <class key>
class ShellSort : public SortMethod<key> {
 public:
  ShellSort(StaticSequence<key>& sequence, const int& size) : sequence_(sequence), size_(size) {}
  void Sort() override {
    ShellSortFunction(sequence_, size_);
  }
  void Print() const {
    sequence_.Print();
  }
 private:
  StaticSequence<key> sequence_;
  int size_;
};


template <class key>
class RadixSort : public SortMethod<key> {
 public:
  RadixSort(StaticSequence<key> sequence, int size) : sequence_(sequence), size_(size) {}
  void Sort() const override {
    RadixSortFunction(sequence_, size_);
  }

 private:
  StaticSequence<key> sequence_;
  int size_;
};



#endif // METHODS_H