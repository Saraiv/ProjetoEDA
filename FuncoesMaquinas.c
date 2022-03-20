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
     * @param [in] id // ID que a máquina vai ficar
     * @param [in] tempo // Tempo que demora
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
    Maquina* InsereMaquina(Maquina* maquinaHeader, Maquina* novaMaquina) {
        if (maquinaHeader == NULL){
            maquinaHeader = novaMaquina;
        }else{
            novaMaquina->nextMaquina = maquinaHeader;	//aponta para onde "h" est� a apontar
            maquinaHeader = novaMaquina;
        }

        return maquinaHeader;
    }

#pragma endregion