#include <iostream>
#include <conio.h>

/*	#
	# two-dimensional-array, para escrever e ler sao necessarios dois for loops
	# No deletion or insertion operations are performed on arrays.
	# Another main disadvantage is its fixed length;
*/

using namespace std;

int main()
{
	//Declaracao do array bidimencional
	int game[3][3]={};
	
	//Inicializando a matrix
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			game[i][j]=i;
		}
	}
	//Visualizando a matriz
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			std::cout<<game[i][j];
		}
		cout<<endl;
	}
	
	return 0;
}