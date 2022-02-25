#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include <vector>
#include <random>

using std::cout;
using std::cin;
using std::string;
using std::left;
using std::setw;
using std::endl;
using std::vector;

const char CDfv[] = "studentai10000.txt";
const int S = 10000; //studentu skaicius
const int P = 15; //pazymiu skaicius

struct Mokinys
{
    string vardas = "";
    string pavarde = "";
    int n = 0;
    vector <int> v;
    int egzaminas = 0;
    double galutinis = 0;
};
//Skaiciuoja galutini pazymi pagal vidurki
void Vidurkis(Mokinys& temp) {
    double sum = 0; //pazymiu suma
    for (int i = 0; i < temp.n + 1; i++) sum += temp.v[i];
    temp.galutinis = 0.4 * (sum / (temp.n + 1)) + 0.6 * temp.egzaminas;
};
//Skaiciuoja galutini pazymi pagal mediana
void Mediana(Mokinys& temp) {
    int n = temp.n + 1;
    double mediana = 0; //pazymiu mediana
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) if (temp.v[i] > temp.v[j]) std::swap(temp.v[i], temp.v[j]);
    if ((n % 2) == 0) mediana = (temp.v[n / 2] + temp.v[(n / 2) - 1]) / 2.0;
    else mediana = temp.v[n / 2];
    temp.galutinis = 0.4 * mediana + 0.6 * temp.egzaminas;
};
//Atsitiktinai generuoja pazymi nuo 1 iki 10
int Generavimas() {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(0, 10);
    return dist(mt);
};
//Skaito duomenis apie studenta
void Ivestis(Mokinys& temp) {
    char paz;
    char gen;
    bool check;
    int skaicius;
    cout << "Iveskite studento varda: "; cin >> temp.vardas;
    cout << "Iveskite studento pavarde: "; cin >> temp.pavarde;
    do {
        do {
            cout << "Ar " << temp.n + 1 << " studento pazymi generuoti atsitiktinai (t/n)? "; cin >> gen;
            check = 1;
            if (gen == 'n') {
                cout << "Iveskite " << temp.n + 1 << "-a pazymi: ";
                while (!(cin >> skaicius)) {
                    cout << "Neteisinga ivestis. Bandykite dar karta " << endl;
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "Iveskite " << temp.n + 1 << "-a pazymi: ";
                };
                temp.v.push_back(skaicius);
            }
            else if (gen == 't') {
                temp.v.push_back(Generavimas());
                cout << temp.n + 1 << "-as pazymys yra " << temp.v[temp.n] << endl;
            }
            else { cout << "Neteisinga ivestis. Bandykite dar karta " << endl; check = 0; }
        } while (!check);
        do {
            cout << "Ar dar yra pazymiu (t/n)? "; cin >> paz;
            check = 1;
            if (paz == 'n') break;
            else if (paz == 't') temp.n++;
            else { cout << "Neteisinga ivestis. Bandykite dar karta" << endl; check = 0; }
        } while (!check);
    } while (paz == 't');
    do {
        cout << "Ar studento egzamino rezultata generuoti atsitiktinai (t/n)? "; cin >> gen;
        check = 1;
        if (gen == 'n') {
            cout << "Iveskite egzamino rezultata: ";
            while (!(cin >> temp.egzaminas)) {
                cout << "Neteisinga ivestis. Bandykite dar karta " << endl;
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Iveskite egzamino rezultata: ";
            };
        }
        else if (gen == 't') {
            temp.egzaminas = Generavimas();
            cout << "Egzamino pazymys yra " << temp.egzaminas << endl;
        }
        else { cout << "Neteisinga ivestis. Bandykite dar karta" << endl; check = 0; }
    } while (!check);
}
//Isveda rezultatus
void Isvestis(Mokinys& temp, char stud) {
    if (stud == 'v') Vidurkis(temp);
    else Mediana(temp);
    cout << left << setw(15) << temp.vardas << left << setw(15) << temp.pavarde << std::fixed << std::setprecision(2) << left << setw(15) << temp.galutinis << endl;
}
int main()
{
    int n = 1;
    vector<Mokinys> mas;
    mas.push_back(Mokinys());
    bool check; //kintamasis skirtas tikrinti duomenu ivesciai
    char stud;
    cout << "Ar studentu duomenis skaityti is failo (t/n)? "; cin >> stud;
    if (stud == 't') {

    }
    else if (stud == 'n') {
        for (int i = 0; i < n; i++) {
            Ivestis(mas[i]);
            do {
                cout << "Ar norite ivesti kita studenta (t/n)? "; cin >> stud;
                check = 1;
                if (stud == 't') {
                    n++;
                    mas.push_back(Mokinys());
                }
                else if (stud == 'n') break;
                else { cout << "Neteisinga ivestis. Bandykite dar karta" << endl; check = 0; }
            } while (!check);
        }
        do {
            cout << "Galutini rezultata pateikti pagal vidurki/mediana (v/m)? "; cin >> stud;
            check = 1;
            if (stud == 'v') cout << "Vardas         Pavarde        Galutinis(vid.)" << endl;
            else if (stud == 'm') cout << "Vardas         Pavarde        Galutinis(med.)" << endl;
            else { cout << "Neteisinga ivestis. Bandykite dar karta" << endl; check = 0; }
        } while (!check);
    }
    cout << "---------------------------------------------" << endl;
    for (int i = 0; i < n; i++) {
        Isvestis(mas[i], stud);
    }
    cout << "---------------------------------------------" << endl;
    return 0;
}
