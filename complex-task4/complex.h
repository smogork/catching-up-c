#pragma once

typedef struct complex {
	double re;
	double im;
} complex_t;

complex_t complex_add(complex_t lhs, complex_t rhs);
complex_t complex_sub(complex_t lhs, complex_t rhs);
complex_t complex_mul(complex_t lhs, complex_t rhs);
complex_t complex_mul_scalar(complex_t lhs, double a);
complex_t complex_div(complex_t lhs, complex_t rhs);
complex_t complex_conjugate(complex_t x);
double complex_length(complex_t x);

