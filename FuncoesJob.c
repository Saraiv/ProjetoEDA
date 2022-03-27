/**
 * Author: Saraiva 
 * Email: mainsaraiva@gmail.com
 * Github: Saraiv
 * Date: 18/03/2022
 * Description: Módulo de implementação do trabalho prático 1.
 *              Trabalho prático 1 - EDA.
 * Class: x
*/

#include<stdbool.h>
#include<stdlib.h>
#include<stdio.h>
#include"Program.h"

#pragma region FuncoesJobs

    /**
     * Cria um job
     * @param [in] id
     * @param [in] operacao
     * @param [out] novoJob	//Retorna o job aqui criado
    */
    Job* CriaJob(int id, ListaOperacoes* operacao){
        Job* novoJob = (Job*)malloc(sizeof(Job));
        if(novoJob == NULL) return NULL; // Se não há memória
            
        novoJob->id = id;
        novoJob->operecao = operacao;
        novoJob->nextJob = NULL;

        return novoJob;
    }

    /**
     * Insere um job
     * @param [in] jobHeader 
     * @param [in] novoJob
     * @param [out] jobHeader	//Retorna o header job
    */
    Job* InsereJob(Job* jobHeader, Job* novoJob){
        if(jobHeader == NULL){
            jobHeader = novoJob;
        } else{
            novoJob->nextJob = jobHeader;
		    jobHeader = novoJob;
        }

        return jobHeader;
    }

    void MostraListaJobs(Job* jobsHeader){
        Job* auxJobs = jobsHeader;
        printf("Jobs:\n");
        while(auxJobs != NULL){
            printf("ID: %d\n", auxJobs->id);
            auxJobs = auxJobs->nextJob;
        }
    }

#pragma endregion