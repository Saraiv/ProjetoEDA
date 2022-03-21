/**
 * Author: Saraiva 
 * Email: mainsaraiva@gmail.com
 * Github: Saraiv
 * Date: 18/03/2022
 * Description: Assinatura de funções e structs.
 *              Trabalho prático 1 - EDA.
 * Class: x
*/

#include<stdbool.h>
#include<stdlib.h>
#include<stdio.h>

#ifndef FEITO
#define FEITO 1

    #pragma region Structs

        #define MAQUINAS 10
        #define OPERACOES 10

        typedef struct Operacao{
            int id;
            struct Maquina* maquinas[MAQUINAS];
            struct Operacao* nextOperacao;
        }Operacao;

        extern Operacao* headOperacao;

        typedef struct Maquina{
            int id;
            int tempo;
            struct Maquina* nextMaquina;
        }Maquina;

        extern Maquina* headMaquina;

        typedef struct Job{
            int id;
            struct Operacao* operecao;
            struct Job* nextJob;
        }Job;

        extern Job* headJob;

    #pragma endregion

    #pragma region AssinaturaDeFuncoes

        //Assinatura de funções máquinas
        Maquina* CriaMaquina(int id, int tempo);
        Maquina* InsereMaquina(Maquina* maquinaHeader, Maquina* novaMaquina);

        //Assinatura de funções operações
        Operacao* CriaOperacao(int id, Maquina* maquinas);
        Operacao* InsereOperacao(Operacao* operacaoHeader, Operacao* novaOperacao);
        Operacao* RemoveOperacao(Operacao* operacaoHeader, int id);
        Operacao* AlterarOperacoes(Operacao* operacaoHeader);
        int TempoMinimoOperacao(Operacao* operacaoHeader);
        
    #pragma endregion

#endif