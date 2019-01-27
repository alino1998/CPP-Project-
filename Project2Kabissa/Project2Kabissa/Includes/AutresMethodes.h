//
//  AutresMethodes.h
//  Project2Kabissa
//
//  Created by KAO Kezie Hermann on 27/01/19.
//  Copyright © 2019 Alain kabissa @toumaï. All rights reserved.
//

#ifndef AutresMethodes_h
#define AutresMethodes_h
#include <iostream>
#include <string>
#include "Client.h"
#include "Produit.h"
#include "Achat.h"
using namespace std;

Produit searchItem(Produit [],int ,int );
Client searchItem(Client [],int ,int );
void decoupMots(string [],int &,string,char);
string traitement_date(string);
string traitement_sexe(string);
#endif /* AutresMethodes_h */
