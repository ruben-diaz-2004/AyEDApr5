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
#include <fstream>
#include "parameters.cc"
#include "sortfunction.cc"
#include "sequence.h"
#include "staticsequence.h"
#include "nif.h"
#include "sortmethod.h"
#include "methods.h"

#include <iostream>
#include <sstream>
#include <string>


int main(int argc, char *argv[]) {
  parameters options = parse_args(argc, argv);

  StaticSequence<Nif>* sequencia_a_ordenar;
  switch (options.init_code) {
    case 0:
      sequencia_a_ordenar = new StaticSequence<Nif>(options.size, options.init_code); // Manual
      break;
    case 1:
      sequencia_a_ordenar = new StaticSequence<Nif>(options.size, options.init_code); // Random
      break;
    case 2:
      std::fstream file(options.file_name);
      sequencia_a_ordenar = new StaticSequence<Nif>(options.size, file); // File
      break;
  }


  SortMethod<Nif>* metodo_ordenacion;
  switch (options.sort_code) {
    case 0:
      metodo_ordenacion = new SelectionSort<Nif>(*sequencia_a_ordenar, options.size, options.trace);
      break;
    case 1:
      metodo_ordenacion = new QuickSort<Nif>(*sequencia_a_ordenar, options.size, options.trace);
      break;
    case 2:
      metodo_ordenacion = new HeapSort<Nif>(*sequencia_a_ordenar, options.size, options.trace);
      break;
    case 3:
      metodo_ordenacion = new ShellSort<Nif>(*sequencia_a_ordenar, options.size, options.trace);
      break;
    case 4:
      metodo_ordenacion = new RadixSort<Nif>(*sequencia_a_ordenar, options.size, options.trace);
      break;
  }

  std::cout << "Antes de ordenar" << std::endl << std::endl;
  metodo_ordenacion->Print();
  std::cout << "Llamando al metodo de ordenacion" << std::endl;
  metodo_ordenacion->Sort();
  std::cout << "Despues de ordenar" << std::endl;
  metodo_ordenacion->Print();

  // bool running = true;
  // char stop;
  // long clave;
  // while(running) {
  //   std::cin >> stop;
  //   switch(stop) {
  //     case 'x':
  //       running = false;
  //       break;
  //     default:
  //       running = false;
  //       break;
  //   }
  // }

  return 0;
}