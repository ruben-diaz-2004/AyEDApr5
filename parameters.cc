/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Computabilidad y Algoritmia 2023-2024
  *
  * @author Rubén Díaz Marrero 
  * @date 19/02/2024
  * @brief Juego de la vida
  */
 
#include <iostream>
#include <vector>
#include <string>
#include <fstream>


struct parameters {
  int size;
  int sort_code;
  int init_code;
  std::string file_name;
  bool trace = true;
};

parameters parse_args(int argc, char* argv[]) {
  std::vector<std::string> args(argv + 1, argv + argc);
  parameters options;
  for (auto it = args.begin(), end = args.end(); it != end; ++it) {
    if (*it == "-size") {
      options.size = std::stoi(*++it);
    } else if (*it == "-ord") {
      if (*++it == "sel") {
        options.sort_code = 0;
      } else if (*it == "quick") {
        options.sort_code = 1;
      } else if (*it == "heap") {
        options.sort_code = 2;
      } else if (*it == "shell") {
        options.sort_code = 3;
      } else if (*it == "radix") {
        options.sort_code = 4;
      }
    } else if (*it == "-init") {
      *++it;
      if (*it == "manual") {
        options.init_code = 0;
      } else if (*it == "random") {
        options.init_code = 1;
      } else if (*it == "file") {
        options.init_code = 2;
        *++it;
        options.file_name = *it;
      }
    } else if (*it == "-trace") {
      if (*++it == "n") {
        options.trace = false;
      }
    }
    else {
      std::cerr << "Error: invalid argument " << *it << std::endl;
      exit(1);
    }
  }
  return options;
}

  

