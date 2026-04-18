Escreva um programa em C onde a thread principal cria outras 128 threads. 
Deve existir um contador global iniciado em 0. 
Cada uma das 128 threads deve incrementar o contador 1000 vezes. 
A thread principal deve aguardar as demais threads terminarem e então imprimir o valor final do contador.
Claramente, existe uma condição de corrida. Elimine-a utilizando um mutex.
Você deve utilizar a biblioteca pthreads.