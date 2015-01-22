#include <iostream>
#include <chrono>
#include <random>

using namespace std;

int main()
{
	//Ensures an even distrabution of random numbers between 1 and 365. Uses the system clock for the seeding of the RNG.
	default_random_engine generator(chrono::system_clock::now().time_since_epoch().count());
	uniform_int_distribution<int> distribution(1, 365);

	int runningAverage = 0;
	int currentPerson = 0;

	//Do 10k simulations, print out info during select simulations
	for (int simulationCount = 1; simulationCount <= 10000; simulationCount++)
	{
		currentPerson = 0;
		do
		{
			currentPerson++;
		} while (distribution(generator) > currentPerson);
		runningAverage += currentPerson + 1;

		switch (simulationCount)
		{
			case 1:
			case 2:
			case 3:
			case 4:
			case 5:
			case 10:
			case 25:
			case 50:
			case 100:
			case 1000:
			case 10000:
				 cout << "Simulation Number: " << simulationCount << ": " 
					 << currentPerson << " People in simulation | Running Average: " << (float)runningAverage / (float)simulationCount << endl;
				 break;
		}

	}
	system("pause");
}