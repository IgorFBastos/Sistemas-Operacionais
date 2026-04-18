#include <iostream>
#include <unistd.h>     // Para usar o fork() e o sleep()
#include <sys/mman.h>   // Para a memória compartilhada (mmap)
#include <semaphore.h>  // Para o semáforo de processos
#include <fcntl.h>      // Para regras de criação de arquivos no SO
#include <sys/wait.h>   // Para o pai poder esperar os filhos (wait)

using namespace std;


int main () {

    int nprocs;

    cout << "Digite a quantidade de processos" << endl;
    cin >> nprocs;

    // função mmap de <sys/mman.h> usada para criar um espaço compartilhado de momoria entre os processos
    int *id_compartilhado = (int*) mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);

    *id_compartilhado = 0;

    // excluimos qualquer semaforo antigo na memoria
    sem_unlink("/semaforo_exclusao");

    // criamos o semaforo para processos
    sem_t *semaforo = sem_open("/semaforo_exclusao", O_CREAT, 0666, 1);

    pid_t process_id;

    for(int i = 0; i < nprocs; i++) {
        process_id = fork();
        if (process_id == 0) {
            break;
        }
    }

    if(process_id == 0) {
        // Processos filhos
        srand(getpid());
        sleep(rand() % 10 + 1);

        sem_wait(semaforo);

        *id_compartilhado = *id_compartilhado + 1;

        cout << "Processo " << *id_compartilhado << " criado" << endl;

        sem_post(semaforo);

    } else {
        // Processo pai
        for(int i = 0; i < nprocs; i++) {
            wait(NULL);
        }

        sem_unlink("/semaforo_exclusao");
        sem_close(semaforo);
        munmap(id_compartilhado, sizeof(int));
    }

    return 0;
}

