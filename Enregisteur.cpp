#include "Enregisteur.h"

void EnregistreurVector::enregistrer(index* Idx){
    cout<<"Enregistrement des statistiques."<<endl;
    ofstream out("StatsSaveFile.txt");
    vector<stats> bib;
    bib=Idx->getAllstats();
    for(unsigned int i=0;i<bib.size();i++){
        out << bib[i]<<endl;
    }
    out.close();
}
