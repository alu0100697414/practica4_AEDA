#include "dni.hpp"

DNI::DNI(void):dni_(0){}


DNI::DNI(int dato):dni_(dato){}


DNI::~DNI(void){
  dni_ = 30000000;
}


void DNI::set_dni(int dato){
  dni_ = dato;
}


int DNI::get_dni(void){
  return dni_;
}
