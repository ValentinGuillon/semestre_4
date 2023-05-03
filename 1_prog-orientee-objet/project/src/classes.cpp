
#include<classes.hpp>
#include<cstdlib>
#include<iostream>
#include<cassert>
#include<map>
#include<error_messages.hpp>
using namespace error_messages;

// using namespace classes;



string choice(string const a, string const b) {
    if (std::rand() % 2)
        return a;
    return b;
};




namespace classes {

    int available_cases(my_tuple* &free_cases, WORLD &world, my_tuple const size, my_tuple const coords, CREATURE* creature) {
        // my_tuple *free_cases = NULL;
        int nb_cases = 0;
        string threat;

        for (int i = coords.x -1; i <= coords.x +1; i++) {
            if (i < 0 || i >= size.x) continue;
            for (int j = coords.y -1; j <= coords.y +1; j++) {
                if (j < 0 || j >= size.y) continue;
                if (! world[i][j]->is_free_for(creature->get_type())) continue;

                threat = creature->get_threat();
                if (! threat.compare("none") == 0) {
                    if (! world[i][j]->is_free_for(threat)) continue;
                }

                free_cases = (my_tuple*)realloc(free_cases, ++nb_cases * sizeof(my_tuple*));
                free_cases[nb_cases-1] = {i, j};
            }
        }
        return nb_cases;
    }




    int my_tuple::operator==(my_tuple &obj) {
        if (this->x != obj.x) return 0;
        if (this->y != obj.y) return 0;
        return 1;
    }

    ostream& operator<<(ostream &out, my_tuple const &obj) {
        out<<"[x="<<obj.x<<",y="<<obj.y<<"]";
        return out;
    }

    ostream& operator<<(ostream &out, CASE const &obj) {
        out << "{" << obj.coords;
        out << ", wolf=" << obj.wolf;
        out << ", sheep=" << obj.sheep;
        out << ", has{wolf=" << (*obj.has)[WOLF];
        out << ",sheep=" << (*obj.has)[SHEEP];
        out << ",herb=" << (*obj.has)[HERB];
        out << ",mineral=" << (*obj.has)[MINERAL] << "}";

        return out << "}";
    }

    ostream& operator<<(ostream &out, CREATURE const &obj) {
        out<< "{" << obj.type;
        out<< "|" << obj.gender;
        out<< ", " << obj.coords;
        out<< ", threat=" << obj.threat;
        out<< ", food=" << obj.food;
        out<< ", day_living=" << obj.day_living;
        out<< "/" << obj.day_esperance;
        out<< ", hunger=" << obj.hunger;
        out<< "/" << obj.hunger_limit;
        out<< ", reproducting=" << obj.reproducting;
        out<< ", has_reproduct=" << obj.has_reproduct;
        out<< ", has_moved=" << obj.has_moved;
        return out << "}";
    }


















    void CASE::display(void) {
        string RESET_COLOR = "\033[0m" ;
        string PINK = "\033[38;2;255;61;248m";
        string BLUE = "\033[38;2;44;187;250m";
        string BACK_GREEN = "\033[48;2;17;100;0;1m";
        string BACK_ORANGE  = "\033[48;2;255;171;0m";
        string BACK_GREY  = "\033[48;2;115;115;115m";
        
        string on_ground = RESET_COLOR;

        if ((*this->has)[HERB])
            on_ground = BACK_GREEN;
        else if ((*this->has)[MINERAL])
           on_ground = BACK_ORANGE;

        cout << on_ground;

        if (!(*this->has)[WOLF] && !(*this->has)[SHEEP]) {
            cout<< "   " << RESET_COLOR;
            return;
        }


        string gender;
        if ((*this->has)[WOLF] && (*this->has)[SHEEP]) {
            gender = this->get_wolf()->get_gender();
                if (gender.compare(MALE) == 0)
                    cout << BLUE;
                else if (gender.compare(FEMALE) == 0)
                    cout << PINK;

                if (this->get_wolf()->get_reproducting())
                    cout << BACK_GREY;

            cout << "W" << on_ground << " ";

            gender = this->get_sheep()->get_gender();
                if (gender.compare(MALE) == 0)
                    cout << BLUE;
                else if (gender.compare(FEMALE) == 0)
                    cout << PINK;

                if (this->get_sheep()->get_reproducting())
                    cout << BACK_GREY;

            cout << "S" << on_ground;
        }


        else if ((*this->has)[WOLF]) {
            cout<< " ";
            gender = this->get_wolf()->get_gender();
                if (gender.compare(MALE) == 0)
                    cout << BLUE;
                else if (gender.compare(FEMALE) == 0)
                    cout << PINK;
    
                if (this->get_wolf()->get_reproducting())
                    cout << BACK_GREY;

            cout << "W" << on_ground << " ";
        }

        else if ((*this->has)[SHEEP]) {
            cout<< " ";
            gender = this->get_sheep()->get_gender();
                if (gender.compare(MALE) == 0)
                    cout << BLUE;
                else if (gender.compare(FEMALE) == 0)
                    cout << PINK;
    
                if (this->get_sheep()->get_reproducting())
                    cout << BACK_GREY;

            cout << "S" << on_ground << " ";
        }

        cout << RESET_COLOR;
    }


    CASE::CASE(my_tuple const coords) {
        this->coords = coords;
        this->has = new map<string, int>;
        this->has->insert(make_pair(WOLF, 0));
        this->has->insert(make_pair(SHEEP, 0));
        this->has->insert(make_pair(HERB, 0));
        this->has->insert(make_pair(MINERAL, 0));

        this->wolf = NULL;
        this->sheep = NULL;

    }

    CASE::~CASE(void) {
        delete this->has;

        if(this->wolf)
            delete(this->wolf);
        if(this->sheep)
            delete(this->sheep);
    };


    int CASE::is_free_for(string const type) const {
        int to_ret = 1;
        try {
            to_ret = !(*this->has)[type];
        }
        catch (out_of_range const&) {
            throw (my_error){OUT_OF_RANGE, "classes.cpp: CASE::is_free_for"};
        }
        catch (...) {
            throw (my_error){NOT_DEFINED_CREATURE, "classes.cpp: CASE::is_free_for"};
        }

        return to_ret;
    }


    void CASE::add_entity(string const type, string gender) {
        if (! this->is_free_for(type)) throw (my_error){WRONG_GIVEN_ENTITY, "classes.cpp: CASE::add_entity"};

        try {
            (*this->has)[type] = 1;
        }
        catch (out_of_range const&) {
            throw (my_error){OUT_OF_RANGE, "classes.cpp: CASE::add_entity"};
        }
        catch (...) {
            throw (my_error){NOT_DEFINED_CREATURE, "classes.cpp: CASE::add_entity"};
        }

        if (gender == "none")
            gender = choice(MALE, FEMALE);

        if (type.compare(HERB) == 0) {
            if (!HIDE_PRINTS)
                cout<<"\033[38;2;255;171;0mHERB GROWS AT :\033[0m"<< this->coords<<endl;
            (*this->has)[MINERAL] = 0;
            return;
        }
        else if (type.compare(MINERAL) == 0) {
            if (!HIDE_PRINTS)
                cout<<"\033[38;2;255;171;0mMINERAL DROPED AT :\033[0m"<< this->coords<<endl;
            return;
        }
        else if (type.compare(WOLF) == 0) {
            this->wolf = new CREATURE{WOLF, {this->coords.x, coords.y}, gender};
        }
        else if (type.compare(SHEEP) == 0)
            this->sheep = new CREATURE{SHEEP, {coords.x, coords.y}, gender};

        else throw (my_error){NOT_DEFINED_CREATURE, "classes.cpp: CASE::add_entity"};
    }


    void CASE::move_creatures(WORLD &world, my_tuple size) {
        CREATURE* creature = NULL;
        my_tuple moved_to;
        my_tuple moved_from;

        if (!this->is_free_for(WOLF)) {
            creature = this->wolf;
            if (!creature->get_has_moved() && !creature->get_reproducting()) {
                moved_from = creature->get_coords();
                moved_to = creature->move(world, size);
                if (moved_from == moved_to) return;
                this->wolf = NULL;
                (*this->has)[WOLF] = 0;

                world[moved_to.x][moved_to.y]->wolf = creature;
                (*world[moved_to.x][moved_to.y]->has)[WOLF] = 1;

                if (!HIDE_PRINTS)
                    cout<<"\033[38;2;255;171;0mMOVED :\033[0m\n"<<*creature<<endl;
            }
        }


        if (!this->is_free_for(SHEEP)) {
            creature = this->sheep;
            if (!creature->get_has_moved() && !creature->get_reproducting()) {
                moved_from = creature->get_coords();
                moved_to = creature->move(world, size);
                if (moved_from == moved_to) return;
                this->sheep = NULL;
                (*this->has)[SHEEP] = 0;

                world[moved_to.x][moved_to.y]->sheep = creature;
                (*world[moved_to.x][moved_to.y]->has)[SHEEP] = 1;

                if (!HIDE_PRINTS)
                    cout<<"\033[38;2;255;171;0mMOVED :\033[0m\n"<<*creature<<endl;
            }
        }

        
    }



    void CASE::remove_entity(string const type, string const death_reason) {
        if (this->is_free_for(type)) throw (my_error){WRONG_GIVEN_ENTITY, "classes.cpp: CASE::remove_entity"};

        (*this->has)[type] = 0;

        if (type.compare(HERB) == 0 or type.compare(MINERAL) == 0) return;

        else if (type.compare(WOLF) == 0) {
            if (!HIDE_PRINTS)
                cout<<"\033[38;2;255;171;0mDIED :\033[0m ("<< death_reason << ")\n" <<*this->wolf<<endl;
            delete(this->wolf);
            this->wolf = NULL;
        }
        else if (type.compare(SHEEP) == 0) {
            if (!HIDE_PRINTS)
                cout<<"\033[38;2;255;171;0mDIED :\033[0m ("<< death_reason << ")\n" <<*this->sheep<<endl;
            delete(this->sheep);
            this->sheep = NULL;
        }
        else throw (my_error){NOT_DEFINED_CREATURE, "classes.cpp: CASE::remove_entity"};

        if ((death_reason.compare(DEATH_HUNGER) == 0) or (death_reason.compare(DEATH_OLDNESS) == 0))
            this->add_entity(MINERAL);
    }




    CREATURE* CASE::get_wolf(void) const { return this->wolf; }
    CREATURE* CASE::get_sheep(void) const { return this->sheep; }































    CREATURE::CREATURE(string const type, my_tuple const coords, string gender){
        this->type = type;
        this->coords.x = coords.x; this->coords.y = coords.y;
        this->day_living = 0;
        this->hunger = 0;
        this->reproducting = 0;
        this->has_reproduct = 1;
        this->has_moved = 1;

        if (type == WOLF) {
            this->food = SHEEP;
            this->threat = "none";
            this->gender = gender;
            this->day_esperance = 30;
            this->hunger_limit = 10;
        }
        else if (type == SHEEP) {
            this->food = HERB;
            this->threat = WOLF;
            this->gender = gender;
            this->day_esperance = 25;
            this->hunger_limit = 5;
        }
        else throw (my_error){NOT_DEFINED_CREATURE, "classes.cpp: CREATURE::CREATURE"};

        if (!HIDE_PRINTS)
            cout<<"\033[38;2;255;171;0mBIRTH :\033[0m\n"<<*this<<endl;
    }






    my_tuple CREATURE::move(WORLD &world, my_tuple size) {
        if (this->has_moved) return this->coords;
        this->has_moved = 1;
        if (this->reproducting) return this->coords;

        my_tuple *free_cases = NULL;
        int nb_cases = available_cases(free_cases, world, size, this->coords, this);


        if (nb_cases == 0) {
            free(free_cases);
            return this->coords;
        }


        int random = std::rand() % nb_cases;
        my_tuple new_coords = free_cases[random];

        this->coords = new_coords;

        free(free_cases);
        return new_coords;

    }


    void CREATURE::eat(WORLD &world) {
        CASE* actual_case = world[this->coords.x][this->coords.y];
        int food_available = !actual_case->is_free_for(this->food);
        if (!food_available) return;

        actual_case->remove_entity(this->food, "eaten");
        this->hunger = 0;
        if (!HIDE_PRINTS)
            cout<<"\033[38;2;255;171;0mCREATURE EAT :\033[0m\n"<<*this<<endl;
    }


    void CREATURE::reproduction(WORLD &world, my_tuple const size) {
        if (this->reproducting) return;
        if (this->has_reproduct) return;

        my_tuple *cases_of_potential_partner = NULL;
        int nb_cases = 0;
        /*
        // my_tuple *free_cases = NULL;
        int nb_cases = 0;
        string threat;

        for (int i = coords.x -1; i <= coords.x +1; i++) {
            if (i < 0 || i >= size.x) continue;
            for (int j = coords.y -1; j <= coords.y +1; j++) {
                if (j < 0 || j >= size.y) continue;
                if (! world[i][j].is_free_for(creature->get_type())) continue;

                threat = creature->get_threat();
                if (! threat.compare("none") == 0) {
                    if (! world[i][j].is_free_for(threat)) continue;
                }

                free_cases = (my_tuple*)realloc(free_cases, ++nb_cases * sizeof(my_tuple*));
                free_cases[nb_cases-1] = {i, j};
            }
        }
        return nb_cases;
        */
        //search on adjacents CASE
        CREATURE* congenere;
        for (int i = this->coords.x -1; i <= this->coords.x +1; i++) {
            if (i < 0 || i >= size.x) continue;
            for (int j = this->coords.y -1; j <= this->coords.y +1; j++) {
                if (j < 0 || j >= size.y) continue;

                int has_congenere = !world[i][j]->is_free_for(this->type);
                if (!has_congenere) continue;


                if (type.compare(WOLF) == 0) {
                    congenere = world[i][j]->get_wolf();
                }
                else if (type.compare(SHEEP) == 0) {
                    congenere = world[i][j]->get_sheep();
                }

                if (congenere->reproducting) continue;
                if (congenere->has_reproduct) continue;
                if (congenere->gender.compare(this->gender) == 0) continue;

                
                cases_of_potential_partner = (my_tuple*)realloc(cases_of_potential_partner, ++nb_cases * sizeof(my_tuple*));
                cases_of_potential_partner[nb_cases-1] = {i, j};
                

                // this->reproducting = 1;
                // congenere->reproducting = 1;

                // if (!HIDE_PRINTS) {
                //     cout<<"\033[38;2;255;171;0mREPRODUCTS OF :\033[0m\n"<<*this <<endl;
                //     cout<<"\033[38;2;255;171;0mWITH :\033[0m\n"<<*congenere<<endl;
                // }
                // return;
            }
        }


        if (nb_cases == 0) {
            free(cases_of_potential_partner);
            return;
        }


        int random = std::rand() % nb_cases;
        my_tuple partner_case = cases_of_potential_partner[random];
        if (this->type.compare(WOLF) == 0)
            congenere = world[partner_case.x][partner_case.y]->get_wolf();
        if (this->type.compare(SHEEP) == 0)
            congenere = world[partner_case.x][partner_case.y]->get_sheep();

        this->reproducting = 1;
        congenere->reproducting = 1;

        if (!HIDE_PRINTS) {
            cout<<"\033[38;2;255;171;0mREPRODUCTS OF :\033[0m\n"<<*this <<endl;
            cout<<"\033[38;2;255;171;0mWITH :\033[0m\n"<<*congenere<<endl;
        }

        free(cases_of_potential_partner);
    }


    void CREATURE::give_birth(WORLD &world, my_tuple const size) {
        if (!this->reproducting) return;
        this->reproducting = 0;
        this->has_reproduct = 1;
        if (this->gender.compare(MALE) == 0) return;

        my_tuple *free_cases = NULL;
        int nb_cases = available_cases(free_cases, world, size, this->coords, this);
        
        if (nb_cases == 0) {
            free(free_cases);
            return;
        }

        int random = std::rand() % nb_cases;


        CASE* choosen_case = world[free_cases[random].x][free_cases[random].y];

        choosen_case->add_entity(this->type);


        free(free_cases);
    };

    string CREATURE::die_today(void) const {
        if (this->day_living >= this->day_esperance) return DEATH_OLDNESS;
        if (this->hunger >= this->hunger_limit) return DEATH_HUNGER;
        return "none";
    };


    void CREATURE::die(WORLD &world) {
        string death_reason = this->die_today();

        if (death_reason.compare("none") == 0) return;
    
        world[this->coords.x][this->coords.y]->remove_entity(this->type, death_reason);
    };

    void CREATURE::has_survived(void) {
        this->day_living++;
        this->hunger++;
    }

    void CREATURE::reset_has_moved(void) { this->has_moved = 0; }
    void CREATURE::reset_has_reproduct(void) { this->has_reproduct = 0; }


    string const CREATURE::get_type(void) const { return this->type; }

    string const CREATURE::get_gender(void) const { return this->gender; }

    string const CREATURE::get_threat(void) const { return this->threat; }

    int CREATURE::get_has_moved(void) const { return this->has_moved; }
    int CREATURE::get_reproducting(void) const { return this->reproducting; }
    my_tuple CREATURE::get_coords(void) const { return this->coords; }

}