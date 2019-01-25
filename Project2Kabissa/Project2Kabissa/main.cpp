//
//  main.cpp
//  Project2Kabissa
//
//  Created by KAO Kezie Hermann on 25/01/19.
//  Copyright © 2019 Alain kabissa @toumaï. All rights reserved.
//

#include <iostream>
#include <string>
//#include "mFichiers.h"
#include "Client.h"
#include "Produit.h"
#include "Achat.h"
#include "mListerRechercher.h"
//#include "mAjoutSupprimerModifier.h"
using namespace std;
int Client::compteurClient=0;

//instanciation des objets de classes crées
void instanciationObjet(Client tabc[],Produit tabp[],Achat taba[]){
    Client cli1("okinawa","alain kibalo","Rabat","M","10/09/1998");
    Client cli2("karaka","horizon","cassanblanca","M","10/7/1998");
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

int main(int argc, const char * argv[]) {
    // insert code here...

    int sTC=2,sTP=2,sTA=2;
    Client tabClient[100];
    Produit tabProduit[100];
    Achat tabAchat[100];
    instanciationObjet(tabClient,tabProduit,tabAchat);
    
    
    return 0;
}
