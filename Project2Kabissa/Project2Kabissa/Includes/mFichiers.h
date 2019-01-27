//
//
//  Project2Kabissa
//
//  Created by KAO Kezie Hermann on 26/01/19.
//  Copyright © 2019 Alain kabissa @toumaï. All rights reserved.
//

#ifndef mFichiers_h
#define mFichiers_h
#include <iostream>
#include <fstream>
#include <string>
#include "Client.h"
#include "Produit.h"
#include "Achat.h"
using namespace std;

void Update_f(string f_location,Client tab[],int n);
void Update_f(string f_location,Produit tab[],int n);
void Update_f(string f_location,Achat tab[],int n);

void Update_tab(string f_location,Client tab[],int &n);
void Update_tab(string f_location,Produit tab[],int &n);
void Update_tab(string f_location,Achat tabA[],int &na,Client tabC[],int nc,Produit tabP[],int np );

#endif /* mFichiers_h */
