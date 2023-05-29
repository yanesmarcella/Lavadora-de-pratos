#include <stdio.h>
#include <stdlib.h>

struct cel{
    int conteudo;
    struct cel *proximo;
}cel;

struct pilha{
   struct cel *topo;
}pilha;

typedef struct cel celula;
typedef struct pilha p;

void empilhar(p *pilha, int valor){
    
    celula *novo;
    novo = malloc(sizeof(celula));
    novo -> conteudo = valor;
    novo -> proximo = pilha -> topo;
    pilha -> topo = novo;
    printf(" Prato adicionado");

}

int desempilhar(p *pilha){
    
    int valor;
    celula *removido;
    
    if (pilha -> topo == NULL)
        valor = 0;
        
    else{
        removido = pilha -> topo;
        valor = removido -> conteudo;
        pilha -> topo = removido -> proximo;
        free(removido);
    }
    return valor;
}


void imprimirpilha(p *pilha){
    
    celula *aux = pilha -> topo;
    printf("\n\tTOPO PILHA");
    
    while(aux != NULL){
        printf("\n\t%d ", aux -> conteudo);
        aux = aux -> proximo;
        
    }
    printf("\n\tFIM PILHA\n");
    
}



void main()
{
    p pilha;
    pilha.topo = NULL;
    
    int opcao,valor;
    
    do{
        printf("LAVA LOUÇAS - PRATOS");
        printf("\n\t0 - Sair\n\t1 - Adicionar prato\n\t2 - Lavar um prato\n\t3 - Mostrar pratos restantes\n");
        scanf("%d", &opcao);
        
        switch(opcao){
            
            case 1:
                printf("Ordem do prato: ");
                scanf("%d",&valor);
                empilhar(&pilha,valor);
                printf("\n");
                break;
            
            case 2:
               int resultado = desempilhar(&pilha);
            
               if(resultado == 0)
                  printf("Todos os pratos foram lavados");
                  
                else
                    printf("A ordem do prato lavado foi: %d", resultado);
                    printf("\n");
               break;
            
            case 3:
                imprimirpilha(&pilha);
                break;
            
            default:
                if(opcao != 0)
                    printf("\nOpção Inválida");
        }
    } while(opcao != 0);
}
