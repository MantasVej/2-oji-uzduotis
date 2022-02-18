#include <iostream>
#include <string>
#include <iomanip>

using std::cout;
using std::cin;
using std::string;
using std::left;
using std::setw;
using std::endl;

struct Mokinys
{
    string vardas = "";
    string pavarde = "";
    int P[3] = { 0 };
    int egzaminas = 0;
    double galutinis = 0;
};
//Skaiciuoja galutini pazymi pagal vidurki
void Vidurkis(Mokinys& temp, int n) {
    int sum = 0; //pazymiu suma
    for (int i = 0; i < n; i++) sum += temp.P[i];
    temp.galutinis = 0.4 * (sum / n) + 0.6 * temp.egzaminas;
};
//Skaiciuoja galutini pazymi pagal mediana
void Mediana(Mokinys& temp, int n) {
    double mediana = 0; //pazymiu mediana
    for (int i = 0; i < n; i++)
        for (int j = i+1; j <= n; j++) if (temp.P[i] > temp.P[j]) std::swap(temp.P[i], temp.P[j]);
    if ((n % 2) == 0) mediana = (temp.P[n / 2] + temp.P[(n / 2) - 1]) / 2.0;
    else mediana = temp.P[n/2];
    temp.galutinis = 0.4 * mediana + 0.6 * temp.egzaminas;
};
//Tikrina ar teisingai ivedamas pazymys
void Pazymys(Mokinys& temp, int i) {
    cout << "Iveskite " << i + 1 << "-a pazymi: ";
    if (!(cin >> temp.P[i])) {
        cout << "Neteisinga ivestis. Bandykite dar karta " << endl;
        cin.clear();
        cin.ignore(10000,'\n');
        Pazymys(temp, i);
    }
}
//Skaito duomenis apie studenta
void Ivestis(Mokinys& temp, int n) {
    cout << "Iveskite studento varda: "; cin >> temp.vardas;
    cout << "Iveskite studento pavarde: "; cin >> temp.pavarde;
    for (int i = 0; i < n; i++) {
        Pazymys(temp, i);
    }
    cout << "Iveskite egzamino rezultata: "; cin >> temp.egzaminas;
}
//Isveda rezultatus
void Isvestis(Mokinys& temp, int n, char rez) {
    if (rez == 'v') Vidurkis(temp, n);
    else Mediana(temp, n);
    cout << left << setw(15) << temp.vardas << left << setw(15) << temp.pavarde << std::fixed << std::setprecision(2) << left << setw(15) << temp.galutinis << endl;
}
//Perkopijuoja studentu duomenis i kita masyva dinamineje atmintyje
void Kopijuoti(Mokinys*& temp, int dydis) {
    Mokinys* kopija = new Mokinys[dydis];
    for (int i = 0; i < dydis - 1; i++)
        kopija[i] = temp[i];
    delete [] temp;
    temp = kopija;
}
int main()
{
    int dydis = 1; //pradinis studentu skaicius
    Mokinys* mas = new Mokinys[dydis];
    int n = 3; // namu darbu skaicius
    bool check; //kintamasis skirtas tikrinti duomenu ivesciai
    char stud;
    char rez;
    for (int i = 0; i < dydis; i++) {
        Ivestis(mas[i], n);
        do {
            cout << "Ar norite ivesti kita studenta (t/n)? "; cin >> stud;
            check = 1;
            if (stud == 't') {
                dydis++;
                Kopijuoti(mas, dydis);
            }
            else if (stud == 'n');
            else { cout << "Neteisinga ivestis. Bandykite dar karta" << endl; check = 0; }
        } while (!check);
    }
    do {
        cout << "Galutini rezultata pateikti pagal vidurki/mediana (v/m)? "; cin >> rez;
        check = 1;
        if (rez == 'v') cout << "Vardas         Pavarde        Galutinis(vid.)" << endl;
        else if (rez == 'm') cout << "Vardas         Pavarde        Galutinis(med.)" << endl;
        else {cout << "Neteisinga ivestis. Bandykite dar karta" << endl; check = 0;}
    } while (!check);
    cout << "---------------------------------------------" << endl;
    for (int i = 0; i < dydis; i++) {
        Isvestis(mas[i], n, rez);
    }
    cout << "---------------------------------------------" << endl;
    delete[] mas;
    return 0;
}
