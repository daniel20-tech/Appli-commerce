#include "ABR.h"
#include <iostream>
using namespace std;

// Constructeur
ABR::ABR() {
    racine = nullptr;
}

// Insérer un produit dans l'arbre
Noeud* ABR::insertion(Noeud* racine, Produit p) {
    if (racine == nullptr) {
        return new Noeud(p);
    }

    // Insertion selon l'ID
    if (p.id < racine->elt.id) {
        racine->gauche = insertion(racine->gauche, p);
    } else if (p.id > racine->elt.id) {
        racine->droit = insertion(racine->droit, p);
    } else {
        // Si l'ID existe déjà, afficher un message d'erreur
        cout << "                  ERREUR: Un produit avec l'ID " << p.id << " existe deja !" << endl;
    }

    return racine;
}

// Afficher tous les produits (parcours infixe)
void ABR::affichage(Noeud* racine) {
    if (racine != nullptr) {
        affichage(racine->gauche);
        
        cout << "                  ID: " << racine->elt.id
             << " | Nom: " << racine->elt.nom
             << " | Stock: " << racine->elt.quantite
             << " | Prix: " << racine->elt.prix << " FCFA" << endl;
        
        affichage(racine->droit);
    }
}

// Chercher un produit par son ID
Noeud* ABR::recherche(Noeud* racine, int idRecherche) {
    if (racine == nullptr || racine->elt.id == idRecherche) {
        return racine;
    }

    if (idRecherche < racine->elt.id) {
        return recherche(racine->gauche, idRecherche);
    }
    
    return recherche(racine->droit, idRecherche);
}

// Mettre à jour la quantité d'un produit
void ABR::miseAJour(Noeud* racine, int id, int nouvelleQte) {
    Noeud* noeud = recherche(racine, id);
    if (noeud != nullptr) {
        noeud->elt.quantite = nouvelleQte;
        cout << "                  Stock mis a jour pour: " << noeud->elt.nom << endl;
    } else {
        cout << "                  Produit non trouve." << endl;
    }
}

// Vérifier les produits en rupture
void ABR::verificationRupture(Noeud* racine, int seuil) {
    if (racine == nullptr) 
        return;

    if (racine->elt.quantite < seuil) {
        cout << "                  ALERTE: Le produit " << racine->elt.nom
             << " est presque epuise (" << racine->elt.quantite << " restants)" << endl;
    }

    verificationRupture(racine->gauche, seuil);
    verificationRupture(racine->droit, seuil);
}

// Calculer la valeur totale du stock
double ABR::calculValeurTotale(Noeud* racine) {
    if (racine == nullptr) {
        return 0.0;
    }

    double valeur = racine->elt.quantite * racine->elt.prix;
    return valeur + calculValeurTotale(racine->gauche) + calculValeurTotale(racine->droit);
}

// Trouver le noeud avec la valeur minimale
Noeud* ABR::trouverMin(Noeud* racine) {
    while (racine && racine->gauche != nullptr) {
        racine = racine->gauche;
    }
    return racine;
}

// Supprimer un produit de l'arbre
Noeud* ABR::suppression(Noeud* racine, int id) {
    if (racine == nullptr) {
        return racine;
    }

    // Chercher le noeud à supprimer
    if (id < racine->elt.id) {
        racine->gauche = suppression(racine->gauche, id);
    } else if (id > racine->elt.id) {
        racine->droit = suppression(racine->droit, id);
    } else {
        // Noeud trouvé, on le supprime
        if (racine->gauche == nullptr) {
            Noeud* temp = racine->droit;
            delete racine;
            return temp;
        } else if (racine->droit == nullptr) {
            Noeud* temp = racine->gauche;
            delete racine;
            return temp;
        }

        // Noeud avec deux enfants
        Noeud* temp = trouverMin(racine->droit);
        racine->elt = temp->elt;
        racine->droit = suppression(racine->droit, temp->elt.id);
    }
    return racine;
}