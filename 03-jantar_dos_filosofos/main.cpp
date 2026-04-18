#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h> 

using namespace std;


char status[5] = {'P', 'P', 'P', 'P', 'P'};
pthread_mutex_t mutex_status = PTHREAD_MUTEX_INITIALIZER;
sem_t semaforosIds[5];
pthread_t threadsIds[5];


bool disponivel_para_comer (int id) {

    int direita = (id + 4) % 5;
    int esquerda = (id + 1) % 5;

    bool faminto = status[id] == 'F';
    bool vizinhosPensando = status[esquerda] != 'C' && status[direita] != 'C';

    return faminto && vizinhosPensando;
}

void tentar_comer (int id) {

    bool disponivel = disponivel_para_comer(id);

    if(disponivel) {

        status[id] = 'C';
        printf("%.5s\n", status);
        
        sem_post(&semaforosIds[id]);
    }   

}


void pegar_garfos (int id) {

    pthread_mutex_lock(&mutex_status);

    status[id] = 'F';
    printf("%.5s\n", status); 
        
    tentar_comer(id);

    pthread_mutex_unlock(&mutex_status);
    
    sem_wait(&semaforosIds[id]);
}

void devolver_garfos (int id) {

    pthread_mutex_lock(&mutex_status);

    status[id] = 'P';
    printf("%.5s\n", status); 

    int direita = (id + 4) % 5;
    int esquerda = (id + 1) % 5;

    tentar_comer(direita);
    tentar_comer(esquerda);

    pthread_mutex_unlock(&mutex_status);
}


void* rotina_filosofo(void* arg) {

    long id_thread = (long)arg;

    while(true) {

        pegar_garfos(id_thread);

        sleep(rand() % 3 + 1);

        devolver_garfos(id_thread);

        sleep(rand() % 3 + 1);
    
    }

    return NULL;
}





int main () {

    for (int i = 0; i <= 4; i++ ) {
        sem_init(&semaforosIds[i], 0, 0);
    };

    for (int i = 0; i <= 4; i++ ) {
        pthread_create(&threadsIds[i], NULL, rotina_filosofo, (void*)(long)i);
    };

    for (int i = 0; i <= 4; i++ ) {
        pthread_join(threadsIds[i], NULL);
    }

    return 0;
}