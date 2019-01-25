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
    Produit ProduitAchete;
    string date;
    
public:
    Achat();
    Achat(int,Client,Produit,string);
    ~Achat();
    
    int getIdAchat();
    Client getClient();
    Produit getProduitAchete();
    string getDate();
    
    void setIdAchat(int);
    void setClient(Client);
    void setProduitAchete(Produit);
    void setDate(string);
    
    void afficher();
    
};


#endif /* Achat_h */
