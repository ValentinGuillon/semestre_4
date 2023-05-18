
#include <GL4D/gl4dp.h>
#include <GL4D/gl4duw_SDL2.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define W 300
#define H 300

#define BPM 80
#define TEMPO 4
#define BEAT_MS_DURATION ((60000 / BPM) *TEMPO) / 4
#define TICKS_BY_BEAT 10

static int tempo = 0; //current moment of the tempo
static int tick = 0; //current ticks of the beat

// static GLuint * pixels = NULL;


void clean(void) {
  gl4duClean(GL4DU_ALL);
}

void drawPoint(GLuint *pixels, int w, int h) {

    int x = rand() % w;
    int y = rand() % h;
    
    int px = x;
    int py = (y*w);
    pixels[px + py] = RGB(255, 0, 0);
}

void drawPoint_by_beat(GLuint *pixels, int w, int h) {

    static int x = 0;
    static int y = 0;
    static GLuint color = RGB(0, 0, 0);

    if (tick == 1) {
        x = rand() % w;
        y = rand() % h;
    }

    if (tick%5 == 1)
        color = RGB(rand()%255, rand()%255, rand()%255);
    
    pixels[x + y*w] = color;
}

void drawRect_by_4_beat(GLuint *pixels, int w, int h) {
    static GLuint color = RGB(0, 0, 0);

    //rect coordinates
    static int x0 = 0;
    static int y0 = 0;
    static int x1 = 0;
    static int y1 = 0;


    if (tempo == 1 && tick == 1) {
        color = RGB(rand()%255, rand()%255, rand()%255);

        x0 = rand()% (w/2);
        y0 = rand()% (h/2);
        x1 = x0+1 + rand()% ((w/2)-1);
        y1 = y0+1 + rand()% ((h/2)-1);
    }
    printf("x0=%d, y0=%d, x1=%d, y1=%d\n", x0, y0, x1, y1);

    for (int i = x0; i < x1; i++) {
        for (int j = y0; j < y1; j++)
            pixels[i + j*w] = color;
    }
}


void draw(void) {
    SDL_Delay(BEAT_MS_DURATION / TICKS_BY_BEAT);
    printf("BEAT DURATION = %d\n", BEAT_MS_DURATION);

    //next tick/temp
    tick++;
    if (tick == TICKS_BY_BEAT+1) {
        tick = 1;
        tempo ++;
    }
    if (tempo == TEMPO+1)
        tempo = 1;

    gl4dpClearScreen();

    //get window size and pixels
    int w = gl4dpGetWidth(), h = gl4dpGetHeight();
    GLuint * pixels = gl4dpGetPixels();

    //draw

    drawRect_by_4_beat(pixels, w, h);
    drawPoint_by_beat(pixels, w, h);
    // drawPoint(pixels, w, h);

    gl4dpUpdateScreen(NULL);
}




// void change_xy(void) {
//     // printf("x=%d, y=%d\n", x, y);
//     int w = gl4dpGetWidth(), h = gl4dpGetHeight();
//     x = rand() % w;
//     y = rand() % h;
//     SDL_Delay(100);
// }


void change_xy(int *x, int *y) {
    int w = gl4dpGetWidth(), h = gl4dpGetHeight();
    *x = rand() % w;
    *y = rand() % h;
}

int main(int argc, char** argv) {
    srand(time(NULL));

    //create window
    if (!gl4duwCreateWindow(argc, argv, "test", 10, 10, W, H, GL4DW_SHOWN))
        return 1;

    //window quadrillage (or how much pixels on the window) 
    gl4dpInitScreenWithDimensions(W/10, H/10);
    atexit(clean);

    // pixels = gl4dpGetPixels();
    //place pixels
    gl4duwDisplayFunc(draw);
    //determine where to place pixels
    // gl4duwIdleFunc(change_xy);


    gl4duwMainLoop();
    return 0;
}
