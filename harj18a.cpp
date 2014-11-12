/*Tee ohjelma, joka kysyy viiden koiran nimet ja i�t.
Tiedot tallennetaan tietuetaulukkoon.
a) järjestä tiedot ikä - kentän mukaan suuruusjärjestykseen
(pienimmästä suurimpaan).Ohjelma tulostaa lopuksi
jarjestetyn taulukon näytölle.
b) järjestä tiedot nimi - kentän mukaan aakkosjärjestyksessä
Ohjelma tulostaa lopuksi jarjestetyn taulukon näytölle.

Lajittelu tulee toteuttaa siten, että se toimisi samoin
myäs 50 tai 5000 koiran tapauksssa.
*/

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct dogInfo
{
	string dogName;
	int dogAge;
};

void clearConsole();
string getUserInputString();
int getUserInputInteger();
int compareDogAges(const void*, const void*);
int getDogCount();
dogInfo getDogDetails(int);
dogInfo * getDogs(int);
void printDogInfo(dogInfo);
void printAllDogs(int numberOfDogs, dogInfo * dogs);

int main()
{
	int numberOfDogs = getDogCount();
	dogInfo * dogs = getDogs(numberOfDogs);
	qsort(dogs, numberOfDogs, sizeof(dogInfo), compareDogAges);
	clearConsole();
	printAllDogs(numberOfDogs, dogs);

	return 0;
}


void printAllDogs(int numberOfDogs, dogInfo * dogs)
{
	for (int i = 0; i < numberOfDogs; i++)
	{
		cout << "Dog " << i + 1 << " ";
		printDogInfo(dogs[i]);
	}

}

void printDogInfo(dogInfo dog)
{
	cout << "Name: " << dog.dogName << " ";
	cout << "Age: " << dog.dogAge << endl;
}

dogInfo * getDogs(int numberOfDogs)
{
	dogInfo * dogs = new dogInfo[numberOfDogs];
	for (int i = 0; i < numberOfDogs; i++)
	{
		clearConsole();
		dogs[i] = getDogDetails(i);
	}
	return dogs;
}

dogInfo getDogDetails(int i)
{
	struct dogInfo dog;
	cout << "Details on dog " << i + 1 << endl;
	cout << "Name: ";
	dog.dogName = getUserInputString();
	cout << "Age: ";
	dog.dogAge = getUserInputInteger();
	return dog;

}

int getDogCount()
{
	int numberOfDogs;
	cout << "How many dogs would you like to enter to the database?: ";
	numberOfDogs = getUserInputInteger();
	return numberOfDogs;
}

int getUserInputInteger()
{
	int userInt;
	cin >> userInt;
	cin.ignore(1, '\n');
	return userInt;
}


string getUserInputString()
{
	string userString;
	getline(cin, userString);
	return userString;
}

void clearConsole()
{
	system("cls");
}

int compareDogAges(const void * a, const void * b)
{
	if (((const dogInfo*)a)->dogAge < ((const dogInfo*)b)->dogAge) return -1;
	if (((const dogInfo*)a)->dogAge == ((const dogInfo*)b)->dogAge) return 0;
	if (((const dogInfo*)a)->dogAge >((const dogInfo*)b)->dogAge) return 1;
}