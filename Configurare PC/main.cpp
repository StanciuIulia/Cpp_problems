#include "echipament_electronic.h"
#include <string>
#include <iostream>

int main(){
int x=1, nr_cpu=0, nr_gpu=0, nr_memorii=0;
Manager man = Manager();

int memorie=0, frecventa=0;
float pret=0, memorie_stocare=0;
std::string nume_comp="", tip_comp="", socket="";
std::string nume_cpu="", nume_gpu="", nume_stocare="";

while(x>0 && x<5){
    std::cin >> x;
    switch(x){
        case 1:{
            std::cin >> pret >> nume_comp >> tip_comp;
            
            if(tip_comp=="placa_baza"){
                std::cin >> socket;
                Placa_baza *p = new Placa_baza(pret, nume_comp, tip_comp, socket);
                man.add_placa(p);
            }
            
            if(tip_comp=="cpu"){
                std::cin.ignore();
                getline(std::cin, socket);
                std::cin >> frecventa;
                CPU *cpu = new CPU(pret, nume_comp, tip_comp, socket,frecventa);
                man.add_cpu(cpu, nr_cpu);
                nr_cpu++;
            }
            
            if(tip_comp=="gpu"){
                std::cin >> memorie;
                GPU *gpu = new GPU(pret, nume_comp, tip_comp, memorie);
                man.add_gpu(gpu, nr_gpu);
                nr_gpu++;
            }
            
            if(tip_comp=="stocare"){
                std::cin >> memorie_stocare;
                Stocare *memorie = new Stocare(pret, nume_comp, tip_comp, memorie_stocare);
                man.add_memorie(memorie, nr_memorii);
                nr_memorii++;
                
            }
            break;
        }
        case 2:{
            man.afisare(nr_cpu, nr_gpu, nr_memorii);
            break;
        }
        case 3:{
            int index_cpu=0, index_gpu=0, index_stocare=0;
            
            std::cin >> nume_cpu >> nume_gpu >> nume_stocare;
            for(int i=0; i<nr_cpu; i++)
                if((*(man.procesoare+i))->get_nume()==nume_cpu)
                    index_cpu = i;
            for(int i=0; i<nr_gpu; i++)
                if((*(man.p_grafice+i))->get_nume()==nume_gpu)
                    index_gpu = i;
            for(int i=0; i<nr_memorii; i++)
                if((*(man.memorii+i))->get_nume()==nume_stocare)
                    index_stocare = i;
                    
            PC pc_configurat(man.placa, *(man.procesoare+index_cpu), *(man.p_grafice+index_gpu), *(man.memorii+index_stocare));
            pc_configurat.compatibilitate();
            break;
        }
        case 4:{
            float buget=0;
            std::cin >> buget;
            
            man.sortare_cpu(nr_cpu);
            man.sortare_gpu(nr_gpu);
            man.sortare_stocare(nr_memorii);
            
            PC configurare_buget(man.placa, *man.procesoare, *man.p_grafice, *man.memorii);
            PC configurare_buget_anterior(man.placa, *man.procesoare, *man.p_grafice, *man.memorii);
            
            int i=1;
            while(i<nr_cpu){
                if(configurare_buget.calcul_pret()>buget){
                    configurare_buget.afisare();
                    break;
                }
                else{
                    if((*(man.procesoare+i))->get_socket()==(man.placa)->get_socket())
                        configurare_buget.set_cpu(*(man.procesoare+i));
                    if(configurare_buget.calcul_pret()>buget){
                        configurare_buget_anterior.afisare();
                        break;
                    }
                    else{
                        if((*(man.procesoare+i))->get_socket()==(man.placa)->get_socket())
                            configurare_buget_anterior.set_cpu(*(man.procesoare+i));
                        configurare_buget.set_gpu(*(man.p_grafice+i));
                        if(configurare_buget.calcul_pret()>buget){
                            configurare_buget_anterior.afisare();
                            break;
                        }
                        else{
                            configurare_buget_anterior.set_gpu(*(man.p_grafice+i));
                            configurare_buget.set_s(*(man.memorii+i));
                            if(configurare_buget.calcul_pret()>buget){
                                configurare_buget_anterior.afisare();
                                break;
                            }
                            else{
                                configurare_buget_anterior.set_s(*(man.memorii+i));
                            }
                        }
                    }
                }
            i++;       
            }                    
            

            break;
        }
    }

}    
    return 0;
}