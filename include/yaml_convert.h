#ifndef YAML_CONVERT_H
#define YAML_CONVERT_H

#include <string>
#include <yaml-cpp/yaml.h>
#include "hero.h"

#include <iostream> //TODO: remove later

namespace YAML
{

template<>
struct convert<Hero>
{
  static bool decode(const Node& node, Hero& hero)
  {
    if (node["name"])
    {
      hero.setName(node["name"].as<std::string>());
    }
    else
    {
      // Hero has no name set
      return false;
    }

    if (node["pos"])
    {
      for (YAML::const_iterator it = node["pos"].begin(); it != node["pos"].end(); ++it)
      {
        if (it->IsScalar())
        {
          hero.setPos(it->as<int>(), true);
        }
        else
        {
          // Position is incorrectly formatted, members are not scalar
          return false;
        }
      }

      for (YAML::const_iterator it = node["pick"].begin(); it != node["pick"].end(); ++it)
      {
        if (it->IsScalar())
        {
          hero.setPick(it->as<int>(), true);
        }
        else
        {
          // Pick is incorrectly formatted, members are not scalar
          return false;
        }
      }

      for (YAML::const_iterator it = node["ban"].begin(); it != node["ban"].end(); ++it)
      {
        if (it->IsScalar())
        {
          hero.setBan(it->as<int>(), true);
        }
        else
        {
          // Pick is incorrectly formatted, members are not scalar
          return false;
        }
      }
    }
    return true;
  }
  
  static Node encode(const Hero& hero)
  {
    Node node;
    node["name"] = hero.getName();
    return node;
  }
};

}
#endif // YAML_CONVERT_H
