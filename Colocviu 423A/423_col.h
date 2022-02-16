#ifndef ANGAJAT_H
#define ANGAJAT_H
#include <string>

class Angajat{
private:
    std::string nume;
    std::string departament;
public:
    Angajat(std::string, std::string);
    ~Angajat();
    std::string get_nume();
    std::string get_dep();
    virtual void afisare() = 0;
    virtual float salariu_brut() = 0;
    virtual float rentabilitate_angajat() = 0;
};


class Salariat: public Angajat{
private:
    int norma;
    int vechime;
    float salariu_net;
public:
    Salariat(std::string, std::string, int, int, float);
    ~Salariat();
    void afisare();
    float salariu_brut();
    float rentabilitate_angajat();
};

class Colaborator: public Angajat{
private:
    float onorariu;
    int nr_prestari_anuale;
public:
    Colaborator(std::string, std::string, float, int);
    ~Colaborator();
    void afisare();
    float salariu_brut();
    float rentabilitate_angajat();
};

#endif