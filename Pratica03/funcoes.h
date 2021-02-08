#include <iostream>
#include <cstring>

using namespace std;


namespace funcoes{

template <class T>
void trocar(T &a, T &b){
int temp = a;
    a = b;
    b = temp;
}
template <class T>
T maximo(const T a, const T b){
    return (a>b) ? a:b;
}
template <class T>
T minimo(const T a, const T b){
    return(a<b) ? a:b;
}
template <>
char * minimo<char *>(char *param1, char *param2){
    strcmp(param1, param2);
}
//void trocar(int &a, const int b){
//int temp = a;
//    a = b;
//    b = temp;
//}
//int maximo(const int a, const int b){
//return (a>b) ? a:b;}
//int minimo(const int a, const int b){
//return (a<b) ? a:b;}
}


