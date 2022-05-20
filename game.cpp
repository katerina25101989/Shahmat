// дипломная работа.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>


#include "Header.h"


using namespace std;








void showGame(string array[8][8])
{
    cout << endl;
    cout << endl;
    cout << "   a    b    c    d    e    f    g    h " << endl;
    for (int i = 0; i < 8; i++)
    {

        cout << i + 1 << " ";
        for (int j = 0; j < 8; j++)
        {
            if (array[i][j] == "Bb" || array[i][j] == "Bw" || array[i][j] == "Nb" || array[i][j] == "Nw" ||
                array[i][j] == "Rb" || array[i][j] == "Rw" || array[i][j] == "Qb" || array[i][j] == "Qw" ||
                array[i][j] == "Kb" || array[i][j] == "Kw" || array[i][j] == "pb" || array[i][j] == "pw") cout << array[i][j] << " | ";

            else
            {
                if (i % 2 != 0)
                {
                    if (j % 2 != 0) cout << "  " << " | ";
                    else cout << char(278) << char(278) << " | ";
                }
                else
                {
                    if (j % 2 != 0) cout << char(278) << char(278) << " | ";
                    else cout << "  " << " | ";
                }
            }
        }
        cout << endl;
        cout << "  ---------------------------------------" << endl;

    }
    cout << endl;
    cout << endl;
}
void  newGame(string array[8][8])
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (i == 0)
            {
                if (j == 0 || j == 7) array[i][j] = "Bb";
                if (j == 1 || j == 6) array[i][j] = "Nb";
                if (j == 2 || j == 5) array[i][j] = "Rb";
                if (j == 3)array[i][j] = "Qb";
                if (j == 4)array[i][j] = "Kb";

            }
            else if (i == 1)
            {
                array[i][j] = "pb";

            }
            else if (i == 6)
            {
                array[i][j] = "pw";
            }
            else if (i == 7)
            {
                if (j == 0 || j == 7) array[i][j] = "Bw";
                if (j == 1 || j == 6) array[i][j] = "Nw";
                if (j == 2 || j == 5) array[i][j] = "Rw";
                if (j == 3)array[i][j] = "Qw";
                if (j == 4)array[i][j] = "Kw";
            }
            else array[i][j] = "";
        }
    }
}


void privetstvie()
{
    setlocale(LC_ALL, "rus");


    cout << endl;
    cout << "Обозначения: " << endl;
    cout << "черные - 'b';   белые - 'w';" << endl;
    cout << "Ладья - 'B';    Конь - 'N';" << endl;
    cout << "Слон - 'R';     Ферзь - 'Q';" << endl;
    cout << "Король - 'K';   Пешка - 'p'." << endl;

}
void  stringNamber(string c, int& hodR, int& hodS)
{
    for (int i = 0; i < 2; i++)
    {
        if (i == 0)
        {
            if (c[i] == char(97)) hodR = 0;
            else if (c[i] == char(98)) hodR = 1;
            else if (c[i] == char(99)) hodR = 2;
            else if (c[i] == char(100)) hodR = 3;
            else if (c[i] == char(101)) hodR = 4;
            else if (c[i] == char(102)) hodR = 5;
            else if (c[i] == char(103)) hodR = 6;
            else if (c[i] == char(104)) hodR = 7;
        }
        if (i == 1)
        {
            if (c[i] == char(49))hodS = 0;
            else if (c[i] == char(50))hodS = 1;
            else if (c[i] == char(51)) hodS = 2;
            else if (c[i] == char(52)) hodS = 3;
            else if (c[i] == char(53)) hodS = 4;
            else if (c[i] == char(54)) hodS = 5;
            else if (c[i] == char(55)) hodS = 6;
            else if (c[i] == char(56)) hodS = 7;
        }
    }
}
void figyra(string array[8][8], int a, int b, int c, int d, int& count, int &k1,int & k2)
{
    if (array[a][b] == "Bb" || array[a][b] == "Bw")figyraB(array, a, b, c, d, count);
    else if (array[a][b] == "Nb" || array[a][b] == "Nw") figyraN(array, a, b, c, d, count);
    else if (array[a][b] == "Rb" || array[a][b] == "Rw") figyraR(array, a, b, c, d, count);
    else if (array[a][b] == "Qb" || array[a][b] == "Qw") figyraQ(array, a, b, c, d, count);
    else if (array[a][b] == "Kb" || array[a][b] == "Kw") figyraK(array, a, b, c, d, count,k1,k2);
    else if (array[a][b] == "pb" || array[a][b] == "pw") figyraP(array, a, b, c, d, count);


}
void hodAB(string array[8][8], string a, string b, int& count, int& hodR1, int& hodS1, int& hodR2, int& hodS2,int& k1,int& k2)
{
    if (count < 10000)
    {
        privetstvie();
        if (count % 2 == 0)
        {
            cout << endl;
            cout << endl;
            cout << "\t\tХод белых. " << endl;
            cout << count;
            showGame(array);
        }
        else if (count % 2 != 0)
        {
            cout << endl;
            cout << endl;
            cout << "\t\tХод черных. " << endl;
            cout << count;
            showGame(array);
        }


        cout << "Введите начальный адрес фигуры (например: d1): ";
        cin >> a;

        stringNamber(a, hodR1, hodS1);

        cout << endl;
        cout << "Ход фигуры в ячейку (например: a2): ";
        cin >> b;
        system("cls");
        stringNamber(b, hodR2, hodS2);
        figyra(array, hodS1, hodR1, hodS2, hodR2, count , k1 , k2);

        hodAB(array, a, b, count, hodS1, hodR1, hodS2, hodR2,k1,k2);
    }
    else
    {
        cout << "\t\t Начать заново: Enter";
        int nW;
        cin >> nW;
        newGame(array);

    }
}
void matK(string array[8][8], int c, int d, int& count)
{
    if (array[c][d] == "Kw" || array[c][d] == "Kb")
    {
        if (array[c][d] == "Kb")
        {
            cout << endl;
            cout << "\t\tБелые обьявили МАТ черным! " << endl;
            cout << endl;
            cout << "\t\tИГРА ОКОНЧЕНА!" << endl;
            cout << endl;
            cout << "\t\tПобеда БЕЛЫХ!" << endl;
            count = 10000;
        }
        else if (array[c][d] == "Kw")
        {
            cout << endl;
            cout << "\t\tЧерные обьявили МАТ белым! ";
            cout << endl;
            cout << "\t\tИГРА ОКОНЧЕНА!";
            cout << endl;
            cout << "\t\tПобеда ЧЕРНЫХ!";
            count = 10000;
        }
    }
}

void rakirovkaK(string array[8][8], int a, int b, int c, int d, int& count, int& k1, int& k2)
{
    if (k1 == 0)
    {
        if (array[a][b] == "Kw" && a == 7)

        {
            if (array[a][b + 3] == "Bw")
            {
                if ((b + 2) == d)
                {
                    if (array[a][b + 1] == "" && array[a][b + 2] == "")
                    {
                        array[c][d] = "Kw";
                        array[a][b + 1] = "Bw";
                        array[a][b + 3] = "";
                        array[a][b] = "";
                        count++;
                    }
                    if (array[a][b - 2] == "" && array[a][b - 1] == "" && array[a][b - 3] == "" && (b - 2) == d && array[a][b - 4] == "Bw")
                    {
                        array[c][d] = "Kw";
                        array[a][b - 1] = "Bw";
                        array[a][b - 4] = "";
                        array[a][b] = "";
                        count++;
                    }
                }
            }
        }
    }
    if (k2 == 0)
    {
        if (array[a][b] == "Kb" && a == 0)

        {
            if (array[a][b + 1] == "" && array[a][b + 2] == "" && (b + 2) == d && array[a][b + 3] == "Bb")
            {
                array[c][d] = "Kb";
                array[a][b + 1] = "Bb";
                array[a][b + 3] = "";
                array[a][b] = "";
                count++;
            }
            if (array[a][b - 2] == "" && array[a][b - 1] == "" && array[a][b - 3] == "" && (b - 2) == d && array[a][b - 4] == "Bb")
            {
                array[c][d] = "Kb";
                array[a][b - 1] = "Bb";
                array[a][b - 4] = "";
                array[a][b] = "";
                count++;
            }
        }
    }
    
}

void figyraK(string array[8][8], int a, int b, int c, int d, int& count,int & k1,int & k2)
{
    int m = count;
    if ((a - 1) == c)
    {
        if ((b - 1) == d || b == d || (b + 1) == d)
        {
            if (count % 2 == 0)
            {
                if (array[c][d] == "Kw" || array[c][d] == "Kb")
                {
                    matK(array, c, d, count);
                }
                else  if (array[c][d] == "Bw" || array[c][d] == "Rw" || array[c][d] == "Qw" ||
                    array[c][d] == "pw" || array[c][d] == "Nw") errorHod();
                else
                {
                    array[c][d] = "Kw";
                    array[a][b] = "";
                    count++;
                    k1++;
                }
            }
            else if (count % 2 != 0)
            {
                if (array[c][d] == "Kw" || array[c][d] == "Kb")
                {
                    matK(array, c, d, count);
                }
                else if (array[c][d] == "Bb" || array[c][d] == "Rb" || array[c][d] == "Qb" ||
                    array[c][d] == "pb" || array[c][d] == "Nb") errorHod();
                else
                {
                    array[c][d] = "Kb";
                    array[a][b] = "";
                    count++;
                    k2++;
                }
            }
        }
    }
    else if (a == c)
    {
        if ((b - 1) == d || (b + 1) == d)
        {
            if (count % 2 == 0)
            {
                if (array[c][d] == "Kw" || array[c][d] == "Kb")
                {
                    matK(array, c, d, count);
                }
                else if (array[c][d] == "Bw" || array[c][d] == "Rw" || array[c][d] == "Qw" ||
                    array[c][d] == "pw" || array[c][d] == "Nw") errorHod();
                else
                {
                    array[c][d] = "Kw";
                    array[a][b] = "";
                    count++;
                    k1++;
                }
            }
            else if (count % 2 != 0)
            {
                if (array[c][d] == "Kw" || array[c][d] == "Kb")
                {
                    matK(array, c, d, count);
                }
                else if (array[c][d] == "Bb" || array[c][d] == "Rb" || array[c][d] == "Qb" ||
                    array[c][d] == "pb" || array[c][d] == "Nb") errorHod();
                else
                {
                    array[c][d] = "Kb";
                    array[a][b] = "";
                    count++;
                    k2++;
                }
            }

        }
        else if ((b + 2) == d || (b - 2) == d) rakirovkaK(array, a, b, c, d, count, k1, k2);
    }
    else if ((a + 1) == c)
    {
        if ((b - 1) == d || b == d || (b + 1) == d)
        {
            if (count % 2 == 0)
            {
                if (array[c][d] == "Kw" || array[c][d] == "Kb")
                {
                    matK(array, c, d, count);
                }
                else if (array[c][d] == "Bw" || array[c][d] == "Rw" || array[c][d] == "Qw" ||
                    array[c][d] == "pw" || array[c][d] == "Nw") errorHod();
                else
                {
                    array[c][d] = "Kw";
                    array[a][b] = "";
                    count++;
                    k1++;
                }
            }
            else if (count % 2 != 0)
            {
                if (array[c][d] == "Kw" || array[c][d] == "Kb")
                {
                    matK(array, c, d, count);
                }
                else  if (array[c][d] == "Bb" || array[c][d] == "Rb" || array[c][d] == "Qb" ||
                    array[c][d] == "Kb" || array[c][d] == "pb" || array[c][d] == "Nb") errorHod();
                else
                {
                    array[c][d] = "Kb";
                    array[a][b] = "";
                    count++;
                    k2++;
                }
            }
        }
    }
   
    else if (m == count) errorHod();
}

void errorHod()
{
    cout << "----------------------------------------------" << endl;
    cout << "Ход не возможен." << endl;
    cout << "----------------------------------------------" << endl;
}


void figyraQ(string array[8][8], int a, int b, int c, int d, int& count)
{

    for (int n = 1; n < 8; )
    {
        //как слон
        if (a < c && b < d)
        {
            if ((a + n) <= c && (b + n) <= d)
            {
                if (array[a + n][b + n] == "")
                {
                    n++;
                    if ((a + n) == c && (b + n) == d)
                    {
                        if (count % 2 == 0)
                        {
                            if (array[c][d] == "Kw" || array[c][d] == "Kb")
                            {
                                matK(array, c, d, count);
                            }
                            else if (array[c][d] == "Bw" || array[c][d] == "Rw" || array[d][c] == "Qw" ||
                                array[c][d] == "pw" || array[c][d] == "Nw")
                            {
                                errorHod();
                                break;
                            }
                            else
                            {
                                array[c][d] = "Qw";
                                array[a][b] = "";
                                count++;
                                break;
                            }
                        }
                        if (count % 2 != 0)
                        {
                            if (array[c][d] == "Kw" || array[c][d] == "Kb")
                            {
                                matK(array, c, d, count);
                            }
                            else if (array[c][d] == "Bb" || array[c][d] == "Rb" || array[c][d] == "Qb" ||
                                array[c][d] == "pb" || array[c][d] == "Nb")
                            {
                                errorHod();
                                break;
                            }
                            else
                            {
                                array[c][d] = "Qb";
                                array[a][b] = "";
                                count++;
                                break;
                            }
                        }
                    }
                }
            }
        }
        else if (a < c && b > d)
        {
            if ((a + n) <= c && (b - n) >= d)
            {
                if (array[a + n][b - n] == "")
                {
                    n++;
                    if ((a + n) == c && (b - n) == d)
                    {
                        if (count % 2 == 0)
                        {
                            if (array[c][d] == "Kw" || array[c][d] == "Kb")
                            {
                                matK(array, c, d, count);
                            }
                            else if (array[c][d] == "Bw" || array[c][d] == "Rw" || array[d][c] == "Qw" ||
                                array[c][d] == "pw" || array[c][d] == "Nw")
                            {
                                errorHod();
                                break;
                            }
                            else
                            {
                                array[c][d] = "Qw";
                                array[a][b] = "";
                                count++;
                                break;
                            }
                        }
                        if (count % 2 != 0)
                        {
                            if (array[c][d] == "Kw" || array[c][d] == "Kb")
                            {
                                matK(array, c, d, count);
                            }
                            else if (array[c][d] == "Bb" || array[c][d] == "Rb" || array[c][d] == "Qb" ||
                                array[c][d] == "pb" || array[c][d] == "Nb")
                            {
                                errorHod();
                                break;
                            }
                            else
                            {
                                array[c][d] = "Qb";
                                array[a][b] = "";
                                count++;
                                break;
                            }
                        }
                    }
                }
            }
        }
        else if (a > c && b < d)
        {
            if ((a - n) >= c && (b + n) <= d)
            {
                if (array[a - n][b + n] == "")
                {
                    n++;
                    if ((a - n) == c && (b + n) == d)
                    {
                        if (count % 2 == 0)
                        {
                            if (array[c][d] == "Kw" || array[c][d] == "Kb")
                            {
                                matK(array, c, d, count);
                            }
                            else if (array[c][d] == "Bw" || array[c][d] == "Rw" || array[d][c] == "Qw" ||
                                array[c][d] == "pw" || array[c][d] == "Nw")
                            {
                                errorHod();
                                break;
                            }
                            else
                            {
                                array[c][d] = "Qw";
                                array[a][b] = "";
                                count++;
                                break;
                            }
                        }
                        if (count % 2 != 0)
                        {
                            if (array[c][d] == "Kw" || array[c][d] == "Kb")
                            {
                                matK(array, c, d, count);
                            }
                            else if (array[c][d] == "Bb" || array[c][d] == "Rb" || array[c][d] == "Qb" ||
                                array[c][d] == "pb" || array[c][d] == "Nb")
                            {
                                errorHod();
                                break;
                            }
                            else
                            {
                                array[c][d] = "Qb";
                                array[a][b] = "";
                                count++;
                                break;
                            }
                        }
                    }
                }

            }
        }
        else if (a > c && b > d)
        {
            if ((a - n) >= c && (b - n) >= d)
            {
                if (array[a - n][b - n] == "")
                {
                    n++;
                    if ((a - n) == c && (b - n) == d)
                    {
                        if (count % 2 == 0)
                        {
                            if (array[c][d] == "Kw" || array[c][d] == "Kb")
                            {
                                matK(array, c, d, count);
                            }
                            else if (array[c][d] == "Bw" || array[c][d] == "Rw" || array[d][c] == "Qw" ||
                                array[c][d] == "pw" || array[c][d] == "Nw")
                            {
                                errorHod();
                                break;
                            }
                            else
                            {
                                array[c][d] = "Qw";
                                array[a][b] = "";
                                count++;
                                break;
                            }
                        }
                        if (count % 2 != 0)
                        {
                            if (array[c][d] == "Kw" || array[c][d] == "Kb")
                            {
                                matK(array, c, d, count);
                            }
                            else if (array[c][d] == "Bb" || array[c][d] == "Rb" || array[c][d] == "Qb" ||
                                array[c][d] == "pb" || array[c][d] == "Nb")
                            {
                                errorHod();
                                break;
                            }
                            else
                            {
                                array[c][d] = "Qb";
                                array[a][b] = "";
                                count++;
                                break;
                            }
                        }
                    }
                }

            }
        }

        // как  ладья

        if (d == b)
        {
            if (a < c && (a + n) <= c)
            {
                if (array[a + n][b] == "")
                {
                    n++;
                    if ((a + n) == c)
                    {
                        if (count % 2 == 0)
                        {
                            if (array[c][d] == "Kw" || array[c][d] == "Kb")
                            {
                                matK(array, c, d, count);
                            }
                            else if (array[c][d] == "Bw" || array[c][d] == "Rw" || array[c][d] == "Qw" ||
                                array[c][d] == "pw" || array[c][d] == "Nw")
                            {
                                errorHod();
                                break;
                            }
                            else
                            {
                                array[c][d] = "Qw";
                                array[a][b] = "";
                                count++;
                                break;
                            }
                        }
                        else if (count % 2 != 0)
                        {
                            if (array[c][d] == "Kw" || array[c][d] == "Kb")
                            {
                                matK(array, c, d, count);
                            }
                            else if (array[c][d] == "Bb" || array[c][d] == "Rb" || array[c][d] == "Qb" ||
                                array[c][d] == "pb" || array[c][d] == "Nb")
                            {
                                errorHod();
                                break;
                            }
                            else
                            {
                                array[c][d] = "Qb";
                                array[a][b] = "";
                                count++;
                                break;
                            }
                        }
                    }
                }

            }
            if (a > c && (a - n) >= 0)
            {
                if (array[a - n][b] == "")
                {
                    n++;
                    if ((a - n) == c)
                    {
                        if (count % 2 == 0)
                        {
                            if (array[c][d] == "Kw" || array[c][d] == "Kb")
                            {
                                matK(array, c, d, count);
                            }
                            else if (array[c][d] == "Bw" || array[c][d] == "Rw" || array[c][d] == "Qw" ||
                                array[c][d] == "pw" || array[c][d] == "Nw")
                            {
                                errorHod();
                                break;
                            }
                            else
                            {
                                array[c][d] = "Qw";
                                array[a][b] = "";
                                count++;
                                break;
                            }
                        }
                        else if (count % 2 != 0)
                        {
                            if (array[c][d] == "Kw" || array[c][d] == "Kb")
                            {
                                matK(array, c, d, count);
                            }
                            else if (array[c][d] == "Bb" || array[c][d] == "Rb" || array[c][d] == "Qb" ||
                                array[c][d] == "pb" || array[c][d] == "Nb")
                            {
                                errorHod();
                                break;
                            }
                            else
                            {
                                array[c][d] = "Qb";
                                array[a][b] = "";
                                count++;
                                break;
                            }
                        }
                    }
                }

            }
        }
        if (c == a)
        {
            if (b < d && (b + n) <= d)

            {
                if (array[a][b + n] == "")
                {
                    n++;
                    if ((b + n) == d)
                    {
                        if (count % 2 == 0)
                        {
                            if (array[c][d] == "Kw" || array[c][d] == "Kb")
                            {
                                matK(array, c, d, count);
                            }
                            else if (array[c][d] == "Bw" || array[c][d] == "Rw" || array[c][d] == "Qw" ||
                                array[c][d] == "pw" || array[c][d] == "Nw")
                            {
                                errorHod();
                                break;
                            }
                            else
                            {
                                array[c][d] = "Qw";
                                array[a][b] = "";
                                count++;
                                break;
                            }
                        }
                        else if (count % 2 != 0)
                        {
                            if (array[c][d] == "Kw" || array[c][d] == "Kb")
                            {
                                matK(array, c, d, count);
                            }
                            else if (array[c][d] == "Bb" || array[c][d] == "Rb" || array[c][d] == "Qb" ||
                                array[c][d] == "pb" || array[c][d] == "Nb")
                            {
                                errorHod();
                                break;
                            }
                            else
                            {
                                array[c][d] = "Qb";
                                array[a][b] = "";
                                count++;
                                break;
                            }
                        }
                    }
                }
            }
            else if (b > d && (b - n) >= 0)
            {
                if (array[a][b - n] == "")
                {
                    n++;
                    if ((b - n) == d)
                    {
                        if (count % 2 == 0)
                        {
                            if (array[c][d] == "Kw" || array[c][d] == "Kb")
                            {
                                matK(array, c, d, count);
                            }
                            else if (array[c][d] == "Bw" || array[c][d] == "Rw" || array[c][d] == "Qw" ||
                                array[c][d] == "pw" || array[c][d] == "Nw")
                            {
                                errorHod();
                                break;
                            }
                            else
                            {
                                array[c][d] = "Qw";
                                array[a][b] = "";
                                count++;
                                break;
                            }
                        }
                        else if (count % 2 != 0)
                        {
                            if (array[c][d] == "Kw" || array[c][d] == "Kb")
                            {
                                matK(array, c, d, count);
                            }
                            else if (array[c][d] == "Bb" || array[c][d] == "Rb" || array[c][d] == "Qb" ||
                                array[c][d] == "pb" || array[c][d] == "Nb")
                            {
                                errorHod();
                                break;
                            }
                            else
                            {
                                array[c][d] = "Qb";
                                array[a][b] = "";
                                count++;
                                break;
                            }
                        }
                    }
                }
            }

        }
        if (n == 1)
        {
            errorHod();
            break;
        }
    }


}

void figyraN(string array[8][8], int a, int b, int c, int d, int& count) //  конь
{
    int m = count;
    //a+2
    if (c == (a + 2))
    {
        if (d == (b + 1))
        {
            if (count % 2 == 0)
            {
                if (array[c][d] == "Kw" || array[c][d] == "Kb")
                {
                    matK(array, c, d, count);
                }
                else if (array[c][d] == "Bw" || array[c][d] == "Rw" || array[c][d] == "Qw" ||
                    array[c][d] == "pw" || array[c][d] == "Nw")
                {
                    errorHod();

                }
                else
                {
                    array[c][d] = "Nw";
                    array[a][b] = "";
                    count++;

                }
            }
            else if (count % 2 != 0)
            {
                if (array[c][d] == "Kw" || array[c][d] == "Kb")
                {
                    matK(array, c, d, count);
                }
                else if (array[c][d] == "Bb" || array[c][d] == "Rb" || array[c][d] == "Qb" ||
                    array[c][d] == "pb" || array[c][d] == "Nb")
                {
                    errorHod();

                }
                else
                {
                    array[c][d] = "Nb";
                    array[a][b] = "";
                    count++;

                }
            }
        }
        else if (d == (b - 1))
        {

            if (count % 2 == 0)
            {
                if (array[c][d] == "Kw" || array[c][d] == "Kb")
                {
                    matK(array, c, d, count);
                }
                else if (array[c][d] == "Bw" || array[c][d] == "Rw" || array[c][d] == "Qw" ||
                    array[c][d] == "pw" || array[c][d] == "Nw")
                {
                    errorHod();

                }
                else
                {
                    array[c][d] = "Nw";
                    array[a][b] = "";
                    count++;

                }
            }
            else if (count % 2 != 0)
            {
                if (array[c][d] == "Kw" || array[c][d] == "Kb")
                {
                    matK(array, c, d, count);
                }
                else if (array[c][d] == "Bb" || array[c][d] == "Rb" || array[c][d] == "Qb" ||
                    array[c][d] == "pb" || array[c][d] == "Nb")
                {
                    errorHod();

                }
                else
                {
                    array[c][d] = "Nb";
                    array[a][b] = "";
                    count++;

                }
            }
        }
    }
    //a+1 
    else if (c == (a + 1))
    {
        if (d == (b + 2))
        {
            if (count % 2 == 0)
            {
                if (count % 2 == 0)
                {
                    if (array[c][d] == "Kw" || array[c][d] == "Kb")
                    {
                        matK(array, c, d, count);
                    }
                    else if (array[c][d] == "Bw" || array[c][d] == "Rw" || array[c][d] == "Qw" ||
                        array[c][d] == "pw" || array[c][d] == "Nw")
                    {
                        errorHod();

                    }
                    else
                    {
                        array[c][d] = "Nw";
                        array[a][b] = "";
                        count++;

                    }
                }
                else if (count % 2 != 0)
                {
                    if (array[c][d] == "Kw" || array[c][d] == "Kb")
                    {
                        matK(array, c, d, count);
                    }
                    else if (array[c][d] == "Bb" || array[c][d] == "Rb" || array[c][d] == "Qb" ||
                        array[c][d] == "pb" || array[c][d] == "Nb")
                    {
                        errorHod();

                    }
                    else
                    {
                        array[c][d] = "Nb";
                        array[a][b] = "";
                        count++;

                    }
                }
            }
            else if (d == (b - 2))
            {
                if (count % 2 == 0)
                {
                    if (array[c][d] == "Kw" || array[c][d] == "Kb")
                    {
                        matK(array, c, d, count);
                    }
                    else if (array[c][d] == "Bw" || array[c][d] == "Rw" || array[c][d] == "Qw" ||
                        array[c][d] == "pw" || array[c][d] == "Nw")
                    {
                        errorHod();

                    }
                    else
                    {
                        array[c][d] = "Nw";
                        array[a][b] = "";
                        count++;

                    }
                }
                else if (count % 2 != 0)
                {
                    if (array[c][d] == "Kw" || array[c][d] == "Kb")
                    {
                        matK(array, c, d, count);
                    }
                    else if (array[c][d] == "Bb" || array[c][d] == "Rb" || array[c][d] == "Qb" ||
                        array[c][d] == "pb" || array[c][d] == "Nb")
                    {
                        errorHod();

                    }
                    else
                    {
                        array[c][d] = "Nb";
                        array[a][b] = "";
                        count++;

                    }
                }
            }
        }
    }

    //a-2
    else if (c == (a - 2))
    {
        if (d == (b + 1))
        {
            if (count % 2 == 0)
            {
                if (array[c][d] == "Kw" || array[c][d] == "Kb")
                {
                    matK(array, c, d, count);
                }
                else if (array[c][d] == "Bw" || array[c][d] == "Rw" || array[c][d] == "Qw" ||
                    array[c][d] == "pw" || array[c][d] == "Nw")
                {
                    errorHod();

                }
                else
                {
                    array[c][d] = "Nw";
                    array[a][b] = "";
                    count++;

                }
            }
            else if (count % 2 != 0)
            {
                if (array[c][d] == "Kw" || array[c][d] == "Kb")
                {
                    matK(array, c, d, count);
                }
                else if (array[c][d] == "Bb" || array[c][d] == "Rb" || array[c][d] == "Qb" ||
                    array[c][d] == "pb" || array[c][d] == "Nb")
                {
                    errorHod();

                }
                else
                {
                    array[c][d] = "Nb";
                    array[a][b] = "";
                    count++;

                }
            }
        }
        else if (d == (b - 1))
        {
            if (count % 2 == 0)
            {
                if (array[c][d] == "Kw" || array[c][d] == "Kb")
                {
                    matK(array, c, d, count);
                }
                else if (array[c][d] == "Bw" || array[c][d] == "Rw" || array[c][d] == "Qw" ||
                    array[c][d] == "pw" || array[c][d] == "Nw")
                {
                    errorHod();

                }
                else
                {
                    array[c][d] = "Nw";
                    array[a][b] = "";
                    count++;

                }
            }
            else if (count % 2 != 0)
            {
                if (array[c][d] == "Kw" || array[c][d] == "Kb")
                {
                    matK(array, c, d, count);
                }
                else if (array[c][d] == "Bb" || array[c][d] == "Rb" || array[c][d] == "Qb" ||
                    array[c][d] == "pb" || array[c][d] == "Nb")
                {
                    errorHod();

                }
                else
                {
                    array[c][d] = "Nb";
                    array[a][b] = "";
                    count++;

                }
            }
        }
    }
    //a-1
    else if (c == (a - 1))
    {
        if (d == (b + 2))
        {
            if (count % 2 == 0)
            {
                if (array[c][d] == "Kw" || array[c][d] == "Kb")
                {
                    matK(array, c, d, count);
                }
                else if (array[c][d] == "Bw" || array[c][d] == "Rw" || array[c][d] == "Qw" ||
                    array[c][d] == "pw" || array[c][d] == "Nw")
                {
                    errorHod();

                }
                else
                {
                    array[c][d] = "Nw";
                    array[a][b] = "";
                    count++;

                }
            }
            else if (count % 2 != 0)
            {
                if (array[c][d] == "Kw" || array[c][d] == "Kb")
                {
                    matK(array, c, d, count);
                }
                else if (array[c][d] == "Bb" || array[c][d] == "Rb" || array[c][d] == "Qb" ||
                    array[c][d] == "pb" || array[c][d] == "Nb")
                {
                    errorHod();

                }
                else
                {
                    array[c][d] = "Nb";
                    array[a][b] = "";
                    count++;

                }
            }
        }
        else if (d == (b - 2))
        {
            if (count % 2 == 0)
            {
                if (array[c][d] == "Kw" || array[c][d] == "Kb")
                {
                    matK(array, c, d, count);
                }
                else if (array[c][d] == "Bw" || array[c][d] == "Rw" || array[c][d] == "Qw" ||
                    array[c][d] == "pw" || array[c][d] == "Nw")
                {
                    errorHod();

                }
                else
                {
                    array[c][d] = "Nw";
                    array[a][b] = "";
                    count++;

                }
            }
            else if (count % 2 != 0)
            {
                if (array[c][d] == "Kw" || array[c][d] == "Kb")
                {
                    matK(array, c, d, count);
                }
                else if (array[c][d] == "Bb" || array[c][d] == "Rb" || array[c][d] == "Qb" ||
                    array[c][d] == "pb" || array[c][d] == "Nb")
                {
                    errorHod();

                }
                else
                {
                    array[c][d] = "Nb";
                    array[a][b] = "";
                    count++;

                }
            }
        }
    }




    if (m == count) errorHod();
}

void figyraP(string array[8][8], int a, int b, int c, int d, int& count)
{
    int m = count;
    if ((a + 1) == c || (a + 2) == c)
    {
            if (b == d)
            {
                if (count % 2 != 0)
                {

                    if (array[a + 1][b] == "")
                    {
                        if (array[c][d] == "Kw" || array[c][d] == "Kb")
                        {
                            matK(array, c, d, count);
                        }
                        else if (array[c][d] == "Bb" || array[c][d] == "Rb" || array[c][d] == "Qb" ||
                            array[c][d] == "pb" || array[c][d] == "Nb")
                        {
                            errorHod();

                        }
                        else
                        {
                            if (a == 6 && (a + 2) == c&& array[a + 2][b] == "")
                            {
                                array[c][d] = "pb";
                                array[a][b] = "";
                                count++;
                            }
                            else if ((a + 1) == c)
                            {
                                array[c][d] = "pb";
                                array[a][b] = "";
                                count++;
                            }

                        }
                    }
                }
            }
            else if ((b + 1) == d || (b - 1) == d)
            {
                if (count % 2 != 0)
                {
                    if (array[c][d] == "Kw" || array[c][d] == "Kb")
                    {
                        matK(array, c, d, count);
                    }
                    else if (array[c][d] == "Bb" || array[c][d] == "Rb" || array[c][d] == "Qb" ||
                        array[c][d] == "pb" || array[c][d] == "Nb")
                    {
                        errorHod();

                    }
                    else if (array[c][d] == "Bw" || array[c][d] == "Rw" || array[c][d] == "Qw" ||
                        array[c][d] == "pw" || array[c][d] == "Nw")
                    {
                        array[c][d] = "pb";
                        array[a][b] = "";
                        count++;

                    }
                }
            }
        
    }
    else if ((a - 1) == c || (a - 2) == c)
    {
        if (b == d)
        {
            if (count % 2 == 0)
            {

                if (array[a - 1][b] == "")
                {
                    if (array[c][d] == "Kw" || array[c][d] == "Kb")
                    {
                        matK(array, c, d, count);
                    }
                    else if (array[c][d] == "Bw" || array[c][d] == "Rw" || array[c][d] == "Qw" ||
                        array[c][d] == "pw" || array[c][d] == "Nw")
                    {
                        errorHod();

                    }

                    else
                    {
                        if (a == 6 && (a - 2) == c && array[a - 2][b] == "")
                        {
                            array[c][d] = "pw";
                            array[a][b] = "";
                            count++;
                        }
                        else if ((a - 1) == c)
                        {
                            array[c][d] = "pw";
                            array[a][b] = "";
                            count++;
                        }

                    }
                }


            }
        }
        else if ((b + 1) == d || (b - 1) == d)
        {
            if (count % 2 == 0)
            {
                if (array[c][d] == "Kw" || array[c][d] == "Kb")
                {
                    matK(array, c, d, count);
                }
                else if (array[c][d] == "Bw" || array[c][d] == "Rw" || array[c][d] == "Qw" ||
                    array[c][d] == "pw" || array[c][d] == "Nw")
                {
                    errorHod();

                }
                else if (array[c][d] == "Bb" || array[c][d] == "Rb" || array[c][d] == "Qb" ||
                    array[c][d] == "pb" || array[c][d] == "Nb")
                {
                    array[c][d] = "pw";
                    array[a][b] = "";
                    count++;

                }
                else errorHod();
            }
        }
    }
    if (m == count) errorHod();

}

void figyraR(string array[8][8], int a, int b, int c, int d, int& count)
{

    for (int n = 1; n < 8; )
    {

        if (a < c && b < d)
        {
            if ((a + n) <= c && (b + n) <= d)
            {
                if (array[a + n][b + n] == "")
                {
                    n++;
                    if ((a + n) == c && (b + n) == d)
                    {
                        if (count % 2 == 0)
                        {
                            if (array[c][d] == "Kw" || array[c][d] == "Kb")
                            {
                                matK(array, c, d, count);
                            }
                            else if (array[c][d] == "Bw" || array[c][d] == "Rw" || array[d][c] == "Qw" ||
                                array[c][d] == "pw" || array[c][d] == "Nw")
                            {
                                errorHod();
                                break;
                            }
                            else
                            {
                                array[c][d] = "Rw";
                                array[a][b] = "";
                                count++;
                                break;
                            }
                        }
                        if (count % 2 != 0)
                        {
                            if (array[c][d] == "Kw" || array[c][d] == "Kb")
                            {
                                matK(array, c, d, count);
                            }
                            else if (array[c][d] == "Bb" || array[c][d] == "Rb" || array[c][d] == "Qb" ||
                                array[c][d] == "pb" || array[c][d] == "Nb")
                            {
                                errorHod();
                                break;
                            }
                            else
                            {
                                array[c][d] = "Rb";
                                array[a][b] = "";
                                count++;
                                break;
                            }
                        }
                    }
                }
            }
        }
        else if (a < c && b > d)
        {
            if ((a + n) <= c && (b - n) >= d)
            {
                if (array[a + n][b - n] == "")
                {
                    n++;
                    if ((a + n) == c && (b - n) == d)
                    {
                        if (count % 2 == 0)
                        {
                            if (array[c][d] == "Kw" || array[c][d] == "Kb")
                            {
                                matK(array, c, d, count);
                            }
                            else if (array[c][d] == "Bw" || array[c][d] == "Rw" || array[d][c] == "Qw" ||
                                array[c][d] == "pw" || array[c][d] == "Nw")
                            {
                                errorHod();
                                break;
                            }
                            else
                            {
                                array[c][d] = "Rw";
                                array[a][b] = "";
                                count++;
                                break;
                            }
                        }
                        if (count % 2 != 0)
                        {
                            if (array[c][d] == "Kw" || array[c][d] == "Kb")
                            {
                                matK(array, c, d, count);
                            }
                            else if (array[c][d] == "Bb" || array[c][d] == "Rb" || array[c][d] == "Qb" ||
                                array[c][d] == "pb" || array[c][d] == "Nb")
                            {
                                errorHod();
                                break;
                            }
                            else
                            {
                                array[c][d] = "Rb";
                                array[a][b] = "";
                                count++;
                                break;
                            }
                        }
                    }
                }
            }
        }
        else if (a > c && b < d)
        {
            if ((a - n) >= c && (b + n) <= d)
            {
                if (array[a - n][b + n] == "")
                {
                    n++;
                    if ((a - n) == c && (b + n) == d)
                    {
                        if (count % 2 == 0)
                        {
                            if (array[c][d] == "Kw" || array[c][d] == "Kb")
                            {
                                matK(array, c, d, count);
                            }
                            else if (array[c][d] == "Bw" || array[c][d] == "Rw" || array[d][c] == "Qw" ||
                                array[c][d] == "pw" || array[c][d] == "Nw")
                            {
                                errorHod();
                                break;
                            }
                            else
                            {
                                array[c][d] = "Rw";
                                array[a][b] = "";
                                count++;
                                break;
                            }
                        }
                        if (count % 2 != 0)
                        {
                            if (array[c][d] == "Kw" || array[c][d] == "Kb")
                            {
                                matK(array, c, d, count);
                            }
                            else if (array[c][d] == "Bb" || array[c][d] == "Rb" || array[c][d] == "Qb" ||
                                array[c][d] == "pb" || array[c][d] == "Nb")
                            {
                                errorHod();
                                break;
                            }
                            else
                            {
                                array[c][d] = "Rb";
                                array[a][b] = "";
                                count++;
                                break;
                            }
                        }
                    }
                }
            }
        }
        else if (a > c && b > d)
        {
            if ((a - n) >= c && (b - n) >= d)
            {
                if (array[a - n][b - n] == "")
                {
                    n++;
                    if ((a - n) == c && (b - n) == d)
                    {
                        if (count % 2 == 0)
                        {
                            if (array[c][d] == "Kw" || array[c][d] == "Kb")
                            {
                                matK(array, c, d, count);
                            }
                            else if (array[c][d] == "Bw" || array[c][d] == "Rw" || array[d][c] == "Qw" ||
                                array[c][d] == "pw" || array[c][d] == "Nw")
                            {
                                errorHod();
                                break;
                            }
                            else
                            {
                                array[c][d] = "Rw";
                                array[a][b] = "";
                                count++;
                                break;
                            }
                        }
                        if (count % 2 != 0)
                        {
                            if (array[c][d] == "Kw" || array[c][d] == "Kb")
                            {
                                matK(array, c, d, count);
                            }
                            else if (array[c][d] == "Bb" || array[c][d] == "Rb" || array[c][d] == "Qb" ||
                                array[c][d] == "pb" || array[c][d] == "Nb")
                            {
                                errorHod();
                                break;
                            }
                            else
                            {
                                array[c][d] = "Rb";
                                array[a][b] = "";
                                count++;
                                break;
                            }
                        }
                    }
                }

            }
        }
        if (n == 1)
        {
            errorHod();
            break;
        }
    }

}

void figyraB(string array[8][8], int a, int b, int c, int d, int& count)// ладья 
{
    for (int n = 1; n < 8; )
    {
        if (d == b)
        {
            if (a < c && (a + n) <= c)

            {
                if (array[a + n][b] == "")
                {
                    n++;
                    if ((a + n) == c)
                    {
                        if (count % 2 == 0)
                        {
                            if (array[c][d] == "Kw" || array[c][d] == "Kb")
                            {
                                matK(array, c, d, count);
                            }
                            else if (array[c][d] == "Bw" || array[c][d] == "Rw" || array[c][d] == "Qw" ||
                                array[c][d] == "pw" || array[c][d] == "Nw")
                            {
                                errorHod();
                                break;
                            }
                            else
                            {
                                array[c][d] = "Bw";
                                array[a][b] = "";
                                count++;
                                break;
                            }
                        }
                        else if (count % 2 != 0)
                        {
                            if (array[c][d] == "Kw" || array[c][d] == "Kb")
                            {
                                matK(array, c, d, count);
                            }
                            else if (array[c][d] == "Bb" || array[c][d] == "Rb" || array[c][d] == "Qb" ||
                                array[c][d] == "pb" || array[c][d] == "Nb")
                            {
                                errorHod();
                                break;
                            }
                            else
                            {
                                array[c][d] = "Bb";
                                array[a][b] = "";
                                count++;
                                break;
                            }
                        }
                    }
                }
            }
            if (a > c && (a - n) >= 0)
            {
                if (array[a - n][b] == "")
                {
                    n++;
                    if ((a - n) == c)
                    {
                        if (count % 2 == 0)
                        {
                            if (array[c][d] == "Kw" || array[c][d] == "Kb")
                            {
                                matK(array, c, d, count);
                            }
                            else if (array[c][d] == "Bw" || array[c][d] == "Rw" || array[c][d] == "Qw" ||
                                array[c][d] == "pw" || array[c][d] == "Nw")
                            {
                                errorHod();
                                break;
                            }
                            else
                            {
                                array[c][d] = "Bw";
                                array[a][b] = "";
                                count++;
                                break;
                            }
                        }
                        else if (count % 2 != 0)
                        {
                            if (array[c][d] == "Kw" || array[c][d] == "Kb")
                            {
                                matK(array, c, d, count);
                            }
                            else if (array[c][d] == "Bb" || array[c][d] == "Rb" || array[c][d] == "Qb" ||
                                array[c][d] == "pb" || array[c][d] == "Nb")
                            {
                                errorHod();
                                break;
                            }
                            else
                            {
                                array[c][d] = "Bb";
                                array[a][b] = "";
                                count++;
                                break;
                            }
                        }
                    }
                }
            }
        }
        if (c == a)
        {
            if (b < d && (b + n) <= d)
            {
                if (array[a][b + n] == "")
                {
                    n++;
                    if ((b + n) == d)
                    {
                        if (count % 2 == 0)
                        {
                            if (array[c][d] == "Kw" || array[c][d] == "Kb")
                            {
                                matK(array, c, d, count);
                            }
                            else if (array[c][d] == "Bw" || array[c][d] == "Rw" || array[c][d] == "Qw" ||
                                array[c][d] == "pw" || array[c][d] == "Nw")
                            {
                                errorHod();
                                break;
                            }
                            else
                            {
                                array[c][d] = "Bw";
                                array[a][b] = "";
                                count++;
                                break;
                            }
                        }
                        else if (count % 2 != 0)
                        {
                            if (array[c][d] == "Kw" || array[c][d] == "Kb")
                            {
                                matK(array, c, d, count);
                            }
                            else if (array[c][d] == "Bb" || array[c][d] == "Rb" || array[c][d] == "Qb" ||
                                array[c][d] == "pb" || array[c][d] == "Nb")
                            {
                                errorHod();
                                break;
                            }
                            else
                            {
                                array[c][d] = "Bb";
                                array[a][b] = "";
                                count++;
                                break;
                            }
                        }
                    }
                }
            }
            else if (b > d && (b - n) >= 0)
            {
                if (array[a][b - n] == "")
                {
                    n++;
                    if ((b - n) == d)
                    {
                        if (count % 2 == 0)
                        {
                            if (array[c][d] == "Kw" || array[c][d] == "Kb")
                            {
                                matK(array, c, d, count);
                            }
                            else if (array[c][d] == "Bw" || array[c][d] == "Rw" || array[c][d] == "Qw" ||
                                array[c][d] == "pw" || array[c][d] == "Nw")
                            {
                                errorHod();
                                break;
                            }
                            else
                            {
                                array[c][d] = "Bw";
                                array[a][b] = "";
                                count++;
                                break;
                            }
                        }
                        else if (count % 2 != 0)
                        {
                            if (array[c][d] == "Kw" || array[c][d] == "Kb")
                            {
                                matK(array, c, d, count);
                            }
                            else if (array[c][d] == "Bb" || array[c][d] == "Rb" || array[c][d] == "Qb" ||
                                array[c][d] == "pb" || array[c][d] == "Nb")
                            {
                                errorHod();
                                break;
                            }
                            else
                            {
                                array[c][d] = "Bb";
                                array[a][b] = "";
                                count++;
                                break;
                            }
                        }
                    }
                }
            }

        }
        if (n == 1)
        {
            errorHod();
            break;
        }

    }

}// ладья 

int main()
{

    setlocale(LC_ALL, "rus");

    int counterHod = 2;


    string igra[8][8];
    newGame(igra);

    string a;
    string b;
    int hodR1 = 0;
    int hodS1 = 0;
    int hodR2 = 0;
    int hodS2 = 0;

    int k1 = 0;
    int k2 = 0;


    hodAB(igra, a, b, counterHod, hodR1, hodS1, hodR2, hodS2,k1,k2);
    showGame(igra);



}

