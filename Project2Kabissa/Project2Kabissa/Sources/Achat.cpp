//
//  Achat.cpp
//  Project2Kabissa
//
//  Created by KAO Kezie Hermann on 25/01/19.
//  Copyright © 2019 Alain kabissa @toumaï. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include "Produit.h"
#include "Achat.h"
#include "Client.h"
using namespace std;

//constructeur et desctructeur


Achat::Achat(){
    IdAchat=0;
    client=Client();;
    ProduitAchete=Produit();
    date="0/0/0";
}

Achat::Achat(int id,Client p,Produit x,string d){
    IdAchat=id;
    client=Client(p);
    ProduitAchete=Produit(x);
    date=d;
}

Achat::~Achat(){
}

//accesseurs

int Achat::getIdAchat(){
    return IdAchat;
};
Client Achat::getClient(){
    return client;
};
Produit Achat::getProduitAchete(){
    return ProduitAchete;
};
string Achat::getDate(){
    return date;
};

//modificateurs

void Achat::setIdAchat(int id){
    IdAchat=id;
};
void Achat::setClient(Client c){
    client=c;
};
void Achat::setProduitAchete(Produit p){
    ProduitAchete=p;
};
void Achat::setDate(string s){
    date=s;
};

//affichage
void Achat::afficher(){
    cout<<IdAchat;
    cout<<" | "<<client.getNom()<<" "<<client.getPrenom()<<" | ";
    cout<<ProduitAchete.getIdProduit()<<" | "<<date<<endl;
}
