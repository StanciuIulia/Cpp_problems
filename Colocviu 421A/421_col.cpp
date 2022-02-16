#include "Firma.h"
#include <iostream>
#include <string>

//
//functii angajat
//

    Angajat::Angajat(std::string nume = "", std::string functie = "", float salariu = 0):
                    nume(nume), functie(functie), salariu_baza(salariu){}
    Angajat::~Angajat(){
        std::cout << "Destructor Angajat\n";
    }
    
void Angajat::set_procent_taxe(float taxe){
    this->procent_taxe_salariu = taxe;
}

float Angajat::get_procent_taxe(){
    return this->procent_taxe_salariu;
}
    
float Angajat::get_salariu_net(){
    return (this->salariu_baza)*(100-procent_taxe_salariu)/100;
}

float Angajat::get_salariu_brut(){
    return this->salariu_baza;
}

float Angajat::get_salariu_baza(){
    return this->salariu_baza;
}

std::string Angajat::get_nume(){
    return this->nume;
}

std::string Angajat::get_functie(){
    return this->functie;
}

void Angajat::marire_salariu(float procent){
    
}

void Angajat::afisare(){
    std::cout << nume << "\n" << functie << "\n";
}

//
//functii analist
//

    Analist::Analist(std::string nume = "", std::string functie = "", float salariu =0): Angajat(nume, functie, salariu){}
    Analist::~Analist(){
        std::cout << "Destructor Analist\n";
    }
    

    
//
//functii programator
//

    Programator::Programator(std::string nume = "", std::string functie = "", float salariu =0, float d_taxe=10): Analist(nume, functie, salariu), procent_deducere_salariu_it(d_taxe){}
    Programator::~Programator(){
        std::cout << "Destructor Programator\n";
    }
    

float Programator::get_salariu_net(){
    return (this->get_salariu_brut())*(100-this->get_procent_taxe()+procent_deducere_salariu_it)/100;
}


//
//functii lider
//

    LiderEchipaProgramare::LiderEchipaProgramare(std::string nume = "", std::string functie = "", float salariu =0, float d_taxe=10, int vechime = 0, float bonus=500):
                                                Programator(nume, functie, salariu, d_taxe), vechime_functie(vechime), bonus_vechime_functie(bonus){}
    
    LiderEchipaProgramare::~LiderEchipaProgramare(){
        std::cout << "Destructor LiderEchipaProgramare\n";
    }
    
float LiderEchipaProgramare::get_salariu_brut(){
    return this->salariu_baza+vechime_functie*bonus_vechime_functie;
}

float LiderEchipaProgramare::get_salariu_net(){
    return (this->get_salariu_brut())*(100-this->get_procent_taxe()+procent_deducere_salariu_it)/100;
}
  
//
//functii firma programare 
//

    FirmaProgramare::FirmaProgramare(int nr, Angajat** angajat): nr_angajati(nr){
        this->a = new Angajat*[100];
        for(int i=0; i<nr; i++){
            *(a+i) = *(angajat+i);
        }
    }
    FirmaProgramare::~FirmaProgramare(){}
    
Angajat** FirmaProgramare::get_angajati(){
    return this->a;
}

void FirmaProgramare::afiseaza_angajati(){
    for(int i=0; i<nr_angajati; i++){
            (*(a+i))->afisare();
        }
}

void FirmaProgramare::afiseaza_salarii(){
    for(int i=0; i<nr_angajati; i++){
            std::cout << (*(a+i))->get_nume() << "\n";
            std::cout << "Salariu brut: " << (*(a+i))->get_salariu_brut() << "\n";
            std::cout << "Salariu Net: " << (*(a+i))->get_salariu_net() << "\n";
        }
}
    
void FirmaProgramare::mareste_salarii(float p1, float p2, float p3){
    for(int i=0; i<nr_angajati; i++){
        std::cout << (*(a+i))->get_nume() << "\n";
        std::cout << "Salariu de baza vechi: " << (*(a+i))->get_salariu_baza()<< "\n";
        if((*(a+i))->get_functie() == "Analist")
            std::cout << "Salariu de baza nou: " << ((*(a+i))->get_salariu_baza())*(100+p1)/100 << "\n";
        if((*(a+i))->get_functie() == "Programator")
            std::cout << "Salariu de baza nou: " << ((*(a+i))->get_salariu_baza())*(100+p2)/100 << "\n";
        if((*(a+i))->get_functie() == "LiderEchipaProgramare")
            std::cout << "Salariu de baza nou: " << ((*(a+i))->get_salariu_baza())*(100+p3)/100 << "\n";
    }
}

void FirmaProgramare::promoveaza(std::string nume, std::string functie){
    for(int i=0; i<nr_angajati; i++){
        if( (*(a+i))->get_nume() == nume){
            float salariu_baza = (*(a+i))->get_salariu_baza();
            float pts = (*(a+i))->get_procent_taxe();
            
            delete *(a+i);
            
            if(functie == "Programator"){
                *(a+i) = new Programator(nume, functie, salariu_baza, 10);
            }
            
            if(functie == "LiderEchipaProgramare"){
                *(a+i) = new LiderEchipaProgramare(nume, functie, salariu_baza, 10, 0, 500);
            }
        }
    }
    
}