#ifndef NOEUD_H
#define NOEUD_H

#include "Produit.h"

// Noeud de l'arbre binaire
class Noeud {
public:
    Produit elt;     // Le produit stocké
    Noeud* gauche;   // Fils gauche
    Noeud* droit;    // Fils droit
    
    Noeud(Produit p);  // Constructeur
};

#endif