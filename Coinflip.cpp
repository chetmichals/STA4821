//Something quickly thrown together for an assignement, simulates a coin being flipped 200 times and output it in 10 lines of 20. 

#include  <iostream>
#include <chrono>
#include <random>

void main()
{
	std::default_random_engine generator(std::chrono::system_clock::now().time_since_epoch().count());
	std::uniform_int_distribution<int> distribution(1, 2);
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (distribution(generator) == 1)
			{
				std::cout << "X";
			}
			else
			{
				std::cout << "O";
			}
		}
		std::cout << std::endl;
	}
	system("pause");
}