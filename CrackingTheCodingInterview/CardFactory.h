#pragma once
#include <vector>
#include "Card.h";
using namespace std;
class CardFactory 
{
public:
	vector<Card*> GenerateBlackJackDeck();
	enum EnumCategory 
	{
		eJoker,
		eAs,
		eKing,
		eQueen,
		ePrince,
		eNumber
	};
	enum EnumSymbol
	{
		eClub,
		eDiamond,
		eHeart,
		eSpade
	};
private:
	Card* GenerateCard(EnumCategory wishedCategory, EnumSymbol wishedSymbol);
};