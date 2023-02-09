#include <iostream>
#include "Nettoyeur.h"


vector<string> Nettoyeur_symb::Nettoyer(vector<string> mots){
    vector<string> resultat;
    for(unsigned int i=0;i<mots.size();i++){
        for(unsigned int j=0;j<mots[i].size();j++){
            if ((mots[i][j]<65 || mots[i][j]>90)&&(mots[i][j]<97 || mots[i][j]>122)){
                mots[i].erase(mots[i].begin()+j);
                j--;
            }
        }
        resultat.push_back(mots[i]);
    }
    return resultat;
}
vector<string> Nettoyeur_majus::Nettoyer(vector<string> mots){
    vector<string> resultat;
    for(unsigned int i=0;i<mots.size();i++){
        for(unsigned int j=0;j<mots[i].size();j++)
            mots[i][j]=tolower(mots[i][j]);
        resultat.push_back(mots[i]);
    }
    return resultat;
}
