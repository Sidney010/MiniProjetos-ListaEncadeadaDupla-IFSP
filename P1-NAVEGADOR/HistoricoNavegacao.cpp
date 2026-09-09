#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Estruturas 
typedef struct Pagina {
	
	char url[255];
	struct Pagina *advance;
	struct Pagina *back;
	
} Pagina;


// Primeiro pagina, Ponteiro inicial da lista
Pagina* ini = NULL;


// Menu Chamado
void ChamaMenu(){
	printf("\n Iniciando Sistema ...\n");
	printf(" Escolha algumas das opcoes a seguir: \n");
	printf("  1. Visistar \n");
	printf("  2. Voltar \n");
	printf("  3. Avancar \n");
	printf("  4. Historico \n");	
	printf("  5. Sair \n");	
}

// Limpar buffer de teclado
void limparBuffer(){
	int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


// Exibir Aba
void ExibirAba(char *url){
	printf("  Url: %s\n", url);
	/*
	if(1){
		//TODO VALIDAÇÔES
		printf("  Url: %s\n", url);
	} else {
		printf("\n\n ERROR 400: Não foi possível processar seu historico\n\n");
	}
	*/

}

// Cadastrar pagina
void VisitarUrlPagina(char *url){
	char url_[50];
	
	printf("\n Visitar Pagina \n ");
	printf(" Digite a pagina que deseja VISITAR a seguir e enter para envia-la ");
	
    limparBuffer();
    
    // Coleta o url
    printf("\n  Url: ");
    fgets(url_, sizeof(url_), stdin);
    url_[strcspn(url_, "\n")] = '\0'; // Remove o \n capturado pelo fgets
    
    // Enviando Url
    strcpy(url, url_);

    
}

// Libera toda a memória alocada para a lista encadeada
void DestruirLista() {
    Pagina *atual = ini;
    Pagina *proximoNode = NULL;
    while (atual != NULL) {
        proximoNode = atual->advance;
        free(atual);
        atual = proximoNode;
    }
    ini = NULL;
}

// Libera toda a memória alocada depois de um vistiar pagina para a lista encadeada
void DestruirListaParaFrente(Pagina *PaginaAtual) {
    Pagina *atual = PaginaAtual;
    Pagina *proximoNode = NULL;
    while (atual != NULL) {
        proximoNode = atual->advance;
        free(atual);
        atual = proximoNode;
    }
}

// Exibe todos as paginas na lista
void ExibirHistorico() {
    if (ini == NULL) {
        printf("\nNenhum pagina visitada na lista.\n");
        return;
    }
    
    Pagina *temp = ini;
    while (temp != NULL) {
        ExibirAba(temp->url);
        temp = temp->advance;
    }
}

// Visitar paginas 
void VisitarPagina(Pagina **PaginaAtual){
	
	if (*PaginaAtual != NULL){
		DestruirListaParaFrente((*PaginaAtual)->advance);
		(*PaginaAtual)->advance = NULL;
	}
    
	Pagina *novaPagina = (Pagina *) calloc(1, sizeof(Pagina));
	
    if (novaPagina == NULL) {
        printf("Erro ao alocar memória\n");
        return;
    }
    
    // Passa o ponteiro para URL
    VisitarUrlPagina(novaPagina->url);
    
    // Se a lista estiver vazia, o nova pagina se torna a primeira
    if (ini == NULL) {
        ini = novaPagina;
        *PaginaAtual = novaPagina;
        return;
    }

    // A nova Pagina deve ser insirida no final ja liberado
    (*PaginaAtual)->advance = novaPagina;
    novaPagina->back = *PaginaAtual;
	novaPagina->advance = NULL;
	*PaginaAtual = novaPagina;

}
void Voltar(Pagina **PaginaAtual){
	if ((*PaginaAtual)->back == NULL){
		printf("  Não é possivel voltar já estamos na primeira aba. \n");
		printf("\n  URL: %s\n", (*PaginaAtual)->url);
		return;
	}
	
	*PaginaAtual = (*PaginaAtual)->back;
	
	printf("\n  URL: %s\n", (*PaginaAtual)->url);
	
}
void Avancar(Pagina **PaginaAtual){
	if ((*PaginaAtual)->advance == NULL){
		printf("  Não é possivel avancar já estamos na ultima aba. ");
		printf("\n  URL: %s\n", (*PaginaAtual)->url);
		return;
	}
	
	*PaginaAtual = (*PaginaAtual)->advance;
	
	printf("\n  URL: %s\n", (*PaginaAtual)->url);
	
}

void Iniciar(){
    int opcao;
    printf(" Bem Vindo !!!");
    
    Pagina *AbaAtual = ini;
    
    do {
        ChamaMenu();
        printf(" Digite: ");
        scanf("%i", &opcao);
        
        switch (opcao) {
            case 1:
                VisitarPagina(&AbaAtual);
                break;
            case 2:
            	Voltar(&AbaAtual);
                break;
            case 3:
            	Avancar(&AbaAtual);
                break;
            case 4:
                ExibirHistorico();
                break;
            case 5:
                printf("\n Saindo do programa e liberando memória...\n");
                DestruirLista();
                break;
            default:
                printf("\n ERRO 404: Não foi possível encontrar sua escolha\n");
                printf(" Tente algumas das disponiveis no momento !!!\n\n");
        }
    } while (opcao != 5);
    
}


int main(){
	
	Iniciar();
	
}
















