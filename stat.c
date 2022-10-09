// Discente: Caroline dos Santos Corrêa
// EP1 - Estatística Básica

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void leNumero( float *f ) {
	char entrada[10];
	float lido;
	char *endptr;

	printf("> ");
	while(1) {
		fgets( entrada, 9, stdin);
		lido = strtof( entrada, &endptr );
		
		if( *endptr =='\n' || *endptr =='\0' ) {
			*f = lido;
			return;
			}
		printf("Número ponto flutuante inválido. Entre novamente: \n> ");
		}
}

int main() {
	unsigned int n;
	char qtdnum[100];
	
	float *vet;  //
	float x, soma, media, dp, desvio, aux, mediana;

	printf("\nEntre com número de valores: ");
	fgets(qtdnum, 100, stdin);
	n = atoi(qtdnum);

    vet = malloc( n * sizeof(float) ); //
    if( ! vet ) {    // vet==NULL
        printf("\nErro de alocação de memória.\n");
        exit(-1);
    }

	for( int i=0; i<n; i++)
		leNumero( vet+i );
		
	for( int i=0; i<n; i++)
		soma += vet[i];
    
    //Calculo da Média
    media = soma/n;
    printf("Média: %f\n", media);
    
    //Desvio Padrão   
	 for(int i=0; i<n; i++)
        dp += (vet[i]-media)*(vet[i]-media);
    desvio = sqrtf(dp/n);
    printf("Desvio: %.2f\n",desvio);
    
    //Mediana
     for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
        	
            if(vet[i] > vet[j]){
            	
                aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;
            }
        }
    }

    if(n%2){
         mediana = vet[n/2];
    } else {
         mediana = (vet[n/2-1]+vet[n/2])/2;
    }
    printf("Mediana: %f\n", mediana);
    // Maior e Menor número
    printf("Menor valor: %f\n", vet[0]);
    printf("Maior valor: %f\n", vet[n-1]);

    free(vet);
}