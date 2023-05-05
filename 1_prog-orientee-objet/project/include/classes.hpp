
#ifndef CREATURE_H
#define CREATURE_H
#include<iostream>
#include<map>
#include<vector>
#include<string>
using namespace std;


#define MALE /*"male"*/ "\033[38;2;44;187;250m♂\033[0m" 
#define FEMALE /*"female"*/ "\033[38;2;255;61;248m♀\033[0m"

#define WOLF "wolf"
#define SHEEP "sheep"
#define GRASS "grass"
#define MINERAL "mineral"

#define DEATH_HUNGER "hunger"
#define DEATH_OLDNESS "oldness"


string choice(string const a, string const b);

namespace classes {
    class CASE;

    typedef vector<vector<CASE*>> WORLD;
    // typedef CASE** WORLD;

    typedef struct tuple_t my_tuple;
    struct tuple_t {
        int x, y;
        friend ostream& operator<<(ostream &out, my_tuple const &obj);
        int operator==(my_tuple &obj);
    };


    class CREATURE;



    class CASE {
        my_tuple coords;
        map<string, int>* has;
        // map<string, CREATURE*> creatures;
        CREATURE* wolf;
        CREATURE* sheep;

        public:
            friend ostream& operator<<(ostream &out, CASE const &obj);

            CASE(my_tuple const coords);
            ~CASE(void);
            void display(void);
            int is_free_for(string const type) const;
            void add_entity(string const type, string const gender = "none");
            void move_creatures(WORLD &world, my_tuple size);
            void remove_entity(string const type, string const death_reason = "none");
            CREATURE* get_wolf(void) const;
            CREATURE* get_sheep(void) const;
    };


    class CREATURE {
        string type;
        my_tuple coords;
        string food;
        string threat;
        string gender;
        int day_living;
        int day_esperance;
        int hunger;
        int hunger_limit;
        int reproducting;
        int has_reproduct;
        int has_moved;

        public:
            friend ostream& operator<<(ostream &out, CREATURE const &obj);

            CREATURE(string const type, my_tuple const coords, string gender);
            //set the coords to available adjacent case (including the current case) then return them
            my_tuple move(WORLD &world, my_tuple size);
            //if there is a FOOD entity on the same case, remove it, and reset HUNGER to 0
            void eat(WORLD &world);
            //increase HUNGER and DAY_LIVING by 1
            void has_survived(void);
            //set REPRODUCTING to 1 if there is nearby congenere from the other gender that is not in reproduction state
            void reproduction(WORLD &world, my_tuple const size);
            //create a TYPE entity on an available adjacent case, if possible (GENDER=FEMALE, REPRODUCTION=1)
            void give_birth(WORLD &world, my_tuple const size);
            //return the death reason (HUNGER or OLDNESS or "none") if good conditions encounter
            string die_today(void) const;
            //check if has to die, then calls the method that removes thit creature
            void die(WORLD &world);

            void reset_has_moved(void);
            void reset_has_reproduct(void);
            int get_has_moved(void) const;
            int get_reproducting(void) const;
            my_tuple get_coords(void) const;
            string const get_type(void) const;
            string const get_gender(void) const;
            string const get_threat(void) const;
    };
}


#endif
