//
//  AutresMethodes.cpp
//  Project2Kabissa
//
//  Created by KAO Kezie Hermann on 27/01/19.
//  Copyright © 2019 Alain kabissa @toumaï. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include "Client.h"
#include "Produit.h"
#include "Achat.h"
#include "AutresMethodes.h"
using namespace std;


//fonctions de recherhe cible par id 
Produit searchItem(Produit tab[],int n,int id){
    Produit x;
    for (int i=0; i<n; i++) {
        if(tab[i].getIdProduit()==id){
            x=tab[i];
        }
    }
    return x;
}
Client searchItem(Client tab[],int n,int id){
    Client x;
    for (int i=0; i<n; i++) {
        if(tab[i].getCodeClient()==id){
            x=tab[i];
        }
    }
    return x;
}

// fonctions de coupure de mot de n caractere a partir de la fin

string truncateMots(string mot, int n){
    unsigned long taillemots1=mot.size();
    string motretour="";
    for (int i=0; i<taillemots1-n; i++) {
        motretour += mot[i];
    }
    return motretour;
}

void decoupMots(string mytab[],int &taille,string ligne,char caractere){
    int p=0;
    string mot="";
    unsigned long a=ligne.size();
    for (int j=0; j<a; j++) {
        mot =mot+ligne[j];
        if (ligne[j]==caractere){
            string mot2=truncateMots(mot, 1);
            mytab[p]=mot2;
            p++;
            mot="";
        }
    }
    taille=p;
}

string traitement_date(string dateTo){
    dateTo+="/";
    int s=0,jour=0,mois=0,annee=0;
    string *recuptab=new string[100];
    decoupMots(recuptab,s, dateTo,'/');
    if(s==3){
        jour =std::stoi(recuptab[0]);
        mois =std::stoi(recuptab[1]);
        annee =std::stoi(recuptab[2]);
    }
    delete [] recuptab;
    if (jour>0 && jour<=31 && mois>0 && mois<=12 && annee>0 && annee<=2019) {
        dateTo=truncateMots(dateTo, 1);
        return dateTo;
    }
    else{
        return "Incorrect";
    }
}
string traitement_sexe(string sexeTo){
    if(sexeTo[0]=='m'||sexeTo[0]=='M'){
        return "M";
    }else{
        if(sexeTo[0]=='f'||sexeTo[0]=='F'){
            return "F";
        }else{
            return "Incorrect";
        }
    }
}
