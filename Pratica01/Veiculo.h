#include <iostream>
using namespace std;

class Veiculo{
	private:
		string nome;
		int num_rodas;
		
	public:
		Veiculo(const char *p){
			this->nome = p;
			cout << "O objeto " << nome << " foi criado" << endl;
		}
		
		~Veiculo(){
			cout << "O objeto " << nome << " foi destruído" << endl;	
		}

	public:
		void setNumRodas(int x);
		int getNumRodas();
};

