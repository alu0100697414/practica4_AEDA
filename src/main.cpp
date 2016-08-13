#include <iostream>
#include <stdlib.h>
#include <math.h>

#include "clases_hijas.hpp"

using namespace std;

int main(void){

  system("clear");

  int tam_hash, tam_celda, fdis, fexp, nPruebas, N;
  double factor;

  Tabla<DNI>* A;

  cout << "Introduzca el numero de posiciones de la tabla hash: ";
  cin >> tam_hash;

  cout << "Introduzca el numero de claves que se pueden almacenar en cada celda: ";
  cin >> tam_celda;

  cout << endl << "Ahora elija el tipo de funcion que desea aplicar." << endl << endl;

  cout << "Funciones de dispersion, h(x)" << endl;
  cout << "1. Modulo." << endl;
  cout << "2. Suma." << endl;
  cout << "3. Pseudo-aleatoria." << endl << endl;
  cout << "Introduzca cual desea: ";
  cin >> fdis;
  cout << endl;

  cout << "Funciones de exploracion, g(x)" << endl;
  cout << "1. Lineal." << endl;
  cout << "2. Cuadratica." << endl;
  cout << "3. Dispersion doble." << endl;
  cout << "4. Re-dispersion." << endl << endl;
  cout << "Introduzca cual desea: ";
  cin >> fexp;
  cout << endl;

  if((fdis==1) && (fexp==1))
    A = new Mlineal<DNI>(tam_hash,tam_celda);
  if((fdis==1) && (fexp==2))
    A = new Mcuadratica<DNI>(tam_hash,tam_celda);
  if((fdis==1) && (fexp==3))
    A = new Mdobledisp<DNI>(tam_hash,tam_celda);
  if((fdis==1) && (fexp==4))
    A = new Mredisp<DNI>(tam_hash,tam_celda);

  if((fdis==2) && (fexp==1))
    A = new Slineal<DNI>(tam_hash,tam_celda);
  if((fdis==2) && (fexp==2))
    A = new Scuadratica<DNI>(tam_hash,tam_celda);
  if((fdis==2) && (fexp==3))
    A = new Sdobledisp<DNI>(tam_hash,tam_celda);
  if((fdis==2) && (fexp==4))
    A = new Sredisp<DNI>(tam_hash,tam_celda);

  if((fdis==3) && (fexp==1))
    A = new Plineal<DNI>(tam_hash,tam_celda);
  if((fdis==3) && (fexp==2))
    A = new Pcuadratica<DNI>(tam_hash,tam_celda);
  if((fdis==3) && (fexp==3))
    A = new Pdobledisp<DNI>(tam_hash,tam_celda);
  if((fdis==3) && (fexp==4))
    A = new Predisp<DNI>(tam_hash,tam_celda);

  cout << "Ahora introduzca el valor de factor de carga (entre 0 y 1): ";
  cin >> factor;
  cout << endl;

  cout << "Finalmente, introduzca el numero de pruebas que desea realizar: ";
  cin >> nPruebas;
  cout << endl << endl;

  N = int (factor*(tam_hash*tam_celda));

  DNI banco[N*2];

  for(int i=0; i<N*2; i++)
    banco[i] = DNI(30000000 + (rand()%50000000));

  for (int i=0; i<N; i++)
    A -> insertar(banco[i]);

  // Pruebas
  int NPruebasbuscar[nPruebas];
  int NPruebasInsertar[nPruebas];

  for(int i=0; i<nPruebas; i++){
    NPruebasbuscar[i] = A -> buscar(banco[rand() % N*2]);
    NPruebasInsertar[i]= A -> insertarsimulado(30000000 + (rand()%50000000));
  }

  //Pruebas buscar y media
  int minBuscar = NPruebasbuscar[0];
  int maxBuscar = NPruebasbuscar[0];
  double mediaBuscar=0.0;

  for (int i=0; i<nPruebas; i++){
    if (minBuscar > NPruebasbuscar[i])
      minBuscar=NPruebasbuscar[i];

    if(maxBuscar<NPruebasbuscar[i])
      maxBuscar=NPruebasbuscar[i];

    mediaBuscar+=NPruebasbuscar[i];
  }

  mediaBuscar=mediaBuscar/nPruebas;

  //Pruebas insertar y media
  int minInsertar = NPruebasInsertar[0];
  int maxInsertar = NPruebasInsertar[0];
  double mediaInsertar=0;

  for (int i=0; i<nPruebas; i++){
    if (minInsertar > NPruebasInsertar[i])
      minInsertar=NPruebasInsertar[i];

    if(maxInsertar < NPruebasInsertar[i])
      maxInsertar=NPruebasInsertar[i];

    mediaInsertar+=NPruebasInsertar[i];
  }

  mediaInsertar=mediaInsertar/nPruebas;

  // Muestra de los resultados de las estadisticas.
  cout << "COMPARACIONES EN INSERCIONES Y BUSQUEDAS." << endl;

  cout << "Celdas: " << tam_hash << endl;
  cout << "Bloques: " << tam_celda << endl;

  if(fexp==1)
    cout << "Exploracion: Lineal." << endl;
  if(fexp==2)
    cout << "Exploracion: Cuadratica." << endl;
  if(fexp==3)
    cout << "Exploracion: Dispersion Doble." << endl;
  if(fexp==4)
    cout << "Exploracion: Redispersion." << endl;

  cout << "Carga: " << factor << endl;
  cout << "Pruebas: " << nPruebas << endl;

  cout << endl << "NUMERO DE COMPARACIONES." << endl << endl;
  cout << "BUSQUEDAS:" << endl;
  cout << "MAXIMO: " << maxBuscar << " MINIMO: " << minBuscar << " MEDIA: " << mediaBuscar << endl << endl;

   cout << "INSERCION:" << endl;
   cout << "MAXIMO: " << maxInsertar << " MINIMO: " << minInsertar << " MEDIA: " << mediaInsertar << endl;
}
