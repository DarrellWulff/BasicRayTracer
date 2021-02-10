#include "MathFunctions.h"

float MathFunctions::clamp(float value, float lowValue, float highValue)
{
	if (value >= highValue) 
	{
		value = highValue;
	}
	else if(value <= lowValue)
	{
		value = lowValue;
	}

	return value;
}
