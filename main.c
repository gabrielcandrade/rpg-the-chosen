#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <windows.h>
#include <locale.h>
#include "personagem.h"
#include <stdlib.h>

void logo();
int autenticarLogin(char *codigoUsuario);
void criarArquivo();
void fullscreen();
void musica();
void historia();
void delay(char * mensagem);
void aventura();
void menuInicial();
void inicializarPersonagem(struct Personagem *personagem, struct Skills *skills, 
struct Atributos *atributos, struct Arma *arma, struct Pet *pet, struct Montaria *montaria);

int main()
{
	char codigoUsuario[50], nomeDoArquivo[35];
	
	fullscreen();
	logo();

	centerText();
	printf("Digite seu codigo de usuario: ");
	scanf("%s", &codigoUsuario);
	
	if (autenticarLogin(codigoUsuario)){
		printf("\n\n");
		centerText();
		printf("Logando usuario . . .");

		Sleep(3000);
	}
	else{
		criarArquivo(codigoUsuario);
	}
	
	system("cls");
	logo();
	menuInicial();
	return 0;
}

int autenticarLogin(char *codigoUsuario){
	if(strcmp(codigoUsuario,"123")) // FixMe: Try to use multi-users
		return 0;
	else
		return 1;
}

void inicializarPersonagem(struct Personagem *personagem, struct Skills *skills, struct Atributos *atributos, struct Arma *arma, struct Pet *pet, struct Montaria *montaria){
	personagem->nivel = 1;
	personagem->hp = 200;
	personagem->mana = 100;
	personagem->pontKills = 0;
	skills->sentenca_morte = 0;
	skills->flecha_penetrante = 0; 
	skills->chuva_flechas = 0; 
	skills->flecha_penas = 0; 
	skills->excalibur = 0; 
	skills->quebrar_armadura = 0; 
	skills->ferida_mortal = 0; 
	skills->avanco_poderoso = 0; 
	skills->recuperacao_divina = 0; 
	skills->corroer = 0; 
	skills->lanca_de_raio = 0; 
	skills->cristalizar_mana = 0; 
	atributos->forca = 5; 
	atributos->destreza = 5; 
	atributos->inteligencia = 5; 
	atributos->sorte = 5; 
	arma->arco = 0; 
	arma->besta = 0; 
	arma->espada_escudo = 0; 
	arma->lanca_escudo = 0; 
	arma->varinha = 0; 
	arma->cajado = 0; 
	pet->tigre = 0; 
	pet->vibora = 0; 
	pet->aguia = 0; 
	montaria->buffalo = 0; 
	montaria->cavalo = 0; 
	montaria->dragao = 0; 
}

void criarArquivo(char *codigoUsuario){
	char extensao[5] = ".txt";
	
	FILE *pont_arq;
	
	strcat(codigoUsuario, extensao);
	//abrindo o arquivo
	pont_arq = fopen(codigoUsuario, "w");
	
	struct Personagem p;
	struct Skills s;
	struct Atributos a;
	struct Arma ar;
	struct Pet pet;
	struct Montaria m;
	
	inicializarPersonagem(&p, &s, &a, &ar, &pet, &m);
	
	// Escrevendo informacao dentro do arquivo .txt
	// fprintf(pont_arq, "%s", linha)
	fprintf(pont_arq, "Nivel: %d\nHP: %d\nMana: %d\nPontKills: %d\nSetenca da Morte: %d\nFlecha Penetrante: %d\nChuva de Flechas: %d\nFlecha de Penas: %d\nExcalibur: %d\nQuebrar Armadura: %d\nFerida Mortal: %d\nAvanco Poderoso: %d\nRecuperacao Divina: %d\nCorroer: %d\nLanca de Raio: %d\nCristalizar Mana: %d\nForca: %d\nDestreza: %d\nInteligencia: %d\nSorte: %d\nArco: %d\nBesta: %d\nEspada e Escudo: %d\nLanca e Escudo:%d\nVarinha: %d\nCajado: %d\nTigre: %d\nVibora: %d\nAguia: %d\nBuffalo: %d\nCavalo: %d\nDragao: %d\n", p.nivel, p.hp, p.mana, p.pontKills, s.sentenca_morte, s.flecha_penetrante, s.chuva_flechas, s.flecha_penas, s.excalibur, s.quebrar_armadura, s.ferida_mortal, s.avanco_poderoso, s.recuperacao_divina, s.corroer, s.lanca_de_raio, s.cristalizar_mana, a.forca, a.destreza, a.inteligencia, a.sorte, ar.arco, ar.besta, ar.espada_escudo, ar.lanca_escudo, ar.varinha, ar.cajado, pet.tigre, pet.vibora, pet.aguia, m.buffalo, m.cavalo, m.dragao);
  
	// fechando arquivo
	fclose(pont_arq);
  
	//mensagem para o usuário
	printf("Sera criado um personagem novo! Bem vindo a Charrfall!\n");
  
	system("pause");
}

void logo()
{
	printf("\t\t\t\t\t\t\t\t\t######################################################################\n");Sleep(100);
	printf("\t\t\t\t\t\t\t\t\t#                                                                    #\n");Sleep(100);
	printf("\t\t\t\t\t\t\t\t\t#         _____ _             ____ _                                 #\n");Sleep(100);
	printf("\t\t\t\t\t\t\t\t\t#        |_   _| |__   ___   / ___| |__   ___  ___  ___ _ __         #\n");Sleep(100);
	printf("\t\t\t\t\t\t\t\t\t#          | | | '_ \\ / _ \\ | |   | '_ \\ / _ \\/ __|/ _ \\ '_ \\        #\n");Sleep(100);
	printf("\t\t\t\t\t\t\t\t\t#          | | | | | |  __/ | |___| | | | (_) \\__ \\  __/ | | |       #\n");Sleep(100);
	printf("\t\t\t\t\t\t\t\t\t#          |_| |_| |_|\\___|  \\____|_| |_|\\___/|___/\\___|_| |_|       #\n");Sleep(100);
   	printf("\t\t\t\t\t\t\t\t\t#                                                                    #\n");Sleep(100);
	printf("\t\t\t\t\t\t\t\t\t#                                                                    #\n");Sleep(100);
	printf("\t\t\t\t\t\t\t\t\t######################################################################\n");Sleep(100);
	printf("\n\n");
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
	const char mensagem[100000] = "Aqui narrará a lore inicial que fará com que o carinha se empolgue com as historia.\n\n";
	delay(mensagem);
}

void delay(char * mensagem){
	int k;
	for (k = 0; mensagem[k] != '\0' ; k++){
		printf("%c", mensagem[k]);
		Sleep(100);
	}
}

void aventura(){
	int escolhaAventura;
	setlocale(LC_ALL, "Portuguese");
	printf("\t\t\t\t\t\t\t\t\t#################### Você está em uma AVENTURA #######################\n");
	printf("\t\t\t\t\t\t\t\t\t######################################################################\n");
	printf("\t\t\t\t\t\t\t\t\t#                                                                    #\n");
	printf("\t\t\t\t\t\t\t\t\t#                            Nível Recomendado:                      #\n");
	printf("\t\t\t\t\t\t\t\t\t#                                                                    #\n");
	printf("\t\t\t\t\t\t\t\t\t#                        1- Floresta       (Livre)                   #\n");
	printf("\t\t\t\t\t\t\t\t\t#                                                                    #\n");
	printf("\t\t\t\t\t\t\t\t\t#                        2- Caverna         (10+)                    #\n");
	printf("\t\t\t\t\t\t\t\t\t#                                                                    #\n");
	printf("\t\t\t\t\t\t\t\t\t#                        3- Montanha        (15+)                    #\n");
	printf("\t\t\t\t\t\t\t\t\t#                                                                    #\n");
	printf("\t\t\t\t\t\t\t\t\t#                        4- Pantano         (20+)                    #\n");
	printf("\t\t\t\t\t\t\t\t\t#                                                                    #\n");
	printf("\t\t\t\t\t\t\t\t\t#                        5- Mar             (25+)                    #\n");
	printf("\t\t\t\t\t\t\t\t\t#                                                                    #\n");
	printf("\t\t\t\t\t\t\t\t\t######################################################################\n");
	printf("\n\n\n\t\t\t\t\t\t\t\t\tPara onde voce deseja ir? ");
	scanf("%d", &escolhaAventura);
	switch(escolhaAventura){
		case 1:
			printf("\n\n");
			centerText();
			printf("Você acaba de entrar em: Floresta\n");
			mensagem[10000] = "A medida que você se distanciar da cidade, mais sucetível a inimigos você estará. Lembre-se, quando você voltar para a cidade, ainda poderá encontrar alguns inimigos.");
			break;
		case 2:
			printf("\n\n");
			centerText();
			printf("Você acaba de entrar em: Caverna\n");
			break;
		case 3:
			printf("\n\n");
			centerText();
			printf("Você acaba de entrar em: Montanha\n");
			break;
		case 4:
			printf("\n\n");
			centerText();
			printf("Você acaba de entrar em: Pantano\n");
			break;
		case 5:
			printf("\n\n");
			centerText();
			printf("Você acaba de entrar em: Mar\n");
			break;
		default :
			centerText();
			printf("Opção Inválida\n");
	}
	
}

void menuInicial(){
	int escolha;
	setlocale(LC_ALL, "Portuguese");
	
	printf("\t\t\t\t\t\t\t\t\t################## Bem vindo ao Reino de Charrfall! ##################\n");
	printf("\t\t\t\t\t\t\t\t\t#                                                                    #\n");
	printf("\t\t\t\t\t\t\t\t\t#                       Selecione a opção desejada:                  #\n");
	printf("\t\t\t\t\t\t\t\t\t#                                                                    #\n");
	printf("\t\t\t\t\t\t\t\t\t#                            1- Aventura                             #\n");
	printf("\t\t\t\t\t\t\t\t\t#                                                                    #\n");
	printf("\t\t\t\t\t\t\t\t\t#                            2- Curandeira                           #\n");
	printf("\t\t\t\t\t\t\t\t\t#                                                                    #\n");
	printf("\t\t\t\t\t\t\t\t\t#                            3- Alquimista                           #\n");
	printf("\t\t\t\t\t\t\t\t\t#                                                                    #\n");
	printf("\t\t\t\t\t\t\t\t\t#                            4- Estábulo                             #\n");
	printf("\t\t\t\t\t\t\t\t\t#                                                                    #\n");
	printf("\t\t\t\t\t\t\t\t\t#                            5- PetMaster                            #\n");
	printf("\t\t\t\t\t\t\t\t\t#                                                                    #\n");
	printf("\t\t\t\t\t\t\t\t\t######################################################################");
	printf("\n\n\n\t\t\t\t\t\t\t\t\tPara onde voce deseja ir? ");
		
	scanf("%d", &escolha);
	
	switch(escolha){ //FixMe: Apenas pode ir em aventuras.
		case 1:
			system("cls");
			logo();
			aventura();
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		default :
			printf("Opção inválida. \n");
	}
}