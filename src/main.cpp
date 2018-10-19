#include <yaml-cpp/yaml.h>
#include <iostream>
#include <string>
#include "hero.h"
#include "yaml_convert.h"

int main(int argc, char ** argv)
{

  YAML::Node mirana = YAML::LoadFile("/home/lbell/Drafter/config/heroes/mirana.yaml");

  if (mirana["name"])
  {
    std::cout << "Name: " << mirana["name"].as<std::string>() << std::endl;
  }

  Hero hero_mirana;
  hero_mirana = mirana.as<Hero>();

  std::cout << "Name: " << hero_mirana.getName() << std::endl;



  return 0;

}
