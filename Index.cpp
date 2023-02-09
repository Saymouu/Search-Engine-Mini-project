#include "index.h"

ostream& operator<<(ostream& flux,const stats &s){
    flux << s.mot<<" "<<s.file <<" "<<s.valeur;
    return flux;
}
void indexVector::addStat(stats S){
    biblio.push_back(S);
}
stats indexVector::getStat(string mot){
    for (vector<stats>::iterator it=biblio.begin(); it!= biblio.end();++it){
        if(it->mot==mot)
            return *it;
        }
    cout<<"Le Statistique de ce mot n'exite pas."<<endl;
    stats s;
    s.mot="0";
    s.file="0";
    s.valeur=0;
    return s;
}
void indexVector::displayIndex(){
    cout<<"Affichage de l'Index:"<<endl;
    for(stats s: biblio)
        cout<<s<<"\n";
}
void indexVector::deleteFilestat(string File){
    for(unsigned int i=0;i<biblio.size();i++){
        if(biblio[i].file==File){
            biblio.erase(biblio.begin()+i);
            i--;
        }
    }
}
