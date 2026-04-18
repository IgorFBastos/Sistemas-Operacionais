#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <cstdlib>
#include <time.h>
#include <cstring>

using namespace std;


int main () {

    int fp[2];

    pipe(fp);

    pid_t p_filhos_id[10];

    pid_t id_process;
    pid_t sorteado;

    for(int i = 0; i < 10; i++) {
        id_process = fork();
        if(id_process == 0) {
            break;
        } else {
            p_filhos_id[i] = id_process;
        }
    }

    if(id_process == 0) {
        // filhos
        read(fp[0], &sorteado, sizeof(sorteado));

        int process_filho_id = getpid();

        if(process_filho_id == sorteado) {
            cout << "<" << process_filho_id << ">: Fui sorteado" << endl;
        }

    } else {
        // pai

        srand(time(0));
        int random = rand() % 10;

        sorteado = p_filhos_id[random];

        cout << "Processo id sorteado: " << sorteado << endl;

        for(int i = 0; i < 10; i++) {
            write(fp[1], &sorteado, sizeof(sorteado));
        }

        close(fp[0]);
        close(fp[1]);

        for(int i = 0; i < 10; i++) {
            wait(NULL);
        }

    }

    return 0;
}