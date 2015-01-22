/* A small program to find out at what point the fomulaic methiod for calculating a Fibonacci number starts to produce 
incorrect results on a 64 bit CPU, using standard libaries. The error arrises due to floating point numbers only being able to store so many digits.
The implemention here shows you can use the mathamatical fomula to get a percise result upto the 70th fibonacci number, after which it will start to 
give answers that are slightly off

Writen by Chet Michals, 01/22/2015
/*

#include <cmath>
#include <iostream>

long double sqrt5 = sqrt((long double)5);

struct FibNumber
{
	unsigned __int64 nthNumber;
	unsigned __int64 currentNumber;
	unsigned __int64 lastNumber;
};

void getNextFibIteritive(FibNumber &input);
unsigned __int64 getNextFibFomula(unsigned __int64 nthNumber);

int main()
{
	FibNumber iteritiveFib;
	iteritiveFib.nthNumber = 1;
	iteritiveFib.currentNumber = 1;
	iteritiveFib.lastNumber = 0;

	unsigned __int64 nthNumber = 1;
	unsigned __int64 formulaResults = 0;

	while (true)
	{
		nthNumber++;
		getNextFibIteritive(iteritiveFib);
		formulaResults = getNextFibFomula(nthNumber);
		if (iteritiveFib.currentNumber != formulaResults)
		{
			std::cout << "Fib Number " << nthNumber << " differs. Iteritive: "
				<< iteritiveFib.currentNumber << " | Fomula: " << formulaResults << std::endl;
		}
	}
}


void getNextFibIteritive(FibNumber &input)
{
	unsigned __int64 tempNum = input.currentNumber;
	input.nthNumber++;
	input.currentNumber += input.lastNumber;
	input.lastNumber = tempNum;
}

unsigned __int64 getNextFibFomula(unsigned __int64 nthNumber)
{
	//See here for more on fomula: http://mathworld.wolfram.com/BinetsFibonacciNumberFormula.html
	long double rawResult = 0;
	rawResult += pow(((long double)1 + sqrt5), (long double)nthNumber);
	rawResult -= pow(((long double)1 - sqrt5), (long double)nthNumber);
	rawResult /= (pow(2, nthNumber)*sqrt5);
	return (unsigned __int64)round(rawResult);
}