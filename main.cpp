#include <iostream>
#include <string>
#include <vector>
#include <chrono>
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

int main()
{
    LecteurFichier Lec;
    EnregistreurVector Eng;
    RecuperateurVector Rec;
    Nettoyeur_majus Net;
    AnalyseurNbApp Analys;
    OrdonnanceurExistence Ord;
    indexVector Data;
    MoteurDeRecherche Moteur(&Lec,&Net,&Analys,&Data,&Ord,&Eng,&Rec);
    auto t3 = chrono::high_resolution_clock::now();
    Moteur.recupererStats();
    auto t4 = chrono::high_resolution_clock::now();
    cout << "L'operation dure "<< chrono::duration_cast<chrono::milliseconds>(t4-t3).count()<< " millisecondes\n";
    int i;
    unsigned int n;
    string input;

    while(true)
    {
        cout << "1- Ajoutter un fichier. " << endl;
        cout << "2- Afficher la liste des fichiers. " << endl;
        cout << "3- Supprimer un fichier. " << endl;
        cout << "4- Indexer un fichier. " << endl;
        cout << "5- Indexer une repertoire. " << endl;
        cout << "6- Afficher l'index."<<endl;
        cout << "7- Supprimer les stats d'un fichier. " << endl;
        cout << "8- Faire une recherche. " << endl;
        cout << "0- Quitter. " << endl;
        cin >> i;
        switch(i)
        {
        case 0:
        {
            auto t1 = std::chrono::high_resolution_clock::now();
            Moteur.enregistrerStats();
            Moteur.enregistrerFichiers();
            auto t2 = std::chrono::high_resolution_clock::now();
            std::cout << "L'operation dure "<< std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count()<< " millisecondes\n";
            return 0;
        }
        case 1:
            cout << "Donnez le nom du fichier: " << endl;
            cin >> input;
            Moteur.ajouterFichier(input);
            continue;
        case 2:
            Moteur.afficherFichiers();
            continue;
        case 3:
            cout << "Donnez le nom du fichier: " << endl;
            cin >> input;
            Moteur.supprimerFichier(input);
            continue;

        case 4:
            cout << "Donnez le nom du fichier: " << endl;
            cin >> input;
            Moteur.indexer(input);
            continue;
        case 5:
        {
            cout << "Donnez le nom du repertoire: " << endl;
            cin >> input;
            auto t1 = std::chrono::high_resolution_clock::now();
            Moteur.indexerRepertoire(input);
            auto t2 = std::chrono::high_resolution_clock::now();
            std::cout << "L'operation dure "<< std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count()<< " millisecondes\n";
            continue;
        }
        case 6:
        {
            auto t1 = std::chrono::high_resolution_clock::now();
            Moteur.afficherIndex();
            auto t2 = std::chrono::high_resolution_clock::now();
            std::cout << "L'operation dure "<< std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count()<< " millisecondes\n";
            continue;
        }
        case 7:
        {
            cout << "Donnez le nom du fichier: " << endl;
            cin >> input;
            auto t1 = std::chrono::high_resolution_clock::now();
            Moteur.supprimerStatsFichier(input);
            auto t2 = std::chrono::high_resolution_clock::now();
            std::cout << "L'operation dure "<< std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count()<< " millisecondes\n";
            continue;
        }
        case 8:
        {
        cout << "Donnez la recherche: " << endl;
        while(getchar() != '\n');
        getline (cin, input);
        cout<< "Donnez le nombre maximale de resultats: "<<endl;
        cin>>n;
        auto t1 = std::chrono::high_resolution_clock::now();
        Moteur.chercher(input,n);
        auto t2 = std::chrono::high_resolution_clock::now();
        std::cout << "L'operation dure "<< std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count()<< " millisecondes\n";
        continue;
        }
        }
    }
    return 0;
}
