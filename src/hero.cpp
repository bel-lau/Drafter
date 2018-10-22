#include "hero.h"

Hero::Hero()
{
  this->name = "";
  for (int i = 0; i < 5; i++)
  {
    this->pos[i] = false;
    this->pick[i] = false;
    if (i < 3)
    {
      this->ban[i] = false;
    }
  }

}

Hero::~Hero()
{

}

std::string Hero::getName() const
{
  return this->name;
}

bool Hero::isPos(int pos)
{
	return this->pos[pos-1];
}

void Hero::setName(std::string name)
{
  this->name = name;
}

void Hero::setPos(int pos, bool status)
{
  this->pos[pos-1] = status;
}

void Hero::setPick(int pick, bool status)
{
  this->pick[pick-1] = status;
}

void Hero::setBan(int ban, bool status)
{
  this->ban[ban-1] = status;
}