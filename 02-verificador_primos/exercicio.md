Escreva um programa que leia um número n>1 do teclado (veja a função scanf) e escreva 1 se o n for primo e 0 caso contrário.
Para a verificação, utilize duas threads onde cada thread verifica metade dos possíveis fatores de n.
A thread que encontrar um divisor (neste caso, o número não é primo) deve cancelar a outra thread e terminar Para cancelar a outra thread, utilize a função pthread_cancel e pthread_canceltype.

O código C para leitura do teclado e escrita do resultado na tela já está disponível e você não deve modificá-lo. 
Lembre de avaliar seu código clicando no botão "avaliar" (botão com checkbox seguido de um zero).