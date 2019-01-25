//
//  Produit.h
//  Project2Kabissa
//
//  Created by KAO Kezie Hermann on 25/01/19.
//  Copyright © 2019 Alain kabissa @toumaï. All rights reserved.
//

#ifndef Produit_h
#define Produit_h
#include <string>
using namespace std;

class Produit{
    
private:
    int IdProduit;
    string nom;
    int prixUnitaire;
    int quantite;
    
public:
    Produit();
    Produit(int,string,int,int);
    Produit(Produit &);
    ~Produit();
    
    int getIdProduit();
    string getNom();
    int getprixUnitaire();
    int getquantite();
    
    void setIdProduit(int);
    void setNom(string);
    void setprixUnitaire(int);
    void setquantite(int);
    
    void afficher();
    
};


#endif /* Produit_h */
