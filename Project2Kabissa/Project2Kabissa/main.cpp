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

//instanciation des objets de classes crées
void instanciationObjet(Client tabc[],Produit tabp[],Achat taba[]){
    Client cli1("okinawa","alain kibalo","Rabat","M","10/09/1998");
    Client cli2("karaka","horizon","cassanblanca","feminin","10/7/1998");
    Produit prod1(1234,"Jus d'ananas",10,2);
    Produit prod2(323,"Mangue",5,10);
    Achat Ach1(123,cli2,prod1,"10/10/2019");
    Achat ach2(12,cli1,prod1,"10/10/2019");
    tabc[0]=cli1;
    tabc[1]=cli2;
    tabp[0]=prod1;
    tabp[1]=prod2;
    taba[0]=Ach1;
    taba[1]=ach2;
}

//les messages d'affichages
void msg1(){
    cout<<"que voulez vous faire"<<endl;
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


//les switch cases


int main(int argc, const char * argv[]) {
    // insert code here...

    int sTC=2,sTP=2,sTA=2;
    string const f_location="/Users/mac/Desktop/C++Learning/CPP-Project-/Project2Kabissa/Project2Kabissa/Files/test.txt";
    Client tabClient[100];
    Produit tabProduit[100];
    Achat tabAchat[100];
    instanciationObjet(tabClient,tabProduit,tabAchat);
    
    string sortir="oui";/*
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
                            cin.ignore();}
                            break;
                        case 2:
                            {affichage(tabProduit, sTP);
                            cin.ignore();}
                            break;
                        case 3:
                            affichage(tabAchat, sTA);
                            cin.ignore();
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
        cout<<"Voulez vous continuer (Oui/Non) : ";
        getline(cin,sortir);
    }*/
//    ajout(tabProduit, sTP);
//    ajout(tabProduit, sTP);
//    Update_f(f_location,tabProduit, sTP);
    Update_tab(f_location, tabProduit, sTP);
    affichage(tabProduit, sTP);
    return 0;
}

/// a revoir ajout achat
