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
	FILE* fp;

	if (headJob == NULL) return false;
	if ((fp = fopen(nomeFicheiro, "wb")) == NULL) return false;
	Job* auxMaquina = headJob;
	while (auxMaquina != NULL){
		fwrite(auxMaquina, sizeof(Job), 1, fp);
		headJob = headJob->nextJob;
	}
	fclose(fp);
	
	return true;
}

Job* lerBinario(char* nomeFicheiro){
	FILE* fp;
	Job* headJob = NULL;
	Job* auxJob;

	if ((fp = fopen(nomeFicheiro, "rb")) == NULL) return NULL;
	auxJob = (Job*)malloc(sizeof(Job));
	while (fread(auxJob, sizeof(Job), 1, fp)){
		headJob = InsereJob(headJob, auxJob);
		headJob = (Job*)malloc(sizeof(Job));
	}
	fclose(fp);

	return headJob;
}