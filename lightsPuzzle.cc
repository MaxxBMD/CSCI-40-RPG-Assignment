#include <vector>
#include <iostream>
#include "/public/colors.h"

using namespace std;


vector<bool> lightBoard {0, 0, 0};


void toggleLight(int i) {
	if (lightBoard.at(i) == true) lightBoard.at(i) = false;
	else if (lightBoard.at(i) == false) lightBoard.at(i) = true;

}

void button1() {
	toggleLight(0);
	toggleLight(2);

}


void button2() {
	toggleLight(0);
	toggleLight(1);
}

void button3() {
	toggleLight(1);
	toggleLight(2);


}



int main() {



	lightBoard.at(0) = true;

	for (int i = 0; i < lightBoard.size(); ++i) {
		cout << lightBoard.at(i) << " ";
	}
	cout << endl;

	char c = 0;
	cin >> c;

	while (c != 'q') {
		//type q when done with puzzle;
		if (c == '1') button1();
		if (c == '2') button2();
		if (c == '3') button3();


		for (int i = 0; i < lightBoard.size(); ++i) {
			cout << lightBoard.at(i) << " ";
		}
		cout << endl;
		cin >> c;
	}


	int sum = 0;
	for (int i = 0; i < lightBoard.size(); ++i) {
		sum += lightBoard.at(i);

	}

	if (sum >= lightBoard.size()) cout << "YOU WIN!" << endl;
	else cout << "you lose :/" << endl;



}
