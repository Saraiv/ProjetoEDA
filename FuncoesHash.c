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
        for (int i = 0; i < MAX; i++)
		    hashTable[i] = NULL;
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
        Job *auxHash = hashTable[key];
        if (auxHash == NULL)
            hashTable[key] = job;
        else
            hashTable[key] = InsereNodoJob(job, hashTable[key]);
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