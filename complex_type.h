/*
 * ======================================================================
 *
 *       Filename:  complex_type.h
 *
 *    Description:  Header file for complex number types:
 *					z = a + j*b
 *
 *        Version:  1.0
 *        Created:  15/02/23 22:15:34
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Icaro Meneses Ferreira de Santana
 *					(Icaro Meneses),
 *					icaro.santana.dev@hotmail.com
 *
 * ======================================================================
 */

#ifndef COMPLEX_TYPE_H_LIB
#define COMPLEX_TYPE_H_LIB

typedef struct complex_float
{
	float real_part;
	float imag_part;
} complex_float;

typedef struct complex_double
{
	double real_part;
	double imag_part;
} complex_double;

#define complex_mult_real(num_a_real,                                \
						  num_a_imag,                                \
						  num_b_real,                                \
						  num_b_imag)                                \
	(num_a_real * num_b_real - num_a_imag * num_b_imag)
#define complex_mult_imag(num_a_real,                                \
						  num_a_imag,                                \
						  num_b_real,                                \
						  num_b_imag)                                \
	(num_a_real * num_b_imag + num_a_imag * num_b_real)

#endif
