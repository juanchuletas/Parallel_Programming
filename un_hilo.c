#include <stdio.h>
#include <pthread.h>

void saludohijo(void *ptr)
{
	printf("Hola soy el hijo\n");
	printf("ya estoy funcionando\n");
	printf("Nos vemos luego\n");

}

int main ()
{
	int result; 
	pthread_t hilo_1;

	//printf("Buenos días soy hilo principal\n");

	result = pthread_create(&hilo_1,NULL, (void *)&saludohijo,(void *)NULL);

	printf("Hola hijo\n");


	return 0;
}
