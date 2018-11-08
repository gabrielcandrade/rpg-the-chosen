#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <windows.h>

void logo();
int autenticarLogin(char *codigoUsuario);
void criarArquivo();
void fullscreen();
void musica();

int main()
{
	char codigoUsuario[50], nomeDoArquivo[35];
	
	fullscreen();
	logo();
	musica();
	
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
	pont_arq = fopen(codigoUsuario, "a");
  
	// fechando arquivo
	fclose(pont_arq);
  
	//mensagem para o usuário
	printf("Sera criado um personagem novo! Bem vindo a Charrfall!\n");
  
	system("pause");
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

