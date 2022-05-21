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
     * Verifica se a operação existe
     * @param [in] operacoesHeader 
     * @param [in] id
     * @param [out] bool //Retorna se encontrou um jogo existente ou não
    */
    bool ExisteOperacao(ListaOperacoes *operacoesHeader, int id){
        if (operacoesHeader == NULL) return false;

        ListaOperacoes* auxOperacoes = operacoesHeader;
        while (auxOperacoes != NULL) {
            if (auxOperacoes->operacao.id == id)
                return true;
            auxOperacoes = auxOperacoes->nextOperacoes;
        }

        return false;
    }

    /**
     * Cria uma operacao
     * @param [in] id
     * @param [in] maquinasHeader
     * @param [out] novaOperacao	//Retorna a máquina aqui criada
    */
    Operacao* CriaOperacao(int id){
        Operacao* novaOperacao = (Operacao*)malloc(sizeof(Operacao));
        if (novaOperacao == NULL) return NULL; // Se não há memória
            
        novaOperacao->id = id;
        novaOperacao->maquinas = NULL;

        return novaOperacao;
    }

    /**
    * Cria novo nodo para a lista de Operações
    * @param [in] novaOperacao
    * @param [out] novaLista para nodo criado
    */
    ListaOperacoes* CriaNodoListaOperacoes(Operacao* novaOperacao){
        ListaOperacoes* novaLista = (ListaOperacoes*)calloc(1, sizeof(ListaOperacoes));

        novaLista->operacao.id = novaOperacao->id;
        novaLista->operacao.maquinas = novaOperacao->maquinas;
        novaLista->nextOperacoes = NULL;

        return novaLista;
    }

    /**
     * Insere uma operação
     * @param [in] operacoesHeader 
     * @param [in] novaOperacao 
     * @param [out] operacoesHeader	//Retorna a máquina aqui criada
    */
    ListaOperacoes* InsereNaListaDeOperacoes(ListaOperacoes* operacoesHeader, Operacao* novaOperacao){
        ListaOperacoes* novaOperacaoCriada = CriaNodoListaOperacoes(novaOperacao);
        
        if (operacoesHeader == NULL){
            operacoesHeader = novaOperacaoCriada;
        }
        else{
            ListaOperacoes* auxOperacoes = operacoesHeader;
            ListaOperacoes* auxAnt = NULL;
            while(auxOperacoes && auxOperacoes->operacao.id < novaOperacaoCriada->operacao.id){
                auxAnt = auxOperacoes;
                auxOperacoes = auxOperacoes->nextOperacoes;
            }
            if(auxAnt == NULL){
                novaOperacaoCriada->nextOperacoes = operacoesHeader;
                operacoesHeader = novaOperacaoCriada;
            }
            else{
                auxAnt->nextOperacoes = novaOperacaoCriada;
                novaOperacaoCriada->nextOperacoes = auxOperacoes;
            }
        }

        return operacoesHeader;
    }

    /**
     * Procura a operação pretendida
     * @param [in] operacoesHeader 
     * @param [in] id
     * @param [out] aux	//Retorna a operação que era procurada
    */
    Operacao* ProcuraOperacao(ListaOperacoes* operacoesHeader, int id){
        if(operacoesHeader == NULL) return NULL; //Lista vazia

        ListaOperacoes* auxOperacoes = operacoesHeader;
        while(auxOperacoes != NULL){
            if(auxOperacoes->operacao.id == id){
                Operacao* newOperacao = CriaOperacao(auxOperacoes->operacao.id);
                return newOperacao;
            }
        }

        return NULL;
    }

    /**
     * Remover a operação
     * @param [in] operacoesHeader 
     * @param [in] id 
     * @param [out] operacoesHeader	//Retorna o header da lista de operações, mas com a operação já removida
    */
    ListaOperacoes* RemoveOperacao(ListaOperacoes* operacoesHeader, int id){
        if (operacoesHeader == NULL) return NULL; //Lista vazia
        // if(!ExisteOperacao(operacoesHeader, id)) return NULL; // Se não existir a operação

        if (operacoesHeader->operacao.id == id){		//remove no inicio da lista
            ListaOperacoes* auxOperacoes = operacoesHeader;
            operacoesHeader = operacoesHeader->nextOperacoes;
            free(auxOperacoes);
        }
        else{
            ListaOperacoes* auxOperacoes = operacoesHeader;
            ListaOperacoes* auxAnt = auxOperacoes;
            while (auxOperacoes && auxOperacoes->operacao.id != id) {	//procura para revover
                auxAnt = auxOperacoes;
                auxOperacoes = auxOperacoes->nextOperacoes;
            }
            if (auxOperacoes != NULL) {					//se encontrou, remove
                auxAnt->nextOperacoes = auxOperacoes->nextOperacoes;
                free(auxOperacoes);
            }
        }
        
        return operacoesHeader;
    }

    /**
     * Alterar operações
     * @param [in] operacoesHeader 
     * @param [in] id
     * @param [in] tempoAMudar
     * @param [in] idMaquina
     * @param [out] operacaoHeader	//Retorna o header daa lista de operações alterada
    */
    ListaOperacoes* AlterarOperacoes(ListaOperacoes* operacoesHeader, int idOperacao, int idMaquina, int tempoAMudar){
        if(operacoesHeader == NULL) return NULL; //Lista vazia
        ListaOperacoes* auxOperacoes = operacoesHeader;

        while(auxOperacoes != NULL){
            if(auxOperacoes->operacao.id == idOperacao){
                ListaMaquinas* auxMaquinas = auxOperacoes->operacao.maquinas;
                while(auxMaquinas != NULL){
                    if(auxMaquinas->maquina.id == idMaquina){
                        auxMaquinas->maquina.tempo = tempoAMudar;
                    }
                    auxMaquinas = auxMaquinas->nextMaquinas;
                }
            }
            auxOperacoes = auxOperacoes->nextOperacoes;
        }

        return operacoesHeader;
    }

    /**
     * Tempo mínimo da operação
     * @param [in] operacaoHeader 
     * @param [out] operacaoHeader	//Retorna a soma do tempos minimos
    */
    int TempoMinimoOperacao(ListaOperacoes* operacoesHeader){
        if (operacoesHeader == NULL) return 0;
        int  soma = 0;

        ListaOperacoes* auxOperacoes = operacoesHeader;
        while(auxOperacoes != NULL){
            soma += TempoMinimoMaquina(auxOperacoes->operacao.maquinas);
            auxOperacoes = auxOperacoes->nextOperacoes;
        }
        
        return soma;
    }

    /**
     * Tempo máximo da operação
     * @param [in] operacaoHeader
     * @param [out] operacaoHeader	//Retorna a soma do tempos máximos
    */
    int TempoMaximoOperacao(ListaOperacoes* operacoesHeader){
        if (operacoesHeader == NULL) return 0;
        int  soma = 0;

        ListaOperacoes* auxOperacoes = operacoesHeader;
        while(auxOperacoes != NULL){
            soma += TempoMaximoMaquina(auxOperacoes->operacao.maquinas);
            auxOperacoes = auxOperacoes->nextOperacoes;
        }
        
        return soma;
    }

    /**
     * Count de quantas máquinas tem cada operação
     * @param [in] operacoesHeader
     * @param [out] operacoesHeader	//Retorna quantas máquinas tem todas as operações
    */
    int CountMaquinasNaOperacao(ListaOperacoes* operacoesHeader){
        if (operacoesHeader == NULL) return 0;
        int count = 0;

        ListaOperacoes* auxOperacoes = operacoesHeader;
        ListaMaquinas* auxMaquinas = auxOperacoes->operacao.maquinas;
        while(auxMaquinas != NULL){
            count++;
            auxMaquinas = auxMaquinas->nextMaquinas;
        }
        
        return count;
    }

    /**
     * Tempo médio da operação
     * @param [in] operacoesHeader
     * @param [out] media	//Retorna o tempo médio do tempo das máquinas
    */
    float TempoMedioOperacao(ListaOperacoes* operacoesHeader){
        if (operacoesHeader == NULL) return 0;
        int soma = 0;
        float count = CountMaquinasNaOperacao(operacoesHeader);

        ListaOperacoes* auxOperacoes = operacoesHeader;
        ListaMaquinas* auxMaquinas = auxOperacoes->operacao.maquinas;
        while(auxMaquinas != NULL){
            soma += auxMaquinas->maquina.tempo;
            auxMaquinas = auxMaquinas->nextMaquinas;
        }
        auxOperacoes = auxOperacoes->nextOperacoes;
        
        return soma/count;
    }

    /**
     * Mostra a lista de operações e máquinas
     * @param [in] operacoesHeader
    */
    void MostraListaOperacoes(ListaOperacoes* operacoesHeader){
        ListaOperacoes* auxOperacoes = operacoesHeader;
        printf("Operacoes:\n");
        while(auxOperacoes != NULL){
            Operacao auxOperacao = auxOperacoes->operacao;
            printf("ID: %d\n", auxOperacao.id);
            MostraListaMaquinas(auxOperacao.maquinas);
            auxOperacoes = auxOperacoes->nextOperacoes;
        }
    }

#pragma endregion