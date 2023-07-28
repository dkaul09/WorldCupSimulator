#ifndef MATCHSIMULATOR_H
#define MATCHSIMULATOR_H
#include <iostream>
#include <string>
#include "player.h"
#include "team.h"
#include <set>
#include <map>



class MatchSimulator {

    public:
     MatchSimulator();// what should it take? All groups but process two at the same time for a matchday

     ~MatchSimulator();

     void runner(std::vector<std::vector<Team*> >&groups);//void for now but we can readjust soon

     void table_sorter(std::vector<Team*>& group);

     void print_table(int matches_played,std::vector<std::vector<Team*> > groups);

};

#endif
