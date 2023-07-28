#include "team.h"

Team::Team(std::string name, int no_of_points, int group_no, std::set<std::string> opponents_played, double attack_rating, double defense_rating): 
 team_name_(name),no_of_points_(no_of_points),group_no_(group_no), opponents_played_(opponents_played), attack_rating_(attack_rating),defense_rating_(defense_rating) {

}

Team::~Team() {

}

std::string Team::get_name() const {
    return this->team_name_;
}

int Team::get_points() const{
     return this->no_of_points_;
 }


 void Team::set_group_no(int group_number) {
    this->group_no_ = group_number;
 }



 void Team::add_points(int points) {
    this->no_of_points_ += points;
 }

 void Team::add_opponents_played(std::string opponent_name) {
    this->opponents_played_.insert(opponent_name);
 }

std::set<std::string> Team::get_opponents_played() {
   return this->opponents_played_;
 }

 int Team::get_goals_scored() {
   return this->goals_scored_;
 }

 int Team::get_goals_conceded() {
   return this->goals_conceded_;
 }

 void Team::add_goals_scored(int goals_scored){ 
    this->goals_scored_ += goals_scored;
 }


 void Team::add_goals_conceded(int goals_conceded){ 
    this->goals_conceded_ += goals_conceded;
 }

 void Team::add_draw(){ 
   this->draws_ +=1;
 }

 void Team::add_win(){ 
   this->wins_ +=1;
 }

 void Team::add_loss(){ 
   this->losses_ +=1;
 }

 int Team::get_draws() {
   return this->draws_;
 }

 int Team::get_wins() {
   return this->wins_;
 }

 int Team::get_losses() {
   return this->losses_;
 }

 double Team::get_attack_rating() {
  return this->attack_rating_;
 }

 double Team::get_defense_rating() {
  return this->defense_rating_;
 }





