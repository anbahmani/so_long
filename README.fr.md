[![en](https://img.shields.io/badge/language-en-red.svg)](https://github.com/anbahmani/so_long/blob/main/README.md)

# 🎮 SO LONG

Il s'agit d'un simple jeu en 2D dans lequel le joueur doit collecter tous les objets sur une carte et s'échapper en empruntant le chemin le plus court possible.

## 🌟 Points forts du projet
Ce projet, intégré dans mon parcours pédagogique à l'école 42, présente plusieurs points forts et opportunités d'apprentissage significatives. Voici quelques aspects saillants :
- Développement de compétences en graphisme informatique : L'utilisation de la librairie graphique m'a initié aux principes de base du graphisme informatique, un domaine essentiel de l'informatique moderne. J'ai appris à gérer les interactions utilisateur, le rendu graphique, et les dynamiques d'un jeu, compétences transférables à des projets plus complexes.
- Créativité et personnalisation : Le projet offre la liberté de créer votre propre univers de jeu. Cette flexibilité stimule la créativité et peut être très gratifiante, car elle m'a permis d'apporter une touche personnelle et d'explorer des idées qui dépassent les exigences de base.

## 🧐 Comment cela fonctionne-t-il ?
Le projet se structure en plusieurs segments cruciaux, chacun assurant une fonction vitale dans la constitution du jeu :
- Analyse et interprétation des données (Parsing) : Cette phase cruciale implique l'extraction et l'organisation méticuleuse des données contenues dans la carte du jeu. Elle englobe la localisation précise du joueur, des obstacles comme les murs, des points de sortie, des entités ennemies, et d'autres éléments interactifs. Cette étape est fondamentale car elle prépare toutes les informations nécessaires pour le rendu visuel ultérieur du jeu.
- Rendu graphique : Exécuté via la bibliothèque graphique fournie par l'école 42, ce segment se charge de la transposition visuelle de l'univers du jeu. Il nécessite la définition minutieuse des textures et des éléments graphiques qui composeront chaque aspect visuel du jeu, de l'environnement immersif aux personnages uniques, assurant une expérience utilisateur riche et engageante.
- Gestion des interactions et dynamiques du jeu : Ce volet concerne la définition et la manipulation des réactions du jeu aux actions de l'utilisateur. Il dicte le déroulement du jeu en réponse aux diverses décisions et actions du joueur (par exemple, les conséquences d'un déplacement vers une cellule contenant un item ou la rencontre avec un ennemi). Cette partie est essentielle pour assurer une interaction cohérente et logique dans le jeu, contribuant directement à l'expérience globale du joueur.

Chacune de ces étapes est interdépendante, nécessitant une exécution précise et une coordination étroite pour garantir la fluidité du jeu, l'immersion visuelle et une expérience utilisateur interactive. Ensemble, elles forment le pilier de la création d'un environnement de jeu virtuel cohérent et captivant.

## 📷 Aperçu

<img src="https://github.com/anbahmani/so_long/blob/main/preview/so_long.gif"/>

Mode extra : 
<img src="https://github.com/anbahmani/so_long/blob/main/preview/so_long_bonus.gif"/>

## 🧑‍💻 Lancer le jeu

Lancer en mode classique :

```
  git clone git@github.com:anbahmani/so_long.git
  cd so_long ; make ; ./so_long map/map2.ber
```

Lancer en mode extra :

```
  git clone git@github.com:anbahmani/so_long.git
  cd so_long ; make ; ./so_long_bonus map/map3.ber
```

## ⌨️ Commandes

| Touche           | Action        |
| ------------- |:-------------:|
| `ESC`         | quitter     		|
| `A`           | se déplacer vers la gauche    |
| `D`           | se déplacer vers la droite   |
| `W`           | avancer  |
| `S`           | reculer |