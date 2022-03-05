#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <ctime>
#include <vector>
#include <random>
#include <sstream>
#include <exception>
#include "Struktura.h"

using std::cout;
using std::cin;
using std::left;
using std::setw;
using std::endl;

const char CDfv[] = "kursiokai.txt";
const char CRfv[] = "rezultatai.txt";

void Studentai(vector<Mokinys>&);
void Vidurkis(Mokinys&);
void Mediana(Mokinys&);
int Generavimas();
void Ivestis(Mokinys&);
void Isvestis(Mokinys&, char);
int Tarpai(string eil);
void Skaitymas(vector<Mokinys>&, int&);
bool Palyginti(Mokinys, Mokinys);
void Isvedimas(vector<Mokinys>&, int);