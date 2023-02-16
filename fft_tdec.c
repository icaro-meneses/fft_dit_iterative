/*
 * ======================================================================
 *
 *       Filename:  fft_tdec.c
 *
 *    Description:  Source file for function implementation
 *					of FFT (decimation in time).
 *
 *        Version:  1.0
 *        Created:  25/01/23 16:32:02
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Icaro Meneses Ferreira de Santana
 *					(Icaro Meneses),
 *					icaro.santana.dev@hotmail.com
 *
 * ======================================================================
 */

#include "fft_tdec.h"
#include "complex_type.h"
#include "array_operations.h"
#include <stdio.h>
#include <math.h>

void
fill_vector(complex_float* dest_vector,
			complex_float* src_vector,
			const int dest_vector_size,
			const int src_vector_size)
{
	int fill_op_size = src_vector_size;

	/* If the size of source vector is greater than destination
	 * vector, the source vector size is cut-off to same size of
	 * destination vector.
	 * Otherwise, the source vector is automatically zero-padded
	 * */
	if (src_vector_size > dest_vector_size)
	{
		fill_op_size = dest_vector_size;
	}

	for (int item = 0; item < fill_op_size; item++)
	{
		dest_vector[item].real_part = src_vector[item].real_part;
		dest_vector[item].imag_part = src_vector[item].imag_part;
	}
}

void
get_fft_freqs(float* freq_array,
			  const int window_length,
			  const float sample_spacing)
{
	int middle = ((window_length - 1) / 2) + 1;
	int i;
	int aux = 0;

	for (i = 0; i < middle; i++)
	{
		freq_array[i] = i;
	}

	i	= middle;
	aux = (-1) * (window_length / 2);
	while (aux < 0)
	{
		freq_array[i] = aux;

		aux++;
		i++;
	}

	for (i = 0; i < window_length; i++)
	{
		freq_array[i] =
			(float)freq_array[i] / (window_length * sample_spacing);
	}
}

unsigned int
bit_reversal(unsigned int bit_num, int log2n)
{
	int result = 0;

	for (int i = 0; i < log2n; i++)
	{
		if (bit_num & (1 << i))
		{
			result |= 1 << (log2n - 1 - i);
		}
	}

	return result;
}

void
swap(complex_float* num_a, complex_float* num_b)
{
	complex_float temp_value = {.real_part = 0.0f, .imag_part = 0.0f};

	temp_value.real_part	 = num_a->real_part;
	temp_value.imag_part	 = num_a->imag_part;
	num_a->real_part		 = num_b->real_part;
	num_a->imag_part		 = num_b->imag_part;
	num_b->real_part		 = temp_value.real_part;
	num_b->imag_part		 = temp_value.imag_part;
}

void
fft_dec_time(complex_float* signal,
			 complex_float* result,
			 int N,
			 bool inverse_mode)
{
	int log2n = 0;

	while ((1 << log2n) < N)
	{
		log2n++;
	}
	fill_vector(result, signal, N, N);

	for (int index = 0; index < N; index++)
	{
		int reversal = bit_reversal(index, log2n);

		if (index < reversal)
		{
			swap(&result[index], &result[reversal]);
		}
	}
	float argument	 = (!inverse_mode) ? (-TWO_PI) : (TWO_PI);
	complex_float W	 = {.real_part = 0.0f, .imag_part = 0.0f};
	complex_float Wk = {.real_part = 1.0f, .imag_part = 0.0f};

	unsigned int index_even;
	unsigned int index_odd;

	complex_float even_part;
	complex_float odd_part;

	for (int r = 1; r <= log2n; r++)
	{
		int m		   = 1 << r;
		int m_over_two = m >> 1;

		float theta	   = argument / m;

		W.real_part	   = cosf(theta);
		W.imag_part	   = sinf(theta);

		for (int s = 0; s < N; s += m)
		{
			Wk.real_part = 1.0f;
			Wk.imag_part = 0.0f;

			for (int t = 0; t < m_over_two; t++)
			{
				index_even			= s + t;
				index_odd			= index_even + m_over_two;

				even_part.real_part = result[index_even].real_part;
				even_part.imag_part = result[index_even].imag_part;

				odd_part.real_part =
					complex_mult_real(Wk.real_part,
									  Wk.imag_part,
									  result[index_odd].real_part,
									  result[index_odd].imag_part);
				odd_part.imag_part =
					complex_mult_imag(Wk.real_part,
									  Wk.imag_part,
									  result[index_odd].real_part,
									  result[index_odd].imag_part);

				result[index_even].real_part =
					even_part.real_part + odd_part.real_part;
				result[index_even].imag_part =
					even_part.imag_part + odd_part.imag_part;
				result[index_odd].real_part =
					even_part.real_part - odd_part.real_part;
				result[index_odd].imag_part =
					even_part.imag_part - odd_part.imag_part;

				odd_part.real_part = complex_mult_real(Wk.real_part,
													   Wk.imag_part,
													   W.real_part,
													   W.imag_part);
				odd_part.imag_part = complex_mult_imag(Wk.real_part,
													   Wk.imag_part,
													   W.real_part,
													   W.imag_part);

				Wk				   = odd_part;
			}
		}
	}
}

float*
abs_fft_calc(complex_float* fft, const int fft_size)
{
	float* fft_abs_output;

	fft_abs_output = vector_create(fft_size);

	for (int item = 0; item < fft_size; item++)
	{
		fft_abs_output[item] = sqrtf(powf(fft[item].real_part, 2.0f) +
									 powf(fft[item].imag_part, 2.0f));
	}

	return fft_abs_output;
}
