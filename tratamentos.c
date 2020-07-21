/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"


void insereNovoTratamento(Cliente *cliente){
    
    //limpar consola
    clear(); //system("cls");
    puts("===========================================================");
    puts("=                   Criar Tratamento                       =");
    puts("===========================================================");
    
    (*cliente).tratamentos[(*cliente).quantidadeTratamentos].codigoCliente = (*cliente).codigo;
    printf("Descrição: ");
    scanf("%s", (*cliente).tratamentos[(*cliente).quantidadeTratamentos].descricao);
    getchar();//fflush(stdin);
    printf("Preco: ");
    scanf("%f", &((*cliente).tratamentos[(*cliente).quantidadeTratamentos].preco));
    printf("Dia: ");
    scanf("%d", &((*cliente).tratamentos[(*cliente).quantidadeTratamentos].dataTratamento.dia));
    printf("Mes: ");
    scanf("%d", &((*cliente).tratamentos[(*cliente).quantidadeTratamentos].dataTratamento.mes));
    printf("Ano: ");
    scanf("%d", &((*cliente).tratamentos[(*cliente).quantidadeTratamentos].dataTratamento.ano));
    (*cliente).quantidadeTratamentos++;
}

void listaTratamentos(Cliente cliente){
    
    int i;//limpar consola
    
    clear(); //system("cls");
    puts("===========================================================");
    puts("=                   Listar Tratamentos                    =");
    puts("===========================================================");
    
    //mostrar informação do cliente    
    printf("Codigo  :   %02d\n", cliente.codigo);
    printf("Nome    :   %s\n", cliente.nome);
    puts("*******************************************************");
    puts("");
    for (i = 0; i < cliente.quantidadeTratamentos; i++){
        
        printf("Descrição:  %s\n", cliente.tratamentos[i].descricao);
        printf("Preco:      %.2f\n", cliente.tratamentos[i].preco);
        printf("Dia:        %02d/ %02d/ %4d\n", cliente.tratamentos[i].dataTratamento.dia,
                                        cliente.tratamentos[i].dataTratamento.mes,
                                        cliente.tratamentos[i].dataTratamento.ano);
        puts("------------------------------------------------------");
    }
    
}