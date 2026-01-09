# GESTION DES VENTE ET STOCKS

## Description du projet
Application de gestion de stock développée en C++ utilisant une structure d'arbre binaire de recherche (ABR) pour organiser et gérer efficacement les produits d'une boutique. Le système permet d'ajouter, modifier, supprimer et consulter les produits avec sauvegarde automatique dans un fichier texte.

## Fonctionnalités principales
-  Ajouter un nouveau produit au stock
-  Afficher l'inventaire complet (trié par ID)
-  Mettre à jour la quantité d'un produit
-  Supprimer un produit du stock
-  Vérifier les alertes de rupture de stock
-  Calculer la valeur totale du stock
-  Sauvegarde automatique dans fichier texte
-  Interface colorée et intuitive

## Technologies utilisées
- **Langage** : C++
- **Structure de données** : Arbre Binaire de Recherche (ABR)
- **Paradigme** : Programmation Orientée Objet (POO)
- **Stockage** : Fichier texte (stock.txt)
- **Interface** : Console avec couleurs ANSI

## Étapes pour exécuter le projet

### Compilation

g++ -o gestion_stock source.cpp ABR.cpp Noeud.cpp Produit.cpp


### Exécution

./gestion_stock


## Structure du projet

TPE/Appli-commerce/
├── source.cpp          # Fichier principal avec main() et interface
├── ABR.h              # Déclaration de la classe ABR
├── ABR.cpp            # Implémentation des méthodes ABR
├── Noeud.h            # Déclaration de la classe Noeud
├── Noeud.cpp          # Implémentation du constructeur Noeud
├── Produit.h          # Déclaration de la classe Produit
├── Produit.cpp        # Fichier de la classe Produit
├── stock.txt          # Base de données des produits (généré automatiquement)
└── README.md          # Documentation du projet


## Auteurs
- **Mvondo Daniel**
- **Mouchili Mfoundikou Mohamed Moust.**

## État du projet
**Terminé et à améliorer**

Le projet est fonctionnel avec toutes les fonctionnalités de base implémentées. Des améliorations futures peuvent être apportées.

## Limites
- Pas de gestion des erreurs de saisie avancée
- Fichier texte simple (pas de base de données relationnelle)
- Interface console uniquement (pas d'interface graphique)
- Limité à un seul fichier de stock
