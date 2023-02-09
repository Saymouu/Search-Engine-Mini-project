#include "moteurrecherche.h"

void MoteurDeRecherche::ajouterFichier(string fichier){
    Fichiers.push_back(fichier);
}

void MoteurDeRecherche::afficherFichiers(){
    cout<<"Affichage de tout les fichiers du moteur:"<<endl;
    for(unsigned int i=0;i<Fichiers.size();i++)
        cout<<Fichiers[i]<<endl;
}

void MoteurDeRecherche::supprimerFichier(string fichier){
    for(vector<string>::iterator it=Fichiers.begin();it!=Fichiers.end();++it){
        if(*it==fichier){
            Fichiers.erase(it);
            break;
        }
    }
}

void MoteurDeRecherche::enregistrerFichiers(){
    cout<<"Enregistrement des fichiers."<<endl;
    ofstream out("FichiersSaveFile.txt");
    for(unsigned int i=0;i<Fichiers.size();i++){
        out<<Fichiers[i]<<endl;
    }
    out.close();
}

void MoteurDeRecherche::recupererFichiers(){
    ifstream File;
    File.open("FichiersSaveFile.txt");
    cout<<"Recuperation des fichiers."<<endl;
    string line;
    while(getline(File, line))
        Fichiers.push_back(line);
    File.close();
}

void MoteurDeRecherche::indexer(string fichier){
    vector<stats> statVector;
    vector<string> vec;
    vec=Lec->Lire(fichier);
    vec=Net->Nettoyer(vec);
    statVector=Anal->Analyser(vec,fichier);
    for(unsigned int i;i<statVector.size();i++){
        Data->addStat(statVector[i]);
    }
}

void MoteurDeRecherche::indexerRepertoire(string chemin){
    LecteurRepertoire Lec;
    vector<string> files;
    files=Lec.Lire(chemin);
    //indexation des fichiers du repertoire.
    for(unsigned int i=2;i<files.size();i++){
        string fichier;
        fichier=chemin+"\\"+files[i];
        cout<<fichier<<" : indexation complete."<<endl;
        indexer(fichier);
    }
}

void MoteurDeRecherche::supprimerStatsFichier(string fichier){
    Data->deleteFilestat(fichier);
}
void MoteurDeRecherche::afficherIndex(){
    Data->displayIndex();
}
void MoteurDeRecherche::chercher(string requette,unsigned int nbResultats){
    //division et nettoyage du requette
    vector<string> request;
    string tmp;
    stringstream ss(requette);
    while(std::getline(ss, tmp,' ')){
        request.push_back(tmp);
    }
    request=Net->Nettoyer(request);

    //extraction de tout les stats des mots
    vector<vector<stats>> result;
    vector<stats> biblio=Data->getAllstats();
    for(unsigned int j=0;j<request.size();j++){
        for(unsigned int i=0;i<biblio.size();i++){
            if(request[j]==biblio[i].mot){
                bool existence=false;
                for(unsigned int k=0; k<result.size();k++){
                    if(biblio[i].file==result[k][0].file){
                        result[k].push_back(biblio[i]);
                        existence=true;
                        break;
                    }
                }
                if(!existence){
                    vector<stats> neew;
                    neew.push_back(biblio[i]);
                    result.push_back(neew);
                }
            }
        }
    }
    result=Ord->Ordonnancer(result);
    cout<<"Resultat de recherche:"<<endl;
    int Min=nbResultats;
    if(result.size()<nbResultats)
        Min=result.size();
    for(int i=0;i<Min;i++){
        cout<<i+1<<"- "<<result[i][0].file<<":"<<endl;
        for(unsigned int j=0;j<result[i].size();j++){
            cout<<"    "<<result[i][j].mot<<" : "<<result[i][j].valeur<<endl;
        }
    }
}

void MoteurDeRecherche::enregistrerStats(){
    Eng->enregistrer(Data);
}

void MoteurDeRecherche::recupererStats(){
    Rec->recuperer(Data);
}

MoteurDeRecherche::MoteurDeRecherche(Lecteur* L,Nettoyeur* N,Analyseur* A,index* I,Ordonnanceur* O,Enregistreur* E,Recuperateur* R):Lec(L),Net(N),Anal(A),Data(I),Ord(O),Eng(E),Rec(R){}

