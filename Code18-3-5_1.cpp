#include <string>
class ZooAnimal;
class Bear;
class Raccoon;
class Endangered;
class Panda;
Bear::Bear(std::string name, bool onExhibit):
    ZooAnimal(name, onExhibit, "Bear") {}
Raccoon::Raccoon(std::string name, bool onExhibit):
    ZooAnimal(name, onExhibit, "Raccoon") {}
Panda::Panda(std::string name, bool onExhibit):
    ZooAnimal(name, onExhibit, "Panda"),
    Bear(name, onExhibit),
    Raccoon(name, onExhibit),
    Endangered(Endangered::critical),
    sleeping_flag(false) {}