//
//  mListerRechercher.cpp
//  Project2Kabissa
//
//  Created by KAO Kezie Hermann on 26/01/19.
//  Copyright © 2019 Alain kabissa @toumaï. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include "Client.h"
#include "Produit.h"
#include "Achat.h"
#include "mListerRechercher.h"
using namespace std;

//affichages des objets
void affichage(Client tab[],int n){
    cout<<"lsite des clients"<<endl;
    for (int i=0; i<n; i++) {
        tab[i].afficher();
    }
    cout<<"*****Client affiché*****"<<endl;
}
void affichage(Produit tab[],int n){
    cout<<"listes des produits disponibles "<<endl;
    for (int i=0; i<n; i++) {
        tab[i].afficher();
    }
    cout<<"*****Produit affiché*****"<<endl;
}
void affichage(Achat tab[],int n){
    cout<<"listes des achats effectués "<<endl;
    for (int i=0; i<n; i++) {
        tab[i].afficher();
    }
    cout<<"*****Achat affiché*****"<<endl;
}

//recherche d'un objet

void recherche(Client tab[],int n){
    int choix;
    bool x=true;
    cout<<"Choissisez le type de recherche que vous voulez effectuer :"<<endl;
    cout<<"1 : par code client "<<endl;
    cout<<"2 : par nom "<<endl;
    cout<<"3 : par prenom "<<endl;
    cout<<"4 : par ville "<<endl;
    cout<<"5 : par sexe "<<endl;
    cout<<"6 : par date de naissance "<<endl;
    cout<< "votre choix : ";
    cin>>choix;
    cin.ignore();
    switch (choix) {
        case 1:
        {int Arechercher;
            cout<<"entrez le code client du client a rechercher : ";
            cin>>Arechercher;
            for (int i=0; i<n; i++) {
                if(tab[i].getCodeClient()==Arechercher){
                    tab[i].afficher();
                    x=false;
                }
            }
            if(x){
                cout<<"*****Aucun client correspondant a votre type de recherche*****"<<endl;
            }else{
                cout<<"*****Recherche terminée*****"<<endl;
            }}
            break;
        case 2:
        {string Arechercher;
            cout<<"entrez le nom du client a rechercher : ";
            getline(cin,Arechercher);
            for (int i=0; i<n; i++) {
                if(tab[i].getNom()==Arechercher){
                    tab[i].afficher();
                    x=false;
                }
            }
            if(x){
                cout<<"*****Aucun client correspondant a votre type de recherche*****"<<endl;
            }else{
                cout<<"*****Recherche terminée*****"<<endl;
            }}
            break;
        case 3:
        {string Arechercher;
            cout<<"entrez le prenom du client a rechercher : ";
            getline(cin,Arechercher);
            for (int i=0; i<n; i++) {
                if(tab[i].getPrenom()==Arechercher){
                    tab[i].afficher();
                    x=false;
                }
            }
            if(x){
                cout<<"*****Aucun client correspondant a votre type de recherche*****"<<endl;
            }else{
                cout<<"*****Recherche terminée*****"<<endl;
            }}
            break;
        case 4:
        {string Arechercher;
            cout<<"entrez la ville du client a rechercher : ";
            getline(cin,Arechercher);
            for (int i=0; i<n; i++) {
                if(tab[i].getVille()==Arechercher){
                    tab[i].afficher();
                    x=false;
                }
            }
            if(x){
                cout<<"*****Aucun client correspondant a votre type de recherche*****"<<endl;
            }else{
                cout<<"*****Recherche terminée*****"<<endl;
            }}
            break;
        case 5:
        {string Arechercher;
            cout<<"entrez le sexe du client a rechercher : ";
            getline(cin,Arechercher);
            for (int i=0; i<n; i++) {
                if(tab[i].getNom()==Arechercher){
                    tab[i].afficher();
                    x=false;
                }
            }
            if(x){
                cout<<"*****Aucun client correspondant a votre type de recherche*****"<<endl;
            }else{
                cout<<"*****Recherche terminée*****"<<endl;
            }}
            break;
        case 6:
        {string Arechercher;
            cout<<"entrez la date de naissance du client a rechercher : ";
            getline(cin,Arechercher);
            for (int i=0; i<n; i++) {
                if(tab[i].getNom()==Arechercher){
                    tab[i].afficher();
                    x=false;
                }
            }
            if(x){
                cout<<"Aucun client correspondant a votre type de recherche "<<endl;
            }else{
                cout<<"*****Recherche terminée*****"<<endl;
            }}
            break;
        default:
            cout<<"*****Erreur !!! veillez choissir un type de recherche conforme*****"<<endl;
            break;
    }
    
}

void recherche(Produit tab[],int n){
    int choix;
    bool x=true;
    cout<<"Choissisez le type de recherche que vous voulez effectuer :"<<endl;
    cout<<"1 : par identifiant produit "<<endl;
    cout<<"2 : par nom "<<endl;
    cout<<"3 : par prix unitaire  "<<endl;
    cout<<"4 : par quantite "<<endl;
    cout<< "votre choix : ";
    cin>>choix;
    cin.ignore();
    switch (choix) {
        case 1:
        {int Arechercher;
            cout<<"entrez l'identifiant du produit a rechercher : ";
            cin>>Arechercher;
            for (int i=0; i<n; i++) {
                if(tab[i].getIdProduit()==Arechercher){
                    tab[i].afficher();
                    x=false;
                }
            }
            if(x){
                cout<<"*****Aucun produit correspondant a votre type de recherche*****"<<endl;
            }else{
                cout<<"*****Recherche terminée*****"<<endl;
            }}
            break;
        case 2:
        {string Arechercher;
            cout<<"entrez le nom du produit a rechercher : ";
            getline(cin,Arechercher);
            for (int i=0; i<n; i++) {
                if(tab[i].getNom()==Arechercher){
                    tab[i].afficher();
                    x=false;
                }
            }
            if(x){
                cout<<"*****Aucun produit correspondant a votre type de recherche***** "<<endl;
            }else{
                cout<<"*****Recherche terminée*****"<<endl;
            }}
            break;
        case 3:
        {int Arechercher;
            cout<<"entrez le prix unitaire du produit a rechercher : ";
            cin>>Arechercher;
            for (int i=0; i<n; i++) {
                if(tab[i].getprixUnitaire()==Arechercher){
                    tab[i].afficher();
                    x=false;
                }
            }
            if(x){
                cout<<"*****Aucun produit correspondant a votre type de recherche***** "<<endl;
            }else{
                cout<<"*****Recherche terminée*****"<<endl;
            }}
            break;
        case 4:
        {int Arechercher;
            cout<<"entrez la quantite du produit a rechercher : ";
            cin>>Arechercher;
            for (int i=0; i<n; i++) {
                if(tab[i].getquantite()==Arechercher){
                    tab[i].afficher();
                    x=false;
                }
            }
            if(x){
                cout<<"*****Aucun produit correspondant a votre type de recherche *****"<<endl;
            }else{
                cout<<"*****Recherche terminée*****"<<endl;
            }}
            break;
        default:
            cout<<"*****Erreur !!! veillez choissir un type de recherche conforme*****"<<endl;
            break;
    }
    
}

void recherche(Achat tab[],int n){
    int choix;
    bool x=true;
    cout<<"Choissisez le type de recherche que vous voulez effectuer :"<<endl;
    cout<<"1 : par identifiant achat "<<endl;
    cout<<"2 : par code client achetteur "<<endl;
    cout<<"3 : par identiant produit acheter "<<endl;
    cout<<"4 : par date d'achat "<<endl;
    cout<< "votre choix : ";
    cin>>choix;
    cin.ignore();
    switch (choix) {
        case 1:
        {int Arechercher;
            cout<<"entrez l'identifiant de l'achat a rechercher : ";
            cin>>Arechercher;
            for (int i=0; i<n; i++) {
                if(tab[i].getIdAchat()==Arechercher){
                    tab[i].afficher();
                    x=false;
                }
            }
            if(x){
                cout<<"*****Aucun achat correspondant a votre type de recherche***** "<<endl;
            }else{
                cout<<"*****Recherche terminée*****"<<endl;
            }}
            break;
        case 2:
        {int Arechercher;
            cout<<"entrez le code du client a rechercher : ";
            cin>>Arechercher;
            for (int i=0; i<n; i++) {
                if(tab[i].getClient().getCodeClient()==Arechercher){
                    tab[i].afficher();
                    x=false;
                }
            }
            if(x){
                cout<<"*****Aucun achat correspondant a votre type de recherche*****"<<endl;
            }else{
                cout<<"*****Recherche terminée*****"<<endl;
            }}
            break;
        case 3:
        {int Arechercher;
            cout<<"entrez l'identifiant du produit a rechercher : ";
            cin>>Arechercher;
            for (int i=0; i<n; i++) {
                if(tab[i].getProduitAchete().getIdProduit()==Arechercher){
                    tab[i].afficher();
                    x=false;
                }
            }
            if(x){
                cout<<"*****Aucun achat correspondant a votre type de recherche*****"<<endl;
            }else{
                cout<<"*****Recherche terminée*****"<<endl;
            }}
            break;
        case 4:
        {string Arechercher;
            cout<<"entrez la quantite du produit a rechercher : ";
            getline(cin,Arechercher);
            for (int i=0; i<n; i++) {
                if(tab[i].getDate()==Arechercher){
                    tab[i].afficher();
                    x=false;
                }
            }
            if(x){
                cout<<"*****Aucun achat correspondant a votre type de recherche***** "<<endl;
            }else{
                cout<<"*****Recherche terminée*****"<<endl;
            }}
            break;
        default:
            cout<<"*****Erreur !!! veillez choissir un type de recherche conforme***** "<<endl;
            break;
    }
}
