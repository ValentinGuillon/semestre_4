
#include<stdlib.h>
#include<stdio.h>
#include<world.hpp>
#include<classes.hpp>
#include<error_messages.hpp>
#include<vector>
using namespace error_messages;



void print_line(int size_y_world) {
    for (int i = 0; i < size_y_world; i++)
        cout << " --- ";
    cout << endl;
}



namespace world {

    // void create(CASE** world, my_tuple size, int nb_creatures) {
    void create(WORLD &world, my_tuple size, int nb_creatures) {
        if (nb_creatures > size.x*size.y) throw (my_error){TOO_MUCH_ENTITY, "world.cpp: create_world"};


        //creéation des CASEs
        for (int i = 0; i < size.x; i++) {
            vector<CASE> line;
            for (int j = 0; j < size.y; j++)
                line.push_back(CASE{{i, j}});
            world.push_back(line);
        }


        //ajout de l'herbe
        for (int i = 0; i < size.x; i++) {
            for (int j = 0; j < size.y; j++) {
                world[i][j].add_entity(HERB);
            }
        }


        // create loup/mouton (which proportion ? -> loup=1/3, mouton=2/3)
        int nb_loups = nb_creatures / 3;
        int nb_moutons = nb_creatures - nb_loups;


        int pos_x, pos_y;
        for (int i = 0; i < nb_loups; i++) {
            while(1) {
                pos_x = std::rand() % size.x;
                pos_y = std::rand() % size.y;
                if (! world[pos_x][pos_y].is_free_for(LOUP)) continue;
                world[pos_x][pos_y].add_entity(LOUP);
                break;
            }
        }

        for (int i = 0; i < nb_moutons; i++) {
            while(1) {
                pos_x = std::rand() % size.x;
                pos_y = std::rand() % size.y;
                if (! world[pos_x][pos_y].is_free_for(LOUP)) continue;
                if (! world[pos_x][pos_y].is_free_for(MOUTON)) continue;
            
                world[pos_x][pos_y].add_entity(MOUTON);
                break;
            }
        }
    }



    void process_day(WORLD &world, my_tuple size, int show_steps) {
        int input;
        CASE* actual_case = NULL;
        CREATURE* creature = NULL;


        //reset has_moved
        for (int i = 0; i < size.x; i++) {
            for (int j = 0; j < size.y; j++) {
                actual_case = &world[i][j];
                creature = actual_case->get_loup();
                if (creature)
                    creature->reset_has_moved();
                creature = actual_case->get_mouton();
                if (creature)
                    creature->reset_has_moved();
            }
        }

        //reset has_reproduct
        for (int i = 0; i < size.x; i++) {
            for (int j = 0; j < size.y; j++) {
                actual_case = &world[i][j];
                creature = actual_case->get_loup();
                if (creature)
                    creature->reset_has_reproduct();
                creature = actual_case->get_mouton();
                if (creature)
                    creature->reset_has_reproduct();
            }
        }

        //herbs grows
        for (int i = 0; i < size.x; i++) {
            for (int j = 0; j < size.y; j++) {
                actual_case = &world[i][j];
                if (actual_case->is_free_for(MINERAL)) continue;
                if (!actual_case->is_free_for(HERB)) {
                    actual_case->remove_entity(MINERAL);
                    continue;
                }
                actual_case->add_entity(HERB);
            }
        }

        if (show_steps) {
            display(world, size);
            cout << "<herbs has grown> (next: <natural deaths>)\n";
            cout << "(any number + <ENTER> to proceed)\n";
            my_scanf(input);
        }

        //death of old/hungry creatures
        for (int i = 0; i < size.x; i++) {
            for (int j = 0; j < size.y; j++) {
                actual_case = &world[i][j];
                //loup
                creature = actual_case->get_loup();
                if (creature) 
                    creature->die(world);
                //mouton
                creature = actual_case->get_mouton();
                if (creature)
                    creature->die(world);
            }
        }

        if (show_steps) {
            display(world, size);
            cout << "<natural deaths> (next: <creatures will move>)\n";
            cout << "(any number + <ENTER> to proceed)\n";
            my_scanf(input);
        }




        //creatures moves
        for (int i = 0; i < size.x; i++) {
            for (int j = 0; j < size.y; j++) {
                actual_case = &world[i][j];

                actual_case->move_creatures(world, size);
            }
        }

        if (show_steps) {
            display(world, size);
            cout << "<creatures has moved> (next: <creatures will give birth>)\n";
            cout << "(any number + <ENTER> to proceed)\n";
            my_scanf(input);
        }

        //creature gives birth
        for (int i = 0; i < size.x; i++) {
            for (int j = 0; j < size.y; j++) {
                actual_case = &world[i][j];
                //loup
                creature = actual_case->get_loup();
                if (creature) 
                    creature->give_birth(world, size);
                //mouton
                creature = actual_case->get_mouton();
                if (creature)
                    creature->give_birth(world, size);
            }
        }

        if (show_steps) {
            display(world, size);
            cout << "<creatures gave birth> (next: <creatures will eat>)\n";
            cout << "(any number + <ENTER> to proceed)\n";
            my_scanf(input);
        }


        //creatures eats
        for (int i = 0; i < size.x; i++) {
            for (int j = 0; j < size.y; j++) {
                actual_case = &world[i][j];
                //loup
                creature = actual_case->get_loup();
                if (creature) 
                    creature->eat(world);
                //mouton
                creature = actual_case->get_mouton();
                if (creature)
                    creature->eat(world);
            }
        }

        if (show_steps) {
            display(world, size);
            cout << "<creatures ate> (next: <creatures will reproduct>)\n";
            cout << "(any number + <ENTER> to proceed)\n";
            my_scanf(input);
        }


        //creatures reproducts
        for (int i = 0; i < size.x; i++) {
            for (int j = 0; j < size.y; j++) {
                actual_case = &world[i][j];
                //loup
                creature = actual_case->get_loup();
                if (creature) 
                    creature->reproduction(world, size);
                //mouton
                creature = actual_case->get_mouton();
                if (creature)
                    creature->reproduction(world, size);
            }
        }

        if (show_steps) {
            display(world, size);
            cout << "<creatures has reproducted> (next: <DAY WILL END>)\n";
            cout << "(any number + <ENTER> to proceed)\n";
            my_scanf(input);
        }
    
        //creatures has survived the day
        for (int i = 0; i < size.x; i++) {
            for (int j = 0; j < size.y; j++) {
                actual_case = &world[i][j];
                creature = actual_case->get_loup();
                if (creature)
                    creature->has_survived();
                creature = actual_case->get_mouton();
                if (creature)
                    creature->has_survived();
            }
        }
    }




    int is_dead(WORLD &world, my_tuple size) {
        for (int i = 0; i < size.x; i++) {
            for (int j = 0; j < size.y; j++) {
                if (!world[i][j].is_free_for(LOUP) || !world[i][j].is_free_for(MOUTON))
                    return 0;
            }
        }
        return 1;
    }


    // void destroy(WORLD &world, my_tuple size) {
    //     cout<<"enter destroy()\n";
    //     for (int i = 0; i < size.x; i++) {
    //         for (int j = 0; j < size.y; j++) {
    //             world[i][j].free_all_creatures();
    //             free(&world[i][j]);
    //         }
    //         // free(world[i]);
    //     }
    //     cout<<"exit destroy()\n";
    // }





    void display(WORLD &world, my_tuple size) {
        for (int i = 0; i < size.x; i++) {
            print_line(size.y);
            for (int j = 0; j < size.y; j++) {
                cout << "|";
                world[i][j].display();
                cout << "|";
            }
            cout << endl;
        }
        print_line(size.y);
    }
}



