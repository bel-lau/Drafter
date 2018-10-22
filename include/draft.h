
#ifndef DRAFTER_DRAFT_H
#define DRAFTER_DRAFT_H

#include <string>
#include "hero.h"

class Draft
{

  private:
    std::string draft_name;
    std::string radiant_name;
    std::string dire_name;
    bool radiant_first;

    Hero* radiant_bans[6];
    Hero* dire_bans[6];

    Hero* radiant_picks[5];
    Hero* dire_bans[5];

  public:
    Draft();

    ~Draft();

};

#endif //DRAFTER_DRAFT_H