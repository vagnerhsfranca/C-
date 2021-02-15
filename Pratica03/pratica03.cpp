#include <iostream>
#include "funcoes.h"
#include "arranjo.h"
#include "aluno.h"

using namespace std;
using namespace funcoes;


int main(){

//int x = 5, y = 10, z = 30;
float x=5.5, y=10.15, z=30.7;

cout << "Antes: x = " << x << " y = " << y << endl;
trocar(x, y);
cout << "Depois : x = " << x << " y = " << y << endl;
cout << "Minimo entre " << x << " e " << y << ": " << minimo(x, y) << endl;
cout << "Maximo entre " << y << " e " << z << ": " << maximo(y, z) << endl;
cout << endl;
cout << maximo("maximo","Maximo") << endl;
cout << minimo("minimo","Minimo") << endl;
cout << endl;

Arranjo<int> arr(10);
arr.set(4, 5);
arr.set(7, 15);
arr.set(8, 22);
arr.exibir();
cout << endl;

Arranjo<float> arr2(5);
arr2.set(0, 5.4);
arr2.set(1, 4.3);
arr2.set(2, 3.2);
arr2.set(3, 2.1);
arr2.set(4, 1.5);
arr2.exibir();
cout << endl;

Arranjo<float> arr3(2);
try{
arr3.set(3, 4.9);
}catch(const char *){
    cout << "Erro set()" << endl;
}
try{
arr3.get(2);
}catch(const char *){
    cout << "Erro get()" << endl;
}
cout << endl;

Arranjo<Aluno> turma(3);
turma.set(0, Aluno("Joao","1234"));
turma.set(1, Aluno("Maria","5235"));
turma.set(2, Aluno("Jose","2412"));
turma.exibir();
cout << endl;


Aluno aluno1=(Aluno("testeSobrecarga", "4321"));

cout << aluno1 << endl;
cout << endl;
return 0;
}
