#include "echipament_electronic.h"
#include <iostream>

//functii ecipament electronic
Echipament_electronic::Echipament_electronic(float pret=0, std::string nume="", std::string tip=""):pret(pret), nume(nume), tip(tip){}

float Echipament_electronic::get_pret(){return pret;}

std::string Echipament_electronic::get_nume(){return nume;}

std::string Echipament_electronic::get_tip(){return tip;}

Echipament_electronic::~Echipament_electronic(){}



//functii placa de baza
Placa_baza::Placa_baza(float pret=0, std::string nume="", std::string tip="", std::string socket=""):Echipament_electronic(pret, nume, tip), socket(socket){}

std::string Placa_baza::get_socket(){
    return this->socket;
}

void Placa_baza::afisare(){
    std::cout << this->get_tip() <<", "<< this->get_nume() <<", " << this->socket << ", " << this->get_pret() << std::endl;
}

Placa_baza::~Placa_baza(){}



//functii CPU
CPU::CPU(float pret=0, std::string nume="", std::string tip="", std::string socket="", int f=0):Echipament_electronic(pret, nume, tip), socket(socket), frecventa(f){}

std::string CPU::get_socket(){
    return this->socket;
}

int CPU::get_frecventa(){
    return this->frecventa;
}

void CPU::afisare(){
    std::cout << this->get_tip() <<", "<< this->get_nume() <<", " << this->socket << ", " << this->frecventa << ", " <<this->get_pret() << std::endl;
}



CPU::~CPU(){}


//functii GPU
GPU::GPU(float pret=0, std::string nume="", std::string tip="", int m=0):Echipament_electronic(pret, nume, tip), memorie(m){}

int GPU::get_memorie(){
    return this->memorie;
}

void GPU::afisare(){
    std::cout << this->get_tip() <<", "<< this->get_nume() <<", " << this->memorie << ", " <<this->get_pret() << std::endl;
}

GPU::~GPU(){}


//functii stocare
Stocare::Stocare(float pret=0, std::string nume="", std::string tip="", float m=0):Echipament_electronic(pret, nume, tip), memorie(m){}

float Stocare::get_memorie(){
    return this->memorie;
}

void Stocare::afisare(){
    std::cout << this->get_tip() <<", "<< this->get_nume() <<", " << this->memorie << ", " <<this->get_pret() << std::endl;
}

Stocare::~Stocare(){}


//functii manager
Manager::Manager(){
    placa = new Placa_baza();
    procesoare = new CPU*[100];
    p_grafice = new GPU*[100];
    memorii = new Stocare*[100];
}

Manager::~Manager(){}

void Manager::add_placa(Placa_baza* p){
    this->placa = p;
}

void Manager::add_cpu(CPU* cpu, int i){
    *(this->procesoare+i) = cpu;
}

void Manager::add_gpu(GPU* gpu, int i){
    *(this->p_grafice+i)= gpu;
}

void Manager::add_memorie(Stocare* memorie, int i){
    *(this->memorii+i) = memorie;
}

void Manager::afisare(int nr_cpu, int nr_gpu, int nr_memorii){
    placa->afisare();
    int i=0;
    for(i=0; i<nr_cpu; i++)
        (*(procesoare+i))->afisare();
    for(i=0; i<nr_gpu; i++)
        (*(p_grafice+i))->afisare();
    for(i=0; i<nr_memorii; i++)
        (*(memorii+i))->afisare();
}

void Manager::sortare_cpu(int nr_cpu){
    for(int i=0; i<nr_cpu-1; i++)
        for(int j=i+1; j<nr_cpu; j++)
            if((*((procesoare)+i))->get_pret()>(*((procesoare)+j))->get_pret()){
                CPU* aux = *(procesoare+i);
                *(procesoare+i) = *(procesoare+j);
                *(procesoare+j) = aux;
            }
            else if((*((procesoare)+i))->get_pret()==(*((procesoare)+j))->get_pret())
                if((*((procesoare)+i))->get_frecventa()<(*((procesoare)+j))->get_frecventa()){
                    CPU* aux = *(procesoare+i);
                    *(procesoare+i) = *(procesoare+j);
                    *(procesoare+j) = aux;
                }
                
}

void Manager::sortare_gpu(int nr_gpu){
    for(int i=0; i<nr_gpu-1; i++)
        for(int j=i+1; j<nr_gpu; j++)
            if((*(p_grafice+i))->get_pret()>(*(p_grafice+j))->get_pret()){
                GPU* aux = *(p_grafice+i);
                *(p_grafice+i) = *(p_grafice+j);
                *(p_grafice+j) = aux;
            }
            else if ((*(p_grafice+i))->get_pret()==(*(p_grafice+j))->get_pret()){
                if((*(p_grafice+i))->get_memorie()<(*(p_grafice+j))->get_memorie()){
                    GPU* aux = *(p_grafice+i);
                    *(p_grafice+i) = *(p_grafice+j);
                    *(p_grafice+j) = aux;
                }
            }
                
}

void Manager::sortare_stocare(int nr_memorii){
    for(int i=0; i<nr_memorii-1; i++)
        for(int j=i+1; j<nr_memorii; j++)
            if((*(memorii+i))->get_pret()>(*(memorii+j))->get_pret()){
                Stocare* aux = *(memorii+i);
                *(memorii+i) = *(memorii+j);
                *(memorii+j) = aux;
            }
            else if((*(memorii+i))->get_pret()==(*(memorii+j))->get_pret())
                if((*(memorii+i))->get_memorie()<(*(memorii+j))->get_memorie()){
                    Stocare* aux = *(memorii+i);
                    *(memorii+i) = *(memorii+j);
                    *(memorii+j) = aux;
                }
                
}

//functii PC

PC::PC(Placa_baza* placa, CPU* procesor, GPU* gpu, Stocare* memorie):p(placa), cpu(procesor), gpu(gpu), s(memorie){}

void PC::set_cpu(CPU* proc){
    this->cpu = proc;
}

void PC::set_gpu(GPU* graf){
    this->gpu = graf;
}

void PC::set_s(Stocare* mem){
    this->s = mem;
}

float PC::calcul_pret(){
    float total=0;
    total = (this->p)->get_pret() + (this->cpu)->get_pret() + (this->gpu)->get_pret() + (this->s)->get_pret();
    return total;
}

void PC::afisare(){
    p->afisare();
    cpu->afisare();
    gpu->afisare();
    s->afisare();
}

void PC::compatibilitate(){
    if(p->get_socket()!=cpu->get_socket()){
        std::cout << "Placa de baza este incompatibila cu CPU ales." << std::endl;
    }
    else {
        this->afisare();
        std::cout << this->calcul_pret() << std::endl;
    }
}

PC::~PC(){}