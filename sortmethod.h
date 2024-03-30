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


#ifndef SORTMETHOD_H
#define SORTMETHOD_H

#include <iostream>


template <class key>
class SortMethod {
 public:
  virtual void Sort() const = 0;
};



#endif // SORTMETHOD_H