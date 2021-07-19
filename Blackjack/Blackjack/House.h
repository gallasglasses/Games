#pragma once

#include "GenericPlayer.h"
#include "Card.h"

class House : public GenericPlayer
{
public:
	House(const std::string& pName = "");
	virtual bool isHitting() const;
	void FlipFirstCard();

	virtual ~House();
};