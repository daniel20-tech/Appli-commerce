#ifndef PRODUIT_H
#define PRODUIT_H

#include <string>
using namespace std;

// Classe pour représenter un produit
class Produit {
public:
    int id;          // ID du produit
    string nom;      // Nom
    int quantite;    // Quantité en stock
    double prix;     // Prix unitaire
};

#endif