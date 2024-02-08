//	gravitational force calculation
#include <iostream> 
#include <stdlib.h>    
#include <cmath>

using namespace std;

int main()
{
	//	infinite loop
	while (true) 
	{
		const double G_CONST = 6.673 * pow(10.0, -8.0);
		double massOne, massTwo, distance;
		double gravityDynes;

		cout << "Please input mass one: ";
		cin >> massOne;
		cout << "Please input mass two: ";
		cin >> massTwo;
		cout << "Please input the distance (d) between the masses: ";
		cin >> distance;
		
		gravityDynes = (G_CONST * massOne * massTwo) / (pow(distance, 2.0));
		
		cout << "The force of gravity measures " << gravityDynes << " Dynes.\n";
		
		
		//	user input for repeats
		char usrIn;
		cout << "New calculation? [y/n] ";
		cin >> usrIn;
		if (usrIn == 'n')
			break;
	}
	cout << "Program terminated.\n";
	return 0;
}