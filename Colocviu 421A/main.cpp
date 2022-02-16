#include "Firma.h"
#include <iostream>
#include <string>


int main(){
    
    int nr, x;
    std::string nume, functie;
    float salariu_baza, vechime;
    Angajat **angajat = new Angajat*[100];
    
    
    std::cin >> nr;
    
    for(int i=0; i<nr; i++){
        std::cin.ignore();
        getline(std::cin,nume);
        std::cin>> functie >> salariu_baza;
        
        if(functie == "Analist"){
            *(angajat+i) =  new Analist(nume, functie, salariu_baza);
            (*(angajat+i))->set_procent_taxe(40);
            
        }
        
        if(functie == "Programator"){
            *(angajat+i) =  new Programator(nume, functie, salariu_baza, 10);
            (*(angajat+i))->set_procent_taxe(40);
            
        }
        
        if(functie == "LiderEchipaProgramare"){
            std::cin >> vechime;
            *(angajat+i) =  new LiderEchipaProgramare(nume, functie, salariu_baza, 10,  vechime, 500);
            (*(angajat+i))->set_procent_taxe(40);
            
        }
    }
    
    
    FirmaProgramare firma(nr, angajat);
    
    std::cin >> x;
    
switch(x){
    case 1:{
        firma.afiseaza_angajati();
        break;
    }
    case 2:{
        firma.afiseaza_salarii();
        break;
    }
    case 3:{
        int p1, p2, p3;
        std::cin >> functie >> p1 >> functie >> p2 >> functie >> p3;
        firma.mareste_salarii(p1,p2,p3);
        break;
    }
    case 4:{
        std::cin.ignore();
        getline(std::cin, nume);
        std::cin >> functie;
        
        firma.promoveaza(nume, functie);
        firma.afiseaza_angajati();
        break;
    }
}
    
    
    return 0;
}