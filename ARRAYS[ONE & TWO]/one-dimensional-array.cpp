#include <iostream>
#include <conio.h>


/*	#
	# one-dimensional-array, para escrever e ler apenas um for loop eh suficiente
	#
*/
using namespace std;

int main()
{
 	//Declarando o array
	int game[5]={};
	//Inicializando o array
	for(int i=0; i<5; i++){
		game[i]=++i;
		i--;
	}
	//Lendo os dados do array
	for(int i=0; i<5; i++){
		std::cout<<game[i]<<endl;
	}
	//Alterando algum dado localizado
	for(int i=0; i<5; i++){
		if(game[i]==2) 
  			game[i]=200;
	}
	//Lendo os dados do array
	for(int i=0; i<5; i++){
		std::cout<<game[i]<<endl;
	}
	
	return 0;
}
