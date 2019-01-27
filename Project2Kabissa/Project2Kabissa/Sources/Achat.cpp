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
    client=Client();
    taillePanier=1;
    for (int i=0; i<taillePanier; i++) {
        panierAchat[i]=Produit();
    }
    date="neant";
}

Achat::Achat(int id,Client p,Produit tab[],int taille,string d){
    IdAchat=id;
    client=Client(p);
    taillePanier=taille;
    for (int i=0; i<taillePanier; i++) {
        panierAchat[i]=tab[i];
    }
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
void Achat::getPanierAchat(Produit tab[],int &n){
    n=taillePanier;
    for (int i=0; i<n; i++) {
        tab[i]=panierAchat[i];
    }
}
int Achat::getTaillePanier(){
    return taillePanier;
}
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
void Achat::setTaillePanier(int n){
    taillePanier=n;
}
void Achat::setPanierAchat(Produit tab[], int n){
    setTaillePanier(n);
    for (int i=0; i<taillePanier; i++) {
        panierAchat[i]=tab[i];
    }
}
void Achat::setDate(string s){
    date=s;
};

//affichage
void Achat::afficher(){
    cout<<IdAchat;
    cout<<" | "<<client.getNom()<<" "<<client.getPrenom()<<" | les produits achetés [ ";
    for (int i=0; i<taillePanier; i++) {
        cout<<panierAchat[i].getNom();
        if(i<taillePanier-1){
            cout<<" ,";
        }
    }
    cout<<" ] | "<<date<<endl;
}
