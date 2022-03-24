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
     * Procura a operação pretendida
     * @param [in] operacaoHeader 
     * @param [in] id
     * @param [out] aux	//Retorna a operação que era procurada
    */
    Operacao* ProcuraOperacao(Operacao* operacaoHeader, int id){
        if(operacaoHeader == NULL) return NULL; //Lista vazia

        Operacao* aux = operacaoHeader;
        while(operacaoHeader->nextOperacao != NULL){
            if(aux->id == id){
                return aux;
            }
        }

        return NULL;
    }

    /**
     * Verifica se o jogo existe
     * @param [in] operacaoHeader 
     * @param [in] id
     * @param [out] bool //Retorna se encontrou um jogo existente ou não
    */
    bool ExisteOperacao(Operacao *operacaoHeader, int id){
        if (operacaoHeader == NULL) return false;

        Operacao* aux = operacaoHeader;
        while (aux != NULL) {
            if (aux->id == id)
                return true;
            aux = aux->nextOperacao;
        }

        return false;
    }

    /**
     * Cria uma operacao
     * @param [in] id
     * @param [in] nomeDaOperacao
     * @param [out] novaOperacao	//Retorna a máquina aqui criada
    */
    Operacao* CriaOperacao(int id, Maquina* maquinas){
        Operacao* novaOperacao = (Operacao*)malloc(sizeof(Operacao));
        if (novaOperacao == NULL) return NULL; // Se não há memória
            
        novaOperacao->id;
        novaOperacao->maquinas = maquinas;
        // InsereMaquina(*novaOperacao->maquinas, maquinas);
        novaOperacao->nextOperacao = NULL;

        return novaOperacao;
    }

    /**
     * Insere uma operação
     * @param [in] operacaoHeader 
     * @param [in] novaOperacao 
     * @param [out] operacaoHeader	//Retorna a máquina aqui criada
    */
    Operacao* InsereOperacao(Operacao* operacaoHeader, Operacao* novaOperacao){
        if(!ExisteOperacao(operacaoHeader, novaOperacao->id)) return NULL; // Se não exister a operação
        
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
    Operacao* RemoveOperacao(Operacao* operacaoHeader, int id){
        if (operacaoHeader == NULL) return NULL; //Lista vazia
        if(!ExisteOperacao(operacaoHeader, id)) return NULL; // Se não existir a operação
        
        Operacao* auxOperacao = operacaoHeader;
        Operacao* auxAnterior = NULL;

        while (auxOperacao && auxOperacao->id != id){
            auxAnterior = auxOperacao;
            auxOperacao = auxOperacao->nextOperacao;
        }
        if (auxAnterior == NULL){ // Se estiver no fim p.e.
            operacaoHeader = operacaoHeader->nextOperacao;
            free(auxOperacao);
        }
        else{ // Se estiver no meio p.e.
            auxAnterior->nextOperacao = auxOperacao->nextOperacao;
            free(auxOperacao);
        }
        
        return operacaoHeader;
    }

    /**
     * Alterar operações
     * @param [in] operacaoHeader 
     * @param [in] id
     * @param [in] tempoAMudar
     * @param [in] idMaquina
     * @param [out] operacaoHeader	//Retorna o header das operações alterada
    */
    Operacao* AlterarOperacoes(Operacao* operacaoHeader, int id, int idMaquina, int tempoAMudar){
        if(operacaoHeader == NULL) return NULL; //Lista vazia
        if(!ExisteOperacao(operacaoHeader, id)) return NULL; // Se não existir a operação

        int i;
        Operacao* operacaoPretendida = ProcuraOperacao(operacaoHeader, id);
        if(operacaoPretendida != NULL){
            i = 0;
            Maquina* maquinaPretendida = ProcuraMaquina(operacaoHeader->maquinas, idMaquina);
            if(maquinaPretendida != NULL){
                maquinaPretendida->tempo = tempoAMudar;
            }
            i++;
        }

        return operacaoHeader;
    }

    /**
     * Tempo mínimo da operação
     * @param [in] operacaoHeader 
     * @param [out] operacaoHeader	//Retorna a soma do tempos minimos
    */
    int TempoMinimoOperacao(Operacao* operacaoHeader){
        if (operacaoHeader == NULL) return -1;
        int tempoMinimo, somaTempoMinimo = 0, i;

        Operacao* auxOperacao = operacaoHeader;
        while(auxOperacao != NULL){
            i = 0;
            Maquina* tempAux = auxOperacao->maquinas;
            while(tempAux->nextMaquina != NULL){
                tempoMinimo = 100;
                if (tempAux->tempo == tempoMinimo)
                    tempoMinimo = tempAux->tempo;
            }
            i++;
            somaTempoMinimo += tempoMinimo;
            auxOperacao = auxOperacao->nextOperacao;
        }
        
        return somaTempoMinimo;
    }

    /**
     * Tempo máximo da operação
     * @param [in] operacaoHeader
     * @param [out] operacaoHeader	//Retorna a soma do tempos máximos
    */
    int TempoMaximoOperacao(Operacao* operacaoHeader){
        if (operacaoHeader == NULL) return -1;
        int tempoMaximo, somaTempoMaximo = 0;

        int i;
        Operacao* auxOperacao = operacaoHeader;
        while(auxOperacao != NULL){
            i = 0;
            Maquina* tempAux = auxOperacao->maquinas;
            while(tempAux->nextMaquina != NULL){
                tempoMaximo = 0;
                if (tempAux->tempo == tempoMaximo)
                    tempoMaximo = tempAux->tempo;
            }
            i++;
            somaTempoMaximo += tempoMaximo;
            auxOperacao = auxOperacao->nextOperacao;
        }
        
        return somaTempoMaximo;
    }

    /**
     * Count de quantas máquinas tem cada operação
     * @param [in] operacaoHeader
     * @param [out] operacaoHeader	//Retorna quantas máquinas tem todas as operações
    */
    int CountMaquinasNaOperacao(Operacao* operacaoHeader){
        if (operacaoHeader == NULL) return -1;
        int count = 0, i;

        Operacao* auxOperacao = operacaoHeader;
        while(auxOperacao != NULL){
            i = 0;
            Maquina* tempAux = auxOperacao->maquinas;
            while(tempAux->nextMaquina != NULL){
                count++;
            }
            auxOperacao = auxOperacao->nextOperacao;
        }
        
        return count;
    }

    /**
     * Tempo médio da operação
     * @param [in] operacaoHeader
     * @param [out] operacaoHeader	//Retorna o tempo médio do tempo das máquinas
    */
    float TempoMedioOperacao(Operacao* operacaoHeader){
        if (operacaoHeader == NULL) return -1;
        int soma = 0, i;
        float count = CountMaquinasNaOperacao(operacaoHeader);

        Operacao* auxOperacao = operacaoHeader;
        while(auxOperacao != NULL){
            i = 0;
            Maquina* tempAux = auxOperacao->maquinas;
            while(tempAux->nextMaquina != NULL){
                soma += tempAux->tempo;
            }
            auxOperacao = auxOperacao->nextOperacao;
        }
        
        return soma/count;
    }

#pragma endregion