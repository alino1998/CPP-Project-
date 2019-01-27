//
//  main.cpp
//  Project2Kabissa
//
//  Created by KAO Kezie Hermann on 25/01/19.
//  Copyright © 2019 Alain kabissa @toumaï. All rights reserved.
//

#include <iostream>
#include <string>
#include "mFichiers.h"
#include "Client.h"
#include "Produit.h"
#include "Achat.h"
#include "mListerRechercher.h"
#include "mAjoutSupprimerModifier.h"
using namespace std;
int Client::compteurClient=0;
int Achat::idAchatCompteur=0;

//instanciation des objets de classes crées
void instanciationObjet(Client tabc[],Produit tabp[],Achat taba[]){
    Client cli1("kabissa","alain kibalo","Rabat","m","10/09/1998");
    Client cli2("karaka","horizon","cassablanca","f","10/7/1998");
    Produit prod1(1234,"Jus d'ananas",10,2);
    Produit prod2(323,"Mangue",5,10);
    Produit t[2];
    t[0]=prod1;
    t[1]=prod1;
    Achat ach1(cli1,t,2,"10/12/2018");
    Achat ach3(cli2,t,2,"15/12/2018");
    tabc[0]=cli1;
    tabc[1]=cli2;
    tabp[0]=prod1;
    tabp[1]=prod2;
    taba[0]=ach1;
    taba[1]=ach3;
}

//les messages d'affichages
void msg1(){
    cout<<"que voulez vous faire ?"<<endl;
    cout<<"1 : pour lister des donnees "<<endl;
    cout<<"2 : rechercher des donnees  "<<endl;
    cout<<"3 : modifier des donnees "<<endl;
    cout<<"4 : ajouter des donnees "<<endl;
    cout<<"5 : supprimer des donnees "<<endl;
}
void msg2(){
    cout<<"specifier les donnees "<<endl;
    cout<<"1 : Pour les Clients "<<endl;
    cout<<"2 : Pour les Produits  "<<endl;
    cout<<"3 : Pour les Achats "<<endl;
}
void msg3(){
    cout<<"erreur"<<endl;
}
void msg4(bool x){
    if(x){
        cout<<"telechargement du fichier terminé avec succes :) vous pouvez commencer !!! "<<endl;
    }else{
        cerr<<"Impossible d'ouvrir le fichier !"<<endl;
    }
}

void msg5(bool x){
    if(x){
        cout<<"*****fichier mis a jour*****"<<endl;
    }else{
        cerr<<"Impossible d'ouvrir le fichier pour mise à jour !"<<endl;
    }
}
void msg6(){
    cout<<"+++++ Bienvenue dans AlinosMarket application de gestion de magasin +++++"<<endl;
}


//les switch cases


int main(int argc, const char * argv[]) {
    // insert code here...

    int sTC=2,sTP=2,sTA=2;
    string const f_location="/Users/mac/Desktop/C++Learning/CPP-Project-/Project2Kabissa/Project2Kabissa/Files/test.txt";
     //indiquer le repertoire du fichier avant de commencer!!!
    string sortir="oui";
    bool testUploadingFichier=false;
    Client *tabClient=new Client[100];
    Produit *tabProduit=new Produit[100];
    Achat *tabAchat=new Achat[100];
    instanciationObjet(tabClient,tabProduit,tabAchat);
    //updating programme tables
    Update_tab(f_location, tabClient, sTC,testUploadingFichier);
    Update_tab(f_location, tabProduit, sTP,testUploadingFichier);
    Update_tab(f_location, tabAchat, sTA, tabClient, sTC, tabProduit, sTP,testUploadingFichier);
    msg4(testUploadingFichier);
    msg6();
    while (sortir[0]!='n' && sortir[0]!='N' ) {
        msg1();
        int choix;
        cin>>choix;
        switch (choix) {
            case 1:
                {
                    msg2();
                    int choix2;
                    cin>>choix2;
                    switch (choix2) {
                        case 1:
                            {affichage(tabClient, sTC);
                            cout<<"*****Client affiché*****"<<endl;
                            cin.ignore();}
                            break;
                        case 2:
                            {affichage(tabProduit, sTP);
                            cout<<"*****Produit affiché*****"<<endl;
                            cin.ignore();}
                            break;
                        case 3:
                            {affichage(tabAchat, sTA);
                            cout<<"*****Achat affiché*****"<<endl;
                            cin.ignore();}
                            break;
                        default:
                            msg3();
                            break;
                    }
                }
                break;
            case 2:
            {
                msg2();
                int choix2;
                cin>>choix2;
                switch (choix2) {
                    case 1:
                        {recherche(tabClient, sTC);}
                        break;
                    case 2:
                        {recherche(tabProduit, sTP);}
                        break;
                    case 3:
                        {recherche(tabAchat, sTA);}
                        break;
                    default:
                        msg3();
                        break;
                }
            }
                break;
            case 3:
            {
                msg2();
                int choix2;
                cin>>choix2;
                switch (choix2) {
                    case 1:
                        {modif(tabClient, sTC);}
                        break;
                    case 2:
                        {modif(tabProduit, sTP);}
                        break;
                    case 3:
                        {modif(tabAchat, sTA, tabClient, sTC, tabProduit, sTP);}
                        break;
                    default:
                        msg3();
                        break;
                }
            }
                break;
            case 4:
            {
                msg2();
                int choix2;
                cin>>choix2;
                switch (choix2) {
                    case 1:
                        {cin.ignore();
                        ajout(tabClient, sTC);}
                        break;
                    case 2:
                        {ajout(tabProduit, sTP);
                        cin.ignore();}
                        break;
                    case 3:
                        {ajout(tabAchat, sTA, tabClient, sTC, tabProduit, sTP);}
                        break;
                    default:
                        msg3();
                        break;
                }
            }
                break;
            case 5:
            {
                msg2();
                int choix2;
                cin>>choix2;
                switch (choix2) {
                    case 1:
                    {supprimer(tabClient, sTC);
                        cin.ignore();}
                        break;
                    case 2:
                    {supprimer(tabProduit, sTP);
                        cin.ignore();}
                        break;
                    case 3:
                    {supprimer(tabAchat, sTA);
                        cin.ignore();}
                        break;
                    default:
                        msg3();
                        break;
                }
            }
                break;
                
            default:
                msg3();
                break;
        }
        Update_f(f_location, tabClient, sTC,testUploadingFichier);
        Update_f(f_location, tabProduit, sTP,testUploadingFichier);
        Update_f(f_location, tabAchat, sTA,testUploadingFichier);
        msg5(testUploadingFichier);
        cout<<"Voulez vous continuer (Oui/Non) : ";
        getline(cin,sortir);
    }
    delete [] tabProduit;
    delete [] tabAchat;
    delete [] tabClient;
    return 0;
}
/// a revoir ajout achat  /Users/mac/Library/Developer/Xcode/DerivedData
