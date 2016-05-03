#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;
// constante de la taille matrice
#define N 10

// valeur des 4 couleurs : blanc, gris clair, gris foncé et noir
int couleur[4] = {15, 7, 8, 0};

int main()
{
    //déclaration
    int image[N][N];
    //saisie de  la matrice d'origine
    saisieMatrice(image);
    // affichage de l’image
    afficheImage(image, 1) ;
    // accentuation du contraste
    accentueContraste(image) ;
    // affichage de l’image
    afficheImage(image, N+10) ;
    cout << N << endl;
    return 0;
}
