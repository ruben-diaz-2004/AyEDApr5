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
#include "staticsequence.h"
#include "sortfunction.h"
#include "sortmethod.h"


template <class key>
class SelectionSort : public SortMethod<key> {
 public:
  SelectionSort(StaticSequence<key> sequence, int size) : sequence_(sequence), size_(size) {}
  void Sort() const override {
    SelectionSort(sequence_, size_);
  }

 private:
  StaticSequence<key> sequence_;
  int size_;
};


template <class key>
class QuickSort : public SortMethod<key> {
 public:
  QuickSort(StaticSequence<key> sequence, int size) : sequence_(sequence), size_(size) {}
  void Sort() const override {
    QuickSort(sequence_, size_);
  }

 private:
  StaticSequence<key> sequence_;
  int size_;
};


template <class key>
class HeapSort : public SortMethod<key> {
 public:
  HeapSort(StaticSequence<key> sequence, int size) : sequence_(sequence), size_(size) {}
  void Sort() const override {
    HeapSort(sequence_, size_);
  }

 private:
  StaticSequence<key> sequence_;
  int size_;
};


template <class key>
class ShellSort : public SortMethod<key> {
 public:
  ShellSort(StaticSequence<key> sequence, int size) : sequence_(sequence), size_(size) {}
  void Sort() const override {
    ShellSort(sequence_, size_);
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
    RadixSort(sequence_, size_);
  }

 private:
  StaticSequence<key> sequence_;
  int size_;
};



#endif // METHODS_H