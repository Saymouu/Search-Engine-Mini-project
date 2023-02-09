#include "Analyseur.h"
vector<stats> AnalyseurNbApp::Analyser(vector<string> wordVector, string fichier){
    vector<stats> statVector;
    bool existence;
    for(auto &s:wordVector)
    {
        existence=false;
        for(unsigned int i=0;i<statVector.size();i++)
        {
            if(statVector[i].mot==s){
                existence=true;
                statVector[i].valeur++;
                break;
                }
        }
        if(existence==false)
        {
            stats statis;
            statis.mot=s;
            statis.file=fichier;
            statis.valeur=1;
            statVector.push_back(statis);
        }
    }
    return statVector;
}

vector<stats> AnalyseurPourcentage::Analyser(vector<string> wordVector, string fichier){
    vector<stats> statVector;
    bool existence;
    for(auto &s:wordVector)
    {
        existence=false;
        for(unsigned int i=0;i<statVector.size();i++)
        {
            if(statVector[i].mot==s){
                existence=true;
                statVector[i].valeur++;
                break;
                }
        }
        if(existence==false)
        {
            stats statis;
            statis.mot=s;
            statis.file=fichier;
            statis.valeur=1;
            statVector.push_back(statis);
        }
    }
    for(auto &s:statVector){
        s.valeur=(s.valeur/wordVector.size())*100;
    }
    return statVector;
}
