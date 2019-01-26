//
//  mAjoutSupprimerModifier.h
//  Project2Kabissa
//
//  Created by KAO Kezie Hermann on 26/01/19.
//  Copyright © 2019 Alain kabissa @toumaï. All rights reserved.
//

#ifndef mAjoutSupprimerModifier_h
#define mAjoutSupprimerModifier_h
#include <iostream>
#include <string>
#include "Client.h"
#include "Produit.h"
#include "Achat.h"
using namespace std;

//ajout de clients / Produit / Achat
void ajout(Client tab[],int *n);
void ajout(Produit tab[],int *n);
void ajout(Achat tab[],int *n);

void modif(Client tab[],int &n);
void modif(Produit tab[],int &n);
void modif(Achat tabA[],int &na,Client tabC[],int &nc,Produit tabP[],int &np );

void supprimer(Client tab[],int *n);
void supprimer(Produit tab[],int *n);
void supprimer(Achat tab[],int *n);

#endif /* mAjoutSupprimerModifier_h */
