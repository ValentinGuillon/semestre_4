
#include<iostream>
#include<cstdio>
using namespace std;
#include<classes.hpp>
#include<world.hpp>
#include<error_messages.hpp>
using namespace error_messages;
#include<time.h>
#include<vector>



int main(void) {
    srand(time(0));
    int nb_creatures = 4;

    classes::my_tuple world_size = {4, 4};
    // classes::CASE **world = NULL;
    WORLD world;
    int world_age = 0;

    int skip_scanf = 0;


    cout << "Would you like to display the simulation ? (1 for yes, 0 for no)\n";
    my_scanf(HIDE_PRINTS);
    HIDE_PRINTS = !HIDE_PRINTS;


    if (!HIDE_PRINTS) {
        cout << "skip scanf ? (1 for yes, 0 for no)\n";
        my_scanf(skip_scanf);
    }


    int input = !HIDE_PRINTS;

    if (skip_scanf)
        input = 0;

    try {

        // HIDE_PRINTS = 0;

        world::create(world, world_size, nb_creatures);

        if (!HIDE_PRINTS) {
            world::display(world, world_size);
            cout <<"<begin simulation>\n(>0 to each steps, 0 to not see them, <0 to end the simulation)\n";
            if (!skip_scanf)
                my_scanf(input);
        }
        
        
        while (input >= 0) {
            world::process_day(world, world_size, input);
            ++world_age;

            if (!HIDE_PRINTS)
                world::display(world, world_size);

            if (world::is_dead(world, world_size))
                break;

            if (!HIDE_PRINTS) {
                cout <<"day "<<world_age<< " <DAY HAS ENDED>\n(>0 to each steps, 0 to not see them, <0 to end the simulation)\n";
                if (!skip_scanf)
                    my_scanf(input);
            }
        }

        if (world::is_dead(world, world_size))
            cout << "The world is dead.\n";

    }
    catch (my_error error) {
        print_error(error);
    }
    catch (out_of_range const&) {
        cout << "\nERROR: out_of_range\n";
    }
    catch (...) {
        cout << "\nERROR: ?\n";
    }

    cout<< "The simulation has ended after " << world_age << " days.\n";
    // world::destroy(world, world_size);

    return 0;
}

