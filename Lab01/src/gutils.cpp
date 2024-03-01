#include "gutils.h"
#include <boost/core/demangle.hpp>


void gutils::handleGameObject(GameObject* gameobject)
{
    std::cout << "Rendering" << boost::core::demangle(typeid(*gameobject).name()) << std::endl;
    if( PlayerCharacter* player_character = dynamic_cast<PlayerCharacter*>(gameobject) ) 
    {
        player_character -> attack();
    }
}

void gutils::handleRenderable(Renderable* renderable)
{
    std::cout << "Drawing " << boost::core::demangle(typeid(*renderable).name()) << std::endl;
     if( PlayerCharacter* player_character = dynamic_cast<PlayerCharacter*>(renderable) ) 
    {
        player_character -> attack();
    }
}