#include <stdio.h>  // Inclure la bibliothèque STanDard Input Output
                    // permet d'utiliser, entre autre, printf et scanf
int main() {
	const int NB_MAX_NOTES = 50;
	int nbNotes;
	float note, sommeDesNotes;
	float tabNotes[NB_MAX_NOTES]; // Déclare un tableau de 50 réels
	
	printf("Entrez des notes (entre 0 et 20)\nPour stopper, saisir une note hors de cet interval.\n");
	
	nbNotes = 0;
	// A. Saisir les notes et les mémoriser dans un tableau
	// + B. Compter les notes saisies et afficher leur nombre
	do {
		scanf("%f", &note);
		tabNotes[nbNotes] = note; // tabNotes[nbNotes] <-- note
		nbNotes++;
	} while((note >= 0) && (note <= 20) && (nbNotes < NB_MAX_NOTES));
	
	if((note < 0) || (note > 20)) nbNotes--; // La dernière note saisie n'est pas valide
	else printf("\nVous avez ateint le nombre maximum de notes possible.");

	printf("\nVous avez saisi %d notes", nbNotes);
	
	// C. Calcul et affichage de la moyenne 
	sommeDesNotes = 0;
	int i;
	for(i = 0 ; i < nbNotes ; i++) {
	    sommeDesNotes = sommeDesNotes + tabNotes[i];
	}
	
	float moyenne = sommeDesNotes / nbNotes; 
	printf("\n\nLa moyenne des notes est : %.2f\n", moyenne);
	
	// D. Comparer chaque note à la moyenne et ajouter, dans l’affichage précédent "égal",
	//    "inférieur" ou "supérieur à la moyenne"
	// + E. Compter et afficher combien il y a de notes supérieures à la moyenne
	int nbNotesSupMoy = 0;
	for(i = 0 ; i < nbNotes ; i++) {
	    printf("\n%d : %.2f", i+1, tabNotes[i]);
	    
	    if(tabNotes[i] > moyenne) {
	        printf(" > à la moyenne");
	        nbNotesSupMoy++;
	    }
	    else if(tabNotes[i] < moyenne)
	        printf(" < à la moyenne");
	    else
	        printf(" = à la moyenne");
	}
	
	printf("\n\nIl y a %d notes > à la moyenne.", nbNotesSupMoy);
	
	// F. Dans le tableau de notes, chercher la note la plus petite 
	float noteLaPlusFaible = 21;
	int positionNoteLaPlusFaible;
	for(i = 0 ; i < nbNotes ; i++) {
	    if(tabNotes[i] < noteLaPlusFaible) {
	        noteLaPlusFaible = tabNotes[i];
	        positionNoteLaPlusFaible = i + 1;
	    }
	}
	
	// F. (suite) Afficher cette note et sa position dans le tableau
	printf("\n\nLa note la plus basse est %.2f, sa position est %d", noteLaPlusFaible, positionNoteLaPlusFaible);

	// G. Dans le tableau de notes, chercher la note la plus haute 
	float noteLaPlusHaute = -1;
	int positionNoteLaPlusHaute;
	for(i = 0 ; i < nbNotes ; i++) {
	    if(tabNotes[i] > noteLaPlusHaute) {
	        noteLaPlusHaute = tabNotes[i];
	        positionNoteLaPlusHaute = i + 1;
	    }
	}
	
	// G. (suite) Afficher cette note et sa position dans le tableau
	printf("\n\nLa note la plus haute est %.2f, sa position est %d", noteLaPlusHaute, positionNoteLaPlusHaute);
	
	return 0;
}
