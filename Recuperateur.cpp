#include "Recuperateur.h"
//istream& operator>>(istream& flux, stats &s){
//    flux >>s.mot>> s.file >>s.valeur;
//    return flux;
//}
void RecuperateurVector::recuperer(index* indx){
    ifstream File;
    File.open("StatsSaveFile.txt");
    cout<<"Recuperation des statistiques."<<endl;
    string line;
    while(getline(File, line))
    {
        string tmp;
        stringstream ss(line);
        vector<string> lineVector;
        while(getline(ss, tmp, ' '))
            lineVector.push_back(tmp);
        stats s;
        s.mot=lineVector[0];
        s.file=lineVector[1];
        s.valeur=stod(lineVector[2]);
        indx->addStat(s);
    }
    File.close();
}

