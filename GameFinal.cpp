#include <stdio.h>
#include <time.h>
#include <iostream>

using namespace std;


class game {

private:

	


public:
	void shuffle(int wDeck[][13]);
	void deal(const int wDeck[][13], const char *wFace[],
		const char *wSuit[]);

	int deck[4][13] = { 0 };
	const char *suit[4] = { "Hearts", "Diamonds", "Clubs", "Spades" };


	const char *face[13] =
	{ "Ace","Deuce", "Three","Four","Five","Six","Seven", "Eight","Nine", "Ten", "Jack", "Queen","King" };


};

void game::shuffle(int wDeck[][13])
{
	int row;
	int column;
	int card;

	for (card = 1; card <= 52; card++) {

		do {
			row = rand() % 4;
			column = rand() % 13;
		} while (wDeck[row][column] != 0);

		wDeck[row][column] = card;
	}
}

void game::deal(const int wDeck[][13], const char *wFace[],
	const char *wSuit[])
{
	int card;
	int row;
	int column;

	int userRow, userColomn;

	for (card = 1; card <= 3; card++) {

		for (row = 0; row <= 3; row++) {

			for (column = 0; column <= 12; column++) {

				if (wDeck[row][column] == card) {
					cout << "_____________________________________________lucky guess the game_____________________________________________" << endl;
					cout << "If your guess is correct then you will win the game.You will have 3 chances to guess correctly" << endl;
					cout << "Enter your choise : " << endl;
					cout << "(Ace-0,Deuce-1, Three-2,Four-3,Five-4,Six-5,Seven-6, Eight-7,Nine-8, Ten-9, Jack-10, Queen-11,King-12)" << endl;
					cin >> userColomn;
					cout << "of" << endl;
					cout << "(Hearts-0, Diamonds-1, Clubs-2, Spades-3)" << endl;
					cin >> userRow;

					cout << "your choise was : " << wFace[userColomn] << " of " << wSuit[userRow] << endl;

					cout << "Lucky card is : " << wFace[column] << " of " << wSuit[row] << endl;

					if ((column == userColomn) && (row == userRow)) {
						cout << "CONGRATULATIONS!!!.your choice is CORRECT.you are very LUCKY!!!" << endl;
					}


					
				}
				
			}
		}
	}
}


int main(void)
{
	game ob1;

	srand(time(0));

	ob1.shuffle(ob1.deck);
	ob1.deal(ob1.deck, ob1.face, ob1.suit);

	cout << "Your chances are OVER!!!.Better luck next time." << endl;

	return 0;
}




