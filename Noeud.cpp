#include "Noeud.h"

// Constructeur du noeud
Noeud::Noeud(Produit p) {
    elt = p;
    gauche = nullptr;
    droit = nullptr;
}