#ifndef SOCIAL_MEDIA_H
#define SOCIAL_MEDIA_H

#include <string>
#include <vector>

class Data{
private:
    unsigned int zi;
    unsigned int luna;
    unsigned int an;
public:
    Data(unsigned int, unsigned int, unsigned int);
    ~Data();
    void afisare();
    unsigned int get_zi();
    unsigned int get_luna();
    unsigned int get_an();
};

class Ora{
private:
    unsigned int ora;
    unsigned int minut;
public:
    Ora(unsigned int, unsigned int);
    ~Ora();
    void afisare();
    unsigned int get_ora();
    unsigned int get_minut();
}

class Utilizator{
private:
    std::string nume;
    std::string prenume;
    std::string email;
    std::vector <Utilizator*> lista_prieteni;

public:
    Utilizator(std::string, std::string, std::string);
    ~Utilizator();
    void schimbare_nume(std::string, std::string);
    std::string get_nume();
    std::string get_prenume();
    std::string get_email();
    std::vector <Utilizator*> get_prieteni()
    void afisare_utilizator();
    void afisare_prieteni();

};

class Postare{
private:
    Utilizator* user;
    std::string mesaj;
    Data data_postarii;
    Ora ora_postarii;
    int numar_likes;
    std::vector <Utilizator*> like_users;
    std::vector <Utilizator*> dislike_users;
public:
    Postare(Utilizator*, std::string, Data ,Ora);
    ~Postare();
    Utilizator* get_user();
    std::string get_mesaj()
    Data get_data()
    Ora get_ora()
    int get_numar_likes()
    void modificare_mesaj(std::string);
    void like_post(Utilizator*);
    void dislike_post(Utilizator*);
    void afisare_postare();
};



class Platforma{
private:
    std::vector <Utilizator*> utilizatori;
    std::vector <Postare*> postari;
public:
    Platforma();
    ~Platforma();
    void add_utilizator(Utilizator*);
    void add_postare(Postare*);
    std::vector <Utilizator*> get_utilizatori();
    std::vector <Postare*> get_postari();
    void sorteaza_postari_timp();
    void sorteaza_postari_likes();
    void afisare feed();
    void afisare_feed_utilizator(Utilizator*);
};


#endif