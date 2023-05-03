
#include<error_messages.hpp>
#include<iostream>

using namespace error_messages;



int HIDE_PRINTS;


void my_scanf(int &input) {
    // while(1) {
    //     try {
    //         printf(">");
    //         scanf("%d", &input);
    //     }
    //     catch (...) {
    //         printf("<give a number> ");
    //         continue;
    //     }
    //     break;
    // }

    char *p, s[100];

    printf(">");
    while (fgets(s, sizeof(s), stdin)) {
        input = strtol(s, &p, 10);
        if (p == s || *p != '\n') {
            printf("<give a number> >");
        } else break;
    }
}


namespace error_messages {
    void print_error(my_error error) {
        std::cout << "error: in " << error.thrower << ":\n";

        if (error.type == ENTITY_NOT_A_CREATURE)
            std::cout << "The given entity is not a CREATURE\n";
        else if (error.type == NOT_DEFINED_CREATURE)
            std::cout << "The given entity is not define\n";
        else if (error.type == WRONG_GIVEN_ENTITY)
            std::cout << "The given entity is not supposed to be given here\n";
        else if (error.type == TOO_MUCH_CREATURES)
            std::cout << "Too much creatures\n";
        else if (error.type == OUT_OF_RANGE)
            std::cout << "Out of range\n";
        else
            std::cout << "(unknown error)\n";
    }

}


