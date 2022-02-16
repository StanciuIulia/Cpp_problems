#include "math_functions.h"
#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>

//functii MathFunction
MathFunction::MathFunction(std::string name=""): function_name(name){}

MathFunction::~MathFunction(){}

void MathFunction::afisare(){
    std::cout << this->function_name;
}

void MathFunction::afisare2(){
}

std::string MathFunction::get_name(){
    return this->function_name;
}

float MathFunction::get_value(int n){
    return 0;
}

float MathFunction::get_max_value(int min, int max){
    float maxim=0;
    for(int i=min; i<=max; i++){
        if(maxim<this->get_value(i))
            maxim=this->get_value(i);
    }
    return maxim;
}

void MathFunction::print_roots(){}

//functii Polynomial
Polynomial::Polynomial(std::string name="", int nr=0, float* coeff=nullptr): MathFunction(name), nr_coeff(nr){
    coefficients = new float[100];
    for(int i=0; i<nr_coeff; i++)
        *(this->coefficients+i) = *(coeff+i);
}

Polynomial::~Polynomial(){}

void Polynomial::afisare(){
    std::cout << this->function_name <<std::endl;
    std::cout << "f(x) = ";
    int i=0;
    
    while(i<nr_coeff){
        if(i==0){
            if(coefficients[i]<0){
                std::cout << " - ";
                std::cout << coefficients[i]*(-1);
            }
            if(coefficients[i]>0)
                std::cout << coefficients[i];
        }
                
        if(i==1 && coefficients[i]!=0){
            if(coefficients[i]<0){
                std::cout << " - ";
                if(coefficients[i] != -1)
                    std::cout << coefficients[i]*(-1);
            }
            if(coefficients[i]>0){
                std::cout << " + ";
                if(coefficients[i] != 1)
                    std::cout << coefficients[i];
            }
            std::cout << "x";
        }    
        
        if(i>1 && coefficients[i]!=0){
            if(coefficients[i]<0){
                std::cout << " - ";
                if(coefficients[i] != -1)
                    std::cout <<coefficients[i]*(-1);
            }
            else if(coefficients[i]>0){
                std::cout << " + ";
                if(coefficients[i] != 1)
                    std::cout <<coefficients[i];
            }
            std::cout << "x^" << i;
        }
    i++;
    }
    std::cout << std::endl;
}

void Polynomial::afisare2(){
    std::cout << "f(x) = ";
    int i=0;
    
    while(i<nr_coeff){
        if(i==0){
            if(coefficients[i]<0){
                std::cout << " - ";
                std::cout << coefficients[i]*(-1);
            }
            if(coefficients[i]>0)
                std::cout << coefficients[i];
        }
                
        if(i==1 && coefficients[i]!=0){
            if(coefficients[i]<0){
                std::cout << " - ";
                if(coefficients[i] != -1)
                    std::cout << coefficients[i]*(-1);
            }
            if(coefficients[i]>0){
                std::cout << " + ";
                if(coefficients[i] != 1)
                    std::cout << coefficients[i];
            }
            std::cout << "x";
        }    
        
        if(i>1 && coefficients[i]!=0){
            if(coefficients[i]<0){
                std::cout << " - ";
                if(coefficients[i] != -1)
                    std::cout <<coefficients[i]*(-1);
            }
            else if(coefficients[i]>0){
                std::cout << " + ";
                if(coefficients[i] != 1)
                    std::cout <<coefficients[i];
            }
            std::cout << "x^" << i;
        }
    i++;
    }
    std::cout << std::endl;
}

float Polynomial::get_value(int n){
    float f=0;
    for(int i=0; i<nr_coeff; i++)
        f+=coefficients[i]*pow(n,i);
    return f;
}


//functii Quadric
Quadratic::Quadratic(std::string name = "", int nr=0, float *coeff=nullptr): Polynomial(name, nr, coeff){}
Quadratic::~Quadratic(){}

void Quadratic::print_roots(){
    float x1=0, x2=0;
    
    x1 = (-coefficients[1] + sqrt(coefficients[1]*coefficients[1]-4*coefficients[0]*coefficients[2]))/(2*coefficients[2]);
    x2 = (-coefficients[1] - sqrt(coefficients[1]*coefficients[1]-4*coefficients[0]*coefficients[2]))/(2*coefficients[2]);
    
    std::cout << std::fixed << std::setprecision(2);
    if(x1==x2){
        std::cout << "X1 = X2 = " << x1 << std::endl;
    }
    else {
        std::cout << "X1 = "  << x1 << std::endl;
        std::cout << "X2 = "  << x2 << std::endl;
    }
}

//functii Exponential
Exponential::Exponential(std::string name, float constant, float exp_coeff): MathFunction(name), constant(constant), exp_coeff(exp_coeff){}

Exponential::~Exponential(){}

void Exponential::afisare(){
    std::cout << this->function_name <<std::endl;
    std::cout << "f(x) = ";
    if(constant > 0)
        std::cout << this->constant;
    if(constant < 0)
        std::cout << "- " << (this->constant)*(-1);
        
    if(this->exp_coeff > 0){
        std::cout << " + ";
        if(this->exp_coeff =! 1)
            std::cout << this->exp_coeff;
    }
    if(constant < 0){
        std::cout << " - ";
        if(this->exp_coeff =! -1)
            std::cout << (this->exp_coeff)*(-1);
    }

    std::cout << "e^x"<< std::endl;
}

void Exponential::afisare2(){
    std::cout << "f(x) = ";
    if(constant > 0)
        std::cout << this->constant;
    if(constant < 0)
        std::cout << "- " << (this->constant)*(-1);
        
    if(this->exp_coeff > 0){
        std::cout << " + ";
        if(this->exp_coeff > 1)
            std::cout << this->exp_coeff;
    }
    if(constant < 0){
        std::cout << " - ";
        if(this->exp_coeff < -1)
            std::cout << (this->exp_coeff)*(-1);
    }

    std::cout << "e^x"<< std::endl;
}

float Exponential::get_value(int n){
    float f=0;
    f = constant + exp_coeff*pow(e,n);
    return f;
}

//functii descrete
DiscreteFunction::DiscreteFunction(std::string name, float x[3], float y[3]):MathFunction(name){
    for(int i=0; i<3; i++){
        x_values[i]=x[i];
        y_values[i]=y[i];
    }
}

//DiscreteFunction::~DiscreteFunction(){}

float DiscreteFunction::sum(int y1, int y2, int y3){
    float sum=0;
    sum = abs(y1-y_values[0])+abs(y2-y_values[1])+abs(y3-y_values[2]);
    
    return sum;
}


