# Référence du keymap Corne42 (AZERTY français)

Ce fichier liste tout ce qui est déjà mappé dans [config/corne.keymap](config/corne.keymap),
pour savoir en un coup d'œil ce qui reste libre. Les noms `FR_xxx` viennent de
[config/keys_fr.h](config/keys_fr.h) et représentent directement le caractère
français tapé (pas un code brut à interpréter).

Rappel de la disposition physique (3 rangées de 6 touches par main + 3 pouces
par main = 42 touches). `trans` = "transparent", la touche ne fait rien de
spécial sur cette couche, elle retombe sur la couche du dessous.

## Couche 0 — Base (active par défaut)

```
ECHAP   A   Z   E   R   T   |   Y   U   I   O   P   BKSP
TAB     Q   S   D   F   G   |   H   J   K   L   M   ENTREE
MAJ.G   W   X   C   V   B   |   N   ,   ;   :   !   MAJ.D
              CTRL  LWR  ESPACE   |   RSE  ALT  WIN
```

- `LWR` (pouce gauche) = maintenir pour activer la couche **Chiffres**.
- `RSE` (pouce droit) = maintenir pour activer la couche **Symboles**.
- Maj fonctionne automatiquement sur toutes les lettres (majuscules) et sur
  `, ; : !` → `? . / §`, comme sur un vrai clavier AZERTY. Rien à coder pour ça.

## Couche 1 — Chiffres (LWR maintenu)

```
        &    é    "    '    (   |   -    è    _    ç    à    )
             .    .    .    .   |  GCHE  BAS  HAUT DRTE  .    .
       BTCLR BT1  BT2  BT3  .   |   .    .    .    .    .    .
              CTRL   .   ESPACE   |   .   ALT  WIN
```

- Sans Maj : accents français directs. Avec Maj (physique) : chiffres `1234567890`.
- `BTCLR` efface les appairages Bluetooth, `BT1`/`BT2`/`BT3` sélectionnent un
  profil Bluetooth (ordi 1, 2, 3).
- **Libre / pas encore décidé** : toute la rangée du milieu à gauche (5
  touches), toute la rangée du bas à droite (5 touches), `BT3`+1 slot bt libre.
  Idées possibles : F1-F12, réglages son (volume/lecture), un 4ᵉ profil BT.

## Couche 2 — Symboles (RSE maintenu)

```
        ~    #    {    [    |   |   `    \    ^    @    ]    }
        =    .    .    .    .   |   €    .    .    .    .    .
        .    .    .    .    .   |   .    .    .    .    .    .
              CTRL   .   ESPACE   |   RSE  ALT  WIN
```

- `^` et `` ` `` sont des touches mortes : elles se combinent avec la touche
  suivante (ex. `^` puis `E` → `ê`). Pour taper le symbole seul : la touche
  puis Espace.
- **Libre / pas encore décidé** : quasiment toute la rangée du milieu (sauf `=`
  et `€`) et toute la rangée du bas (10 touches). Idées possibles : flèches
  aussi accessibles ici, raccourcis media, touches de fonction F1-F12.

## Pas encore abordé du tout

- Touches de fonction F1-F12 (utile si tu fais du dev/debug).
- Une couche ou combo dédiée aux accents circonflexes/tréma composés
  (`ê â î ô û`, `ë ï ü`) — actuellement accessibles via `^`/`` ` `` + lettre,
  mais pas encore testé sur vrai matériel.
- Réglages Bluetooth avancés (BT4/BT5 comme dans la version d'origine de Max).
- Boîtier/PCB : rien à voir avec ce fichier, cf. [PLAN.md](PLAN.md).

## Piège à éviter en éditant à la main ou via keymap-editor.github.io

Toujours utiliser les alias `FR_xxx` (pas les lettres US brutes) pour toute
nouvelle touche de lettre/accent/symbole — sinon le résultat réel à l'écran
sera différent de ce qui est affiché dans l'éditeur (déjà arrivé avec A/Q,
W/Z et M). Si tu édites sur le site, montre-moi le fichier avant de considérer
que c'est bon, je vérifie contre ce document.
