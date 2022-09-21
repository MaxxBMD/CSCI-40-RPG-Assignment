#include<iostream>
using namespace std;


void combatMode(int &HP, int enemyHP) {
	int playerDmg = 25;
	int enemyDmg = 10;
	int choice = 0;
	string action;
	cout << "you have encoutered a Alien uh oh\n";
	while ((HP > 0) && (enemyHP > 0)) {
		cout << "you strike" << endl;
		cout << "you do " << playerDmg << "damage to the alien" << endl;
		enemyHP -= playerDmg;//player dmg affects alien hp
		cout << "the alien has " << enemyHP << "hp remaining" << endl;
		cout << "the alien strikes\n";
		HP -= enemyDmg;
		cout << "you take " << enemyDmg << " damage\n";
		cout << "you have " << HP << " Health remaining" << endl;
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
	} else {
		return;
	}

}


int main() {
	int HP = 100;
	int enemyHP = 100;


	combatMode(HP, enemyHP);

	cout << " back to exploring \n";

}

