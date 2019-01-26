//
//  mListerRechercher.h
//  Project2Kabissa
//
//  Created by KAO Kezie Hermann on 26/01/19.
//  Copyright © 2019 Alain kabissa @toumaï. All rights reserved.
//

#ifndef mListerRechercher_h
#define mListerRechercher_h
#include <iostream>
#include <string>
#include "Client.h"
#include "Produit.h"
#include "Achat.h"
using namespace std;

// listage d'objet
void affichage(Client tab[],int n);
void affichage(Produit tab[],int n);
void affichage(Achat tab[],int n);

//methode de recherche d'objet

void recherche(Client tab[],int n);
void recherche(Produit tab[],int n);
void recherche(Achat tab[],int n);

#endif /* mListerRechercher_h */
