#ifndef TEAMPARSER_H
#define TEAMPARSER_H
#include "team.h"

struct ParserError : public std::runtime_error
{
    ParserError(const char* what) : std::runtime_error(what) {}
};

class TeamParser {
  public: 
   TeamParser();
   ~TeamParser();
   void parse(std::string db_filename,std::set<Team*>& teams, std::vector<Team*>& sorted_teams);
};

#endif 

