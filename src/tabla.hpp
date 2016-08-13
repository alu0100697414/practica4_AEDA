// Clase tabla

#include <iostream>

#include "celda.hpp"

template<class T>
class Tabla {

private:

  Celda<T>** tabla_;
  int size_;

public:

  Tabla(int tam, int i){

    tabla_ = NULL;
    tabla_ = new Celda<T>*[tam];

    for(int k=0; k<tam; k++)
      tabla_[k] = new Celda<T>(i);

    size_ = tam;
  }

  virtual ~Tabla(){

    if (tabla_!= NULL){
      delete [] tabla_;
      tabla_ = NULL;
    }

    size_=0;
  }

  int longitud(void){
    return size_;
  }

  int buscar(T x){

    int contmax = 0;
    int cont = 0;
    int aux = 0;

    int contador = 0;
    int indice;

    do {

      indice = exploracion(x, contmax);
      cont = 0;

      while(((aux!=-1) && (aux!=x.get_dni())) && (cont < tabla_[indice]->get_size())){
        aux=tabla_[indice]->get_dato_entero(cont);
        cont++;
      }

      contmax++;
      contador+=cont;

    } while (((aux!=-1) && (aux!=x.get_dni()))&& (contmax<longitud()));

    return contador;
  }

  void insertar(T x){

    int contmax = 0;
    int cont = 0;
    int indice = 0;
    int aux = 0;

    do {

      indice = exploracion(x, contmax);

      cont = 0;

      while((aux != -1) && (cont < tabla_[indice]->get_size())){
        aux = tabla_[indice]->get_dato_entero(cont);
  	    if(aux==-1)
  	      tabla_[indice]->insertarCelda(cont, x);

  	    cont++;
      }

      contmax ++;

    } while ((aux!=-1) && (contmax<longitud()));
  }

  int insertarsimulado(T x){

    int contmax = 0;
    int cont = 0;
    int indice = 0;
    int aux = 0;
    int contador = 0;

    do {

      indice = exploracion(x, contmax);
      cont = 0;

      while((aux!=-1) && (cont < tabla_[indice]->get_size())){
        aux=tabla_[indice]->get_dato_entero(cont);
  	    cont++;
      }

      contador+=cont;
      contmax++;

    }while((aux!=-1) && contmax<longitud());

    return contador;
  }

  virtual int hash(T clave) = 0;
  virtual int exploracion(T x,int i) = 0;
};
