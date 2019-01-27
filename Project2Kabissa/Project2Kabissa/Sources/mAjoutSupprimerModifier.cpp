//
//  mAjoutSupprimerModifier.cpp
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
#include "AutresMethodes.h"
#include "mAjoutSupprimerModifier.h"
using namespace std;


//ajouter des donnees
void ajout(Client tab[],int &n){
    string nom,prenom,ville,sexe,happybirhday;
    cout<<"Veillez saisir les informations du clients a ajouter "<<endl;
    cout<<"Nom : ";
    getline(cin,nom);
    cout<<"Prenom : ";
    getline(cin,prenom);
    cout<<"Ville : ";
    getline(cin,ville);
    cout<<"Sexe : ";
    getline(cin,sexe);
    cout<<"Date de naissance : ";
    getline(cin,happybirhday);
    Client newClient(nom,prenom,ville,sexe,happybirhday);
    tab[n]=newClient;
    n++;
    cout<<"*****client ajouté*****"<<endl;
}

void ajout(Produit tab[],int &n){
    string nom;
    int id,prixUnitaire,quantite;
    cout<<"Veillez saisir les informations du produits a ajouter "<<endl;
    cout<<"id : ";
    cin>>id;
    cin.ignore();
    cout<<"nom : ";
    getline(cin,nom);
    cout<<"Prix unitaire  : ";
    cin>>prixUnitaire;
    cout<<"Quantite : ";
    cin>>quantite;
    Produit newProduit(id,nom,prixUnitaire,quantite);
    tab[n]=newProduit;
    n++;
    cout<<"*****produit ajouté*****"<<endl;
}


void ajout(Achat tabA[],int &na,Client tabC[],int nc,Produit tabP[],int np ){
    string date,verification="";
    int idachat,idclient,taille=100,tailleReel=0,id=0;
    Client achetteur;
    Produit prodAcheter;
    Produit *tabprim=new Produit[taille];
    cout<<"Veillez saisir les informations de l'achat a ajouter "<<endl;
    cout<<"id : ";
    cin>>idachat;
    cout<<"entrez l'identifiant du client parmi la liste affichée"<<endl;
    affichage(tabC, nc);
    cout<<"id client : ";
    cin>>idclient;
    achetteur=searchItem(tabC, nc, idclient);
    cout<<"entrez les identifiants des produits achetés parmi la liste affichée"<<endl;
    affichage(tabP, np);
    do {
        cout<<"Id produit "<<tailleReel+1<<" : ";
        cin>>id;
        prodAcheter=searchItem(tabP, np, id);
        tabprim[tailleReel]=prodAcheter;
        tailleReel++;
        cin.ignore();
        cout<<"continuer a ajouter ? (Oui/Non) : ";
        getline(cin,verification);
    } while (verification[0]!='n' && verification[0]!='N');
    cout<<"date : ";
    getline(cin,date);
    Achat newAchat(idachat,achetteur,tabprim,tailleReel,date);
    tabA[na]=newAchat;
    na++;
    delete [] tabprim;
    cout<<"*****Achat ajoute*****"<<endl;
}

// modifier des donnees

void modif(Client tab[],int n){
    int choix,id;
    bool x=true;
    cout<<"entrez le code du client a modifier : ";
    cin>>id;
    cout<<"Que voulez vous modifier  :"<<endl;
    cout<<"1 : pour le nom "<<endl;
    cout<<"2 : pour le prenom "<<endl;
    cout<<"3 : pour la ville "<<endl;
    cout<<"4 : pour le sexe "<<endl;
    cout<<"5 : pour la date de naissance "<<endl;
    cout<< "votre choix : ";
    cin>>choix;
    switch (choix) {
        case 1:
        {string AModifier;
            cout<<"entrez le nouveau nom du client : ";
            cin.ignore();
            getline(cin,AModifier);
            for (int i=0; i<n; i++) {
                if(tab[i].getCodeClient()==id){
                    tab[i].setNom(AModifier);
                    x=false;
                }
            }
            if(x){
                cout<<"*****Aucun client correspondant a votre identifiant saisi*****"<<endl;
            }else{
                cout<<"*****modification effectuer avec success*****"<<endl;
            }}
            break;
        case 2:
        {string AModifier;
            cout<<"entrez le nouveau prenom du client : ";
            cin.ignore();
            getline(cin,AModifier);
            for (int i=0; i<n; i++) {
                if(tab[i].getCodeClient()==id){
                    tab[i].setPrenom(AModifier);
                    x=false;
                }
            }
            if(x){
                cout<<"*****Aucun client correspondant a votre identifiant saisi***** "<<endl;
            }else{
                cout<<"*****modification effectuer avec success*****"<<endl;
            }}
            break;
        case 3:
        {string AModifier;
            cout<<"entrez la nouvelle ville du client : ";
            cin.ignore();
            getline(cin,AModifier);
            for (int i=0; i<n; i++) {
                if(tab[i].getCodeClient()==id){
                    tab[i].setVille(AModifier);
                    x=false;
                }
            }
            if(x){
                cout<<"*****Aucun client correspondant a votre identifiant saisi***** "<<endl;
            }else{
                cout<<"*****modification effectuer avec success*****"<<endl;
            }}
            break;
        case 4:
        {string AModifier;
            cout<<"entrez le nouveau sexe du client : ";
            cin.ignore();
            getline(cin,AModifier);
            for (int i=0; i<n; i++) {
                if(tab[i].getCodeClient()==id){
                    tab[i].setSexe(AModifier);
                    x=false;
                }
            }
            if(x){
                cout<<"*****Aucun client correspondant a votre identifiant saisi*****"<<endl;
            }else{
                cout<<"*****modification effectuer avec success*****"<<endl;
            }}
            break;
        case 5:
        {string AModifier;
            cout<<"entrez la nouvelle date de naissance du client : ";
            cin.ignore();
            getline(cin,AModifier);
            for (int i=0; i<n; i++) {
                if(tab[i].getCodeClient()==id){
                    tab[i].setDateNaissance(AModifier);
                    x=false;
                }
            }
            if(x){
                cout<<"*****Aucun client correspondant a votre identifiant saisi*****"<<endl;
            }else{
                cout<<"*****modification effectuer avec success*****"<<endl;
            }}
            break;
            
        default:
            cout<<"*****Erreur !!! veillez choissir un type de modification conforme  *****"<<endl;
            break;
    }
    
}

void modif(Produit tab[],int n){
    int choix,id;
    bool x=true;
    cout<<"entrez l'identifiant du produit a modifier : ";
    cin>>id;
    cout<<"Que voulez vous modifier  :"<<endl;
    cout<<"1 : pour l'identifiant "<<endl;
    cout<<"2 : pour le nom "<<endl;
    cout<<"3 : pour le prix unitaire "<<endl;
    cout<<"4 : pour la quantite "<<endl;
    cout<< "votre choix : ";
    cin>>choix;
    cin.ignore();
    switch (choix) {
        case 1:
        {int AModifier;
            cout<<"entrez le nouveau identifiant du produit : ";
            cin>>AModifier;
            cin.ignore();
            for (int i=0; i<n; i++) {
                if(tab[i].getIdProduit()==id){
                    tab[i].setIdProduit(AModifier);
                    x=false;
                }
            }
            if(x){
                cout<<"*****Aucun produit correspondant a votre identifiant saisi*****"<<endl;
            }else{
                cout<<"*****modification effectuer avec success*****"<<endl;
            }}
            break;
        case 2:
        {string AModifier;
            cout<<"entrez le nouveau nom du produit : ";
            cin.ignore();
            getline(cin,AModifier);
            for (int i=0; i<n; i++) {
                if(tab[i].getIdProduit()==id){
                    tab[i].setNom(AModifier);
                    x=false;
                }
            }
            if(x){
                cout<<"*****Aucun produit correspondant a votre identifiant saisi***** "<<endl;
            }else{
                cout<<"*****modification effectuer avec success*****"<<endl;
            }}
            break;
        case 3:
        {int AModifier;
            cout<<"entrez le nouveau prix unitaire du produit : ";
            cin>>AModifier;
            cin.ignore();
            for (int i=0; i<n; i++) {
                if(tab[i].getIdProduit()==id){
                    tab[i].setprixUnitaire(AModifier);
                    x=false;
                }
            }
            if(x){
                cout<<"*****Aucun produit correspondant a votre identifiant saisi***** "<<endl;
            }else{
                cout<<"*****modification effectuer avec success*****"<<endl;
            }}
            break;
        case 4:
        {int AModifier;
            cout<<"entrez le nouvelle quantite du produit : ";
            cin>>AModifier;
            cin.ignore();
            for (int i=0; i<n; i++) {
                if(tab[i].getIdProduit()==id){
                    tab[i].setquantite(AModifier);
                    x=false;
                }
            }
            if(x){
                cout<<"*****Aucun produit correspondant a votre identifiant saisi***** "<<endl;
            }else{
                cout<<"*****modification effectuer avec success*****"<<endl;
            }}
            break;
        default:
            cout<<"*****Erreur !!! veillez choissir un type de modification conforme  *****"<<endl;
            break;
    }
    
}

void modif(Achat tabA[],int na,Client tabC[],int nc,Produit tabP[],int np ){
    int choix,id;
    bool x=true;
    cout<<"entrez l'identifiant de l'achat a modifier : ";
    cin>>id;
    cout<<"Que voulez vous modifier  :"<<endl;
    cout<<"1 : pour l'identifiant "<<endl;
    cout<<"2 : pour le client "<<endl;
    cout<<"3 : pour les produits achetés "<<endl;
    cout<<"4 : pour la date "<<endl;
    cout<< "votre choix : ";
    cin>>choix;
    switch (choix) {
        case 1:
        {int AModifier;
            cout<<"entrez le nouveau identifiant de l'achat : ";
            cin>>AModifier;
            cin.ignore();
            for (int i=0; i<na; i++) {
                if(tabA[i].getIdAchat()==id){
                    tabA[i].setIdAchat(AModifier);
                    x=false;
                }
            }
            if(x){
                cout<<"*****Aucun achat correspondant a votre identifiant saisi*****"<<endl;
            }else{
                cout<<"*****modification effectuer avec success*****"<<endl;
            }}
            break;
        case 2:
        {
            int AModifier;
            Client nouveau;
            cout<<"entrez l'identifiant de nouvelle achetteur de l'achat : ";
            cin>>AModifier;
            cin.ignore();
            nouveau=searchItem(tabC, nc, AModifier);
            for (int i=0; i<na; i++) {
                if(tabA[i].getIdAchat()==id){
                    tabA[i].setClient(nouveau);
                    x=false;
                }
            }
            if(x){
                cout<<"*****Aucun achat correspondant a votre identifiant saisi*****"<<endl;
            }else{
                cout<<"*****modification effectuer avec success*****"<<endl;
            }}
            break;
        case 3:
        {
            string verification="";
            int taille=100,tailleReel=0,idprod=0;
            Client achetteur;
            Produit prodAcheter;
            Produit *tabprim=new Produit[taille];
            cout<<"entrez les identifiants du nouveaux produits achetés par la liste de produits : "<<endl;
            affichage(tabP, np);
            do {
                cout<<"Id produit "<<tailleReel+1<<" : ";
                cin>>idprod;
                prodAcheter=searchItem(tabP, np, idprod);
                tabprim[tailleReel]=prodAcheter;
                tailleReel++;
                cin.ignore();
                cout<<"continuer a ajouter ? (Oui/Non) : ";
                getline(cin,verification);
            } while (verification[0]!='n' && verification[0]!='N');
            for (int i=0; i<na; i++) {
                if(tabA[i].getIdAchat()==id){
                    tabA[i].setPanierAchat(tabprim, tailleReel);
                    x=false;
                }
            }
            delete [] tabprim;
            if(x){
                cout<<"*****Aucun achat correspondant a votre identifiant saisi*****"<<endl;
            }else{
                cout<<"*****modification effectuer avec success*****"<<endl;
            }
            
        }
            break;
        case 4:
        {string AModifier;
            cout<<"entrez la nouvelle date de l'achat : ";
            cin.ignore();
            getline(cin,AModifier);
            for (int i=0; i<na; i++) {
                if(tabA[i].getIdAchat()==id){
                    tabA[i].setDate(AModifier);
                    x=false;
                }
            }
            if(x){
                cout<<"*****Aucun achat correspondant a votre identifiant saisi***** "<<endl;
            }else{
                cout<<"*****modification effectuer avec success*****"<<endl;
            }}
            break;
        default:
            cout<<"*****Erreur !!! veillez choissir un type de modification conforme  *****"<<endl;
            break;
    }
    
}
// suppression

void supprimer(Client tab[],int &n){
    int Asupprimer,j=0;
    Client newtab[n];
    bool x=false;
    cout<<"entrez le code du client a supprimer parmi la liste des achats : ";
    affichage(tab, n);
    cin>>Asupprimer;
    for (int i=0; i<n; i++) {
        if(tab[i].getCodeClient()!=Asupprimer){
            newtab[j]=tab[i];
            j++;
        }
        if(tab[i].getCodeClient()==Asupprimer){
            x=true;
        }
    }
    if(x){
        n--;
        for (int i=0; i<n; i++) {
            tab[i]=newtab[i];
        }
        cout<<"client supprimé "<<endl;
    }else{
        cout<<"*****Aucun client correspondant a votre identifiant saisi*****"<<endl;
    }
}

void supprimer(Produit tab[],int &n){
    int Asupprimer,j=0;
    Produit newtab[n];
    bool x=false;
    cout<<"entrez le code du produit a supprimer parmi la liste des achats : ";
    affichage(tab, n);
    cin>>Asupprimer;
    for (int i=0; i<n; i++) {
        if(tab[i].getIdProduit()!=Asupprimer){
            newtab[j]=tab[i];
            j++;
        }
        if(tab[i].getIdProduit()==Asupprimer){
            x=true;
        }
    }
    if(x){
        n--;
        for (int i=0; i<n; i++) {
            tab[i]=newtab[i];
        }
        cout<<"*****Produit supprimé***** "<<endl;
    }else{
        cout<<"*****Aucun produit correspondant a votre identifiant saisi***** "<<endl;
    }
}

void supprimer(Achat tab[],int &n){
    int Asupprimer,j=0;
    Achat newtab[n];
    bool x=false;
    cout<<"entrez le code de l'achat a supprimer parmi la liste des achats : ";
    affichage(tab, n);
    cin>>Asupprimer;
    for (int i=0; i<n; i++) {
        if(tab[i].getIdAchat()!=Asupprimer){
            newtab[j]=tab[i];
            j++;
        }
        if(tab[i].getIdAchat()==Asupprimer){
            x=true;
        }
    }
    if(x){
        n--;
        for (int i=0; i<n; i++) {
            tab[i]=newtab[i];
        }
        cout<<"*****Achat supprimé*****"<<endl;
    }else{
        cout<<"*****Aucun Achat correspondant a votre identifiant saisi *****"<<endl;
    }
}
