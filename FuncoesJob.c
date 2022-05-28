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
#include<string.h>
#include"Program.h"

#pragma region FuncoesJobs

    /**
     * Cria um job
     * @param [in] id
     * @param [in] operacao
     * @param [out] novoJob	//Retorna o job aqui criado
    */
    Job* CriaJob(char* id){
        Job* novoJob = (Job*)malloc(sizeof(Job));
        if(novoJob == NULL) return NULL; // Se não há memória
            
        novoJob->id = strcpy(id, id);
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
        } else{
            novoJob->nextJob = jobsHeader;
            jobsHeader = novoJob;
        }

        return jobsHeader;
    }

    /**
     * Insere um nodo da lista jobs
     * @param [in] jobsHeader 
     * @param [in] novoJob
     * @param [out] jobsHeader	//Retorna o header job
    */
    Job* InsereNodoJob(Job* node, Job* jobsHeader){
        if (jobsHeader == NULL)
            jobsHeader = InsereJob(node, jobsHeader);
        else{
            printf("\n\n\n");
            Job* auxJob = jobsHeader;
            Job* auxJob2 = auxJob;

            while (auxJob != NULL && strcmp(auxJob->id, node->id) < 0){
                auxJob2 = auxJob;
                auxJob = auxJob->nextJob;
            }

            if (auxJob == jobsHeader){
                jobsHeader = InsereJob(node, jobsHeader);
            }

            else{
                if (auxJob == NULL){
                    auxJob2->nextJob = node;
                }
                else{
                    auxJob2->nextJob = node;
                    node->nextJob = auxJob;
                }
            }
        }
        return jobsHeader;
    }

    /**
     * Procura o job por id
     * @param [in] id
     * @param [in] jobsHeader
     * @param [out] jobsHeader	//Retorna o header job
    */
    Job* ProcuraJob(char *id, Job* jobsHeader){
        if (!jobsHeader) return NULL;
        Job* auxJobs = jobsHeader;
        while (auxJobs != NULL && strcmp(auxJobs->id, id) != 0) auxJobs = auxJobs->nextJob;
        return auxJobs;
    }

    /**
     * Mostra a lista de jobs e operações e máquinas
     * @param [in] jobsHeader
    */
    void MostraListaJobs(Job* jobsHeader){
        Job* auxJobs = jobsHeader;
        while(auxJobs != NULL){
            printf("-----------------------------------------\n");
            printf("ID Job: %s\n", auxJobs->id);
            MostraListaOperacoes(jobsHeader->operacoes);
            auxJobs = auxJobs->nextJob;
        }
    }

#pragma endregion

#pragma region Ficheiros

    /**
     * Escreve em ficheiros .bin os elementos da hashtable jobs
     * @param [in] jobsHeader
     * @param [out] bool	//Retorna se a ação foi bem sucessida ou não
    */
    bool GravaJob(Job* jobsHeader){
        FILE *file;

        if (jobsHeader == NULL) return false;

        if ((file = fopen("jobs.bin", "wb")) == NULL){
            return false;
        }

        Job* auxJob = jobsHeader;
        Job* nextJob;
        while (auxJob != NULL) {
            nextJob = auxJob->nextJob;
            auxJob->nextJob = NULL;
            fseek(file, 0, SEEK_END);
            fwrite(auxJob, sizeof(Job), 1, file);
            auxJob = nextJob;
            nextJob = NULL;
        }
        
        fclose(file);
        file = NULL;
        return true;
    }

#pragma endregion