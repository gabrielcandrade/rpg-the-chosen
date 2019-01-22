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
void aventura(char * codigoUsuario);
void menuInicial(char * codigoUsuario);
void centerText();
int navegacao();
void curandeira();
void serGuerreiro(codigoUsuario);
void escolherClasse(char * codigoUsuario);
void inicializarPersonagem(struct Personagem *personagem, struct Atributos *atributos,
						   struct Arma *arma, struct Pet *pet, struct Montaria *montaria);

int main(){
	char codigoUsuario[50], nomeDoArquivo[35];
	int loop = 1;
	
	fullscreen();
	logo();

	centerText();
	printf("Digite seu codigo de usuario: ");
	scanf("%s", &codigoUsuario);

	autenticarLogin(codigoUsuario);
	
	while (loop == 1){
		system("cls");
		logo();
		menuInicial(codigoUsuario);
	}
	return 0;
}

int autenticarLogin(char *codigoUsuario){
	char extensao[5] = ".txt";
	FILE *pont_arq;
	
	strcat(codigoUsuario, extensao);
	
	pont_arq = fopen(codigoUsuario, "r");
	
	//Verifica abertura do arquivo:
	if(!pont_arq){
		criarArquivo();
		return 0;
	}
	else{
		printf("\n\n");
		centerText();
		printf("Logando em sua conta . . .");
		Sleep(3000);
		return 1;
	}	
}

void lore(){
 setlocale(LC_ALL, "Portuguese");
 printf("\n\t\t\t\t\t\tVocê era uma pessoa normal, vivia no planeta terra do universo 7, estudante em uma instituição de magia renomada conhecida por Hog... ""Unipê"".\n");
 printf("\n\t\t\t\t\t\tSua turma possuia um estranho costume de manipular uma magia poderosa conhecida como Malloc. Até então, uma arte pouco conhecida.\n");
 printf("\n\t\t\t\t\t\tCerto dia, a turma se reuniu junto ao Mestre Tainha para realizar um ritual. Infelizmente eles não sabiam as consequências que iriam sofrer.\n");
 printf("\n\t\t\t\t\t\tUm poderoso demônico surgiu, seu nome, Seap Saisoj( nunca leia esse nome ao contrário). Com apenas um movimento, toda a turma foi teletransportada para o mundo de Charfall.\n");
 printf("\n\t\t\t\t\t\tAgora você se encontra perdido em um mundo de magia, cabe a você traçar seu caminho para a vitória e obter sua vingança.\n");
 printf("\n\t\t\t\t\t\tPara realizar esse feito, você deve derrotar o arauto do demônio. . . Cthulhu\n");
}

void inicializarPersonagem(struct Personagem *personagem, struct Atributos *atributos, struct Arma *arma, struct Pet *pet, struct Montaria *montaria){
	personagem->nivel = 1;
	personagem->exp = 0;
	personagem->hp = 200;
	personagem->moedas = 100;
	personagem->pontKills = 0;
	atributos->forca = 5;
	atributos->destreza = 5;
	atributos->inteligencia = 5;
	atributos->sorte = 5;
	arma->arco = 0;
	arma->espada = 0;
	arma->varinha = 0;
	pet->tigre = 0;
	pet->vibora = 0;
	pet->aguia = 0;
	montaria->buffalo = 0;
	montaria->cavalo = 0;
	montaria->dragao = 0;
}

void criarArquivo(char *codigoUsuario){
	int loop = 1;
	FILE *pont_arq;
	
	//abrindo o arquivo
	pont_arq = fopen(codigoUsuario, "w");

	struct Personagem p;
	struct Atributos a;
	struct Arma ar;
	struct Pet pet;
	struct Montaria m;

	inicializarPersonagem(&p, &a, &ar, &pet, &m);
	
	// Escrevendo informacao dentro do arquivo .txt
	// fprintf(pont_arq, "%s", linha)
	fprintf(pont_arq, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", p.nivel, p.exp, p.hp, p.moedas, p.pontKills, a.forca, a.destreza, a.inteligencia, a.sorte, ar.arco, ar.espada, ar.varinha, pet.tigre, pet.vibora, pet.aguia, m.buffalo, m.cavalo, m.dragao);

	// fechando arquivo
	fclose(pont_arq);

	//mensagem para o usuário
	printf("\n\n");
	centerText();
	printf("Sera criado um personagem novo! Bem vindo a Charrfall!\n");
	Sleep(3000);
	lore();printf("\n\n");
	centerText();
	system("pause");
	system("cls");
	logo();
	while (loop == 1){
		escolherClasse(codigoUsuario);
	}

	system("pause");
}

void logo(){
	printf("\t\t\t\t\t\t\t\t\t######################################################################\n");	Sleep(100);
	printf("\t\t\t\t\t\t\t\t\t#                                                                    #\n");	Sleep(100);
	printf("\t\t\t\t\t\t\t\t\t#         _____ _             ____ _                                 #\n");	Sleep(100);
	printf("\t\t\t\t\t\t\t\t\t#        |_   _| |__   ___   / ___| |__   ___  ___  ___ _ __         #\n");	Sleep(100);
	printf("\t\t\t\t\t\t\t\t\t#          | | | '_ \\ / _ \\ | |   | '_ \\ / _ \\/ __|/ _ \\ '_ \\        #\n");	Sleep(100);
	printf("\t\t\t\t\t\t\t\t\t#          | | | | | |  __/ | |___| | | | (_) \\__ \\  __/ | | |       #\n");	Sleep(100);
	printf("\t\t\t\t\t\t\t\t\t#          |_| |_| |_|\\___|  \\____|_| |_|\\___/|___/\\___|_| |_|       #\n");	Sleep(100);
	printf("\t\t\t\t\t\t\t\t\t#                                                                    #\n");	Sleep(100);
	printf("\t\t\t\t\t\t\t\t\t#                                                                    #\n");	Sleep(100);
	printf("\t\t\t\t\t\t\t\t\t######################################################################\n");	Sleep(100);
	printf("\n\n");
}

void centerText(){
	printf("\t\t\t\t\t\t\t\t\t\t\t ");
}

void musica(void){
	Beep(523, 500);
}

void fullscreen(){
	keybd_event ( VK_MENU, 0x36, 0, 0 );
	keybd_event ( VK_RETURN, 0x1C, 0, 0 );
	keybd_event ( VK_RETURN, 0x1C, KEYEVENTF_KEYUP, 0 );
	keybd_event ( VK_MENU, 0x38, KEYEVENTF_KEYUP, 0 );
}

void historia(){
	setlocale(LC_ALL, "Portuguese");
	const char mensagem[10000] = "Aqui narrará a lore inicial que fará com que o carinha se empolgue com as historia.\n\n";
	delay(mensagem);
}

void delay(char * mensagem){
	int k;
	for (k = 0; mensagem[k] != '\0' ; k++)
	{
		printf("%c", mensagem[k]);
		Sleep(5);
	}
}

void aventura(char * codigoUsuario){
	int poder = calcularPoder(codigoUsuario);
	int escolhaAventura;
	setlocale(LC_ALL, "Portuguese");
	printf("\t\t\t\t\t\t\t\t\t#################### Você está em uma AVENTURA #######################\n");
	printf("\t\t\t\t\t\t\t\t\t######################################################################\n");
	printf("\t\t\t\t\t\t\t\t\t#                                                                    #\n");
	printf("\t\t\t\t\t\t\t\t\t#                            Seu poder de luta: %d                   #\n", poder);
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


	switch(escolhaAventura)
	{
	case 1:
		system("cls");
		logo();
		char mensagemFloresta[10000] = "\t\t\t\t\t\t\t\t\t\t\tVocê acaba de entrar em: Floresta\n\n\t\t\t\t\t\t\tBem vindo à Floresta Proibida, grande região localizada em toda região oeste de Charfall a partir das Colinas Errantes. \n\t\t\t\t\t\t\tAqui você irá se deparar com criaturas ferozes e mortais, tais como:\n\n\t\t\t\t\t\t\t\t#########################################################################################\n\t\t\t\t\t\t\t\t#     Javali     #     Lobo     #     Goblins     #     Salamandra     #     Harpia     #\n\t\t\t\t\t\t\t\t#                #              #                 #                    #                #\n\t\t\t\t\t\t\t\t#    Terrestre   #  Terrestre   #     Terrestre   #     Terrestre      #     Voador     #\n\t\t\t\t\t\t\t\t#                #              #                 #                    #                #\n\t\t\t\t\t\t\t\t#    Hp: 50      #    Hp: 100   #     Hp: 150     #      Hp: 200       #     Hp: 300    #\n\t\t\t\t\t\t\t\t#                #              #                 #                    #                #\n\t\t\t\t\t\t\t\t#########################################################################################\n\n\t\t\t\t\t\t\tSeja cuidadoso, enfrentar uma criatura estando despreparado pode ser fatal.\n";
		delay(mensagemFloresta);
		navegacaoFloresta(codigoUsuario);
		break;
	case 2:
		system("cls");
		logo();
		char mensagemCaverna[10000] = "\t\t\t\t\t\t\t\t\t\t\tVocê acaba de entrar em: Caverna\n\n\t\t\t\t\t\t\tBem vindo à Caverna do Dragão, localizada em um local pouco conhecido, escondido na Floresta Proibida. \n\t\t\t\t\t\t\tAqui você irá se deparar com criaturas ferozes e mortais, tais como:\n\n\t\t\t\t\t\t\t\t#########################################################################################\n\t\t\t\t\t\t\t\t#    Morcego     #  Manticore   #     Ettercap    #  Morcego Gigante   #     Dragão     #\n\t\t\t\t\t\t\t\t#                #              #                 #                    #                #\n\t\t\t\t\t\t\t\t#    Voador      #   Voador     #     Terrestre   #       Voador       #     Voador     #\n\t\t\t\t\t\t\t\t#                #              #                 #                    #                #\n\t\t\t\t\t\t\t\t#    Hp: 300     #   Hp: 400    #     Hp: 430     #      Hp: 500       #     Hp: 700    #\n\t\t\t\t\t\t\t\t#                #              #                 #                    #                #\n\t\t\t\t\t\t\t\t#########################################################################################\n\n\t\t\t\t\t\t\tSeja cuidadoso, enfrentar uma criatura estando despreparado pode ser fatal.\n";
		delay(mensagemCaverna);
		navegacaoCaverna(codigoUsuario);
		break;
	case 3:
		system("cls");
		logo();
		char mensagemMontanha[10000] = "\t\t\t\t\t\t\t\t\t\t\tVocê acaba de entrar em: Montanha\n\n\t\t\t\t\t\t\t\tBem vindo às Colinas Errantes, localizada no ponto mais alto de Charfall. \n\t\t\t\t\t\t\t\tAqui você irá se deparar com criaturas ferozes e mortais, tais como:\n\n\t\t\t\t\t\t\t\t#########################################################################################\n\t\t\t\t\t\t\t\t#    Owlbear     #   Minotauro  #     Escorpião   #     Escaravelho    #     Golem      #\n\t\t\t\t\t\t\t\t#                #              #                 #                    #                #\n\t\t\t\t\t\t\t\t#    Terrestre   #   Terrestre  #     Terrestre   #     Terrestre      #     Terrestre  #\n\t\t\t\t\t\t\t\t#                #              #                 #                    #                #\n\t\t\t\t\t\t\t\t#    Hp: 600     #   Hp: 700    #     Hp: 750     #     Hp: 800        #     Hp: 1000   #\n\t\t\t\t\t\t\t\t#                #              #                 #                    #                #\n\t\t\t\t\t\t\t\t#########################################################################################\n\n\t\t\t\t\t\t\t\tSeja cuidadoso, enfrentar uma criatura estando despreparado pode ser fatal.\n";
		delay(mensagemMontanha);
		navegacaoMontanha(codigoUsuario);
		break;
	case 4:
		system("cls");
		logo();
		char mensagemPantano[10000] = "\t\t\t\t\t\t\t\t\t\t\tVocê acaba de entrar em: Pantano\n\n\t\t\t\t\t\t\t\tBem vindo ao Pantano Palus, localizada ao norte das Colinas Errantes. \n\t\t\t\t\t\t\t\tAqui você irá se deparar com criaturas ferozes e mortais, tais como:\n\n\t\t\t\t\t\t\t\t#########################################################################################\n\t\t\t\t\t\t\t\t#    Esqueleto   #   Pantera    #   Crocopótamo   #      Agrutha       #     Ente       #\n\t\t\t\t\t\t\t\t#                #              #                 #                    #                #\n\t\t\t\t\t\t\t\t#    Terrestre   #   Terrestre  #    Terrestre    #      Terrestre     #     Terrestre  #\n\t\t\t\t\t\t\t\t#                #              #                 #                    #                #\n\t\t\t\t\t\t\t\t#    Hp: 900     #   Hp: 950    #     Hp: 1000    #      Hp: 1100      #     Hp: 1300   #\n\t\t\t\t\t\t\t\t#                #              #                 #                    #                #\n\t\t\t\t\t\t\t\t#########################################################################################\n\n\t\t\t\t\t\t\t\tSeja cuidadoso, enfrentar uma criatura estando despreparado pode ser fatal.\n";
		delay(mensagemPantano);
		navegacaoPantano(codigoUsuario);
		break;
	case 5:
		system("cls");
		logo();
		char mensagemMar[10000] = "\t\t\t\t\t\t\t\t\t\t\tVocê acaba de entrar em: Mar\n\n\t\t\t\t\t\t\t\t\tBem vindo ao Mar Morto, localizada ao leste das Colinas Errantes. \n\t\t\t\t\t\t\t\t\tAqui você irá se deparar com criaturas ferozes e mortais, tais como:\n\n\t\t\t\t\t\t\t\t#########################################################################################\n\t\t\t\t\t\t\t\t#                         ALERTA: NÍVEL MAIS AVANÇADO                                   #\n\t\t\t\t\t\t\t\t#########################################################################################\n\t\t\t\t\t\t\t\t#     Tubarão    #Baleia Megalo # Dragão de Água  #      Leviatã       #     Cthulhu    #\n\t\t\t\t\t\t\t\t#                #              #                 #                    #                #\n\t\t\t\t\t\t\t\t#     Aquático   #   Aquático   #    Aquático     #      Aquático      #      TODOS     #\n\t\t\t\t\t\t\t\t#                #              #                 #                    #                #\n\t\t\t\t\t\t\t\t#     Hp: 1300   #   Hp: 1400   #     Hp: 1500    #      Hp: 1800      #     Hp: 2500   #\n\t\t\t\t\t\t\t\t#                #              #                 #                    #                #\n\t\t\t\t\t\t\t\t#########################################################################################\n\n\n\t\t\t\t\t\t\t\t\tSeja cuidadoso, enfrentar uma criatura estando despreparado pode ser fatal.\n";
		delay(mensagemMar);
		navegacaoMar(codigoUsuario);
		break;
	default :
		centerText();
		printf("Opção Inválida\n");
	}

}

void menuInicial(char *codigoUsuario){
	int escolha, loop;
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
	switch(escolha)  //FixMe: Nao pode ir para Estabulo ou PetMaster.
	{
	case 1:
		system("cls");
		logo();
		aventura(codigoUsuario);
		break;
	case 2:
		system("cls");
		logo();
		curandeira(codigoUsuario);
		break;
	case 3:
		system("cls");
		logo();
		alquimista(codigoUsuario);
		break;
	case 4:
		system("cls");
		logo();
		estabulo(codigoUsuario);
		break;
	case 5:
		system("cls");
		logo();
		petMaster(codigoUsuario);
		break;
	default :
		printf("\n\n");
		centerText();
		printf("Opção inválida. \n");
		Sleep(1000);
	}
}

void navegacaoFloresta(char *codigoUsuario){
	int escolha;

	printf("\n\n\t\t\t\t\t\t\t\t\t######################################################################\n");
	printf("\t\t\t\t\t\t\t\t\t#                                                                    #\n");
	printf("\t\t\t\t\t\t\t\t\t#                       Selecione a opção desejada:                  #\n");
	printf("\t\t\t\t\t\t\t\t\t#                                                                    #\n");
	printf("\t\t\t\t\t\t\t\t\t#                            1- Andar                                #\n");
	printf("\t\t\t\t\t\t\t\t\t#                                                                    #\n");
	printf("\t\t\t\t\t\t\t\t\t#                            0- Voltar para a cidade                 #\n");
	printf("\t\t\t\t\t\t\t\t\t#                                                                    #\n");
	printf("\t\t\t\t\t\t\t\t\t######################################################################");
	printf("\n\n\n\t\t\t\t\t\t\t\t\tO que você deseja fazer? ");

	scanf("%d", &escolha);

	if (escolha == 1)
	{
		inimigosFloresta(codigoUsuario);
	}
	else
	{
		system("cls");
		logo();
		menuInicial(codigoUsuario);
	}
}

void navegacaoCaverna(char * codigoUsuario){
	int escolha;

	printf("\n\n\t\t\t\t\t\t\t\t\t######################################################################\n");
	printf("\t\t\t\t\t\t\t\t\t#                                                                    #\n");
	printf("\t\t\t\t\t\t\t\t\t#                       Selecione a opção desejada:                  #\n");
	printf("\t\t\t\t\t\t\t\t\t#                                                                    #\n");
	printf("\t\t\t\t\t\t\t\t\t#                            1- Andar                                #\n");
	printf("\t\t\t\t\t\t\t\t\t#                                                                    #\n");
	printf("\t\t\t\t\t\t\t\t\t#                            0- Voltar para a cidade                 #\n");
	printf("\t\t\t\t\t\t\t\t\t#                                                                    #\n");
	printf("\t\t\t\t\t\t\t\t\t######################################################################");
	printf("\n\n\n\t\t\t\t\t\t\t\t\tO que você deseja fazer? ");

	scanf("%d", &escolha);

	if (escolha == 1)
	{
		inimigosCaverna(codigoUsuario);
	}
	else
	{
		system("cls");
		logo();
		menuInicial(codigoUsuario);
	}
}

void navegacaoMontanha(char * codigoUsuario){
	int escolha;

	printf("\n\n\t\t\t\t\t\t\t\t\t######################################################################\n");
	printf("\t\t\t\t\t\t\t\t\t#                                                                    #\n");
	printf("\t\t\t\t\t\t\t\t\t#                       Selecione a opção desejada:                  #\n");
	printf("\t\t\t\t\t\t\t\t\t#                                                                    #\n");
	printf("\t\t\t\t\t\t\t\t\t#                            1- Andar                                #\n");
	printf("\t\t\t\t\t\t\t\t\t#                                                                    #\n");
	printf("\t\t\t\t\t\t\t\t\t#                            0- Voltar para a cidade                 #\n");
	printf("\t\t\t\t\t\t\t\t\t#                                                                    #\n");
	printf("\t\t\t\t\t\t\t\t\t######################################################################");
	printf("\n\n\n\t\t\t\t\t\t\t\t\tO que você deseja fazer? ");

	scanf("%d", &escolha);

	if (escolha == 1)
	{
		inimigosMontanha(codigoUsuario);
	}
	else
	{
		system("cls");
		logo();
		menuInicial(codigoUsuario);
	}
}

void navegacaoPantano(char * codigoUsuario){
	int escolha;

	printf("\n\n\t\t\t\t\t\t\t\t\t######################################################################\n");
	printf("\t\t\t\t\t\t\t\t\t#                                                                    #\n");
	printf("\t\t\t\t\t\t\t\t\t#                       Selecione a opção desejada:                  #\n");
	printf("\t\t\t\t\t\t\t\t\t#                                                                    #\n");
	printf("\t\t\t\t\t\t\t\t\t#                            1- Andar                                #\n");
	printf("\t\t\t\t\t\t\t\t\t#                                                                    #\n");
	printf("\t\t\t\t\t\t\t\t\t#                            0- Voltar para a cidade                 #\n");
	printf("\t\t\t\t\t\t\t\t\t#                                                                    #\n");
	printf("\t\t\t\t\t\t\t\t\t######################################################################");
	printf("\n\n\n\t\t\t\t\t\t\t\t\tO que você deseja fazer? ");

	scanf("%d", &escolha);

	if (escolha == 1)
	{
		inimigosPantano(codigoUsuario);
	}
	else
	{
		system("cls");
		logo();
		menuInicial(codigoUsuario);
	}
}

void navegacaoMar(char * codigoUsuario){
	int escolha;

	printf("\n\n\t\t\t\t\t\t\t\t\t######################################################################\n");
	printf("\t\t\t\t\t\t\t\t\t#                                                                    #\n");
	printf("\t\t\t\t\t\t\t\t\t#                       Selecione a opção desejada:                  #\n");
	printf("\t\t\t\t\t\t\t\t\t#                                                                    #\n");
	printf("\t\t\t\t\t\t\t\t\t#                            1- Andar                                #\n");
	printf("\t\t\t\t\t\t\t\t\t#                                                                    #\n");
	printf("\t\t\t\t\t\t\t\t\t#                            0- Voltar para a cidade                 #\n");
	printf("\t\t\t\t\t\t\t\t\t#                                                                    #\n");
	printf("\t\t\t\t\t\t\t\t\t######################################################################");
	printf("\n\n\n\t\t\t\t\t\t\t\t\tO que você deseja fazer? ");

	scanf("%d", &escolha);

	if (escolha == 1)
	{
		inimigosMar(codigoUsuario);
	}
	else
	{
		system("cls");
		logo();
		menuInicial(codigoUsuario);
	}
}

void inimigosFloresta(char * codigoUsuario){
	int numero, pForcaJavali, pForcaLobo, pForcaGoblin, pForcaSalamandra, pForcaHarpia, expJavali, moedas, expLobo, expGoblin, expSalamandra, expHarpia;
	srand(time(NULL));
	centerText();
	printf("Procurando inimigo . . .\n\n");
	Sleep(3000);
	numero = rand() % 15;
	if (numero < 3) // 1 ou 2
	{
		system("cls");
		logo();
		centerText();
		printf("Voce encontrou um Javali.\n\n");
		pForcaJavali = 70;
		expJavali = 5;
		srand(time(NULL));
		moedas = rand() % 25;
		menuDeBatalha(codigoUsuario, pForcaJavali, expJavali, moedas);
	}
	else if ((numero > 2) && (numero < 5))  //3 ou 4
	{
		system("cls");
		logo();
		centerText();
		printf("Voce encontrou um Lobo.\n\n");
		pForcaLobo = 90;
		expLobo = 7;
		srand(time(NULL));
		moedas = rand() % 25;
		menuDeBatalha(codigoUsuario, pForcaLobo, expLobo, moedas);
	}
	else if ((numero > 4) && (numero < 7))  // 5 ou 6
	{
		system("cls");
		logo();
		centerText();
		printf("Voce encontrou um Goblin.\n\n");
		pForcaGoblin = 110;
		expGoblin = 9;
		srand(time(NULL));
		moedas = rand() % 25;
		menuDeBatalha(codigoUsuario, pForcaGoblin, expGoblin, moedas);
	}
	else if ((numero > 6) && (numero < 9))  //7 ou 8
	{
		system("cls");
		logo();
		centerText();
		printf("Voce encontrou uma Salamandra.\n\n");
		pForcaSalamandra = 130;
		expSalamandra = 11;
		srand(time(NULL));
		moedas = rand() % 25;
		menuDeBatalha(codigoUsuario, pForcaSalamandra, expSalamandra, moedas);
	}
	else if ((numero > 8) && (numero < 11))  //9 ou 10
	{
		system("cls");
		logo();
		centerText();
		printf("Voce encontrou uma Harpia.\n\n");
		pForcaHarpia = 175;
		expHarpia = 15;
		srand(time(NULL));
		moedas = rand() % 25;
		menuDeBatalha(codigoUsuario, pForcaHarpia, expHarpia, moedas);
	}
	else
	{
		system("cls");
		logo();
		centerText();
		printf("Nada foi encontrado. Continue andando. \n\n");
		Sleep(7000);
		system("cls");
		logo();
		navegacaoFloresta(codigoUsuario);
	}
}

void inimigosCaverna(char * codigoUsuario){
	int numero, pForcaMorcego, pForcaManticore, pForcaEttercap, pForcaMorcegoGigante, pForcaDragao, expMorcego, moedas, expManticore, expEttercap, expMorcegoGigante, expDragao ;
	srand(time(NULL));
	centerText();
	printf("Procurando inimigo . . .\n\n");
	Sleep(3000);
	numero = rand() % 15;
	if (numero < 3) // 1 ou 2
	{
		system("cls");
		logo();
		centerText();
		printf("Voce encontrou um Morcego.\n\n");
		pForcaMorcego = 200;
		expMorcego = 17;
		srand(time(NULL));
		moedas = rand() % 50;
		menuDeBatalha(codigoUsuario, pForcaMorcego, expMorcego, moedas);
	}
	else if ((numero > 2) && (numero < 5))  //3 ou 4
	{
		system("cls");
		logo();
		centerText();
		printf("Voce encontrou um Manticore.\n\n");
		pForcaManticore = 220;
		expManticore = 19;
		srand(time(NULL));
		moedas = rand() % 50;
		menuDeBatalha(codigoUsuario, pForcaManticore, expManticore, moedas);
	}
	else if ((numero > 4) && (numero < 7))  // 5 ou 6
	{
		system("cls");
		logo();
		centerText();
		printf("Voce encontrou um Ettercap.\n\n");
		pForcaEttercap = 240;
		expEttercap = 21;
		srand(time(NULL));
		moedas = rand() % 50;
		menuDeBatalha(codigoUsuario, pForcaEttercap, expEttercap, moedas);
	}
	else if ((numero > 6) && (numero < 9))  //7 ou 8
	{
		system("cls");
		logo();
		centerText();
		printf("Voce encontrou uma Morcego Gigante.\n\n");
		pForcaMorcegoGigante = 275;
		expMorcegoGigante = 24;
		srand(time(NULL));
		moedas = rand() % 50;
		menuDeBatalha(codigoUsuario, pForcaMorcegoGigante, expMorcegoGigante, moedas);
	}
	else if ((numero > 8) && (numero < 11))  //9 ou 10
	{
		system("cls");
		logo();
		centerText();
		printf("Voce encontrou uma Dragão.\n\n");
		pForcaDragao = 300;
		expDragao = 30;
		srand(time(NULL));
		moedas = rand() % 50;
		menuDeBatalha(codigoUsuario, pForcaDragao, expDragao, moedas);
	}
	else
	{
		system("cls");
		logo();
		centerText();
		printf("Nada foi encontrado. Continue andando.\n\n");
		Sleep(7000);
		system("cls");
		logo();
		navegacaoCaverna(codigoUsuario);
	}
}

void inimigosMontanha(char * codigoUsuario){
	int numero, pForcaOwnbear, pForcaMinotauro, pForcaEscorpiao, pForcaEscaravelho, pForcaGolem, expOwnbear, moedas, expMinotauro, expEscorpiao, expEscaravelho, expGolem;
	srand(time(NULL));
	centerText();
	printf("Procurando inimigo . . .\n\n");
	Sleep(3000);
	numero = rand() % 15;
	if (numero < 3) // 1 ou 2
	{
		system("cls");
		logo();
		centerText();
		printf("Voce encontrou um Owlbear.\n\n");
		pForcaOwnbear = 320;
		expOwnbear = 32;
		srand(time(NULL));
		moedas = rand() % 100;
		menuDeBatalha(codigoUsuario, pForcaOwnbear, expOwnbear, moedas);
	}
	else if ((numero > 2) && (numero < 5))  //3 ou 4
	{
		system("cls");
		logo();
		centerText();
		printf("Voce encontrou um Minotauro.\n\n");
		pForcaMinotauro = 340;
		expMinotauro = 34;
		srand(time(NULL));
		moedas = rand() % 100;
		menuDeBatalha(codigoUsuario, pForcaMinotauro, expMinotauro, moedas);
	}
	else if ((numero > 4) && (numero < 7))  // 5 ou 6
	{
		system("cls");
		logo();
		centerText();
		printf("Voce encontrou um Escorpião.\n\n");
		pForcaEscorpiao = 360;
		expEscorpiao = 36;
		srand(time(NULL));
		moedas = rand() % 100;
		menuDeBatalha(codigoUsuario, pForcaEscorpiao, expEscorpiao, moedas);
	}
	else if ((numero > 6) && (numero < 9))  //7 ou 8
	{
		system("cls");
		logo();
		centerText();
		printf("Voce encontrou uma Escaravelho.\n\n");
		pForcaEscaravelho = 380;
		expEscaravelho = 38;
		srand(time(NULL));
		moedas = rand() % 100;
		menuDeBatalha(codigoUsuario, pForcaEscaravelho, expEscaravelho, moedas);
	}
	else if ((numero > 8) && (numero < 11))  //9 ou 10
	{
		system("cls");
		logo();
		centerText();
		printf("Voce encontrou uma Golem.\n\n");
		pForcaGolem = 450;
		expGolem = 45;
		srand(time(NULL));
		moedas = rand() % 100;
		menuDeBatalha(codigoUsuario, pForcaGolem, expGolem, moedas);
	}
	else
	{
		system("cls");
		logo();
		centerText();
		printf("Nada foi encontrado. Continue andando. \n\n");
		Sleep(7000);
		system("cls");
		logo();
		navegacaoMontanha(codigoUsuario);
	}
}

void inimigosPantano(char * codigoUsuario){
	int numero, pForcaEsqueleto, pForcaPantera, pForcaCrocopotamo, pForcaAgrutha, pForcaEnte, expEsqueleto, expPantera, expCrocopotamo, moedas, expAgrutha, expEnte;
	srand(time(NULL));
	centerText();
	printf("Procurando inimigo . . .\n\n");
	Sleep(3000);
	numero = rand() % 15;
	if (numero < 3) // 1 ou 2
	{
		system("cls");
		logo();
		centerText();
		printf("Voce encontrou um Esqueleto.\n\n");
		pForcaEsqueleto = 500;
		expEsqueleto = 50;
		srand(time(NULL));
		moedas = rand() % 200;
		menuDeBatalha(codigoUsuario, pForcaEsqueleto, expEsqueleto, moedas);
	}
	else if ((numero > 2) && (numero < 5))  //3 ou 4
	{
		system("cls");
		logo();
		centerText();
		printf("Voce encontrou um Pantera.\n\n");
		expPantera = 52;
		pForcaPantera = 520;
		srand(time(NULL));
		moedas = rand() % 200;
		menuDeBatalha(codigoUsuario, pForcaPantera, expPantera, moedas);
	}
	else if ((numero > 4) && (numero < 7))  // 5 ou 6
	{
		system("cls");
		logo();
		centerText();
		printf("Voce encontrou um Crocopótamo.\n\n");
		pForcaCrocopotamo = 550;
		srand(time(NULL));
		moedas = rand() % 200;
		expCrocopotamo = 55;
		menuDeBatalha(codigoUsuario, pForcaCrocopotamo, expCrocopotamo, moedas);
	}
	else if ((numero > 6) && (numero < 9))  //7 ou 8
	{
		system("cls");
		logo();
		centerText();
		printf("Voce encontrou uma Agrutha.\n\n");
		pForcaAgrutha = 575;
		expAgrutha = 57;
		srand(time(NULL));
		moedas = rand() % 200;
		menuDeBatalha(codigoUsuario, pForcaAgrutha, expAgrutha, moedas);
	}
	else if ((numero > 8) && (numero < 11))  //9 ou 10
	{
		system("cls");
		logo();
		centerText();
		printf("Voce encontrou uma Ente.\n\n");
		srand(time(NULL));
		moedas = rand() % 200;
		pForcaEnte = 700;
		expEnte = 70;
		menuDeBatalha(codigoUsuario, pForcaEnte, expEnte, moedas);
	}
	else
	{
		centerText();
		printf("Nada foi encontrado. Continue andando. \n\n");
		Sleep(7000);
		system("cls");
		logo();
		navegacaoPantano(codigoUsuario);
	}
}

void inimigosMar(char * codigoUsuario){
	int numero, pForcaTubarao, pForcaMegalo, pForcaDragaoAgua, pForcaLeviata, pForcaCthulhu, expTubarao, moedas, expMegalo, expDragaoAgua, expLeviata, expCthulhu ;
	srand(time(NULL));
	centerText();
	printf("Procurando inimigo . . .\n\n");
	Sleep(3000);
	numero = rand() % 15;
	if (numero < 3)  // 1 ou 2
	{
		system("cls");
		logo();
		centerText();
		printf("Voce encontrou um Tubarão.\n\n");
		pForcaTubarao = 750;
		expTubarao = 75;
		srand(time(NULL));
		moedas = rand() % 300;
		menuDeBatalha(codigoUsuario, pForcaTubarao, expTubarao, moedas);
	}
	else if ((numero > 2) && (numero < 5))  //3 ou 4
	{
		system("cls");
		logo();
		centerText();
		printf("Voce encontrou um Baleia Megalo.\n\n");
		pForcaMegalo = 780;
		expMegalo = 78;
		srand(time(NULL));
		moedas = rand() % 300;
		menuDeBatalha(codigoUsuario, pForcaMegalo, expMegalo, moedas);
	}
	else if ((numero > 4) && (numero < 7))  // 5 ou 6
	{
		system("cls");
		logo();
		centerText();
		printf("Voce encontrou um Dragão de Água.\n\n");
		pForcaDragaoAgua = 800;
		expDragaoAgua = 80;
		srand(time(NULL));
		moedas = rand() % 300;
		menuDeBatalha(codigoUsuario, pForcaDragaoAgua, expLeviata, moedas);
	}
	else if ((numero > 6) && (numero < 9))  //7 ou 8
	{
		system("cls");
		logo();
		centerText();
		printf("Voce encontrou uma Leviatã.\n\n");
		pForcaLeviata = 900;
		expLeviata = 90;
		srand(time(NULL));
		moedas = rand() % 300;
		menuDeBatalha(codigoUsuario, pForcaLeviata, expLeviata, moedas);
	}
	else if ((numero > 8) && (numero < 11))  //9 ou 10
	{
		system("cls");
		logo();
		centerText();
		printf("Voce encontrou uma Cthulhu.\n\n");
		pForcaCthulhu = 1250;
		expCthulhu = 125;
		srand(time(NULL));
		moedas = rand() % 300;
		menuDeBatalha(codigoUsuario, pForcaCthulhu, expCthulhu, moedas);
	}
	else
	{
		system("cls");
		logo();
		centerText();
		printf("Nada foi encontrado. Continue andando. \n\n");
		Sleep(7000);
		system("cls");
		logo();
		navegacaoMar(codigoUsuario);
	}
}

void menuDeBatalha(char *codigoUsuario, int forca, int expInimigo, int moedas){
	int escolha;
	
	printf("\t\t\t\t\t\t\t\t\t################## Ele possui: %d de PODER DE ATAQUE! ################\n", forca);
	printf("\t\t\t\t\t\t\t\t\t######################################################################\n");
	printf("\t\t\t\t\t\t\t\t\t#                                                                    #\n");
	printf("\t\t\t\t\t\t\t\t\t#                       Selecione a opção desejada:                  #\n");
	printf("\t\t\t\t\t\t\t\t\t#                                                                    #\n");
	printf("\t\t\t\t\t\t\t\t\t#                            1- Lutar                                #\n");
	printf("\t\t\t\t\t\t\t\t\t#                                                                    #\n");
	printf("\t\t\t\t\t\t\t\t\t#                            0- Correr                               #\n");
	printf("\t\t\t\t\t\t\t\t\t#                                                                    #\n");
	printf("\t\t\t\t\t\t\t\t\t######################################################################");
	printf("\n\n\n\t\t\t\t\t\t\t\t\tO que você deseja fazer? ");

	scanf("%d", &escolha);

	if (escolha == 1)
	{
		printf("\n\n");
		centerText();
		printf("Voce se encontra em uma batalha . . .\n");
		Sleep(2000);
		batalha(codigoUsuario, forca, expInimigo, moedas);
	}
	else if(escolha == 0)
	{
		printf("\n\n");
		centerText();
		printf("Corri!");
		Sleep(3000);
		system("cls");
		logo();
		navegacaoFloresta(codigoUsuario);
	}
	else
	{
		printf("Opcao Invalida");
	}
}

void curandeira(char * codigoUsuario){
	setlocale(LC_ALL, "Portuguese");
	int escolha;

	printf("\t\t\t\t\t\t\t\t\t   ____ _   _ ____     _    _   _ ____  _____ ___ ____     _    \n");
	printf("\t\t\t\t\t\t\t\t\t  / ___| | | |  _ \\   / \\  | \\ | |  _ \\| ____|_ _|  _ \\   / \\   \n");
	printf("\t\t\t\t\t\t\t\t\t | |   | | | | |_) | / _ \\ |  \\| | | | |  _|  | || |_) | / _ \\  \n");
	printf("\t\t\t\t\t\t\t\t\t | |___| |_| |  _ < / ___ \\| |\\  | |_| | |___ | ||  _ < / ___ \\ \n");
	printf("\t\t\t\t\t\t\t\t\t  \\____|\\___/|_| \\_/_/   \\_|_| \\_|____/|_____|___|_| \\_/_/   \\_\\\n");
	printf("\n\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t            .----.\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t           ===(_)==   PROMETO QUE NAO VAI DOER...\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t          // 6  6 \\\\  /\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t          (    7   )\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t           \\ '--' /\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t            \\_ ._/\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t          __)  (__\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t       /""¨/¨\\¨V/¨\\¨\\\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t       /   \\  `Y _/_ \\\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t      / [DR]\\_ |/ / /\\\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t      |     ( \\/ / / /\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t       \\  \\  \\      /\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t        \\  `-/`  _.`\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t         `=. `=./\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t            ""\n");
	printf("\n\n");
	printf("\t\t\t\t\t\t\t\t\t######################################################################\n");
	printf("\t\t\t\t\t\t\t\t\t#                                                                    #\n");
	printf("\t\t\t\t\t\t\t\t\t#                       Selecione a opção desejada:                  #\n");
	printf("\t\t\t\t\t\t\t\t\t#                                                                    #\n");
	printf("\t\t\t\t\t\t\t\t\t#                            1- Buff (100 moedas)                    #\n");
	printf("\t\t\t\t\t\t\t\t\t#                                                                    #\n");
	printf("\t\t\t\t\t\t\t\t\t#                                  ( +5 Forca )                      #\n");
	printf("\t\t\t\t\t\t\t\t\t#                                  ( +5 Destreza )                   #\n");
	printf("\t\t\t\t\t\t\t\t\t#                                  ( +5 Sorte )                      #\n");
	printf("\t\t\t\t\t\t\t\t\t#                                  ( +5 Inteligencia )               #\n");
	printf("\t\t\t\t\t\t\t\t\t#                                                                    #\n");
	printf("\t\t\t\t\t\t\t\t\t#                            0- Sair                                 #\n");
	printf("\t\t\t\t\t\t\t\t\t#                                                                    #\n");
	printf("\t\t\t\t\t\t\t\t\t######################################################################\n");
	printf("\t\t\t\t\t\t\t\t\tO que você deseja fazer? ");
	scanf("%d", &escolha);
	
	if (escolha == 1){
		buffarCurandeira(codigoUsuario);
		Sleep(3000);
		system("cls");
		logo();
		menuInicial(codigoUsuario);
	}
	else{
		system("cls");
		logo();
		menuInicial(codigoUsuario);
	}
}

void alquimista(char * codigoUsuario){
	setlocale(LC_ALL, "Portuguese");
	int escolha;

	printf("\t\t\t\t\t\t\t\t\t                                Puxa,Puxa\n");
	printf("\t\t\t\t\t\t\t\t\t                                 Quem não quiser feitiço\n");
	printf("\t\t\t\t\t\t\t\t\t               (       ""     )   mesmo que seja sem compromisso\n");
	printf("\t\t\t\t\t\t\t\t\t                ( _  *              vai levar um chá de sumiço.\n");
	printf("\t\t\t\t\t\t\t\t\t                   * (     /      \\    ___\n");
	printf("\t\t\t\t\t\t\t\t\t                      "     "        _/ /\n");
	printf("\t\t\t\t\t\t\t\t\t                     (   *  )    ___/   |\n");
	printf("\t\t\t\t\t\t\t\t\t                       )   ""     _ o)'-./__\n");
	printf("\t\t\t\t\t\t\t\t\t                      *  _ )    (_, . $$$\n");
	printf("\t\t\t\t\t\t\t\t\t                      (  )   __ __ 7_ $$$$\n");
	printf("\t\t\t\t\t\t\t\t\t                       ( :  { _)  '---  $\\\n");
	printf("\t\t\t\t\t\t\t\t\t                  ______'___//__\\   ____, \\\n");
	printf("\t\t\t\t\t\t\t\t\t                   )           ( \\_/ _____\\_\n");
	printf("\t\t\t\t\t\t\t\t\t                 .'             \\   \\------''.\n");
	printf("\t\t\t\t\t\t\t\t\t                |='           '=|  |         )\n");
	printf("\t\t\t\t\t\t\t\t\t                |               |  |  .    _/\n");
	printf("\t\t\t\t\t\t\t\t\t                 \\    (. ) ,   /  /__I_____\\\n");
	printf("\t\t\t\t\t\t\t\t\t                   '._/_)_(\\__.'   (__,(__,_]\n");
	printf("\t\t\t\t\t\t\t\t\t                  @---()_.'---@\n");
	printf("\n\n");
	printf("\t\t\t\t\t\t\t\t\t######################################################################\n");
	printf("\t\t\t\t\t\t\t\t\t#                                                                    #\n");
	printf("\t\t\t\t\t\t\t\t\t#                       Selecione a opção desejada:                  #\n");
	printf("\t\t\t\t\t\t\t\t\t#                                                                    #\n");
	printf("\t\t\t\t\t\t\t\t\t#                            1- Buff (200 moedas)                    #\n");
	printf("\t\t\t\t\t\t\t\t\t#                                                                    #\n");
	printf("\t\t\t\t\t\t\t\t\t#                                  ( +15 Forca )                     #\n");
	printf("\t\t\t\t\t\t\t\t\t#                                  ( +15 Destreza )                  #\n");
	printf("\t\t\t\t\t\t\t\t\t#                                  ( +15 Sorte )                     #\n");
	printf("\t\t\t\t\t\t\t\t\t#                                  ( +15 Inteligencia )              #\n");
	printf("\t\t\t\t\t\t\t\t\t#                                                                    #\n");
	printf("\t\t\t\t\t\t\t\t\t#                            0- Sair                                 #\n");
	printf("\t\t\t\t\t\t\t\t\t#                                                                    #\n");
	printf("\t\t\t\t\t\t\t\t\t######################################################################\n");
	printf("\t\t\t\t\t\t\t\t\tO que você deseja fazer? ");
	scanf("%d", &escolha);
	
	if (escolha == 1){
		buffarAlquimista(codigoUsuario);
		Sleep(3000);
		system("cls");
		logo();
		menuInicial(codigoUsuario);
	}
	else{
		system("cls");
		logo();
		menuInicial(codigoUsuario);
	}
}

void estabulo(char * codigoUsuario){
	int escolha;
	setlocale(LC_ALL, "Portuguese");
	
	printf("\t\t\t .----------------.  .----------------.  .----------------.  .----------------.  .----------------.  .----------------.  .----------------.  .----------------. \n");
	printf("\t\t\t| .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. |\n");
	printf("\t\t\t| |  _________   | || |    _______   | || |  _________   | || |      __      | || |   ______     | || | _____  _____ | || |   _____      | || |     ____     | |\n");
	printf("\t\t\t| | |_   ___  |  | || |   /  ___  |  | || | |  _   _  |  | || |     /  \\     | || |  |_   _ \\    | || ||_   _||_   _|| || |  |_   _|     | || |   .'    `.   | |\n");
	printf("\t\t\t| |   | |_  \\_|  | || |  |  (__ \\_|  | || | |_/ | | \\_|  | || |    / /\\ \\    | || |    | |_) |   | || |  | |    | |  | || |    | |       | || |  /  .--.  \\  | |\n");
	printf("\t\t\t| |   |  _|  _   | || |   '.___`-.   | || |     | |      | || |   / ____ \\   | || |    |  __'.   | || |  | '    ' |  | || |    | |   _   | || |  | |    | |  | |\n");
	printf("\t\t\t| |  _| |___/ |  | || |  |`\\____) |  | || |    _| |_     | || | _/ /    \\ \\_ | || |   _| |__) |  | || |   \\ `--' /   | || |   _| |__/ |  | || |  \\  `--'  /  | |\n");
	printf("\t\t\t| | |_________|  | || |  |_______.'  | || |   |_____|    | || ||____|  |____|| || |  |_______/   | || |    `.__.'    | || |  |________|  | || |   `.____.'   | |\n");
	printf("\t\t\t| |              | || |              | || |              | || |              | || |              | || |              | || |              | || |              | |\n");
	printf("\t\t\t| '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' |\n");
	printf("\t\t\t '----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------' \n");
	printf("\t\t\t\t\t\t\t\t\t                                 +&-\n");
	printf("\t\t\t\t\t\t\t\t\t                                _.-^-._    .--.\n");
	printf("\t\t\t\t\t\t\t\t\t                             .-'   _   '-. |__|\n");
	printf("\t\t\t\t\t\t\t\t\t                            /     |_|     \\|  |\n");
	printf("\t\t\t\t\t\t\t\t\t                           /               \\  |\n");
	printf("\t\t\t\t\t\t\t\t\t                          /|     _____     |\\ |\n");
	printf("\t\t\t\t\t\t\t\t\t                           |    |==|==|    |  |\n");
	printf("\t\t\t\t\t\t\t\t\t       |---|---|---|---|---|    |--|--|    |  |\n");
	printf("\t\t\t\t\t\t\t\t\t       |---|---|---|---|---|    |==|==|    |  |\n");
	printf("\t\t\t\t\t\t\t\t\t      ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");	
	
	printf("\n\n\t\t\t\t\t\t\t\t\t######################################################################\n");
	printf("\t\t\t\t\t\t\t\t\t#                                                                    #\n");
	printf("\t\t\t\t\t\t\t\t\t#                       Selecione a opção desejada:                  #\n");
	printf("\t\t\t\t\t\t\t\t\t#                                                                    #\n");
	printf("\t\t\t\t\t\t\t\t\t#                      1- Transceder Montaria (500 Moedas)           #\n");
	printf("\t\t\t\t\t\t\t\t\t#                                                                    #\n");
	printf("\t\t\t\t\t\t\t\t\t#                                  ( +40 Forca )                     #\n");
	printf("\t\t\t\t\t\t\t\t\t#                                  ( +40 Destreza )                  #\n");
	printf("\t\t\t\t\t\t\t\t\t#                                  ( +40 Sorte )                     #\n");
	printf("\t\t\t\t\t\t\t\t\t#                                  ( +40 Inteligencia )              #\n");
	printf("\t\t\t\t\t\t\t\t\t#                                                                    #\n");
	printf("\t\t\t\t\t\t\t\t\t#                      0- Retornar a cidade                          #\n");
	printf("\t\t\t\t\t\t\t\t\t#                                                                    #\n");
	printf("\t\t\t\t\t\t\t\t\t######################################################################");
	printf("\n\n\n\t\t\t\t\t\t\t\t\tO que você deseja fazer? ");
	scanf("%d", &escolha);
	
	if (escolha == 1){
		transcederMontaria(codigoUsuario);
		Sleep(3000);
		system("cls");
		logo();
		menuInicial(codigoUsuario);
	}
	else{
		system("cls");
		logo();
		menuInicial(codigoUsuario);
	}
}

void petMaster(char * codigoUsuario){
	int escolha;
	setlocale(LC_ALL, "Portuguese");
		
	printf("\t\t\t\t\t\t\t\t\t\t  ____      _   __  __           _            \n");
	printf("\t\t\t\t\t\t\t\t\t\t |  _ \\ ___| |_|  \\/  | __ _ ___| |_ ___ _ __ \n");
	printf("\t\t\t\t\t\t\t\t\t\t | |_) / _ \\ __| |\\/| |/ _` / __| __/ _ \\ '__|\n");
	printf("\t\t\t\t\t\t\t\t\t\t |  __/  __/ |_| |  | | (_| \\__ \\ ||  __/ |   \n");
	printf("\t\t\t\t\t\t\t\t\t\t |_|   \\___|\\__|_|  |_|\\__,_|___/\\__\\___|_|   \n");
	
	
	printf("\n\n\t\t\t\t\t\t\t\t\t######################################################################\n");
	printf("\t\t\t\t\t\t\t\t\t#                                                                    #\n");
	printf("\t\t\t\t\t\t\t\t\t#                       Selecione a opção desejada:                  #\n");
	printf("\t\t\t\t\t\t\t\t\t#                                                                    #\n");
	printf("\t\t\t\t\t\t\t\t\t#                            1- Transceder Pet (300 moedas)          #\n");
	printf("\t\t\t\t\t\t\t\t\t#                                                                    #\n");
	printf("\t\t\t\t\t\t\t\t\t#                                  ( +25 Forca )                     #\n");
	printf("\t\t\t\t\t\t\t\t\t#                                  ( +25 Destreza )                  #\n");
	printf("\t\t\t\t\t\t\t\t\t#                                  ( +25 Sorte )                     #\n");
	printf("\t\t\t\t\t\t\t\t\t#                                  ( +25 Inteligencia )              #\n");
	printf("\t\t\t\t\t\t\t\t\t#                                                                    #\n");
	printf("\t\t\t\t\t\t\t\t\t#                            0- Retornar a cidade                    #\n");
	printf("\t\t\t\t\t\t\t\t\t#                                                                    #\n");
	printf("\t\t\t\t\t\t\t\t\t######################################################################");
	printf("\n\n\n\t\t\t\t\t\t\t\t\tO que você deseja fazer? ");                                             
	scanf("%d", &escolha);
	
	if (escolha == 1){
		transcederPet(codigoUsuario);
		Sleep(3000);
		system("cls");
		logo();
		menuInicial(codigoUsuario);
	}
	else{
		system("cls");
		logo();
		menuInicial(codigoUsuario);
	}
}

void escolherClasse(char * codigoUsuario){
	int escolha;

	printf("\t\t\t\t\t\t\t\t\t######################################################################\n");
	printf("\t\t\t\t\t\t\t\t\t#                                                                    #\n");
	printf("\t\t\t\t\t\t\t\t\t#                       Escolha a sua classe:                        #\n");
	printf("\t\t\t\t\t\t\t\t\t#                                                                    #\n");
	printf("\t\t\t\t\t\t\t\t\t#                            1- Guerreiro (+ Forca)                  #\n");
	printf("\t\t\t\t\t\t\t\t\t#                                                                    #\n");
	printf("\t\t\t\t\t\t\t\t\t#                            2- Arqueiro (+ Destreza)                #\n");
	printf("\t\t\t\t\t\t\t\t\t#                                                                    #\n");
	printf("\t\t\t\t\t\t\t\t\t#                            3- Mago (+ Inteligencia)                #\n");
	printf("\t\t\t\t\t\t\t\t\t#                                                                    #\n");
	printf("\t\t\t\t\t\t\t\t\t######################################################################\n\n");
	printf("\t\t\t\t\t\t\t\t\tEscolha qual sua classe: ");
	scanf("%d", &escolha);
	
	switch(escolha)
	{
	case 1:
		guerreiro();
		Sleep(7000);
		system("cls");
		logo();
		buffalo();
		tigre();
		serGuerreiro(codigoUsuario);
		Sleep(7000);
		system("cls");
		logo();
		menuInicial(codigoUsuario);
		break;
	case 2:
		arqueiro();
		Sleep(7000);
		system("cls");
		logo();
		cavalo();
		vibora();	
		serArqueiro(codigoUsuario);
		Sleep(7000);
		system("cls");
		logo();
		menuInicial(codigoUsuario);
		break;
	case 3:
		mago();
		Sleep(7000);
		system("cls");
		logo();
		dragao();
		aguia();
		serMago(codigoUsuario);
		Sleep(7000);
		system("cls");
		logo();
		menuInicial(codigoUsuario);
		break;
	default:
		centerText();
		printf("Opção inválida!\n\n");
		break;
	}
}

// Tela de pets

void tigre(){
	setlocale(LC_ALL, "Portuguese");
	printf("\t\t\t\t\t\t\t\t\t###########################################################################\n");
    printf("\t\t\t\t\t\t\t\t\t#                                                                         #\n");  
    printf("\t\t\t\t\t\t\t\t\t#                       Seu Pet é a tigresa do Kung Fu Panda              #\n");  
    printf("\t\t\t\t\t\t\t\t\t#                                                                         #\n");  
    printf("\t\t\t\t\t\t\t\t\t###########################################################################\n");
	printf("\t\t\t\t\t\t\t\t\t\t   _\n");
	printf("\t\t\t\t\t\t\t\t\t\t  ( \                ..-----..__\n");
	printf("\t\t\t\t\t\t\t\t\t\t   \\.'.        _.--'`  [   '  ' ```'-._\n");
 	printf("\t\t\t\t\t\t\t\t\t\t   `. `'-..-'' `    '  ' '   .  ;   ; `-'''-.,__/|/_\n");
 	printf("\t\t\t\t\t\t\t\t\t\t     `'-.;..-''`|'  `.  '.    ;     '  `    '   `'  `,\n");
 	printf("\t\t\t\t\t\t\t\t\t\t                \\ '   .    ' .     '   ;   .`   . ' 7 \\\n");
 	printf("\t\t\t\t\t\t\t\t\t\t                 '.' . '- . \\    .`   .`  .   .\\     `Y\n");
 	printf("\t\t\t\t\t\t\t\t\t\t                    '-.' .   ].  '   ,    '    /'`""';:'\n");
   	printf("\t\t\t\t\t\t\t\t\t\t                   /Y   '.] '-._ /    ' _.-'\n");
 	printf("\t\t\t\t\t\t\t\t\t\t                  \\'\\_   ; (`'.'.'  .""/\n");
 	printf("\t\t\t\t\t\t\t\t\t\t                   ' )` /  `.'   .-'.'\n");
 	printf("\t\t\t\t\t\t\t\t\t\t                 '\\  \\).'  .-'--""\n");
  	printf("\t\t\t\t\t\t\t\t\t\t                  `. `,_'`\n");
  	printf("\t\t\t\t\t\t\t\t\t\t                    `.__)  \n");
}

void vibora(){
	setlocale(LC_ALL, "Portuguese");
	printf("\t\t\t\t\t\t\t\t\t###########################################################################\n");
    printf("\t\t\t\t\t\t\t\t\t#                                                                         #\n");  
    printf("\t\t\t\t\t\t\t\t\t#                        Seu Pet é a víbora do Kung Fu Panda              #\n");  
    printf("\t\t\t\t\t\t\t\t\t#                                                                         #\n");  
    printf("\t\t\t\t\t\t\t\t\t###########################################################################\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t                         .-=-.          .--.\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t               __        .'     '.       /  "" )\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t       _     .'  '.     /   .-.   \\     /  .-'\\\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t      ( \\   / .-.  \\   /   /   \\   \\   /  /    ^\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t       \\ `-` /   \\  `-'   /     \\   `-`  /\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t        `-.-`     '.____.'       `.____.'\n");
}

void aguia(){
	setlocale(LC_ALL, "Portuguese");
	printf("\t\t\t\t\t\t\t\t\t###########################################################################\n");
    printf("\t\t\t\t\t\t\t\t\t#                                                                         #\n");  
    printf("\t\t\t\t\t\t\t\t\t#                              Seu Pet é uma águia                        #\n");  
    printf("\t\t\t\t\t\t\t\t\t#                                                                         #\n");  
    printf("\t\t\t\t\t\t\t\t\t###########################################################################\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t ///,        ////\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t \\  /,      /  >.\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t  \\  /,   _/  /.\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t   \\_  /_/   /.\n");
 	printf("\t\t\t\t\t\t\t\t\t\t\t\t   \\__/_   <    \n");
 	printf("\t\t\t\t\t\t\t\t\t\t\t\t   /<<< \\_\\_ \n");
  	printf("\t\t\t\t\t\t\t\t\t\t\t\t /,)^>>_._ \\\n");
  	printf("\t\t\t\t\t\t\t\t\t\t\t\t (/   \\\ /\"\\\n");
  	printf("\t\t\t\t\t\t\t\t\t\t\t\t      // ````\n");
 	printf("\t\t\t\t\t\t\t\t\t\t\t\t======((`=======\n");
}

// Tela de montarias

void buffalo(){
	setlocale(LC_ALL, "Portuguese");
	printf("\t\t\t\t\t\t\t\t\t###########################################################################\n");
    printf("\t\t\t\t\t\t\t\t\t#                                                                         #\n");  
    printf("\t\t\t\t\t\t\t\t\t#                          Sua montaria é o Appa do Aang.                 #\n");  
    printf("\t\t\t\t\t\t\t\t\t#                                                                         #\n");  
    printf("\t\t\t\t\t\t\t\t\t###########################################################################\n");
	printf("\t\t\t\t\t\t\t\t\t                                   _.-````'-,_\n");
	printf("\t\t\t\t\t\t\t\t\t                         _,.,_ ,-'`           `'-.,_\n");
	printf("\t\t\t\t\t\t\t\t\t                       /)     (\\                   '``-.\n");
	printf("\t\t\t\t\t\t\t\t\t                     ((      ) )                      `\\\n");
	printf("\t\t\t\t\t\t\t\t\t                       \\)    (_/                        )\\\n");
	printf("\t\t\t\t\t\t\t\t\t                        |       /)           '    ,'    / \\\n");
	printf("\t\t\t\t\t\t\t\t\t                        `\\    ^'            '     (    /  ))\n");
	printf("\t\t\t\t\t\t\t\t\t                          |      _/\\ ,     /    ,,`\\   (  ""`\n");
	printf("\t\t\t\t\t\t\t\t\t                           \\Y,   |  \\  \\  | ````| / \\_ \\\n");
	printf("\t\t\t\t\t\t\t\t\t                             `)_/    \\  \\  )    ( >  ( >\n");
	printf("\t\t\t\t\t\t\t\t\t                                     \\( \\(     |/   |/\n");
	printf("\t\t\t\t\t\t\t\t\t                                     /_(/_(    /_(  /_(	\n");
}

void cavalo(){
	setlocale(LC_ALL, "Portuguese");
	printf("\t\t\t\t\t\t\t\t\t###########################################################################\n");
    printf("\t\t\t\t\t\t\t\t\t#                                                                         #\n");  
    printf("\t\t\t\t\t\t\t\t\t#                          Sua montaria é o Pé-de-pano                    #\n");  
    printf("\t\t\t\t\t\t\t\t\t#                                                                         #\n");  
    printf("\t\t\t\t\t\t\t\t\t###########################################################################\n");
	printf("\t\t\t\t\t\t\t\t\t ,\n");
	printf("\t\t\t\t\t\t\t\t\t_,,)\.~,,._\n");
	printf("\t\t\t\t\t\t\t\t\t(()`  ``)\\))),,_\n");
	printf("\t\t\t\t\t\t\t\t\t |     \\ ''((\\)))),,_          ____\n");
	printf("\t\t\t\t\t\t\t\t\t |6`   |   ''((\\())) ""-.____.-"    "-.-,\n");
	printf("\t\t\t\t\t\t\t\t\t |    .'\\    ''))))'                  \\)))\n");
	printf("\t\t\t\t\t\t\t\t\t |   |   `.     ''                     ((((\n");
	printf("\t\t\t\t\t\t\t\t\t \\, _)     \\/                          |))))\n");
	printf("\t\t\t\t\t\t\t\t\t  `'        |                          (((((\n");
	printf("\t\t\t\t\t\t\t\t\t            \\                  |       ))))))\n");
	printf("\t\t\t\t\t\t\t\t\t             `|    |           ,\\     /((((((\n");
	printf("\t\t\t\t\t\t\t\t\t              |   / `-.______.<  \\   |  )))))\n");
	printf("\t\t\t\t\t\t\t\t\t              |   |  /         `. \\  \\  ((((\n");
	printf("\t\t\t\t\t\t\t\t\t              |  / \\ |           `.\\  | (((\n");
	printf("\t\t\t\t\t\t\t\t\t              \\  | | |             )| |  ))\n");
	printf("\t\t\t\t\t\t\t\t\t              | | | |            / | |  '\n");
	printf("\t\t\t\t\t\t\t\t\t              | | /_(           /_(/ /\n");
	printf("\t\t\t\t\t\t\t\t\t              /_(/__]           \\_/_(\n");
	printf("\t\t\t\t\t\t\t\t\t              /__]                /__]\n");
}

void dragao(){
	setlocale(LC_ALL, "Portuguese");
	printf("\t\t\t\t\t\t\t\t\t###########################################################################\n");
    printf("\t\t\t\t\t\t\t\t\t#                                                                         #\n");  
    printf("\t\t\t\t\t\t\t\t\t#                      Sua montaria é um Dragão bem top.                  #\n");  
    printf("\t\t\t\t\t\t\t\t\t#                                                                         #\n");  
    printf("\t\t\t\t\t\t\t\t\t###########################################################################\n");
	printf("\t\t\t\t\t\t\t\t\t                ,'\\   |\\\n");
	printf("\t\t\t\t\t\t\t\t\t              / /.:  ;;\n");
	printf("\t\t\t\t\t\t\t\t\t              / :'|| //\n");
	printf("\t\t\t\t\t\t\t\t\t            (| | ||;'\n");
	printf("\t\t\t\t\t\t\t\t\t             / ||,;'-.._\n");
	printf("\t\t\t\t\t\t\t\t\t            : ,;,`';:.--`\n");
	printf("\t\t\t\t\t\t\t\t\t            |:|'`-(\ \ \n");
	printf("\t\t\t\t\t\t\t\t\t            ::: \\-'\\`'\n");
	printf("\t\t\t\t\t\t\t\t\t             \\\ \\,-`.\n");
	printf("\t\t\t\t\t\t\t\t\t              `'\\ `.,-`-._      ,-._\n");
	printf("\t\t\t\t\t\t\t\t\t       ,-.       \\  `.,-' `-.  / ,..`.\n");
	printf("\t\t\t\t\t\t\t\t\t      / ,.`.      `.  \\ _.-' \\',: ``\\ \\\n");
	printf("\t\t\t\t\t\t\t\t\t     / / :..`-'''``-)  `.   _.:''  ''\\ \\\n");
	printf("\t\t\t\t\t\t\t\t\t    : :  '' `-..''`/    |-''  |''  '' \\ \\\n");
	printf("\t\t\t\t\t\t\t\t\t    | |  ''   ''  :     |__..-;''  ''  : :\n");
	printf("\t\t\t\t\t\t\t\t\t    | |  ''   ''  |     ;    / ''  ''  | |\n");
	printf("\t\t\t\t\t\t\t\t\t    | |  ''   ''  ;    /--../_ ''_ '' _| |\n");
	printf("\t\t\t\t\t\t\t\t\t    | |  ''  _;:_/    :._  /-.'',-.'',-. |\n");
	printf("\t\t\t\t\t\t\t\t\t    : :  '',;'`;/     |_ ,(   `'   `'   \\|\n");
	printf("\t\t\t\t\t\t\t\t\t     \\ \\  \\(   /\\     :,'  \\\n");
	printf("\t\t\t\t\t\t\t\t\t      \\ \\.'/  : /    ,)    /\n");
	printf("\t\t\t\t\t\t\t\t\t       \\ ':   ':    / \\   :\n");
	printf("\t\t\t\t\t\t\t\t\t        `.\\   :   :\\  \\  |\n");
	printf("\t\t\t\t\t\t\t\t\t                \\  | `. \\ |..-_\n");
	printf("\t\t\t\t\t\t\t\t\t                 ) |.  `/___-.-`\n");
	printf("\t\t\t\t\t\t\t\t\t               ,'  -.'.  `. `'        _,)\n");
	printf("\t\t\t\t\t\t\t\t\t               \\'\\(`.\\ `._ `-..___..-','\n");
	printf("\t\t\t\t\t\t\t\t\t                  `'      ``-..___..-'\n");
}

// Tela de classes
void guerreiro(){
	setlocale(LC_ALL, "Portuguese");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t       _\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t       (_)\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t       |=|\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t       |=|\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t   /|__|_|__|\\\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t  (    ( )    )\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t   \|\\/\\\"/\\/|/\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t     |  Y  |\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t     |  |  |\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t     |  |  |\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t    _|  |  |\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t __/ |  |  |\\\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t/  \\ |  |  |  \\\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t   __|  |  |   |\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t/\\/  |  |  |   |\\\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t <   +\\ |  |\\ />  \\\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t  >   + \\  | LJ    |\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t        + \\|+  \\  < \\\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t  (O)      +    |    )\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t  |             \\  /\\ \n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t( | )   (o)      \\/  )\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t_\\\\|//__( | )______)_/ \n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t        \\\\|//        \n");
	printf("\t\t\t\t\t\t\t\t\t###########################################################################\n");
	printf("\t\t\t\t\t\t\t\t\t#                                                                         #\n");
	printf("\t\t\t\t\t\t\t\t\t#    Voce escolheu a classe Guerreiro, esta é uma classe muito poderosa.  #\n");                  
	printf("\t\t\t\t\t\t\t\t\t#    Para esta classe é recomendado evoluir os seguintes atributos:       #\n");                                                        
	printf("\t\t\t\t\t\t\t\t\t#                                                                         #\n");
	printf("\t\t\t\t\t\t\t\t\t#                                                                         #\n");
	printf("\t\t\t\t\t\t\t\t\t#                    * Força (aumentará HP e dano)                        #\n");
	printf("\t\t\t\t\t\t\t\t\t#                                                                         #\n");
	printf("\t\t\t\t\t\t\t\t\t#                    * Sorte (aumenta chance de crítico)                  #\n");
	printf("\t\t\t\t\t\t\t\t\t#                                                                         #\n");
	printf("\t\t\t\t\t\t\t\t\t###########################################################################\n");

}

void arqueiro(){
	setlocale(LC_ALL, "Portuguese");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t            4$$-.  \n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t            4   "". \n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t            4    ^. \n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t            4     $  \n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t            4     'b \n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t            4      ""b.\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t            4        $ \n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t            4        $r \n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t            4        $F  \n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t -$b========4========$b====*P=- \n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t            4       *$$F  \n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t            4        $$""  \n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t            4       .$F    \n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t            4       dP     \n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t            4      F       \n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t            4     @         \n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t            4    .          \n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t            J.               \n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t           '$$       \n");
	printf("\t\t\t\t\t\t\t\t\t###########################################################################\n");
	printf("\t\t\t\t\t\t\t\t\t#                                                                         #\n");
	printf("\t\t\t\t\t\t\t\t\t#    Voce escolheu a classe Arqueiro, esta é uma classe muito poderosa.   #\n");                  
	printf("\t\t\t\t\t\t\t\t\t#    Para esta classe é recomendado evoluir os seguintes atributos:       #\n");                                                        
	printf("\t\t\t\t\t\t\t\t\t#                                                                         #\n");
	printf("\t\t\t\t\t\t\t\t\t#                                                                         #\n");
	printf("\t\t\t\t\t\t\t\t\t#                    * Destreza (aumentará dano e chance de acerto)       #\n");
	printf("\t\t\t\t\t\t\t\t\t#                                                                         #\n");
	printf("\t\t\t\t\t\t\t\t\t#                    * Sorte (aumenta chance de crítico)                  #\n");
	printf("\t\t\t\t\t\t\t\t\t#                                                                         #\n");
	printf("\t\t\t\t\t\t\t\t\t###########################################################################\n");
}

void mago(){
	setlocale(LC_ALL, "Portuguese");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t              *\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t       *   *\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t      *    \\* / *\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t        * --.:. *\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t       *   * :\\ -\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t         .*  | \\\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t        * *     \\\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t      .  *       \\\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t       ..        /\\.\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t      *          |\\)|\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t    .   *         \\ |\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t   . . *           |/\\\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t      .* *         /  \\\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t    *              \\ / \\\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t  *  .  *           \\   \\\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t     * .  \n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t   *    *    \n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t   .   *    *  \n");
    printf("\t\t\t\t\t\t\t\t\t###########################################################################\n");
	printf("\t\t\t\t\t\t\t\t\t#                                                                         #\n");
	printf("\t\t\t\t\t\t\t\t\t#    Voce escolheu a classe Mago, esta é uma classe muito poderosa.       #\n");                  
	printf("\t\t\t\t\t\t\t\t\t#    Para esta classe é recomendado evoluir os seguintes atributos:       #\n");                                                        
	printf("\t\t\t\t\t\t\t\t\t#                                                                         #\n");
	printf("\t\t\t\t\t\t\t\t\t#                                                                         #\n");
	printf("\t\t\t\t\t\t\t\t\t#                    * Inteligência (aumentará dano e nota em cálculo)    #\n");
	printf("\t\t\t\t\t\t\t\t\t#                                                                         #\n");
	printf("\t\t\t\t\t\t\t\t\t#                    * Sorte (aumenta chance de crítico)                  #\n");
	printf("\t\t\t\t\t\t\t\t\t#                                                                         #\n");
	printf("\t\t\t\t\t\t\t\t\t###########################################################################\n");

}

// Mensagens de batalha
void vitoriaBatalha(int exp, int moedas){
	setlocale(LC_ALL, "Portuguese");
	
	printf("\t\t\t\t\t\t\t\t\t __      __                         __       __                      __  \n");     
	printf("\t\t\t\t\t\t\t\t\t/  \\    /  |                       /  |  _  /  |                    /  |   \n");   
	printf("\t\t\t\t\t\t\t\t\t$$  \\  /$$/______   __    __       $$ | / \\ $$ |  ______   _______  $$ |   \n");   
	printf("\t\t\t\t\t\t\t\t\t $$  \\/$$//      \\ /  |  /  |      $$ |/$  \\$$ | /      \\ /       \\ $$ |   \n");   
	printf("\t\t\t\t\t\t\t\t\t  $$  $$//$$$$$$  |$$ |  $$ |      $$ /$$$  $$ |/$$$$$$  |$$$$$$$  |$$ |   \n");   
	printf("\t\t\t\t\t\t\t\t\t   $$$$/ $$ |  $$ |$$ |  $$ |      $$ $$/$$ $$ |$$ |  $$ |$$ |  $$ |$$/    \n");   
	printf("\t\t\t\t\t\t\t\t\t    $$ | $$ \\__$$ |$$ \\__$$ |      $$$$/  $$$$ |$$ \\__$$ |$$ |  $$ | __     \n");  
	printf("\t\t\t\t\t\t\t\t\t    $$ | $$    $$/ $$    $$/       $$$/    $$$ |$$    $$/ $$ |  $$ |/  |    \n");  
	printf("\t\t\t\t\t\t\t\t\t    $$/   $$$$$$/   $$$$$$/        $$/      $$/  $$$$$$/  $$/   $$/ $$/     \n\n"); Sleep(2000);
	printf("\t\t\t\t\t\t\t\t\t###########################################################################\n");
	printf("\t\t\t\t\t\t\t\t\t#                                                                         #\n");  
	printf("\t\t\t\t\t\t\t\t\t#                   O vencedor fica com os espólios!                      #\n");  
	printf("\t\t\t\t\t\t\t\t\t#                                                                         #\n");  
	printf("\t\t\t\t\t\t\t\t\t#                Você Recebeu: %d pontos de Experiência                   #\n", exp);                                                              
	printf("\t\t\t\t\t\t\t\t\t#                                                                         #\n");  
	printf("\t\t\t\t\t\t\t\t\t#                Você Recebeu: %d moedas                                  #\n", moedas);  
	printf("\t\t\t\t\t\t\t\t\t#                                                                         #\n");  
	printf("\t\t\t\t\t\t\t\t\t#                                                                         #\n");  
	printf("\t\t\t\t\t\t\t\t\t###########################################################################\n\n");
	centerText();
	system("pause");
	system("cls");
}

void levelUp(){
	
	
setlocale(LC_ALL, "Portuguese");                                                                                                                                                                     
                                                                                                                                                                     
	printf("\t\t\t\t\tLLLLLLLLLLL             EEEEEEEEEEEEEEEEEEEEEEVVVVVVVV           VVVVVVVVEEEEEEEEEEEEEEEEEEEEEELLLLLLLLLLL                  UUUUUUUU     UUUUUUUUPPPPPPPPPPPPPPPPP   \n");
	printf("\t\t\t\t\tL:::::::::L             E::::::::::::::::::::EV::::::V           V::::::VE::::::::::::::::::::EL:::::::::L                  U::::::U     U::::::UP::::::::::::::::P  \n");
	printf("\t\t\t\t\tL:::::::::L             E::::::::::::::::::::EV::::::V           V::::::VE::::::::::::::::::::EL:::::::::L                  U::::::U     U::::::UP::::::PPPPPP:::::P \n");
	printf("\t\t\t\t\tLL:::::::LL             EE::::::EEEEEEEEE::::EV::::::V           V::::::VEE::::::EEEEEEEEE::::ELL:::::::LL                  UU:::::U     U:::::UUPP:::::P     P:::::P\n");
	printf("\t\t\t\t\t  L:::::L                 E:::::E       EEEEEE V:::::V           V:::::V   E:::::E       EEEEEE  L:::::L                     U:::::U     U:::::U   P::::P     P:::::P\n");
	printf("\t\t\t\t\t  L:::::L                 E:::::E               V:::::V         V:::::V    E:::::E               L:::::L                     U:::::D     D:::::U   P::::P     P:::::P\n");
	printf("\t\t\t\t\t  L:::::L                 E::::::EEEEEEEEEE      V:::::V       V:::::V     E::::::EEEEEEEEEE     L:::::L                     U:::::D     D:::::U   P::::PPPPPP:::::P \n");
	printf("\t\t\t\t\t  L:::::L                 E:::::::::::::::E       V:::::V     V:::::V      E:::::::::::::::E     L:::::L                     U:::::D     D:::::U   P:::::::::::::PP  \n");
	printf("\t\t\t\t\t  L:::::L                 E:::::::::::::::E        V:::::V   V:::::V       E:::::::::::::::E     L:::::L                     U:::::D     D:::::U   P::::PPPPPPPPP    \n");
	printf("\t\t\t\t\t  L:::::L                 E::::::EEEEEEEEEE         V:::::V V:::::V        E::::::EEEEEEEEEE     L:::::L                     U:::::D     D:::::U   P::::P            \n");
	printf("\t\t\t\t\t  L:::::L                 E:::::E                    V:::::V:::::V         E:::::E               L:::::L                     U:::::D     D:::::U   P::::P            \n");
	printf("\t\t\t\t\t L:::::L         LLLLLL  E:::::E       EEEEEE        V:::::::::V          E:::::E       EEEEEE  L:::::L         LLLLLL      U::::::U   U::::::U   P::::P            \n");
	printf("\t\t\t\t\tLL:::::::LLLLLLLLL:::::LEE::::::EEEEEEEE:::::E         V:::::::V         EE::::::EEEEEEEE:::::ELL:::::::LLLLLLLLL:::::L      U:::::::UUU:::::::U PP::::::PP          \n");
	printf("\t\t\t\t\tL::::::::::::::::::::::LE::::::::::::::::::::E          V:::::V          E::::::::::::::::::::EL::::::::::::::::::::::L       UU:::::::::::::UU  P::::::::P          \n");
	printf("\t\t\t\t\tL::::::::::::::::::::::LE::::::::::::::::::::E           V:::V           E::::::::::::::::::::EL::::::::::::::::::::::L         UU:::::::::UU    P::::::::P          \n");
	printf("\t\t\t\t\tLLLLLLLLLLLLLLLLLLLLLLLLEEEEEEEEEEEEEEEEEEEEEE            VVV            EEEEEEEEEEEEEEEEEEEEEELLLLLLLLLLLLLLLLLLLLLLLL           UUUUUUUUU      PPPPPPPPPP          \n\n\n");
	printf("\t\t\t\t\t\t\t\t\t###########################################################################\n");
	printf("\t\t\t\t\t\t\t\t\t#                                                                         #\n");  
	printf("\t\t\t\t\t\t\t\t\t#              Seus pontos serão distribuidos automaticamente!            #\n");  
	printf("\t\t\t\t\t\t\t\t\t#                                                                         #\n");  
	printf("\t\t\t\t\t\t\t\t\t###########################################################################\n");                                                                                                                                                                        
                                                                                                                                                                     
}

void gameOver(){
	
	setlocale(LC_ALL, "Portuguese");
	                                                                                                           
	printf("\t\t\t\t\t      _____           ____        ______  _______        ______           _____     ____      ____      ______        _____   \n");
	printf("\t\t\t\t\t ___|\\    \\     ____|\\   \\      |      \\/       \\   ___|\\     \\     ____|\\    \\   |    |    |    | ___|\\     \\   ___|\\    \\  \n");
	printf("\t\t\t\t\t /    /\\    \\   /    /\\    \\    /          /\\     \\ |     \\     \\   /     /\\    \\  |    |    |    ||     \\     \\ |    |\\    \\ \n");
	printf("\t\t\t\t\t|    |  |____| |    |  |    |  /     /\\   / /\\     ||     ,_____/| /     /  \    \\ |    |    |    ||     ,_____/||    | |    |\n");
	printf("\t\t\t\t\t|    |    ____ |    |__|    | /     /\\ \_/ / /    /||     \\--'\\_|/|     |    |    ||    |    |    ||     \\--'\\_|/|    |/____/ \n");
	printf("\t\t\t\t\t|    |   |    ||    .--.    ||     |  \\|_|/ /    / ||     /___/|  |     |    |    ||    |    |    ||     /___/|  |    |\\    \\ \n");
	printf("\t\t\t\t\t|    |   |_,  ||    |  |    ||     |       |    |  ||     \\____|\\ |\\     \\  /    /||\\    \\  /    /||     \\____|\ |    | |    |\n");
	printf("\t\t\t\t\t|\\ ___\\___/  /||____|  |____||\\____\\       |____|  /|____ '     /|| \_____\\/____/ || \\ ___\\/___ / ||____ '     /||____| |____|\n");
	printf("\t\t\t\t\t| |   /____ / ||    |  |    || |    |      |    | / |    /_____/ | \\ |    ||    | / \\ |   ||   | / |    /_____/ ||    | |    |\n");
	printf("\t\t\t\t\t \\|___|    | / |____|  |____| \\|____|      |____|/  |____|     | /  \\|____||____|/   \\|___||___|/  |____|     | /|____| |____|\n");
	printf("\t\t\t\t\t   \\( |____|/    \\(      )/      \\(          )/       \\( |_____|/      \\(    )/        \\(    )/      \\( |_____|/   \\(     )/  \n");
	printf("\t\t\t\t\t    '   )/        '      '        '          '         '    )/          '    '          '    '        '    )/       '     '   \n");
	printf("\t\t\t\t\t        '                                                   '                                              '                  \n");
	printf("\n\n\t\t\t\t\t\t\t\t\t Você morreu, aguarde 60 segundos para que seu corpo reencontre sua alma.\n"); Sleep(60000);
}


// #############################################################################
// #		       	PARTE QUE FICARA AS INSERCOES DE ARQUIVOS                  #
// #############################################################################

void matouMonstro(char * codigoUsuario, int expInimigo, int moedas){
	int aux;
	FILE *pont_arq;
	
	pont_arq = fopen(codigoUsuario, "r");
	
	//Verifica abertura do arquivo:
	if(!pont_arq){
		printf("Deu errado!");
	}
	
	struct Personagem p;
	struct Atributos a;
	struct Arma ar;
	struct Pet pet;
	struct Montaria m;
	
	// Ler arquivo e aloca na memoria
	char linha[10];
	
	fgets(linha, 10, pont_arq);
	p.nivel = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	p.exp = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	p.hp = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	p.moedas = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	p.pontKills = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	a.forca = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	a.destreza = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	a.inteligencia = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	a.sorte = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	ar.arco = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	ar.espada = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	ar.varinha = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	pet.tigre = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	pet.vibora = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	pet.aguia = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	m.buffalo = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	m.cavalo = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	m.dragao = atoi(linha);
	
	// Fecha arquivo de leitura.
	fclose(pont_arq);
	
	p.moedas = p.moedas + moedas;
	p.exp = p.exp + expInimigo;
	if (p.exp > 100){
		levelUp();
		p.nivel++; // Ganha 1 nivel
		p.exp = p.exp - 100; // Perde a exp do nivel e ganha 2 pontos aleatorios
		
		// Distribui o primeiro ponto!
		srand(time(NULL));
		aux = rand() % 4;
		if (aux == 1){
			a.forca++;
			centerText();
			printf("Voce ganhou 1 ponto em forca!\n");
		}
		else if (aux == 2){
			a.destreza++;
			centerText();
			printf("Voce ganhou 1 ponto em destreza!\n");
		}
		else if (aux == 3){
			a.inteligencia++;
			centerText();
			printf("Voce ganhou 1 ponto em inteligencia!\n");
		}
		else{
			a.sorte++;
			centerText();
			printf("Voce ganhou 1 ponto em sorte!\n");
		}
		Sleep(3000);
		// Distribui o segundo ponto!
		srand(time(NULL));
		aux = rand() % 4;
		if (aux == 1){
			a.forca++;
			centerText();
			printf("Voce ganhou 1 ponto em forca!\n");
		}
		else if (aux == 2){
			a.destreza++;
			centerText();
			printf("Voce ganhou 1 ponto em destreza!\n");
		}
		else if (aux == 3){
			a.inteligencia++;
			centerText();
			printf("Voce ganhou 1 ponto em inteligencia!\n");
		}
		else{
			a.sorte++;
			centerText();
			printf("Voce ganhou 1 ponto em sorte!\n");
		}
		Sleep(3000);
	}
	
	pont_arq = fopen(codigoUsuario, "w");
	// Escreve o que foi alterado no arquivo original.
	fprintf(pont_arq, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", p.nivel, p.exp, p.hp, p.moedas, p.pontKills, a.forca, a.destreza, a.inteligencia, a.sorte, ar.arco, ar.espada, ar.varinha, pet.tigre, pet.vibora, pet.aguia, m.buffalo, m.cavalo, m.dragao);	
	// Fecha o arquivo editado.
	fclose(pont_arq);
}

void batalha(char *codigoUsuario, int poderAtkInimigo, int expInimigo, int moedas){
	int poder, hp;
	FILE *pont_arq;
	
	pont_arq = fopen(codigoUsuario, "r");
	
	//Verifica abertura do arquivo:
	if(!pont_arq){
		printf("Deu errado!\n");
		printf("Voce errou no batalha\n");
	}
	
	struct Personagem p;
	struct Atributos a;
	struct Arma ar;
	struct Pet pet;
	struct Montaria m;
	
	// Ler arquivo e aloca na memoria
	char linha[10];
	
	fgets(linha, 10, pont_arq);
	p.nivel = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	p.exp = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	p.hp = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	p.moedas = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	p.pontKills = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	a.forca = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	a.destreza = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	a.inteligencia = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	a.sorte = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	ar.arco = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	ar.espada = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	ar.varinha = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	pet.tigre = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	pet.vibora = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	pet.aguia = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	m.buffalo = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	m.cavalo = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	m.dragao = atoi(linha);
	
	// Fecha arquivo de leitura.
	fclose(pont_arq);
	
	if(ar.arco == 1){
		poder = (a.forca * 5) + (a.destreza * 8) + (a.inteligencia * 2) + (a.sorte * 4);
		hp = p.hp + (a.forca * 25);
	}
	else if (ar.espada == 1){
		poder = (a.forca * 8) + (a.destreza * 5) + (a.inteligencia * 4) + (a.sorte * 2);
		hp = p.hp + (a.forca * 25);
	}
	else{
		poder = (a.forca * 2) + (a.destreza * 4) + (a.inteligencia * 8) + (a.sorte * 5);
		hp = p.hp + (a.forca * 25);
	}
	
	if (hp <= poderAtkInimigo){
		reduzirMoedas(codigoUsuario);
		centerText();
		printf("Voce perdeu METADE de suas moedas! Seu HP é inferior ao poder de ataque do inimigo! :(\n\n");
		gameOver();
		system("cls");
		logo();
		menuInicial(codigoUsuario);
	}
	else if(poder >= poderAtkInimigo){
		vitoriaBatalha(expInimigo, moedas);
		matouMonstro(codigoUsuario, expInimigo, moedas);
		Sleep(3000);
		system("cls");
		logo();
		menuInicial(codigoUsuario);
	}
	else{
		reduzirMoedas(codigoUsuario);
		centerText();
		printf("Voce perdeu METADE de suas moedas! Seu poder de ataque é inferior ao poder de ataque do inimigo! :(\n\n");
		gameOver();
		system("cls");
		logo();
		menuInicial(codigoUsuario);
	}
}

void reduzirMoedas(char *codigoUsuario){
	FILE *pont_arq;
	
	pont_arq = fopen(codigoUsuario, "r");
	
	//Verifica abertura do arquivo:
	if(!pont_arq){
		printf("Deu errado!\n");
		printf("Voce errou no reduzirMoedas\n");
	}
	
	struct Personagem p;
	struct Atributos a;
	struct Arma ar;
	struct Pet pet;
	struct Montaria m;
	
	// Ler arquivo e aloca na memoria
	char linha[10];
	
	fgets(linha, 10, pont_arq);
	p.nivel = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	p.exp = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	p.hp = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	p.moedas = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	p.pontKills = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	a.forca = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	a.destreza = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	a.inteligencia = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	a.sorte = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	ar.arco = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	ar.espada = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	ar.varinha = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	pet.tigre = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	pet.vibora = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	pet.aguia = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	m.buffalo = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	m.cavalo = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	m.dragao = atoi(linha);
	
	// Fecha arquivo de leitura.
	fclose(pont_arq);
	
	p.moedas = (p.moedas / 2);
	
	// Abre arquivo de escrita.
	pont_arq = fopen(codigoUsuario, "w");
	// Escreve o que foi alterado no arquivo original.
	fprintf(pont_arq, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", p.nivel, p.exp, p.hp, p.moedas, p.pontKills, a.forca, a.destreza, a.inteligencia, a.sorte, ar.arco, ar.espada, ar.varinha, pet.tigre, pet.vibora, pet.aguia, m.buffalo, m.cavalo, m.dragao);	
	// Fecha o arquivo editado.
	fclose(pont_arq);
}

void serGuerreiro(char *codigoUsuario){
	FILE *pont_arq;
	
	pont_arq = fopen(codigoUsuario, "r");
	
	//Verifica abertura do arquivo:
	if(!pont_arq){
		printf("Deu errado!");
	}
	
	struct Personagem p;
	struct Atributos a;
	struct Arma ar;
	struct Pet pet;
	struct Montaria m;
	
	// Ler arquivo e aloca na memoria
	char linha[10];
	
	fgets(linha, 10, pont_arq);
	p.nivel = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	p.exp = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	p.hp = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	p.moedas = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	p.pontKills = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	a.forca = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	a.destreza = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	a.inteligencia = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	a.sorte = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	ar.arco = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	ar.espada = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	ar.varinha = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	pet.tigre = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	pet.vibora = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	pet.aguia = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	m.buffalo = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	m.cavalo = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	m.dragao = atoi(linha);
	
	// Fecha arquivo de leitura.
	fclose(pont_arq);
	
	//Pequena alteracao dos dados pode ser feita aqui.
	ar.espada++;
	pet.tigre++;
	m.buffalo++;
	// Abre arquivo de escrita.
	pont_arq = fopen(codigoUsuario, "w");
	// Escreve o que foi alterado no arquivo original.
	fprintf(pont_arq, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", p.nivel, p.exp, p.hp, p.moedas, p.pontKills, a.forca, a.destreza, a.inteligencia, a.sorte, ar.arco, ar.espada, ar.varinha, pet.tigre, pet.vibora, pet.aguia, m.buffalo, m.cavalo, m.dragao);	
	// Fecha o arquivo editado.
	fclose(pont_arq);
}

void serArqueiro(char *codigoUsuario){
	FILE *pont_arq;
	
	pont_arq = fopen(codigoUsuario, "r");
	
	//Verifica abertura do arquivo:
	if(!pont_arq){
		printf("Deu errado!");
	}
	
	struct Personagem p;
	struct Atributos a;
	struct Arma ar;
	struct Pet pet;
	struct Montaria m;
	
	// Ler arquivo e aloca na memoria
	char linha[10];
	
	fgets(linha, 10, pont_arq);
	p.nivel = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	p.exp = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	p.hp = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	p.moedas = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	p.pontKills = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	a.forca = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	a.destreza = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	a.inteligencia = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	a.sorte = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	ar.arco = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	ar.espada = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	ar.varinha = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	pet.tigre = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	pet.vibora = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	pet.aguia = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	m.buffalo = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	m.cavalo = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	m.dragao = atoi(linha);
	
	// Fecha arquivo de leitura.
	fclose(pont_arq);
	
	//Pequena alteracao dos dados pode ser feita aqui.
	ar.arco++;
	pet.vibora++;
	m.cavalo++;
	// Abre arquivo de escrita.
	pont_arq = fopen(codigoUsuario, "w");
	// Escreve o que foi alterado no arquivo original.
	fprintf(pont_arq, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", p.nivel, p.exp, p.hp, p.moedas, p.pontKills, a.forca, a.destreza, a.inteligencia, a.sorte, ar.arco, ar.espada, ar.varinha, pet.tigre, pet.vibora, pet.aguia, m.buffalo, m.cavalo, m.dragao);	
	// Fecha o arquivo editado.
	fclose(pont_arq);
}

void serMago(char *codigoUsuario){
	FILE *pont_arq;
	
	pont_arq = fopen(codigoUsuario, "r");
	
	//Verifica abertura do arquivo:
	if(!pont_arq){
		printf("Deu errado!");
	}
	
	struct Personagem p;
	struct Atributos a;
	struct Arma ar;
	struct Pet pet;
	struct Montaria m;
	
	// Ler arquivo e aloca na memoria
	char linha[10];
	
	fgets(linha, 10, pont_arq);
	p.nivel = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	p.exp = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	p.hp = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	p.moedas = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	p.pontKills = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	a.forca = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	a.destreza = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	a.inteligencia = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	a.sorte = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	ar.arco = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	ar.espada = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	ar.varinha = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	pet.tigre = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	pet.vibora = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	pet.aguia = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	m.buffalo = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	m.cavalo = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	m.dragao = atoi(linha);
	
	// Fecha arquivo de leitura.
	fclose(pont_arq);
	
	//Pequena alteracao dos dados pode ser feita aqui.
	ar.varinha++;
	pet.aguia++;
	m.dragao++;
	// Abre arquivo de escrita.
	pont_arq = fopen(codigoUsuario, "w");
	// Escreve o que foi alterado no arquivo original.
	fprintf(pont_arq, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", p.nivel, p.exp, p.hp, p.moedas, p.pontKills, a.forca, a.destreza, a.inteligencia, a.sorte, ar.arco, ar.espada, ar.varinha, pet.tigre, pet.vibora, pet.aguia, m.buffalo, m.cavalo, m.dragao);	
	// Fecha o arquivo editado.
	fclose(pont_arq);
}

void buffarAlquimista(char * codigoUsuario){
	FILE *pont_arq;
	
	pont_arq = fopen(codigoUsuario, "r");
	
	//Verifica abertura do arquivo:
	if(!pont_arq){
		printf("Deu errado!");
	}
	
	struct Personagem p;
	struct Atributos a;
	struct Arma ar;
	struct Pet pet;
	struct Montaria m;
	
	// Ler arquivo e aloca na memoria
	char linha[10];
	
	fgets(linha, 10, pont_arq);
	p.nivel = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	p.exp = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	p.hp = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	p.moedas = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	p.pontKills = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	a.forca = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	a.destreza = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	a.inteligencia = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	a.sorte = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	ar.arco = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	ar.espada = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	ar.varinha = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	pet.tigre = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	pet.vibora = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	pet.aguia = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	m.buffalo = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	m.cavalo = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	m.dragao = atoi(linha);
	
	// Fecha arquivo de leitura.
	fclose(pont_arq);
	
	if (p.moedas >= 200){
		p.moedas = p.moedas - 200;
		a.forca = a.forca + 15;
		a.destreza = a.destreza + 15;
		a.inteligencia = a.inteligencia + 15;
		a.sorte = a.sorte + 15;
		centerText();
		printf("Pontos adicionados com sucesso!\n\n");
		centerText();
		printf("Seu saldo eh: %d moedas", p.moedas);
	}
	else{
		printf("\n\n");
		centerText();
		printf("Saldo insuficiente!\n\n");
		centerText();
		printf("Voce tem apenas: %d moedas", p.moedas);
	}
	// Abre arquivo de escrita.
	pont_arq = fopen(codigoUsuario, "w");
	// Escreve o que foi alterado no arquivo original.
	fprintf(pont_arq, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", p.nivel, p.exp, p.hp, p.moedas, p.pontKills, a.forca, a.destreza, a.inteligencia, a.sorte, ar.arco, ar.espada, ar.varinha, pet.tigre, pet.vibora, pet.aguia, m.buffalo, m.cavalo, m.dragao);	
	// Fecha o arquivo editado.
	fclose(pont_arq);
}

void buffarCurandeira(char * codigoUsuario){
	FILE *pont_arq;
	
	pont_arq = fopen(codigoUsuario, "r");
	
	//Verifica abertura do arquivo:
	if(!pont_arq){
		printf("Deu errado!");
	}
	
	struct Personagem p;
	struct Atributos a;
	struct Arma ar;
	struct Pet pet;
	struct Montaria m;
	
	// Ler arquivo e aloca na memoria
	char linha[10];
	
	fgets(linha, 10, pont_arq);
	p.nivel = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	p.exp = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	p.hp = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	p.moedas = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	p.pontKills = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	a.forca = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	a.destreza = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	a.inteligencia = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	a.sorte = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	ar.arco = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	ar.espada = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	ar.varinha = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	pet.tigre = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	pet.vibora = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	pet.aguia = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	m.buffalo = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	m.cavalo = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	m.dragao = atoi(linha);
	
	// Fecha arquivo de leitura.
	fclose(pont_arq);
	
	if (p.moedas >= 100){
		p.moedas = p.moedas - 100;
		a.forca = a.forca + 5;
		a.destreza = a.destreza + 5;
		a.inteligencia = a.inteligencia + 5;
		a.sorte = a.sorte + 5;
		centerText();
		printf("Pontos adicionados com sucesso!\n\n");
		centerText();
		printf("Seu saldo eh: %d moedas", p.moedas);
	}
	else{
		printf("\n\n");
		centerText();
		printf("Saldo insuficiente!\n");
		centerText();
		printf("Voce tem apenas: %d moedas", p.moedas);
	}
	// Abre arquivo de escrita.
	pont_arq = fopen(codigoUsuario, "w");
	// Escreve o que foi alterado no arquivo original.
	fprintf(pont_arq, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", p.nivel, p.exp, p.hp, p.moedas, p.pontKills, a.forca, a.destreza, a.inteligencia, a.sorte, ar.arco, ar.espada, ar.varinha, pet.tigre, pet.vibora, pet.aguia, m.buffalo, m.cavalo, m.dragao);	
	// Fecha o arquivo editado.
	fclose(pont_arq);
}

void transcederMontaria(char * codigoUsuario){
	FILE *pont_arq;
	
	pont_arq = fopen(codigoUsuario, "r");
	
	//Verifica abertura do arquivo:
	if(!pont_arq){
		printf("Deu errado!");
	}
	
	struct Personagem p;
	struct Atributos a;
	struct Arma ar;
	struct Pet pet;
	struct Montaria m;
	
	// Ler arquivo e aloca na memoria
	char linha[10];
	
	fgets(linha, 10, pont_arq);
	p.nivel = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	p.exp = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	p.hp = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	p.moedas = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	p.pontKills = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	a.forca = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	a.destreza = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	a.inteligencia = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	a.sorte = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	ar.arco = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	ar.espada = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	ar.varinha = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	pet.tigre = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	pet.vibora = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	pet.aguia = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	m.buffalo = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	m.cavalo = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	m.dragao = atoi(linha);
	
	// Fecha arquivo de leitura.
	fclose(pont_arq);
	
	if (p.moedas >= 500){
		p.moedas = p.moedas - 500;
		a.forca = a.forca + 40;
		a.destreza = a.destreza + 40;
		a.inteligencia = a.inteligencia + 40;
		a.sorte = a.sorte + 40;
		if (ar.arco == 1){
			m.cavalo++;
		}
		else if(ar.espada == 1){
			m.buffalo++;
		}
		else{
			m.dragao++;
		}
		centerText();
		printf("Pontos adicionados com sucesso! E sua montaria transcedeu!\n\n");
		centerText();
		printf("Seu saldo eh: %d moedas", p.moedas);
	}
	else{
		printf("\n\n");
		centerText();
		printf("Saldo insuficiente!\n");
		centerText();
		printf("Voce tem apenas: %d moedas", p.moedas);
	}
	// Abre arquivo de escrita.
	pont_arq = fopen(codigoUsuario, "w");
	// Escreve o que foi alterado no arquivo original.
	fprintf(pont_arq, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", p.nivel, p.exp, p.hp, p.moedas, p.pontKills, a.forca, a.destreza, a.inteligencia, a.sorte, ar.arco, ar.espada, ar.varinha, pet.tigre, pet.vibora, pet.aguia, m.buffalo, m.cavalo, m.dragao);	
	// Fecha o arquivo editado.
	fclose(pont_arq);
}

int calcularPoder(char * codigoUsuario){
	int poder;
	FILE *pont_arq;
	
	pont_arq = fopen(codigoUsuario, "r");
	
	//Verifica abertura do arquivo:
	if(!pont_arq){
		printf("Deu errado!");
	}
	
	struct Personagem p;
	struct Atributos a;
	struct Arma ar;
	struct Pet pet;
	struct Montaria m;
	
	// Ler arquivo e aloca na memoria
	char linha[10];
	
	fgets(linha, 10, pont_arq);
	p.nivel = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	p.exp = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	p.hp = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	p.moedas = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	p.pontKills = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	a.forca = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	a.destreza = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	a.inteligencia = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	a.sorte = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	ar.arco = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	ar.espada = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	ar.varinha = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	pet.tigre = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	pet.vibora = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	pet.aguia = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	m.buffalo = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	m.cavalo = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	m.dragao = atoi(linha);
	
	// Fecha arquivo de leitura.
	fclose(pont_arq);
	
	if(ar.arco == 1){
		poder = (a.forca * 5) + (a.destreza * 8) + (a.inteligencia * 2) + (a.sorte * 4);
	}
	else if (ar.espada == 1){
		poder = (a.forca * 8) + (a.destreza * 5) + (a.inteligencia * 4) + (a.sorte * 2);
	}
	else{
		poder = (a.forca * 2) + (a.destreza * 4) + (a.inteligencia * 8) + (a.sorte * 5);
	}
	
	return poder;
}

void transcederPet(char * codigoUsuario){
	FILE *pont_arq;
	
	pont_arq = fopen(codigoUsuario, "r");
	
	//Verifica abertura do arquivo:
	if(!pont_arq){
		printf("Deu errado!");
	}
	
	struct Personagem p;
	struct Atributos a;
	struct Arma ar;
	struct Pet pet;
	struct Montaria m;
	
	// Ler arquivo e aloca na memoria
	char linha[10];
	
	fgets(linha, 10, pont_arq);
	p.nivel = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	p.exp = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	p.hp = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	p.moedas = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	p.pontKills = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	a.forca = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	a.destreza = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	a.inteligencia = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	a.sorte = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	ar.arco = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	ar.espada = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	ar.varinha = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	pet.tigre = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	pet.vibora = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	pet.aguia = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	m.buffalo = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	m.cavalo = atoi(linha);
	
	fgets(linha, 10, pont_arq);
	m.dragao = atoi(linha);
	
	// Fecha arquivo de leitura.
	fclose(pont_arq);
	
	if (p.moedas >= 300){
		p.moedas = p.moedas - 300;
		a.forca = a.forca + 25;
		a.destreza = a.destreza + 25;
		a.inteligencia = a.inteligencia + 25;
		a.sorte = a.sorte + 25;
		if (ar.arco == 1){
			pet.vibora++;
		}
		else if(ar.espada == 1){
			pet.tigre++;
		}
		else{
			pet.aguia++;
		}
		centerText();
		printf("Pontos adicionados com sucesso! Mas isso aqui nao eh Pokemon! Evolua sua montaria. . .\n\n");
		centerText();
		printf("Seu saldo eh: %d moedas", p.moedas);
	}
	else{
		printf("\n\n");
		centerText();
		printf("Saldo insuficiente!\n");
		centerText();
		printf("Voce tem apenas: %d moedas", p.moedas);
	}
	// Abre arquivo de escrita.
	pont_arq = fopen(codigoUsuario, "w");
	// Escreve o que foi alterado no arquivo original.
	fprintf(pont_arq, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", p.nivel, p.exp, p.hp, p.moedas, p.pontKills, a.forca, a.destreza, a.inteligencia, a.sorte, ar.arco, ar.espada, ar.varinha, pet.tigre, pet.vibora, pet.aguia, m.buffalo, m.cavalo, m.dragao);	
	// Fecha o arquivo editado.
	fclose(pont_arq);
}