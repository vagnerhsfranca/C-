#include <iostream>
using namespace std;
class Roda{
	
	public:
	Roda();
	~Roda();
	
};
class Veiculo{
	private:
		string nome;
		int num_rodas;
		Roda *rodas;
	public:
		Veiculo(const char *p){
			this->nome = p;
			this->rodas = NULL;
			cout << "O objeto " << nome << " foi criado" << endl;
		}
		
		~Veiculo(){
			cout << "O objeto " << nome << " foi destruído" << endl;	
		}

	public:
		void setNumRodas(int x);
		int getNumRodas();
};

