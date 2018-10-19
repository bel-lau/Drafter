
#ifndef DRAFTER_HERO_H
#define DRAFTER_HERO_H

#include <string>

class Hero
{

  private:
    std::string name;
    bool pos[5];
    bool pick[5];
    bool ban[3];

  public:
    Hero();

    ~Hero();

    std::string getName() const;

    void setName(std::string name);
    void setPos(int pos, bool status);
};

#endif //DRAFTER_HERO_H
