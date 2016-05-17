#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio2.h>
//#include <conio.h>


using namespace std;
// constante de la taille matrice
#define N 10


int couleur[4] = {15, 7, 8, 0};


//déclaration fonctions

int saisie(int x, int y) {
    int val ;
    do {
        gotoxy(x, y) ; cout << " " ;
        gotoxy(x, y) ; val=getche() ;
    }while(val<48 || val>51) ;
    return (val-48) ;
}

void saisieMatrice(int image[N][N]){
    gotoxy(1, 1) ; cout << "Saisie de la matrice (valeurs 0 blanc, 1 gris clair, 2 gris foncé ou 3 noir) :" ;
    // affihage des points pour montrer où se fait la saisie
    for (int x=0 ; x<N ; x++) {
        for (int y=0 ; y<N ; y++) {
            gotoxy(x*3+1, y+2) ; cout << "." ;
        }
    }
    // saisie
    for (int x=0 ; x<N ; x++) {
        for (int y=0 ; y<N ; y++) {
            image[x][y] = saisie(x*3+1, y+2) ;
        }
    }
};


void afficheImage(int image[N][N], int position){
    gotoxy(position, 1) ;
    for (int x=0 ; x<N ; x++) {
        for (int y=0 ; y<N ; y++) {
            gotoxy(x + position, y+2+N) ; textbackground(couleur[image[x][y]]); cout << " " ;
        }
    }

    //retour au fond noir pour la console ;)
    textbackground(couleur[3]);
};

void accentueContraste(int image[N][N]){
    int moyenne = 0;
    //calcul de la moyenne
    for (int x=0 ; x<N ; x++) {
        for (int y=0 ; y<N ; y++) {
            moyenne += image[x][y];
        }
    }
    moyenne *= 10; // pas de virgule donc décalage de 10 pour 1 chiffre significatif
    moyenne /=(N*N);

    //remplacement des valeurs de la matrice
    for (int x=0 ; x<N ; x++) {
        for (int y=0 ; y<N ; y++){
            // ne pas oublier de multiplier par 10
            //cond1 < a la moyenne && cond2 > 0 pour ne pas descendre en dessous de 0
            if(10*image[x][y] < moyenne && image[x][y] > 0){
                --image[x][y];
            }
            //cond1 > a la moyenne && cond2 < 3 pour ne pas aller au delà de 3
            else if(10*image[x][y] > moyenne && image[x][y] < 3){
                ++image[x][y];
            }
            else{
                //on ne fait rien
            }
        }
    }
};

int main()
{
    //déclaration de la matrice
    int image[N][N];
    //saisie de  la matrice d'origine
    saisieMatrice(image);
    // affichage de l’image
    afficheImage(image, 1) ;
    // accentuation du contraste
    accentueContraste(image) ;
    // affichage de l’image contrastée
    afficheImage(image, N+10) ;
    return 0;
}

