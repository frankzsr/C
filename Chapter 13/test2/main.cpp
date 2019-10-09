#include <iostream>
#include "tabtenn.h"

using namespace std;

int main()
{
	TableTennisPlayer player1("Tara", "Boomdea", false);
	RatedPlayer rplayer1(1440, "Mallory", "Duck", true);

	rplayer1.Name();
	if (rplayer1.HasTable())
		cout << ": has a table.\n";
	else {
		cout << ": hasn't a table.\n";
	}

	player1.Name();
	if (player1.HasTable())
		cout << ": has a table.\n";
	else {
		cout << ": hasn't a table.\n";
	}

	cout << "Name: ";
	rplayer1.Name();
	cout << "; Rating: " << rplayer1.Rating() << endl;

	RatedPlayer rplayer2(1212, player1);
	cout << "Name: ";
	rplayer2.Name();
	cout << "; Rating: " << rplayer2.Rating() << endl;

	rplayer2.Name();
	if (rplayer2.HasTable())
		cout << ": has a table.\n";
	else {
		cout << ": hasn't a table.\n";
	}

	return 0;
}
