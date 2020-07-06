#pragma once
#include "CardCategory.h";
#include "CardSymbol.h";
class CardFactory;
class Card 
{
public:
	friend CardFactory;
	Card(CardCategory* cat, CardSymbol* symb);
	~Card();
	int GetOverallPower();
	bool operator<(Card* c);
	bool operator>(Card* c);
	bool operator==(Card* c);
	bool operator<=(Card* c);
	bool operator>=(Card* c);
protected:
	CardCategory* _category = nullptr;
	CardSymbol* _symbol = nullptr;
};