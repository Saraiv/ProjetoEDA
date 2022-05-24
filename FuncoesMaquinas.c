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

#pragma region FuncoesMaquinas

    /**
     * Verifica se a maquina existe
     * @param [in] maquinasHeader
     * @param [in] id
     * @param [out] bool //Retorna se encontrou um jogo existente ou não
    */
    bool ExisteMaquina(ListaMaquinas *maquinasHeader, int id){
        if (maquinasHeader == NULL) return false;

        ListaMaquinas* aux = maquinasHeader;
        while (aux != NULL){
            if (aux->maquina.id == id)
                return true;
            aux = aux->nextMaquinas;
        }

        return false;
    }

    /**
     * Cria uma máquina
     * @param [in] id
     * @param [in] tempo
     * @param [out] novaMaquina	//Retorna a máquina aqui criada
    */
    Maquina* CriaMaquina(int id, int tempo){
        Maquina* novaMaquina = (Maquina*)malloc(sizeof(Maquina));
        if(novaMaquina == NULL) return NULL; // Se não há memória
            
        novaMaquina->id = id;
        novaMaquina->tempo = tempo;

        return novaMaquina;
    }

    /**
    * Cria novo nodo para a lista de Maquinas
    * @param [in] novaMaquina
    * @param [out] novaLista //Retorna uma nova lista para nodo criado
    */
    ListaMaquinas* CriaNodoListaMaquinas(Maquina* novaMaquina){
        ListaMaquinas* novaLista = (ListaMaquinas*)calloc(1, sizeof(ListaMaquinas));

        novaLista->maquina.id = novaMaquina->id;
        novaLista->maquina.tempo = novaMaquina->tempo;
        novaLista->nextMaquinas = NULL;

        return novaLista;
    }

    /**
     * Insere uma máquina
     * @param [in] maquinasHeader 
     * @param [in] novaMaquina
     * @param [out] maquinasHeader	//Retorna o header da lista de máquinas com a nova máquina inserida
    */
    ListaMaquinas* InsereNaListaDeMaquinas(ListaMaquinas* maquinasHeader, Maquina* novaMaquina){
        ListaMaquinas* novaMaquinaCriada = CriaNodoListaMaquinas(novaMaquina);

        if (maquinasHeader == NULL){
            maquinasHeader = novaMaquinaCriada;
        }
        else{
            ListaMaquinas* auxMaquinas = maquinasHeader;
            ListaMaquinas* auxAnt = NULL;
            while(auxMaquinas && auxMaquinas->maquina.id < novaMaquinaCriada->maquina.id){
                auxAnt = auxMaquinas;
                auxMaquinas = auxMaquinas->nextMaquinas;
            }
            if(auxAnt == NULL){
                novaMaquinaCriada->nextMaquinas = maquinasHeader;
                maquinasHeader = novaMaquinaCriada;
            }
            else{
                auxAnt->nextMaquinas = novaMaquinaCriada;
                novaMaquinaCriada->nextMaquinas = auxMaquinas;
            }
        }
        
        return maquinasHeader;
    }

    /**
     * Procura a máquina pretendida
     * @param [in] maquinasHeader 
     * @param [in] id
     * @param [out] newMaquina	//Retorna a cópia de uma nova máquina que estava a procura
    */
    Maquina* ProcuraMaquina(ListaMaquinas* maquinasHeader, int id){
        if(maquinasHeader == NULL) return NULL; //Lista vazia

        ListaMaquinas* auxMaquinas = maquinasHeader;
        while(auxMaquinas != NULL){
            if(auxMaquinas->maquina.id == id){
                Maquina* newMaquina = CriaMaquina(auxMaquinas->maquina.id, auxMaquinas->maquina.tempo);
                return newMaquina;
            }
            auxMaquinas = auxMaquinas ->nextMaquinas;
        }

        return NULL;
    }

    /**
     * Tempo mínimo de cada máquina em cada operação
     * @param [in] maquinasHeader
     * @param [out] tempoMinimo	//Retorna o tempo mínimo
    */
    int TempoMinimoMaquina(ListaMaquinas* maquinasHeader){
        if(maquinasHeader == NULL) return 0; //Lista vazia

        ListaMaquinas* auxMaquinas = maquinasHeader;
        int tempoMinimo = auxMaquinas->maquina.tempo;
        while(auxMaquinas != NULL){
            if(auxMaquinas->maquina.tempo < tempoMinimo)
                tempoMinimo = auxMaquinas->maquina.tempo;
            auxMaquinas = auxMaquinas->nextMaquinas;
        }

        return tempoMinimo;
    }

    /**
     * Tempo maximo de cada máquina em cada operação
     * @param [in] maquinasHeader
     * @param [out] tempoMaximo	//Retorna o tempo maximo
    */
    int TempoMaximoMaquina(ListaMaquinas* maquinasHeader){
        if(maquinasHeader == NULL) return 0; //Lista vazia

        ListaMaquinas* auxMaquinas = maquinasHeader;
        int tempoMaximo = auxMaquinas->maquina.tempo;
        while(auxMaquinas != NULL){
            if(auxMaquinas->maquina.tempo > tempoMaximo)
                tempoMaximo = auxMaquinas->maquina.tempo;
            auxMaquinas = auxMaquinas->nextMaquinas;
        }

        return tempoMaximo;
    }

    /**
     * Mostra todas as máquinas
     * @param [in] maquinasHeader
    */
    void MostraListaMaquinas(ListaMaquinas* maquinasHeader){
        ListaMaquinas* auxMaquinas = maquinasHeader;
        printf("Maquinas:\n");
        while(auxMaquinas != NULL){
            Maquina auxMaquina = auxMaquinas->maquina;
            printf("ID: %d - Tempo: %d\n", auxMaquina.id, auxMaquina.tempo);
            auxMaquinas = auxMaquinas->nextMaquinas;
        }
    }

#pragma endregion