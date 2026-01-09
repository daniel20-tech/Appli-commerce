#ifndef ABR_H
#define ABR_H

#include "Noeud.h"

// Arbre binaire de recherche pour gérer le stock
class ABR {
public:
    Noeud* racine;  // Racine de l'arbre
    
    ABR();  // Constructeur
    
    // Méthodes de gestion
    Noeud* insertion(Noeud* racine, Produit p);
    void affichage(Noeud* racine);
    Noeud* recherche(Noeud* racine, int idRecherche);
    void miseAJour(Noeud* racine, int id, int nouvelleQte);
    void verificationRupture(Noeud* racine, int seuil);
    double calculValeurTotale(Noeud* racine);
    Noeud* suppression(Noeud* racine, int id);  
    Noeud* trouverMin(Noeud* racine);  
};

#endif