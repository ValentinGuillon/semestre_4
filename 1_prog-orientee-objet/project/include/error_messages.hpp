
#ifndef ERROR_MESSAGES_H
#define ERROR_MESSAGES_H

// #include<iostream>
#include<string>

#define ENTITY_NOT_A_CREATURE 20
#define NOT_DEFINED_CREATURE 21
#define WRONG_GIVEN_ENTITY 22
#define TOO_MUCH_CREATURES 23
#define OUT_OF_RANGE 24


extern int HIDE_PRINTS;




void my_scanf(int &input);


namespace error_messages {
    typedef struct error_t {
        int type;
        std::string thrower;
    } my_error;

    // void test(int a);
    void print_error(my_error error);
}



#endif

