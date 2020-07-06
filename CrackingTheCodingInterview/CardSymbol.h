#pragma once
class CardSymbol 
{
public:
	void SetPower(int pow);
	int GetPower();
protected:
	int _symbolPower = 0;
};