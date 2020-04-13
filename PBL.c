#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

#define READ 0
#define WRITE 1
#define TRUE 1
#define GNUPLOT "gnuplot -persist"

int produtor(int fd[2]);

int main(){

	int fd[2];

	/* criando pipe */
	pipe(fd);

	/* criando novo processo */
	int pid = fork();

	if (pid == -1)
	{
		perror("Erro ao criar um novo processo!");
	}
	else if (pid == 0)
	{
		/* o novo processo funciona como produtor */
		produtor(fd);
	}
	else
	{
		/* o processo pai funciona como consumidor */
		int counter, bytesLidos;
		while (1)
		{
			bytesLidos = read(fd[READ], &counter, sizeof(int));
			if (bytesLidos == -1)
			{
				perror("Erro na leitura");
			}
			printf("contador: %d  \n", counter);

			if (counter == 3)
			{
				FILE *gp;
				gp = popen(GNUPLOT, "w");
				if (gp == NULL)
				{
					printf("Erro na abertura do GNUPLOT");
					exit(0);
				}
				fprintf(gp, "load 'scriptPlotagem.gnu'\n");
				fclose(gp);
				break;
			}
			sleep(1);
		}
		close(fd[READ]);
	}
	return 0;
}

int produtor(int fd[2])
{
        close(fd[READ]);
	double x0 = 0;	  // valor inicial
	double step = 1;
        
	printf("# x \t f(x) \n");
	int contador = 0;
	int bytesEscritos;
	while (1)
	{
		int value = x0 - 3;
		FILE *arq = fopen("dados.txt", "a");
		fprintf(arq, "%.3f \t %.3f \n", x0, 3*sin(value));
		printf("%.3f \t %.3f \n", x0, 3*sin(value));
		contador++;
		bytesEscritos = write(fd[WRITE], &contador, sizeof(int));
		if (bytesEscritos == -1)
		{
			perror("ERRO NA ESCRITA");
		}
		fclose(arq);
		x0 += step;
		sleep(1);
	}
	close(fd[WRITE]);
	return 0;
}
