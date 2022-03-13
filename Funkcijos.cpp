#include "Header.h"
#include "Struktura.h"

void Studentai(vector<Mokinys>& mas) {
    int n = 1;
    int paz;
    bool check; //kintamasis skirtas tikrinti duomenu ivesciai
    char duom;
    char stud;
    string failas;
    int s = 1000000; //studentu skaiciu duomenu failui generuoti
    do {
        cout << "Ar generuoti nauja studentu duomenu faila? (t/n)? "; cin >> duom;
        check = 1;
        if (duom == 't') {
            cout << "Kiek studentai turi pazymiu? "; cin >> paz;
            cout << "Galutini rezultata pateikti pagal vidurki/mediana (v/m)? "; cin >> stud;
            FailoGeneravimas(s, paz, failas);
            Skaitymas(mas, n, failas);
            Rusiavimas(mas, s, stud);
        }
        else if (duom == 'n') break;
        else { cout << "Neteisinga ivestis. Bandykite dar karta" << endl; check = 0; }
    } while (!check);
    if (duom == 'n') {
        do {
            cout << "Ar studentu duomenis skaityti is failo (t/n)? "; cin >> duom;
            check = 1;
            if (duom == 't') {
                Skaitymas(mas, n, CDfv);
                Isvedimas(mas, n, CRfv);
            }
            else if (duom == 'n') {
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

                cout << "---------------------------------------------" << endl;
                for (int i = 0; i < n; i++) {
                    Isvestis(mas[i], stud);
                }
                cout << "---------------------------------------------" << endl;
            }
            else { cout << "Neteisinga ivestis. Bandykite dar karta" << endl; check = 0; }
        } while (!check);
    }
}
//Skaiciuoja galutini pazymi pagal vidurki
void Vidurkis(Mokinys& temp) {
    double sum = 0; //pazymiu suma
    for (int i = 0; i < temp.n; i++) sum += temp.v[i];
    temp.galutinis = 0.4 * (sum / (temp.n)) + 0.6 * temp.egzaminas;
};
//Skaiciuoja galutini pazymi pagal mediana
void Mediana(Mokinys& temp) {
    int n = temp.n;
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
            if (paz == 'n') { temp.n++; break; }
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
//Skaiciuoja kiek string eiluteje yra tarpu
int Tarpai(string eil) {
    int tarpai = 0;
    for (int i = 0; eil[i] != '\0'; ++i)
    {
        if ((eil[i] == ' ') && (eil[i - 1] != ' '))
            tarpai++;
    }
    return tarpai;
}
void Skaitymas(vector<Mokinys>& mas, int& i, string failas) {
    mas.reserve(10000000);
    i = 0; //studentu skaicius

    string eil;
    std::stringstream my_buffer;

    try {
        std::ifstream fd(failas);
        fd.exceptions(std::ifstream::failbit);
        my_buffer << fd.rdbuf();
        fd.close();
    }
    catch(std::exception& e) {
        cout << "Toks duomenu failas neegzistuoja.";
    }
    bool sk = 1;
    int paz;
    int n = 0; //pazymiu skaicius
    while (my_buffer) {
        if (!my_buffer.eof()) {
            std::getline(my_buffer, eil);
            if (sk == 1) {
                n = Tarpai(eil) - 2;
                sk = 0;
            }
            else {
                std::stringstream s(eil);
                s >> mas[i].vardas >> mas[i].pavarde;
                for (int j = 0; j < n; j++) {
                    s >> paz;
                    mas[i].v.push_back(paz);
                }
                s >> mas[i].egzaminas;
                mas[i].n = n;
                mas.push_back(Mokinys());
                i++;
            }
        }
        else break;
    }
}
bool Palyginti(Mokinys a, Mokinys b) {
    return a.vardas < b.vardas;
}
void Isvedimas(vector<Mokinys>& mas, int n, string failas) {
    std::ofstream fr(failas);
    std::sort(mas.begin(), mas.end() - 1, Palyginti);
    std::stringstream my_buffer;
    my_buffer << "Vardas         Pavarde        Galutinis(vid.)     Galutinis(med.)" << endl;
    my_buffer << "-----------------------------------------------------------------" << endl;
    for (int i = 0; i < n; i++) {
        Vidurkis(mas[i]);
        my_buffer << left << setw(15) << mas[i].vardas << left << setw(15) << mas[i].pavarde << std::fixed << std::setprecision(2) << left << setw(20) << mas[i].galutinis;
        Mediana(mas[i]);
        my_buffer << std::fixed << std::setprecision(2) << left << setw(20) << mas[i].galutinis << endl;
    };
    fr << my_buffer.str();
    fr.close();
}
void FailoGeneravimas(int n, int paz, string & failas) {
    failas = "studentai" + std::to_string(n) + ".txt";
    std::ofstream fr(failas);
    std::stringstream my_buffer;
    my_buffer << left << setw(20) << "Vardas" << left << setw(20) << "Pavarde";
    for (int i = 0; i < paz; i++) my_buffer << "ND" << left << setw(6) << std::to_string(i + 1);
    my_buffer << "Egz." << endl;
    for (int i = 0; i < n; i++) {
        if(i != 0) my_buffer << endl;
        my_buffer << "Vardas" << left << setw(14) << std::to_string(i + 1)  << "Pavarde" << left << setw(13) << std::to_string(i + 1);
        for (int j = 0; j <= paz; j++) my_buffer << left << setw(8) << Generavimas();
    }
    fr << my_buffer.str();
    fr.close();
}
void Rusiavimas(vector<Mokinys>& mas, int n, char galutinis)
{
    string failas1 = "vargsiukai" + std::to_string(n) + ".txt";
    string failas2 = "galvociai" + std::to_string(n) + ".txt";
    std::ofstream fr1(failas1);
    std::ofstream fr2(failas2);
    std::stringstream vargsiukai;
    std::stringstream galvociai;
    vargsiukai << "Vardas              Pavarde             Galutinis" << endl;
    vargsiukai << "-------------------------------------------------" << endl;
    galvociai << "Vardas              Pavarde             Galutinis" << endl;
    galvociai << "-------------------------------------------------" << endl;
    for(int i = 0; i < n; i++){
        if (galutinis == 'v') Vidurkis(mas[i]);
        else Mediana(mas[i]);
        if(mas[i].galutinis < 5) vargsiukai << left << setw(20) << mas[i].vardas << left << setw(20) << mas[i].pavarde << std::fixed << std::setprecision(2) << left << setw(20) << mas[i].galutinis << endl;
        else galvociai << left << setw(20) << mas[i].vardas << left << setw(20) << mas[i].pavarde << std::fixed << std::setprecision(2) << left << setw(20) << mas[i].galutinis << endl;
    }
    fr1 << vargsiukai.str();
    fr2 << galvociai.str();
    fr1.close();
    fr2.close();
}
