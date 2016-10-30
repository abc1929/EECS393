# EECS393

---
Current goals of implementation ☐☑
--- 
Rewriting project blueprint classes in C++, current progress percentage roughly
1. ☐ Mage -> MyCharacter, 50%
  to do: Sprint & stamina consumption, jump stamina consumption, other misc.
2. ☐ Fireball, 60%
  to do: explosion effect on hit, knock back logic
3. ☐ Safezone, 0%
  to do: basic construction ,shrink logic, damage per tick logic
4. ☐ HUD, 0 %
  to do: drawing HP/Stamina Bars, crosshair, casting progress bar
5. ☐ UI, 0 %
  to do: main menu, in game esc menu





goals
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
  
