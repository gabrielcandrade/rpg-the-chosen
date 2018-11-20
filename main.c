#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <windows.h>
#include <locale.h>
#include "personagem.h"

void logo();
int autenticarLogin(char *codigoUsuario);
void criarArquivo();
void fullscreen();
void musica();
void historia();
void delay(char * mensagem);
void inicializarPersonagem(struct Personagem *personagem, struct Skills *skills, 
struct Atributos *atributos, struct Arma *arma, struct Pet *pet, struct Montaria *montaria);

int main()
{
	char codigoUsuario[50], nomeDoArquivo[35];
	
	fullscreen();
	logo();
	musica();
	historia();
	
	printf("Digite seu codigo de usuario: ");
	scanf("%s", &codigoUsuario);
	
	if (autenticarLogin(codigoUsuario)){
		printf("Usuario Logado\n\n\n\n\n\n");
	}
	else{
		criarArquivo(codigoUsuario);
	}

	
	return 0;
}

int autenticarLogin(char *codigoUsuario){
	if(strcmp(codigoUsuario,"123")) // FixMe: Try to use multi-users
		return 0;
	else
		return 1;
}

void criarArquivo(char *codigoUsuario){
	char extensao[5] = ".txt";
	
	FILE *pont_arq;
	
	strcat(codigoUsuario, extensao);
	//abrindo o arquivo
	pont_arq = fopen(codigoUsuario, "w");
	
	// Escrevendo informacao dentro do arquivo .txt
	// fprintf(pont_arq, "%s", linha)
	
	//%d\n %d\n %d\n %d\n %d\n %d\n %d\n %d\n %d\n %d\n %d\n %d\n %d\n %d\n %d\n %d\n %d\n %d\n %d\n %d\n %d\n %d\n %d\n %d\n 
  
	// fechando arquivo
	fclose(pont_arq);
  
	//mensagem para o usuário
	printf("Sera criado um personagem novo! Bem vindo a Charrfall!\n");
  
	system("pause");
}

void inicializarPersonagem(struct Personagem *personagem, struct Skills *skills, 
struct Atributos *atributos, struct Arma *arma, struct Pet *pet, struct Montaria *montaria){
	personagem.nivel = 1;
	personagem.hp = 200;
	personagem.mana = 100;
	personagem.pontKills = 0;
	skills.sentenca_morte = 0;
	skills.flecha_penetrante = 0;
	skills.chuva_flechas = 0;
	skills.flecha_penas = 0;
	skills.excalibur = 0;
	skills.quebrar_armadura = 0;
	skills.ferida_mortal = 0;
	skills.avanco_poderoso = 0;
	skills.recuperacao_divina = 0;
	skills.corroer = 0;
	skills.lanca_de_raio = 0;
	skills.cristalizar_mana = 0;
	atributos.forca = 5;
	atributos.destreza = 5;
	atributos.inteligencia = 5;
	atributos.sorte = 5;
	arma.arco = 0;
	arma.besta = 0;
	arma.espada_escudo = 0;
	arma.lanca_escudo = 0;
	arma.varinha = 0;
	arma.cajado = 0;
	pet.tigre = 0;
	pet.vibora = 0;
	pet.aguia = 0;
}

void logo()
{
	printf("\t\t\t\t\t\t\t\t\t######################################################################\n");
	printf("\t\t\t\t\t\t\t\t\t#                                                                    #\n");
	printf("\t\t\t\t\t\t\t\t\t#         _____ _             ____ _                                 #\n");
	printf("\t\t\t\t\t\t\t\t\t#        |_   _| |__   ___   / ___| |__   ___  ___  ___ _ __         #\n");
	printf("\t\t\t\t\t\t\t\t\t#          | | | '_ \\ / _ \\ | |   | '_ \\ / _ \\/ __|/ _ \\ '_ \\        #\n");
	printf("\t\t\t\t\t\t\t\t\t#          | | | | | |  __/ | |___| | | | (_) \\__ \\  __/ | | |       #\n");
	printf("\t\t\t\t\t\t\t\t\t#          |_| |_| |_|\\___|  \\____|_| |_|\\___/|___/\\___|_| |_|       #\n");
   	printf("\t\t\t\t\t\t\t\t\t#                                                                    #\n");
	printf("\t\t\t\t\t\t\t\t\t#                                                                    #\n");
	printf("\t\t\t\t\t\t\t\t\t######################################################################\n");
	printf("\n\n");
	centerText();
}

void centerText(){
	printf("\t\t\t\t\t\t\t\t\t\t\t ");
}

void musica(void){
	Beep(523,500);
	}

void fullscreen(){
	keybd_event ( VK_MENU, 0x36, 0, 0 );
	keybd_event ( VK_RETURN, 0x1C, 0, 0 );
	keybd_event ( VK_RETURN, 0x1C, KEYEVENTF_KEYUP, 0 );
	keybd_event ( VK_MENU, 0x38, KEYEVENTF_KEYUP, 0 );
}

void historia(){
	setlocale(LC_ALL, "Portuguese");
	const char mensagem[100000] = "Aqui narrará a lore inicial que fará com que o carinha.";
	delay(mensagem);
}

void delay(char * mensagem){
	int k;
	for (k = 0; mensagem[k] != '\0' ; k++){
		printf("%c", mensagem[k]);
		Sleep(100);
	}
}