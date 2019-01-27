//
//  Achat.h
//  Project2Kabissa
//
//  Created by KAO Kezie Hermann on 25/01/19.
//  Copyright © 2019 Alain kabissa @toumaï. All rights reserved.
//

#ifndef Achat_h
#define Achat_h
#include <string>
#include "Produit.h"
#include "Client.h"
using namespace std;

class Achat{
    
private:
    int IdAchat;
    Client client;
    string date;
    int taillePanier;
    Produit *panierAchat= new Produit[10];
    static int idAchatCompteur;
public:
    Achat();
    Achat(int,Client,Produit [],int,string);
    Achat(Client,Produit [],int,string);
    ~Achat();
    
    int getIdAchat();
    Client getClient();
    void getPanierAchat(Produit [],int &) ;
    int getTaillePanier();
    string getDate();
    
    void setClient(Client);
    void setPanierAchat(Produit tab[],int);
    void setTaillePanier(int);
    void setDate(string);
    
    void afficher();
    
};


#endif /* Achat_h */
