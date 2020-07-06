#include "CardFactory.h"
#include "Club.h";
#include "Diamond.h";
#include "Heart.h";
#include "Spade.h";
#include "As.h";
#include "Joker.h";
#include "King.h";
#include "Number.h";
#include "Prince.h";
#include "Queen.h";
vector<Card*> CardFactory::GenerateBlackJackDeck() 
{
	vector<Card*> deck;
	for (short i = 0; i < 4; ++i) 
	{
		for (short j = 2; j < 11; ++j) 
		{
			Card* card = this->GenerateCard(eNumber, (EnumSymbol)i);
			card->_category->SetPower(j);
			deck.push_back(card);
		}

		Card* joker = this->GenerateCard(eJoker, (EnumSymbol)i);
		joker->_category->SetPower(20);
		deck.push_back(joker);

		Card* as = this->GenerateCard(eAs, (EnumSymbol)i);
		as->_category->SetPower(15);
		deck.push_back(as);

		Card* king = this->GenerateCard(eKing, (EnumSymbol)i);
		king->_category->SetPower(14);
		deck.push_back(king);

		Card* prince = this->GenerateCard(ePrince, (EnumSymbol)i);
		prince->_category->SetPower(13);
		deck.push_back(prince);

	}

	return deck;
}
Card* CardFactory::GenerateCard(EnumCategory wishedCategory, EnumSymbol wishedSymbol)
{
	CardCategory*  category = nullptr;
	CardSymbol* symbol = nullptr;
	switch (wishedSymbol)
	{
		case CardFactory::eClub:
			symbol = new Club();
			break;
		case CardFactory::eDiamond:
			symbol = new Diamond();
			break;
		case CardFactory::eHeart:
			symbol = new Heart();
			break;
		case CardFactory::eSpade:
			symbol = new Spade();
			break;
	}
	switch (wishedCategory)
	{
		case CardFactory::eJoker:
			category = new Joker();
			break;
		case CardFactory::eAs:
			category = new As();
			break;
		case CardFactory::eKing:
			category = new King();
			break;
		case CardFactory::eQueen:
			category = new Queen();
			break;
		case CardFactory::ePrince:
			category = new Prince();
			break;
		case CardFactory::eNumber:
			category = new Number();
			break;
	}
	return new Card(category, symbol);
}