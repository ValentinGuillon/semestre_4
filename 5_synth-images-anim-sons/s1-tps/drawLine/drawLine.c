
#include <stdio.h>
#include <stdlib.h>
#include <string.h> /* pour memset */
#include <images_io.h>
#include <time.h>
#include <math.h>

#define W 80
#define H 60


typedef struct coords_t {
    int x; int y;
} coords;


static void swap(coords *a, coords *b) {
    coords temp = *a;
    *a = *b;
    *b = temp;
}

static int out_of_limits(coords c1, coords c2) {
    if (c1.x < 0 || c1.x >= W)
        return 1;
    if (c2.x < 0 || c2.x >= W)
        return 1;
    if (c1.y < 0 || c1.y >= H)
        return 1;
    if (c2.y < 0 || c2.y >= H)
        return 1;
    return 0;
}



static void drawLine(unsigned char * image, int w, coords c1, coords c2, unsigned char color) {
    if (out_of_limits(c1, c2))
        return;

    float y = 0.0f, pente;

    //on fait en sorte que le tracé se fasse toujours de gauche à droite
    if (c2.x < c1.x)
        swap(&c1, &c2);

    int u = c2.x - c1.x, v = c2.y - c1.y;
    pente = v / (float)u;

    double add = 1.0;
    if (pente > add)
        add /= pente;
    else if (pente < -1*add)
        add /= -1*pente;

    //si, de gauche à droite, les y montent (diminue)
    if (pente < 0) {
        for (double x = 0; x <= u; x+=add) {
            image[(c1.y + ((int)(y + 0.5f))) * w + (int)x + c1.x] = color;
            y += pente*add;
        }
    }
    else {
        for (double x = 0; x <= u; x+=add) {
            image[(c1.y + ((int)(y + 0.5f))) * w + (int)x + c1.x] = color;
            y += pente*add;
        }
    }
}





void drawCircle(unsigned char * image) {
    printf("drawCircle() not writed !!!\n");
    drawLine(image, W, (coords){5, 10}, (coords){70, 50}, 255);
    return;
}


int main(void) {
    srand(time(0));
    /* on part sur une image 8 bits / 256 niveaux de gris */
    unsigned char image[H * W];
    /* on met tous les pixels à zéro */
    memset(image, 0, sizeof image);
    /* on dessine une droite de (5, 10) à (70, 50) 
     * la couleur utilisée est le blanc (255)
     */

    // drawLine(image, W, (coords){5, 10}, (coords){70, 50}, 255);
    // //exo 1
    // drawLine(image, W, (coords){75, 10}, (coords){0, 50}, 255); //on échange ses coordonnées
    // //exo 2
    // drawLine(image, W, (coords){10, 10}, (coords){20, 50}, 255); //j'ai pas compris l'interêt de cette ligne
    // //exo 3
    // drawLine(image, W, (coords){-10, -10}, (coords){120, 150}, 255); //on ne fait pas la fonction

    // //exo 4
    // for (float angle = 0.0f, rayon = 20.0f; angle < 2.0f * M_PI; angle += 0.5f)
    //    drawLine(image, W, (coords){W/2, H/2}, (coords){W/2 + rayon * cos(angle), H/2 + rayon * sin(angle)}, rand()%256);
    

    //exo 5
    drawCircle(image);
    //rayon * rayon = (x - x0) * (x - x0) + (y - y0) * (y - y0);


    imageSaveBMP("resu.bmp", image, W, H, 1, 8);
    printf("IMAGE SAVED !\n");
    return EXIT_SUCCESS;
}


/*
 * Exercice 1 : essayez de dessiner le segment (75, 10, 0, 50, 255),
 * ça ne fonctionne pas. Corriger drawLine.
 *
 * Exercice 2 : essayez de dessiner le segment (10, 10, 20, 50, 255),
 * ça ne fonctionne pas. Corriger drawLine.
 * 
 * Exercice 3 : essayez de dessiner le segment (-10, -10, 120, 150,
 * 255), ça ne fonctionne pas. Corriger drawLine.
 *
 * Exercice 4 : dessiner (si ça marche) toutes les positions d'une
 * aiguille trotteuse en variant les intensités de gris. Vous pouvez
 * utiliser cos et sin (inclure math.h) tels que :
 *
 * for (float angle = 0.0f, rayon = 20.0f; angle < 2.0f * M_PI; angle += 0.5f)
 *    drawLine(image, W, W/2, H/2, W/2 + rayon * cos(angle), H/2 + rayon * sin(angle), rand()%256);
 * 
 * Exercice 5 : l'équation d'un cercle est donnée par 
 * 
 * rayon * rayon = (x - x0) * (x - x0) + (y - y0) * (y - y0);
 * écrire drawCircle.
*/
