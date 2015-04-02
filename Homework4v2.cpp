/*
Written by Chet Michals
Created 03/23/15, edited 04/01/15
STA4821 Homework 4

Used to show the difference in variance and probability of different distribution functions 
*/

#include <iostream>
#include <chrono>
#include <random>

using namespace std;

//Global RNG generator for use by the different distribution functions. Uses the system clock for the seeding of the RNG.
default_random_engine generator(chrono::system_clock::now().time_since_epoch().count());
uniform_int_distribution<int> distribution(0, 10000000);

//Function Prototypes
float GenerateNumber();
float UniformDistrabution();
float ExponentialDistribution();
float UniformDistrabution_2();
float DiscreteDistrabution();

//Function takes two distrabution functions are parameters
void RunSimulation(float (*distrabutionFunciton1)(), float (*distrabutionFunciton2)());

//Main
int main()
{
	RunSimulation(UniformDistrabution,UniformDistrabution); //Two uniform distributions between 0 and 1
	RunSimulation(ExponentialDistribution,ExponentialDistribution); //Two Exponential Distribution with a lambda of 2
	RunSimulation(UniformDistrabution,UniformDistrabution_2); //One uniform distribution between 0 and 1, and one between 0 and 2
	RunSimulation(DiscreteDistrabution,DiscreteDistrabution); //Discrete distribution that can be ether .3 or 1.3
	system("pause");
}

//Function definitions

//Return a float between 0 and 1
float GenerateNumber()
{
	return (float)distribution(generator) / 10000000;
} 

//Uniform Continues Distribution between 0 and 1
float UniformDistrabution()
{	
	return GenerateNumber();
}

//Exponential Distribution with a lambda of 2
float ExponentialDistribution()
{
	float RNG = GenerateNumber();
	float ReturnNumber = -1*log(1-RNG)/2;
	return ReturnNumber;
}

//Uniform Distribution between 0 and 2
float UniformDistrabution_2()
{
	return GenerateNumber() * 2;
}

//Discrete distribution which returns ether .3 or 1.3, but an expected value of .50
float DiscreteDistrabution()
{
	//80% chance to be .3, 20% chance to be 1.3
	float RNG = GenerateNumber();
	if (RNG > .2) return .3; 
	else return 1.3;
}

/* Function takes in two distribution functions and runs a simulation 10k times, showing the expected value, 
variance, and probability that the number will lay between .4 and 1.4 of the two distributions added together
*/
void RunSimulation(float (*distrabutionFunciton1)(), float (*distrabutionFunciton2)())
{
	//S1 is the accumulator to track expected value, S2 is the accumulator to track variance
	//S3 is the accumulator of the times the sum of the random numbers is between .4 and 1.4
	float S1 = 0;
	float S2 = 0;
	int S3 = 0;

	//Do 10k simulations, print out info during select simulations
	for (int simulationCount = 1; simulationCount <= 10000; simulationCount++)
	{

		// Generate two random numbers (X1 and X2) add them together (Y)
		float X1 = (*distrabutionFunciton1)();
		float X2 = (*distrabutionFunciton2)();
		float Y = X1 + X2;
		S1 = S1 + Y;
		S2 = S2 + (Y * Y);
		if ((Y > .4) && ( Y <= 1.4)) S3++;
	}
	//Output the averages of the collected data to console
	cout << "Expec Val: " << S1 / 10000 << " | Variance: " << S2/10000 -  (S1 / 10000)*(S1 / 10000) 
	<< " | Probability [.4 < Y <= 1.4]: " << (float)S3 /10000 << endl;
}