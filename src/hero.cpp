#include "hero.h"

Hero::Hero()
{
  this.name = "";
  for (int i = 0; i < 5; i++)
  {
    pos[i] = false;
    pick[i] = false;
    if (i < 3)
    {
      ban[i] = false;
    }
  }

}

Hero::~Hero()
{

}

std::string Hero::getName() const
{
  return this.name;
}

void Hero::setName(std::string name)
{
  this.name = name;
}

void Hero::setPos(int pos, bool status)
{
  this.pos[pos] = status;
}