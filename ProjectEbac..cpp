#include <stdio.h> //biblioteca de comunica��o com o usuario
#include <stdlib.h>  //biblioteca de aloca��o de espa�o em memoria 
#include <locale.h> //biblioteca de aloca��o de texto por regi�o 
#include <string.h> //biblioteca de respons�vel a cuidar das strings


int registro() //chama a fun��o

{
    char arquivo [40]; //conjunto de caracteres
	char cpf[40];
	char nome[40];
    char sobrenome[40];
    char cargo[40];
    
    printf("digite o CPF a ser cadastrado: ");
    scanf("%s",cpf);  //Se o arquvio n�o for encontrado(n�o existir)
    
    strcpy(arquivo,cpf); //copia os dados da string
    
    FILE *file; //cria o arquivo 
    file = fopen(arquivo,"w"); //cria o arquivo
	fprintf(file, "CPF: ");
	fprintf(file,cpf); //salva o valor da vari�vel
	fclose(file); //fecha arquivo 
	
	file = fopen(arquivo, "a");
	fprintf(file,","); //d� espa�o
	fclose(file);
	
    printf("digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	 
	file =fopen(arquivo, "a");
	fprintf(file,"\nNome: ");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	 
	file = fopen(arquivo, "a");
    fprintf(file,"\nSobrenome: ");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo , "a");
	fprintf(file,",");
	fclose(file);
	
	printf("digite o cargo a ser cadastrado: ");
	 scanf("%s",cargo);
	 
	file = fopen(arquivo, "a");
    fprintf(file,"\nCargo: ");
	fprintf(file,cargo);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	 	 
}

int consulta() //chmama a fun��o
 
{
	setlocale(LC_ALL,  "PORTUGUESE"); //define acentua��o e alfabeto do que aparecer� ao user

	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);  // ler conteudo inserido pelo user
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
{
	printf("CPF digitado n�o consta na base de dados!\n");	
}
    printf("\nEssas s�o as informa��es do usu�rio!\n");	
	while(fgets(conteudo, 200, file) != NULL)

{
	printf("\n%s",conteudo);  // ler conteudo inserido pelo user
	printf("\n\n"); 
}
	
	system("pause");
}

int deletar() //fun��o delete
{     
    char cpf[40];
    
    printf("Digite o CPF do usu�rio a ser deletado: ");
    scanf("%s", cpf);
    
    remove(cpf);
 
    FILE *file;
    file = fopen(cpf, "r");
    
    if(file == NULL) //Se o arquvio n�o for encontrado(n�o existir)
{
    printf("O usu�rio n�o se encontra no sistema!.\n");
	system("pause"); 
}

}

int main() //fun��o principal
{
	int opcao=0; 
	int laco=1;
	
	for(laco=1;laco=1;) 
{
	
    system("cls");	
	    
	     
	
	
	setlocale(LC_ALL,  "PORTUGUESE");  //Definindo a linguagem 
	
	printf("### cart�rio da ebac ###\n\n");   //in�cio do menu
    printf("Escolha a op��o desejada do menu:\n\n");
    printf("\t1 - Registrar nomes;\n\n");
    printf("\t2 - Consultar nomes;\n\n"); 
    printf("\t3 - Deletar nomes;\n\n");
    printf("\t4 - Sair do aplicativo;\n\n");
    printf("Op��o: ");  //fim do menu
	
    scanf("%d", &opcao);

    system("cls"); 
       
    switch(opcao)
	{
	case 1:  //se op for 1 
	registro();
	break;
	  
	case 2: //se op for 2 
	consulta();
    break;
        	
    case 3: //se op for 3
    deletar();
    break;
    
    case 4: //se op for 4
    printf("\nVolte sempre que precisar!");
	return 0;
    break;
    		
    default:  
    printf("essa op��o n�o est� dispon�vel\n");
	system("pause");
        		
}

}

}






	




