#include "Veiculo.h"

void Veiculo::setNumRodas(int x){
	this->num_rodas = x;
	this->rodas = new Roda[x];
}

int Veiculo::getNumRodas(){
	return this->num_rodas;
}

