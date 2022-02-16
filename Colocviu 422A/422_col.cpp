#include "Card_calatorie.h"
#include <iostream>
#include <iomanip>
#include <string>
//
//functii Card_calatorie
//

Card_calatorie::Card_calatorie(int id, char tip): id(id), tip(tip){}
Card_calatorie::~Card_calatorie(){}

int Card_calatorie::get_id(){
    return this->id;
}

char Card_calatorie::get_tip(){
    return this->tip;
}

void Card_calatorie::set_ultima_validare(int validare){
    this->ultima_validare = validare;
}

int Card_calatorie::get_ultima_validare(){
    return this->ultima_validare;
}

//
//functii Card_autobuz
//

Card_autobuz::Card_autobuz(int id, char tip, int sold): Card_calatorie(id, tip), sold(sold){}
Card_autobuz::~Card_autobuz(){}

void Card_autobuz::afisare(){
    std::cout << this->get_id() << " " << this->get_tip() << " " << sold << " " << this->get_ultima_validare() << "\n";
}

void Card_autobuz::incarcare(int sold){
    this->sold += sold;
}

void Card_autobuz::validare_calatorie(int id, int mom){
    if(sold<3)
        std::cout << "Sold insuficient\n";
    else if(this->get_ultima_validare()==0 || (this->get_ultima_validare() - mom) > 90){
        this->sold -=3;
        this->set_ultima_validare(mom);
        }
        else return;
    
}

int Card_autobuz::get_sold(){
    return this->sold;
}

int Card_autobuz::get_nr_calatorii(){
}

//
//functii Card_metrou
//

Card_metrou::Card_metrou(int id, char tip, int nr_cal): Card_calatorie(id, tip), nr_calatorii(nr_cal){}
Card_metrou::~Card_metrou(){}

void Card_metrou::afisare(){
    std::cout << this->get_id() << " " << this->get_tip() << " " << nr_calatorii << " " << this->get_ultima_validare()  << "\n";
}

void Card_metrou::incarcare(int nr){
    this->nr_calatorii += nr;
}

void Card_metrou::validare_calatorie(int id, int mom){
        if(nr_calatorii<1)
            std::cout << "Numar calatorii insuficient\n";
        else if(this->get_ultima_validare()==0 || (this->get_ultima_validare() - mom) > 90){
            this->nr_calatorii -=1;
            this->set_ultima_validare(mom);
            }
            else return;
}

int Card_metrou::get_nr_calatorii(){
        return this->nr_calatorii;
}

int Card_metrou::get_sold(){
}