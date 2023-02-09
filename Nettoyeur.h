#ifndef NETTOYEUR_H_INCLUDED
#define NETTOYEUR_H_INCLUDED
#include <string>
#include <vector>
#include <cctype>
using namespace std;

class Nettoyeur{
public:
     virtual vector<string> Nettoyer(vector<string> mots)=0;

};
class Nettoyeur_symb:public Nettoyeur{
public:
     vector<string> Nettoyer(vector<string> mots);

};
class Nettoyeur_majus:public Nettoyeur{
public:
     vector<string> Nettoyer(vector<string> mots);

};
//add Nettoyeur that does both
#endif // NETTOYEUR_H_INCLUDED
