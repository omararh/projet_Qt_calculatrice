# projet_Qt_calculatrice
widgets , layouts , connexions , événements


La première étape dans la réalisation d’une interface graphique est de dessiner la maquette de l’interface voulue. Il s’agit d’une coquille vide où seuls les widgets sont en place mais aucune action n’est réalisable. L’application « Calculatrice » ne possède qu’un écran (les widgets ne sont pas modifiés par des actions, il n’y a pas plusieurs fenêtre, etc.), il est donc plus aisé de faire la maquette.
Dans l’application, nous souhaitons avoir trois « blocs », dont on voit les séparations sur l’image de droite. Le premier bloc contient les affichages : la première ligne affiche le nombre en cours de rédaction, la seconde ligne affiche l’opérateur. Le deuxième bloc permet de saisir les chiffres (réels). Le troisième bloc permet lui de saisir l’opérateur.
L’affichage des nombres doit prendre toute la largeur de la fenêtre, ne doit pas être éditable en tapant directement dedans, et le texte doit être aligné à droite.
Même principe pour l’affichage de l’opérateur, mais il doit être plus petit : seulement 30 pixels, et il doit être aligné à droite avec le premier affichage.
Le bouton du zéro doit prendre deux fois plus de place que les autres boutons afin de former un rectangle fermé.


→ Maintenant que la maquette est réalisée, il faut développer le « moteur » de l’application. Notez que le modèle de l’application est généralement développé avant la vue, afin de savoir quelles vues il faut définir.
La calculatrice est assez simpliste puisqu’elle n’effectue que des opérations entre deux réels. Le premier réel est un réel en mémoire, qui est le résultat des calculs précédents. Le second réel est en construction, et on doit pouvoir ajouter des chiffres ou séparateur décimal afin de le construire. En fonction d’un opérateur définit, on doit pouvoir calculer l’opération.
Vous serez vigilent à la production d’erreurs (division par zéro, nombre mal formé).


→ Le contrôleur fait le lien entre la vue et le modèle. Il faut donc implémenter les méthodes qui définissent les actions possibles : un chiffre (et virgule) à ajouter au nombre en cours de construction, un choix d’opérateur, l’affichage du résultat.
Il faut donc ici bien identifier quels seront les slots et quels seront les signaux. Connectez ensuite les différents signaux aux slots pour tester votre application.


→ Il peut être plus pratique de saisir directement au clavier nos opérations. Implémentez un système pour que les chiffres, la virgule et les opérations binaires (+, -, *, /) soient accessibles directement depuis le clavier.
