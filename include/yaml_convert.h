#ifndef YAML_CONVERT_H
#define YAML_CONVERT_H

#include <string>
#include <yaml-cpp/yaml.h>
#include "hero.h"

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
      return false;
    }

    if (node["pos"])
    {
      for (YAML::Node::const_iterator it = node["pos"].begin(); it != node["pos"].end(); it++)
      {
      	if (it->first.IsScalar())
      	{
      	  hero.setPos(it->first.as<int>(), true);
      	}
      }
    }

  }
  
  static Node encode(const Hero& hero)
  {
    Node node;
    node["name"] = hero.getName();
  }
};

}
#endif // YAML_CONVERT_H
