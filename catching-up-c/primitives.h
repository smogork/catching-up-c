#pragma once

/// <summary>
/// This functions randomizes an integer number in range [from, to).
/// </summary>
/// <param name="from">Lower bound of randomization ranage (inclusive).</param>
/// <param name="to">Upper bound of randomization range (exclusive).</param>
/// <returns>Newly randomized number in given range.</returns>
int rand_int(int from, int to);

/// <summary>
/// This functions randomizes a float number in range [from, to).
/// </summary>
/// <param name="from">Lower bound of randomization ranage (inclusive).</param>
/// <param name="to">Upper bound of randomization range (exclusive).</param>
/// <returns>Newly randomized number in given range.</returns>
float rand_float(float from, float to);

/// <summary>
/// This functions randomizes a byte.
/// </summary>
/// <returns>Newly randomized byte.</returns>
unsigned char rand_byte();

/// <summary>
/// This function generates a character which can be represented by ASCII encoding.
/// </summary>
/// <returns>Newly randomize human readable character.</returns>
char rand_character();