
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
    world::presentation();

    srand(time(0));
    classes::my_tuple world_size;
    int nb_wolfs, nb_sheeps;

    //take world size and number of creatures
    cout << "World size: {x, y}\nx ";
    while (1) {
        my_scanf(world_size.x);
        if (world_size.x > 0) break;
        cout << "<give positive interger> ";
    }
    cout << "y ";
    while (1) {
        my_scanf(world_size.y);
        if (world_size.y > 0) break;
        cout << "<give positive interger> ";
    }

    cout << "How many \"wolfs\" ?\n";
    while (1) {
        my_scanf(nb_wolfs);
        if (nb_wolfs >= 0) break;
        cout << "<give positive or null interger> ";
    }
    cout << "How many \"sheeps\" ?\n";
    while (1) {
        my_scanf(nb_sheeps);
        if (nb_sheeps >= 0) break;
        cout << "<give positive or null interger> ";
    }

    
    WORLD world;
    int world_age = 0;
    int day_survive_wolf = 0;
    int day_survive_sheep = 0;

    int skip_scanf = 1;


    cout << "Would you like to display the simulation ? (1 for yes, 0 for no)\n";
    while (1) {
        my_scanf(HIDE_PRINTS);
        if (HIDE_PRINTS == 1 || HIDE_PRINTS == 0) break;
        cout << "<give 1 or 0> ";
    }
    HIDE_PRINTS = !HIDE_PRINTS;


    if (!HIDE_PRINTS) {
        cout << "skip scanf ? (1 for yes, 0 for no)\n";
        while (1) {
            my_scanf(skip_scanf);
            if (skip_scanf == 1 || skip_scanf == 0) break;
            cout << "<give 1 or 0> ";
        }
    }


    int input = !HIDE_PRINTS;

    if (skip_scanf)
        input = 0;

    int error_occurred = 0;
    try {
        cout <<"<begin simulation>\n";
        world::create(world, world_size, nb_wolfs, nb_sheeps);

        if (!HIDE_PRINTS) {
            world::display(world, world_size);
            cout <<"(>0 to each steps, 0 to not see them, <0 to end the simulation, 1234 to skip to the end)\n";
            if (!skip_scanf)
                my_scanf(input);
        }

        if (input == 1234) {
            skip_scanf = 1;
            input = 0;
        }
                
        while (input >= 0) {
            world::process_day(world, world_size, input);
            world_age++;
            day_survive_wolf += world::has_creatures(world, world_size, WOLF);
            day_survive_sheep += world::has_creatures(world, world_size, SHEEP);

            if (skip_scanf && HIDE_PRINTS && world_age%500 == 0) {
                cout << world_age <<" has passed...\n";
                if (world_age%2000 == 0)
                    world::display(world, world_size);
            }

            if (!HIDE_PRINTS)
                world::display(world, world_size);

            if (world::is_dead(world, world_size))
                break;

            if (!HIDE_PRINTS) {
                cout <<"day "<<world_age<< " <DAY HAS ENDED>\n(>0 to each steps, 0 to not see them, <0 to end the simulation, 1234 to skip to the end)\n";
                if (!skip_scanf)
                    my_scanf(input);
                if (input == 1234) {
                    skip_scanf = 1;
                    input = 0;
                }
            }
        }

        cout << "\n\n=========\n   END\n=========\n\n";

        if (world::is_dead(world, world_size) && !HIDE_PRINTS)
            cout << "The world is dead.\n";

    }
    catch (my_error error) {
        print_error(error);
        error_occurred = 1;
    }
    catch (out_of_range const&) {
        cout << "\nERROR: out_of_range\n";
        error_occurred = 1;
    }
    catch (...) {
        cout << "\nERROR: ?\n";
        error_occurred = 1;
    }

    world::destroy(world, world_size);

    if (error_occurred) return 0;

    if (input < 0)
        cout<< "The simulation has been crushed.\n";
    else {
        cout<< "This " << world_size << " world, was started with " << nb_wolfs << " wolfs and " << nb_sheeps << " sheeps\n";
        cout<< "The simulation has ended after " << world_age << " days.\n";
        cout<< WOLF << "s has survived " << day_survive_wolf << " days.\n";
        cout<< SHEEP << "s has survived " << day_survive_sheep << " days.\n";
    }


    return 0;
}

