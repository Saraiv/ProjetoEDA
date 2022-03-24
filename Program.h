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

/*
NOTAS:
    Job -> Operações -> Várias Máquinas
    Cada Job tem:
        Uma ou mais operações.
    Cada Operação tem:
        Um id da operação;
        Uma ou mais máquinas.
    Cada Máquina tem:
        Um id da máquina;
        Um tempo que a máquina demora a efetuar uma operação.
*/

#ifndef FEITO
#define FEITO 1

    #pragma region Structs

        #define MAQUINAS 10
        #define OPERACOES 10

        typedef struct Operacao{
            int id;
            struct Maquina* maquinas;
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

        //Assinatura de funções ficheiros
        bool gravarBinario(char* nomeFicheiro, Job* headJob);
        Job* lerBinario(char* nomeFicheiro);

        //Assinatura de funções job
        Job* CriaJob(int id, Operacao* operacao);
        Job* InsereJob(Job* jobHeader, Job* novoJob);

        //Assinatura de funções máquinas
        Maquina* ProcuraMaquina(Maquina* maquinaHeader, int id);
        Maquina* CriaMaquina(int id, int tempo);
        Maquina* InsereMaquina(Maquina* maquinaHeader, Maquina* novaMaquina);
        

        //Assinatura de funções operações
        Operacao* ProcuraOperacao(Operacao* operacaoHeader, int id);
        bool ExisteOperacao(Operacao *operacaoHeader, int id);
        Operacao* CriaOperacao(int id, Maquina* maquinas);
        Operacao* InsereOperacao(Operacao* operacaoHeader, Operacao* novaOperacao);
        Operacao* RemoveOperacao(Operacao* operacaoHeader, int id);
        Operacao* AlterarOperacoes(Operacao* operacaoHeader, int id, int idMaquina, int tempoAMudar);
        int TempoMinimoOperacao(Operacao* operacaoHeader);
        int TempoMaximoOperacao(Operacao* operacaoHeader);
        int CountMaquinasNaOperacao(Operacao* operacaoHeader);
        int TempoMaximoOperacao(Operacao* operacaoHeader);
        float TempoMedioOperacao(Operacao* operacaoHeader);

    #pragma endregion

#endif