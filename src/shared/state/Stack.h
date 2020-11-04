// Generated by dia2code
#ifndef STATE__STACK__H
#define STATE__STACK__H

#include <stack>
#include <memory>

namespace state {
  class Zone;
  class Game;
}

#include "Zone.h"
#include "Game.h"

namespace state {

  /// class Stack - 
  class Stack : public state::Zone {
    // Associations
    // Attributes
  public:
    std::stack<std::shared_ptr<Ability>> stackContent;
    // Operations
  public:
    Stack ();
    ~Stack ();
    // Setters and Getters
  };

};

#endif