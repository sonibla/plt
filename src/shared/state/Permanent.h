// Generated by dia2code
#ifndef STATE__PERMANENT__H
#define STATE__PERMANENT__H

#include <map>
#include <list>
#include <string>

namespace state {
  class TriggeredAbility;
  class PlayableGameElement;
  class ActivatedAbility;
  class Cost;
}

#include "TriggeredAbility.h"
#include "PlayableGameElement.h"
#include "ActivatedAbility.h"
#include "Cost.h"

namespace state {

  // Interface
  /// class Permanent - 
  class Permanent : public state::PlayableGameElement {
    // Associations
    // Attributes
  public:
    std::map<Cost,ActivatedAbility> activatedAbilites;
    std::list<TriggeredAbility> triggeredAbilites;
    bool tapped     = false;
    int strength     = 0;
    int toughness     = 0;
    std::string image_uri;
    // Operations
  public:
    bool Tap ();
    bool IsDead ();
    // Setters and Getters
  };

};

#endif
