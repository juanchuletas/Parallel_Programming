#include <stdio.h>
#include <pthread.h>

void saludohijo(void *ptr)
{
	int id = (int)ptr;
	printf("Hola Padre soy el hilo %d \n",id);
	printf("ya estoy funcionando\n");
	printf("Nos vemos luego\n");

	pthread_exit((void *)NULL); //El hilo hijo dice avisa que ya terminó

}

int main ()
{
	int result1,result2,result3; 
	pthread_t hilo_1,hilo_2,hilo_3;

	printf("Buenos días soy hilo principal\n");

	result1 = pthread_create(&hilo_1,NULL, (void *)&saludohijo,(void *)0);
	result2 = pthread_create(&hilo_2,NULL, (void *)&saludohijo,(void *)1);
	result3 = pthread_create(&hilo_3,NULL, (void *)&saludohijo,(void *)2);

	printf("Hola hijo\n");

	pthread_join(hilo_1,(void *)NULL); //El hilo padre espera la tarea del hijo
	pthread_join(hilo_2,(void *)NULL); //El hilo padre espera la tarea del hijo
	pthread_join(hilo_3,(void *)NULL); //El hilo padre espera la tarea del hijo


	return 0;
}
