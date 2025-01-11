#include <stdio.h>
#include <conio.h>

/*	#
	# one-dimensional-array, para escrever e ler apenas um for loop eh suficiente
	#
*/

int main(){
	
	//Declarando o array
	int game[5]={};
	int j=0;
	int i=0;
	//Inicializando o array
	for(j=0; j<5; j++){
		game[j]=++j;
		j--;
	}
	//Lendo os dados do array
	for(i=0; i<5; i++){
		printf("%i\n",&game[i]);//Mostra o endereco
	}
	//Alterando algum dado localizado
	for(i=0; i<5; i++){
		if(game[i]==2) 
  			game[i]=200;
	}
	//Lendo os dados do array
	for(i=0; i<5; i++){
		printf("%i\n",game[i]);
	}
	
	return 0;
}
