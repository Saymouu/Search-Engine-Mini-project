#include "Lecteur.h"
#include <iostream>
using namespace std;
vector<string> LecteurFichier::Lire(string ch){
    //Loading of the file into a string text
    ifstream ifs(ch);
    string text( (istreambuf_iterator<char>(ifs)), (istreambuf_iterator<char>()) );
    //next up is the loading of the string text into the vect
    string tmp;
    stringstream ss(text);
    vector<string> words;
    while(getline(ss, tmp, ' ')){
        words.push_back(tmp);
    }
    return words;
}
vector<string> LecteurRepertoire::Lire(string ch){
    vector<string> fichiers;
    DIR* rep=opendir(ch.c_str());
    if (rep!=NULL)
    {
        dirent* ent;
        while((ent=readdir(rep))!=NULL)
            fichiers.push_back(ent->d_name);
        closedir(rep);
    }
    return fichiers;//C'est un vecteur rempli par les noms des fichiers .txt dans la repertoire.
}
