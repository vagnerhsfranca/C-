#include <iostream>
using namespace std;
#include "veiculo.h"

//Veiculo
void Veiculo::mover(){

cout <<"Veiculo "<< nome << " moveu" <<endl;
}

//Terrestre
int Terrestre::getCapPass(){
return this->cap_pass;
}

void Terrestre::setCapPass(int x){
this->cap_pass=x;
}

void Terrestre::mover(){

cout <<"Veiculo terrestre "<< nome << " moveu" <<endl;
}

//Aquatico
float Aquatico::getCargaMax(){
return this->carg_max;
}
void Aquatico::setCargaMax(float x){
this->carg_max=x;
}
void Aquatico::mover(){

cout <<"Veiculo aquatico "<< nome << " moveu" <<endl;
}

//Aereo
float Aereo::getVelMax(){
return this->vel_max;
}
void Aereo::setVelMax(float x){
this->vel_max=x;
}
void Aereo::mover(){

cout <<"Veiculo aereo "<< nome << " moveu" <<endl;
}
