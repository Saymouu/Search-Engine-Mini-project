#ifndef ANALYSEUR_H_INCLUDED
#define ANALYSEUR_H_INCLUDED
#include <string>
#include <vector>
#include "stats.h"
using namespace std;

class Analyseur{
public:
    virtual vector<stats> Analyser(vector<string> Mots, string fichier)=0;
};
class AnalyseurNbApp:public Analyseur{
public:
      vector<stats> Analyser(vector<string> Mots, string fichier);
};
class AnalyseurPourcentage:public Analyseur{
public:
      vector<stats> Analyser(vector<string> Mots, string fichier);
};

#endif // ANALYSEUR_H_INCLUDED
