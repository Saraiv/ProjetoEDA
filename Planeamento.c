/**
 * Author: Saraiva 
 * Email: mainsaraiva@gmail.com
 * Github: Saraiv
 * Date: 01/06/2022
 * Description: Módulo de implementação do trabalho prático 1.
 *              Trabalho prático 1 - EDA.
 * Class: x
*/

//          t e m p o
//          t1   t2   t3   t4
//   m  m1 O1J1 O1J1 O1J1
//   a  m2
//   q  m3 O1J2 01J2      O2J1 O2J1 O2J1
//   u  m4
//   i  m5           O2J2 O2J2 O2J2 O2J2
//   n
//   a
//   s
//


#include<stdbool.h>
#include<stdlib.h>
#include<stdio.h>
#include"Program.h"

#pragma region Planeamento

    /**
     * Inicia a matriz para o plano
     * @param [in] plano
     * @param [in] idJob
     * @param [in] idOperacao
    */
    void IniciaPlano(Plano plano[][TEMPO], int idJob, int idOperacao){
        for (int idMaquina = 0; idMaquina < MAX; idMaquina++)
            for (int tempo = 0; tempo < TEMPO; tempo++){
                plano[idMaquina][tempo].idJob = idJob;
                plano[idMaquina][tempo].idOperacao = idOperacao;
            }
    }

    /**
     * Ocupa uma célula no plano
     * @param [in] plano
     * @param [in] idMaquina
     * @param [in] tempo
     * @param [in] idJob
     * @param [in] idOperacao
    */
    void OcupaUm(Plano plano[][TEMPO], int idMaquina, int tempo, int idJob, int idOperacao){
        plano[idMaquina][tempo].idMaquina = idMaquina;
        plano[idMaquina][tempo].tempo = tempo;
        plano[idMaquina][tempo].idJob = idJob;
        plano[idMaquina][tempo].idOperacao = idOperacao;
    }

    /**
     * Lista a matriz de planeamento
     * @param [in] plano
    */
    void MostarPlano(Plano plano[][TEMPO]){
        for (int idMaquina = 0; idMaquina < MAX; idMaquina++){
            printf("m%d:\n", idMaquina + 1);
            for (int tempo = 0; tempo < TEMPO; tempo++){
                printf("tempo %d: ", tempo + 1);
                printf("Maquina: %d Tempo: %d\n", plano[idMaquina][tempo].idMaquina, plano[idMaquina][tempo].tempo);
            }
            printf("\n");
        }
    }

#pragma endregion