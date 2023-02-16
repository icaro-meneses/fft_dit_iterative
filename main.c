/*
 * ======================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  FFT by decimation in time
 *
 *        Version:  1.0
 *        Created:  25/01/23 01:32:29
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Icaro Meneses Ferreira de Santana
 *					(Icaro Meneses),
 *					icaro.santana.dev@hotmail.com
 *
 * ======================================================================
 */

#include <stdio.h>
#include "complex_type.h"
#include <math.h>
#include "array_operations.h"
#include "fft_tdec.h"
#include "out_file.h"

#define FFT_SIZE 8192

int
main(void)
{
	complex_float* signal_example;
	complex_float* fft_output;
	float* fft_freqs;
	float* fft_abs;

	float freq_A, freq_B;
	float signal_freq;
	float total_time	   = 1.0f;
	float sample_frequency = 8.0e3f;
	float sample_period	   = 1.0f / sample_frequency;
	int signal_size = (int)ceilf(sample_frequency * total_time);

	signal_example	= vector_create_cpx(signal_size);
	fft_output		= vector_create_cpx(FFT_SIZE);
	fft_freqs		= vector_create(FFT_SIZE);

	get_fft_freqs(fft_freqs, FFT_SIZE, sample_period);

	freq_A		= 1000.0f;
	freq_B		= 2000.0f;
	signal_freq = (float)gcd((int)freq_A, freq_B);
	for (int n = 0; n < signal_size; n++)
	{
		signal_example[n].real_part =
			sinf(TWO_PI * freq_A * n * sample_period) +
			0.5f * sinf(TWO_PI * freq_B * n * sample_period +
						((3.0f * PI) / 4.0f));
	}

#ifdef DEBUG_MODE
	printf("Signal Example (Complex Form):\n");
	print_vector_cpx(signal_example, signal_size);
#endif

	printf("Performing FFT...\n");
	fft_dec_time(signal_example, fft_output, FFT_SIZE, false);
	fft_abs = abs_fft_calc(fft_output, FFT_SIZE);

#ifdef DEBUG_MODE
	printf("FFT Output (Complex Form):\n");
	print_vector_cpx(fft_output, FFT_SIZE);
	printf("FFT Freqs:\n");
	print_vector(fft_freqs, FFT_SIZE);
	printf("FFT Output (Magnitude):\n");
	print_vector(fft_abs, FFT_SIZE);
#endif

	printf("Outputting the data files...\n");
	output_data_cpx("input_signal.txt", signal_example, signal_size);
	output_data("input_signal_params.txt",
				(float[]){signal_freq, sample_frequency},
				2);
	output_data("fft_freqs.txt", fft_freqs, FFT_SIZE);
	output_data_cpx("fft_out.txt", fft_output, FFT_SIZE);
	output_data("fft_abs.txt", fft_abs, FFT_SIZE);

	vector_delete_cpx(signal_example);
	vector_delete_cpx(fft_output);

	vector_delete(fft_freqs);
	vector_delete(fft_abs);

	return 0;
}
