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

#define MAX 3

    #pragma region Structs

        typedef struct Maquina{
            int id;
            int tempo;
        }Maquina;

        typedef struct ListaMaquinas{
            struct Maquina maquina;
            struct ListaMaquinas* nextMaquinas;
        }ListaMaquinas;

        extern ListaMaquinas* maquinasHeader;

        typedef struct Operacao{
            int id;
            struct ListaMaquinas* maquinas;
        }Operacao;

        typedef struct ListaOperacoes{
            struct Operacao operacao;
            struct ListaOperacoes* nextOperacoes;
        }ListaOperacoes;

        extern ListaOperacoes* operacoesHeader;

        typedef struct Job{
            char* id;
            struct ListaOperacoes* operacoes;
            struct Job* nextJob;
        }Job;

        extern Job jobsHeader;

        typedef struct HashTable{
            int max;
            struct Job* tabela[MAX];
        }HashTable;

        typedef struct JobFile{
            int idJob;
            int idOperacao;
            int idMaquina;
            int tempo;
        }JobFile;

    #pragma endregion

    #pragma region AssinaturaDeFuncoes

        //Assinatura de funções ficheiros

        //Assinatura de funções job
        Job* CriaJob(char* id);
        Job* InsereJob(Job* jobsHeader, Job* novoJob);
        Job* InsereNodoJob(Job* node, Job* jobsHeader);
        void MostraListaJobs(Job* jobsHeader);

        //Assinatura de funções hash table
        void IniciaHash(Job *hashTable[]);
        int Key(char* id);
        void InsereNodoJobNaHash(Job* job, Job* hashTable[]);
        void MostrarHashTable(Job *hashTable[]);

        //Assinatura de funções máquinas
        bool ExisteMaquina(ListaMaquinas *maquinasHeader, int id);
        Maquina* CriaMaquina(int id, int tempo);
        ListaMaquinas* CriaNodoListaMaquinas(Maquina* novaMaquina);
        ListaMaquinas* InsereNaListaDeMaquinas(ListaMaquinas* maquinaHeader, Maquina* novaMaquina);
        Maquina* ProcuraMaquina(ListaMaquinas* maquinaHeader, int id);
        int TempoMinimoMaquina(ListaMaquinas* maquinasHeader);
        int TempoMaximoMaquina(ListaMaquinas* maquinasHeader);
        void MostraListaMaquinas(ListaMaquinas* maquinasHeader);

        //Assinatura de funções operações
        bool ExisteOperacao(ListaOperacoes *operacaoHeader, int id);
        Operacao* CriaOperacao(int id);
        ListaOperacoes* CriaNodoListaOperacoes(Operacao* novaOperacao);
        ListaOperacoes* InsereNaListaDeOperacoes(ListaOperacoes* operacoesHeader, Operacao* novaOperacao);
        Operacao* ProcuraOperacao(ListaOperacoes* operacoesHeader, int id);
        ListaOperacoes* RemoveOperacao(ListaOperacoes* operacoesHeader, int id);
        ListaOperacoes* AlterarOperacoes(ListaOperacoes* operacoesHeader, int idOperacao, int idMaquina, int tempoAMudar);
        int TempoMinimoOperacao(ListaOperacoes* operacoesHeader);
        int TempoMaximoOperacao(ListaOperacoes* operacoesHeader);
        int CountMaquinasNaOperacao(ListaOperacoes* operacoesHeader);
        float TempoMedioOperacao(ListaOperacoes* operacoesHeader);
        void MostraListaOperacoes(ListaOperacoes* operacoesHeader);

    #pragma endregion

#endif