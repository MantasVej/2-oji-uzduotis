#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <ctime>
#include <vector>
#include <iterator>
#include <chrono>
#include <random>
#include <sstream>
#include <exception>
#include <algorithm>
#include "Klase.h"

using std::cout;
using std::cin;
using std::left;
using std::setw;
using std::endl;
using std::mt19937;


using hrClock = std::chrono::high_resolution_clock;
typedef std::uniform_int_distribution<int>  int_distribution;

void Studentai(vector<Mokinys>&);
void Vidurkis(Mokinys&);
void Mediana(Mokinys&);
int Generavimas();
void Ivestis(Mokinys&);
void Isvestis(Mokinys&, char);
int Tarpai(string eil);
void Skaitymas(vector<Mokinys>&, int&, string);
void FailoGeneravimas(int, int, string&);
void Rusiavimas(vector<Mokinys>&, int);
void Galutinis(vector<Mokinys>&, char);
