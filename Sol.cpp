#include<iostream>
#include<ctime>
using namespace std;

void play(int* cash, int bet) {
    char c[] = { 'J', 'Q', 'K' };
    cout << "Shuffling ...." << endl;
    srand(time(0));

    for (int i = 0; i < 5; i++) {
        int x = rand() % 3;
        int y = rand() % 3;

        char temp = c[x];
        c[x] = c[y];
        c[y] = temp;
    }

    int playersGuess;
    cout << "What's the position of Queen: 1, 2, 3" << endl;
    cout << endl;
    cin >> playersGuess;

    if (c[playersGuess - 1] == 'Q') {
        *cash += 3 * bet;
        cout << "You Won! Result = " << c[0] << c[1] << c[2] << " Cash: $ " << *cash;
        cout << endl;
    }
    else {
        *cash -= bet;
        cout << "You lose! Result = " << c[0] << c[1] << c[2] << " Cash: $ " << *cash;
        cout << endl;
    }
}


int main() {
	int bet,cash;
	cout << "Welcome to Virtual Casino " << endl;
	cash = 200;
    cout << endl;
	cout << "Total Cash: $ " << cash << endl;
	while (cash > 0) {
		cout << "What's Your Bet? " << endl;
		cin >> bet;
		if (bet == 0 || bet > cash) {
			break;
		}
		play(&cash,bet);
        cout << endl;
		cout << "************************************************" << endl;
	}

	return 0;
}