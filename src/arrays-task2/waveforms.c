#include "waveforms.h"
#include <stdlib.h>
#include <string.h>

#define _USE_MATH_DEFINES
#include <math.h>

int16_t* generate_silence(int size)
{
	const size_t buffer_size = sizeof(int16_t) * size;

	int16_t* res = malloc(buffer_size);
	if (!res)
		return NULL;
	memset(res, 0, buffer_size);

	return res;
}

int16_t* generate_sin(int period_length, int16_t amplitude, int size)
{
	const size_t buffer_size = sizeof(int16_t) * size;
	int16_t* res = malloc(buffer_size);
	if (!res)
		return NULL;
	
	int period_idx = 0;
	while (period_idx < size)
	{
		int last_idx = min(size, period_idx + period_length) - period_idx;
		for (int i = 0; i < last_idx; ++i) {
			double arg = ((double)i / period_length) * 2.0 * M_PI;
			res[period_idx + i] = (int16_t)round(amplitude * sin(arg));
		}
		period_idx += period_length;
	}

	return res;
}

void change_phase(int16_t* waveform, int size, int shift)
{
	if (shift == 0)
		return;

	const size_t buffer_size = sizeof(int16_t) * abs(shift);
	int16_t* buffer = malloc(buffer_size);
	if (!buffer)
		return;

	if (shift > 0)
	{
		// Copy the end of waveform to temporary buffer
		memcpy(buffer, waveform + size - shift, buffer_size);
		// Copy the rest of the waveform to the end
		memmove(waveform + shift, waveform, (size - shift) * sizeof(int16_t));
		// Copy the buffer to the begining of the waveform
		memcpy(waveform, buffer, buffer_size);
	}
	else
	{
		shift = abs(shift);

		// Copy the begining of waveform to temporary buffer
		memcpy(buffer, waveform, buffer_size);
		// Copy the rest of the waveform to the front
		memmove(waveform , waveform + shift, (size - shift) * sizeof(int16_t));
		// Copy the buffer to the end of the waveform
		memcpy(waveform, waveform + size - shift, buffer_size);
	}

	free(buffer);
}

void combine_waveforms(int16_t const* lhs, int16_t const* rhs, int16_t* result, int size)
{
	for (int i = 0; i < size; ++i)
		result[i] = lhs[i] + rhs[i];
}
