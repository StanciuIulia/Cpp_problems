#ifndef MATH_FUNCTIONS_H
#define MATH_FUNCTIONS_H

#include <string>

class MathFunction{
    protected:
        std::string function_name;
    public:
        MathFunction(std::string);
        ~MathFunction();
        std::string get_name();
        virtual float get_value(int);
        float get_max_value(int, int);
        virtual void afisare();
        virtual void afisare2();
        virtual void print_roots();
};


class Polynomial: public MathFunction{
    protected:
        int nr_coeff;
        float* coefficients;
    public:
        Polynomial(std::string, int, float*);
        ~Polynomial();
        void afisare();
        void afisare2();
        float get_value(int);
};


class Exponential: public MathFunction{
    private:
        const float e=2.71;
        float constant;
        float exp_coeff;
    public:
        Exponential(std::string, float, float);
        ~Exponential();
        void afisare();
        void afisare2();
        float get_value(int);
};

class DiscreteFunction: public MathFunction{
    private:
        float x_values[100];
        float y_values[100];
    public:
        DiscreteFunction(std::string, float[], float[]);
        //~DiscreteFunction();
        float sum(int, int, int);
};

class Quadratic: public Polynomial{
    public:
        Quadratic(std::string, int, float[]);
        ~Quadratic();
        void print_roots();
};

#endif