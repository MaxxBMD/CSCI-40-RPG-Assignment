#include<iostream>
using namespace std;

void puzzle(int puzzleNum, int &key) {
	string prompt;
	if (puzzleNum == 1) {
		cout << "Damn just got some deja vu \nThis reminds me of when Ripley was sneaking around the escape shuttle before fighting xenomorph...\nWhat was that song she sang during that battle? Something about a star?\n";
		while (key != 1) {
			getline(cin, prompt);
			if (prompt == "You are my lucky star" || prompt == "you are my lucky star") {
				key = 1;//passed test
				cout << "Access granted\n";
			}//? is this a memory or a password?
			else {
				cout << "Access denied\n Try again\n";
			}
		}
	}

	if (puzzleNum == 2) {
		cout << "dalkjfkldsjafjklsadfjsdlafdkljdlaf\n Translation:When was the first war of worlds?\n";
		while (key != 1) {
			getline(cin, prompt);
			if (prompt == "1989") {
				key = 1;
				cout << "Access granted\n";
			} else {
				cout << "Access denied\n Try again\n";
			}
		}
	}

	if (puzzleNum == 3) {
		cout << "wowhododkljdfasdfkjlekhellokjfasbruhdk\n Translation:In Alien we have Xenomorph\nIn Avater we have The Na'vi\nIn Starship Troopers we Arachnids\n In District 9 we have...";
		while (key != 1) {
			getline(cin, prompt);
			if (prompt == "prawns" || prompt == "Prawns") {
				key = 1;
				cout << "Access granted\n";
			} else {
				cout << "Access denied\n Try again\n";
			}
		}
	}
}
int main() {
	int key1 = 0;// maybe keys can be used for something?
	int key2 = 0;
	int key3 = 0;
	puzzle(3, key3);// picks puzzle to do and changes key value to 1 if passed

	cout << "back to expoloring\n";
}
