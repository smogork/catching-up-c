#pragma once
#include <stdint.h>

/// <summary>
/// This function generates an array of 0 of given size.
/// </summary>
/// <param name="size">Number of samples to generate.</param>
/// <returns>Pointer to the dynamically alocated array of silence samples. Ownership is passed to the caller.</returns>
int16_t* generate_silence(int size);

/// <summary>
/// This function generates an array of sinus function samples. You have to pass the period length and amplitude of the sinus function.
/// </summary>
/// <param name="period_length">Period length in samples.</param>
/// <param name="amplitude">Amplitude of sinus function.</param>
/// <param name="size">Size of the generated array. Number of total samples.</param>
/// <returns>Pointer to the dynamically alocated array of sinus waveform samples. Ownership is passed to the caller.</returns>
int16_t* generate_sin(int period_length, int16_t amplitude, int size);

/// <summary>
/// This function changes the phase of the waveform in place. 
/// </summary>
/// <param name="waveform">Pointer to the waveform to modify.</param>
/// <param name="size">Number of samples in passed waveform.</param>
/// <param name="shift">How many samples the waveform will be moved.</param>
void change_phase(int16_t* waveform, int size, int shift);

/// <summary>
/// This functions combine two waveforms into one. It uses normal additive operation.
/// </summary>
/// <param name="lhs">Waveform to combine.</param>
/// <param name="rhs">Waveform to combine.</param>
/// <param name="result">Buffer where the result of addition will be written.</param>
/// <param name="size">Size of all waveforms passed to the function (inputs and outputs).</param>
void combine_waveforms(int16_t const* lhs, int16_t const* rhs, int16_t* result, int size);
