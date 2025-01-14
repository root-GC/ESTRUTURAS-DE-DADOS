//  EM C++, A ALOCACAO E LIBERTACAO DA MEMORIA EH FEITA POR MEIO DE new E delete

// SINTAXE new
     Pointer_Variable = new data_type;

     // e.g.
     int * var1=new int;

// SINTAXE delete
     delete Pointer_Variable;

     //e.g.
     delete var1;


// Alocação para Vetores:
int *var=new int[50];

//Limpando a memoria alocada
delete[] var;

//Acessando elementos do vector
var[4]=3;



//Alocacao para matrizese
int **matrix=new int*[4]; // Aloca um array de 5 ponteiros

for(int i=0; i<4; i++){
     matrix[i]=new int[5]; // Aloca memória para cada linha
}

//Liberação da memória:
for(int i = 0; i < 5; i++) {
    delete[] matrix[i];  // Libera cada linha
}

delete[] matrix;  // Libera o array de ponteiros
