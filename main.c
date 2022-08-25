#include <stdio.h>
#include <math.h>
#include "wave.h"

//constantes non modifiables
#define PI 3.14159
const int FREQ_ECHANTILLONAGE= 48000; //ne peut �tre modifi� sans modifier le fichier wave.c

//constantes modifiables
#define NB_SEC 5 //nombres de secondes de notre fichier wav
const double FREQ_NOTE_EN_HERTZ = 150; // partie param�trable pour g�n�rer une sinuoide
const double OMEGA = 2 * PI * FREQ_NOTE_EN_HERTZ ; //calcul de omega pour la sinusoide.

int main(void)
{
    double t = 0 ;//temps
    double phi=0;//dephasage
    int nb_echantillons=CreerFichierSon("sinus.wav",1,NB_SEC); //ouverture du fichier
    unsigned char data[nb_echantillons]; //cr�ation du tableau dynamiquement (VLA)
    //g�n�ration de la sinusoide
    for (int i=0 ; i<nb_echantillons; i++)
    {
        data[i] = 127 + 127 * sin(OMEGA*t+phi) ;
        t = t + 1/(double)FREQ_ECHANTILLONAGE ;
    }
    //sauvegarde du fichier avec les donn�es cr��es.
    EnregistrerFichierSon(data,nb_echantillons);
    return 0;
}

