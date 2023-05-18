
#include <GL4D/gl4dp.h>
#include <GL4D/gl4duw_SDL2.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DELAY 50

#define W 300
#define H 300

#define NB_ELEMENTS 150

// static GLuint * pixels = NULL;
static int elements[50];
static int to_swap[2]; //index of an element in elements






void drawLine(GLuint * pixels, int index, int height, int w, GLuint color) {
    for (int y = 0; y < height; y++)
        pixels[index + y*w] = color;
}



void draw(void) {
    gl4dpClearScreen();

    int w = gl4dpGetWidth();
    GLuint * pixels = gl4dpGetPixels();

    for (int i = 0; i < NB_ELEMENTS; i++)
        drawLine(pixels, i, elements[i], w, RGB(255, 255, 255));
    drawLine(pixels, to_swap[0], elements[to_swap[0]], w, RGB(255, 171, 0));
    drawLine(pixels, to_swap[1], elements[to_swap[1]], w, RGB(255, 171, 0));

    gl4dpUpdateScreen(NULL);
}




void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort(void) {
    static int index = 0;

    to_swap[0] = index;
    to_swap[1] = index;
    for (int i = index+1; i < NB_ELEMENTS; i++) {
        if (elements[i] < elements[to_swap[1]])
            to_swap[1] = i;
    }



    // SDL_Delay(100);


    swap(&elements[index], &elements[to_swap[1]]);

    index++;
    SDL_Delay(DELAY);
}





void init_elements() {
    for (int i = 0; i < NB_ELEMENTS; i++)
        elements[i] = 1 + (rand()% (NB_ELEMENTS -1));
}


void clean(void) {
  gl4duClean(GL4DU_ALL);
}

// void change_xy(int *x, int *y) {
//     int w = gl4dpGetWidth(), h = gl4dpGetHeight();
//     *x = rand() % w;
//     *y = rand() % h;
// }

int main(int argc, char** argv) {
    srand(time(0));
    init_elements();

    //create window
    if (!gl4duwCreateWindow(argc, argv, "visualSort", 10, 10, W, H, GL4DW_SHOWN))
        return 1;

    //window quadrillage (or how much pixels on the window)
    gl4dpInitScreenWithDimensions(NB_ELEMENTS, NB_ELEMENTS);
    atexit(clean);

    // pixels = gl4dpGetPixels();
    //place pixels
    gl4duwDisplayFunc(draw);
    //determine where to place pixels
    gl4duwIdleFunc(sort);


    gl4duwMainLoop();
    return 0;
}



