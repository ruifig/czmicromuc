#pragma once

#include "crazygaze/micromuc/czmicromuc.h"

namespace cz
{

inline float mapValue(float x, float in_min, float in_max, float out_min, float out_max)
{
	return (((out_max - out_min) * (x - in_min)) / (in_max - in_min)) + out_min;
}

inline bool isNearlyEqual(float a, float b, float errorTolerance = 1.e-8f)
{
	return abs(a-b) <= errorTolerance;
}

template<typename T>
T clamp(T value, T min, T max)
{
	if (value < min)
		return min;
	else if (value > max)
		return max;
	else
		return value;
}

struct StandardDeviation
{
	float mean;
	float stdDeviation;
};

template<typename T>
StandardDeviation calcStandardDeviation(const T* samples, int numSamples)
{
	StandardDeviation res;
	float sum = 0;
	for(int i=0; i<numSamples; ++i)
	{
		sum += samples[i];
	}

	res.mean = sum / static_cast<float>(numSamples);

	float sumSqr = 0;
	for(int i=0; i<numSamples; ++i)
	{
		float deviation = static_cast<float>(samples[i]) - res.mean;
		sumSqr += deviation * deviation;
	}

	float variance = sumSqr / static_cast<float>(numSamples);
	res.stdDeviation = std::sqrt(variance);
	return res;
}
} // namespace cz

