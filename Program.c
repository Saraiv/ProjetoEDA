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

        ListaMaquinas* maquinasHeader = NULL;

        maquinasHeader = InsereNaListaDeMaquinas(maquinasHeader, m1);
        maquinasHeader = InsereNaListaDeMaquinas(maquinasHeader, m2);

        //Operações
        Operacao* o1 = CriaOperacao(1, maquinasHeader);

        ListaOperacoes* operacoesHeader = NULL;

        operacoesHeader = InsereNaListaDeOperacoes(operacoesHeader, o1);

        // operacoesHeader = InsereMaquinaNaListaOperacoes(operacoesHeader, m1);
        // operacoesHeader = InsereMaquinaNaListaOperacoes(operacoesHeader, m1);

        //Mostrar
        MostraListaOperacoes(operacoesHeader);

        //Funções

        // //Remover
        // operacoesHeader = RemoveOperacao(operacoesHeader, 1);
        // MostraListaOperacoes(operacoesHeader);

        //Alterar
        // operacoesHeader = AlterarOperacoes(operacoesHeader, 1, 3, 8);

        //Minimo
        printf("Tempo Minimo: %d\n", TempoMinimoOperacao(operacoesHeader));

        //Maximo
        printf("Tempo Maximo: %d\n", TempoMaximoOperacao(operacoesHeader));

        //Media
        printf("Tempo Medio: %.2f\n", TempoMedioOperacao(operacoesHeader));

    #pragma endregion
}