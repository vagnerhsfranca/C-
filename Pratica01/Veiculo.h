#include <iostream>
using namespace std;

class Roda{

	public:
		Roda(){
			cout <<"A roda foi construida" << endl;
		}
		~Roda(){
			cout <<"A roda foi destruida" <<endl;
		}
};
class Veiculo{

	string nome;
	int num_rodas;
	Roda *rodas;

	public:
		Veiculo(const char *name){
			this->nome = name;
			cout <<"O veiculo " << nome <<" foi construido" << endl;
			this->rodas = NULL;
		}

		~Veiculo(){
			cout <<"O veiculo " << nome <<" foi detruido" << endl;
			delete [] this->rodas;
		}

		void setNumRodas(int x);
		int getNumRodas();
};
