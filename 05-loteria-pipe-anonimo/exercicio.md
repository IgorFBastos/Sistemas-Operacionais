Escreva um programa C/C++ usando pipe anônimo para simular um sorteio da seguinte forma. 
Um processo pai cria 10 processos filhos e guarda os respectivos pids em um array.  
Em seguida, o pai sorteia um pid e imprime no pipe  "PID sorteado: <pid>", onde <pid> é o pid sorteado. 
Os filhos leem o pipe, e um filho imprimirá "<pid>: fui sorteado" se o pid lido é equivalente seu pid. 
Em seguida todos os processos encerram o pipe. 

Instruções:

a) use o comando fork para criar processos filhos. Ou seja, não use threads.

b) o pai deverá escrever 10 vezes o pid sorteado no pipe, para que todos os filhos possam ler o pipe uma vez.