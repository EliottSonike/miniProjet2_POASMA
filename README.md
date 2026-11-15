# Tournoi du dilemme du prisonnier itéré

Projet HAI716I (Projet 2, partie 1) : un moteur de tournoi de dilemme du prisonnier itéré en C++, au format d'Axelrod. Chaque stratégie affronte chaque autre sur 5 parties de 200 tours, et le meilleur score total gagne.

Le journal de bord (démarche, prédictions, résultats, impasses) est dans [journal.md](journal.md), et les captures d'écran sont dans [captures/](captures/).

## Prérequis

- un compilateur C++17 (`g++`)
- `make`

**Linux (Debian / Ubuntu)** :

```bash
sudo apt install g++ make
```

**Windows** : avec [MSYS2](https://www.msys2.org/), installer `g++` et `make` :

```bash
pacman -S mingw-w64-x86_64-gcc make
```

puis ajouter ces deux dossiers au `PATH` (variables d'environnement Windows) :

```
C:\msys64\mingw64\bin
C:\msys64\usr\bin
```

## Compilation

À la racine du dépôt :

```bash
make         # compile l'executable (tournoi sous Linux, tournoi.exe sous Windows)
make clean   # supprime les fichiers compiles
```

## Lancer les tournois

Un argument choisit le tournoi. Un seul tournoi est lancé par exécution.

| Commande Linux | Commande Windows | Tournoi |
|---|---|---|
| `./tournoi diapo` | `tournoi.exe diapo` | Test de validation du CM page 68 : TFT, TFT, ALL-D, 1 partie de 10 tours (résultat attendu : 48, 48, 46) |
| `./tournoi etape1` | `tournoi.exe etape1` | Étape 1 : les 5 stratégies du cours (ALL-D, RANDOM, TIT-FOR-TAT, TESTER, JOSS) |
| `./tournoi etape2` | `tournoi.exe etape2` | Étape 2 : population élargie avec GRUDGER et WSLS (7 stratégies) |
| `./tournoi bruit` | `tournoi.exe bruit` | Étape 3 : population de l'étape 2, chaque coup inversé avec une probabilité de 5 % |
| `./tournoi horizon` | `tournoi.exe horizon` | Étape 3 : population de l'étape 2, horizon inconnu (la partie continue avec une probabilité w = 0,995, soit 200 tours en moyenne) |
| `./tournoi combine` | `tournoi.exe combine` | Bonus : bruit 5 % et horizon inconnu en même temps |

Sans argument, le programme affiche la liste des modes.

Le programme affiche le score de chaque duel, puis le classement final.

## Reproductibilité

Le générateur aléatoire est un `std::mt19937` avec une graine fixe (`2052004`). Comme chaque exécution ne lance qu'un seul tournoi, une même commande redonne toujours exactement le même résultat. Les résultats sont identiques sous Windows (MSYS2, g++) et sous Linux (g++).

## Organisation du code

```
src/
  main.cpp          choix du tournoi (modes)
  Moteur.hpp/.cpp   partie, match, tournoi, classement, options (bruit, horizon)
  Strategie.hpp     classe de base des strategies
  Coup.hpp          les coups C et D
  Strategies.hpp    inclut toutes les strategies
  strategies/       une classe par strategie (AllD, Random, TitForTat, Tester, Joss, Grudger, WSLS)
captures/           captures d'ecran des resultats
journal.md          journal de bord
```

Pour ajouter une stratégie : créer `src/strategies/Nom.hpp` et `Nom.cpp` (une classe qui hérite de `Strategie` et définit `choisir()` et `nom()`), puis l'inclure dans `Strategies.hpp`. Le Makefile compile automatiquement tous les fichiers de `src/`.
