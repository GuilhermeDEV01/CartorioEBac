#include <stdio.h> //biblioteca de comunicação com o usuario
#include <stdlib.h>  //biblioteca de alocação de espaço em memoria 
#include <locale.h> //biblioteca de alocação de texto por região 
#include <string.h> //biblioteca de responsável a cuidar das strings


int registro() //chama a função

{
    char arquivo [40]; //conjunto de caracteres
	char cpf[40];
	char nome[40];
    char sobrenome[40];
    char cargo[40];
    
    printf("digite o CPF a ser cadastrado: ");
    scanf("%s",cpf);  //Se o arquvio não for encontrado(não existir)
    
    strcpy(arquivo,cpf); //copia os dados da string
    
    FILE *file; //cria o arquivo 
    file = fopen(arquivo,"w"); //cria o arquivo
	fprintf(file, "CPF: ");
	fprintf(file,cpf); //salva o valor da variável
	fclose(file); //fecha arquivo 
	
	file = fopen(arquivo, "a");
	fprintf(file,","); //dá espaço
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

int consulta() //chmama a função
 
{
	setlocale(LC_ALL,  "PORTUGUESE"); //define acentuação e alfabeto do que aparecerá ao user

	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);  // ler conteudo inserido pelo user
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
{
	printf("CPF digitado não consta na base de dados!\n");	
}
    printf("\nEssas são as informações do usuário!\n");	
	while(fgets(conteudo, 200, file) != NULL)

{
	printf("\n%s",conteudo);  // ler conteudo inserido pelo user
	printf("\n\n"); 
}
	
	system("pause");
}

int deletar() //função delete
{     
    char cpf[40];
    
    printf("Digite o CPF do usuário a ser deletado: ");
    scanf("%s", cpf);
    
    remove(cpf);
 
    FILE *file;
    file = fopen(cpf, "r");
    
    if(file == NULL) //Se o arquvio não for encontrado(não existir)
{
    printf("O usuário não se encontra no sistema!.\n");
	system("pause"); 
}

}

int main() //função principal
{
	int opcao=0; 
	int laco=1;
	
	for(laco=1;laco=1;) 
{
	
    system("cls");	
	    
	     
	
	
	setlocale(LC_ALL,  "PORTUGUESE");  //Definindo a linguagem 
	
	printf("### cartório da ebac ###\n\n");   //início do menu
    printf("Escolha a opção desejada do menu:\n\n");
    printf("\t1 - Registrar nomes;\n\n");
    printf("\t2 - Consultar nomes;\n\n"); 
    printf("\t3 - Deletar nomes;\n\n");
    printf("\t4 - Sair do aplicativo;\n\n");
    printf("Opção: ");  //fim do menu
	
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
    printf("essa opção não está disponível\n");
	system("pause");
        		
}

}

}






	




