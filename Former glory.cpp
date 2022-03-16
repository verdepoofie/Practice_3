#include <iostream>
using namespace std;

void former_glory();
int main(){
	former_glory();
	return 0;
}
void former_glory() {
	for (int i = 0; i < 6; i++) {
		for (int star = 0; star < 8; star++) {
			cout << "*  ";
		}
		for (int stripe = 0; stripe < 36; stripe++) {
			cout << "_";
		}
		cout << "\n";
	}
	for (int i = 0; i < 7; i++) {
		for (int stripe = 0; stripe < 60; stripe++) {
			cout << "_";
		}
		cout << "\n";
	}
}