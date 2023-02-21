

#ifndef CHAINE_H
#define CHAINE_H


class chaine_t {
    int size;
    char* tab;

    public:
        chaine_t (const char* str);
        ~chaine_t (void);
        void print_chaine (void);
};

#endif





