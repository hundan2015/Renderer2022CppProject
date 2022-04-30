#pragma once
#include "Compoment.h"

class Movement :
	public Component
{
	float speed;
public:
	void Update() override;
	Movement(float spd);
};

