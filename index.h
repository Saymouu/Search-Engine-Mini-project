#ifndef INDEX_H_INCLUDED
#define INDEX_H_INCLUDED
#include <vector>
#include <iostream>
#include "stats.h"
using namespace std;

class index{
public:
    virtual void addStat(stats S)=0;
    virtual stats getStat(string mot)=0;
    virtual int getSize()=0;
    virtual vector<stats> getAllstats()=0;
    virtual void displayIndex()=0;
    virtual void deleteFilestat(string File)=0;
};

class indexVector:public index{
    vector<stats> biblio;
public:
    void addStat(stats S);
    stats getStat(string mot);
    int getSize(){return biblio.size();};
    vector<stats> getAllstats(){return biblio;};
    void displayIndex();
    void deleteFilestat(string File);
};

ostream& operator<<(ostream& flux,const stats &s);

#endif // INDEX_H_INCLUDED
