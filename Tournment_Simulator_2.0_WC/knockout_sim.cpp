#include "knockout_sim.h"
#include <iostream>
#include <random>
#include <ctime>
#include <cmath>
using namespace std;

KnockoutSimulator::KnockoutSimulator() {

}

KnockoutSimulator::~KnockoutSimulator() {


}

std::vector<Team*> KnockoutSimulator::runner(std::vector<std::vector<Team*> >& bracket1, std::vector<std::vector<Team*> >& bracket2) {
    double avg_world_cup_goals_scored_pg = 1.477;
    std::vector<Team*> winners;
    for (int i = 0; i < bracket1.size() * 2 ; i++) {
        Team* winner;
        Team* loser;
        std::vector<std::vector<Team*> > current_bracket; 
        std::vector<Team*> match_up;
        if (i  % 2 == 0) {
            current_bracket = bracket1;
        } else {
            current_bracket = bracket2;
        }
        match_up = current_bracket[ i / 2];

        Team* team_1 = match_up[0];
        Team* team_2 = match_up[1];

        cout << team_1->get_name() << " vs " << team_2->get_name() << endl;
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
        bool penalties; 
        penalties = false;
        std::string penalty_winner;
        std::string penalty_loser;
        int penalty_winner_pens;
        int penalty_loser_pens;

       


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
        penalties = false;
        winners.push_back(winner);
     
}
   return winners;

}