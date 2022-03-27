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

        //Maquinas
        Maquina* m1 = CriaMaquina(1, 4);
        Maquina* m2 = CriaMaquina(3, 5);

        //Operações
        Operacao* o1 = CriaOperacao(1);

        ListaOperacoes* operacoesHeader = NULL;

        o1->maquinas = InsereNaListaDeMaquinas(o1->maquinas, m1);
        o1->maquinas = InsereNaListaDeMaquinas(o1->maquinas, m2);
        
        operacoesHeader = InsereNaListaDeOperacoes(operacoesHeader, o1);


        //Mostrar
        printf("\n\n-----------------------------------------\n");
        MostraListaOperacoes(operacoesHeader);
        printf("\n\n-----------------------------------------\n");

        //Funções
        //Alterar
        operacoesHeader = AlterarOperacoes(operacoesHeader, 1, 3, 8);
        MostraListaOperacoes(operacoesHeader);
        printf("\n\n-----------------------------------------\n");

        //Minimo
        printf("Tempo Minimo: %d\n", TempoMinimoOperacao(operacoesHeader));
        printf("\n\n-----------------------------------------\n");

        //Maximo
        printf("Tempo Maximo: %d\n", TempoMaximoOperacao(operacoesHeader));
        printf("\n\n-----------------------------------------\n");

        //Media
        printf("Tempo Medio: %.2f\n", TempoMedioOperacao(operacoesHeader));
        printf("\n\n-----------------------------------------\n");

        //Remover
        operacoesHeader = RemoveOperacao(operacoesHeader, 1);
        MostraListaOperacoes(operacoesHeader);
        printf("\n\n-----------------------------------------\n");

    #pragma endregion
}