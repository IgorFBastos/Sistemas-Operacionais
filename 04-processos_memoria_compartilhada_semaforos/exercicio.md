Escreva um programa em C/C++ que lê do teclado (stdin) a quantidade de processos a serem criados 
(dica: use std::cin >> nprocs, onde nprocs > 0 é uma variável inteira). 
O processo principal (processo pai) cria procs processos filhos com uso da chamada de sistema fork(). 
Cada processo filho deverá ficar bloqueado durante um tempo aleatório entre 1s e 10s e deverá imprimir "Processo XX criado", 
onde XX é um identificador único de 1 até nprocs. Em outras palavras, XX deverá ser 1 para o primeiro filho que acordar,
2 para o segundo filho, 3 para o terceiro filho, etc...

Para realizar essa tarefa, você precisará:
    (i) criar uma região de memória compartilhada entre os processos (uma variável inteira denominada aqui de "id" e inicializada com valor 0); 
    (ii) inicializar um semáforo compartilhado entre todos os processos que será utilizado como um mecanismo de exclusão mútua; 
    (iii) fazer com que cada processo filho, entre em uma região crítica, incremente id, imprima "Processo <id> criado", 
          onde <id> é o valor da variável id, e saia da região crítica.

Dica: para a criação de uma região de memória compartilhada entre processos, pesquise sobre a chamada de sistema mmap() ou shmget(). 
Para a criação de um semáforo compartilhado entre processos, pesquise sobre as funções sem_open() e sem_unlink() disponivel em <semaphore.h>

Aviso: não use as chamadas semget e semop disponível em <sys/sem.h>.