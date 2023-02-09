#ifndef MOTEURDERECHERCHE_H_INCLUDED
#define MOTEURDERECHERCHE_H_INCLUDED
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include "moteurrecherche.h"
#include "index.h"
#include "Analyseur.h"
#include "stats.h"
#include "Lecteur.h"
#include "Nettoyeur.h"
#include "ordonnanceur.h"
#include "Enregisteur.h"
#include "Recuperateur.h"
using namespace std;

class MoteurDeRecherche{
    vector<string> Fichiers;
    Lecteur* Lec;
    Nettoyeur* Net;
    Analyseur* Anal;
    index* Data;
    Ordonnanceur* Ord;
    Enregistreur* Eng;
    Recuperateur* Rec;
public:
    MoteurDeRecherche(Lecteur* ,Nettoyeur* ,Analyseur* ,index* ,Ordonnanceur* ,Enregistreur* ,Recuperateur*);
    void ajouterFichier(string fichier);
    void afficherFichiers();
    void supprimerFichier(string fichier);
    void enregistrerFichiers();
    void recupererFichiers();
    void indexer(string fichier);
    void indexerRepertoire(string chemin);
    void afficherIndex();
    void supprimerStatsFichier(string fichier);
    void chercher(string requette,unsigned int nbResultats);
    void enregistrerStats();
    void recupererStats();
};

#endif // MOTEURDERECHERCHE_H_INCLUDED
