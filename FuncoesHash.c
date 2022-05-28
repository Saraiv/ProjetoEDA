/**
 * Author: Saraiva 
 * Email: mainsaraiva@gmail.com
 * Github: Saraiv
 * Date: 20/05/2022
 * Description: Módulo de implementação do trabalho prático 1.
 *              Trabalho prático 1 - EDA.
 * Class: x
*/

#include<stdbool.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"Program.h"

#pragma region FuncoesHash

    /**
     * Inicia o ínicio de uma nova hash table
     * @param [in] hashTable
    */
    void IniciaHash(Job* hashTable[]){
        for (int i = 0; i < MAX; i++){
		    hashTable[i] = NULL;
            // hashTable[i]->id = NULL;
            // hashTable[i]->nextJob = NULL;
            // hashTable[i]->operacoes = NULL;
        }
    }

    /**
     * Determina a key necessária para inserir na hash table
     * @param [in] id
     * @param [out] key	//Retorna a key
    */
    int Key(char* id){
        int soma = 0;
        for (int i = 0; i < strlen(id); i++){
            soma += (int)id[i];
        }
        return soma % MAX;
    }

    /**
     * Insere o nodo Job recebido no incio da hash table
     * @param [in] job
     * @param [in] hashTable
    */
    void InsereNodoJobNaHash(Job* job, Job* hashTable[]){
        int key = Key(job->id);
        job->nextJob = hashTable[key];
        hashTable[key] = job;
    }

    /**
     * Procura em todos os nodos o job que quer por id
     * @param [in] id 
     * @param [in] hashTable
     * @param [out] Job	//Retorna o job
    */
    Job* ProcuraNode(char* id, Job* hashTable[]){
        int key = Key(id);
        if (hashTable[key] == NULL) return NULL;
        return ProcuraJob(id, hashTable[key]);
    }

    /**
     * Remover o Job
     * @param [in] id
     * @param [in] jobsHeader 
    */
    void RemoveJobNaHash(char* id, Job* hashTable[]){
        int key = Key(id);
        if (hashTable[key] == NULL) return;

        if(strcmp(hashTable[key]->id, id) == 0){ //remove no inicio da lista
            Job* auxJob = hashTable[key];
            hashTable[key] = hashTable[key]->nextJob;
            free(auxJob);
        }
        else{
            Job* auxJob = hashTable[key];
            Job* auxAnt = auxJob;
            while(auxJob && strcmp(auxJob->id, id) > 0){ //procura para revover
                auxAnt = auxJob;
                auxJob = auxJob->nextJob;
            }
            if(auxJob != NULL) { //se encontrou, remove
                auxAnt->nextJob = auxJob->nextJob;
                free(auxJob);
            }
        }
    }

    /**
     * Mostra a lista de jobs e operações e máquinas usando a hash table
     * @param [in] hashTable
    */
    void MostrarHashTable(Job *hashTable[]){
        for (int i = 0; i < MAX; i++){
            if (hashTable[i] != NULL){
                printf("Index: %d\n", i);
                MostraListaJobs(hashTable[i]);
                printf("\n");
            }
        }
    }

#pragma endregion

#pragma region FicheirosJobs

    /**
     * Escreve em ficheiros .bin os elementos da hashtable, ou seja jobs, operações e máquinas
     * @param [in] hashTable
     * @param [out] bool	//Retorna se a ação foi bem sucessida ou não
    */
    bool GravarBinario(Job* hashTable[]){
        bool jobs, operacoes, maquinas = false;
        for(int i = 0; i < MAX; i++) {
            if (hashTable[i] != NULL){
                //gravar jobs
                jobs = GravaJob(hashTable[i]);
                //gravar operações
                operacoes = GravaOperacoes(hashTable[i]->operacoes);
                //gravar máquinas
                maquinas = GravaMaquinas(hashTable[i]->operacoes->operacao.maquinas);
            }
        }
        return true;
    }

    /**
     * Exporta para um ficheiro .csv os elementos da hashtable, ou seja jobs, operações e máquinas
     * @param [in] hashTable
     * @param [out] bool	//Retorna se a ação foi bem sucessida ou não
    */
    bool ExportarCsv(Job* hashTable[]){
        if (hashTable == NULL) return false;
        FILE* file;
        int j = 0;
        if((file = fopen("exportar.csv", "w")) == NULL) return false;
        for(int i = 0; i < MAX; i++){
            if (hashTable[i] != NULL){
                Job* auxJobs = hashTable[i];
                while(auxJobs != NULL){
                    ListaOperacoes* auxOperacoes = hashTable[i]->operacoes;
                    while(auxOperacoes != NULL){
                        ListaMaquinas* auxMaquinas = auxOperacoes->operacao.maquinas;
                        while(auxMaquinas != NULL){
                            fprintf(file, "p%d,Maquina %d, Job %s - Oper %d,,,%d,0,\n", 
                                    ++j, auxMaquinas->maquina.id, auxJobs->id, auxOperacoes->operacao.id, 
                                    auxMaquinas->maquina.tempo);
                            auxMaquinas = auxMaquinas->nextMaquinas;
                        }
                        auxOperacoes = auxOperacoes->nextOperacoes;
                    }
                    auxJobs = auxJobs->nextJob;
                }
            }
        }
        fclose(file);
        return true;
    }

#pragma endregion