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