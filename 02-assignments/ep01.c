/**********************************************************************/
/* MAC0115 IF 2016    -   Profa. Renata                               */
/*                                                                    */
/* Primeiro Exercicio Programa                                        */
            /*                                                           */
/* Edio Cerati Neto             NUSP: 9762678                         */
/*                                                                    */
/**********************************************************************/


#include <stdio.h>     /* Adiciona funcoes de entrada e saida */
#define true 1        /* Define a condicao de "verdadeiro" para uma variavel */
#define false 0      /* Define a condicao de "falso" para uma variavel */

int main (){

int pokeball,      /* Conta a quantidade de pokebolas restantes ao treinador */
velocidade_x,     /* Velocidade horizontal de lancamento da pokebola */
velocidade_y,    /* Velocidade vertical de lancamento da pokebola */
pokeball_x,     /* Coordenada horizontal da localizacao da pokebola */
pokeball_y,    /*Coordenada vertical da localizacao da pokebola */
pokemon_x,    /* Coordenada horizontal da localizacao do Pokemon */
pokemon_y,   /* Coordenada vertical da localizacao do Pokemon */
captured,   /* Define se o Pokemon foi capturado ou nao */
delta_t,   /* Indica o passo de tempo para cada iteracao */
g,        /* Aceleracao gravitacional local */    
t;       /* Instante de tempo */



velocidade_x=1;           /* Velocidade horizontal de lancamento da pokebola, suposta constante */
captured=false;          /* Condicao inicial do pokemon */
pokeball=3;             /* Quantidade inicial de pokebolas */
delta_t=1;             /* Intervalo de tempo utilizado na simulacao */

/* Imprime os agradecimentos e apresentacoes iniciais */
printf("Apoio: FAPPESP - 01/09/16 \n");
printf("Pokemon Algorithmical Capturator \n");
printf("PALC-9000 \n");
printf("\n");
printf("Programa que simula o arremesso de pokebolas na captura de um Pokemon");
printf("\nPokebolas restantes: %d", pokeball);

/* Definicao da aceleracao gravitacional e localizacao do Pokemon */
printf("\n\nInsira a aceleracao gravitacional g local (g inteiro positivo): ");
scanf("%d", &g); /* Le o valor da aceleracao gravitaciona definido pelo usuario */

printf("\n\nInsira as coordenadas inteiras nao-negativas (x,y) do Pokemon: ");
printf("\n(Separadas por espaco). Exemplo: x y \n");
scanf("%d", &pokemon_x); /* Le a coordenada horizontal da posicao do Pokemon a ser capturado */
scanf("%d", &pokemon_y); /* Le a coordenada vertical da posicao do Pokemon a ser capturado */
		
/* Atualiza a situacao de cada tentativa de captura*/	
while (pokeball>0 && captured==false){ /* Define a condicao de funcionamento para: possuir pokebolas e o Pokemon ainda nao tiver sido capturado */
	
	t=0; /* Define o instante inicial como zero */
	
	printf("\n\nInsira as coodernadas inteiras nao-negativas (x,y) do treinador (posicao do arremesso)");
	printf("\n(Separadas por espaco). Exemplo: x y \n");
	scanf("%d", &pokeball_x); /* Le a coordenada horizontal (do treinador) de onde sera lancada a pokebola */
	scanf("%d", &pokeball_y); /* Le a coodernada vertical (do treinador) de onde sera lancada a pokebola */
	printf("\nInsira a velocidade vertical de lancamento da pokebola: ");
	scanf("%d", &velocidade_y); /* Le a velocidade vertical com que a pokebola e lancada*/
	
	/* Imprime as condicoes iniciais definidas */
	printf("\nt=%06d",t);
	printf(" vy=%06d",velocidade_y);
	printf(" x=%06d",pokeball_x);
	printf(" y=%06d \n",pokeball_y);
	
	/* Atualizacao iterativa do arremesso */
	if(pokeball_y==0){ /* Caso especifico onde a pokebola parte da altura zero (chao) */
	
		t=t+delta_t; /* Atualiza o instante de tempo */
		pokeball_x=pokeball_x+(velocidade_x*delta_t); /* Atualiza a posicao x da pokebola */
		pokeball_y=pokeball_y+(velocidade_y*delta_t)-(g*delta_t*delta_t/2); /* Atualiza a posicao y da pokebola */
		velocidade_y=velocidade_y-g*delta_t; /* Atualiza a velocidade vertical da pokebola */
		
		/* Imprime as condicoes do problema a cada intervalo de tempo */
		printf("t=%06d",t);
		printf(" vy=%06d",velocidade_y);
		printf(" x=%06d",pokeball_x);
		printf(" y=%06d \n",pokeball_y);
	}	
	while(pokeball_y>0 && pokeball_x<pokemon_x){ 
		/* Condicoes para atualizacao: pokebola nao ter atingido o chao e nao ter ultrapassado a coordenada x do Pokemon*/
		
		t=t+delta_t; /* Atualiza o instante de tempo */
		pokeball_x=pokeball_x+(velocidade_x*delta_t); /* Atualiza a posicao x da pokebola */
		pokeball_y=pokeball_y+(velocidade_y*delta_t)-(g*delta_t*delta_t/2); /* Atualiza a posicao y da pokebola */
		velocidade_y=velocidade_y-g*delta_t; /* Atualiza a velocidade vertical da pokebola */
		
		/* Imprime as condicoes do problema a cada intervalo de tempo */
		printf("t=%06d",t);
		printf(" vy=%06d",velocidade_y);
		printf(" x=%06d",pokeball_x);
		printf(" y=%06d \n",pokeball_y);
	}
	pokeball--; /* Diminui a quantidade de pokebolas restantes */ 
	printf("\nPokebolas restantes: %d", pokeball);
	if(pokeball_x==pokemon_x && pokeball_y==pokemon_y){ /* Apenas se a pokebola ocupa a mesma posicao do Pokemon, capturando-o */
		printf("\nParabens! O Pokemon foi capturado com sucesso!");
		captured = true;} /* Define o estado do Pokemon como capturado */
    	else
		printf("\nInfelizmente o Pokemon ainda nao foi capturado");
	if(pokeball==0 && captured==false) /* Imprime que o treinador ficou sem pokebolas para a simulacao */
		printf("\nSem pokebolas. A simulacao acabou");
}

	return 0;
}