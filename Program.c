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

        //Máquinas job1
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

        //Máquinas job2
        Maquina* m12 = CriaMaquina(1, 1);
        Maquina* m13 = CriaMaquina(3, 5);
        Maquina* m14 = CriaMaquina(5, 7);
        Maquina* m15 = CriaMaquina(4, 5);
        Maquina* m16 = CriaMaquina(8, 4);
        Maquina* m17 = CriaMaquina(4, 1);
        Maquina* m18 = CriaMaquina(6, 6);
        Maquina* m19 = CriaMaquina(4, 4);
        Maquina* m20 = CriaMaquina(7, 4);
        Maquina* m21 = CriaMaquina(8, 7);
        Maquina* m22 = CriaMaquina(4, 1);
        Maquina* m23 = CriaMaquina(6, 2);
        Maquina* m24 = CriaMaquina(1, 5);
        Maquina* m25 = CriaMaquina(6, 6);
        Maquina* m26 = CriaMaquina(8, 4);
        Maquina* m27 = CriaMaquina(4, 4);

        //Máquinas job3
        Maquina* m28 = CriaMaquina(2, 7);
        Maquina* m29 = CriaMaquina(3, 6);
        Maquina* m30 = CriaMaquina(8, 8);
        Maquina* m31 = CriaMaquina(4, 7);
        Maquina* m32 = CriaMaquina(8, 7);
        Maquina* m33 = CriaMaquina(3, 7);
        Maquina* m34 = CriaMaquina(5, 8);
        Maquina* m35 = CriaMaquina(7, 7);
        Maquina* m36 = CriaMaquina(4, 7);
        Maquina* m37 = CriaMaquina(6, 8);
        Maquina* m38 = CriaMaquina(1, 1);
        Maquina* m39 = CriaMaquina(2, 4);

        //Operação job1
        Operacao* o1 = CriaOperacao(1);
        Operacao* o2 = CriaOperacao(2);
        Operacao* o3 = CriaOperacao(3);
        Operacao* o4 = CriaOperacao(4);
        
        //Operação job2
        Operacao* o5 = CriaOperacao(1);
        Operacao* o6 = CriaOperacao(2);
        Operacao* o7 = CriaOperacao(3);
        Operacao* o8 = CriaOperacao(4);
        Operacao* o9 = CriaOperacao(5);
        Operacao* o10 = CriaOperacao(6);
        Operacao* o11 = CriaOperacao(7);

        //Operação job3
        Operacao* o12 = CriaOperacao(1);
        Operacao* o13 = CriaOperacao(2);
        Operacao* o14 = CriaOperacao(3);
        Operacao* o15 = CriaOperacao(4);
        Operacao* o16 = CriaOperacao(5);
        
        //Jobs
        Job* j1 = CriaJob("1");
        Job* j2 = CriaJob("2");
        Job* j3 = CriaJob("3");

        //Job1
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

        //Job2
        o5->maquinas = InsereNaListaDeMaquinas(o5->maquinas, m12);
        o5->maquinas = InsereNaListaDeMaquinas(o5->maquinas, m13);
        o5->maquinas = InsereNaListaDeMaquinas(o5->maquinas, m14);

        j2->operacoes = InsereNaListaDeOperacoes(j2->operacoes, o5);

        o6->maquinas = InsereNaListaDeMaquinas(o6->maquinas, m15);
        o6->maquinas = InsereNaListaDeMaquinas(o6->maquinas, m16);

        j2->operacoes = InsereNaListaDeOperacoes(j2->operacoes, o6);

        o7->maquinas = InsereNaListaDeMaquinas(o7->maquinas, m17);
        o7->maquinas = InsereNaListaDeMaquinas(o7->maquinas, m18);

        j2->operacoes = InsereNaListaDeOperacoes(j2->operacoes, o7);

        o8->maquinas = InsereNaListaDeMaquinas(o8->maquinas, m19);
        o8->maquinas = InsereNaListaDeMaquinas(o8->maquinas, m20);
        o8->maquinas = InsereNaListaDeMaquinas(o8->maquinas, m21);

        j2->operacoes = InsereNaListaDeOperacoes(j2->operacoes, o8);

        o9->maquinas = InsereNaListaDeMaquinas(o9->maquinas, m22);
        o9->maquinas = InsereNaListaDeMaquinas(o9->maquinas, m23);

        j2->operacoes = InsereNaListaDeOperacoes(j2->operacoes, o9);

        o10->maquinas = InsereNaListaDeMaquinas(o10->maquinas, m24);
        o10->maquinas = InsereNaListaDeMaquinas(o10->maquinas, m25);
        o10->maquinas = InsereNaListaDeMaquinas(o10->maquinas, m26);

        j2->operacoes = InsereNaListaDeOperacoes(j2->operacoes, o10);

        o11->maquinas = InsereNaListaDeMaquinas(o11->maquinas, m27);

        j2->operacoes = InsereNaListaDeOperacoes(j2->operacoes, o11);
        
        jobsHeader = InsereJob(jobsHeader, j2);

        //job3
        o12->maquinas = InsereNaListaDeMaquinas(o12->maquinas, m28);
        o12->maquinas = InsereNaListaDeMaquinas(o12->maquinas, m29);
        o12->maquinas = InsereNaListaDeMaquinas(o12->maquinas, m30);

        j3->operacoes = InsereNaListaDeOperacoes(j3->operacoes, o12);

        o13->maquinas = InsereNaListaDeMaquinas(o12->maquinas, m31);
        o13->maquinas = InsereNaListaDeMaquinas(o12->maquinas, m32);

        j3->operacoes = InsereNaListaDeOperacoes(j3->operacoes, o13);

        o14->maquinas = InsereNaListaDeMaquinas(o14->maquinas, m33);
        o14->maquinas = InsereNaListaDeMaquinas(o14->maquinas, m34);
        o14->maquinas = InsereNaListaDeMaquinas(o14->maquinas, m35);

        j3->operacoes = InsereNaListaDeOperacoes(j3->operacoes, o14);
        
        o15->maquinas = InsereNaListaDeMaquinas(o15->maquinas, m36);
        o15->maquinas = InsereNaListaDeMaquinas(o15->maquinas, m37);

        j3->operacoes = InsereNaListaDeOperacoes(j3->operacoes, o15);

        o16->maquinas = InsereNaListaDeMaquinas(o16->maquinas, m38);
        o16->maquinas = InsereNaListaDeMaquinas(o16->maquinas, m39);

        j3->operacoes = InsereNaListaDeOperacoes(j3->operacoes, o16);
        
        jobsHeader = InsereJob(jobsHeader, j3);
        // bool ficheiro = GravarBinario("Dados.bin", jobsHeader);

        // jobsHeader = LerBinario("Dados.bin");

    #pragma endregion

    #pragma region PrintfsFase1

        // //Mostrar
        // printf("\n\n-----------------------------------------\n");
        // MostraListaJobs(jobsHeader);
        // printf("\n\n-----------------------------------------\n");

        // //Funções
        // //Alterar
        // jobsHeader->operacoes = AlterarOperacoes(jobsHeader->operacoes, 1, 3, 8);
        // MostraListaJobs(jobsHeader);
        // printf("\n\n-----------------------------------------\n");

        // //Minimo
        // printf("Tempo Minimo: %d\n", TempoMinimoOperacao(jobsHeader->operacoes));
        // printf("\n\n-----------------------------------------\n");

        // //Maximo
        // printf("Tempo Maximo: %d\n", TempoMaximoOperacao(jobsHeader->operacoes));
        // printf("\n\n-----------------------------------------\n");

        // //Media
        // printf("Tempo Medio: %.2f\n", TempoMedioOperacao(jobsHeader->operacoes));
        // printf("\n\n-----------------------------------------\n");

        // //Remover
        // jobsHeader->operacoes = RemoveOperacao(jobsHeader->operacoes, 1);
        // MostraListaJobs(jobsHeader);
        // printf("\n\n-----------------------------------------\n");

    #pragma endregion

    #pragma region HashTableFase2

        Job* hashTable[MAX];

        IniciaHash(hashTable);
        InsereNodoJobNaHash(j1, hashTable);
        InsereNodoJobNaHash(j2, hashTable);
        InsereNodoJobNaHash(j3, hashTable);

        printf("\nHashtable\n");
        MostrarHashTable(hashTable);

        //Funções
        //Alterar
        hashTable[2]->operacoes = AlterarOperacoes(hashTable[2]->operacoes, 6, 6, 8);
        printf("\nHashtable Alterada\n");
        MostrarHashTable(hashTable);

        //Remover
        hashTable[2]->operacoes = RemoveOperacao(hashTable[2]->operacoes, 4);
        printf("\nHashtable Removida\n");
        MostrarHashTable(hashTable);

        //Minimo
        printf("\n\n-----------------------------------------\n");
        printf("Tempo Minimo: %d\n", TempoMinimoOperacao(hashTable[2]->operacoes));
        printf("\n\n-----------------------------------------\n");

        //Maximo
        printf("Tempo Maximo: %d\n", TempoMaximoOperacao(hashTable[2]->operacoes));
        printf("\n\n-----------------------------------------\n");

        //Media
        printf("Tempo Medio: %.2f\n", TempoMedioOperacao(hashTable[2]->operacoes));

        //Gravar em ficheiros
        bool res = GravarBinario(hashTable);

    #pragma endregion

}