#include "Card.h"
Card::Card(CardCategory* cat, CardSymbol* symb)
{
	this->_category = cat;
	this->_symbol = symb;
}
Card::~Card() 
{
	delete this->_category;
	delete this->_symbol;
}
int Card::GetOverallPower()
{
	return this->_category->GetPower() +
		this->_symbol->GetPower();
}

bool Card::operator<(Card* c) 
{
	return this->GetOverallPower() < c->GetOverallPower();
}

bool Card::operator>(Card* c)
{
	return this->GetOverallPower() > c->GetOverallPower();
}

bool Card::operator==(Card* c)
{
	return this->GetOverallPower() == c->GetOverallPower();
}

bool Card::operator<=(Card* c)
{
	return this->GetOverallPower() <= c->GetOverallPower();
}

bool Card::operator>=(Card* c)
{
	return this->GetOverallPower() >= c->GetOverallPower();
}