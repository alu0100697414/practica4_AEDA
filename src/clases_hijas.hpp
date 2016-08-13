#include <stdlib.h>

#include "tabla.hpp"

// Funciones de exploracion con la funcion de dispersion hash de modulo.
template<class T>
class Mlineal : public Tabla<T> {

public:

  Mlineal(int num, int i);
  ~Mlineal();

  int hash(T clave);
  int exploracion(T x, int i);
};

template<class T>
class Mcuadratica : public Tabla<T> {

public:

  Mcuadratica(int num, int i);
  ~Mcuadratica();

  int hash(T clave);
  int exploracion(T x, int i);
};

template<class T>
class Mdobledisp : public Tabla<T> {

public:

  Mdobledisp(int num, int i);
  ~Mdobledisp();

  int hash(T clave);
  int exploracion(T x, int i);
};

template<class T>
class Mredisp : public Tabla<T> {

public:

  Mredisp(int num, int i);
  ~Mredisp();

  int hash(T clave);
  int exploracion(T x, int i);
};





// Funciones de exploracion con la funcion de dispersion hash de suma.
template<class T>
class Slineal : public Tabla<T> {

public:

  Slineal(int num, int i);
  ~Slineal();

  int hash(T clave);
  int exploracion(T x, int i);
};

template<class T>
class Scuadratica : public Tabla<T> {

public:

  Scuadratica(int num, int i);
  ~Scuadratica();

  int hash(T clave);
  int exploracion(T x, int i);
};

template<class T>
class Sdobledisp : public Tabla<T> {

public:

  Sdobledisp(int num, int i);
  ~Sdobledisp();

  int hash(T clave);
  int exploracion(T x, int i);
};

template<class T>
class Sredisp : public Tabla<T> {

public:

  Sredisp(int num, int i);
  ~Sredisp();

  int hash(T clave);
  int exploracion(T x, int i);
};





// Funciones de exploracion con la funcion de dispersion hash pseudo-aleatoria.
template<class T>
class Plineal : public Tabla<T> {

public:

  Plineal(int num, int i);
  ~Plineal();

  int hash(T clave);
  int exploracion(T x, int i);
};

template<class T>
class Pcuadratica : public Tabla<T> {

public:

  Pcuadratica(int num, int i);
  ~Pcuadratica();

  int hash(T clave);
  int exploracion(T x, int i);
};

template<class T>
class Pdobledisp : public Tabla<T> {

public:

  Pdobledisp(int num, int i);
  ~Pdobledisp();

  int hash(T clave);
  int exploracion(T x, int i);
};

template<class T>
class Predisp : public Tabla<T> {

public:

  Predisp(int num, int i);
  ~Predisp();

  int hash(T clave);
  int exploracion(T x, int i);
};

// Clase hija MLineal
template<class T> Mlineal<T>::Mlineal(int num, int i): Tabla<T>(num,i){}


template<class T> Mlineal<T>::~Mlineal(){}


template<class T> int Mlineal<T>::hash(T clave){

  return clave.get_dni() % this->longitud();
}


template<class T> int Mlineal<T>::exploracion(T x, int i){

  int pos=(hash(x.get_dni())+i) % this->longitud();
  return pos;
}


// Clase hija MCuadratica
template<class T> Mcuadratica<T>::Mcuadratica(int num, int i): Tabla<T>(num,i){}


template<class T> Mcuadratica<T>::~Mcuadratica(){};


template<class T> int Mcuadratica<T>::hash(T clave){

  return clave.get_dni() % this->longitud();
}


template<class T> int Mcuadratica<T>::exploracion(T x, int i){

  int pos=(hash(x.get_dni())+i*i) % this->longitud();
    return pos;
}

// Clase hija Doble Dispersion
template<class T> Mdobledisp<T>::Mdobledisp(int num, int i): Tabla<T>(num,i){}


template<class T> Mdobledisp<T>::~Mdobledisp(){};


template<class T> int Mdobledisp<T>::hash(T clave){

  return clave.get_dni() % this->longitud();
}


template<class T> int Mdobledisp<T>::exploracion(T x, int i){

    int pos=(hash(x)+hash(x)*i) % this->longitud();
    return pos;
}

// Clase hija Redispersion
template<class T> Mredisp<T>::Mredisp(int num, int i): Tabla<T>(num,i){}


template<class T> Mredisp<T>::~Mredisp(){};


template<class T> int Mredisp<T>::hash(T clave){

  return clave.get_dni() % this->longitud();
}


template<class T> int Mredisp<T>::exploracion(T x, int i){
    int pos=(hash(x.get_dni())+hash(x.get_dni()*i)) % this->longitud();
    return pos;
}





// Clase hija SLineal
template<class T> Slineal<T>::Slineal(int num, int i): Tabla<T>(num,i){}


template<class T> Slineal<T>::~Slineal(){};


template<class T> int Slineal<T>::hash(T clave){

  int d = 0, y;
  int x = clave.get_dni();

  while (x > 0){

    y = x % 10;
    d = d + y;
    x = x / 10;
  }

  return (d % this->longitud());
}


template<class T> int Slineal<T>::exploracion(T x, int i){

    int pos=(hash(x)+i) % this->longitud();
    return pos;
}

// Clase hija SCuadratica
template<class T> Scuadratica<T>::Scuadratica(int num, int i): Tabla<T>(num,i){}


template<class T> Scuadratica<T>::~Scuadratica(){};


template<class T> int Scuadratica<T>::hash(T clave){

  int d = 0, y;
  int x = clave.get_dni();

  while (x > 0){

    y = x % 10;
    d = d + y;
    x = x / 10;
  }

  return (d % this->longitud());
}


template<class T> int Scuadratica<T>::exploracion(T x, int i){

  int pos=(hash(x)+i*i) % this->longitud();
    return pos;
}

// Clase hija Doble Dispersion
template<class T> Sdobledisp<T>::Sdobledisp(int num, int i): Tabla<T>(num,i){}


template<class T> Sdobledisp<T>::~Sdobledisp(){};


template<class T> int Sdobledisp<T>::hash(T clave){

  int d = 0, y;
  int x = clave.get_dni();

  while (x > 0){

    y = x % 10;
    d = d + y;
    x = x / 10;
  }

  return (d % this->longitud());
}


template<class T> int Sdobledisp<T>::exploracion(T x, int i){

    int pos=(hash(x)+hash(x)*i) % this->longitud();
    return pos;
}

// Clase hija Redispersion
template<class T> Sredisp<T>::Sredisp(int num, int i): Tabla<T>(num,i){}


template<class T> Sredisp<T>::~Sredisp(){};


template<class T> int Sredisp<T>::hash(T clave){

  int d = 0, y;
  int x = clave.get_dni();

  while (x > 0){

    y = x % 10;
    d = d + y;
    x = x / 10;
  }

  return (d % this->longitud());
}


template<class T> int Sredisp<T>::exploracion(T x, int i){
    int pos=(hash(x.get_dni())+hash(x.get_dni()*i)) % this->longitud();
    return pos;
}





// Clase hija PLineal
template<class T> Plineal<T>::Plineal(int num, int i): Tabla<T>(num,i){}


template<class T> Plineal<T>::~Plineal(){};


template<class T> int Plineal<T>::hash(T clave){

  srand(clave.get_dni());
  return rand() % this->longitud();
}


template<class T> int Plineal<T>::exploracion(T x, int i){

    int pos=(hash(x)+i) % this->longitud();
    return pos;
}

// Clase hija PCuadratica
template<class T> Pcuadratica<T>::Pcuadratica(int num, int i): Tabla<T>(num,i){}


template<class T> Pcuadratica<T>::~Pcuadratica(){};


template<class T> int Pcuadratica<T>::hash(T clave){

  srand(clave.get_dni());
  return rand() % this->longitud();
}


template<class T> int Pcuadratica<T>::exploracion(T x, int i){

  int pos=(hash(x)+i*i) % this->longitud();
  return pos;
}

// Clase hija Doble Dispersion
template<class T> Pdobledisp<T>::Pdobledisp(int num, int i): Tabla<T>(num,i){}


template<class T> Pdobledisp<T>::~Pdobledisp(){};


template<class T> int Pdobledisp<T>::hash(T clave){

  srand(clave.get_dni());
  return rand() % this->longitud();
}


template<class T> int Pdobledisp<T>::exploracion(T x, int i){

    int pos=(hash(x)+hash(x)*i) % this->longitud();
    return pos;
}

// Clase hija Redispersion
template<class T> Predisp<T>::Predisp(int num, int i): Tabla<T>(num,i){}


template<class T> Predisp<T>::~Predisp(){};


template<class T> int Predisp<T>::hash(T clave){

  srand(clave.get_dni());
  return rand() % this->longitud();
}


template<class T> int Predisp<T>::exploracion(T x, int i){
    int pos=(hash(x)+hash(x.get_dni()*i)) % this->longitud();
    return pos;
}
