#pragma once
#include "Hand.h"

namespace BlackJack
{
	enum BlackJackPhase
	{
		CHOICE = 0,
		EVALUATE = 1,
	};

	class BlackjackApp
	{
	public:
		BlackJackPhase Phase;
		bool QuitGame;
		Hand* PlayerHand;
		Hand* ComputerHand;

		BlackjackApp();
		~BlackjackApp();
		void RunGame();
		int EvaluatePlayerHand();
		int EvaluateComputerHand();
		std::string CompareHands();
	};
}