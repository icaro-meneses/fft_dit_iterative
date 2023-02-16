/*
 * ======================================================================
 *
 *       Filename:  fft_tdec.h
 *
 *    Description:  Header file for function prototypes for
 *					the implementation of FFT (decimation in
 *					time).
 *
 *        Version:  1.0
 *        Created:  25/01/23 16:29:31
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Icaro Meneses Ferreira de Santana
 *					(Icaro Meneses),
 *					icaro.santana.dev@hotmail.com
 *
 * ======================================================================
 */

#ifndef FFT_TDEC_LIB_H
#define FFT_TDEC_LIB_H

#include <stdbool.h>
#include "complex_type.h"

#define PI	   3.141592653589793f
#define TWO_PI (2.0f * PI)

/*
 * ===  FUNCTION  ==================================================
 *         Name:  fill_vector
 *  Description:  Fill a (Nx1) destination vector with source
 *				  signal vector.
 * =================================================================
 */
void
fill_vector(complex_float* dest_vector,
			complex_float* src_vector,
			const int dest_vector_size,
			const int src_vector_size);

/*
 * ===  FUNCTION  ==================================================
 *         Name:  get_fft_freqs
 *  Description:  Fill a array with the FFT sample frequencies
 * =================================================================
 */
void
get_fft_freqs(float* freq_array,
			  const int window_length,
			  const float sample_spacing);

/*
 * ===  FUNCTION  ==================================================
 *         Name:  bit_reversal
 *  Description:  Performs the bit reversing of the indexes of
 *				  the input coefficients.
 * =================================================================
 */
unsigned int
bit_reversal(unsigned int bit_num, int log2n);

/*
 * ===  FUNCTION  ==================================================
 *         Name:  swap
 *  Description:  Perform a order swap in array data.
 * =================================================================
 */
void
swap(complex_float* num_a, complex_float* num_b);

/*
 * ===  FUNCTION  ==================================================
 *         Name:  fft_dec_time
 *  Description:  Performs the Fast Fourier Transform (Decimation
 *				  in time) of a sampled signal as input and
 *				  returns a vector with the complex values of FFT.
 *				  The parameter inverse_mode determines if the
 *				  procedure performed will be FFT or IFFT.
 * =================================================================
 */
void
fft_dec_time(complex_float* signal,
			 complex_float* result,
			 int N,
			 bool inverse_mode);

/*
 * ===  FUNCTION  ==================================================
 *         Name:  abs_fft_calc
 *  Description:  Calculates the magnitude(absolute value) of
 *				  a previous calculated FFT.
 * =================================================================
 */
float*
abs_fft_calc(complex_float* fft, const int fft_size);

#endif
