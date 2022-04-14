#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <ctime>
#include <deque>
#include <iterator>
#include <chrono>
#include <random>
#include <sstream>
#include <exception>
#include <algorithm>
#include "Struktura.h"

using std::cout;
using std::cin;
using std::left;
using std::setw;
using std::endl;
using std::mt19937;


using hrClock = std::chrono::high_resolution_clock;
typedef std::uniform_int_distribution<int>  int_distribution;

void Studentai(deque<Mokinys>&);
void Vidurkis(Mokinys&);
void Mediana(Mokinys&);
int Generavimas();
void Ivestis(Mokinys&);
void Isvestis(Mokinys&, char);
int Tarpai(string eil);
void Skaitymas(deque<Mokinys>&, int&, string);
void FailoGeneravimas(int, int, string&);
void Rusiavimas(deque<Mokinys>&, int);
void Galutinis(deque<Mokinys>&, char);
