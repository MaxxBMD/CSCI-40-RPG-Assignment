//Fill out this comment with your names and which bullet points you did
//Partners: Herbart Hernandez, Rene Hernandez, Ayden Messick, Allesandra Orozco-Newton, Brandon Sam
//Bullet Points:
//Extra Credit:
//URL to cover art and music:
#include "/public/read.h"
#include "/public/colors.h"
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;
using map_t = vector<vector<char>>;
//global variables go here:


//this map is not currently used
vector<string> world_map = {
	"-----------------      ",
	"|        |      |      ",
	"|        | H    |      ",
	"|        |      |      ",
	"|        ---    |      ",
	"| c        i    |      ",
	"|               -------",
	"|    -----            1",
	"|          A       z  1",
	"|                     1",
	"-----------------------",

};


map_t map2 = {
	{'*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
	{'*', ' ', '*', ' ', ' ', ' ', ' ', '*', ' ', ' '},
	{'*', ' ', '*', ' ', '*', '*', ' ', '*', ' ', '*'},
	{'*', ' ', '*', ' ', '*', '*', ' ', '*', ' ', '*'},
	{'*', ' ', '*', ' ', '*', '*', ' ', '*', ' ', '*'},
	{'*', ' ', '*', ' ', '*', '*', ' ', '*', ' ', '*'},
	{'*', ' ', '*', ' ', '*', '*', ' ', '*', ' ', '*'},
	{'*', ' ', '*', ' ', '*', '*', ' ', '*', ' ', '*'},
	{'*', ' ', ' ', ' ', '*', '*', ' ', ' ', ' ', '*'},
	{'*', '*', '*', '*', '*', '*', '*', '*', '*', '*'}
};



const int ROWS = map2.size();
const int COLS = map2.at(0).size(); //MAKE SURE ALL ROWS ARE THE SAME SIZE OR BAD TIMES


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
					cout << RED;
					break;
				case 'T':
					cout << GREEN;
					break;
				case 'R':
					cout << YELLOW;
					break;
				case 'B':
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



//save_map(map1,"map1.txt");
void save_map(const map_t& map, const string& filename) {
	//Learning Point #1: How to open a file for writing
	//If the file exists, it is truncated (erased and set to 0 size)
	//If the file doesn't exist, it is created
	ofstream john(filename);
	if (!john) {
		cout << "Error: couldn't open " << filename << " for writing.\n";
		exit(EXIT_FAILURE);
	}
	for (const vector<char>& row : map) {  //Call by Const Reference
		for (char col : row) { //Call by Value
			john << col;
		}
		john << endl;
	}
	john.close(); //Closes a file - I only do this if I need the file closed early
}

//map_t map3 = load_map("map3.txt");
map_t load_map(const string& filename) {
	//Learing Point #2: How to open a file for reading
	ifstream lemon(filename);
	if (!lemon) {
		cout << "Could not open the file " << filename << " for reading!\n";
		exit(1);
	}
	map_t retval(ROWS, vector<char>(COLS));
	for (auto &row : retval) {
		for (auto &col : row) {
			col = lemon.get(); //Every time you do a cin >> x or .get() or any input
			if (!lemon) { //Always with a read check for an error
				cout << "Unexpected file read error in: " << filename << endl;
				exit(EXIT_FAILURE);
			}
			if (col == '\n') {
				col = lemon.get();
				if (!lemon) break;
			}
		}
	}
	return retval;
}







char get_world_location(size_t row, size_t col) {
	if (row >= map2.size()) return ' ';
	if (col >= map2.at(row).size()) return ' ';
	return map2.at(row).at(col);
}


void set_world_location(size_t row, size_t col, char c) {
	if (row >= map2.size()) return;
	if (col >= map2.at(row).size()) return;

	map2.at(row).at(col) = c;
}

void print_world(size_t player_row, size_t player_col) {
	clearscreen();
	movecursor(0, 0);
//	print_map(map2);
	for (size_t row = 0; row < map2.size(); row++) {
		for (size_t col = 0; col < map2.at(row).size(); col++) {
			if (row == player_row && col == player_col) cout << "@";

			else
				cout << map2.at(row).at(col);

		}
		cout << endl;
	}
}

int main() {
	const int FPS = 60;
	int row = ROWS / 2, col = COLS / 2;
	int last_row = -1, last_col = -1; //Save our last position so we only redraw on update
	set_raw_mode(true);
	show_cursor(false);

	srand(time(NULL));
	int HP = 100; //player health

	//=============================

	map_t map1(ROWS, vector<char>(COLS));

	for (vector<char>& row : map1) {  //Call by Const Reference
		for (char& col : row) { //Call by Reference
			int roll = rand() % 10;
			if (roll < 4) //30% chance
				col = ' ';
			else if (roll < 7) //30% chance
				col = '*';
			else if (roll < 8) //10% chance
				col = 'T';
			else if (roll < 9) //10% chance
				col = 'R';
			else
				col = 'B';
		}
	}





	//============================


	while (true) {
		int c = toupper(quick_read());
		if (c == 'Q') break;
		if (c == 'W' or c == UP_ARROW) row--;
		if (c == 'S' or c == DOWN_ARROW) row++;
		if (c == 'A' or c == LEFT_ARROW) col--;
		if (c == 'D' or c == RIGHT_ARROW) col++;
		//if (c == 'i') checkInventory(); //this function does not exist. just a temp for when inventory is added.
		if (!(row == last_row and col == last_col)) { //If we moved...
			print_map(map2, row, col); //...redraw the map
			last_row = row;
			last_col = col;
			movecursor(0, 0);
			cout << CYAN  << "ROW: " << row << YELLOW << " COL: " << col << RESET;
			movecursor(ROWS + 3, 0);
			cout << "Welcome to the game\n";
			//cout.flush();
		}
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

