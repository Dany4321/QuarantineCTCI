#pragma once
class CardCategory
{
public:
	void SetPower(int pow);
	int GetPower();
protected:
	int _categoryPower = 0;
};