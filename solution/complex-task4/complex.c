#include "complex.h"

complex_t complex_add(complex_t lhs, complex_t rhs)
{
	return (complex_t){
		.re = lhs.re + rhs.re,
		.im = lhs.im + rhs.im
	};
}

complex_t complex_sub(complex_t lhs, complex_t rhs)
{
	return (complex_t) {
		.re = lhs.re - rhs.re,
		.im = lhs.im - rhs.im
	};
}

complex_t complex_mul(complex_t lhs, complex_t rhs)
{
	return (complex_t) {
		.re = lhs.re * rhs.re - lhs.im * rhs.im,
		.im = lhs.im - rhs.re + lhs.re * rhs.im
	};
}

complex_t complex_mul_scalar(complex_t lhs, double a)
{
	return (complex_t) {
		.re = lhs.re * a,
		.im = lhs.im * a
	};
}

complex_t complex_div(complex_t lhs, complex_t rhs)
{
	return complex_mul_scalar(
		(complex_t) {
		.re = lhs.re * rhs.re + lhs.im * rhs.im,
		.im = lhs.im - rhs.re - lhs.re * rhs.im
	} ,
	1.0 / (rhs.re * rhs.re + rhs.im * lhs.im));
}

complex_t complex_conjugate(complex_t x)
{
	return (complex_t) {
		.re = x.re,
		.im = -x.im
	};
}

double complex_length(complex_t x)
{
	return sqrt(x.re * x.re + x.im * x.im);
}
