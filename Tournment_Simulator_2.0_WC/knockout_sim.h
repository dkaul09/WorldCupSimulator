#ifndef KNOCKOUTSIM_H
#define KNOCKOUTSIM_H
#include "match_simulator.h"


class KnockoutSimulator: public MatchSimulator {
    public:
     KnockoutSimulator();
     ~KnockoutSimulator();
     std::vector<Team*> runner(std::vector<std::vector<Team*> >& bracket1, std::vector<std::vector<Team*> >& bracket2);//void for now but we can readjust soon

};


#endif