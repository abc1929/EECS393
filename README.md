# EECS393 code guide

ClassProject1 Contains original blueprint scripts assets, kept for potential reuse
ClassProject2 is the one we're operating on.


Source/

   - *.cs are generated code for compiling
   - ClassProject2/
        ClassProject2.cpp is generated code for compiling and linking utitlies, not modified
        ClassProject2Character.cpp is generated, unused for our project, maybe we should just delete it
        ClassProject2GameMode.cpp is generated class that would contains guides overarching game behavior and world state which we have none yet.

   - ClassProject2/Private or Public
       1.*Ability* is an abstract class that guides 5 castable categories of abilities that a player controlled character has.
       2.*AbilityEffect* is not implemented yet, it would corresponds a slowing/stun/DoT etc. effect applied to a character. 
       3.*AbilityList.h* is a header file for include encapsulation 
       4.*Fireball* 
       5.*Mobility/Offensive Ability* is an abstract class that guide one category of abilities
       6.*MobilityAbility_RushBase* describes a charge ability, not fully implemented yet. It actually would represents 15 slight differnetly flavored charging forward abilities, 1.determined by a prefix calculated by *MyElementalAffinity* 
       7.*MyAutomationTestSettings* contains some unit tests 
       8.*MyCharacter* describes a basic character, it is derived from UE's ACharacter class for camera configuration. The class contains how our character is assembled using engine internals and how to react to user input, it contains basic properties like HP/Stamina, as well as encapsulating a *MyElementalAffinity* component for character behavior   
       9.*MyElementalAffinity* describes the character progression of 5 elements. It takes in character's 5 elements amount and calculate effective multiplier that buffs character's own properties as well as the abilities a character casts.
       10.*Safevolume* describes a fat cylindrical volume that player will not take damage in, the volume would shrink every 15 seconds. This is an object that is crucial to actual gameplay, as it is extremely rewarding to force your opponent outside of the safevolume. The visual representation is subject to change. 
       11.*MobilityAbility_RushBase* is not implemented yet, it should resembles *MobilityAbility_RushBase* in a parallel way
       12.*OtherClasses* are generated templates that are not used and modified currently, which might get utilized later.
