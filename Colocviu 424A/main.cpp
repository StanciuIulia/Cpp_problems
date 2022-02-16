#include "math_functions.h"
#include <iostream>
#include <iomanip>
#include <string>


int nr_functii, nr_coeff, x;
std::string nume_functie;
float constant, coeff;
float *coeff_poly = new float[100];
MathFunction **f = new MathFunction*[100];

int main(){
    
    std::cin >> nr_functii;
    for(int i=0; i<nr_functii; i++){
        std::cin >> nume_functie;
        
        if(nume_functie=="Polynomial"){
            std::cin >> nr_coeff;
            for(int j=0; j<nr_coeff; j++){
                std::cin >> coeff_poly[j];
                //std::cout << coeff_poly[j]<< std::endl;
            }
            *(f+i) = new Polynomial(nume_functie, nr_coeff, coeff_poly);
        }
        
        if(nume_functie=="Quadratic"){
            nr_coeff = 3;
            for(int j=0; j<nr_coeff; j++){
                std::cin >> coeff_poly[j];
            }
            *(f+i) = new Quadratic(nume_functie, nr_coeff, coeff_poly);
        }
        
        if(nume_functie=="Exponential"){
            std::cin >> constant >> coeff;
            *(f+i) = new Exponential(nume_functie, constant, coeff);
        }
    }
    
    std::cin >> x;
    switch(x){
        case 1:{
            for(int i=0; i<nr_functii; i++){
                (*(f+i))->afisare();    
            }
            break;
        }
        
        case 2:{
            for(int i=0; i<nr_functii; i++){
                if((*(f+i))->get_name() == "Quadratic")
                    (*(f+i))->print_roots();    
            }
            break;
        }
        
        case 3:{
            int max_value=0, min_value=0;
            std::cin >> min_value >> max_value;
            
            for(int i=0; i<nr_functii; i++){
                std::cout << std::fixed << std:: setprecision(2) << (*(f+i))->get_max_value(min_value, max_value) << std::endl;    
            }
            break;
        }
        
        case 4:{
            float x[4], y[4];
            for(int i=0; i<3; i++){
                std::cin >> x[i];
            }
            for(int i=0; i<3; i++){
                std::cin >> y[i];
            }
            
            float newy[4];
            
            DiscreteFunction **d = new DiscreteFunction*[100];
            for(int i=0; i<nr_functii; i++){
                
                for(int j=0; j<3; j++){
                    newy[j]=(*(f+i))->get_value(x[j]);
                }    
                *(d+i) = new DiscreteFunction((*(f+i))->get_name(), x, newy);
            }
            
            float min = (*d)->sum(y[0], y[1], y[2]);
            int index = 0;
            
            for(int i=0; i<nr_functii; i++){
                float s = (*(d+i))->sum(y[0], y[1], y[2]);
                if(s<min){
                    min=s;
                    index=i;
                }
            }
            
            (*(f+index))->afisare2();
            std::cout << min << "\n";
            
            break;
        }
    }
    
    
    
    return 0;
}