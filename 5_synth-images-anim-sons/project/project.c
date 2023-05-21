
#include <GL4D/gl4dp.h>
#include <GL4D/gl4duw_SDL2.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define W 500
#define H 500
#define W_DIVIDER 2
#define H_DIVIDER 2

#define BPM 81
#define TEMPO 4
#define MUSIC_DURATION (58*TEMPO)
#define BEAT_MS_DURATION (((60000 / BPM) *TEMPO) / 4)
#define TICKS_BY_BEAT (3*TEMPO)

#define SOUND 1//1:ON, 0:OFF

static int _tempo = 1; //current moment of the tempo
static int _tick = -8*TICKS_BY_BEAT; //current ticks of the beat

static Mix_Music *_music = NULL;

// static GLuint * pixels1 = NULL;


typedef struct coords_t {
    int x;
    int y;
} my_coords;

static int _xmouse = 1, _ymouse = 1;



//appel la méthode gl4duClean()
void clean(void);
int min(int a, int b);
int max(int a, int b);
//échange deux points
void swap(my_coords *a, my_coords *b);
//retourne 1 si "c" est hors du rectangle "limits"
int out_of_limits(my_coords c, my_coords limits_p0, my_coords limits_p1);
//place un point à une position aléatoire
void drawRandomPoint(GLuint *pixels, my_coords limits);
//place un point coloré
void drawPoint(GLuint *pixels, my_coords point, my_coords limits, GLuint color);
//place un point. La position change à chaque beat, et la couleur tous les 5 ticks
void drawPoint_by_beat(GLuint *pixels, my_coords limits);
//place un rectangle. La position et la color change tous les 4 beats
void drawRect_by_4_beat(GLuint *pixels, my_coords limits);
// place des pixels colorés de p0 à p1
void drawLine(GLuint *pixels, my_coords limits, my_coords p0, my_coords p1, GLuint color);
//place des pixels colorés de p0 à p1 (si la ligne pas strictement verticale ou horizontal, la fonction ne fait rien)
void drawStraightLine(GLuint *pixels, my_coords limits, my_coords p0, my_coords p1, GLuint color);

void draw_MusicProgressBar(GLuint *pixels, my_coords limits, int actual_tempo);
//animation d'un rectangle dans une position et couleur aléatoire (chaque appel effectue rend un affichage différent en fonction selon l'étape de l'anim)
void drawRect_explosion(GLuint *pixels, my_coords limits);
//place des lignes dans tous les sens en partant d'un point définit (donne une illusion de vitesse)
void drawSpeed(GLuint *pixels, my_coords limits);
//appel les différentes animations selon un tracé prédéfini, pour être synchro avec la musique
void draw(void);

//adjust rect coords to fits inside "limits"
void adjust(my_coords *p0, my_coords *p1, my_coords limits);
//modulo for float
float modulo(float val , float mod);

//met à jour "_xmouse" et "_ymouse", les coords du curseur sur la fenêtre
void pmotion(int x, int y);






int main(int argc, char** argv) {
    srand(time(NULL));

    //create window
    if (!gl4duwCreateWindow(argc, argv, "Project", 10, 10, W, H, GL4DW_SHOWN))
        return 1;

    //window quadrillage (or how much pixels on the window) 
    gl4dpInitScreenWithDimensions(W/2, H/2);
    atexit(clean);

    //mixer
    if (SOUND) {
        Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2024);
        _music = Mix_LoadMUS("Pastless_remake.mp3");
        Mix_PlayMusic(_music, 1);
    }

    // //ttf
    // TTF_Init();
    // TTF_Font *font = TTF_OpenFont("Monocraft.otf", 32);


    // int w = gl4dpGetWidth(), h = gl4dpGetHeight();
    // pixels1 = malloc(w*h * sizeof(GLuint));

    //place pixels
    gl4duwDisplayFunc(draw);
    //determine where to place pixels
    // gl4duwIdleFunc();

    gl4duwPassiveMotionFunc(pmotion);

    gl4duwMainLoop();
    return 0;
}







void draw(void) {
    SDL_Delay(BEAT_MS_DURATION / TICKS_BY_BEAT);
    // SDL_Delay(250);

    //
    static int actual_tempo = 0;

    //next tick/temp
    if (_tick == 0) actual_tempo = 1;
    _tick++;
    if (_tick == TICKS_BY_BEAT+1) {
        _tick = 1;
        _tempo ++;
        actual_tempo++;
    }
    if (_tempo == TEMPO+1)
        _tempo = 1;


    static int phase = 0;
    if (_tick == 1)
        phase++;
    if (phase == 5)
        phase = 1;


    gl4dpClearScreen();

    //get window size and pixels
    int w = gl4dpGetWidth(), h = gl4dpGetWidth();
    my_coords screen_size = {w, h};
    GLuint * pixels = gl4dpGetPixels();

    //draw
    int anim = 0;
    printf("actual_tempo=%d\n", actual_tempo);
    if (_tick < 1 || actual_tempo < 1 || actual_tempo > MUSIC_DURATION)
        anim = 0;
    else anim = 1;



    draw_MusicProgressBar(pixels, screen_size, actual_tempo);
    if (anim) {
        if (phase % 2 == 1)
            drawRect_explosion(pixels, screen_size);

        drawSpeed(pixels, screen_size);


        drawRect_by_4_beat(pixels, screen_size);
        // drawPoint_by_beat(pixels, screen_size);
    }
    else
        drawSpeed(pixels, screen_size);





    gl4dpUpdateScreen(NULL);
}













void clean(void) {
    gl4duClean(GL4DU_ALL);
    Mix_FreeMusic(_music);
}



void pmotion(int x, int y) {
    _xmouse = x / W_DIVIDER; 
    _ymouse = (H - y) / H_DIVIDER;
}






int min(int a, int b) { if (a<b) return a; return b; }
int max(int a, int b) { if (a>b) return a; return b; }

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



void drawRandomPoint(GLuint *pixels, my_coords limits) {
    my_coords point = {rand()%limits.x, rand()%limits.y};
    pixels[point.x + point.y*limits.x] = RGB(255, 0, 0);
}



void drawPoint(GLuint *pixels, my_coords point, my_coords limits, GLuint color) {    
    pixels[point.x + point.y*limits.x] = color;
}


void drawPoint_by_beat(GLuint *pixels, my_coords limits) {

    static my_coords point = {0, 0};
    static GLuint color = RGB(0, 0, 0);

    if (_tick == 1)
        point = (my_coords){rand() % limits.x, rand() % limits.y};

    if (_tick%5 == 1)
        color = RGB(rand()%255, rand()%255, rand()%255);
    
    pixels[point.x + point.y*limits.x] = color;
}

void drawRect_by_4_beat(GLuint *pixels, my_coords limits) {
    static GLuint color = RGB(0, 0, 0);
    static my_coords p0 = {0, 0};
    static my_coords p1 = {0, 0};


    if (_tempo == 1 && _tick == 1) {
        color = RGB(rand()%255, rand()%255, rand()%255);

        p0 = (my_coords){rand()% (limits.x/2), rand()% (limits.y/2)};
        p1 = (my_coords){p0.x+1 + rand()% ((limits.x/2)-1), p0.y+1 + rand()% ((limits.y/2)-1)};
    }

    for (int i = p0.x; i < p1.x; i++) {
        for (int j = p0.y; j < p1.y; j++)
            pixels[i + j*limits.x] = color;
    }
}



void drawStraightLine(GLuint *pixels, my_coords limits, my_coords p0, my_coords p1, GLuint color) {
    if (!((p0.x == p1.x) || (p0.y == p1.y))) {
        printf("error in drawStraightLine: the line must be straight.\n");
        return;
    }

    if (p0.x > p1.x || p0.y > p1.y) {
        swap(&p0, &p1);
    }

    for (int i = p0.x; i <= p1.x; i++) {
        for (int j = p0.y; j <= p1.y; j++) {
            if (out_of_limits((my_coords){i, j}, (my_coords){0, 0}, limits))
                continue;
            pixels[i + j*limits.x] = color;
        }
    }
    // exit(0);
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


void intensify_color(int add, int *r0, int *g0, int *b0, int r1, int g1, int b1) {
    if ( *r0 < r1 -add) *r0+=add;
    if ( *g0 < g1 -add) *g0+=add;
    if ( *b0 < b1 -add) *b0+=add;
}

void drawLine_fade(GLuint *pixels, my_coords limits, my_coords p0, my_coords p1, int r, int g, int b) {
    float y = 0.0f, pente;

    int u = p1.x - p0.x, v = p1.y - p0.y;
    pente = v / (float)u;

    double add = 1.0;
    int r1 = 0, g1 = 0, b1 = 0;


    GLuint color = RGB(0, 0, 0);
    float c = 0;
    float color_add = ((float)limits.x / 100)* (2+(rand()%20));
    //from left to right...
    if (p0.x < p1.x) {

        if (pente > add)
            add /= pente;
        else if (pente < -1*add)
            add /= -1*pente;

        for (double x = 0; x <= u; x+=add) {
            color = RGB(r1, g1, b1);
            intensify_color(color_add, &r1, &g1, &b1, r, g, b);
            // if ( c < 255 -color_add) c+=color_add;

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
            color = RGB(r1, g1, b1);
            intensify_color(color_add, &r1, &g1, &b1, r, g, b);
            if ( c < 255 -color_add) c+=color_add;

            int a = p0.y + ((int)(y + 0.5f));
            int b = (int)x + p0.x;
            if (out_of_limits((my_coords){a, b}, (my_coords){0, 0}, limits)) break;
            pixels[(a) * limits.x + b] = color;
            y -= pente*add;
        }

    }
}





void drawRect_explosion(GLuint *pixels, my_coords limits) {
    static GLuint color = RGB(0, 0, 0);
    static int step = 0;
    static my_coords center = {50, 50};
    my_coords size = {50, 50};


    if (_tick %(TICKS_BY_BEAT/4) == 1)
        step++;
    printf("step=%d, _tick=%d\n", step, _tick);
    if (step >= 5 && _tick == 1) {
        center = (my_coords){rand()%limits.x, rand()%limits.x};
        color = RGB(rand()%255, rand()%255, rand()%255);
        step = 1;
    }


    //rect coordinates
    static my_coords p0 = {0, 0};
    // static my_coords p1 = {0, 0};
    p0 = (my_coords) {center.x - size.x/2, center.y - size.y/2};
    // p1 = (my_coords) {center.x + size.x/2, center.y + size.y/2};



    for (int i = p0.x, j = p0.y, minus = 0; i <= center.x && j <= center.y; i++, j++, minus+=2) {
        int skip = 1;
        switch (step) {
            case 1:
                if (i < p0.x+20) skip = 0;
                break;
            case 2:
                if (i < p0.x+15) skip = 0;
                break;
            case 3:
                if (i < p0.x+10) skip = 0;
                break;
            case 4:
                if (i < p0.x+5) skip = 0;
                break;
            
            default:
                printf("error in drawRect_explosion: \"step\" have an unwanted value (%d)\n", step);
                break;
        }
        if (skip) continue;

        //starting from up left (to right and down)
        int x = i;
        int y = j;
        // drawPoint(pixels, (my_coords){x, y}, limits, color);
        // drawLine(pixels, limits, (my_coords){x, y}, (my_coords){x, y+size.y-minus}, color);
        // drawLine(pixels, limits, (my_coords){x, y}, (my_coords){x+size.x-minus, y}, color);
        drawStraightLine(pixels, limits, (my_coords){x, y}, (my_coords){x, y+size.y-minus}, color);
        drawStraightLine(pixels, limits, (my_coords){x, y}, (my_coords){x+size.x-minus, y}, color);
        // starting from down right (to left and up)
        x += size.x - minus;
        y += size.y - minus; 
        // drawPoint(pixels, (my_coords){x, y}, limits, color);
        // drawLine(pixels, limits, (my_coords){x, y}, (my_coords){x, y-size.y+minus}, color);
        // drawLine(pixels, limits, (my_coords){x, y}, (my_coords){x-size.x+minus, y}, color);
        drawStraightLine(pixels, limits, (my_coords){x, y}, (my_coords){x, y-size.y+minus}, color);
        drawStraightLine(pixels, limits, (my_coords){x, y}, (my_coords){x-size.x+minus, y}, color);
    }

    // for (int i = center.x, j = center.y, minus = 0; i <= p0.x && j <= p0.y; i--, j--, minus+=2) {
    //     int skip = 1;
    //     switch (step) {
    //         case 1:
    //             if (i < 20) skip = 0;
    //             break;
    //         case 2:
    //             if (i < 15) skip = 0;
    //             break;
    //         case 3:
    //             if (i < 10) skip = 0;
    //             break;
    //         case 4:
    //             if (i < 5) skip = 0;
    //             break;
            
    //         default:
    //             printf("error in drawRect_explosion: \"step\" have an unwanted value (%d)\n", step);
    //             break;
    //     }
    //     if (skip) continue;

    //     //starting from up left (to right and down)
    //     int x = i;
    //     int y = j;
    //     // drawPoint(pixels, (my_coords){x, y}, limits, color);
    //     drawStraightLine(pixels, limits, (my_coords){x, y}, (my_coords){x, y+size.y-minus}, color);
    //     drawStraightLine(pixels, limits, (my_coords){x, y}, (my_coords){x+size.x-minus, y}, color);
    //     // starting from down right (to left and up)
    //     x += size.x + minus;
    //     y += size.y + minus; 
    //     // drawPoint(pixels, (my_coords){x, y}, limits, color);
    //     drawStraightLine(pixels, limits, (my_coords){x, y}, (my_coords){x, y-size.y+minus}, color);
    //     drawStraightLine(pixels, limits, (my_coords){x, y}, (my_coords){x-size.x+minus, y}, color);
    // }


}


float modulo(float val , float mod) {
    while (val >= mod)  {val -= mod;}
    return val;
}


void adjust(my_coords *p0, my_coords *p1, my_coords limits) {
    //add stop conditions
    //rect greater then limits

    //x
    if (p0->x < 0) {
        int add = 0;
        while (p0->x < 0) {
            p0->x++; add++;
        }
        p1->x += add;
    }
    else if (p1->x >= limits.x) {
        p0->x -= p1->x - limits.x + 1;
        p1->x -= p1->x - limits.x + 1;
    }

    //y
    if (p0->y < 0) {
        int add = 0;
        while (p0->y < 0) {
            p0->y++; add++;
        }
        p1->y += add;
    }
    else if (p1->y >= limits.y) {
        p0->y -= p1->y - limits.y + 1;
        p1->y -= p1->y - limits.y + 1;
    }
}




void drawSpeed(GLuint *pixels, my_coords limits) {
    //statics
    static my_coords center = {0, 0}; //where the speed comes from
    static int r = 255/2, g = 255/2, b = 255/2; //color for all lines

    //rectangle autours du curseur
    my_coords sub_limits_p0 = (my_coords){_xmouse - (limits.x/40), _ymouse - (limits.y/40)};
    my_coords sub_limits_p1 = (my_coords){_xmouse + (limits.x/40), _ymouse + (limits.y/40)};
    adjust(&sub_limits_p0, &sub_limits_p1, limits);

    //up "center" to be inside sub_limits rect 
    do {
        center.x = sub_limits_p0.x + (rand()%(sub_limits_p1.x - sub_limits_p0.x));
        center.y = sub_limits_p0.y + (rand()%(sub_limits_p1.y - sub_limits_p0.y));
    }
    while (out_of_limits(center, sub_limits_p0, sub_limits_p1));
    // center = sub_limits_p1;

    //randomly change lines color
    int color_add = 50;
    int temp = r;
    do {
        r = temp + ((color_add/2) - rand()%color_add);
    } while (r < 100 || r > 255);
    temp = g;
    do {
        g = temp + ((color_add/2) - rand()%color_add);
    } while (g < 100 || g > 255);
    temp = b;
    do {
        b = temp + ((color_add/2) - rand()%color_add);
    } while (b < 100 || b > 255);


    //taille des lignes (= diagonal of window size)
    float rayon = sqrt(pow(limits.x, 2) + pow(limits.y, 2));
    //distance du centre avant de dessiner les lignes
    float dist_from_center = rayon/5;

    for (float angle = 0.0f; angle < 2.0f * M_PI; angle += ((float)(1+ (rand()%5)))/10) {
        //pour faire en sorte de "dessiner" un ovale autour du centre
        if (modulo(angle, M_PI) < 0.5*M_PI) dist_from_center -= 3;
        else dist_from_center += 3;

        //calcul des coordonnées de la ligne
        my_coords from = {center.x + dist_from_center * cos(angle), center.y + dist_from_center * sin(angle)};
        my_coords to = {center.x + rayon * cos(angle), center.y + rayon * sin(angle)};

        drawLine_fade(pixels, limits, from, to, r, g, b);
    }
    //center indication
    // drawPoint(pixels, center, limits, RGB(r, g, b));
}




void draw_MusicProgressBar(GLuint *pixels, my_coords limits, int actual_tempo) {
    if (actual_tempo == 0) actual_tempo = 1;
    // int musicPercent = (int)((float)100/MUSIC_DURATION) * actual_tempo;
    int musicPercent = (actual_tempo) * ((float)100/(MUSIC_DURATION)) ;
    printf("dur=%d\n", MUSIC_DURATION);

    printf("musicPercent=%d\n", musicPercent);
    int end = ((float)limits.x/100) * musicPercent;
    printf("end=%d\n", end);

    for (int y = 0; y < ((float)limits.y/100); y++)
        drawLine(pixels, limits, (my_coords){0, y}, (my_coords){end, y}, RGB(255, 171, 0));

}




