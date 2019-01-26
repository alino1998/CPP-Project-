//
//  Client.h
//  Project2Kabissa
//
//  Created by KAO Kezie Hermann on 25/01/19.
//  Copyright © 2019 Alain kabissa @toumaï. All rights reserved.
//

#ifndef Client_h
#define Client_h
#include <string>
using namespace std;

class Client{
    
private:
    int codeClient;
    string nom;
    string prenom;
    string ville;
    string sexe;  // F ou M
    string dateNaissance; // sous la forme 10/09/2019
    static int compteurClient;
    
public:
    Client();
    Client(string,string,string,string,string);
    Client(int,string,string,string,string,string);//uniquement pour interagir avec les files
    Client(Client &);
    ~Client();
    
    int getCodeClient();
    string getNom();
    string getPrenom();
    string getVille();
    string getSexe();
    string getDateNaissance();
    
    void setNom(string);
    void setPrenom(string);
    void setVille(string);
    void setSexe(string);
    void setDateNaissance(string);
    
    void afficher();
    
};

#endif /* Client_h */
