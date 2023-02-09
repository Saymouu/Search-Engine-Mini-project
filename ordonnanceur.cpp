#include "ordonnanceur.h"
vector<vector<stats> > OrdonnanceurNbApp::Ordonnancer(vector<vector<stats>> recherche){
    int s[recherche.size()],temp;
    for(unsigned int i=0;i<recherche.size();i++){
        s[i]=0;
        for(unsigned int j=0;j<recherche[i].size();j++)
            s[i]+=recherche[i][j].valeur;
    }
    vector<stats> tempVec;
    for (unsigned int i=0;i<recherche.size();i++)
    {
        for(unsigned int j=i+1;j<recherche.size();j++)
        {
            if(s[i]<s[j]){
                temp=s[i];
                s[i]=s[j];
                s[j]=temp;

                tempVec=recherche[i];
                recherche[i]=recherche[j];
                recherche[j]=tempVec;
            }
        }
    }
    return recherche;
}

vector<vector<stats>> OrdonnanceurExistence::Ordonnancer(vector<vector<stats>> recherche){
    double s[recherche.size()],temp;
    for(unsigned int i=0;i<recherche.size();i++){
        s[i]=recherche[i].size();
    }
    vector<stats> tempVec;
    for (unsigned int i=0;i<recherche.size();i++)
    {
        for(unsigned int j=i+1;j<recherche.size();j++)
        {
            if(s[i]<s[j]){
                temp=s[i];
                s[i]=s[j];
                s[j]=temp;

                tempVec=recherche[i];
                recherche[i]=recherche[j];
                recherche[j]=tempVec;
            }
        }
    }
    return recherche;
}







