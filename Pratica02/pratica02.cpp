#include <iostream>
using namespace std;
#include "veiculo.h"

int main(){

//    Veiculo v1;
//    Terrestre t1;
//    Aquatico aq1;
//    Aereo ar1;

//    Veiculo v2("automovel");
//    Terrestre t2("carro");
//    Aquatico aq2("navio");
//    Aereo ar2("aviao");

    cout << endl;

    Veiculo * terr, * aqua, * aereo;

 terr = new Terrestre("VT1");
 dynamic_cast<Terrestre *>(terr)->setCapPass(45);
 terr->mover();
 //casting Terrestre
//((Terrestre *)terr)->setCapPass(45);

cout << endl;

aqua = new Aquatico("VQ1");
dynamic_cast<Aquatico *>(aqua)->setCargaMax(12.5);
aqua->mover();
//casting Aquatico
//((Aquatico *)aqua)->setCargaMax(12.5);



cout << endl;

aereo = new Aereo("VA1");
aereo->mover();
//casting Aereo
//((Aereo*)aereo)->setVelMax(1040.5);


cout << endl;

delete terr;
delete aqua;
delete aereo;

cout << endl;

Veiculo * anfi;
anfi = new Anfibio("anfibio");
anfi->mover();

    return 0;
}
