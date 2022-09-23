#include<iostream>
#include<cstdlib>
using namespace std;


int combatRNG(int dmg){
	int	y = rand() % 10;
	if (y < 2)
		return (dmg + (dmg * 0.3));//20% crit of +30% damage
	else if (y < 3)
		return (dmg = 0);//10% miss rate
	// all part of simple damage deviation so basiccaly rest is 70%
	if (y < 4)
		return (dmg + 2);

	if (y < 5)
		return (dmg - 5);

	if (y < 6)
		return (dmg + 7);

	if (y < 6)
		return (dmg + -2);

	if (y <9)
		return (dmg + 4);
	else
		return(0);
}


void combatMode(int &HP) {
	int playerDmg = 15;
	int enemyDmg = 15;
//	int newPlayerDmg = combatRNG(playerDmg);
//	int newEnemyDmg = combatRNG(enemyDmg);
	int enemyHP = 100;
	string action;
	cout << "you have encoutered a Alien uh oh\n";
	while ((HP > 0) && (enemyHP > 0)) {
		cout << "you strike\n";
		enemyHP -= combatRNG(playerDmg);//player dmg affects alien hp
		cout << "you do " << combatRNG(playerDmg) << " damage to the alien\n";
		if (enemyHP<=0){
			break;
		}
		cout << "the alien has " << enemyHP << "hp remaining\n";
		cout << "the alien strikes\n";
		HP -= combatRNG(enemyDmg);	
		if (HP <= 0) {
			break;
		}
		cout << "you take " << combatRNG(enemyDmg) << " damage\n";
		cout << "you have " << HP << "hp remaining\n";
		cout << "attempt to flee by pressing q or any other key to continue\n";
		cin >> action;
		if (action == "q") {
			break;
		}		
	}
	if (HP <= 0) {
		cout << "you died rip \n";
		exit(0);
		}
	else if (enemyHP <= 0) {
		cout << " you killed the alien good job\n";
		return;
		}
}

int main() {
	int HP = 100;
	int enemyHP = 100;

	srand(time(NULL));

	combatMode(HP);

	cout << " back to exploring \n";

}

