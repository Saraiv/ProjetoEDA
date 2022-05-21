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
        Maquina* m3 = CriaMaquina(2, 4);
        Maquina* m4 = CriaMaquina(4, 5);
        Maquina* m5 = CriaMaquina(3, 5);
        Maquina* m6 = CriaMaquina(5, 6);
        Maquina* m7 = CriaMaquina(4, 5);
        Maquina* m8 = CriaMaquina(5, 5);
        Maquina* m9 = CriaMaquina(6, 4);
        Maquina* m10 = CriaMaquina(7, 5);
        Maquina* m11 = CriaMaquina(8, 9);


        //Operações
        Operacao* o1 = CriaOperacao(1);
        Operacao* o2 = CriaOperacao(2);
        Operacao* o3 = CriaOperacao(3);
        Operacao* o4 = CriaOperacao(4);
        
        //Jobs
        Job* j1 = CriaJob("123AsdaA321");

        o1->maquinas = InsereNaListaDeMaquinas(o1->maquinas, m1);
        o1->maquinas = InsereNaListaDeMaquinas(o1->maquinas, m2);
        
        j1->operacoes = InsereNaListaDeOperacoes(j1->operacoes, o1);

        o2->maquinas = InsereNaListaDeMaquinas(o2->maquinas, m3);
        o2->maquinas = InsereNaListaDeMaquinas(o2->maquinas, m4);
        
        j1->operacoes = InsereNaListaDeOperacoes(j1->operacoes, o2);

        o3->maquinas = InsereNaListaDeMaquinas(o3->maquinas, m5);
        o3->maquinas = InsereNaListaDeMaquinas(o3->maquinas, m6);
        
        j1->operacoes = InsereNaListaDeOperacoes(j1->operacoes, o3);
        
        o4->maquinas = InsereNaListaDeMaquinas(o4->maquinas, m7);
        o4->maquinas = InsereNaListaDeMaquinas(o4->maquinas, m8);
        o4->maquinas = InsereNaListaDeMaquinas(o4->maquinas, m9);
        o4->maquinas = InsereNaListaDeMaquinas(o4->maquinas, m10);
        o4->maquinas = InsereNaListaDeMaquinas(o4->maquinas, m11);
        
        j1->operacoes = InsereNaListaDeOperacoes(j1->operacoes, o4);

        jobsHeader = InsereJob(jobsHeader, j1);

        // bool ficheiro = GravarBinario("Dados.bin", jobsHeader);

        // jobsHeader = LerBinario("Dados.bin");

    #pragma endregion

    #pragma region HashTable

        // Job** hashTable = NULL;

        // IniciaHash(hashTable);

        // hashTable = InsereNodoJobNaHash(j1, hashTable);
        // // *hashTable = InsereNodoJobNaHash(j2, hashTable);

        // MostrarHashTable(hashTable);

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