/* leia  o ano de nascimento da pessoa, divida em dois, some ambas as partes por 5 e pegue o resto 
	dependendo do resto, mostre uma resposta */
	
int main() {
	// declare as variaveis 
	int ano, v1, v2, resultado;
	
	// leia o ano
	printf("Insira seu ano de nascimento: ");
    scanf("%i", &ano);
	v1 = ano/100;
	v2 = ano - v1*100;

	// Formar o resulado
	resultado = (v1+v2)%5;
	if (resultado == 0) 
		printf("\nVoce e timido");
	if (resultado == 1) 
		printf("\nnVoce e sonhador");
	if (resultado == 2) 
		printf("\nnVoce e paquerador");
	if (resultado == 3) 
		printf("\nnVoce e atraente");
	if (resultado == 4) 
		printf("\nnVoce e irresistivel");
}

