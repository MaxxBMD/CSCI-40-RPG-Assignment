//Fill out this comment with your names and which bullet points you did
//Partners: Herbart Hernandez, Rene Hernandez, Ayden Messick, Allesandra Orozco-Newton, Brandon Sam
//Bullet Points:
//Extra Credit:
//URL to cover art and music:
#include "/public/read.h"
#include "/public/colors.h"
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

//TODO make enum to store maps



//global variables go here:
vector<string> world_map = {
	"-----------------      ",
	"|        |      |      ",
	"|     i  | H   |       ",
	"|        |      |      ",
	"|   H    ---   |      ",
	"|              |       ",
	"|      G     B  -------",
	"|    -----            1",
	"|                  z  1",
	"|     F                1",
	"-----------------------",


};


char get_world_location(size_t row, size_t col) {
	if (row >= world_map.size()) return ' ';
	if (col >= world_map.at(row).size()) return ' ';
	return world_map.at(row).at(col);
}


void set_world_location(size_t row, size_t col, char c) {
	if (row >= world_map.size()) return;
	if (col >= world_map.at(row).size()) return;

	world_map.at(row).at(col) = c;
}

void print_world(size_t player_row, size_t player_col) {
	clearscreen();
	movecursor(0, 0);
	for (size_t row = 0; row < world_map.size(); row++) {
		for (size_t col = 0; col < world_map.at(row).size(); col++) {
			if (row == player_row && col == player_col) cout << "@";
			else
				cout << world_map.at(row).at(col);
		}
		cout << endl;
	}
}



void cutsceneTime(char cutsceneNum) {
	//the int we take in determines what text is outputted
	/* 0 = default
	   1 = game intro

	   */
	clearscreen();

	if (cutsceneNum == 'i') {
		//game intro
		cout << "You wake up to the blaring ring of an alarm and a message broadcasting in a language of hoarse squeals and guttural noises you do not understand.\n";
 		cout << "Covering your ears and turning away from the flashing neon green bars of light arranged like a cage around your feeble, frail human body,\nyou remember how you got here: you were captured.\n";
		cout << "Captured by alien invaders as you ran toward the evacuation site and thrown in a prison cell composed of lasers.\n";
		cout << "Lasers that scorched right through the strands of hair you ripped from your head and placed in their path to learn just how hopeless your situation was.\n";
		cout << "As the memories come back, you hear the buzz of the lasers begin to fade away. You open your eyes to see your cage has disappeared.\n";
		cout << "The alarm message must be something about a power outage. You don’t take more than a couple seconds to decide you must seize this opportunity.\n";
		cout << "You begin to walk toward the door that you presume leads you out of this prison.\n";
		cout << endl << "Use the arrow keys to reach the door and escape.\n";
	}

	//default
	if (cutsceneNum == 'a') {
		cout << "this is the default cutscene. alien encounters will be done in their own function." << endl;
	}

	cout << "press any key to continue" << endl;
	int x = quick_read();//like cin >> x, but faster
	//program does not proceed until player input.

	return;//exits the function and resumes right where we were in main

}

void combatTime() {
	set_raw_mode(false);
	clearscreen();

	cout << "aaawaga" << endl;
	string x = "";
	cin >> x;

	int i = 0;
	while (x != "autowin") {
		cout << "type autowin to end the battle" << endl;
		cin >> x; //make this a getline
		/*	possible actual inputs:
			-melee / knife / [weapon name]
			-ranged / gun / blaster / [weapon name]
			-flee / whatever
			-autowin (only a temp for debug)
		*/

		i++;
		if (i >= 100) break;
		//failsafe to prevent infinite loop is kicking in at least
	}
	set_raw_mode(true);
	return;
}

void die() {
	cout << "BAD INPUT" << endl;
	exit(1);
}
/*
void alienBlaster (int& HP, int& enemyHP) {
	clearscreen();
    show_cursor(true);
    set_raw_mode(false);
   
	while ((HP >= 0) && (enemyHP >= 0)) {
		srand(time(NULL));
   	    int rand1 = (rand() % 40) + 20;; 
    	int rand2 = (rand() % 30) + 10;
    	int alien_blaster = rand1;
    	int enemyDmg = rand2;
    	int newplayerDmg = alien_blaster;;
   	    int newenemyDmg = enemyDmg;
    	string action;
	}
}
	*/    
void Combat_mode (int& HP, int& enemyHP) {

	clearscreen();
    show_cursor(true);
    set_raw_mode(false);

	 while ((HP >= 0) && (enemyHP >= 0)) {
		 srand(time(NULL));
		int rand1 = (rand() % 40) + 20;;
        int rand2 = (rand() % 30) + 10;
        int alien_blaster = rand1;
        int enemyDmg = rand2;
        int newplayerDmg = alien_blaster;;
        int newenemyDmg = enemyDmg;
        string action;

	    cout << RED << "Alien HP: " << enemyHP << WHITE <<  " | "  << GREEN << "Human HP " << HP <<  endl;
        resetcolor();

        cout << "You strike the alien\n";
        newplayerDmg = alien_blaster; //holds the random value

        enemyHP -= newplayerDmg;//player dmg affects alien hp
        cout << "You do: " << CYAN << alien_blaster;
        resetcolor();
        cout << " damage to the alien\n";
        newplayerDmg = alien_blaster;// resets the random value to the deafault dmg
        if (enemyHP <= 0) {
            break;
        }

        cout << "The Alien strikes\n";
        newenemyDmg = enemyDmg;
        HP -= newenemyDmg;
		if (HP <= 0) {
            break;
        }
		cout << "You take: " << CYAN << newenemyDmg;
		resetcolor();
		cout << " damage" << endl;
		newenemyDmg = enemyDmg;

        cout << "Attempt to flee by pressing q\n";
        cin >> action;
        if (action == "q") { 
            break;
        }
	}
		if (HP <= 0) {
        cout << "YOU DIED!\n";
		cout << RED << "Alien HP: " << enemyHP << WHITE <<  " | "  << GREEN << "Human HP " << HP <<  endl;
        resetcolor();
			exit(0);
		 }

		 else if (enemyHP <= 0) {
		cout << "You killed the alien!\n";
		cout << RED << "Alien HP: " << enemyHP << WHITE <<  " | "  << GREEN << "Human HP " << HP <<  endl;
        resetcolor();
         cout << "Back to exploring!" << endl;
		 }
  
    
    resetcolor();
    show_cursor(false);
    set_raw_mode(true);
    return;
}

/*
void Baseball_bat (int &HP, int &enemyHP) {

    clearscreen();
    show_cursor(true);
    set_raw_mode(false);

    while ((HP > 0) && (enemyHP > 0)) {
        srand(time(NULL));
        int rand1 = (rand() % 20) + 15;
        int rand2 = (rand() % 15) + 10;
        int alien_blaster  = rand1;
        int enemyDmg = rand2;
        int newplayerDmg = bat;
        int newenemyDmg = enemyDmg;
        int choice1;
        string action;
	}
}
        

void Melee (int &HP, int &enemyHP) {
	
	clearscreen();
    show_cursor(true);
    set_raw_mode(false);

    while ((HP > 0) && (enemyHP > 0)) {	
		srand(time(NULL));
	    int rand1 = (rand() % 20) + 10;
    	int rand2 = (rand() % 20) + 5;
	    int alien_blaster = rand1;
        int enemyDmg = rand2;
	    int newplayerDmg = Melee;
        int newenemyDmg = enemyDmg;
        int choice1;
		string action;
	}
}
*/

int main() {
	const int ROWS = world_map.size();
	const int COLS = world_map.at(0).size(); //MAKE SURE ALL ROWS ARE THE SAME SIZE OR BAD TIMES
	const int FPS = 60;
    char weapon;

    int HP = 100; //player health
    int enemyHP = 100; // alien health

	int row = ROWS / 2, col = COLS / 2;
	int last_row = -1, last_col = -1; //Save our last position so we only redraw on update
	set_raw_mode(true);
	show_cursor(false);

	while (true) {
		int c = toupper(quick_read());
		if (c == 'Q') break;
		if (c == 'W' or c == UP_ARROW) row--;
		if (c == 'S' or c == DOWN_ARROW) row++;
		if (c == 'A' or c == LEFT_ARROW) col--;
		if (c == 'D' or c == RIGHT_ARROW) col++;
		//if (c == 'i') checkInventory(); //this function does not exist. just a temp for when inventory is added.
		if (!(row == last_row and col == last_col)) { //If we moved...
			print_world(row, col); //...redraw the map
			last_row = row;
			last_col = col;
			movecursor(2, COLS + 5);
			cout << BLUE << "ROW: " << row << RED << " COL: " << col << RESET;
			movecursor(ROWS + 2, 0);
			cout << "Welcome to the game\n";
			//cout.flush();
		}

		
		if (get_world_location(row, col) == 'G') {
			set_world_location(row, col, ' ');
			movecursor(ROWS + 2, 0);
		
			cout << "You picked up an Alien blaster. (This weopon deals more damage than your hands, but only contains 10 bullets)\n";
	
		}

		//alien
		if (get_world_location(row, col) == 'F') {
			movecursor(ROWS + 2, 0);
			cout << YELLOW << "WARNING:"; 
			resetcolor();
			cout << " You have encoutered a Alien uh oh\n";
			cout << "Chose your weapon to fight the alien!\n";
			cout << "Enter 1) Melee" << endl;
 			cout << "Enter 2) Alien Blaster" << endl;
 			cout << "Enter 3) Baseball Bat" << endl;
			cin >> weapon;
			if (!cin) die();

			print_world(row, col);
            set_world_location(row, col, ' ');
			
			if (weapon == '1') {
				Combat_mode (HP, enemyHP);
			}
			
			if (weapon == '2') {
			Combat_mode(HP, enemyHP);
			}	  

			if (weapon == '3') {
				Combat_mode(HP, enemyHP);
			}


		}
		 
		if (get_world_location(row, col) == 'B') {
         set_world_location(row, col, ' ');
        movecursor(ROWS + 2, 0);
		cout << "You picked up a baseball bat! This deals more damage but take in more damage" << endl;
        
		}
	    
		

		//intro cutscene
		if (get_world_location(row, col) == 'i') {
			cutsceneTime('i');
			set_world_location(row, col, ' ');
		}



		//health pickup
		if (get_world_location(row, col) == 'H') {		
             set_world_location(row, col,' ' );
              movecursor(ROWS + 2, 0);
		cout << "CONGRATS! You found a health pack!" << endl;
        if (HP < 100){
         HP += 15;
		}
         if (HP >= 100) {
         cout << "Health is already at maxed" << endl;
			 HP = 100;

		}
	}
	

		//end
		if (get_world_location(row, col) == 'z') {
			movecursor(ROWS + 2, 0);
			cout << "YOU WIN!!!!!!!!!^G^G^G\n";
			usleep(2'000'000);
			break;
		}
		if (c == ERR) usleep(1'000'000 / FPS);
	}
	set_raw_mode(false);
	show_cursor(true);
	movecursor(0, 0);
	clearscreen();


	/*
	cout << "Please enter a row and column" << endl;
	int row, col;
	cin >> row >> col;
	if (world_map.at(row).at(col) == '*') cout << "There is a wall there.\n";

	//A vector is a data structure, "Something that holds multiple variables"
	//Syntax: vector<type of thing to hold> name of the vector(size of the vector)
	vector<int> help = {1,2,3,4,50};
	//Print the contents of help:
	for (int x : help) cout << x << endl;

	//This just made 40 integers, within a vector named help
	for (size_t i = 0; i < help.size(); i++) {
	    cout << "Please enter the value for help.at(" << i << ")\n";
	    cin >> help.at(i);
	}
	cout << "Here is the help vector!\n";
	for (int x : help) {
	    cout << x << endl;
	}
	*/
}


