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
    Job* CriaJob(int id){
        Job* novoJob = (Job*)malloc(sizeof(Job));
        if(novoJob == NULL) return NULL; // Se não há memória
            
        novoJob->id = id;
        novoJob->operacoes = NULL;
        novoJob->nextJob = NULL;

        return novoJob;
    }

    /**
     * Insere um job
     * @param [in] jobsHeader 
     * @param [in] novoJob
     * @param [out] jobsHeader	//Retorna o header job
    */
    Job* InsereJob(Job* jobsHeader, Job* novoJob){
        if (jobsHeader == NULL){
            jobsHeader = novoJob;
        }
        else{
            Job* auxJobs = jobsHeader;
            Job* auxAnt = NULL;
            while(auxJobs && auxJobs->id < novoJob->id){
                auxAnt = auxJobs;
                auxJobs = auxJobs->nextJob;
            }
            if(auxAnt == NULL){
                novoJob->nextJob = jobsHeader;
                jobsHeader = novoJob;
            }
            else{
                auxAnt->nextJob = novoJob;
                novoJob->nextJob = auxJobs;
            }
        }

        return jobsHeader;
    }

    /**
     * Mostra a lista de jobs e operações e máquinas
     * @param [in] jobsHeader
    */
    void MostraListaJobs(Job* jobsHeader){
        Job* auxJobs = jobsHeader;
        printf("Jobs:\n");
        while(auxJobs != NULL){
            printf("ID: %d\n", auxJobs->id);
            MostraListaOperacoes(jobsHeader->operacoes);
            auxJobs = auxJobs->nextJob;
        }
    }

#pragma endregion