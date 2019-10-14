#include <iostream>
#include "tabtenn.h"

using namespace std;

int main()
{
	TableTennisPlayer player1("Chuck", "Blizzard", true);
	TableTennisPlayer player2("Tara", "Boomdea", false);
	player1.Name();
	if (player1.HasTable())
		cout << ": has a table.\n";
	else {
		cout << ": hasn't a table.\n";
	}
	player2.Name();
	if (player2.HasTable())
		cout << ": has a table.\n";
	else {
		cout << ": hasn't a table.\n";
	}

	player1.Name(10);
	player1.Name();
	if (player1.HasTable())
		cout << ": has a table.\n";
	else {
		cout << ": hasn't a table.\n";
	}

	player2.Name(10);
	player2.Name();
	if (player2.HasTable())
		cout << ": has a table.\n";
	else {
		cout << ": hasn't a table.\n";
	}

	return 0;
}
