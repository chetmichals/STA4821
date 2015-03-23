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
		float X1 = (float)distribution(generator) / 10000000;
		float X2 = (float)distribution(generator) / 10000000;

		/* 
		
		//Used for case 2

		float z = (float)distribution(generator) / 10000000;
		float X1 = -1*log(1-z)/2;

		z = (float)distribution(generator) / 10000000;
		float X2 = -1*log(1-z)/2;

		*/

		/*case 3
		float X1 = (float)distribution(generator) / 10000000; //Distrabution from 0 to 1
		float X2 = (float)distribution(generator) / 5000000; //Distrabution from 0 to 2
		*/

		
		/*
		//case 4
		float X1 = (float)distribution(generator) / 10000000;
		X1 = (X1 > .2) ? .3 : 1.3; // Whooooo, A conditional operator. I don't think I'll ever use one of these again, too hard to read
		*/
		
		
		float Y = X1 + X2;
		S1 = S1 + Y;
		S2 = S2 + (Y * Y);
		if ((Y > .4) && ( Y <= 1.4)) c++;

	}
	//Output maths to console
	cout << "S1: " << S1 / 10000 << " | S2: " << S2/10000 -  (S1 / 10000)*(S1 / 10000) << " | C: " << (float)c /10000 << endl;
	system("pause");
}