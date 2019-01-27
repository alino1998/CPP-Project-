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
//

void decoupMots(string mytab[],string ligne){
    int p=0;
    string mot="";
    unsigned long a=ligne.size();
    for (int j=0; j<a; j++) {
        mot =mot+ligne[j];
        if (ligne[j]=='\t'||ligne[j]=='.'){
            string mot2=truncateMots(mot, 1);
            mytab[p]=mot2;
            p++;
            mot="";
        }
    }
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
