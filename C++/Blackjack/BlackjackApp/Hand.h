#pragma once
#include <vector>
#include "Card.h"

namespace BlackJack
{
	class Hand
	{
	public:
		std::vector<Card*> Cards;
		Hand();
		~Hand();

		void NewHand(int newCardCount);
	};
}