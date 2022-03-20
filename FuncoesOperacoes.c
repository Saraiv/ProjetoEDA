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

#pragma region FuncoesOperacoes

    /**
     * Cria uma operacao
     * @param [in] id // ID que a operação vai ficar
     * @param [in] nomeDaOperacao // Nome que a operação vai ficar
     * @param [out] novaOperacao	//Retorna a máquina aqui criada
    */
    Operacao* CriaOperacao(int id, Maquina* maquinas){
        Operacao* novaOperacao = (Operacao*)malloc(sizeof(Operacao));
        if (novaOperacao == NULL) return NULL; // Se não há memória
            
        novaOperacao->id;
        *novaOperacao->maquinas = maquinas;
        novaOperacao->nextOperacao = NULL;

        return novaOperacao;
    }

    /**
     * Insere uma operação
     * @param [in] operacaoHeader 
     * @param [in] novaOperacao 
     * @param [out] operacaoHeader	//Retorna a máquina aqui criada
    */
    Operacao* InsereOperacao(Operacao* operacaoHeader, Operacao* novaOperacao) {
        if (operacaoHeader == NULL){
            operacaoHeader = novaOperacao;
        }else{
            novaOperacao->nextOperacao = operacaoHeader;
            operacaoHeader = novaOperacao;
        }
        return operacaoHeader;
    }

    /**
     * Remover a operação
     * @param [in] operacaoHeader 
     * @param [in] id 
     * @param [out] operacaoHeader	//Retorna a máquina aqui criada
    */
    Operacao* RemoveOperacao(Operacao* operacaoHeader, int id) {

        if (operacaoHeader == NULL) return NULL; //Lista vazia

        Operacao* auxOperacao = operacaoHeader;
        Operacao* auxAnt = NULL;

        while (auxOperacao && auxOperacao->id != id) {
            auxAnt = auxOperacao;
            auxOperacao = auxOperacao->nextOperacao;
        }
        if (auxAnt == NULL){
            operacaoHeader = operacaoHeader->nextOperacao;
            free(auxOperacao);
        }
        else{
            auxAnt->nextOperacao = auxOperacao->nextOperacao;
            free(auxOperacao);
        }
        
        return operacaoHeader;
    }

    /**
     * Alterar operações
     * @param [in] operacaoHeader 
     * @param [in] id 
     * @param [out] operacaoHeader	//Retorna a máquina aqui criada
    */
    Operacao* AlterarOperacoes(Operacao* operacaoHeader){
        // TODO
    }

    /**
     * Tempo mínimo
     * @param [in] operacaoHeader 
     * @param [in] id 
     * @param [out] operacaoHeader	//Retorna a máquina aqui criada
    */
    int TempoMinimoOperacao(Operacao* operacaoHeader){
        int tempoMinimo, somaTempoMinimo = 0;
        if (operacaoHeader == NULL) return NULL;
        Operacao* auxOperacao = operacaoHeader;

        while (auxOperacao != NULL){
            Maquina* tempAux = auxOperacao->maquinas;
            while(tempAux->nextMaquina != NULL){
                tempoMinimo = 100;
                if (tempAux->tempo == tempoMinimo)
                    tempoMinimo = tempAux->tempo;
            }
            somaTempoMinimo += tempoMinimo;
            auxOperacao = auxOperacao->nextOperacao;
        }
        
        return somaTempoMinimo;
    }



#pragma endregion