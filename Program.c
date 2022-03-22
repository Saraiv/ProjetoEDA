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

        Maquina* headMaquina = NULL;

        headMaquina = InsereMaquina(headMaquina, m1);
        headMaquina = InsereMaquina(headMaquina, m2);
        headMaquina = InsereMaquina(headMaquina, m3);
        headMaquina = InsereMaquina(headMaquina, m4);
        headMaquina = InsereMaquina(headMaquina, m5);
        headMaquina = InsereMaquina(headMaquina, m6);
        headMaquina = InsereMaquina(headMaquina, m7);
        headMaquina = InsereMaquina(headMaquina, m8);
        headMaquina = InsereMaquina(headMaquina, m9);
        headMaquina = InsereMaquina(headMaquina, m10);
        headMaquina = InsereMaquina(headMaquina, m11);

        bool auxFicheiro = gravarBinarioMaquina("Dados.bin", headMaquina);
    #pragma endregion
}