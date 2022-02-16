#include "Angajat.h"
#include <iostream>
#include <iomanip>
#include <string>


int main(){
    
    int n;
    std::string tip, nume, dep;
    int norma, vechime, prestari;
    float salariu, onorariu;
    Angajat **a = new Angajat*[100];
    
    std::cin >> n;
    
    for(int i=0; i<n; i++){
        std::cin >> tip >> nume >> dep;
        
        if(tip=="salariat"){
            std::cin >> norma >> vechime >> salariu;
            *(a+i) = new Salariat(nume, dep, norma, vechime, salariu);
        }
        
        if(tip=="colaborator"){
            std:: cin >> onorariu >> prestari;
            *(a+i) = new Colaborator(nume, dep, onorariu, prestari);
        }
    }
    
    int x;
    std::cin >> x;
    
    switch(x){
        case 1:{
            std::cin >> dep;
            
            for(int i=0; i<n; i++){
                if( (*(a+i))->get_dep() == dep)
                    (*(a+i))->afisare();
            }    
            break;
        }
        
        case 2:{
            std::cin >> nume;
            for(int i=0; i<n; i++){
                if( (*(a+i))->get_nume() == nume)
                    std::cout << std::fixed << std::setprecision(2) << (*(a+i))->salariu_brut();
            }
            
            break;
        }
        case 3:{
            float max=0;
            int index=0;
            
            for(int i=0; i<n; i++){
                if((*(a+i))->rentabilitate_angajat() > max){
                    max = (*(a+i))->rentabilitate_angajat();
                    index = i;
                }
            }
            
            std::cout << (*(a+index))->get_nume() << "\n";
            
            break;
        }
        case 4:{
            std::cin >> dep;
            float salariu_mediu_brut_dep=0;
            float suma_salarii_brute=0;
            int nr_angajati_dep=0;
            
            for(int i=0; i<n; i++){
                if( (*(a+i))->get_dep() == dep){
                    suma_salarii_brute += (*(a+i))->salariu_brut();
                    nr_angajati_dep++;
                }
            }
            salariu_mediu_brut_dep=suma_salarii_brute/nr_angajati_dep;
            std::cout << std::fixed << std::setprecision(2) << salariu_mediu_brut_dep << "\n";
            break;
        }
    }
    
    return 0;
}