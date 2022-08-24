#include <stdio.h>
#include <math.h>
#include "wave.h"

//constantes non modifiables
#define PI 3.14159
const int FREQ_ECHANTILLONAGE= 8000; //ne peut �tre modifi� sans modifier le fichier wave.c

//constantes modifiables
#define NB_SEC 5 //nombres de secondes de notre fichier wav
const int FREQ_NOTE_EN_HERTZ = 150; // partie param�trable pour g�n�rer une sinuoide
const double OMEGA = 2 * PI * FREQ_NOTE_EN_HERTZ ; //calcul de omega pour la sinusoide.

int main(void) {
    double t = 0 ;//temps
    double phi=0;//dephasage
    int nbEchantillon=OpenFile("test.wav",NB_SEC); //ouverture du fichier
    unsigned char data[nbEchantillon]; //cr�ation du tableau dynamiquement (VLA)
    //g�n�ration de la sinusoide
    for (int i=0 ; i<nbEchantillon ; i++) {
        data[i] = 127 + 127 * sin(OMEGA*t+phi) ;
        t = t + 1/(double)FREQ_ECHANTILLONAGE ;
    }
    //sauvegarde du fichier avec les donn�es cr��es.
    WriteFile(data,nbEchantillon);
	return 0;
}
