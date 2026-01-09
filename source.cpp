
#include <iostream>
#include "ABR.h"
#include <cstdlib>  // Pour system()
#include <fstream>  // Pour les fichiers

using namespace std;

// Fonction pour sauvegarder un produit dans le fichier
void sauvegarderProduit(const Produit& p) {
    ofstream fichier("stock.txt", ios::app);  // Mode append
    if (fichier.is_open()) {
        fichier << p.id << ";" << p.nom << ";" << p.quantite << ";" << p.prix << endl;
        fichier.close();
    }
}

// Fonction pour sauvegarder tout l'arbre dans le fichier
void sauvegarderArbre(Noeud* racine, ofstream& fichier) {
    if (racine != nullptr) {
        sauvegarderArbre(racine->gauche, fichier);
        fichier << racine->elt.id << ";" << racine->elt.nom << ";" << racine->elt.quantite << ";" << racine->elt.prix << endl;
        sauvegarderArbre(racine->droit, fichier);
    }
}

// Fonction pour réécrire complètement le fichier stock
void reecrirefichier(ABR& stock) {
    ofstream fichier("stock.txt");
    if (fichier.is_open()) {
        sauvegarderArbre(stock.racine, fichier);
        fichier.close();
    }
}

// Fonction pour charger les produits depuis le fichier
void chargerStock(ABR& stock) {
    ifstream fichier("stock.txt");
    if (fichier.is_open()) {
        string ligne;
        while (getline(fichier, ligne)) {
            if (!ligne.empty()) {
                Produit p;
                size_t pos1 = ligne.find(';');
                size_t pos2 = ligne.find(';', pos1 + 1);
                size_t pos3 = ligne.find(';', pos2 + 1);
                
                p.id = stoi(ligne.substr(0, pos1));
                p.nom = ligne.substr(pos1 + 1, pos2 - pos1 - 1);
                p.quantite = stoi(ligne.substr(pos2 + 1, pos3 - pos2 - 1));
                p.prix = stod(ligne.substr(pos3 + 1));
                
                stock.racine = stock.insertion(stock.racine, p);
            }
        }
        fichier.close();
    }
}

// Fonction pour afficher le logo de l'application
void afficherLogo() {
    cout << "\n";
    cout << "\033[1;31m";  
    cout << "                      _    ____  ____  _     ___       ____  ____  __  __ __  __ _____ ____   ____ _____\n";
    cout << "\033[1;33m";  
    cout << "                     / \\  |  _ \\|  _ \\| |   |_ _|     / ___||  _ \\|  \\/  |  \\/  | ____|  _ \\ / ___| ____|\n";
    cout << "\033[1;32m";  
    cout << "                    / _ \\ | |_) | |_) | |    | |  ____| |    | | | | |\\/| | |\\/| |  _| | |_) | |   |  _|\n";
    cout << "\033[1;36m"; 
    cout << "                   / ___ \\|  __/|  __/| |___ | | |____| |___ | |_| | |  | | |  | | |___| _ <| |___| |___\n";
    cout << "\033[1;35m";  
    cout << "                  /_/   \\_\\_|   |_|   |_____|___|      \\____|____/|_|  |_|_|  |_|_____|_| \\_\\____|_____|\n\n\n";
    cout << "\033[1;34m";  
    cout << "       ===============================================Product By Daniel & Akhash_P==========================================\n\n";
    cout << "\033[1;37m";  
    cout << "                                                      GESTION DE STOCK AVANCEE \n";
    cout << "\033[0m";     
    cout << "\n";
}



// Affichage du menu principal
void menu() {
    cout << "\033[90m"; 
    cout << "\n                                               ==================================================" << endl;
    cout << "\033[1;32m";  
    cout << "                                                          BIENVENU DANS GESTION-STOCK      " << endl;
    cout << "\033[90m"; 
    cout << "                                               ==================================================" << endl;
    cout << "\033[37m"; 
    cout << "                                                1. Ajouter un nouveau produit" << endl;
    cout << "                                                2. Afficher l'inventaire complet" << endl;
    cout << "                                                3. Mettre a jour la quantite d'un produit" << endl;
    cout << "                                                4. Supprimer un produit" << endl;
    cout << "                                                5. Verifier les alertes de rupture" << endl;
    cout << "                                                6. Calculer la valeur totale du stock" << endl;
    cout << "                                                0. Quitter l'application" << endl;
    cout << "\033[90m";  // Gris clair pour les bordures
    cout << "                                               ==================================================" << endl;
    cout << "\033[33m";  // Jaune pour le prompt
    cout << "                                                                  Votre choix : ";
    cout << "\033[0m";  // Reset couleur
}

int main() {
    ABR monStock;  // Création de l'arbre
    int choix;
    
    system("cls");  // Nettoyer l'écran
    afficherLogo();  // Afficher le logo
    
    // Charger les produits existants depuis le fichier
    chargerStock(monStock);
    
    do {
        menu();
        cin >> choix;

        switch (choix) {
            case 1: {  // Ajouter un produit
                cout << "\033[41m\033[1;37m                  === AJOUTER UN PRODUIT ===                  \033[0m\n";
                Produit p;
                cout << "                  ID : "; cin >> p.id;
                cout << "                  Nom : "; cin >> p.nom;
                cout << "                  Quantite : "; cin >> p.quantite;
                cout << "                  Prix : "; cin >> p.prix;
                monStock.racine = monStock.insertion(monStock.racine, p);
                reecrirefichier(monStock);  // Réécrire le fichier après ajout
                cout << "\n                  Produit ajoute avec succes!!" << endl;
                break;
            }
            case 2:  // Afficher l'inventaire
                cout << "\033[42m\033[1;37m                  === INVENTAIRE COMPLET ===                  \033[0m\n";
                monStock.affichage(monStock.racine);
                break;
            case 3: {  // Modifier quantité
                cout << "\033[43m\033[1;30m                  === MODIFIER QUANTITE ===                  \033[0m\n";
                int id, qte;
                cout << "                  ID du produit a modifier : "; cin >> id;
                cout << "                  Nouvelle quantite : "; cin >> qte;
                monStock.miseAJour(monStock.racine, id, qte);
                reecrirefichier(monStock);  // Réécrire le fichier après modification
                break;
            }
            case 4: {  // Supprimer un produit
                cout << "\033[44m\033[1;37m                  === SUPPRIMER PRODUIT ===                  \033[0m\n";
                int id;
                cout << "                  ID du produit a supprimer : "; cin >> id;
                Noeud* produit = monStock.recherche(monStock.racine, id);
                if (produit != nullptr) {
                    cout << "                  Suppression du produit: " << produit->elt.nom << endl;
                    monStock.racine = monStock.suppression(monStock.racine, id);
                    reecrirefichier(monStock);  // Réécrire le fichier après suppression
                    cout << "                  Produit supprime et fichier mis a jour !" << endl;
                } else {
                    cout << "                  Produit non trouve." << endl;
                }
                break;
            }
            case 5: {  // Alertes rupture
                cout << "\033[45m\033[1;37m                  === ALERTES RUPTURE ===                  \033[0m\n";
                int seuil;
                cout << "                  Entrez le seuil d'alerte : "; cin >> seuil;
                monStock.verificationRupture(monStock.racine, seuil);
                break;
            }
            case 6:  // Valeur totale
                cout << "\033[46m\033[1;30m                  === VALEUR TOTALE ===                  \033[0m\n";
                cout << "                  Valeur totale du stock : "
                     << monStock.calculValeurTotale(monStock.racine) << " FCFA" << endl;
                break;
            case 0:
                cout << "\033[47m\033[1;31m                  === AU REVOIR ===                  \033[0m\n";
                break;
            default:
                cout << "\033[101m\033[1;37m                  === CHOIX INVALIDE ===                  \033[0m\n";
                cout <<"Product By Daniel & Akhash_P";
        }
    } while (choix != 0);

    return 0;
}
