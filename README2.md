# EECS393

Current goals of implementation

code coverage: we might test via this:
https://opencppcoverage.codeplex.com/

getting coverage from unit tests might be a bit difficult since we're not operating on Visual studio's unit test solutions but rather the UE4 inner unit test solution.

I think it is valid to test coverage via running the executable directly if possible that is pertaining towards functional testings.

Current implementation goals (works before functional test demo)
I'll provide sources as much as I can
---
JD:

1. HUD implementations: flesh it up, we shall have a skill bar take tracks our 4 abilities CDs, as well as the basic ability CD
  we need a tooltip system, UI part of the targeting system. We need nameplates and HP bars drawn on characters heads
2. Menu: nothing particularly, but we do need a multiplayer module part in the menu
3. Networking: we shall start with a local two person multiplayer, we would then do a lan thing.

JW:

1. Create a base defensive (highly morphable like rushbase, wavebase) and a utility ability
2. Targeting system: ray casting, maybe something like a smart soft lock on.
3. momentum accumulation value (another attribute to characters, it's like current vulnerability value, decreases overtime)
4. something else 




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
  
