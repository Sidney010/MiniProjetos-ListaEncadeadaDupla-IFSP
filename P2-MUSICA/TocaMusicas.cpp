#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Estruturas
typedef struct Dados {
	
	char titulo[50];
	char artista[100];

} Dados;
 
typedef struct Musica {
	
	Dados dadosMusica;
	struct Musica *ant;
	struct Musica *prox;
	
} Musica;

// Primeira, Ponteiro inicial da lista
Musica *ini = NULL;

// Limpar buffer de teclado
void limparBuffer(){
	int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Exibir Musica tocada
void ExibirMusicaTocando(Dados dadosMusica){
	printf("\n\n  Tocando... \n");
	printf("  Musica: %s\n", dadosMusica.titulo);
	printf("  Artista: %s\n", dadosMusica.artista);
	
	/*
	if(1){
		//TODO VALIDAÇÔES
		printf("  Musica: %s\n", dadosMusica.titulo);
	} else {
		printf("\n\n ERROR 400: Não foi possível processar sua playlist\n\n");
	}
	*/

}

// Cadastrar musica
void CadastrarMusica(Dados *dadosMusica){
	
	char titulo_[50];
	char artista_[100];
	
	printf("\n Adicionando Musica... \n ");
	printf(" Digite os dados da Musica que deseja ADICIONAR a seguir e enter para envia-la ");
	
    limparBuffer();
    
    // Coleta o titulo
    printf("\n  Titulo: ");
    fgets(titulo_, sizeof(titulo_), stdin);
    titulo_[strcspn(titulo_, "\n")] = '\0'; // Remove o \n capturado pelo fgets
    
    // Coleta o artista
    printf("  Artista: ");
    fgets(artista_, sizeof(artista_), stdin);
    artista_[strcspn(artista_, "\n")] = '\0'; 
    
    // Enviando dados
    strcpy(dadosMusica->titulo, titulo_);
	strcpy(dadosMusica->artista, artista_);
	
    
}

// Adiciona uma música no final da lista duplamente encadeada circular
void AdicionarMusica(Musica **MusicaTocando) { 
    Musica *novaMusica = (Musica *) calloc(1, sizeof(Musica)); 
    
    if (novaMusica == NULL) { 
        printf("Erro ao alocar memória\n"); 
        return; 
    } 
     
    CadastrarMusica(&(novaMusica->dadosMusica)); 
     
    // Se a lista estiver vazia
    if (ini == NULL) { 
        ini = novaMusica; 
        novaMusica->prox = ini; 
        novaMusica->ant = ini; // Aponta para si mesmo nos dois sentidos
        *MusicaTocando = novaMusica; 
        return; 
    } 
    
    // Como é duplamente encadeada circular, o último nó é sempre ini->ant
    Musica *ultimo = ini->ant;
    
    ultimo->prox = novaMusica;
    novaMusica->ant = ultimo;
    novaMusica->prox = ini;
    ini->ant = novaMusica;
} 

// Libera toda a memória alocada para a lista
void DestruirLista() { 
    if (ini == NULL) return;

    Musica *atual = ini;
    Musica *proximoNode = NULL;

    do {
        proximoNode = atual->prox;
        free(atual);
        atual = proximoNode;
    } while (atual != ini);

    ini = NULL; 
}



// Avançando para a próxima musica
void Proxima(Musica **MusicaTocando){
    if (MusicaTocando == NULL || *MusicaTocando == NULL) {
        printf("\n Nenhuma musica na playlist!\n");
        return;
    }

    *MusicaTocando = (*MusicaTocando)->prox;
    ExibirMusicaTocando((*MusicaTocando)->dadosMusica);
}

// Retornando a musaica tocada
void Anterior(Musica **MusicaTocando){
    if (MusicaTocando == NULL || *MusicaTocando == NULL) {
        printf("\n Nenhuma musica na playlist!\n");
        return;
    }

    *MusicaTocando = (*MusicaTocando)->ant;
    ExibirMusicaTocando((*MusicaTocando)->dadosMusica);
}

// Exibe todas as musicas na lista
void ExibirPlaylist(Musica **MusicaTocando) {
    if (ini == NULL) {
        printf("\n Nenhuma musica na playlist!\n");
        return;
    }

    Musica *temp = ini;
    int contador = 1;

    printf("\n=== MINHA PLAYLIST ===\n");
    do {
        // Indica qual musica esta tocando no momento
        if (MusicaTocando != NULL && *MusicaTocando == temp) {
            printf(" [%d] %s - %s (Tocando Agora)\n", contador, temp->dadosMusica.titulo, temp->dadosMusica.artista);
        } else {
            printf("  %d. %s - %s\n", contador, temp->dadosMusica.titulo, temp->dadosMusica.artista);
        }

        temp = temp->prox;
        contador++;
    } while (temp != ini); // Para quando der a volta e voltar ao primeiro nó
    
    printf("======================\n");
}

// Remover musica pelo titulo
void RemoverMusica(Musica **MusicaTocando) {
    if (ini == NULL) {
        printf("\n Nenhuma musica na playlist para remover!\n");
        return;
    }

    char tituloBusca[50];
    printf("\n Removendo Musica... \n");
    printf(" Digite o titulo da musica que deseja REMOVER: ");
    
    limparBuffer();
    fgets(tituloBusca, sizeof(tituloBusca), stdin);
    tituloBusca[strcspn(tituloBusca, "\n")] = '\0';

    Musica *atual = ini;
    int encontrada = 0;

    // Busca a música na lista circular
    do {
        if (strcmp(atual->dadosMusica.titulo, tituloBusca) == 0) {
            encontrada = 1;
            break;
        }
        atual = atual->prox;
    } while (atual != ini);

    if (!encontrada) {
        printf("\n Musica nao encontrada na playlist!\n");
        return;
    }

    // Se for o único nó da lista
    if (atual->prox == atual) {
        ini = NULL;
        *MusicaTocando = NULL;
    } else {
        // Reajusta os ponteiros dos vizinhos (desconecta o nó atual)
        atual->ant->prox = atual->prox;
        atual->prox->ant = atual->ant;

        // Se o nó a ser removido for o inicio (ini), atualiza o ini
        if (atual == ini) {
            ini = atual->prox;
        }

        // Se a música removida era a que estava tocando, toca a próxima
        if (atual == *MusicaTocando) {
            *MusicaTocando = atual->prox;
        }
    }

    free(atual);
    printf("\n Musica removida com sucesso!\n");
}

// Menu Chamado
void ChamaMenu(){
	printf("\n Iniciando Sistema ...\n");
	printf(" Escolha algumas das opcoes a seguir: \n");
	printf("  1. Adicionar Musica \n");
	printf("  2. Remover Musica \n");
	printf("  3. Proxima \n");
	printf("  4. Anterior \n");
	printf("  5. Exibir Playlist \n");	
	printf("  6. Sair \n");	
}
void Iniciar(){
    int opcao;
    printf(" Bem Vindo !!!");
    
    Musica *MusicaTocando = ini;
    
    do {
        ChamaMenu();
        printf(" Digite: ");
        scanf("%i", &opcao);
        
        switch (opcao) {
            case 1:
            	AdicionarMusica(&MusicaTocando);
    			break;
            case 2:
            	RemoverMusica(&MusicaTocando);
                break;
			case 3:
			    Proxima(&MusicaTocando);
			    break;
			case 4:
			    Anterior(&MusicaTocando);
			    break;
            case 5:
                ExibirPlaylist(&MusicaTocando);
                break;
            case 6:
                printf("\n Saindo do programa e liberando memória...\n");
                DestruirLista();
                break;
            default:
                printf("\n ERRO 404: Não foi possível encontrar sua escolha\n");
                printf(" Tente algumas das disponiveis no momento !!!\n\n");
        }
    } while (opcao != 6);
    
}

int main(){
	Iniciar();
}
