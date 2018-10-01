//*******************************************
//  Juan José García
//  Programa para lanzar N hilos y calcular 
//  el factorial de N haciendo uso de los 
//  hilos
// 
//*******************************************
#include <stdio.h>
#include <pthread.h>
#define N 6 //***** Número de hilos

void* saludohijo(void *threadid)
{
	long task_id;
	task_id = (long)threadid;
	//int id = (int)ptr;
	printf("Hola Padre soy el hilo %ld \n",task_id);
	printf("ya estoy funcionando\n");
	printf("Nos vemos luego\n");
	task_id = task_id + 1;
	pthread_exit((void *)task_id); //El hilo hijo  avisa que ya terminó

}

int main ()
{
	int result1; 
	long taskid[N],salida[N],fact = 1;
	pthread_t hilos[N];

	printf("Buenos días soy hilo principal\n");

	for(int i=0; i<N; i++)
	{
		taskid[i] = i;
		result1 = pthread_create(&hilos[i],NULL,saludohijo,(void *)taskid[i]);
	}

	printf("Hola hijo\n");
	for(int i=0; i<N; i++)
	{
		pthread_join(hilos[i],(void *)&salida[i]); //El hilo padre espera la tarea del hijo
		printf("Terminó hilo %ld\n",salida[i]);
		fact = fact*salida[i];

	}

	printf("Factorial de %d es %ld\n",N,fact);


	return 0;
}
