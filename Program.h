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

        typedef struct Maquina{
            int id;
            int tempo;
            struct Maquina* nextMaquina;
        }Maquina;

        extern Maquina* headMaquina;

        typedef struct ListaMaquinas{
            struct Maquina maquina;
            struct ListaMaquinas* nextMaquinas;
        }ListaMaquinas;

        extern ListaMaquinas* headMaquinas;

        typedef struct Operacao{
            int id;
            struct ListaMaquinas* maquinas;
            struct Operacao* nextOperacao;
        }Operacao;

        extern Operacao* headOperacao;

        typedef struct ListaOperacoes{
            struct Operacao operacao;
            struct ListaOperacoes* nextOperacoes;
        }ListaOperacoes;

        extern ListaOperacoes* headOperacoes;

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
        bool ExisteMaquina(ListaMaquinas *maquinasHeader, int id);
        Maquina* CriaMaquina(int id, int tempo);
        ListaMaquinas* CriaNodoListaMaquinas(Maquina* novaMaquina);
        ListaMaquinas* InsereMaquina(ListaMaquinas* maquinaHeader, Maquina* novaMaquina);
        Maquina* ProcuraMaquina(ListaMaquinas* maquinaHeader, int id);
        int TempoMinimoMaquina(ListaMaquinas* maquinasHeader);
        int TempoMaximoMaquina(ListaMaquinas* maquinasHeader);

        //Assinatura de funções operações
        bool ExisteOperacao(ListaOperacoes *operacaoHeader, int id);
        Operacao* CriaOperacao(int id, ListaMaquinas* maquinasHeader);
        ListaOperacoes* CriaNodoListaOperacoes(Operacao* novaOperacao);
        ListaOperacoes* InsereOperacao(ListaOperacoes* operacoesHeader, Operacao* novaOperacao);
        Operacao* ProcuraOperacao(ListaOperacoes* operacaoHeader, int id);
        ListaOperacoes* RemoveOperacao(ListaOperacoes* operacoesHeader, int id);
        ListaOperacoes* AlterarOperacoes(ListaOperacoes* operacoesHeader, int idOperacao, int idMaquina, int tempoAMudar);
        int TempoMinimoOperacao(ListaOperacoes* operacoesHeader);
        int TempoMaximoOperacao(ListaOperacoes* operacoesHeader);
        int CountMaquinasNaOperacao(ListaOperacoes* operacoesHeader);
        float TempoMedioOperacao(ListaOperacoes* operacaoHeader);

    #pragma endregion

#endif