#include "Social_Media.h"
#include <iostream>
#include <string>
#include <vector>
#include <alorithm>

//
//functii data
//
Data::Data(unsigned int zi, unsigned int luna, unsigned int an):zi(zi), luna(luna), an(an){}
Data:~Data(){}

void Data::afisare(){
    std::cout << zi << "." << luna << "." << an << "\n";
}

unsigned int Data::get_an(){
    return this->an;
}

unsigned int Data::get_luna(){
    return this->luna;
}

unsigned int Data::get_zi(){
    return this->zi;
}

//
//functii ora
//
Ora::Ora(unsigned int ora, unsigned int minut):ora(ora), minut(minut){}
Ora::~Ora(){}
    
void Ora::afisare(){
    std::cout << ora << ":" << minut << "\n"
}

unsigned int Ora::get_ora(){
    return this->ora;
}

unsigned int Ora::get_minut(){
    return this->minut;
}



//
//functii utilizator
//

//constructor
Utilizator::Utilizator(std::string nume="", std::string prenume="", std::string email=""):
                        nume(nume), prenume(prenume), email(email){};
//destructor
Utilizator::~Utilizator(){
    std::cout << "Utilizator sters!" << "\n";
}

//setter
void Utilizator::schimbare_nume(std::string nume_nou, std::string prenume_nou){
    if(nume_nou==this->nume && prenume_nou==this->prenume){
        std::cout << "Numele nou nu poate fi identic cu numele vechi. Incercati din nou!\n"
    }
    else {
        this->nume = nume_nou;
        this->prenume = prenume_nou;
    }
}

//getters
std::string Utilizator::get_nume(){
    return this->nume;
}

std::string Utilizator::get_prenume(){
    return this->prenume;
}

std::string Utilizator::get_email(){
    return this->email;
}

std::vector <Utilizator*> Utilizator::get_prieteni(){
    return this->lista_prieteni;
}

//afisari
void Utilizator::afisare_utilizator(){
    std::cout << nume << " " << prenume << "\n";
}

void Utilizator::afisare_prieteni(){
    for(Utilizator* i:lista_prieteni)
        i->afisare_utilizator();
}

//
//functii postare
//

//constructor
Postare::Postare(Utilizator* user, std::string mesaj, Data data, Ora ora): user(user), data(data), ora(ora){}
//destructor
Postare::~Postare(){
    std::cout << "Postare stearsa\n"; 
}

//getters
Utilizator* Postare::get_user(){
    return this->user;
}

std::string get_mesaj(){
    return this->mesaj;
}

Data get_data(){
    return this->data;
}

Ora get_ora(){
    return this->ora;
}

int get_numar_likes(){
    return numar_likes;
}

//setters
void modificare_mesaj(std::string mesaj_nou){
    this->mesaj = mesaj_nou;
}

void like_post(Utilizator* user){
    this->numar_likes +=1;
    like_users.push_back(user);
}
void dislike_post(Utilizator* user){
    this->numar_likes -=1;
    dislike_users.push_back(user);
}
void afisare_postare(){
    std::cout << "Utilizator: " << user->afisare_utilizator() <<"\n";
    std::cout << "Data: " << data->afisare() << " " << " Ora: " << ora->afisare() << "\n";
    std::cout << "Mesaj:" << mesaj << "\n";
}

//
//functii sortari
//

bool timp(Postare* p1, Postare* p2){
    if((p1->get_data()).get_an()>(p1->get_data()).get_an())
        return true;
    else 
        if((p1->get_data()).get_an()<(p1->get_data()).get_an())
            return false;
        else{


            if((p1->get_data()).get_luna()>(p1->get_data()).get_luna())
                return true;
            else 
                if((p1->get_data()).get_luna()<(p1->get_data()).get_luna())
                    return false;
                else{


                    if((p1->get_data()).get_zi()>(p1->get_data()).get_zi())
                        return true;
                    else 
                        if((p1->get_data()).get_zi()<(p1->get_data()).get_zi())
                            return false;
                        else{


                            if((p1->get_ora()).get_ora()>(p1->get_ora()).get_ora())
                                return true;
                            else 
                                if((p1->get_ora()).get_ora()<(p1->get_ora()).get_ora())
                                    return false;
                                else{


                                    if((p1->get_ora()).get_minut()>(p1->get_ora()).get_minut())
                                        return true;
                                    else 
                                        return false;
                                }
                        }

                }

        }
}

bool likes(Postare* p1, Postare* p2){
    return p1->get_numar_likes()>(p1->get_numar_likes();
}

//
//functii platforma
//

//constructor
Platforma::Platforma(){
}

//destructor
Platforma::~Platforma(){}

//setters
void Platforma::add_utilizator(Utilizator* u){
    utilizatori.push_back(u);
}
void Platforma::add_postare(Postare* p){
    postari.push_back(p);
}

//getters
std::vector Platforma::<Utilizator*> get_utilizatori()[
    return this->utilizatori;
]
std::vector Platforma::<Postare*> get_postari(){
    return this->postari;
}

void Platforma::sorteaza_postari_timp(){
    std::sort(this->begin(), this->end, timp);
}
void Platforma::sorteaza_postari_likes(){
    std::sort(this->begin(), this->end, likes);

}
void Platforma::afisare_feed(){
    for(Postare* i:postari)
        i->afisare_postare();
}

void Platforma::afisare_feed_utilizator(Utilizator* user){
    for(Postare* i:postari)
        for(Utilizator* j:(user->get_prieteni()))
            if(i->get_user()==j)
                i->afisare_postare();
}