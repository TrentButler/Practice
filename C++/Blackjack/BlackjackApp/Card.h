#pragma once
#include <string>

namespace BlackJack
{
	class Card
	{
	public:
		std::string Value;
		int NumberValue;

		Card();
		Card(int value);
		~Card();

		void RandomCard();
		const char* GetValue();
	};
}