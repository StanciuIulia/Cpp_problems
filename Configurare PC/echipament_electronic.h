#ifndef ECHIPAMENT_ELECTRONIC_H
#define ECHIPAMENT_ELECTRONIC_H

#include <string>

class Echipament_electronic{
protected:
    float pret;
    std::string nume;
    std::string tip;
public:
    Echipament_electronic(float, std::string, std::string);
    float get_pret();
    std::string get_nume();
    std::string get_tip();
    //virtual void afisare()=0;
    //virtual float raport_calitate_pret()=0;
    virtual ~Echipament_electronic();
};

class Placa_baza: public Echipament_electronic{
private:
    std::string socket;
public:
    Placa_baza(float, std::string, std::string, std::string);
    std::string get_socket();
    void afisare();
    ~Placa_baza();
};

class CPU: public Echipament_electronic{
private:
    std::string socket;
    int frecventa;
public:
    CPU(float, std::string, std::string, std::string, int);
    std::string get_socket();
    int get_frecventa();
    void afisare();
    ~CPU();    
};

class GPU: public Echipament_electronic{
private:
    int memorie;
public:
    GPU(float, std::string, std::string, int);
    int get_memorie();
    void afisare();
    ~GPU();    
};    

class Stocare: public Echipament_electronic{
private:
    float memorie;
public:
    Stocare(float, std::string, std::string, float);
    float get_memorie();
    void afisare();
    ~Stocare();     
};


class PC{
private:
    Placa_baza* p;
    CPU* cpu;
    GPU* gpu;
    Stocare* s;
public:
    PC(Placa_baza*, CPU*, GPU*, Stocare*);
    ~PC();
    void set_cpu(CPU*);
    void set_gpu(GPU*);
    void set_s(Stocare*);
    float calcul_pret();
    void afisare();
    void compatibilitate();
};

class Manager{
    friend class PC;
public:
    Placa_baza* placa;
    CPU** procesoare;
    GPU** p_grafice;
    Stocare** memorii;
public:
    Manager();
    void add_placa(Placa_baza*);
    void add_cpu(CPU*, int );
    void add_gpu(GPU*, int );
    void add_memorie(Stocare*, int );
    void afisare(int, int, int);
    
    void sortare_cpu(int);
    void sortare_gpu(int);
    void sortare_stocare(int);
    ~Manager();
};

#endif