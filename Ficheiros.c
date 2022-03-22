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

bool gravarBinarioMaquina(char* nomeFicheiro, Maquina* headMaquina){
	FILE* fp;

	if (headMaquina == NULL) return false;
	if ((fp = fopen(nomeFicheiro, "wb")) == NULL) return false;
	Maquina* auxMaquina = headMaquina;
	while (auxMaquina != NULL){
		fwrite(auxMaquina, sizeof(Maquina), 1, fp);
		auxMaquina = auxMaquina->nextMaquina;
	}
	fclose(fp);
	
	return true;
}

Maquina* lerBinarioMaquina(char* nomeFicheiro){
	FILE* fp;
	Maquina* headMaquina = NULL;
	Maquina* auxMaquina;

	if ((fp = fopen(nomeFicheiro, "rb")) == NULL) return NULL;
	auxMaquina = (Maquina*)malloc(sizeof(Maquina));
	while (fread(auxMaquina, sizeof(Maquina), 1, fp)){
		headMaquina = InsereMaquina(headMaquina, auxMaquina);
		headMaquina = (Maquina*)malloc(sizeof(Maquina));
	}
	fclose(fp);

	return headMaquina;
}