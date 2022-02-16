#ifndef CARD_CALATORIE_H
#define CARD_CALATORIE_H

class Card_calatorie{
private:
    int id;
    char tip;
    int ultima_validare = 0;
public:
    Card_calatorie(int, char);
    ~Card_calatorie();
    
    void set_ultima_validare(int);
    
    int get_ultima_validare();
    int get_id();
    char get_tip();
    
    virtual void afisare() = 0;
    virtual void validare_calatorie(int, int)=0;
    virtual void incarcare(int)=0;
    virtual int get_sold() = 0;
    virtual int get_nr_calatorii() = 0;
};

class Card_autobuz: public Card_calatorie{
private:
    int sold;
public:
    void afisare();
    void incarcare(int);
    void validare_calatorie(int, int);
    int get_sold();
    int get_nr_calatorii();
    Card_autobuz(int, char, int);
    ~Card_autobuz();
};

class Card_metrou: public Card_calatorie{
private:
    int nr_calatorii;
public:
    void afisare();
    void incarcare(int);
    void validare_calatorie(int, int);
    int get_sold();
    int get_nr_calatorii();
    Card_metrou(int, char, int);
    ~Card_metrou();
};

#endif