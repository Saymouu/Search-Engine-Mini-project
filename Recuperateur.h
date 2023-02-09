#ifndef RECUPERATEUR_H_INCLUDED
#define RECUPERATEUR_H_INCLUDED
#include <fstream>
#include <string>
#include <iostream>
#include "index.h"
#include <sstream>
using namespace std;
class Recuperateur{
public:
    virtual void recuperer(index* indx)=0;
};
class RecuperateurVector:public Recuperateur{
public:
    void recuperer(index* indx);
};
#endif // RECUPERATEUR_H_INCLUDED
