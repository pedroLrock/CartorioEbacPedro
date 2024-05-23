#include <stdio.h>   //Biblioteca de comunicaÃ§Ã£o com o usuÃ¡rio
#include <stdlib.h> //Biblioteca de aalocações de  espaço de memoria
#include <locale.h> //Biblioteca de alocações de texto por regiÃ£o
#include <string.h> //blioteca responsável por cuidas das string

int registrar()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[90];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das string
	
	FILE *file;///cria o arquivo 
	file= fopen(arquivo, "w"); //cria o arquivo
	fprintf(file,cpf);//salva o valor da variavel
	fclose(file);//fecha o arquivo
	
	file= fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file); 
	
	printf("Digite o Nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo,"a");
	fprintf(file,nome);
	fclose(file);
	
	file= fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file); 
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file= fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file); 
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
}

int consultar()
{
	setlocale (LC_ALL, "Portuguese_Brazil.1252"); //definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");
	}
	
	while(fgets(conteudo, 200,	file) != NULL)
	{
		printf("\n Essas s�o as informa��es do usu�rio:	");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	

}

int deletar()
{
	char cpf [40];	
	
	printf("Digite o cpf a ser deletado: \n");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file ==NULL);
	{
		printf("O usu�rio n�o se encontra no sistema!.\n");
		system("pause");
	}
	
}

int main()
{
	int opcao=0; //definindo variaveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		setlocale (LC_ALL, "Portuguese_Brazil.1252"); //definindo a linguagem
		
	//inicio do menu
		printf("\t------  Cart�rio da EBAC ------ \n\n");	
		
		system("cls"); //responsavel por apagar tudo apos a opção ser escolhida
		
	//menu
		printf("Escolha a op��o desejada do menu: \n \n\n");	
	
	//opções do menu
		printf("\t1 Registrar nome  \n\n");
		printf("\t2 Consultar os nome \n\n");
		printf("\t3 Deletar Nomes \n "); 
		printf("Opcao:");//fim do menu
	
		scanf("%d", &opcao); //codigo para armaze na opcao, a variavel que o usuario digitar.
	
		system("cls"); //responsavel por apagar tudo apos a opção ser escolhida
	
		//codigo responsavel pela escolha das opções
		
		switch(opcao)
		{
		case 1:
	 	registrar();
		break;
	
		case 2:
		consultar();
		break;	
	 
	 	case 3:
	 	deletar();
	 	break;	
		
		default:
		printf("Essa op��o n�o esta dispon�vel!\n");
		system("pause");
		break;
		
		}
	}

}                                        
