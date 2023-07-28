#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>

class Player {
    public: 
    Player(std::string name, std::string nationality, std::string position, int jersey_number, int goals, int assists);
    ~Player();

    std::string get_name() const;
    std::string get_nationality() const; 
    std::string get_position() const; 
    int get_jersey_number() const;

    int get_goals();
    int get_assists();

    void add_goal();
    void add_assist();

    void give_red();
    bool check_red();
    void remove_red();

    private: 
     std::string name_;
     std::string nationality_;
     std::string position_;
     int jerseyno_;
     int goals_;
     int assists_;
     bool red_card_;

};

#endif