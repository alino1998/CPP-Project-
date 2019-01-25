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
//#include "mListerRechercher.h"
//#include "mAjoutSupprimerModifier.h"
using namespace std;
int Client::compteurClient=0;

int main(int argc, const char * argv[]) {
    // insert code here...
    Client cli1("okinawa","alain kibalo","Rabat","M","10/09/1998");
    Produit prod1(1234,"Jus d'ananas",10,2);
    Achat Ach1(123,cli1,prod1,"10/10/2019");
    prod1.afficher();
    cli1.afficher();
    Ach1.afficher();
    return 0;
}
