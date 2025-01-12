//Explicação e Comparação: malloc() vs calloc()

malloc() //Memory Allocation

//Forma Geral: 
prt = (int *)malloc(n * sizeof(block_size));

/* #CARACTERÍSTICAS

	#Aloca um único bloco de memória contínuo de tamanho m*sizeof(block_size);

	#INICIALIZAÇÃO: A memória alocada contém valores indeterminados(garbage);


	@EXEMPLO: 
	int *ptr = (int *) malloc(5 * sizeof(int)); 

		-- Aloca espaço suficiente para armazenar 5 inteiros, mas
		os valores iniciais no bloco de memória não são garantidos
		(podem conter "lixo").

*/


calloc() //Contiguous Allocation

//Forma Geral
prt = (int_type *)calloc(n, sizeof(block_size));

/*  #CARACTERÍSTICAS

	# Aloca multiplos blocos de memória contínuos - n blocos de tamanho sizeof(block_size) cada.

	#INICIALIZAÇÃO: Todos os blocos são inicializados com zero.

	@EXEMPLO: 
	int *ptr = (int *)calloc(5,sizeof(int));

		-- Aloca espaco para 5 inteiros e os inicializa com 0;
*/

/*	#DIFERENCA(RESUMO)

	#malloc(): Um grande bloco contínuo com valores de lixo.
	#calloc(): Blocos contínuos e logicamente "separados", cada posição zerada.
	
	#Tratamento Independente:
	Sim, você pode usar cada posição como variável independente com ambas funções. O comportamento de inicialização é a principal diferença prática.

*/


/* QUANDO UTILIZAR CADA?

	#Quando usar malloc()?
	Quando a inicialização dos valores não importa, ou você pretende definir cada valor explicitamente.
	
	#Quando usar calloc()?
	Quando você precisa garantir que os valores começam com zero, ou quando deseja economizar um passo na inicialização dos elementos.
*/