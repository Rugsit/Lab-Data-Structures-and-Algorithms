#include <iostream>
#include <cmath>
using namespace std;
typedef struct hero {
  string name;
  int healt, attack, defense;
  int energy, time;
  double xAttack, xDefense;
} Hero;

void heroFight(Hero, Hero);
int main() {
  string name; int currentEnergy1 = 0, turn = 0; int currentEnergy2 = 0;
  Hero hero1, hero2;
  cin >> hero1.name >> hero1.healt >> hero1.attack >> hero1.defense >> hero1.energy;
  cin >> hero1.xAttack >> hero1.xDefense >> hero1.time;
  cin >> hero2.name >> hero2.healt >> hero2.attack >> hero2.defense >> hero2.energy;
  cin >> hero2.xAttack >> hero2.xDefense >> hero2.time;
  while (hero1.healt > 0 && hero2.healt > 0) {
    if (hero1.healt <= 0) {
      cout << hero2.name << " is victorious" << endl;
    }
    player1Attack(hero1, hero2, currentEnergy1);
    turn++;

    if (hero2.healt <= 0) {
      cout << hero1.name << " is victorious" << endl;
    }
    player2Attack(hero1, hero2, currentEnergy2);
    turn++;
  }
  cout << "The battle took " << turn << " turn(s)"
  return 0;
}

void player1Attack(Hero &hero1, Hero &hero2, int &currenEnergy1) {
  int attack = hero1.xAttack * hero1.attack;
  int defense = hero1.xDefense * hero1.defense;
  if (currenEnergy1 == hero1.energy) {
    attack *= 2;
  } else {
    currenEnergy1 += 1;
  } 
  int dmg = attack / defense; 
  hero2.healt -= dmg; 
  hero1.time -= 1;
}

void player2Attack(Hero &hero1, Hero &hero2, int &currenEnergy2) {
  int attack = hero2.xAttack * hero2.attack;
  int defense = hero2.xDefense * hero2.defense;
  if (currenEnergy2 == hero2.energy) {
    attack *= 2;
  } else {
    currenEnergy2 += 1;
  } 
  int dmg = attack / defense; 
  hero1.healt -= dmg; 
  hero2.time -= 1;
}
