#ifndef FIRMA_H
#define FIRMA_H
#include <iostream>
#include <string>


class Angajat{
protected:
    std::string nume;
    std::string functie;
    float salariu_baza;
    float procent_taxe_salariu;
public:
    Angajat(std::string, std::string, float);
    virtual ~Angajat();
    
    void set_procent_taxe(float);
    float get_procent_taxe();
    
    virtual float get_salariu_net();
    virtual float get_salariu_brut();
    float get_salariu_baza();
    std::string get_nume();
    std::string get_functie();
    void marire_salariu(float);
    
    virtual void afisare();
    
};

class Analist: public Angajat{
public:
    Analist(std::string, std::string, float);
    ~Analist();

};

class Programator: public Analist{
protected:
    float procent_deducere_salariu_it;
public:
    Programator(std::string, std::string, float, float);
    ~Programator();

    float get_salariu_net();
};

class LiderEchipaProgramare: public Programator{
protected:
    float bonus_vechime_functie;
    int vechime_functie;
public:
    LiderEchipaProgramare(std::string, std::string, float, float, int, float);
    ~LiderEchipaProgramare();
    
    float get_salariu_brut();
    float get_salariu_net();

};

class FirmaProgramare{
private:
    int nr_angajati;
    Angajat **a;
public:
    FirmaProgramare(int, Angajat**);
    ~FirmaProgramare();
    
    Angajat** get_angajati();
    void afiseaza_angajati();
    void afiseaza_salarii();
    void mareste_salarii(float, float, float);
    void promoveaza(std::string, std::string);
};

#endif