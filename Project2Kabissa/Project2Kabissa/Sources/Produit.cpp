//
//  Produit.cpp
//  Project2Kabissa
//
//  Created by KAO Kezie Hermann on 25/01/19.
//  Copyright © 2019 Alain kabissa @toumaï. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include "Produit.h"
using namespace std;

//constructeur et desctructeur


Produit::Produit(){
    IdProduit=0;
    nom="a renseigner";
    prixUnitaire=0;
    quantite=0;
}

Produit::Produit(int id,string n,int p,int q){
    IdProduit=id;
    nom=n;
    prixUnitaire=p;
    quantite=q;
}

Produit::Produit(Produit &p){
    IdProduit=p.IdProduit;
    nom=p.nom;
    prixUnitaire=p.prixUnitaire;
    quantite=p.quantite;
}

Produit::~Produit(){
}

//accesseurs
int Produit::getIdProduit(){
    return IdProduit;
};
string Produit::getNom(){
    return nom;
};
int Produit::getprixUnitaire(){
    return prixUnitaire;
};
int Produit::getquantite(){
    return quantite;
};

//modificateurs

void Produit::setIdProduit(int id){
    IdProduit=id;
};
void Produit::setNom(string n){
    nom=n;
};
void Produit::setprixUnitaire(int p){
    prixUnitaire=p;
};
void Produit::setquantite(int q){
    quantite=q;
};

//affichage
void Produit::afficher(){
    cout<<IdProduit<<" | "<<nom<<" | "<<prixUnitaire<<" DH | "<<quantite<<endl;
}
