#include <iostream>
using namespace std;

int main()
{
	cout << "\tWell cum to NumberGuesser!\n" << endl;
	cout << "\tEnter the number from 1 to 1000 and I'll close my eyes: ";
	
	int number;
	cin >> number;
	if (number < 1 || number > 1000)
	{
		cout << "\n\tHave you completed elementary school?" << endl;
		cout << "\tFrom 1 to 1000: ";
	}
	while (true)
	{
		cin >> number;
		if (number < 1 || number > 1000)
		{
			cout << "\n\tBruh..." << endl;
			cout << "\tFrom 1 to 1000, please: ";
		}
		else
		{
			break;
		}
	}

	cout << "\n\tGotcha! I have no eyes!" << endl;
	cout << "\tBut! I don't know exactly what you entered, because I have no eyes." << endl;
	cout << "\tI'm an honest guy..." << endl;
	cout << "\tI mean... I mean a computer, of course..." << endl;
	cout << "\tThere won't be a story like Pinocchio here." << endl;
	cout << "\tSo! Let's start!" << endl;

	int tries = 0;
	srand(static_cast <unsigned int> (time(0)));
	int guess = rand() % 1000 + 1;
	char answer;
	cout << "\n\tI think it's " << guess << "?" << endl;
	++tries;
	cout << "\t(Y / N) ";

	// это в функцию
	while (true)
	{
		cin >> answer;
		if (answer < 'n' && answer > 'Y')
		{
			cout << "\n\tAre you stupid or something?" << endl;
			cout << "\t(Y / N) ";
		}
		else if (answer < 'y' && answer > 'n')
		{
			cout << "\n\tAre you kiddng me?" << endl;
			cout << "\t(Y / N) ";
		}
		else if (answer < 'Y' && answer > 'N')
		{
			cout << "\n\tIt's not even funny anymore." << endl;
			cout << "\t(Y / N) ";
		}
		else if (answer < 'N' && answer > 'y')
		{
			cout << "\n\tNigga, what a fuck?" << endl;
			cout << "\t(Y / N) ";
		}
		else
		{
			cout << "\n\tFinally... So..." << endl;
			break;
		}
	}

	cout << "\n\tMaybe it's " << guess << "?" << endl;
	++tries;
	cin >> answer;

	// пример

	/*
	do
	{
		cout << "\n\tI think it's " << guess << "?" << endl;
		cin >> guess;
		++tries;

		if (guess > secretNumber)
		{
			cout << "Too high!\n\n";
		}
		else if (guess < secretNumber)
		{
			cout << "Too low!\n\n";
		}
		else
		{
			cout << "\nThat's it! You got it in " << tries << " guesses!\n";
		}
	} while (guess != secretNumber);
	*/
}