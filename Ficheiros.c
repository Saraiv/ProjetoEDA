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

bool gravarJobBinario(char* nomeFicheiro, Job* headJob) {
	FILE* fp;

	if (headJob == NULL) return false;
	if ((fp = fopen(nomeFicheiro, "wb")) == NULL) return false;
	//grava n registos no ficheiro
	Job* auxJob = headJob;
	while (auxJob) {		//while(aux!=NULL)
		fwrite(auxJob, sizeof(Job), 1, fp);
		auxJob = auxJob->nextJob;
	}
	fclose(fp);
	return true;
}

