
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
}



namespace world {


    void presentation(void) {
        cout<< "============================================\n";
        cout<< "                 ECOSYSTEM\n";
        cout<< "============================================\n";
        cout<< "               A simulation\n";
        cout<< "   where different kind of entity coexists\n";
        cout<< "         in a grass based 2D world\n";
        cout<< "============================================\n";
        cout<< "  ENTITY are all kinds of object that can\n";
        cout<< " interact/be interacted with other entities\n";
        cout<< "  CREATURE are entities that can perform\n";
        cout<< "      actions, like moving or eating\n";
        cout<< "============================================\n";
        cout<< "       The creatures (wolf and sheep)\n";
        cout<< "       has different type of actions:\n";
        cout<< " - MOVE, go to an adjacent empty case\n";
        cout<< "   (\"empty\" means without same\n";
        cout<< "   race-creature, and without threat)\n";
        cout<< " - EAT, eat the food-entity on the same case\n";
        cout<< "   and reset the hunger\n";
        cout<< " - REPRODUCT, if there is a same\n";
        cout<< "   race-creature of the opposite gender\n";
        cout<< "   nearby, switch to \"reproducting\" state.\n";
        cout<< "   Cannot move the next day on that state\n";
        cout<< " - GIVE BIRTH, if in \"reproducting\" state,\n";
        cout<< "   generate a same race-creature on\n";
        cout<< "   adjacent empty case\n";
        cout<< " - DIE, delete the creature from the world.\n";
        cout<< "   If the death if caused by\n";
        cout<< "   \"oldness\" or \"hunger\",\n";
        cout<< "   a mineral was dropped on the case\n";
        cout<< "============================================\n";
        cout<< " At the start of the day, minerals generate\n";
        cout<< "     grass on the case, and disapear\n";
        cout<< "============================================\n";
    }


    // void create(CASE** world, my_tuple size, int nb_creatures) {
    void create(WORLD &world, my_tuple size, int nb_wolfs, int nb_sheeps) {
        if (nb_wolfs+nb_sheeps > size.x*size.y) throw (my_error){TOO_MUCH_CREATURES, "world.cpp: create_world"};

        CASE* temp;
        //creation of CASEs
        for (int i = 0; i < size.x; i++) {
            vector<CASE*> line;

            for (int j = 0; j < size.y; j++) {
                temp = new CASE{{i, j}};
                line.push_back(temp);
            }
            world.push_back(line);
        }
        temp = NULL;


        //adding grass
        for (int i = 0; i < size.x; i++) {
            for (int j = 0; j < size.y; j++)
                world[i][j]->add_entity(GRASS);
        }


        // create wolf/sheep
        int has_wolf_female = 0, has_wolf_male = 0, has_sheep_female = 0, has_sheep_male = 0;

        int pos_x, pos_y;
        for (int i = 0; i < nb_wolfs; i++) {
            while(1) {
                pos_x = std::rand() % size.x;
                pos_y = std::rand() % size.y;
                if (! world[pos_x][pos_y]->is_free_for(WOLF)) continue;
                if (!has_wolf_male) {
                    has_wolf_male = 1;
                    world[pos_x][pos_y]->add_entity(WOLF, MALE);
                    break;
                }
                if (!has_wolf_female) {
                    has_wolf_female = 1;
                    world[pos_x][pos_y]->add_entity(WOLF, FEMALE);
                    break;
                }
                world[pos_x][pos_y]->add_entity(WOLF);
                break;
            }
        }

        for (int i = 0; i < nb_sheeps; i++) {
            while(1) {
                pos_x = std::rand() % size.x;
                pos_y = std::rand() % size.y;
                if (! world[pos_x][pos_y]->is_free_for(WOLF)) continue;
                if (! world[pos_x][pos_y]->is_free_for(SHEEP)) continue;
                if (!has_sheep_male) {
                    has_sheep_male = 1;
                    world[pos_x][pos_y]->add_entity(SHEEP, MALE);
                    break;
                }
                if (!has_sheep_female) {
                    has_sheep_female = 1;
                    world[pos_x][pos_y]->add_entity(SHEEP, FEMALE);
                    break;
                }
            
                world[pos_x][pos_y]->add_entity(SHEEP);
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
                actual_case = world[i][j];
                creature = actual_case->get_wolf();
                if (creature)
                    creature->reset_has_moved();
                creature = actual_case->get_sheep();
                if (creature)
                    creature->reset_has_moved();
            }
        }

        //reset has_reproduct
        for (int i = 0; i < size.x; i++) {
            for (int j = 0; j < size.y; j++) {
                actual_case = world[i][j];
                creature = actual_case->get_wolf();
                if (creature)
                    creature->reset_has_reproduct();
                creature = actual_case->get_sheep();
                if (creature)
                    creature->reset_has_reproduct();
            }
        }

        //grass grows
        for (int i = 0; i < size.x; i++) {
            for (int j = 0; j < size.y; j++) {
                actual_case = world[i][j];
                if (actual_case->is_free_for(MINERAL)) continue;
                if (!actual_case->is_free_for(GRASS)) {
                    actual_case->remove_entity(MINERAL);
                    continue;
                }
                actual_case->add_entity(GRASS);
            }
        }

        if (show_steps) {
            display(world, size);
            cout << "<grass has grown> (next: <natural deaths>)\n";
            cout << "(any number + <ENTER> to proceed)\n";
            my_scanf(input);
        }

        //death of old/hungry creatures
        for (int i = 0; i < size.x; i++) {
            for (int j = 0; j < size.y; j++) {
                actual_case = world[i][j];
                //wolf
                creature = actual_case->get_wolf();
                if (creature) 
                    creature->die(world);
                //sheep
                creature = actual_case->get_sheep();
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
                actual_case = world[i][j];

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
                actual_case = world[i][j];
                //wolf
                creature = actual_case->get_wolf();
                if (creature) 
                    creature->give_birth(world, size);
                //sheep
                creature = actual_case->get_sheep();
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
                actual_case = world[i][j];
                //wolf
                creature = actual_case->get_wolf();
                if (creature) 
                    creature->eat(world);
                //sheep
                creature = actual_case->get_sheep();
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
                actual_case = world[i][j];
                //wolf
                creature = actual_case->get_wolf();
                if (creature) 
                    creature->reproduction(world, size);
                //sheep
                creature = actual_case->get_sheep();
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
                actual_case = world[i][j];
                creature = actual_case->get_wolf();
                if (creature)
                    creature->has_survived();
                creature = actual_case->get_sheep();
                if (creature)
                    creature->has_survived();
            }
        }
    }




    int is_dead(WORLD &world, my_tuple size) {
        for (int i = 0; i < size.x; i++) {
            for (int j = 0; j < size.y; j++) {
                if (!world[i][j]->is_free_for(WOLF) || !world[i][j]->is_free_for(SHEEP))
                    return 0;
            }
        }
        return 1;
    }

    int has_creatures(WORLD &world, my_tuple size, string creature) {
        for (int i = 0; i < size.x; i++) {
            for (int j = 0; j < size.y; j++) {
                if (!world[i][j]->is_free_for(creature))
                    return 1;
            }
        }
        return 0;
    }

    void destroy(WORLD &world, my_tuple size) {
        for (int i = 0; i < size.x; i++) {
            for (int j = 0; j < size.y; j++)
                delete(world[i][j]);
        }
    }





    void display(WORLD &world, my_tuple size) {
        cout<< "\n    y";

        for (int i = 0; i < size.y; i++) {
            if (i < 10)
                cout<<"  "<< i <<"  ";
            else if (i < 100)
                cout<<"  "<< i <<" ";
            else if (i < 1000)
                cout<<" "<< i <<" ";
        }

        cout<< "y\n  x  ";
    
        for (int i = 0; i < size.x; i++) {
            if (i > 0)
                cout<< "     ";
            print_line(size.y);
            if (i == 0)
                cout<< "  x";
            cout<<endl;
    
            if (i < 10)
                cout<<"  "<< i <<"  ";
            else if (i < 100)
                cout<<"  "<< i <<" ";
            else if (i < 1000)
                cout<<" "<< i <<" ";
            for (int j = 0; j < size.y; j++) {
                cout << "|";
                world[i][j]->display();
                cout << "|";
            }
            if (i < 10)
                cout<<"  "<< i;
            else if (i < 100)
                cout<<"  "<< i;
            else if (i < 1000)
                cout<<" "<< i;
            cout << endl;
        }

        cout<< "  x  ";
        print_line(size.y);
        cout<< "  x\n    y";

        for (int i = 0; i < size.y; i++)
            if (i < 10)
                cout<<"  "<< i <<"  ";
            else if (i < 100)
                cout<<"  "<< i <<" ";
            else if (i < 1000)
                cout<<" "<< i <<" ";

        cout<< "y\n\n";
    }

}



