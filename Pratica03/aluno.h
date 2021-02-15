#include <iostream>
#include <ostream>
using namespace std;

class Aluno {

private:
    string nome;
    string mat;
public:
    Aluno() {}
    Aluno(const char * nome, const char * mat) : nome(nome), mat(mat) {}

    friend class Arranjo<Aluno>;
    friend ostream & operator << (ostream &out, const Aluno &aluno);

Aluno & operator=(const Aluno & aluno) {
    nome = aluno.nome;
    mat = aluno.mat;
}
};
template<>
void Arranjo<Aluno>::set(int idx, const Aluno & aluno) {
// atribua nome e mat individualmente para o item do array
    itens[idx].nome = aluno.nome;
    itens[idx].mat = aluno.mat;
}
template<>
void Arranjo<Aluno>::exibir() {
// exiba cada aluno do array no formato "idx : mat = nome"
    for(int i=0; i < tamanho; i++){
        cout << i << " : " << itens[i].mat << " = " << itens[i].nome << endl;
    }
}
ostream & operator<<(ostream & out, const Aluno & aluno) {
    out << aluno.nome << " : " << aluno.mat << endl;
    return out;
}

