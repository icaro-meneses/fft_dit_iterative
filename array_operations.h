/*
 * ======================================================================
 *
 *       Filename:  array_operations.h
 *
 *    Description:  Header file for array operations function
 *					prototypes.
 *
 *        Version:  1.0
 *        Created:  22/01/23 17:26:41
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Icaro Meneses Ferreira de Santana
 *					(Icaro Meneses),
 *					icaro.santana.dev@hotmail.com
 *
 * ======================================================================
 */

#ifndef ARRAY_OP_LIB_H
#define ARRAY_OP_LIB_H

#include "complex_type.h"

/*
 * ===  FUNCTION  ==================================================
 *         Name:  get_size
 *  Description:  Determines the size of a signal to power
 *				  of 2.
 * =================================================================
 */
int
get_size(int num);

/*
 * ===  FUNCTION  ==================================================
 *         Name:  gcd
 *  Description:  Determines the Greater Common Divisor
 *				  between two integers.
 * =================================================================
 */
int
gcd(int num_a, int num_b);

float*
vector_create(const int size_N);

/*
 * ===  FUNCTION  ==================================================
 *         Name:  vector_create_cpx
 *  Description:  Create a complex (Nx1) matrix defined by size.
 * =================================================================
 */
complex_float*
vector_create_cpx(const int size_N);

/*
 * ===  FUNCTION  ==================================================
 *         Name:  print_vector_cpx
 *  Description:  Print the complex (Nx1) vector in stdout.
 * =================================================================
 */
void
print_vector_cpx(complex_float* vector, const int size_N);

/*
 * ===  FUNCTION  ==================================================
 *         Name:  print_vector_cpx
 *  Description:  Print the (Nx1) vector in stdout.
 * =================================================================
 */
void
print_vector(float* vector, const int size_N);

/*
 * ===  FUNCTION  ==================================================
 *         Name:  matrix_delete_cpx
 *  Description:  Free the memory allocated in complex vector
 * =================================================================
 */
void
vector_delete_cpx(complex_float* vector);

/*
 * ===  FUNCTION  ==================================================
 *         Name:  matrix_delete_cpx
 *  Description:  Free the memory allocated in vector
 * =================================================================
 */
void
vector_delete(float* vector);

#endif
