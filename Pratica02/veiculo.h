#include <iostream>
using namespace std;

class Veiculo{

protected:
    string nome;

    public:
    Veiculo(const char* name){
    this->nome=name;
    cout << "Construido veiculo " << nome << endl;
    }

    virtual ~Veiculo(){
    cout << "Veiculo " << nome << " destruido" << endl;
    }
    virtual void mover()=0;
};

class Terrestre : public virtual Veiculo{

private:
int cap_pass;

protected:
    Terrestre() : Veiculo(""){};

public:
    Terrestre(const char* name) : Veiculo(name){
        this->cap_pass=5;
        cout << "Terrestre construido " << nome <<  endl;
    }
    virtual ~Terrestre(){
    cout <<"Terrestre " << nome << " destruido" << endl;
    }
    int getCapPass();
    void setCapPass(int x);
    void mover();
};

class Aquatico : public virtual Veiculo{

private:
float carg_max;

protected:
    Aquatico() : Veiculo(""){};

public:
    Aquatico(const char* name) : Veiculo(name){
        this->carg_max=10;
        cout << "Aquatico construido " << nome <<  endl;
    }
    virtual ~Aquatico(){
    cout <<"Aquatico " << nome << " destruido" << endl;
    }
    float getCargaMax();
    void setCargaMax(float x);
    void mover();
};

class Aereo : public Veiculo{

private:
float vel_max;

public:
    Aereo(const char* name) : Veiculo(name){
    this->vel_max=100;
    cout << "Aereo construido " << nome <<  endl;
    }
    virtual ~Aereo(){
    cout <<"Aereo " << nome << " destruido" << endl;
    }
    float getVelMax();
    void setVelMax(float x);
    void mover();
};

class Anfibio : public Terrestre, public Aquatico{

public:
Anfibio(const char * name) : Veiculo(name), Terrestre(), Aquatico(){}

void mover(){
Terrestre::mover();
Aquatico::mover();
}
};
