# EECS393

Current goals of implementation
Rewriting project blueprint classes in C++, current progress percentage roughly
---
In Descending Priority Roughly

1. Ability abstract class -> spell types -> individual spells (more necessary as we create more abilities)
2. Character Progression system: Character has subalignment(Mage, Melee, not implemented yet) and "Element affinity",together augments spells directly as well as what spell one can get, maybe I'll throw in more
3. Game Rules - actually implement 7 rounds, inbetween rest time to progress character, and determine winner, all that
4. HUD/UI - drawing HP/Stamina Bars, crosshair, casting progress bar, main menu, in game esc menu, tool tip, round info, misc popup, more

Specifications
---
Ability(contains visual, life cycle. hit mechanics/movement component, onhit event, owner, abilityeffectlist)
  - maybe a raytracing and target system needed, for instant cast and the game itself's sake
Abilityeffectlist(contains list of procedurally processed effect on hit target, resolves on itself, no info needed passing from ability, this is not implemented yet.)

Abilityeffect(contains info how to resolve the effect, maybe visual here as well)
  - dot, slow, stun etc
  - dmg and knockback would get encapsulated later. Make specific abilities leaner.

all of those need modifiers and augments from owner, namely his elemental affinity

World state
  - char state
    - level? (maybe we don't need this)
    - elemental affinity (maybe make it slider, floats rather than int)
      - modifying char attributes
      - modifying ability (passing through)
  maybe no need to rush game rules



goals (Outdated)
---
Arena
- flat space with dome (force field) enclosing it (a soft boundary); exiting this dome out of the arena would cause dmg to the character per unit time (see WC3 Warlock)
- A timer associated with the game, the dome shall be smaller throughout time (forcing game to end in a way, think h1z1)
- environment objects
  - pillars;covers
  - elevation;plateau;ramp;
  - etc.

Game elements
- we can have some characters to choose from (think overwatch, MOBAs)
  - We should have basic attack (melee/ranged basic knocking back/with dmg, also see WC3 Warlock)
    - game should stress keeping opponent out of the force field to take prime dmg rather than hitting them to deal dmg.
    more actions; more movements; this shall be a fast paced game
  - We should have customizable actives and passive skills (see WC3 Warlock)
    - Skill shots and environment utilization are where the primary skillcap is at
    - also think abilities that might change how a game is played
    like placing a stationary sigil on the ground and you could press a button to teleport to it. 


game format
- we shall treat this as a online competitive pvp game
  - FFA
    - game ends when there is one character alive
  - Team VS
    - game ends when there is no alive character in one team
  - 1v1
    - well.. 
  
UI
- see pretty much any single player game out during 2015-16; clean looks 

Assets
- IDK, we're not making arts, just ignore this for now.
  
