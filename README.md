# EECS393 code guide

Source/

*.cs are generated code for compiling
ClassProject2/

- ClassProject2.cpp is generated code for compiling and linking utitlies, not modified
- ClassProject2GameMode.cpp is generated class that would contains guides overarching game behavior and world state which we have none yet.

ClassProject2/Private or Public

1. *Ability* is an abstract class that guides 5 castable categories of abilities that a player controlled character has.
2. *AbilityEffect* is an abstract class, it would corresponds a slowing/stun/DoT etc. effect applied to a character. 
3. *AbilityList.h* is a header file for include encapsulation 
4. *Fireball* is a self explanatory ability that is one of the basic ability. It fires a projectile that knocks back inflicted target.
5. *xxx Ability* is an abstract class that guide one category of abilities
6. *MobilityAbility_RushBase* describes a charge ability that deals dmg and knocksback inflicted target, partially implemented. It would represents 15 slight differnetly flavored charging forward abilities, determined by prefixes calculated by *MyElementalAffinity* of the caster.
11. *OffensiveAbility_WaveBase* is the basic offensive ability, it should resembles *MobilityAbility_RushBase* in a parallel way
7. *MyAutomationTestSettings* contains some unit tests 
8. *MyCharacter* describes a basic character, it is derived from UE's ACharacter class for camera configuration. The class contains how our character is assembled using engine internals and how to react to user input, it contains basic properties like HP/Stamina, as well as encapsulating a *MyElementalAffinity* component for character behavior. It has the ability to casts 5 different abilities, with one basic abilities determined passively, and one of each from *Offensive/Defensive/Mobility/Utility Abilities*.
9. *MyElementalAffinity* describes the character progression of 5 elements. It takes in character's 5 elements amount and calculate effective multiplier that buffs character's own properties as well as the abilities a character casts.
10. *Safevolume* describes a fat cylindrical volume that player will not take damage in, the volume would shrink every 15 seconds. This is an object that is crucial to actual gameplay, as it is extremely rewarding to force your opponent outside of the safevolume. The visual representation is subject to change. 
4. *xxx_Effect* would be the residual effects logics applied to target by an *Ability*.
12. *OtherClasses* are created skeletons that are not used and modified currently, which might get utilized later, or it might be created considering scalability and not yet utilized.



Assets made with Unreal Editor is located at: \Content\ThirdPersonCPP
- The asset content can be requires Unreal Editor to be viewed. 
