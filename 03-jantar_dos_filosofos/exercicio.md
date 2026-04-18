Implemente o problema do Jantar dos Filósofos utilizando uma thread para cada filósofo.

Em uma variável global, guarde um vetor do tipo char com cinco posições. Cada posição representa o estado de um filósofo. 
Os valores possíveis para cada posição são 'P', 'F', 'C', que correspondem, respectivamente, a pensando, faminto e comendo.

Inicialmente as threads iniciam no estado pensando. Portanto, o valor inicial do vetor deve ser PPPPP.

As threads dormem um tempo aleatório (veja a função rand() de cstdlib) antes de passar para o próximo estado. 
Toda vez que uma thread muda de estado, ela deve mudar seu estado no vetor de estados (cuidado com condição de corrida aqui!) 
e imprimir no console o vetor de estados. 

Seu programa deve imprimir algo como:

PPPPP

PFPPF

PCPPC

Lembre-se que dois filósofos vizinhos NÃO podem comer ao mesmo tempo. Por exemplo, os seguintes estados são inválidos:

CPPPC

PCCPP

Lembre-se de usar um mutex para proteger o vetor de estados.

Dicas: utilize um vetor de 5 posix semaphores inicializado com o 3o argumento value=0. Veja um exemplo de uso em https://www.geeksforgeeks.org/use-posix-semaphores-c/