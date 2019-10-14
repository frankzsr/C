#include <iostream>
#include "tabtenn.h"

TableTennisPlayer::TableTennisPlayer(const string &fn, const string &ln,
									 bool ht) : firstname(fn), lastname(ln), hasTable(ht) {}
void TableTennisPlayer::Name() const
{
	std::cout << lastname << ", " << firstname;
}

void TableTennisPlayer::Name(int i)
{
	cout << "input: " << i << endl;
}
