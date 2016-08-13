// Clase celda.
#include <iostream>

#include "dni.hpp"

template<class T>
class Celda {

private:

  T *nBloques_;
  int size_;

public:

  Celda(int tam){

    nBloques_ = NULL;
    nBloques_ = new T[tam];

    for(int i=0;i<tam;i++){
      nBloques_[i] = -1;
    }

    size_ = tam;
  }

  ~Celda(void){

    if(nBloques_ != NULL){
      delete [] nBloques_;
      nBloques_ = NULL;
    }

    size_ = 0;
  }

  bool buscarCelda(T x){

    for(int i=0;i<size_;i++)
      if(nBloques_[i] == x)
        return true;

    return false;
  }

  bool insertarCelda(int pos, T x){

    if(nBloques_[pos].get_dni() == -1){
      nBloques_[pos] = x;
      return true;
    }
    else
      return false;
  }

  T get_dato(int pos){
    return nBloques_[pos];
  }

  int get_dato_entero(int pos){
    return nBloques_[pos].get_dni();
  }

  int get_size(void){
    return size_;
  }

};
