

#ifndef ALED
#define ALED


class point2_t {
    float x;
    float y;

    public:
        point2_t(float px=0 ,float py=0);
        ~point2_t(void);
        void affichePoint();
        void rotate();
};



#endif // LISTE_H_INCLUDED


