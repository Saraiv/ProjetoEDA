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
     * Cria uma máquina
     * @param [in] id
     * @param [in] tempo
     * @param [out] novaMaquina	//Retorna a máquina aqui criada
    */
    Maquina* CriaMaquina(int id, int tempo){
        Maquina* novaMaquina = (Maquina*)malloc(sizeof(Maquina));
        if (novaMaquina == NULL) return NULL; // Se não há memória
            
        novaMaquina->id = id;
        novaMaquina->tempo = tempo;
        novaMaquina->nextMaquina = NULL;

        return novaMaquina;
    }

    /**
     * Insere uma máquina
     * @param [in] maquinaHeader 
     * @param [in] novaMaquina
     * @param [out] maquinaHeader	//Retorna o header maquina
    */
    Maquina* InsereMaquina(Maquina* maquinaHeader, Maquina* novaMaquina){
        if (maquinaHeader == NULL){
            maquinaHeader = novaMaquina;
        }else{
            novaMaquina->nextMaquina = maquinaHeader;
            maquinaHeader = novaMaquina;
        }

        return maquinaHeader;
    }

    /**
     * Procura a máquina pretendida
     * @param [in] maquinaHeader 
     * @param [in] id
     * @param [out] aux	//Retorna a máquina que estava a procura
    */
    Maquina* ProcuraMaquina(Maquina* maquinaHeader, int id){
        if(maquinaHeader == NULL) return NULL; //Lista vazia

        Maquina* aux = maquinaHeader;
        while(maquinaHeader->nextMaquina != NULL){
            if(aux->id == id){
                return aux;
            }
        }

        return NULL;
    } 

#pragma endregion