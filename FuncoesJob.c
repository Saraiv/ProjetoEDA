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
     * Remover o Job
     * @param [in] jobsHeader 
     * @param [in] id 
     * @param [out] jobsHeader	//Retorna o header da lista de jobs, mas com o job já removido
    */
    Job* RemoveJob(Job* jobsHeader, char* id){
        if (jobsHeader == NULL) return NULL; //Lista vazia

        if (strcmp(jobsHeader->id, id)){		//remove no inicio da lista
            Job* auxJob = jobsHeader;
            jobsHeader = jobsHeader->nextJob;
            free(auxJob);
        }
        else{
            Job* auxJob = jobsHeader;
            Job* auxAnt = auxJob;
            while (auxJob && !strcmp(auxJob->id, id)){	//procura para revover
                auxAnt = auxJob;
                auxJob = auxJob->nextJob;
            }
            if (auxJob != NULL) {					//se encontrou, remove
                auxAnt->nextJob = auxJob->nextJob;
                free(auxJob);
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
        while(auxJobs != NULL){
            printf("-----------------------------------------\n");
            printf("ID Job: %s\n", auxJobs->id);
            MostraListaOperacoes(jobsHeader->operacoes);
            auxJobs = auxJobs->nextJob;
        }
    }

#pragma endregion

#pragma region FicheirosJobs

    /**
     * Escreve num ficheiro .bin a estrutura job
     * @param [in] nomeFicheiro
     * @param [in] jobsHeader
     * @param [out] bool	//Retorna se a ação foi bem sucessida ou não
    */
    // bool GravarBinario(char* nomeFicheiro, Job* jobsHeader){
    //     if (jobsHeader == NULL) return false;
    //     FILE* fp;
    //     if ((fp = fopen(nomeFicheiro, "wb")) == NULL) return false;
        
    //     Job* auxJob = jobsHeader;
    //     JobFile auxFileJob;

    //     while (auxJob != NULL){
    //         auxFileJob.idJob = auxJob->id;
    //         ListaOperacoes* auxOperacoes = auxJob->operacoes;
    //         while(auxOperacoes != NULL){
    //             auxFileJob.idOperacao = auxOperacoes->operacao.id;
    //             ListaMaquinas* auxMaquinas = auxOperacoes->operacao.maquinas;
    //             while(auxMaquinas != NULL){
    //                 auxFileJob.idMaquina = auxMaquinas->maquina.id;
    //                 auxFileJob.tempo = auxMaquinas->maquina.tempo;
    //                 fwrite(&auxFileJob, sizeof(JobFile), 1, fp);
    //                 auxMaquinas = auxMaquinas->nextMaquinas;
    //             }
    //             auxOperacoes = auxOperacoes->nextOperacoes;
    //         }
    //         auxJob = auxJob->nextJob;
    //     }
    //     fclose(fp);

    //     return true;
    // }

    // Job* LerBinario(char* nomeFicheiro){
    //     FILE* fp;
    //     Job* jobsHeader = NULL;
    //     Maquina* auxMaquina = NULL;
    //     Operacao* auxOperacao = NULL;

    //     Job* auxJob;

    //     if ((fp = fopen(nomeFicheiro, "rb")) == NULL) return NULL;
    //     JobFile auxFileJob;
    //     while (fread(&auxFileJob, sizeof(Job), 1, fp)){
    //         auxMaquina = CriaMaquina(auxFileJob.idMaquina, auxFileJob.tempo);
    //         auxOperacao = CriaOperacao(auxFileJob.idOperacao);
    //         auxOperacao->maquinas = InsereNaListaDeMaquinas(auxOperacao->maquinas, auxMaquina);            
    //         auxJob = CriaJob(auxFileJob.idJob);

    //         auxJob->operacoes = InsereNaListaDeOperacoes(auxJob->operacoes, auxOperacao);

    //         jobsHeader = InsereJob(jobsHeader, auxJob);
    //     }
    //     fclose(fp);

    //     return jobsHeader;
    // }

#pragma endregion