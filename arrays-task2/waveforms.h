#pragma once
#include <stdint.h>

/// <summary>
/// 
/// </summary>
/// <param name="size"></param>
/// <returns></returns>
int16_t* generate_silence(int size);

/// <summary>
/// 
/// </summary>
/// <param name="period_length"></param>
/// <param name="amplitude"></param>
/// <param name="size"></param>
/// <returns></returns>
int16_t* generate_sin(int period_length, int16_t amplitude, int size);

/// <summary>
/// 
/// </summary>
/// <param name="waveform"></param>
/// <param name="size"></param>
/// <param name="shift"></param>
void change_phase(int16_t* waveform, int size, int shift);

/// <summary>
/// 
/// </summary>
/// <param name="lhs"></param>
/// <param name="rhs"></param>
/// <param name="result"></param>
/// <param name="size"></param>
void combine_waveforms(int16_t const* lhs, int16_t const* rhs, int16_t* result, int size);
