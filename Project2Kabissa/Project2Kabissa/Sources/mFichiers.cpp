//
//  mFichiers.cpp
//  Project2Kabissa
//
//  Created by KAO Kezie Hermann on 26/01/19.
//  Copyright © 2019 Alain kabissa @toumaï. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <fstream>
#include "mFichiers.h"
#include <string>
#include "Client.h"
#include "Produit.h"
#include "Achat.h"
#include "AutresMethodes.h"
using namespace std;


//methodes d'ajout aux tables du programme

void ajoutToTable(Client tabP[],int &n,string tabDeVal[]){
    string nom,prenom,ville,sexe,dateDeNaissance;
    int id;
    id=std::stoi(tabDeVal[0]);
    nom=tabDeVal[1];
    prenom=tabDeVal[2];
    ville=tabDeVal[3];
    sexe=tabDeVal[4];
    dateDeNaissance=tabDeVal[5];
    Client newClient(id,nom,prenom,ville,sexe,dateDeNaissance);
    tabP[n]=newClient;
    n++;
}

void ajoutToTable(Produit tabP[],int &n,string tabDeVal[]){
    string nom;
    int id,prix,quantite;
    id=std::stoi(tabDeVal[0]);
    nom=tabDeVal[1];
    prix=std::stoi(tabDeVal[2]);
    quantite=std::stoi(tabDeVal[3]);
    Produit newP(id,nom,prix,quantite);
    tabP[n]=newP;
    n++;
}
void ajoutToTable(Achat tabA[],int &na,Client tabC[],int nc,Produit tabP[],int np,string tabDeVal[]){
    string date,chaineIdProd;
    int idachat,idclient,taille=100,tailleReel=0,idprod=0,s=0;
    Client clientfound;
    Produit prodAcheter;
    idachat=std::stoi(tabDeVal[0]);
    idclient=std::stoi(tabDeVal[2]);
    chaineIdProd=tabDeVal[3];
    clientfound=searchItem(tabC, nc, idclient);
    Produit *tabprim=new Produit[taille];
    string *recuptab=new string[taille];
    decoupMots(recuptab, s, chaineIdProd, '-');
    for (int i=0; i<s; i++) {
        idprod=std::stoi(recuptab[i]);
        prodAcheter=searchItem(tabP, np, idprod);
        tabprim[tailleReel]=prodAcheter;
        tailleReel++;
    }
    date=tabDeVal[4];
    Achat newAchat(idachat,clientfound,tabprim,tailleReel,date);
    delete [] tabprim;
    delete [] recuptab;
    tabA[na]=newAchat;
    na++;
}

//
void Update_f(string f_location,Client tab[],int n){
    
    ofstream fichier(f_location.c_str(), ios::out | ios::trunc);
    if(fichier)
    {
        fichier<<"*fichier des clients*"<<endl;
        for (int i=0; i<n; i++) {
            fichier <<tab[i].getCodeClient()<<"\t";
            fichier <<tab[i].getNom()<<"\t";
            fichier <<tab[i].getPrenom()<<"\t";
            fichier <<tab[i].getVille()<<"\t";
            fichier <<tab[i].getSexe()<<"\t";
            fichier <<tab[i].getDateNaissance()<<"."<<endl;
        }
        fichier.close();
    }
    else
        cerr << "Impossible d'ouvrir le fichier !" << endl;
    
}


void Update_f(string f_location,Produit tab[],int n){
    
    ofstream fichier(f_location.c_str(), ios::out | ios::app);
    if(fichier)
    {
        fichier<<"*fichier des produits*"<<endl;
        for (int i=0; i<n; i++) {
            fichier <<tab[i].getIdProduit()<<"\t";
            fichier <<tab[i].getNom()<<"\t";
            fichier <<tab[i].getprixUnitaire()<<"\t";
            fichier <<tab[i].getquantite()<<"."<<endl;
        }
        fichier.close();
    }
    else
        cerr << "Impossible d'ouvrir le fichier !" << endl;
    
}

void Update_f(string f_location,Achat tab[],int n){
    ofstream fichier(f_location.c_str(), ios::out | ios::app);
    if(fichier)
    {
        fichier<<"*fichier des achats*"<<endl;
        for (int i=0; i<n; i++) {
            fichier <<tab[i].getIdAchat()<<"\t";
            fichier <<tab[i].getClient().getNom()<<" "<<tab[i].getClient().getPrenom()<<"\t";
            fichier <<tab[i].getClient().getCodeClient()<<"\t";
            string idProd="",recup="";
            Produit *tabprim=new Produit[100];
            int taille=0;
            tab[i].getPanierAchat(tabprim, taille);
            for (int j=0; j<taille; j++) {
                recup=std::to_string(tabprim[j].getIdProduit());
                idProd +=recup+"-";
            }
            delete [] tabprim;
            fichier <<idProd<<"\t";
            fichier <<tab[i].getDate()<<"."<<endl;
        }
        fichier.close();
    }
    else
        cerr << "Impossible d'ouvrir le fichier !" << endl;
    
}


// function to update table


void Update_tab(string f_location,Client tab[],int &n){
    n=0;
    ifstream fichier(f_location.c_str(), ios::in);
    if(fichier)
    {
        string ligne;
        bool test=false;
        while(getline(fichier, ligne))
        {
            if (ligne=="*fichier des produits*"||ligne=="*fichier des achats*") {
                test=false;
            }
            if (test) {
                int s=6;
                string recuptab[s];
                decoupMots(recuptab, ligne);
                ajoutToTable(tab, n, recuptab);
            }
            if (ligne=="*fichier des clients*") {
                test=true;
            }
        }
        fichier.close();
    }
    else
        cerr << "Impossible d'ouvrir le fichier !" << endl;
}

void Update_tab(string f_location,Produit tab[],int &n){
    n=0;
    ifstream fichier(f_location.c_str(), ios::in);
    if(fichier)
    {
        string ligne;
        bool test=false;
        while(getline(fichier, ligne))
        {
            if (ligne=="*fichier des clients*"||ligne=="*fichier des achats*") {
                test=false;
            }
            if (test) {
                int s=4;
                string recuptab[s];
                decoupMots(recuptab, ligne);
                ajoutToTable(tab, n, recuptab);
            }
            if (ligne=="*fichier des produits*") {
                test=true;
            }
        }
        fichier.close();
    }
    else
        cerr << "Impossible d'ouvrir le fichier !" << endl;
}

void Update_tab(string f_location,Achat tabA[],int &na,Client tabC[],int nc,Produit tabP[],int np ){
    na=0;
    ifstream fichier(f_location.c_str(), ios::in);
    if(fichier)
    {
        string ligne;
        bool test=false;
        while(getline(fichier, ligne))
        {
            if (ligne=="*fichier des clients*"||ligne=="*fichier des produits*") {
                test=false;
            }
            if (test) {
                int s=5;
                string recuptab[s];
                decoupMots(recuptab, ligne);
                ajoutToTable(tabA,na,tabC,nc,tabP,np, recuptab);
            }
            if (ligne=="*fichier des achats*") {
                test=true;
            }
        }
        fichier.close();
    }
    else
        cerr << "Impossible d'ouvrir le fichier !" << endl;
}



//int i = std::stoi(a)+10; // string -> integer
//float f = std::stof(a)+10.2; // string -> float

