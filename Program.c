/**
 * Author: Saraiva 
 * Email: mainsaraiva@gmail.com
 * Github: Saraiv
 * Date: 18/03/2022
 * Description: Programa Principal.
 *              Trabalho prático 1 - EDA.
 * Class: x
*/

#include "Program.h"

void main(){

    #pragma region CriacaoVariaveis
    
        Job* jobsHeader = NULL;

        // Maquinas
        Maquina* m1 = CriaMaquina(1, 4);
        Maquina* m2 = CriaMaquina(3, 5);

        //Operações
        Operacao* o1 = CriaOperacao(1);

        o1->maquinas = InsereNaListaDeMaquinas(o1->maquinas, m1);
        o1->maquinas = InsereNaListaDeMaquinas(o1->maquinas, m2);

        //Jobs
        Job* j1 = CriaJob(1);
        
        j1->operacoes = InsereNaListaDeOperacoes(j1->operacoes, o1);

        jobsHeader = InsereJob(jobsHeader, j1);

        // bool ficheiro = gravarBinario("Dados.bin", jobsHeader);

        // jobsHeader = lerBinario("Dados.bin");

    #pragma endregion

    #pragma region Printfs

        //Mostrar
        printf("\n\n-----------------------------------------\n");
        MostraListaJobs(jobsHeader);
        printf("\n\n-----------------------------------------\n");

        //Funções
        //Alterar
        jobsHeader->operacoes = AlterarOperacoes(jobsHeader->operacoes, 1, 3, 8);
        MostraListaJobs(jobsHeader);
        printf("\n\n-----------------------------------------\n");

        //Minimo
        printf("Tempo Minimo: %d\n", TempoMinimoOperacao(jobsHeader->operacoes));
        printf("\n\n-----------------------------------------\n");

        //Maximo
        printf("Tempo Maximo: %d\n", TempoMaximoOperacao(jobsHeader->operacoes));
        printf("\n\n-----------------------------------------\n");

        //Media
        printf("Tempo Medio: %.2f\n", TempoMedioOperacao(jobsHeader->operacoes));
        printf("\n\n-----------------------------------------\n");

        //Remover
        jobsHeader->operacoes = RemoveOperacao(jobsHeader->operacoes, 1);
        MostraListaJobs(jobsHeader);
        printf("\n\n-----------------------------------------\n");

    #pragma endregion
    
}