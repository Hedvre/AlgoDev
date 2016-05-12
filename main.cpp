#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;
// constante de la taille matrice
#define N 10

// valeur des 4 couleurs : blanc, gris clair, gris foncé et noir
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
            gotoxy(x*3+1, y+2) ; textbackground(couleur[image[x][y]]); cout << " " ;
        }
    }
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
    moyenne = moyenne/(N*N);

    //remplacement
    for (int x=0 ; x<N ; x++) {
        for (int y=0 ; y<N ; y++)
            // ne pas oublier de multiplier par 10
            //cond 1 < a la moyenne && cond2 >= 1 pour ne pas descendre en dessous de 0
            if(10*image[x][y] < moyenne && 10*image[x][y] >= 10){
                image[x][y] -=1;
            }
            //cond 1 > a la moyenne && cond2 >= 1 pour ne pas aller au delà de 3
            else if(10*image[x][y] > moyenne && 10*image[x][y] <= 20){
                image[x][y] +=1;
            }
            else{}
        }
    }
};

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

