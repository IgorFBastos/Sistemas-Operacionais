#include <iostream> // Biblioteca para entrada e saída
#include <pthread.h> // Biblioteca para threads

using namespace std; // Define o namespace padrão


int contador = 0;
int const num_incremento = 1000;
// crio o mutex  com a lib
pthread_mutex_t mutex_contador = PTHREAD_MUTEX_INITIALIZER;


void* incrementar_contador(void *arg) {
    
    for(int i = 0; i < num_incremento; i++) {
        // bloqueio o mutex
        pthread_mutex_lock(&mutex_contador);
        // atualizo a variavel protegida, garantido um acesso por vez
        contador++;
        // desbloqueio o mutex
        pthread_mutex_unlock(&mutex_contador);
    };
    return NULL;
}

int main() {

    const int num_threads = 128; // Define o número de threads
    pthread_t thread_list_id [num_threads]; // Cria um array para armazenar as threads ids

    // preciso percorrer essa estrutura para poder criar as 128 threads
    for (int i = 0; i < num_threads; i++) {
        cout << "Criando thread para index: " << i << endl;
        pthread_create(&thread_list_id[i], NULL, incrementar_contador, NULL);
    }

    // preciso mandar a thread principal esperar as demais para finaliza o programa
    for (int i = 0; i < num_threads; i++) {
        pthread_join(thread_list_id[i], NULL);
    }

    cout << "Contador após as " << num_threads << " threads : " << contador << endl; 

    return 0; // Finaliza o programa
}
