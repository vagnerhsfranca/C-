
#include <iostream>
using namespace std;

class Veiculo{

	protected:
	string nome;

	public:

	Veiculo(const char *name){
		this->nome = name;
		cout <<"O veiculo " << nome << "foi criado" << endl;
	}
};

class Terrestre : public Veiculo{

	public:
	Terrestre(const char *nameT):Veiculo(const char *name){
		this->nome = nomeT;
		cout <<"O veiculo Terrestre " << nome << "foi criado" << endl;
	}

};

class Aquatico : public Veiculo{

	public:
	Aquatico(const char *nomeAq):Veiculo(const char *name){
		this->nome = nomeAq;
		cout <<"O veiculo Aquatico " << nome << "foi criado" << endl;
	}
};

class Aereo : public Veiculo{
	Aereo(const char *nomeAr):Veiculo(const char *name){
		this->nome = nomeAr;
				cout <<"O veiculo Aereo " << nome << "foi criado" << endl;
	}
};

