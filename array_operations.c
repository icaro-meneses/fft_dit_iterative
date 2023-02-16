/*
 * ======================================================================
 *
 *       Filename:  array_operations.c
 *
 *    Description:  Source file for array_operations.h
 *
 *        Version:  1.0
 *        Created:  22/01/23 17:32:34
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Icaro Meneses Ferreira de Santana
 *					(Icaro Meneses),
 *					icaro.santana.dev@hotmail.com
 *
 * ======================================================================
 */

#include "array_operations.h"
#include "complex_type.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int
get_size(int num)
{
	return (int)powf(2.0f, ceilf(logf((float)num) / logf(2.0f)));
}

int
gcd(int num_a, int num_b)
{
	int aux;

	while (num_b != 0)
	{
		aux	  = num_a % num_b;

		num_a = num_b;
		num_b = aux;
	}

	return num_a;
}

float*
vector_create(const int size_N)
{
	float* vector_output_ptr;

	vector_output_ptr = (float*)malloc(size_N * sizeof(float));

	if (vector_output_ptr == NULL)
	{
		printf("Error in memory allocation for %s vector.\n",
			   "vector_output_ptr");
		exit(EXIT_FAILURE);
	}

	for (int item = 0; item < size_N; item++)
	{
		vector_output_ptr[item] = 0.0f;
	}

	return vector_output_ptr;
}

complex_float*
vector_create_cpx(const int size_N)
{
	complex_float* vector_output_ptr;

	vector_output_ptr =
		(complex_float*)malloc(size_N * sizeof(complex_float));

	if (vector_output_ptr == NULL)
	{
		printf("Error in memory allocation for %s vector.\n",
			   "vector_output_ptr");
		exit(EXIT_FAILURE);
	}

	for (int item = 0; item < size_N; item++)
	{
		vector_output_ptr[item].real_part = 0.0f;
		vector_output_ptr[item].imag_part = 0.0f;
	}

	return vector_output_ptr;
}

void
print_vector_cpx(complex_float* vector, const int size_N)
{
	printf("Column vector (%d x 1) represented as row vector:\n",
		   size_N);
	for (int item = 0; item < size_N; item++)
	{
		printf("\t(%6.2f + %6.2fj) ",
			   vector[item].real_part,
			   vector[item].imag_part);
	}
	printf("\n\n");
}

void
print_vector(float* vector, const int size_N)
{
	printf("Column vector (%d x 1) represented as row vector:\n",
		   size_N);
	for (int item = 0; item < size_N; item++)
	{
		printf("\t%6.2f ", vector[item]);
	}
	printf("\n\n");
}

void
vector_delete_cpx(complex_float* vector)
{
	free(vector);
}

void
vector_delete(float* vector)
{
	free(vector);
}
