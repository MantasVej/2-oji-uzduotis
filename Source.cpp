#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Mokinys
{
    string vardas = "";
    string pavarde = "";
    int P[3] = { 0 };
    int egzaminas = 0;
    double galutinis = 0;
};
void Ivestis(Mokinys& temp) {
    int n = 3;
    double sum = 0;
    cout << "Iveskite studento varda: "; cin >> temp.vardas;
    cout << "Iveskite studento pavarde: "; cin >> temp.pavarde;
    for (int i = 0; i < n; i++) {
        cout << "Iveskite " << i + 1 << "-a pazymi: "; cin >> temp.P[i];
        sum += temp.P[i];
    }
    cout << "Iveskite egzamino rezultata: "; cin >> temp.egzaminas;
    temp.galutinis = 0.4 * (sum / n) + 0.6 * temp.egzaminas;
}
void Isvestis(Mokinys& temp) {
    cout << left << setw(15) << temp.vardas << left << setw(15) << temp.pavarde << fixed << setprecision(2) << left << setw(15) << temp.galutinis << endl;
}
int main()
{
    Mokinys* mas = new Mokinys[3];
    for (int i = 0; i < 3; i++) {
        Ivestis(mas[i]);
    }
    cout << "Vardas         Pavarde        Galutinis(vid.)" << endl;
    cout << "---------------------------------------------" << endl;
    for (int i = 0; i < 3; i++) {
        Isvestis(mas[i]);
    }
    cout << "---------------------------------------------" << endl;
    delete[] mas;
    return 0;
}
