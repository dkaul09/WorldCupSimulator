#include "match_simulator.h"
#include <iostream>
using namespace std;

MatchSimulator::MatchSimulator() {

}

MatchSimulator::~MatchSimulator() {

}

void MatchSimulator::table_sorter(std::vector<Team*>& group) {
     for (int step = 1; step < group.size(); step++)
     {
        Team* key = group[step];
        int j = step - 1;
        if (key->get_points() == group[j]->get_points()) {
            continue;
        } 
        while (j >= 0) 
        { 

         if (key->get_points() > group[j]->get_points()) {
            group[j + 1] = group[j];
         } else {
            break;
         }
         j -= 1;
        } 
        group[j + 1] = key;       
     
     }
  
     
      for (int step = 1; step < group.size(); step++) // see if there is an efficient way to address GD. Maybe include it in the prev loop
     {
        Team* key = group[step];
        int j = step - 1; 
        if (key->get_points() == group[j]->get_points()) {
            if(key->get_goals_scored() - key->get_goals_conceded() >  group[j]->get_goals_scored() - group[j]->get_goals_conceded()) {
                group[j + 1] = group[j];
                group[j] = key; 
            } else if (key->get_goals_scored() - key->get_goals_conceded() ==  group[j]->get_goals_scored() - group[j]->get_goals_conceded()) {
                continue;
            }
        }    
        
     } 
}

void MatchSimulator::print_table(int matches_played,std::vector<std::vector<Team*> > groups) {
    for (int i = 0; i < 8; i++) {
        std::vector<Team*> current_group = groups[i];
        cout << " League Position " << " || " << " Team Name " << " || " <<  " Matches Played " << " || " << " Wins " << " || " << " Draws " << "||" << " Losses " << " ||" " GF " << "||" << " GA " << "|| " << " GD " << "||" << " Pts " << endl;
         for (int j = 1; j < 5; j++) {
         cout << j << "                    " << current_group[j - 1]->get_name() << "                      " << matches_played << "                " << current_group[j-1]->get_wins() << " " << " || " << current_group[j-1]->get_draws () << " || " << current_group[j-1]->get_losses() << " " << "||" << current_group[j-1]->get_goals_scored() << " || " <<  current_group[j-1]->get_goals_conceded() << " || " << current_group[j-1]->get_goals_scored() - current_group[j-1]->get_goals_conceded() << " " << current_group[j-1]->get_points() << endl; 
       }
    }

}

void MatchSimulator::runner(std::vector<std::vector<Team*> >& groups) {
    for (int i = 0; i < 8; i += 2) {
        std::vector<Team*> group_1 = groups[i];
        std::vector<Team*> group_2 = groups[i + 1];
        std::set<Team*> teams_played_on_matchday;
        for (int j = 0; j < 4; j++) { 
            std::vector<Team*> current_group;
            if (j % 2 == 0) {
                current_group = group_1;
            } else {
                current_group = group_2;
            }

         int r = (rand() % 4); 
         Team* team_1 = current_group[r];
         std::set<std::string> team_1_opponents_played = team_1->get_opponents_played();
         if (team_1_opponents_played.size() == 3 || teams_played_on_matchday.find(team_1) != teams_played_on_matchday.end()) {
             r = (rand() % 4); 
             Team* new_team_1 = current_group[r];
             std::set<std::string> new_team_1_opponents_played = new_team_1->get_opponents_played();
             while (team_1 == new_team_1 || new_team_1_opponents_played.size() == 3 || teams_played_on_matchday.find(new_team_1) != teams_played_on_matchday.end()) {
                r = (rand() % 4); 
                new_team_1 = current_group[r];
                new_team_1_opponents_played = new_team_1->get_opponents_played();
             }
             team_1 = new_team_1;
             team_1_opponents_played = team_1->get_opponents_played();
         }

        r = (rand() % 4); 
        Team* team_2 = current_group[r];
        std::set<std::string> team_2_opponents_played = team_2->get_opponents_played();

        if (team_2_opponents_played.size() == 3 || teams_played_on_matchday.find(team_2) != teams_played_on_matchday.end()) {
            r = (rand() % 4); 
            Team* new_team_2 = current_group[r];
            std::set<std::string> new_team_2_opponents_played = new_team_2->get_opponents_played();
            while (new_team_2 == team_1|| team_2 == new_team_2 || new_team_2_opponents_played.size() == 3 || teams_played_on_matchday.find(new_team_2) != teams_played_on_matchday.end()) {
                r = (rand() % 4); 
                new_team_2 = current_group[r];
                new_team_2_opponents_played = new_team_2->get_opponents_played();
             }
            team_2 = new_team_2;
            team_2_opponents_played = team_2->get_opponents_played();
         }

         while(team_1_opponents_played.find(team_2->get_name()) != team_1_opponents_played.end() ||team_2_opponents_played.find(team_1->get_name()) != team_2_opponents_played.end() || team_1 == team_2 || teams_played_on_matchday.find(team_1) != teams_played_on_matchday.end() || teams_played_on_matchday.find(team_2) != teams_played_on_matchday.end()) { 
            if (team_1_opponents_played.size() == 3 || team_1_opponents_played.find(team_2->get_name()) != team_1_opponents_played.end() || team_1 == team_2 || teams_played_on_matchday.find(team_1) != teams_played_on_matchday.end()) {
                r = (rand() % 4); 
                Team* new_team_1 = current_group[r];
                std::set<std::string> new_team_1_opponents_played = new_team_1->get_opponents_played();
                while (team_1 == new_team_1 || new_team_1_opponents_played.size() == 3 || new_team_1 == team_2 || new_team_1_opponents_played.find(team_2->get_name()) != new_team_1_opponents_played.end() || teams_played_on_matchday.find(new_team_1) != teams_played_on_matchday.end() ) { //have a look at the last condition
                 r = (rand() % 4); 
                 new_team_1 = current_group[r];
                 new_team_1_opponents_played = new_team_1->get_opponents_played();
                 
            } 
            team_1 = new_team_1;
            team_1_opponents_played = team_1->get_opponents_played();
             }
             

             if (team_2_opponents_played.size() == 3 || team_2_opponents_played.find(team_1->get_name()) != team_2_opponents_played.end() || team_1 == team_2 || teams_played_on_matchday.find(team_2) != teams_played_on_matchday.end()) {
                r = (rand() % 4); 
                Team* new_team_2 = current_group[r];
                std::set<std::string> new_team_2_opponents_played = new_team_2->get_opponents_played();
                while (team_1 == new_team_2 || new_team_2_opponents_played.size() == 3 || new_team_2 == team_2 || new_team_2_opponents_played.find(team_1->get_name()) != new_team_2_opponents_played.end() || teams_played_on_matchday.find(new_team_2) != teams_played_on_matchday.end()) { //have a look at the last condition
                 r = (rand() % 4); 
                 new_team_2 = current_group[r];
                 new_team_2_opponents_played = new_team_2->get_opponents_played();
                 
             }
             team_2 = new_team_2;
             team_2_opponents_played = team_2->get_opponents_played();
            
            } 
            std::set<std::string> new_team_2_opponents_played = team_2->get_opponents_played();
         }
        

        cout << team_1->get_name() << " vs " << team_2->get_name() << endl;
        team_1->add_opponents_played(team_2->get_name());
        team_2->add_opponents_played(team_1->get_name());
        teams_played_on_matchday.insert(team_1);
        teams_played_on_matchday.insert(team_2);

        cout << "Press enter to Continue";
        cin.ignore(); 

        int minute_scored_by_team_1 = rand() % 92; // if clock is 0 then no one has scored
        int minute_scored_by_team_2 = rand() % 92; // use 92 or 94

        std::string scorers_for_team_1 = " ";
        std::string scorers_for_team_2 = " ";



       //use hashing to generate minute?

       //create an array storing the minutes and have the largest one, a number bigger than the largest minute should be generated
       //mark each minute with whether it's been used up or not 
        int latest_team_1 = 0;
        int latest_team_2 = 0;

        int goals_by_team1 = 0;
        int goals_by_team2 = 0;


        if (minute_scored_by_team_1 != 0) {
            int player_index = rand() % 4;
            latest_team_1 = minute_scored_by_team_1;
            scorers_for_team_1 += "(" + team_1_players[player_index]->get_name() + " " + to_string(minute_scored_by_team_1) + "'";
            goals_by_team1++;
            minute_scored_by_team_1 = rand() % 92;
            while(minute_scored_by_team_1 > latest_team_1 && minute_scored_by_team_1 != 92) {
                 player_index = rand() % 4;
                 scorers_for_team_1 += "," + team_1_players[player_index]->get_name() + " " + to_string(minute_scored_by_team_1) + "'";
                 latest_team_1 = minute_scored_by_team_1;
                 goals_by_team1++;
                 minute_scored_by_team_1 = rand() % 92; //have a look at this
            }
            if (goals_by_team1 >= 0) {
                 scorers_for_team_1 += ")";
        }
        }

        if (minute_scored_by_team_2 != 0) {
            int player_index = rand() % 4;
            latest_team_2 = minute_scored_by_team_2;
            scorers_for_team_2 += "(" + team_2_players[player_index]->get_name() + " " + to_string(minute_scored_by_team_2) + "'";
            goals_by_team2++;
            minute_scored_by_team_2 = rand() % 92;
            while(minute_scored_by_team_2 > latest_team_2 && minute_scored_by_team_2 != 92) {
                 player_index = rand() % 4;
                 scorers_for_team_2 += "," + team_2_players[player_index]->get_name() + " " + to_string(minute_scored_by_team_2) + "'";
                 latest_team_2 = minute_scored_by_team_2;
                 goals_by_team2++;
                 minute_scored_by_team_2 = rand() % 92; //have a look at this
            }
            if (goals_by_team2 >= 0) {
                 scorers_for_team_2 += ")";
        }
        }
         cout << "Final score: " << team_1->get_name() << " " << goals_by_team1 << " : "  << goals_by_team2 << " " << team_2->get_name() << endl;
         cout << scorers_for_team_1 << " " << scorers_for_team_2 << endl;

         if (goals_by_team1 > goals_by_team2) {
            team_1->add_points(3);
            team_1->add_win();
            team_2->add_loss();
         } else if (goals_by_team2 > goals_by_team1) {
            team_2->add_points(3);
            team_2->add_win();
            team_1->add_loss();
         } else {
            team_1->add_points(1);
            team_2->add_points(1);
            team_1->add_draw();
            team_2->add_draw();
         }

         team_1->add_goals_scored(goals_by_team1);
         team_1->add_goals_conceded(goals_by_team2);
         team_2->add_goals_scored(goals_by_team2);
         team_2->add_goals_conceded(goals_by_team1);
   }    
   for (int i = 0; i < groups.size(); i++) {
       table_sorter(groups[i]);
   }
}
}