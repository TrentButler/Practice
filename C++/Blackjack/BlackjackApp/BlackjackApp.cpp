#include "stdafx.h"
#include <vector>
#include <iostream>
#include "BlackjackApp.h"
#include "Card.h"
#include "Hand.h"


//DEALER DEALS PLAYER 2 CARDS
//PLAYER IS PLAYING AGAINST THE COMPUTER
//PLAYER CAN 'STAND' -> KEEP HAND
//PLAYER CAN 'HIT' -> REQUEST ANOTHER CARD
//	- IF PLAYER'S HAND IS LESS THAN 21 THEY CAN HIT AGAIN
//	- IF PLAYER'S HAND IS GREATER THAN 21 THEY LOSE
//AT THE END OF PLAYER'S TURN, EVALUATE THE PLAYER'S HAND AGAINST THE DEALER'S HAND
//DISPLAY RESULTS AND BEGIN ANOTHER TURN


BlackJack::BlackjackApp::BlackjackApp()
{
	Phase = CHOICE;
	QuitGame = false;
	PlayerHand = new Hand();
	ComputerHand = new Hand();

	PlayerHand->NewHand(2);
	ComputerHand->NewHand(2);
}

BlackJack::BlackjackApp::~BlackjackApp()
{
	//DESTROY APP
}

void BlackJack::BlackjackApp::RunGame()
{
	while (!QuitGame)
	{
		switch (Phase)
		{

		case CHOICE:
		{
			if (EvaluatePlayerHand() < 21)
			{
				std::string player_hand = "";
				std::string computer_hand = "";

				for (int i = 0; i < PlayerHand->Cards.size(); i++)
				{
					auto card = PlayerHand->Cards.at(i);
					player_hand += "|" + card->Value + "| ";
				}

				for (int i = 0; i < ComputerHand->Cards.size(); i++)
				{
					auto card = ComputerHand->Cards.at(i);

					if (i == 0)
					{
						computer_hand += "|" + card->Value + "| ";
					}
					else
					{
						computer_hand += "|?| ";
					}					
				}

				auto player_output = "YOUR HAND -> " + player_hand + "-> " + std::to_string(EvaluatePlayerHand()) + "\n\n";
				auto computer_output = "DEALER HAND -> " + computer_hand + "\n\n";
				std::cout << player_output << computer_output;

				std::cout << "S = STAND || H = HIT || Q = QUIT -> \n";

				std::string player_choice;
				std::cin >> player_choice;

				if (player_choice == "Q" || player_choice == "q")
				{
					QuitGame = true;
					break;
				}

				if (player_choice == "S" || player_choice == "s")
				{
					Phase = EVALUATE;
					break;
				}

				if (player_choice == "H" || player_choice == "h")
				{
					auto card = new Card();
					card->RandomCard();
					PlayerHand->Cards.push_back(card);
				}
			}
			else
			{
				Phase = EVALUATE;
			}

			break;
		}

		case EVALUATE:
		{
			CompareHands();

			std::cout << "N = NEW HAND || Q = QUIT -> \n";

			std::string player_choice;
			std::cin >> player_choice;

			if (player_choice == "Q" || player_choice == "q")
			{
				QuitGame = true;
				break;
			}

			if (player_choice == "N" || player_choice == "n")
			{
				PlayerHand->NewHand(2);
				ComputerHand->NewHand(2);
				Phase = CHOICE;
				break;
			}

			break;
		}

		default:
		{
			break;
		}
		}
	}
}

int BlackJack::BlackjackApp::EvaluatePlayerHand()
{
	int player_score = 0;

	for (int i = 0; i < PlayerHand->Cards.size(); i++)
	{
		auto card = PlayerHand->Cards.at(i);
		player_score += card->NumberValue;
	}

	return player_score;
}

int BlackJack::BlackjackApp::EvaluateComputerHand()
{
	int computer_score = 0;

	for (int i = 0; i < ComputerHand->Cards.size(); i++)
	{
		auto card = ComputerHand->Cards.at(i);
		computer_score += card->NumberValue;
	}

	return computer_score;
}

std::string BlackJack::BlackjackApp::CompareHands()
{
	auto player_score = EvaluatePlayerHand();
	auto computer_score = EvaluateComputerHand();

	std::string player_result = "";
	std::string computer_result = "";
	std::string result = "";

	player_result += "PLAYER SCORE |" + std::to_string(player_score) + "|";
	computer_result += "COMPUTER SCORE |" + std::to_string(computer_score) + "|";

	//CHECK FOR SCORE OVER 21
	if (player_score > 21)
	{
		player_result += " BUST\n";
	}
	if (computer_score > 21)
	{
		computer_result += " BUST\n";
	}

	//CHECK FOR TIE
	if (player_score == computer_score)
	{
		result = "DRAW\n";
		player_result += "\n";
		computer_result += "\n";

		printf(player_result.c_str());
		printf(computer_result.c_str());
		printf(result.c_str());
		return result;
	}

	//CHECK FOR BLACKJACK
	if (player_score == 21)
	{
		result = "PLAYER WIN\n";
		player_result += "\n";
		computer_result += "\n";

		printf(player_result.c_str());
		printf(computer_result.c_str());
		printf(result.c_str());
		return result;
	}
	if (computer_score == 21)
	{
		result = "COMPUTER WIN\n";
		player_result += "\n";
		computer_result += "\n";

		printf(player_result.c_str());
		printf(computer_result.c_str());
		printf(result.c_str());
		return result;
	}

	if (player_score > 21 && computer_score <= 21)
	{
		result = "COMPUTER WIN\n";
		player_result += "\n";
		computer_result += "\n";

		printf(player_result.c_str());
		printf(computer_result.c_str());
		printf(result.c_str());
		return result;
	}
	if (computer_score > 21 && player_score <= 21)
	{
		result = "PLAYER WIN\n";
		player_result += "\n";
		computer_result += "\n";

		printf(player_result.c_str());
		printf(computer_result.c_str());
		printf(result.c_str());
		return result;
	}

	result = (player_score > computer_score) ? "PLAYER WIN\n" : "COMPUTER WIN\n";
	player_result += "\n";
	computer_result += "\n";

	printf(player_result.c_str());
	printf(computer_result.c_str());
	printf(result.c_str());
	return result;
}