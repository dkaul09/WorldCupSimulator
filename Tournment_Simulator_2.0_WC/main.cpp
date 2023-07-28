#include <iostream>
#include <fstream>
#include <set>
#include <sstream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <map>
#include "team.h"
#include "teamparser.h"
#include "match_simulator.h"
#include "knockout_sim.h"
#include <stdio.h>
#include <stdlib.h>
#include <random>
#include <ctime>
#include <cmath>
#include <cstdlib>
using namespace std; 

int main(int argc, char * argv[]) {

    srand((unsigned) time(NULL));

    if(argc < 2) {
        cerr << "Please specify a database file" << endl;
        return 1;
    }

    ifstream ifile(argv[1]);
    if(ifile.fail()){
        cout << "Cannot open file: " << argv[1] << endl;
        return 1;
    }

    TeamParser parser;
    std::set<Team*> tourny_teams;
    std::vector<Team*> sorted_teams;
    parser.parse(argv[1], tourny_teams,sorted_teams);
    set<Team*>::iterator itr;
    std::map<int,std::set<Team*> > groups;  
   

  
    for (int i = 1; i < 9; i++) {
        std::set<Team*> group;
        groups[i - 1] = group;
    } 

    int option;
    cout << "Enter 0 if you want randomized groups or enter 1 if you want the fixed groups." << endl;
    cin >> option;

    if (option == 1) {

    groups[0].insert(sorted_teams[0]);
    groups[0].insert(sorted_teams[1]);
    groups[0].insert(sorted_teams[2]);
    groups[0].insert(sorted_teams[3]);

    groups[1].insert(sorted_teams[4]);
    groups[1].insert(sorted_teams[5]);
    groups[1].insert(sorted_teams[6]);
    groups[1].insert(sorted_teams[7]);

    groups[2].insert(sorted_teams[8]);
    groups[2].insert(sorted_teams[9]);
    groups[2].insert(sorted_teams[10]);
    groups[2].insert(sorted_teams[11]);

    groups[3].insert(sorted_teams[12]);
    groups[3].insert(sorted_teams[13]);
    groups[3].insert(sorted_teams[14]);
    groups[3].insert(sorted_teams[15]);


    groups[4].insert(sorted_teams[16]);
    groups[4].insert(sorted_teams[17]);
    groups[4].insert(sorted_teams[18]);
    groups[4].insert(sorted_teams[19]);

    groups[5].insert(sorted_teams[20]);
    groups[5].insert(sorted_teams[21]);
    groups[5].insert(sorted_teams[22]);
    groups[5].insert(sorted_teams[23]);

    groups[6].insert(sorted_teams[24]);
    groups[6].insert(sorted_teams[25]);
    groups[6].insert(sorted_teams[26]);
    groups[6].insert(sorted_teams[27]);

    groups[7].insert(sorted_teams[28]);
    groups[7].insert(sorted_teams[29]);
    groups[7].insert(sorted_teams[30]);
    groups[7].insert(sorted_teams[31]);
    } else {
   
     for (itr = tourny_teams.begin(); itr != tourny_teams.end(); ++itr)
    {  
       Team* team = *itr;
       int r = rand() % 8;
       bool not_added = true; 

       team->set_group_no(r + 1);
       std::set<Team*> group_no;
       group_no = groups[r];

       while (not_added) {
        if (groups[r].size() != 4 && groups[r].find(*itr) == groups[r].end()) {
            groups[r].insert(*itr);
            not_added = false;
        } else {
            r = rand() % 8;
        }
       }
   }
    }

    

    for (auto i : groups) {  
        cout << "Group " << i.first + 1 << endl;
        for (auto j : i.second) {
            cout << j->get_name() << endl;
        }
        cout << endl;
    }
 
   

  //create an object that runs matches normally. Group stage and then use inheritance for quarters and semis etc (classify it as knockout for those 3 categories)
   
   std::vector<std::vector<Team*> > rankings; 
   for (auto i: groups) {
       std::vector<Team*> vc(i.second.begin(), i.second.end());
       rankings.push_back(vc);
   }


  

    cout << "Press enter to Continue" << endl;
    cin.ignore(); 

  for (int x = 1; x < 4; x++) {
    cout << "Matchday " << x << endl;
     MatchSimulator match; 
     match.runner(rankings);
     match.print_table(x,rankings);
  } 

  //create a set for each match up????

 std::vector<std::vector<Team*> > bracket_1;
 std::vector<std::vector<Team*> > bracket_2;

 for (int i = 0; i < 8; i+= 2) {
    std::vector<Team* > match_up; 
    match_up.push_back(rankings[i][0]);
    match_up.push_back(rankings[i + 1][1]);
    bracket_1.push_back(match_up);
 }

  for (int i = 0; i < 8; i+= 2) {
    std::vector<Team* > match_up; 
    match_up.push_back(rankings[i][1]);
    match_up.push_back(rankings[i + 1][0]);
    bracket_2.push_back(match_up);
 }

  

cout << "Bracket 1: " << endl;
 for (int i = 0; i < bracket_1.size(); i++) {
    cout << bracket_1[i][0]->get_name() << " vs " << bracket_1[i][1]->get_name() << endl;
 }


 cout << "Bracket 2: " << endl;
 for (int i = 0; i < bracket_2.size(); i++) {
    cout << bracket_2[i][0]->get_name() << " vs " << bracket_2[i][1]->get_name() << endl;
 }
 cout << endl;
 

KnockoutSimulator knockout; 



std::vector<Team*> winners_of_r16 = knockout.runner(bracket_1,bracket_2);

for (int i = 0; i < winners_of_r16.size();i++){
    cout << winners_of_r16[i]->get_name() << endl;
}

std::vector<std::vector<Team*> > q8_bracket_1;
std::vector<std::vector<Team*> > q8_bracket_2;

for (int i = 0; i < 8; i+= 4) {
    std::vector<Team* > match_up; 
    match_up.push_back(winners_of_r16[i]);
    match_up.push_back(winners_of_r16[i + 2]);
    q8_bracket_1.push_back(match_up);
 }

 for (int i = 1; i < 8; i+= 4) {
    std::vector<Team* > match_up; 
    match_up.push_back(winners_of_r16[i]);
    match_up.push_back(winners_of_r16[i + 2]);
    q8_bracket_2.push_back(match_up);
 }


 cout << "Q8 Bracket 1: " << endl;
 for (int i = 0; i < q8_bracket_1.size(); i++) {
    cout << q8_bracket_1[i][0]->get_name() << " vs " << q8_bracket_1[i][1]->get_name() << endl;
 }


 cout << "Q8 Bracket 2: " << endl;
 for (int i = 0; i < q8_bracket_2.size(); i++) {
    cout << q8_bracket_2[i][0]->get_name() << " vs " << q8_bracket_2[i][1]->get_name() << endl;
 }
 cout << endl;

std::vector<Team*> winners_of_q8 = knockout.runner(q8_bracket_1,q8_bracket_2);

for (int i = 0; i < winners_of_q8.size();i++){
    cout << winners_of_q8[i]->get_name() << endl;
}

std::vector<std::vector<Team*> > s4_bracket_1;
std::vector<std::vector<Team*> > s4_bracket_2;

 std::vector<Team* > match_up; 
 match_up.push_back(winners_of_q8[0]);
 match_up.push_back(winners_of_q8[2]);
 s4_bracket_1.push_back(match_up);

 match_up.clear();
match_up.push_back(winners_of_q8[1]);
match_up.push_back(winners_of_q8[3]);
 s4_bracket_2.push_back(match_up);


cout << "Semi-Final1: " << endl;
cout << s4_bracket_1[0][0]->get_name() << " vs " << s4_bracket_1[0][1]->get_name() << endl;
cout << "SemiFinal 2: " << endl;
cout << s4_bracket_2[0][0]->get_name() << " vs " << s4_bracket_2[0][1]->get_name() << endl;

std::vector<Team*> winners_of_semis= knockout.runner(s4_bracket_1,s4_bracket_2);
Team* team_1 = winners_of_semis[0];
Team* team_2 = winners_of_semis[1];

cout << "Final: " << team_1->get_name() << " vs " << team_2->get_name() << endl;
double avg_world_cup_goals_scored_pg = 1.477;
Team* winner;
Team* loser;
bool penalties;
 cout << "Press enter to Continue";
cin.ignore(); 



 double generated_team_1_expected_goals = team_1->get_attack_rating() * team_2->get_defense_rating() * avg_world_cup_goals_scored_pg;
 double generated_team_2_expected_goals = team_2->get_attack_rating() * team_1->get_defense_rating() * avg_world_cup_goals_scored_pg;

        cout << "Team 1 eX: " << generated_team_1_expected_goals << endl;
        cout << "Team 2 eX: " << generated_team_2_expected_goals << endl;


        static std::random_device rd;
        static std::mt19937 gen(rd());
        
        std::poisson_distribution<int> team_1_generator(generated_team_1_expected_goals);
        std::poisson_distribution<int> team_2_generator(generated_team_2_expected_goals);

        int goals_by_team1 = team_1_generator(gen);
        int goals_by_team2 = team_2_generator(gen);

        if (goals_by_team1 > goals_by_team2) {
            winner = team_1;
            loser = team_2;
        } else if (goals_by_team1 < goals_by_team2) {
            loser = team_1;
            winner = team_2;
        } else {
            penalties = true;
            int rand_winner = rand() % 2;
            if (rand_winner == 0) {
                winner = team_1;
                loser = team_2;
            } else{
                winner = team_2;
                loser = team_1;
            }
        }

        if (penalties) {
             cout << "Final score: " << team_1->get_name() << " " << goals_by_team1 << " : "  << goals_by_team2 << " " << team_2->get_name() << " " << endl;
             cout << winner->get_name() << " wins on pens!" << endl;
        } else {
             cout << "Final score: " << team_1->get_name() << " " << goals_by_team1 << " : "  << goals_by_team2 << " " << team_2->get_name() << " " << endl;

        }

    cout << winner->get_name() << " wins the World Cup!" << endl;













 


}
     
