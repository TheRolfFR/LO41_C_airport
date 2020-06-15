# Projet LO41 UTBM P20 : Gestion d'un aéroport

<img alt="GitHub repo size" src="https://img.shields.io/github/repo-size/TheRolfFR/LO41_C_airport?style=flat-square"> <img alt="GitHub repo size" src="https://tokei.rs/b1/github/TheRolfFR/LO41_C_airport?category=code"> <a href="./LICENSE.md"><img alt="GitHub repo size" src="https://img.shields.io/badge/License-NPOSL--3.0-red?style=flat-square"></a> <a href="./README-en.md"><img src="https://img.shields.io/badge/EN-README-red?style=flat-square"></a>

_Projet individuel noté : Gestion d'un aéroport C système_

## Objectif
Comprendre le fonctionnement d'un système d'exploitation et son organistation. Utiliser l'API en C pour implémenter un cas réel:
Gérer la tour de contrôle d'un aéroport et ses pistes.

## Comment compiler et lancer le projet
Si vous utilisez [l'IDE JetBrains CLion](https://www.jetbrains.com/clion/), vous pouvez facilement commencer.
Sinon vous pouvez utiliser le [Makefile](./cmake-build-debug/Makefile) and le fichier [cbp file](./cmake-build-debug/lo41_projet.cbp)
générés automatiquement par le projet. Ou simplement, tapez ceci dans terminal :
```sh
gcc -Wall main.c -o lo41_projet && chmod +x lo41_projet && ./lo41_projet
```

ou :

```sh
./compile.sh && ./launch.sh
```

*le compileur gcc est nécessaire pour faire cette commande*

## Parties principales du code

Ici les données sont séparées dans différentes catégories/thèmes
Here data is separated in different categories/themes :

- affichage : tout ce qui permet d'afficher à l'écran
- arguments : tous les arguments passés au thread
- plane : l'avion lui-même
- controleur : le controleur chargé de réguler le traffic aérien
- listeAttente : la liste d'attente utilisée pour le décollage et l'atterissage
- mutex : tout ce qui est lié à des ressources critiques et des ressources partagées
- piste : les données des pistes et comment les gérer
- tarmac : les données du tarmac et comment le gérer
- utilitaires : toutes les fonctions utilitaires nécessaires au programme

## Dépot GitHub du projet

Si vous voulez trouver le dernier code source mis à jour, allez voir à l'adresse suivante :

[https://github.com/TheRolfFR/LO41_C_airport.git](https://github.com/TheRolfFR/LO41_C_airport.git)