# Fantasy Combat Tournament

This game is a one-user-two-player game, so one user should be able to play setup fighters for both teams. For simplicity, we will call the order of fighters in each team “lineup”, like a batting order in baseball or softball.

The flow of gameplay is as follows:

At the start of the tournament, the user is prompted to enter the number of fighters for both teams. After that, for each fighter, the game asks the user to choose the type of character, and enter a name for the fighter. For example: assume the user chooses Harry Potter for player No.1’s team lineup, the user can name the Harry Potter character “Larry Snotter” or just “Harry Potter No.1”. The game allows more than 1 of the same character for team lineups. For example, Team A has 3 members: 2 barbarians and 1 Harry Potter. The order of the lineup is the same as the order user entered.

After the user supplied the lineup of fighters in order, for Team No.1, and Team No.2, the tournament starts. In the tournament, the fighter at the head/front of each lineup will battle. The winner of each fight gets put at the back of their lineup, while loser goes to the top of the loser container.

If a fighter won, it may have taken damage, so the game restores 20% of their current health when they get back in line.

The lineup order cannot be changed, meaning that the game cannot modify the order of the lineup except when putting winner at the back of lineup and loser at the top of the loser container.

The tournament finishes when one of the team does not have any more fighters to fight. When the game ends, the result of the game is printed, and users have the choice to display the contents of the loser pile. More information is shown below in the menu section.

## Combat System

Each combat between 2 characters ends when one of the characters die.

Each round consists of two attacks, one for each character. For each attack, attacker and defender both generate dice rolls. The type and number of dice for each character is listed below.

The actual damage inflicted from the attacker onto the defender is calculated as follows:

Damage = attacker’s roll – defender’s roll – defender’s armor

Then the value of that damage is subtracted from the defender’s strength points.


Example: 
```
Character A attacks with dice roll of: 8 10, which means it has an attack of 18,
and character B defends with dice roll of 5 6, which means it has defense of 11,
character B also has an armor of 3. So the actual damage inflicted from A to B
is 18 – 11 – 3 = 4.

If character B has strength point of 8 during that round, the new strength point
would be 8 – 4 = 4, which means next round B will have strength point of 4.

If character B has strength point of 3 during that round, the new strength point 
would be 3 – 4 = -1, which means character B dies.
```

## Characters

Note: “1d12” means rolling one 12-sided die, and “2d6” means rolling 2 6-sided dice, etc.

### Vampire
```
Attack: 1d12
Defense: 1d6
Armor: 1
Strength Points: 18
Special Ability: Charm - Vampires can charm an opponent into not attacking. 
For a given attack there is a 50% chance that their opponent does not actually attack them.
```

### Barbarian
```
Attack: 2d6
Defense: 2d6
Armor: 0
Strength Points: 12
Special Ability: None
```

### Blue Men
```
Attack: 2d10
Defense: 3d6
Armor: 3
Strength Points: 12
Special Ability: Mob - Blue Men are actually a swarm of small individuals. 
For every 4 points of damage, they lose one defense die. 
For example, if they have a strength of 8, they would have 2d6 for defense.
```

### Medusa
```
Attack: 2d6
Defense: 1d6
Armor: 3
Strength Points: 8
Special Ability: Glare - If a Medusa rolls a 12 when attacking then the target 
instantly gets turned into stone and Medusa wins! If Medusa uses Glare on Harry Potter 
on his first life, then Harry Potter comes back to life.
```

### Harry Potter
```
Attack: 2d6
Defense: 2d6
Armor: 0
Strength Points: 10/20
Special Ability: Hogwarts - If Harry Potter's strength reaches 0 or below, 
he immediately recovers and his total strength becomes 20. If he were to die 
again, then he’s dead.
```

### Notes

    If Medusa uses “glare” on Harry Potter on his first life, 
    then Harry Potter comes back to life after using “hogwarts”.
    
    If the Vampire’s “charm” ability activates when Medusa uses “glare”, 
    the Vampire’s charm trumps Medusa’s glare.

## Installing and Running the Program

Compile the program with this command:

```
make tournament
```

Run the program with this command:

```
./tournament
```

Clean files with this command:

```
make tournament
```

## Built With

* C++
