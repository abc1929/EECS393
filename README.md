# EECS393



Current goals of implementation
---
1. ☐ make arena, just flat ground with shrinking force field (we could worry about the visual of it later) associated with time 
2. ☐ make a ragdoll character controlled by a single player with hp and movements (kinda given by UE4)
3. ☐ make a punchbag ragdoll dummy enemy with hp
4. ~~make a basic melee punch skill that deals minor dmg and knockback whoever is hit a bit.~~
4. ☑ Ranged projectile made
5. ☐ everything with hp shall take dmg constantly while in force field









Some goals (or how the game is foreseen)
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
  
