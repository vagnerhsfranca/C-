#include <iostream>
using namespace std;
#include "veiculo.h"

int main(){

	cout << "Primeira aplicacao C++" << endl;

//	Veiculo veiculo1("v1");
//	{
//		Veiculo veiculo2("v2");
//		{
//			Veiculo veiculo3("v3");
//		}
//	}

	Veiculo *obj4 = new Veiculo("v4");
	obj4->setNumRodas(2);
	cout << endl;
	delete obj4;

	return 0;
}
