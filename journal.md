13/11 : premiere séance (debut)
    - language : C++, language nécessaire au master imagine donc ca m'entraine
    
    - Format du tournoi : chaque programme affronte chaque autre sur 5 parties de 200 tours ; le gagnant a le meilleur score total (CM page 63)
    
    - Matrice de gain : (C,C) = 3,3 · (C,D) = 0,5 · (D,C) = 5,0 · (D,D) = 2,2
    
    - Gains : 
            Les préférences de i :
            D,C ≻ᵢ C,C ≻ᵢ D,D ≻ᵢ C,D
            
            Les noms des issues
            5 : la tentation · 3 : la récompense · 2 : la punition · 0 : le gain du pigeon

    -regles :
        - une strategie peut jouer contre elle meme si ce n'est pas le meme "joueur"
        - chaque programme connait les coups passés de l'adversaire
        - Score : somme des scores contre chaque adversaire

    Stratégies : 
        - ALL-D :  toujours D : la stratégie "rationnelle" de la récurrence à rebours 
        - RANDOM :  C ou D au hasard, une chance sur deux : sert de témoin
        - TI-FOR-TAT : C au premier tour, puis rejouer le coup de l'adversaire au tour précédent
        - TESTER : D au premier tour. Si l'adversaire à riposté au tour 1, joue TIT-FOR-TAT à partir du tour 2 ; sinon répète C, C, D a partir du tour 2 (interpretation du cm page 64)
        - JOSS : TIT-FOR-TAT, mais remplace C par D une fois sur dix de facon deterministe

    Graine aléatoire : std::mt19937 rng(2052004); (valeur arbitraire)

14/11 : moteur du tournoi
    - Modèle de population : une case de la population = un JOUEUR (comme dans le mini-tournoi du CM page 68 : TFT1, TFT2, ALL-D).
        - un joueur ne joue jamais contre lui-même : chaque paire de joueurs différents joue un match (boucle j = i + 1)
        - pour faire jouer une stratégie contre elle-même, on met deux joueurs de cette stratégie dans la population (ex : TFT1 contre TFT2)
        - ce modèle servira directement pour la sélection (étape 3), où le nombre de joueurs de chaque stratégie varie

    - Impasse : j'avais d'abord fait jouer chaque case contre elle-même (boucle j = i, en comptant le score une seule fois),
      en pensant qu'une case = une stratégie et que ce match représentait TFT1 contre TFT2.
      Problème : si on met deux TFT dans la population, le match TFT contre TFT est joué 3 fois au lieu d'une.
      Le CM (page 68) montre qu'un joueur ne joue pas contre lui-même (diagonale vide) → retour à j = i + 1.

    - Stratégies sans état interne : JOSS et TESTER décident uniquement à partir de mesCoups / coupsAdverses
      (mesCoups.size() donne le numéro du tour), donc pas besoin de reset() et un même objet peut servir à plusieurs joueurs sans risque.

    - Différence avec Axelrod 1980 : avec un joueur par stratégie, il n'y a pas de match entre "jumeaux" (Axelrod en faisait un).
      À prendre en compte pour répondre à la question "TFT gagne-t-il ?".

    - Test de validation prévu : population {TFT, TFT, ALL-D}, 1 partie de 10 tours → on doit retrouver TFT1 = 48, TFT2 = 48, ALL-D = 46 (CM page 68).

15/11 : Tournoi d'Axelrod : 
    Observations : 
      -TFT : n'affronte pas assez de strategies coopérative et ne peux donc pas farmer des points.
      -AllD : se fait avoir pas les strategies qui verifie qui verifient si il joue D et qui ensuite l'empeche de marquer des points
      -Joss : joue comme TFT, mais vole des points avec ses D surprises, gagne de peu grace a ca. Contre ALL-D il perd comme TFT.
      -Random : dernier, perd beaucoup contre ALL-D (998 - 3503) et comme il joue au hasard il ne peut jamais construire une longue cooperation pour marquer des points. Il bat quand meme Tester.
      -Tester : contre ALL-D il voit le D au tour 1 donc passe en TFT, ca donne D/D tout le temps donc égalité. Contre ceux qui jouent C au tour 1 (TFT, JOSS) il essaie d'exploiter avec C, C, D mais ils ripostent : egalite contre TFT et il perd contre JOSS.
