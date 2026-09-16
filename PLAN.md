# Contexte du projet — à lire avant de m'aider (Claude Code)

> Ce fichier a été rédigé par **Claude (interface web/chat, claude.ai)**, dans une conversation séparée de celle-ci, avec Ethan. Il sert à te donner (Claude Code) tout le contexte nécessaire pour continuer le projet directement dans ce dépôt, sans qu'Ethan ait à tout réexpliquer. Traite-le comme un brief de projet, pas comme des instructions figées — les décisions ci-dessous peuvent évoluer, demande confirmation à Ethan si quelque chose semble dépassé ou contradictoire avec l'état actuel du repo.

## Qui est l'utilisateur

Ethan, étudiant français, en stage de recherche à la THM (Gießen, Allemagne). Ce projet clavier est **personnel**, sans lien avec son stage. Il n'est pas développeur de formation — plutôt réseau/systèmes/sécurité — donc explique les concepts techniques simplement, pas de jargon non expliqué.

## Le projet en une phrase

Construire un clavier ergonomique **Corne V4 Pro Micro Edition**, **sans fil**, sous firmware **ZMK**, avec une disposition de touches personnalisée pensée pour le français (pas de l'AZERTY recopié tel quel), en partant de la config ZMK que Max (propriétaire original de ce repo, forké par Ethan) lui a donnée comme base.

## Les repos impliqués

- **Ce repo (`corne42`)** — forké par Ethan depuis `TheBestPartOfMe/corne42` (le compte de Max). C'est la config logicielle ZMK : dossier `config/` (fichiers `.keymap`, `.conf`), `build.yaml` pour la CI GitHub Actions, `keymap-drawer/` pour visualiser la disposition en SVG. Généré à l'origine depuis le template `typeractivexyz/corne-wireless-view-zmk-config` (donc pensé pour du **sans fil** avec écran nice!view).
- **PCB/matériel** : https://github.com/klouderone/CorneV4ProMicroEdition — repo séparé, pas cloné, contient les gerbers PCB, les fichiers de boîtier imprimables en 3D, et le README avec la liste de composants (BOM). Le PCB supporte switches MX **et** Choc, filaire (Pro Micro) **et** sans fil (nice!nano V2).
- **Firmware** : https://github.com/zmkfirmware/zmk (le firmware lui-même, généralement pas besoin d'y toucher directement, `corne42` s'appuie dessus via West).

## Décisions déjà prises avec Ethan

1. **Sans fil**, ZMK, avec des **nice!nano V2** (pas de Pro Micro filaire).
2. **Switches déjà en stock** : Akko Creamy Blue V3 Pro, tactiles, format MX 5-pin, 45 unités (couvre les 42 touches + 3 de rechange).
3. **Keycaps personnalisées** : sujet mis de côté pour l'instant, à traiter plus tard (impression 3D possible, Ethan a une imprimante).
4. **Disposition de touches** : **décision changée le 2026-09-16** (session Claude Code, en désaccord avec ce brief initial) — Ethan veut finalement un **AZERTY français porté tel quel** sur le Corne (lettres dans le même ordre qu'un clavier AZERTY classique, juste coupé en deux moitiés), pas de réorganisation ergonomique des lettres. La piste Ergo-L/Ergopti évoquée ci-dessous est abandonnée pour l'instant, possiblement à revisiter plus tard une fois à l'aise avec le clavier.
   - ~~Piste abandonnée : s'inspirer de la logique de **Bone** (disposition allemande, optimisée par ordinateur) adaptée au français via **Ergo-L** (ergol.org) ou **Ergopti**, plutôt que le Bépo classique.~~
5. Ethan est en tout début de projet : rien n'est encore commandé/soudé. Il travaille en ce moment sur la partie logicielle (repo + disposition) en parallèle de la commande des pièces.

## Ce qui reste à faire (dans l'ordre logique)

1. **Comprendre le repo `CorneV4ProMicroEdition`** (Ethan est en train de le lire) : liste de composants exacte, vérifier si le shield ZMK générique `corne` correspond bien à la matrice/brochage réel du PCB (le README du PCB recommande QMK/VIA à l'origine, donc pas garanti à 100% que la config ZMK actuelle colle sans adaptation).
2. **Compléter la BOM** (liste d'achat) : microcontrôleurs nice!nano V2 x2, sockets hotswap MX x42, diodes, connecteurs batterie + batteries + interrupteurs (sans fil), boutons reset, supports Mill-Max pour rendre le microcontrôleur amovible, éventuellement écran nice!view.
3. **Fabrication** : envoyer les gerbers PCB à un fabricant en ligne (JLCPCB ou équivalent), imprimer le boîtier en 3D avec les fichiers du repo PCB.
4. **Soudure** de la carte (ordre : diodes → sockets hotswap → TRRS/pads batterie → interrupteur/reset → supports microcontrôleur → headers écran → test électrique → switches → boîtier).
5. **Travail sur ce repo (`corne42`)** :
   - Vérifier/adapter `build.yaml` (cibles board `nice_nano_v2` + shield, gauche/droite).
   - Concevoir la disposition de touches définitive (couches, lettres, accents français, symboles/couche code) et l'écrire dans le fichier `.keymap`.
   - Utiliser `keymap-drawer` pour visualiser/valider chaque itération de la disposition.
   - Laisser la CI GitHub Actions compiler, ou configurer l'environnement ZMK en local (`west`) pour itérer plus vite.
6. **Flash** des fichiers `.uf2` générés sur les deux nice!nano (mode bootloader, drag & drop).
7. **Tests et itérations** : vérifier chaque touche, ajuster le keymap, entraînement à la nouvelle disposition.
8. **Finitions** : boîtier fermé, keycaps personnalisées.

## Comment m'aider (Claude Code) à partir d'ici

- Si Ethan te demande de travailler sur le `.keymap` ou `build.yaml` : commence par lire les fichiers existants dans `config/` pour comprendre ce que Max avait déjà mis en place, avant de proposer des changements.
- Ne pars pas du principe qu'il faut "traduire" un keymap QWERTY vers AZERTY touche par touche — la disposition est à concevoir en fonction des choix ci-dessus (esprit Ergo-L/Ergopti), pas recopiée depuis un clavier standard.
- Si un point de ce fichier semble en désaccord avec l'état actuel du repo (ex. le shield/board dans `build.yaml` ne correspond pas à `nice_nano_v2`), signale-le à Ethan plutôt que de trancher seul.
