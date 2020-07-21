/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"




/*
 * Funcionalidade: cria dados para testes
 */
int carregaDadosTeste(Cliente * clientes){
    
    Cliente cliente;
    
    //cliente 1
    cliente.codigo = 1;
    strcpy(cliente.nome, "Maria");
    cliente.genero = 'f';
    strcpy(cliente.email, "maria.oliveira@gmail.com");
    cliente.dataNascimento.dia = 12;
    cliente.dataNascimento.mes = 12;
    cliente.dataNascimento.dia = 1985;
    cliente.inativo = false;
    //tratamento 1
    cliente.tratamentos[0].codigoCliente = 1;
    strcpy(cliente.tratamentos[0].descricao, "Unhas de gel");
    cliente.tratamentos[0].preco = 12.5F;
    cliente.tratamentos[0].dataTratamento.dia = 12;
    cliente.tratamentos[0].dataTratamento.mes = 12;
    cliente.tratamentos[0].dataTratamento.ano = 2018;
    //tratamento 2
    cliente.tratamentos[1].codigoCliente = 1;
    strcpy(cliente.tratamentos[1].descricao, "Depilacao laser");
    cliente.tratamentos[1].preco = 65.0F;
    cliente.tratamentos[1].dataTratamento.dia = 12;
    cliente.tratamentos[1].dataTratamento.mes = 11;
    cliente.tratamentos[1].dataTratamento.ano = 2018;
    
    cliente.quantidadeTratamentos = 2;
    
    //inserir cliente no array
    clientes[0] = cliente;
    
    
    //cliente 1
    cliente.codigo = 2;
    strcpy(cliente.nome, "Jose");
    cliente.genero = 'm';
    strcpy(cliente.email, "jose.faria@gmail.com");
    cliente.dataNascimento.dia = 5;
    cliente.dataNascimento.mes = 8;
    cliente.dataNascimento.dia = 1990;
    cliente.inativo = false;
    //tratamento 1
    cliente.tratamentos[0].codigoCliente = 1;
    strcpy(cliente.tratamentos[0].descricao, "Pedicure");
    cliente.tratamentos[0].preco = 10.0F;
    cliente.tratamentos[0].dataTratamento.dia = 10;
    cliente.tratamentos[0].dataTratamento.mes = 6;
    cliente.tratamentos[0].dataTratamento.ano = 2018;
    //tratamento 2
    cliente.tratamentos[1].codigoCliente = 1;
    strcpy(cliente.tratamentos[1].descricao, "massagem");
    cliente.tratamentos[1].preco = 20.0F;
    cliente.tratamentos[1].dataTratamento.dia = 15;
    cliente.tratamentos[1].dataTratamento.mes = 9;
    cliente.tratamentos[1].dataTratamento.ano = 2018;
    //tratamento 3
    cliente.tratamentos[2].codigoCliente = 1;
    strcpy(cliente.tratamentos[2].descricao, "massagem");
    cliente.tratamentos[2].preco = 20.0F;
    cliente.tratamentos[2].dataTratamento.dia = 15;
    cliente.tratamentos[2].dataTratamento.mes = 10;
    cliente.tratamentos[2].dataTratamento.ano = 2018;
    
    cliente.quantidadeTratamentos = 3;
    
    //inserir cliente no array
    clientes[1] = cliente;
    
    
    return 2;
    
}

Cliente novoCliente(int quantidade){
    
    //declarar variáveis
    Cliente cliente;
    
    //atrubuir numero sequenciar
    cliente.codigo = quantidade + 1;
    
    //recolher dados cliente
    printf("insira o nome: ");
    scanf("%s", cliente.nome);
    
    printf("insira o email: ");
    scanf("%s", cliente.email);
    getchar();
    
    printf("insira o genero: ");
    scanf("%c", &cliente.genero);

    printf("insira o dia de nascimento: ");
    scanf("%d", &cliente.dataNascimento.dia);

    printf("insira o mes de nascimento: ");
    scanf("%d", &cliente.dataNascimento.mes);

    printf("insira o ano de nascimento: ");
    scanf("%d", &cliente.dataNascimento.ano);

    //novo cliente ativo
    cliente.inativo = false;
    
    //novo cliente com 0 tratamentos
    cliente.quantidadeTratamentos = 0;
    
    return cliente;
}


/*
 * Funcionalidade: elimina/inativa um cliente
 */
void eliminaCliente(Cliente *clientes, int posicao){
    
    //inativar o cliente
    clientes[posicao].inativo = true;
   
}


/*
 * Funcionalidade: cria/insere Clientes no array
 */
int insereClientes(Cliente * clientes, int quantidade, int tamanho){
    
    //declarar variáveis
    Cliente cliente;
    
    //limpar consola
    clear(); //system("cls");
    puts("===========================================================");
    puts("=                   Criar Clientes                        =");
    puts("===========================================================");
    
    //recolher nome do cliente para verificar condição de paragem
    printf("Insira sair para terminar\n");
    printf("insira o nome: ");
    scanf("%s", cliente.nome);
    
    //strcasecmp = stricmp
    while (strcasecmp(cliente.nome, "sair")!= 0 && quantidade < tamanho){
        
        //atrubuir numero sequenciar
        cliente.codigo = quantidade + 1;
                
        //recolher dados cliente
        printf("insira o email: ");
        scanf("%s", cliente.email);
        //fflush(stdin);
        getchar();
        
        printf("insira o genero: ");
        scanf("%c", &cliente.genero);
        
        printf("insira o dia de nascimento: ");
        scanf("%d", &cliente.dataNascimento.dia);
        
        printf("insira o mes de nascimento: ");
        scanf("%d", &cliente.dataNascimento.mes);
        
        printf("insira o ano de nascimento: ");
        scanf("%d", &cliente.dataNascimento.ano);
        
        //novo cliente ativo
        cliente.inativo = false;
        
        //novo cliente com 0 tratamentos
        cliente.quantidadeTratamentos = 0;
        
        //inserir cliente no array
        clientes[quantidade] = cliente;
        
        //incrementar a quantidade
        quantidade++;
        
        //limpar consola
        clear();//system("cls");
        
        puts("===========================================================");
        puts("=                   Criar Clientes                        =");
        puts("===========================================================");
        
        //recolher nome do cliente para verificar condição de paragem
        printf("Insira sair para terminar\n");
        printf("insira o nome: ");
        scanf("%s", cliente.nome);
        
    }
    
    //retornar quantidade
    return quantidade;
}


/*
 * Funcionalidade: Lista clientes do genero masculino
 */
void listaClientesMasculino(Cliente * clientes, int quantidade){
    
    //declarar variáveis
    int i, contador=0;
    
    //limpar consola
    clear(); //system("cls");
    
    puts("===========================================================");
    puts("=                   Clientes Masculino                    =");
    puts("===========================================================");
    
    //se o array estiver vazio
    if (quantidade == 0){
        puts("Lista vazia");
        return;
    }
    
    for (i = 0; i < quantidade; i++){
        //verificar genero do cliente e se está ativo
        if ((clientes[i].genero == 'M' || clientes[i].genero == 'm') && !clientes[i].inativo){
            contador++;
            printf("Nome        :   %s\n", clientes[i].nome);
            printf("Email       :   %s\n", clientes[i].email);
        }
    }
    
    //caso não existam clientes do genero masculino
    if (contador == 0){
        puts("Lista vazia");
        return;
    }
    
}


/*
 * Funcionalidade: Lista todos os clientes
 */
void listaClientes(Cliente * clientes, int quantidade){
    
    //declarar variáveis
    int i;
    
    //limpar consola
    clear(); //system("cls");
    
    puts("===========================================================");
    puts("=                         Clientes                        =");
    puts("===========================================================");
    
    if (quantidade == 0){
        puts("Lista vazia");
        return;
    }
    
    //listar todos os clientes guardados no array
    for (i = 0; i < quantidade; i++){
        //verificar se cliente está ativo
        if (clientes[i].inativo == false){  
            
            //mostar dados
            printf("Nome           :    %s\n", clientes[i].nome);
            printf("Email          :    %s\n", clientes[i].email);
            printf("Data nascimento:    %02d/ %02d/ %4d\n", clientes[i].dataNascimento.dia,
                                        clientes[i].dataNascimento.mes,
                                        clientes[i].dataNascimento.ano);
            puts("------------------------------------------------------");
        }
        
        
        
    }
    
}


/*
 * Funcionalidade: Mostra ficha de cliente
 */
void mostraFichaCliente(Cliente cliente){
    
    //limpar consola
    clear(); //system("cls");
            
    puts("===========================================================");
    puts("=                    Ficha Cliente                        =");
    puts("===========================================================");
    
    //mostrar informação do cliente    
    printf("Nome           :    %s\n", cliente.nome);
    puts("------------------------------------------------------");
    printf("Email          :    %s\n", cliente.email);
    printf("Genero         :    %c\n", cliente.genero);
    printf("Data nascimento:    %02d/ %02d/ %4d\n", cliente.dataNascimento.dia,
                                    cliente.dataNascimento.mes,
                                    cliente.dataNascimento.ano);
    puts("------------------------------------------------------");
}


/*
 * Funcionalidade: pesquisa um cliente por nome
 */
int pesquisaClienteNome(Cliente *clientes, int quantidade, char *nome){
    
    //declarar variáveis
    int i = 0;
    
    //percorrer o array enquanto não encontra o nome
    while (i < quantidade && strcasecmp(clientes[i].nome, nome)!=0 && !clientes[i].inativo){
        i++;
    }
    
    //se cliente não existe o incrementador toma o valor da quantidade
    if (i >= quantidade)
        return -1;
    
    //retornar posicao do array onde o cliente está guardado
    return i;
}


/*
 * Funcionalidade: Ordena um array de clientes por nome ascendentemente
 */
void ordenaClientesNomeAscendente(Cliente *clientes, int quantidade){
    int i, j;
    Cliente aux;
       
    for (i = 0; i < quantidade - 1; i++){
        for (j = i + 1; j < quantidade; j++){
            //verificar necessidade de troca de valores
            if (strcmp(clientes[i].nome, clientes[j].nome) > 0){
                aux = clientes[i];
                clientes[i] = clientes[j];
                clientes[j] = aux;
            }
        }
    }
}