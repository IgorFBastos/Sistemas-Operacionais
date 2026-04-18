

#include <iostream> // Biblioteca para entrada e saída
#include <pthread.h> // Biblioteca para threads

using namespace std; // Define o namespace padrão


pthread_t thread_1, thread_2;
int valor;
int primo = 1;

void* check_metade_primo(void* arg) {

    pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, NULL);

    long id_thread = (long)arg;

    int ini;
    int fim;

    if(id_thread == 1) {
        ini = 2;
        fim = valor / 2;
    } else {
        ini = (valor / 2) + 1;
        fim = valor  - 1;
    }

    for (int i = ini; i <= fim; i++) {
        if (valor % i == 0) {
            primo = 0;

            if(id_thread == 1) {
                cout << "Matando thread 2" << endl;
                pthread_cancel(thread_2);
            } else {
                cout << "Matando thread 1" << endl;
                pthread_cancel(thread_1);
            }
            
            break;
        }
    }
    return NULL;
}





int main() {

    cout << "Criando thread para index: "  << endl;
    cin >> valor;

    if (valor <= 1) {
        cout << 0 << endl; 
        return 0;
    }

    pthread_create(&thread_1, NULL, check_metade_primo, (void*)1);

    pthread_create(&thread_2, NULL, check_metade_primo, (void*)2);

    pthread_join(thread_1, NULL);

    pthread_join(thread_2, NULL);


    cout << primo << endl;

    return 0;
}


