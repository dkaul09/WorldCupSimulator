#include "teamparser.h"
#include "player.h"
#include "team.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

TeamParser::TeamParser() {

}

TeamParser::~TeamParser() {

}

void TeamParser::parse(std::string db_filename, std::set<Team*>& teams, std::vector<Team*>& sorted_teams) {
     teams.clear();
     ifstream ifile(db_filename);
    if(ifile.fail()){
        cout << "Cannot open file: " << "db_filename" << endl;
        return;
    }
     
     string no_of_flags; 
     getline(ifile,no_of_flags);
     stringstream ss(no_of_flags);
     int n; //number of teams 
     ss >> n; 


     if (ifile.fail()) {
        cout << "Failed." << endl;
        return;
     }
   
     for (int i = 0; i < n; i++) {
        string team_info;
        string team_name;
        string whitespace;
        double attack_rating; 
        double defense_rating;
      
        getline(ifile,team_info);
        stringstream ts(team_info);
        ts >> team_name >> attack_rating >> defense_rating;
      

        std::set<std::string> teams_played;
        Team* new_team = new Team(team_name,0,0,teams_played,attack_rating,defense_rating);
        teams.insert(new_team);
        sorted_teams.push_back(new_team);
     }
     
  }
