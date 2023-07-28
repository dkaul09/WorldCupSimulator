#ifndef TEAM_H
#define TEAM_H
#include <iostream>
#include <string>
#include <set>


class Team {

    public:
      Team(std::string name, int no_of_trophies, int group_no, std::set<std::string> opponents_played, double attack_rating, double defense_rating);

     ~Team();

     std::string get_name() const;
     int get_points() const;
     void add_points(int points);
     void set_group_no(int group_number);
     int get_goals_scored();
     int get_goals_conceded();
     int get_wins();
     int get_losses();
     int get_draws();
     void add_win();
     void add_loss();
     void add_draw();
     void add_goals_scored(int goals_scored);
     void add_goals_conceded(int goals_conceded);
     void add_opponents_played(std::string opponents);
     double get_attack_rating();
     double get_defense_rating();
     std::set<std::string> get_opponents_played();


     private: 
      std::string team_name_;
      bool current_winner_;
      int no_of_points_;
      int group_no_;
      int goals_scored_;
      int goals_conceded_;
      int wins_;
      int losses_;
      int draws_;
      double attack_rating_;
      double defense_rating_;
      std::set<std::string> opponents_played_;
};


#endif