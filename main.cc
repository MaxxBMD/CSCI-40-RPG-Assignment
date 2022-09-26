//Fill out this comment with your names and which bullet points you did
//Partners: Herbart Hernandez, Rene Hernandez, Ayden Messick, Allesandra Orozco-Newton, Brandon Sam
//Bullet Points: world map, combat, colors, puzzles, (amount of dialogue not counted yet)
//Extra Credit:	soundtrack/art
//URL to cover art and music: https://youtu.be/39IdvNnUgRA
#include "/public/read.h"
#include "/public/colors.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cctype>
using namespace std;
using map_t = vector<vector<char>>;


map_t map0 = {
	{'*', '*', '*', '*', '*', '*', '*', '*', '*', '*'}, // jail cell
	{'*', ' ', ' ', '*', ' ', '*', 'A', ' ', 'P', '1'},// part 1
	{'*', ' ', ' ', ' ', ' ', '*', ' ', '*', '*', '*'},
	{'*', '*', '*', '*', ' ', '*', ' ', ' ', 'H', '*'},
	{'*', ' ', ' ', '*', ' ', '*', ' ', ' ', ' ', '*'},
	{'*', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', '*'},
	{'*', '*', '*', '*', ' ', '*', 'i', ' ', ' ', '*'},
	{'*', ' ', ' ', '*', ' ', '*', '*', '*', ' ', '*'},
	{'*', ' ', ' ', ' ', ' ', ' ', 'r', ' ', ' ', '*'},
	{'*', '*', '*', '*', '*', '*', '*', '*', '*', '*'}
};
map_t map1 = {
	{'*', '*', '*', '*', '*', '*', '*', '*', '2', '*'},// storage room
	{'0', ' ', ' ', ' ', ' ', ' ', 'H', '*', ' ', '*'},// part 2
	{'*', 'A', '*', ' ', '*', ' ', '*', '*', 'P', '*'},
	{'*', ' ', '*', ' ', '*', 'A', '*', '*', ' ', '*'},
	{'*', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', '*'},
	{'*', ' ', '*', ' ', '*', 'A', '*', ' ', 'A', '*'},
	{'*', ' ', '*', ' ', '*', ' ', '*', ' ', ' ', '*'},
	{'*', ' ', '*', 'A', '*', ' ', '*', '*', ' ', '*'},
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
	{'*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
};



map_t map2 = {
	{'*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},// main hall
	{'*', '*', ' ', '*', '*', '*', 'H', '*', 'A', '*'},// part 3
	{'*', '*', 'A', ' ', '*', 'A', ' ', '*', ' ', '*'},
	{'*', ' ', ' ', 'A', '*', ' ', ' ', ' ', ' ', '*'},
	{'*', 'A', ' ', ' ', 'P', ' ', 'A', ' ', ' ', '*'},
	{'3', ' ', ' ', ' ', '*', 'A', ' ', 'A', ' ', '*'},
	{'*', 'i', ' ', ' ', '*', ' ', ' ', ' ', ' ', '*'},
	{'*', '*', 'A', ' ', '*', 'A', ' ', '*', ' ', '*'},
	{'*', '*', ' ', '*', '*', '*', ' ', '*', ' ', '*'},
	{'*', '*', '*', '*', '*', '*', '*', '*', '1', '*'},
};


map_t map3 = {
	{'*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},// the lab
	{'*', 'H', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*'},// part 4
	{'*', ' ', 'A', ' ', '*', '*', ' ', 'A', '*', '*'},
	{'*', '*', '*', ' ', ' ', 'A', ' ', ' ', ' ', '*'},
	{'4', ' ', 'P', ' ', 'A', ' ', ' ', ' ', ' ', '*'},
	{'*', '*', '*', ' ', '*', '*', 'A', ' ', ' ', '2'},
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
	{'*', 'A', '*', 'A', ' ', ' ', ' ', ' ', '*', '*'},
	{'*', 'i', '*', ' ', '*', '*', ' ', ' ', '*', '*'},
	{'*', '*', '*', '*', '*', '*', '*', '*', '*', '*'}
};
map_t map4 = {
	{' ', ' ', ' ', ' ', ' ', '*', '*', '*', '*', '*'},// the command center
	{' ', ' ', ' ', ' ', '*', 'A', ' ', ' ', ' ', '*'},// part 5
	{' ', ' ', ' ', '*', 'A', 'A', ' ', 'A', 'H', '*'},
	{' ', '*', '*', 'A', ' ', ' ', ' ', '*', '*', '*'},
	{'*', 'P', 'A', ' ', 'A', '*', ' ', ' ', ' ', '3'},
	{'*', ' ', 'A', ' ', ' ', '*', 'A', ' ', 'A', '*'},
	{' ', '*', '*', 'A', ' ', ' ', ' ', '*', '*', '*'},
	{' ', ' ', ' ', '*', 'A', 'A', ' ', '*', 'H', '*'},
	{' ', ' ', ' ', ' ', '*', 'A', ' ', '|', ' ', '*'},
	{' ', ' ', ' ', ' ', ' ', '*', '*', '*', '5', '*'}
};
vector<map_t> theMaps{map0, map1, map2, map3, map4};
int currentMap = 0;


const int ROWS = map0.size();
const int COLS = map0.at(0).size(); //MAKE SURE ALL ROWS ARE THE SAME SIZE OR BAD TIMES

void print_map(const map_t &map, int player_row, int player_col) {

	clearscreen();
	movecursor(3, 0);//offset from top left

	for (int i = 0; i < map.size(); i++) {
		for (int j = 0; j < map.at(0).size(); j++) {
			//traverses the entire array using two loops
			if (i == player_row && j == player_col) {
				//if we are on the player's position, draw an @
				cout << '@' << " " << RESET;;
			} else {
				//otherwise, set a color based on what tile we're looking at...
				switch (map.at(i).at(j)) {
				case '*':
					setcolor(100, 50, 100);
					break;
				case 'H':
					//healthpack
					cout << GREEN;
					break;
				case 'A':
					//alien
					setcolor(20, 0, 21);
					break;
				case 'r':
				case 'i':
					//ammo
					cout << YELLOW;
					break;
				case '0':
				case '1':
				case '2':
				case '3':
				case '4':
				case '5':
					cout << CYAN;
					break;
				}

				//...and then draw that tile (then reset color)
				cout << map.at(i).at(j) << " " << RESET;
			}
		}
		cout << endl;//end of the row

	}
}


char get_world_location(size_t row, size_t col) {
	if (row >= theMaps.at(currentMap).size()) return ' ';
	if (col >= theMaps.at(currentMap).at(row).size()) return ' ';
	return theMaps.at(currentMap).at(row).at(col);
}


void set_world_location(size_t row, size_t col, char c) {
	if (row >= theMaps.at(currentMap).size()) return;
	if (col >= theMaps.at(currentMap).at(row).size()) return;
	theMaps.at(currentMap).at(row).at(col) = c;
}



void cutsceneTime(int cutsceneNum) {
	//cutscene 1 - intro
	//cutscene 2 - outro

	clearscreen();
	movecursor(0, 0);

	if (cutsceneNum == 1) {
		//game intro
		cout << "You wake up to the blaring ring of an alarm and a message broadcasting in a language of hoarse squeals and guttural noises you do not understand.\n";
		cout << "Covering your ears and turning away from the flashing neon green bars of light arranged like a cage around your feeble, frail human body,\nyou remember how you got here: you were captured.\n";
		cout << "Captured by alien invaders as you ran toward the evacuation site and thrown in a prison cell composed of lasers.\n";
		cout << "Lasers that scorched right through the strands of hair you ripped from your head and placed in their path to learn just how hopeless your situation was.\n";
		cout << "As the memories come back, you hear the buzz of the lasers begin to fade away. You open your eyes to see your cage has disappeared.\n";
		cout << "The alarm message must be something about a power outage. You don’t take more than a couple seconds to decide you must seize this opportunity.\n";
		cout << "You begin to walk toward the door that you presume leads you out of this prison.\n";
		cout << endl << "Use the arrow keys to reach the door and escape.\n";
		int x = 0;
		cin >> x;
		//sleep(2);
	}

	else if (cutsceneNum == 2) {
		clearscreen();
		cout << "You escaped. The world around you is unfamiliar. This is not earth." << endl;
		cout << "THE END" << endl;
		set_raw_mode(true);
		show_cursor(true);
		exit(0);
	}


	cout << "press any key to continue" << endl;
	int x = quick_read();//like cin >> x, but faster
	//program does not proceed until player input.


	return;//exits the function and resumes right where we were in main

}


void die() {
	cout << "BAD INPUT" << endl;
	exit(1);
}


int gunAmmo = 0;


int randDialogue() {
	int theRand = ((rand() / 100) % 4);
	if (theRand == 4)
		return 4;
	else if (theRand == 3)
		return 3;
	else if (theRand == 2)
		return 2;
	else return 1;
	//1-4



}

void Combat_mode(int& HP) {

	clearscreen();
	show_cursor(true);
	set_raw_mode(false);
	int enemyHP = 85;


	//possible todo: vectors of strings. each containing dialogue lines for the same action. pick one at random.



	vector<string> attackLinesMelee{"You attack the alien.", "You swing your knife at the alien.", "You thrust your knife fowards, aiming directly for the alien.", "You strike the alien."};
	vector<string> attackLinesRange{"You fire your blaster at the alien.", "You fire a shot at the alien.", "A bolt of blasma shoots out of your blaster towards the alien.", "You pull the trigger on your blaster"};
	vector<string> attackOpener{"Suddenly, an alien reveals itself before you!", "Out of nowhere, an alien jumps out at you!", "Suddenly, you trip and fall. Turns out, an alien was camoflaged underneath you!", "The floor and walls before you begin shifting. It's an alien!"};

	movecursor(0, 0);
	cout << attackOpener.at(randDialogue()) << endl;;
	while ((HP > 0) && (enemyHP > 0)) {



		srand(time(NULL));
		int rand1 = (rand() % 40) + 20;;
		int rand2 = (rand() % 30) + 10;


		int alien_blaster = rand1;
		int enemyDmg = rand2;
		int newplayerDmg = alien_blaster;;
		int newenemyDmg = enemyDmg;
		string action;


		//	movecursor(0, 0);

		cout << RED << "Alien HP: " << enemyHP << WHITE <<  " | "  << GREEN << "Human HP " << HP <<  endl;
		resetcolor();



		cout << "What will you do?\nMELEE - 1\t RANGED(" << gunAmmo <<  ") - 2" << endl;
		usleep(100000);


		cin.clear();

		char playerChoice = '0';
		cin >> playerChoice; //this is not working1!
//		getline(cin, playerChoice);


		cout << playerChoice << endl;

		assert(playerChoice == '1' || playerChoice == '2');

		if (playerChoice == '1') {
			//melee
			cout << attackLinesMelee.at(randDialogue());
			newplayerDmg = alien_blaster; //holds the random value

			enemyHP -= newplayerDmg;//player dmg affects alien hp
			cout << "You do: " << CYAN << alien_blaster + 15;
			resetcolor();
			cout << " damage to the alien\n";
			newplayerDmg = alien_blaster;// resets the random value to the deafault dmg
		} else if (playerChoice == '2') {
			//ranged
			if (gunAmmo > 0) {
				cout << "BANG! ";
				newplayerDmg = alien_blaster + 30; //holds the random value
				gunAmmo--;

				cout << attackLinesRange.at(randDialogue()) << endl;
				enemyHP -= newplayerDmg;//player dmg affects alien hp
				cout << "You do: " << CYAN << alien_blaster;
				resetcolor();
				cout << " damage to the alien\n";
				newplayerDmg = alien_blaster;// resets the random value to the deafault dmg
			} else {
				cout << "*CLICK!*\nYour blaster is our of ammunition!" << endl;
			}

		}


		if (enemyHP <= 0) {
			cout << RED << "Alien HP: " << enemyHP << WHITE <<  " | "  << GREEN << "Human HP " << HP <<  endl;
			cout << CYAN << "You killed the alien!\n" << RESET;
			usleep(125000);
			//cout << "Press any key to continue" << endl;
			//int dummyVar = 0;
			//	cin >> dummyVar;
			//	dummyVar = 0;

			break;
		} else if (playerChoice != '2' || (playerChoice == '2' && gunAmmo <= 0)) {

			cout << "The Alien strikes\n";
			newenemyDmg = enemyDmg;
			HP -= newenemyDmg;

			cout << "You take " << CYAN << newenemyDmg;
			resetcolor();
			cout << " damage." << endl;
			newenemyDmg = enemyDmg;


			if (HP <= 0) {
				cout << "YOU DIED!\n";
				//  cout << RED << "Alien HP: " << enemyHP << WHITE <<  " | "  << GREEN << "Human HP " << HP <<  endl;
				resetcolor();
				exit(0);
			}

		}
	}

	resetcolor();
	show_cursor(false);
	set_raw_mode(true);
	return;

}


//this is for the last puzzle
vector<bool> lightBoard {0, 0, 0};
void toggleLight(int i) {
	if (lightBoard.at(i) == true) lightBoard.at(i) = false;
	else if (lightBoard.at(i) == false) lightBoard.at(i) = true;
}


int puzzleNum = 1;
void puzzle() {

	clearscreen();
	show_cursor(true);
	set_raw_mode(false);
	string prompt;
	if (puzzleNum == 1) {
		cout << "Damn just got some deja vu... \nThis reminds me of when Ripley Alien was sneaking around the escape shuttle before fighting that xenomorph...\nWhat was that song she was singing during that battle? Something about a star?\n";
		while (true) {
			getline(cin, prompt);
			if (prompt == "You are my lucky star" || prompt == "you are my lucky star") {
				break;
			} else {
				cout << "Hmm, no, that wasn't it.\n Something about, no, a lucky star?" << endl;
			}
		}
	}

	if (puzzleNum == 2) {
		cout << "dalkjfkldsjafjklsadfjsdlafdkljdlaf\nTranslation: SECURITY QUESTION: WHAT EARTH YEAR WAS THE FIRST WAR OF THE WORLDS?\n";
		while (true) {
			getline(cin, prompt);
			if (prompt == "1938") {
				break;
			} else {
				cout << "Access denied.\n";
			}
		}
	}

	if (puzzleNum == 3) {
		cout << "wowhododkljdfasdfkjlekhellokjfasbruhdk\nTranslation:\nALIEN - XENOMORPH\n2001 - [translation error]\nSTARSHIP TROOPERS - ARACHNIDS\nDISTRICT 9 - ";
		while (true) {
			getline(cin, prompt);
			if (prompt == "prawns" || prompt == "Prawns" || prompt == "PRAWNS") {
				break;
			} else {
				cout << "Access Denied\n";
			}
		}

	}
	if (puzzleNum == 4) {

		cout << "As you pass through the place, you notice that the writing on one of these whiteboard-like things kind of looks like math.\nYou realize that potentially being the first person to perfom Alien Math is too good of a chance to pass up." << endl;
		cout << "  |\\\n";
		cout << "  | \\\n";
		cout << "12|  \\[__]\n";
		cout << "  |   \\\n";
		cout << "  |    \\\n";
		cout << "  -------\n";
		cout << "     5\n";

		int pyTher = 0;
		while (true) {
			cin >> pyTher;

			if (pyTher == 13) {
				break;
			} else {
				cout << "No, that doesn't seem right...\nIt looks like the pythagorean theorem.\n";
			}
		}
	}

	if (puzzleNum == 5) {
		cout << "Before you is a large terminal. It appears to be able to control everything on the ship.\nMost of it has been damaged by the crash, but some of it remains intact.\nOff to the side is a series of buttons and lights\n";


		char buttons = '0';

		while (true) {
			cout << "--1-2-3--\n";
			cout << "{ ";
			for (int i = 0; i < lightBoard.size(); ++i) {
				cout << lightBoard.at(i) << " ";
			}
			cout << "}" << endl;
			cin >> buttons;

			if (buttons == '1') {
				toggleLight(0);
				toggleLight(2);
			}
			if (buttons == '2') {
				toggleLight(1);

			}
			if (buttons == '3') {
				toggleLight(1);
				toggleLight(2);
			}

			int sum = 0;
			for (int i = 0; i < lightBoard.size(); ++i)
				sum += lightBoard.at(i);

			if (sum >= lightBoard.size()) break;
		}
		cout << "\n{ ";
		for (int i = 0; i < lightBoard.size(); ++i) {
			cout << lightBoard.at(i) << " ";
		}
		cout << "}" << endl;

		cout << "The all lights are now on.\nYou hear an airlock open behind you\n";
		usleep(1450000);




	}


	clearscreen();
	show_cursor(false);
	set_raw_mode(true);
}






int main() {
	const int FPS = 60;
	int row = ROWS / 2, col = COLS / 2;
	int last_row = -1, last_col = -1; //Save our last position so we only redraw on update
	char weapon;
	set_raw_mode(true);
	show_cursor(false);

	srand(time(NULL));
	int key1 = 0, key2 = 0, key3 = 0;
	int HP = 100; //player health
	int enemyHP = 100; // alien health
	string tileStr = "default text";

	row = 1;
	col = 1;

	cutsceneTime(1);

	while (true) {
		tileStr = "default text";



		if (HP < 30) tileStr = "it hurts.";


		int c = toupper(quick_read());
		if (c == 'Q') break;
		if (c == 'W' or c == UP_ARROW) row--;
		if (c == 'S' or c == DOWN_ARROW) row++;
		if (c == 'A' or c == LEFT_ARROW) col--;
		if (c == 'D' or c == RIGHT_ARROW) col++;
		if (!(row == last_row and col == last_col)) { //If we moved...



			switch (get_world_location(row, col)) {
			case '*':
				//comment out this whole case to disable collision
				row = last_row;
				col = last_col;
				tileStr = "can't go there. that's a wall.";
				break;
			case '0':
				currentMap = 0;
				row = 1;
				col = 8;
				tileStr = "Guess this is the ship's brig.";
				break;
			case '1':
				if (currentMap == 0) {
					row = 1;
					col = 1;
				} else if (currentMap == 2) {
					row = 1;
					col = 8;
				}
				currentMap = 1;
				tileStr = "This looks like a storage area.";
				break;
			case '2':
				if (currentMap == 1) {
					row = 8;
					col = 8;
				} else if (currentMap == 3) {
					row = 5;
					col = 1;
				}
				currentMap = 2;
				tileStr = "Now in map 2";
				break;
			case '3':
				if (currentMap == 2) {
					row = 5;
					col = 8;
				} else if (currentMap == 4) {
					row = 4;
					col = 1;
				}
				currentMap = 3;
				tileStr = "Now in map 3";
				break;
			case '4':
				row = 4;
				col = 8;
				currentMap = 4;
				tileStr = "Now in map 4";
				break;
			case '5':
				cutsceneTime(2);
				break;
			case 'i':
				//ammo
				gunAmmo += 5;
				tileStr = "Found some cells for that blaster.";
				set_world_location(row, col, ' ');
				break;
			case 'A':
				//alien ancounter
				resetcolor();
				Combat_mode(HP);
				set_world_location(row, col, ' ');
				tileStr = "You kiled the alien!";
				break;
			case 'H':

				tileStr = "You find a health pack.\nYou feel a bit better.";
				if (HP < 100) {
					HP += 25;
					set_world_location(row, col, ' ');
				}

				if (HP >= 100) {
					tileStr =  "You find a health pack.\nThankfully, you don't need one right now.";
					HP = 100;
				}
				break;
			case 'r':
				tileStr = "There's an alien blaster on the ground. You pick it up.\nStay strapped or get clapped, as they say.";
				set_world_location(row, col, ' ');
				break;
			case 'P':
				puzzle(); //do the puzzle
				if (puzzleNum == 1) {
					tileStr = "Yeah, that was the one.";
				} else if (puzzleNum == 5) {
					tileStr = "Is that the exit over there?";
					set_world_location(8, 7, ' ');

				} else {
					tileStr = "Access Granted";
				}
				puzzleNum++; //next P will be the next puzzle;
				set_world_location(row, col, ' ');
				break;


			}
			// dont put usleep on <-this-> line it'll cause usleep*/
			print_map(theMaps.at(currentMap), row, col); //...redraw the map

			last_row = row;
			last_col = col;
			movecursor(0, 0);
			cout << CYAN  << "ROW: " << row << YELLOW << " COL: " << col << RESET << " MAP: " << currentMap;
			cout << GREEN;
			if (HP < 50) cout << YELLOW;
			if (HP < 30) cout << RED;
			cout << " HP: " << HP;
			resetcolor();
			movecursor(ROWS + 3, 0);
			cout << tileStr << endl;
			cout.flush();
			usleep(100000);

		}
	}
	set_raw_mode(false);
	show_cursor(true);
	movecursor(0, 0);
	clearscreen();

}
