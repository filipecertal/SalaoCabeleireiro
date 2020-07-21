/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: martamartinho
 *
 * Created on 13 de Dezembro de 2018, 0:30
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

/*
 * 
 */
int main(int argc, char** argv) {

    
    //declarar variáveis
    Cliente clientes[10];
    int quantidade = 0;
    int opcao;
    char nome[100];
    int posicao;
    
    //carregar dados para teste
    quantidade = carregaDadosTeste(clientes);
    
    do{
        // limpar consola
        clear(); //system("cls");
        ///Escrever menu
        puts("===========================================================");
        puts("=                         MENU                            =");
        puts("===========================================================");
        puts("=                                                         =");
        puts("= 1................... Inserir clientes                   =");
        puts("= 2................... Apagar cliente                     =");
        puts("= 3................... Ficha cliente                      =");
        puts("= 4................... Listar clientes                    =");
        puts("= 5................... Inserir tratamentos                =");
        puts("= 6................... Listar tratamentos                 =");
        puts("= 7................... Sair                               =");
        puts("=                                                         =");
        puts("===========================================================");
        puts("");
        
        //recolher opção a executar
        puts("Insira uma opcao: ");
        scanf("%d", &opcao);
        
        switch(opcao){
            case 1:
                //inserir n clientes
                quantidade = insereClientes(clientes, quantidade, 10);
                getchar();
                break;
            case 2:
                clear(); //system("cls");
                puts("===========================================================");
                puts("=                Eliminar Cliente                         =");
                puts("===========================================================");
                
                //recolher nome a procurar
                printf("Insira o nome: ");
                scanf("%s", nome);
                
                //pesquisar posicao do cliente no array
                posicao = pesquisaClienteNome(clientes, quantidade, nome);
                
                //vericar se cliente existe
                if (posicao < 0 || clientes[posicao].inativo) 
                    puts("O cliente que procura não existe.");
                else{
                    //apagar cliente
                    eliminaCliente(clientes, posicao);
                    puts("Cliente eliminado com sucesso.");
                }
                break;
            case 3:
                clear(); //system("cls");
                puts("===========================================================");
                puts("=                 Ficha Cliente                           =");
                puts("===========================================================");
                
                //recolher nome a procurar
                printf("Insira o nome: ");
                scanf("%s", nome);
                
                //pesquisar posicao do cliente no array
                posicao = pesquisaClienteNome(clientes, quantidade, nome);
                
                //vericar se cliente existe
                if (posicao < 0 || clientes[posicao].inativo)
                    puts("O cliente que procura não existe.");
                else
                    //mostrar ficha do cliente
                    mostraFichaCliente(clientes[posicao]);
                    
                break;
            case 4:
                
                listaClientes(clientes, quantidade);
                
                break;
            case 5:
                clear(); //system("cls");
                puts("===========================================================");
                puts("=                Criar Tratamento                         =");
                puts("===========================================================");
                
                //recolher nome a procurar
                printf("Insira o nome: ");
                scanf("%s", nome);
                
                //pesquisar posicao do cliente no array
                posicao = pesquisaClienteNome(clientes, quantidade, nome);
                
                //vericar se cliente existe
                if (posicao < 0 || clientes[posicao].inativo) 
                    puts("O cliente que procura não existe.");
                else{
                    //inserir tratamento
                    insereNovoTratamento(&clientes[posicao]);
                }
                
                break;
            case 6:
                clear(); //system("cls");
                puts("===========================================================");
                puts("=               Listar Tratamentos                        =");
                puts("===========================================================");
                
                //recolher nome a procurar
                printf("Insira o nome: ");
                scanf("%s", nome);
                
                //pesquisar posicao do cliente no array
                posicao = pesquisaClienteNome(clientes, quantidade, nome);
                
                //vericar se cliente existe
                if (posicao < 0 || clientes[posicao].inativo) 
                    puts("O cliente que procura não existe.");
                else{
                    //listar tratamento
                    listaTratamentos(clientes[posicao]);
                }
                break;
            case 7:
                clear(); //system("cls");
                printf("Até breve!");
                break;
            default:
                clear(); //system("cls");
                printf("Opção invalida!");
                break;
        }
        
        
        getchar();
        getchar();
        
        
    }while(opcao != 7);
    
    return (EXIT_SUCCESS);
}

