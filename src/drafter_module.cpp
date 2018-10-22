#include "drafter_module.h"

DrafterModule::DrafterModule()
{
  std::cout << "Drafter module constructing\n";
  std::string filename = "config/config.yaml";
  if (!checkFile(filename))
  {
    // File does not exist, exit module construction
    return;
  }

  YAML::Node config = YAML::LoadFile(filename);

  if (config["number_of_heroes"])
  {
    this->num_heroes = config["number_of_heroes"].as<int>();
  }
  
  if (config["heroes"])
  {
    parseHeroes(config["heroes"]);
  }
}

DrafterModule::~DrafterModule()
{

}

bool DrafterModule::checkFile(std::string file)
{
  std::ifstream infile(file.c_str());
  return infile.good();
}

void DrafterModule::parseHeroes(YAML::Node heroes)
{
  int count = 0;
  std::string hero_file = "";
  for (YAML::const_iterator it = heroes.begin(); it != heroes.end(); ++it)
  {
    hero_file = "config/heroes/" + it->as<std::string>() + ".yaml";
    std::cout << hero_file << std::endl;
    if (!initHero(hero_file, count))
    {
      // Hero initialization failed. Panic?
    }
    count++;
  }
}

bool DrafterModule::initHero(std::string hero_file, int hero_count)
{
  if (!checkFile(hero_file))
  {
    // File does not exist, exit hero initialization
    return false;
  }
  YAML::Node hero = YAML::LoadFile(hero_file);

  this->heroes[hero_count] = hero.as<Hero>();

  return true;
}