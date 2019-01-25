//
//  Client.cpp
//  Project2Kabissa
//
//  Created by KAO Kezie Hermann on 25/01/19.
//  Copyright © 2019 Alain kabissa @toumaï. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include "Client.h"
using namespace std;

//constructeur et desctructeur


Client::Client(){
    compteurClient++;
    codeClient=compteurClient;
    nom="Aucun";
    prenom="Aucun";
    ville="Aucun";
    sexe="nom definit";
    dateNaissance="neant";
}

Client::Client(string name1,string prenom1,string ville1,string sexe1,string d){
    compteurClient++;
    codeClient=compteurClient;
    nom=name1;
    prenom=prenom1;
    ville=ville1;
    sexe=sexe1;
    dateNaissance=d;
}

Client::Client(Client &p){
    codeClient=p.codeClient;
    nom=p.nom;
    prenom=p.prenom;
    ville=p.ville;
    sexe=p.sexe;
    dateNaissance=p.dateNaissance;
}

Client::~Client(){
}

//accesseurs
int Client::getCodeClient(){
    return codeClient;
}

string Client::getNom(){
    return nom;
}

string Client::getPrenom(){
    return prenom;
}

string Client::getVille(){
    return ville;
}

string Client::getSexe(){
    return sexe;
}

string Client::getDateNaissance(){
    return dateNaissance;
}

//modificateurs

void Client::setNom(string newValeur){
    nom=newValeur;
}

void Client::setPrenom(string newValeur){
    prenom=newValeur;
}

void Client::setVille(string newValeur){
    ville=newValeur;
}

void Client::setSexe(string newValeur){
    sexe=newValeur;
}

void Client::setDateNaissance(string newValeur){
    dateNaissance=newValeur;
}


//affichage
void Client::afficher(){
    cout<<codeClient<<" | "<<nom<<" "<<prenom<<" | "<<ville<<" | "<<sexe<<" | ";
    cout<<dateNaissance<<endl;
}

