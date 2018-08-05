#include "stdafx.h"
#include "Card.h"
#include <time.h>
#include <random>

BlackJack::Card::Card()
{
	//srand(time(NULL));
	Value = "";
	NumberValue = NULL;
}

BlackJack::Card::Card(int value)
{
	auto _value = value;

	if (_value >= 0 && _value <= 13)
	{
		if (_value == 0)
		{
			Value = "A";
			NumberValue = _value;
			return;
		}
		if (_value == 11)
		{
			Value = "J";
			NumberValue = _value;
			return;
		}
		if (_value == 12)
		{
			Value = "Q";
			NumberValue = _value;
			return;
		}
		if (_value == 13)
		{
			Value = "K";
			NumberValue = _value;
			return;
		}
		else
		{
			//CONVERT INT TO STRING
			Value = std::to_string(_value);
			NumberValue = _value;
			return;
		}
	}
}

BlackJack::Card::~Card()
{
}

void BlackJack::Card::RandomCard()
{
	auto _value = rand() % 13 + 0;

	if (_value == 0)
	{
		Value = "A";
		NumberValue = _value;
		return;
	}
	if (_value == 11)
	{
		Value = "J";
		NumberValue = _value;
		return;
	}
	if (_value == 12)
	{
		Value = "Q";
		NumberValue = _value;
		return;
	}
	if (_value == 13)
	{
		Value = "K";
		NumberValue = _value;
		return;
	}
	else
	{
		//CONVERT INT TO STRING
		Value = std::to_string(_value);
		NumberValue = _value;
		return;
	}
}

const char * BlackJack::Card::GetValue()
{
	return Value.c_str();
}