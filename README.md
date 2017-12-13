# wolf3d

- Probleme Makefile : make $(NAME)
- Verif sur fichier externe - il faut des murs sur les contours !
- changer fichier externe pour mettre sur la premiere ligne les info du labyrinthe et la pos de base du joueur
- X.h --> /System/Library/Frameworks/Tk.framework/Versions/8.5/Headers/X11/
- pourquoi ne pas choisir les touches que l'on souhaite utiliser ?
- LEAKS !!!


src/boucle.c:	while (env->hit == 0) //TODO: boucle infini si fichier pourri !!!
src/hook.c://TODO: donner la possibilite de choisir ces touches de mouvement
src/hook.c:		exit(0); //TODO: free + destruction image : faire fonction
src/hook.c:	//TODO: faire fonction pour fermer le prog en haut a gauche
src/hook.c:	env->dep.time = tmp + 10000; //TODO: a reduire, pour up le rafraichis.. !!
src/main.c:// TODO: free env.tab !!
