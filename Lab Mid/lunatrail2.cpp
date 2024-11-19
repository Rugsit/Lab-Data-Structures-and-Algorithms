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
  string name;
  Hero hero1, hero2;
  cin >> hero1.name >> hero1.healt >> hero1.attack >> hero1.defense >> hero1.energy;
  cin >> hero1.xAttack >> hero1.xDefense >> hero1.time;
  cin >> hero2.name >> hero2.healt >> hero2.attack >> hero2.defense >> hero2.energy;
  cin >> hero2.xAttack >> hero2.xDefense >> hero2.time;
  heroFight(hero1, hero2);
  return 0;
}

void heroFight(Hero hero1, Hero hero2) {
  int turn = 0; 
  int hero1Energy = 0, hero2Energy = 0, dmg;
  while (hero1.healt > 0 && hero2.healt > 0) {
    if (turn % 2 == 0) {
      if (hero1Energy == hero1.energy) {
        hero1Energy = 0;
        dmg = pow(int(hero1.attack * hero1.xAttack * 2), 2) / int(hero2.defense * hero2.xDefense);
      } else {
        dmg = pow(int(hero1.attack * hero1.xAttack), 2) / int(hero2.defense * hero2.xDefense);
        hero1Energy++;
      } 
      hero2.healt -= dmg;
      hero1.time--;
      if (hero1.time == 0) {
       hero1.xAttack = 1;
       hero1.xDefense = 1;
      }
    } else {
      if (hero2Energy == hero2.energy) {
        hero2Energy = 0;
        dmg = pow(int(hero2.attack * hero2.xAttack * 2), 2) / int(hero1.defense * hero1.xDefense);
      } else {
        dmg = pow(int(hero2.attack * hero2.xAttack), 2) / int(hero1.defense * hero1.xDefense);
        hero2Energy++;
      }
      hero1.healt -= dmg;
      hero2.time--;
      if (hero2.time == 0) {
        hero2.xAttack = 1;
        hero2.xDefense = 1;
      }
    }
    turn++;
    // cout << dmg << endl;
  }

  if (hero1.healt <= 0) cout << hero2.name << " is victorious" << endl;
  else if (hero2.healt <= 0) cout << hero1.name << " is victorious" << endl;
  cout << "The battle took " << turn << " turn(s)" << endl;
}