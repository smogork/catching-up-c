#pragma once

/// <summary>
/// This function takes two integers and adds them toghether.
/// </summary>
/// <param name="lhs">Left side of addition operator.</param>
/// <param name="rhs">Right side of addition operator.</param>
/// <returns>A result of addition.</returns>
int add_integers(int lhs, int rhs);

/// <summary>
/// This function takes two integers and adds them toghether.
/// </summary>
/// <param name="lhs">Left side of addition operator.</param>
/// <param name="rhs">Right side of addition operator.</param>
/// <param name="result">Output parameter where the result of addition will be written.</param>
void add_integers2(int lhs, int rhs, int* result);

/// <summary>
/// This function takes two interegrs and incements the first one by value of the second one.
/// </summary>
/// <param name="lhs">Number to be incremented.</param>
/// <param name="rhs">Value to increment</param>
void add_integers3(int lhs, int rhs);

/// <summary>
/// This function takes two interegrs and incements the first one by value of the second one.
/// </summary>
/// <param name="lhs">Number to be incremented.</param>
/// <param name="rhs">Value to increment</param>
void add_integers4(int* lhs, int rhs);

/// <summary>
/// This function takes two unsigned integers and adds them toghether.
/// </summary>
/// <param name="lhs">Left side of addition operator.</param>
/// <param name="rhs">Right side of addition operator.</param>
/// <returns>A result of addition.</returns>
unsigned int add_unsigned(unsigned int lhs, unsigned int rhs);