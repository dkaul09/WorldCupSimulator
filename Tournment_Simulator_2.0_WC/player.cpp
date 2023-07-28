#include "player.h"


Player::Player(std::string name, std::string nationality, std::string position, int jersey_number, int goals, int assists): 
  name_(name),nationality_(nationality),position_(position),jerseyno_(jersey_number), goals_(goals),assists_(assists), red_card_(false)
  {

  }

Player::~Player() {

}

std::string Player::get_name() const {
    return this->name_;
}

std::string Player::get_nationality() const {
    return this->nationality_;
}

std::string Player::get_position() const {
    return this->position_;
}

int Player::get_jersey_number() const {
    return this->jerseyno_;
}

int Player::get_goals() {
    return this->goals_;
}

int Player::get_assists() {
    return this->assists_;
}

void Player::add_goal(){
    this->goals_++;
}

void Player::add_assist(){
    this->assists_++;
}

void Player::give_red() {
    this->red_card_ = true;
}

void Player::remove_red() {
    this->red_card_ = false;
}

bool Player::check_red() {
    return this->red_card_;
}
   
   
   