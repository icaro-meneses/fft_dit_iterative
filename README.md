# FFT(Fast Fourier Transform) por decimação no tempo

É uma atividade que consiste na implementação da Transformada Rápida de 
Fourier(FFT) por decimação no Tempo (algoritmo de Cooley-Tukey(1965)),
implementada com o algoritmo iterativo.

## Dependências

Na sua distribuição linux, certifique-se de já ter instalado os pacotes:

- gcc
- make
- octave
- pdflatex

## Instruções de Build e Execução

1. Clone o repositório na sua máquina

```
$ git clone https://github.com/icaro-meneses/fft_dit_iterative
$ cd fft_dit_iterative
```

2. Para realizar a compilação do programa

```
$ make release
```

3. Para executar somente o programa:

```
$ ./fft_time_dec.x
```

ou

```
$ make run
```

4. Para executar o programa e exportar o arquivo em .pdf:

```
$ make run graph
```

5. Caso precise fazer a limpeza dos arquivos, execute: `make clean`

6. **Extra:** Para realizar a compilação no modo de DEBUG:

```
$ make debug
```

## Exemplo de resultado

com um sinal x(t) descrito por:

$$x(t) = \sin(2 \pi 1000 t) + 0.5 \cdot \sin(2 \pi 2000 t + \frac{3 \pi}{4})$$

o resultado da operação de FFT de tamanho $N = 8192$ é

![Resultado da FFT do sinal x(t)](./results/result_plot.png "FFT Result")

**Nota:** O código ainda requer testes.

