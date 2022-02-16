#include "Angajat.h"
#include <iostream>
#include <iomanip>
#include <string>
//
//functii angajat
//
    Angajat::Angajat(std::string nume, std::string departament):nume(nume), departament(departament){}
    
    Angajat::~Angajat(){}
    
std::string Angajat::get_nume(){
    return this->nume;
}

std::string Angajat::get_dep(){
    return this->departament;
}


//   
//functii salariat
//
    Salariat::Salariat(std::string nume, std::string departament, int norma, int vechime, float salariu):
                        Angajat(nume,departament), norma(norma), vechime(vechime), salariu_net(salariu){}
    
    Salariat::~Salariat(){}
    
void Salariat::afisare(){
    std::cout << this->get_nume() << " " << norma << " " << vechime << " " << salariu_net << "\n";
}

float Salariat::salariu_brut(){
    if(this->get_dep()=="IT"){
        return salariu_net*12/(1-0.35);
    }
    else
    {
        return salariu_net*12/(1-0.45);
    }
}

float Salariat::rentabilitate_angajat(){
    return norma*(250-vechime/3)/(this->salariu_brut());
}


//
//functii colaborator
//
    Colaborator::Colaborator(std::string nume, std::string departament, float onorariu, int prestari):
                            Angajat(nume,departament), onorariu(onorariu), nr_prestari_anuale(prestari){}
    
    Colaborator::~Colaborator(){}

void Colaborator::afisare(){
    std::cout << this->get_nume() << " " << onorariu << " " << nr_prestari_anuale << "\n";
}

float Colaborator::salariu_brut(){
    if(this->get_dep()=="IT"){
        return (onorariu*nr_prestari_anuale)/(1-0.35);
    }
    else
    {
        return (onorariu*nr_prestari_anuale)/(1-0.45);
    }
}

float Colaborator::rentabilitate_angajat(){
    return 0;
}