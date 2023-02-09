#ifndef LECTEUR_H_INCLUDED
#define LECTEUR_H_INCLUDED
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <dirent.h>
#include <cstring>
using namespace std;

class Lecteur{
public:
    virtual vector<string> Lire(string ch)=0;
};

class LecteurFichier:public Lecteur{
public:
    vector<string> Lire(string ch);
};
class LecteurRepertoire:public Lecteur{
public:
    vector<string> Lire(string ch);
};
#endif // LECTEUR_H_INCLUDED
