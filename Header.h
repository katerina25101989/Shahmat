#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>



using namespace std;


void showGame(string);
void newGame(string);
void privetstvie();
void errorHod();
void stringNamber(string, int&, int&);
void hodAB(string, string, string, int&, int&, int&, int&, int&,int&,int &);
void figyra(string array[8][8], int, int, int, int, int&,int &, int &);
void figyraB(string array[8][8], int, int, int, int, int&);
void figyraR(string array[8][8], int, int, int, int, int&);
void figyraP(string array[8][8], int, int, int, int, int&);
void figyraN(string array[8][8], int, int, int, int, int&);
void figyraQ(string array[8][8], int, int, int, int, int&);
void figyraK(string array[8][8], int, int, int, int, int&,int &,int &);
void matK(string array[8][8], int, int, int&);
void rakirovkaK(string array[8][8], int, int, int, int, int&, int&, int&);
void rakirovkaB(string array[8][8], int, int, int, int, int&, int&, int&);