#ifndef ENREGISTEUR_H_INCLUDED
#define ENREGISTEUR_H_INCLUDED
#include <fstream>
#include <string>
#include <iostream>
#include "index.h"
using namespace std;
class Enregistreur{
public:
    virtual void enregistrer(index* Idx)=0;
};
class EnregistreurVector:public Enregistreur{
public:
    void enregistrer(index* Idx);
};
#endif // ENREGISTEUR_H_INCLUDED
