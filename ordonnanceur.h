#ifndef ORDONNANCEUR_H_INCLUDED
#define ORDONNANCEUR_H_INCLUDED
#include <vector>
#include "stats.h"
using namespace std;
class Ordonnanceur{
public:
    virtual vector<vector<stats>> Ordonnancer(vector<vector<stats>> recherche)=0;
};
class OrdonnanceurNbApp: public Ordonnanceur{
public:
    vector<vector<stats>> Ordonnancer(vector<vector<stats>> recherche);
};

class OrdonnanceurExistence: public Ordonnanceur{
public:
    vector<vector<stats>> Ordonnancer(vector<vector<stats>> recherche);
};
#endif // ORDONNANCEUR_H_INCLUDED
