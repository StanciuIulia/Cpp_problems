#include "Card_calatorie.h"
#include <iostream>
#include <iomanip>
#include <string>

int main(){
    int n, x=1;
    std::cin >> n;
    
    char tip =' ';
    int id, sold, nr_cal, inc, moment_validare, id_giver, id_getter;
    Card_calatorie **c = new Card_calatorie*[10];
    
    for(int i=0; i<n; i++){
        std::cin >> tip >> id;
        if(tip == 'a'){
            std::cin >> sold;
            *(c+i) = new Card_autobuz(id, tip, sold);
            (*(c+i))->set_ultima_validare(0);
            
        }
        if(tip == 'm'){
            std::cin >> nr_cal;
            *(c+i) = new Card_metrou(id, tip, nr_cal);
            (*(c+i))->set_ultima_validare(0);
        }
    }
    
    while(x>0 && x<5){
        std::cin >> x;
    
    switch(x){
        case 1:{
            
            for(int i=0; i<n; i++){
                (*(c+i))->afisare();
            }
            break;
        }
        
        case 2:{
            std::cin >> id >> inc;
            for(int i=0; i<n; i++){
                if( (*(c+i))->get_id() == id ){
                        (*(c+i))->incarcare(inc);
                }
            }
            break;
        }
        
        case 3:{
            std::cin >> id >> moment_validare;
            for(int i=0; i<n; i++){
                if( (*(c+i))->get_id() == id ){
                        (*(c+i))->validare_calatorie(id, moment_validare);
                }
            }
            break;
        }
        
        case 4:{
            std::cin >> id_giver >> id_getter >> inc;
            for(int i=0; i<n; i++){
                if( (*(c+i))->get_id() == id_giver){    
                    for(int j=0; j<n; j++){
                        
                        if( (*(c+j))->get_id() == id_getter){
                            
                            if((*(c+i))->get_tip() != (*(c+j))->get_tip()){
                                std::cout << "Transfer nereusit\n";
                            }
                            else {
                                if((*(c+i))->get_tip() == 'a')
                                    if((*(c+i))->get_sold() > inc){
                                        (*(c+i))->incarcare(inc*(-1));
                                    (   *(c+j))->incarcare(inc);
                                    }
                                    else std::cout << "Transfer nereusit\n";
                                
                                if((*(c+i))->get_tip() == 'm')
                                    if((*(c+i))->get_nr_calatorii() > inc){
                                        (*(c+i))->incarcare(inc*(-1));
                                    (   *(c+j))->incarcare(inc);
                                    }
                                    else std::cout << "Transfer nereusit\n";
                            }
                        }
                    }
                }
            }
            break;
        }
    }
    
    }
    return 0;
}