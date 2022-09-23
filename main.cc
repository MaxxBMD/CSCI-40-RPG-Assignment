//Fill out this comment with your names and which bullet points you did
//Partners: Herbart Hernandez, Rene Hernandez, Ayden Messick, Allesandra Orozco-Newton, Brandon Sam
//Bullet Points:
//Extra Credit:
//URL to cover art and music:
#include "/public/read.h"
#include "/public/colors.h"
#include <iostream>
#include <vector>

using namespace std;

//global variables go here:
vector<string> world_map = {
	"*****************      ",
	"*        |      *      ",
	"*        |      *      ",
	"*        |      *      ",
	"*        ---    *      ",
	"* c        1    *      ",
	"*               *******",
	"*    -----            *",
	"*          A          *",
	"*                     *",
	"***********************",



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



void cutsceneTime(int cutsceneNum) {
	//what if we also parse in a number or character, and have that correspond with a string? and so each string would correlate with a different cutscene?
	/* 0 = default. (nothing)
	   1 = game intro

	   */

	clearscreen();



	if (cutsceneNum == 1) {
		cout << "You wake up to the blaring ring of an alarm and a message broadcasting in a language of hoarse squeals and guttural noises you do not understand.\n";
		cout << "Covering your ears and turning away from the flashing neon green bars of light arranged like a cage around your feeble, frail human body,\nyou remember how you got here: you were captured.\n";
		cout << "Captured by alien invaders as you ran toward the evacuation site and thrown in a prison cell composed of lasers.\n";
		cout << "Lasers that scorched right through the strands of hair you ripped from your head and placed in their path to learn just how hopeless your situation was.\n";
		cout << "As the memories come back, you hear the buzz of the lasers begin to fade away. You open your eyes to see your cage has disappeared.\n";
		cout << "The alarm message must be something about a power outage. You don’t take more than a couple seconds to decide you must seize this opportunity.\n";
		cout << "You begin to walk toward the door that you presume leads you out of this prison.\n";
		cout << endl << "Use the arrow keys to reach the door and escape.\n";
	}

	if (cutsceneNum == 0) {
		cout << "this is the default cutscene. alien encounters will be done in their own function." << endl;
	}

	cout << "press any key to continue" << endl;
	int x = quick_read();//like cin >> x, but faster

	//program does not proceed until player input.


	return;//exits the function and resumes right where we were in main

}



int main() {
	const int ROWS = world_map.size();
	const int COLS = world_map.at(0).size(); //MAKE SURE ALL ROWS ARE THE SAME SIZE OR BAD TIMES
	const int FPS = 60;
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
		if (!(row == last_row and col == last_col)) { //If we moved...
			print_world(row, col); //...redraw the map
			last_row = row;
			last_col = col;
			movecursor(2, COLS + 5);
			cout << BLUE << "ROW: " << row << RED << " COL: " << col << RESET;
			movecursor(ROWS + 2, 0);
			cout << "Welcome to the game\n";
			cout.flush();
		}
		if (get_world_location(row, col) == 'r') {
			set_world_location(row, col, ' ');
			movecursor(ROWS + 2, 0);
			cout << "You picked up a radish!\n";
		}
		if (get_world_location(row, col) == 'A') {
			cutsceneTime(0);
			set_world_location(row, col, ' ');
		}

		if (get_world_location(row, col) == '1') {
			cutsceneTime(1);
			set_world_location(row, col, ' ');
		}


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

