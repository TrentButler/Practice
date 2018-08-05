#include "stdafx.h"
#include "Hand.h"

BlackJack::Hand::Hand()
{
}

BlackJack::Hand::~Hand()
{
}

void BlackJack::Hand::NewHand(int newCardCount)
{
	Cards.clear();
	
	for (int i = 0; i < newCardCount; i++)
	{
		auto card = new Card();
		card->RandomCard();
		Cards.push_back(card);
	}
}