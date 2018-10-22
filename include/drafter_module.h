
#ifndef DRAFTER_DRAFTER_MODULE_H
#define DRAFTER_DRAFTER_MODULE_H

#include <yaml-cpp/yaml.h>
#include <string>
#include <fstream>
#include "hero.h"
#include "yaml_convert.h"

#include <iostream>

class DrafterModule
{

  private:
    std::string package_path;
    int num_heroes;
    Hero heroes[200];

    bool checkFile(std::string file);
    void parseHeroes(YAML::Node heroes);
    bool initHero(std::string hero_file, int hero_count);

  public:
    DrafterModule();

    ~DrafterModule();

};

#endif //DRAFTER_DRAFTER_MODULE_H