/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   header.h
 * Author: martamartinho
 *
 * Created on 13 de Dezembro de 2018, 10:31
 */

#ifndef HEADER_H
#define HEADER_H

/*
    DEFINIÇÕES
    > Na definição de padrões foi forçado um numero fixo para representação de inteiros no ficheiro,
      para permitir que, caso estes valores passem a usar mais que uma casa (ex: 12 -> 8372) tal 
      alteração não signifique a o novo registo escreva por cima do registo seguinte!

    > O tamanho da linha é importante para uso no fseek(), ou seja, para facilitar o posicionamento
      do apontador o ficheiro.
*/
#define FICHEIRO "clientes.txt"
#define LINHA_ESCRITA "%4d,%50s,%5c,%50s,%02d/%02d/%4d,%d,%4d\n"
#define LINHA_LEITURA "%4d,%50s,%5c,%50s,%02d/%02d/%4d,%d,%4d\n"
#define LINHA_TAMANHO 131
#define clear() printf("\033[H\033[J")

//enumeravel para valores logicos
typedef enum bool{
    false,
    true,
}bool;


//estrutura para descrição de uma data
typedef struct data{
    int dia;
    int mes;
    int ano;
}Data;


//estrutura para descrição de um tratamento
typedef struct tratamento{
    char descricao[200];
    float preco;
    int codigoCliente;
    Data dataTratamento;
}Tratamento;


//estrutura para descrição de um cliente
typedef struct cliente{
    int codigo;
    char nome[100];
    char genero; // M/F
    char email[100];
    Data dataNascimento;
    Tratamento tratamentos[50];
    int quantidadeTratamentos;
    bool inativo;
}Cliente;

/*
 * Funcionalidade: cria um novo cliente
 */
Cliente novoCliente();


/*
 * Funcionalidade: elimina/inativa um cliente
 */
void eliminaCliente(Cliente *clientes, int posicao);


/*
 * Funcionalidade: cria/insere Clientes no array
 */
int insereClientes(Cliente * clientes, int quantidade, int tamanho);


/*
 * Funcionalidade: Lista clientes do genero masculino
 */
void listaClientesMasculino(Cliente * clientes, int quantidade);

/*
 * Funcionalidade: Lista todos os clientes
 */
void listaClientes(Cliente * clientes, int quantidade);


/*
 * Funcionalidade: Mostra ficha de cliente
 */
void mostraFichaCliente(Cliente cliente);


/*
 * Funcionalidade: pesquisa um cliente por nome
 */
int pesquisaClienteNome(Cliente *clientes, int quantidade, char *nome);


/*
 * Funcionalidade: Ordena um array de clientes por nome ascendentemente
 */
void ordenaClientesNomeAscendente(Cliente *clientes, int quantidade);



/*
 * Funcionalidade: cria dados teste
 */
int carregaDadosTeste(Cliente * clientes);


/*
 * Funcionalidade: insere um novo tratamento para um cliente
 */
void insereNovoTratamento(Cliente *cliente);

/*
 * Funcionalidade: lista tratamentos de um cliente
 */
void listaTratamentos(Cliente cliente);



#endif /* HEADER_H */

