/*
Written by Chet Michals
Created 04/01/15
STA4821 Homework 6

Show the Untilzation, Probability of Waiting, and average wait time of various random distrabutions
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
float ExponentialDistribution_1_6();
float UniformDistrabution_2();
float DiscreteDistrabution();
float ConstantServiceTime(){return .5;}

//Function takes two distrabution functions are parameters
void RunSimulation(float (*distrabutionFunciton1)());

//Main
int main()
{
	cout << "Exponetional service times" << endl;
	RunSimulation(ExponentialDistribution); 
	cout << "Constant service times" << endl;
	RunSimulation(ConstantServiceTime); 
	cout << "Uniform service times" << endl;
	RunSimulation(UniformDistrabution); 
	cout << "Discrete service times" << endl;
	RunSimulation(DiscreteDistrabution); 
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

//Exponential Distribution with a lambda of 1.6
float ExponentialDistribution_1_6()
{
	float RNG = GenerateNumber();
	float ReturnNumber = -1*log(1-RNG)/1.6;
	return ReturnNumber;
}

//Uniform Distribution between 0 and 2
float UniformDistrabution_2()
{
	return GenerateNumber() * 2;
}

//Discrete distribution which returns ether 1/3 or 2, with an expected value of .5.
float DiscreteDistrabution()
{
	//90% chance to be 1/3, 10% chance to be 2
	float RNG = GenerateNumber();
	if (RNG > .1) return .333; 
	else return 2.0;
}

/* Function takes in two distribution functions and runs a simulation 10k times, showing the expected value, 
variance, and probability that the number will lay between .4 and 1.4 of the two distributions added together
*/
void RunSimulation(float (*distrabutionFunciton1)())
{
	
	
	//S1 is the accumulator to track expected value, S2 is the accumulator to track variance
	//S3 is the accumulator of the times the sum of the random numbers is between .4 and 1.4
	float T = 0;
	float W = 0;
	float SW = 0;
	float SX = 0;
	float X = 0;
	int C = 0;

	//Do 10k simulations, print out info during select simulations
	for (int simulationCount = 1; simulationCount <= 100000; simulationCount++)
	{
		//Generate an Interarrival time
		float IA = ExponentialDistribution_1_6();
		T += IA;
		W += X - IA;
		if (W < 0) W = 0;
		if (W > 0) C++;
		SW += W;
		X = (*distrabutionFunciton1)();
		SX += X;
	}
	//Output the averages of the collected data to console
	cout << "Utilization: " << SX/T <<endl;
	cout << "Prob of Wait: " << 1-(float)C/100000 <<endl;
	cout << "Mean Wait Time: " << SW/100000  <<endl <<endl;
}