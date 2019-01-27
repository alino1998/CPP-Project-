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
using namespace std;


//methodes de traitement auxilliaires

string truncateMots(string mot, int n){
    unsigned long taillemots1=mot.size();
    string motretour="";
    for (int i=0; i<taillemots1-n; i++) {
        motretour += mot[i];
    }
    return motretour;
}
//methodes de decoupage en differents  mot pour creation d'objet
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


//
void Update_f(string f_location,Client tab[],int n){
    
    ofstream fichier(f_location.c_str(), ios::out | ios::trunc);
    if(fichier)
    {
        for (int i=0; i<n; i++) {
            fichier <<tab[i].getCodeClient()<<"\t";
            fichier <<tab[i].getNom()<<"\t";
            fichier <<tab[i].getPrenom()<<"\t";
            fichier <<tab[i].getVille()<<"\t";
            fichier <<tab[i].getSexe()<<"\t";
            fichier <<tab[i].getDateNaissance()<<"."<<endl;
        }
        
        cout << "*****fichier mis a jour*****" << endl;
        fichier.close();
    }
    else
        cerr << "Impossible d'ouvrir le fichier !" << endl;
    
}


void Update_f(string f_location,Produit tab[],int n){
    
    ofstream fichier(f_location.c_str(), ios::out | ios::trunc);
    if(fichier)
    {
        for (int i=0; i<n; i++) {
            fichier <<tab[i].getIdProduit()<<"\t";
            fichier <<tab[i].getNom()<<"\t";
            fichier <<tab[i].getprixUnitaire()<<"\t";
            fichier <<tab[i].getquantite()<<"."<<endl;
        }
        
        cout << "*****fichier mis a jour*****" << endl;
        fichier.close();
    }
    else
        cerr << "Impossible d'ouvrir le fichier !" << endl;
    
}
/*
void Update_f(Achat tab[],int n){
    string const f_location="/Users/mac/Desktop/C++Learning/KabissaProjectCpp2/KabissaProjectCpp2/save_fichiers/test.txt";
    
    ofstream fichier(f_location.c_str(), ios::out | ios::trunc);
    if(fichier)
    {
        for (int i=0; i<n; i++) {
            fichier <<tab[i].getIdAchat()<<"\t";
            fichier <<tab[i].getClient().getNom()<<" "<<tab[i].getClient().getPrenom()<<"\t";
            fichier <<tab[i].getProduitAchete().getIdProduit()<<"\t";
            fichier <<tab[i].getDate()<<"."<<endl;
        }
        
        cout << "*****fichier mis a jour*****" << endl;
        fichier.close();
    }
    else
        cerr << "Impossible d'ouvrir le fichier !" << endl;
    
}
 */

// function to update table


void Update_tab(string f_location,Client tab[],int &n){
    n=0;
    ifstream fichier(f_location.c_str(), ios::in);
    if(fichier)
    {
        string ligne;
        while(getline(fichier, ligne))
        {
            int s=6;
            string recuptab[s];
            decoupMots(recuptab, ligne);
            ajoutToTable(tab, n, recuptab);
        }
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
        while(getline(fichier, ligne))
        {
            int s=4;
            string recuptab[s];
            decoupMots(recuptab, ligne);
            ajoutToTable(tab, n, recuptab);
        }
    }
    else
        cerr << "Impossible d'ouvrir le fichier !" << endl;
}



//int i = std::stoi(a)+10; // string -> integer
//float f = std::stof(a)+10.2; // string -> float

