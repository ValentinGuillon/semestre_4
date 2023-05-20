
#include <GL4D/gl4dp.h>
#include <GL4D/gl4duw_SDL2.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define W 300
#define H 300



typedef struct coords_t {
    int x;
    int y;
} my_coords;





//appel la méthode gl4duClean()
void clean(void);
//échange deux points
void swap(my_coords *a, my_coords *b);
//retourne 1 si "c" est hors du rectangle "limits"
int out_of_limits(my_coords c, my_coords limits_p0, my_coords limits_p1);
//place un point coloré
void drawPoint(GLuint *pixels, my_coords point, my_coords limits, GLuint color);
//place des pixels colorés de p0 à p1
void drawLine(GLuint *pixels, my_coords limits, my_coords p0, my_coords p1, GLuint color);
//place des pixels colorés de p0 à p1. La couleur s'intensifie en s'éloignant de "p0"
void drawLine_fade(GLuint *pixels, my_coords limits, my_coords p0, my_coords p1);
//place des lignes dans tous les sens en partant d'un point définit (donne une illusion de vitesse)
void drawSpeed(GLuint *pixels, my_coords limits);
//appel les différentes animations selon un tracé prédéfini, pour être synchro avec la musique
void draw(void);

float modulo (float val , float mod);





int main(int argc, char** argv) {
    srand(time(NULL));

    //create window
    if (!gl4duwCreateWindow(argc, argv, "Project", 10, 10, W, H, GL4DW_SHOWN))
        return 1;

    //window quadrillage (or how much pixels on the window) 
    gl4dpInitScreenWithDimensions(W/2, H/2);
    atexit(clean);


    //place pixels
    gl4duwDisplayFunc(draw);
    //determine where to place pixels
    // gl4duwIdleFunc(...);


    gl4duwMainLoop();
    return 0;
}











void draw(void) {
    SDL_Delay(150);


    gl4dpClearScreen();

    //get window size and pixels
    int w = gl4dpGetWidth(), h = gl4dpGetWidth();
    my_coords screen_size = {w, h};
    GLuint * pixels = gl4dpGetPixels();

    //draw

    drawSpeed(pixels, screen_size);





    gl4dpUpdateScreen(NULL);
}













void clean(void) {
  gl4duClean(GL4DU_ALL);
}





void swap(my_coords *a, my_coords *b) {
    my_coords temp = *a;
    *a = *b;
    *b = temp;
}




int out_of_limits(my_coords c, my_coords limits_p0, my_coords limits_p1) {
    if (c.x < limits_p0.x || c.x >= limits_p1.x)
        return 1; 
    if (c.y < limits_p0.y || c.y >= limits_p1.y)
        return 1;
    return 0;
}






void drawPoint(GLuint *pixels, my_coords point, my_coords limits, GLuint color) {    
    pixels[point.x + point.y*limits.x] = color;
}



void drawLine(GLuint *pixels, my_coords limits, my_coords p0, my_coords p1, GLuint color) {
    float y = 0.0f, pente;

    int u = p1.x - p0.x, v = p1.y - p0.y;
    pente = v / (float)u;

    double add = 1.0;


    //from left to right...
    if (p0.x < p1.x) {

        if (pente > add)
            add /= pente;
        else if (pente < -1*add)
            add /= -1*pente;

        for (double x = 0; x <= u; x+=add) {

            int a = p0.y + (int)(y + 0.5f);
            int b = (int)x + p0.x;
            if (out_of_limits((my_coords){a, b}, (my_coords){0, 0}, limits)) break;
            pixels[a * limits.x + b] = color;
            y += pente*add;
        }
    }
    //from right to left...
    else {
        
        if (pente > add)
            add /= pente;
        else if (pente < -1*add)
            add /= -1*pente;

        for (double x = 0; x > u; x-=add) {

            int a = p0.y + ((int)(y + 0.5f));
            int b = (int)x + p0.x;
            if (out_of_limits((my_coords){a, b}, (my_coords){0, 0}, limits)) break;
            pixels[(a) * limits.x + b] = color;
            y += pente*add;
        }

    }
}


void drawLine_fade(GLuint *pixels, my_coords limits, my_coords p0, my_coords p1) {
    float y = 0.0f, pente;

    int u = p1.x - p0.x, v = p1.y - p0.y;
    pente = v / (float)u;

    double add = 1.0;

    GLuint color = RGB(0, 0, 0);
    float c = 0;
    float minus = ((float)limits.x / 100) * 10;
    //from left to right...
    if (p0.x < p1.x) {

        if (pente > add)
            add /= pente;
        else if (pente < -1*add)
            add /= -1*pente;

        for (double x = 0; x <= u; x+=add) {
            color = RGB(0, 0, (int)c);
            if ( c < 255 -minus) c+=minus;

            int a = p0.y + (int)(y + 0.5f);
            int b = (int)x + p0.x;
            if (out_of_limits((my_coords){a, b}, (my_coords){0, 0}, limits)) break;
            pixels[a * limits.x + b] = color;
            y += pente*add;
        }
    }
    //from right to left...
    else {
        
        if (pente > add)
            add /= pente;
        else if (pente < -1*add)
            add /= -1*pente;

        for (double x = 0; x > u; x-=add) {
            color = RGB(0, (int)c, 0);
            if ( c < 255 -minus) c+=minus;

            int a = p0.y + ((int)(y + 0.5f));
            int b = (int)x + p0.x;
            if (out_of_limits((my_coords){a, b}, (my_coords){0, 0}, limits)) break;
            pixels[(a) * limits.x + b] = color;
            y += pente*add;
        }

    }
}





float modulo (float val , float mod) {
    while (val >= mod)  {val -= mod;}
    return val;
}

void drawSpeed(GLuint *pixels, my_coords limits) {
    //determine limits where speed comes from
    my_coords sub_limits_p0 = {0, limits.y/3};
    my_coords sub_limits_p1 = {limits.x, (limits.y/3)*2};

    static my_coords center = {0, 0};

    static int first_time = 1;
    if (first_time) {
        center = (my_coords) {rand()%(limits.x), sub_limits_p0.y + (rand()%(sub_limits_p1.y - sub_limits_p0.y))};
        first_time = 0;
    }
    do {
        center.x += (rand()%11)-5;
    }
    while (out_of_limits(center, sub_limits_p0, sub_limits_p1));
    do {
        center.y += (rand()%11)-5;
    }
    while (out_of_limits(center, sub_limits_p0, sub_limits_p1));

    //taille des lignes
    float rayon = sqrt(pow(limits.x, 2) + pow(limits.y, 2));
    //distance du centre avant de dessiner les lignes
    float dist_from_center = rayon/5;

    for (float angle = 0.0f; angle < 2.0f * M_PI; angle += ((float)(1+ (rand()%5)))/10) {
        //pour faire en sorte de "dessiner" un ovale autour du centre
        // if (modulo(angle, M_PI) < 0.5*M_PI) dist_from_center -= 3;
        // else dist_from_center += 3;

        center = (my_coords){limits.x/2, limits.y/2};
        // my_coords from = {center.x, center.y};
        my_coords from = {center.x + dist_from_center * cos(angle), center.y + dist_from_center * sin(angle)};
        my_coords to = {center.x + rayon * cos(angle), center.y + rayon * sin(angle)};
        drawLine_fade(pixels, limits, from, to);
        // drawLine(pixels, limits, from, to, RGB(255, 255, 255));

    }
    drawPoint(pixels, center, limits, RGB(255, 0, 0));
}





