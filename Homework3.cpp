/*Code is a simple simulation of the Birthday Problem, in order to calculate the average number of people needed to be asked 
to have two with the same Birthday

Written by Chet Michals
Created 01/15/2015
*/

#include <iostream>
#include <chrono>
#include <random>

using namespace std;

int main()
{
	//Ensures an even distrabution of random numbers between 1 and 365. Uses the system clock for the seeding of the RNG.
	default_random_engine generator(chrono::system_clock::now().time_since_epoch().count());
	uniform_int_distribution<int> distribution(0, 10000000);

	//These are such bad varable names...
	float S1 = 0;
	float S2 = 0;
	int c = 0;
	int f1 = 0,f2 = 0,f3= 0,f4= 0,f5= 0,f6= 0,f7= 0,f8= 0;

	//Do 10k simulations, print out info during select simulations
	for (int simulationCount = 1; simulationCount <= 10000; simulationCount++)
	{
		
		// case 1
		float x = (float)distribution(generator) / 10000000;

		/* 
		
		//Used for case 2

		float z = (float)distribution(generator) / 10000000;
		float x = -1*log(1-z)/2;

		*/

		/*case 3
		float x = .5;
		*/

		
		/*
		//case 4
		float x = (float)distribution(generator) / 10000000;
		x = (x > .2) ? .2 : 1.7; // Whooooo, A conditional operator. I don't think I'll ever use one of these again, too hard to read
		*/
		
		S1 = S1 + x;
		S2 = S2 + (x * x);
		if ((x > .4) && ( x <= 1.4)) c++;

		if (x < -.25) f1++;
		if (x < 0) f2++;
		if (x < .25) f3++;
		if (x < .5) f4++;
		if (x < .75) f5++;
		if (x < 1) f6++;
		if (x < 1.25) f7++;
		if (x < 1.5) f8++;
	}
	//Output maths to console
	cout << "S1: " << S1 / 10000 << " | S2: " << S2/10000 -  (S1 / 10000)*(S1 / 10000) << " | C: " << (float)c /10000 << endl;
	cout << " f1: " << (float)f1 / 10000 << " f2: " << (float)f2 / 10000 << " f3: " << (float)f3 / 10000
		<< " f4: " << (float)f4 / 10000 << " f5: " << (float)f5 / 10000 << " f6: " << (float)f6 / 10000 << " f7: " << (float)f7 / 10000 << " f8: " << (float)f8 / 10000 << endl;
	system("pause");
}