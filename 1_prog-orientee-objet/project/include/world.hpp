
#ifndef WORLD_H
#define WORLD_H

#include<vector>
#include<map>
using namespace std;
#include<classes.hpp>
using namespace classes;




namespace world {

    void presentation(void);
    void create(WORLD &world, my_tuple size, int nb_wolfs, int nb_sheeps);
    void process_day(WORLD &world, my_tuple size, int show_steps);
    int is_dead(WORLD &world, my_tuple size);
    int has_creatures(WORLD &world, my_tuple size, string creature);
    void display(WORLD &world, my_tuple size);
    void destroy(WORLD &world, my_tuple size);

}


#endif
