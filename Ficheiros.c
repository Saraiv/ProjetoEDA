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

bool gravarBinario(char* nomeFicheiro, Job* headJob){
	if (headJob == NULL) return false;
	FILE* fp;
	if ((fp = fopen(nomeFicheiro, "wb")) == NULL) return false;
	
	Job* auxJob = headJob;
	JobFile auxFileJogo;

	while (auxJob != NULL){
		auxFileJogo.id = auxJob->id;
		fwrite(&auxFileJogo, sizeof(JobFile), 1, fp);
		auxJob = auxJob->nextJob;
	}
	fclose(fp);

	return true;
}

Job* lerBinario(char* nomeFicheiro){
	FILE* fp;
	Job* headJob = NULL;
	Job* auxJob;

	if ((fp = fopen(nomeFicheiro, "rb")) == NULL) return NULL;
	JobFile auxFileJob;
	while (fread(&auxFileJob, sizeof(Job), 1, fp)){
		auxJob = CriaJob(auxFileJob.id);
		headJob = InsereJob(headJob, auxJob);
	}
	fclose(fp);

	return headJob;
}