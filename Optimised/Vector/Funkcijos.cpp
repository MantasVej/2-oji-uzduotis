#include "Header.h"
#include "Struktura.h"

void Studentai(vector<Mokinys>& mas) {
    string failas = "studentai1000000.txt"; // Duomenu failo pavadinimas
    int n = 1;
    int paz;
    int s;
    bool check;
    char duom;
    char stud;
    do {
        cout << "Ar generuoti nauja studentu duomenu faila? (t/n)? "; cin >> duom;
        check = 1;
        if (duom == 't') {
            cout << "Kiek yra studentu? ";
            while (!(cin >> s)) {
                    cout << "Neteisinga ivestis. Bandykite dar karta " << endl;
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "Kiek yra studentu? ";
                };
            cout << "Kiek studentai turi pazymiu? ";
            while (!(cin >> paz)) {
                    cout << "Neteisinga ivestis. Bandykite dar karta " << endl;
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "Kiek studentai turi pazymiu? ";
                };
            FailoGeneravimas(s, paz, failas);
        }
        else if (duom == 'n') break;
        else { cout << "Neteisinga ivestis. Bandykite dar karta" << endl; check = 0; }
    } while (!check);
        do {
            cout << "Ar studentu duomenis skaityti is failo (t/n)? "; cin >> duom;
            check = 1;
            if (duom == 't') {
                cout << "Galutini rezultata pateikti pagal vidurki/mediana (v/m)? "; cin >> stud;
                while ((stud != 'v') && (stud != 'm')){
                    cout << "Neteisinga ivestis. Bandykite dar karta " << endl;
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "Galutini rezultata pateikti pagal vidurki/mediana (v/m)? "; cin >> stud;
                };
                Skaitymas(mas, n, failas);
                Galutinis(mas, stud);
                Rusiavimas(mas, n);
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
void Galutinis(vector<Mokinys>& temp, char galutinis)
{
    for(auto&s : temp){
        if (galutinis == 'v') Vidurkis(s);
        else Mediana(s);
    }
};
//Skaiciuoja galutini pazymi pagal vidurki
void Vidurkis(Mokinys& temp) {
    double sum = 0; //pazymiu suma
    for (int i = 0; i < temp.getn(); i++) sum += temp.getv(i);
    temp.setgalutinis(0.4 * (sum / (temp.getn())) + 0.6 * temp.getegzaminas());
};
//Skaiciuoja galutini pazymi pagal mediana
void Mediana(Mokinys& temp) {
    int n = temp.getn();
    double mediana = 0; //pazymiu mediana
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) if (temp.getv(i) > temp.getv(j)) temp.swapv(i, j);
    if ((n % 2) == 0) mediana = (temp.getv(n / 2) + temp.getv((n / 2) - 1)) / 2.0;
    else mediana = temp.getv(n / 2);
    temp.setgalutinis(0.4 * mediana + 0.6 * temp.getegzaminas());
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
    string vardas, pavarde;
    int egzaminas;
    cout << "Iveskite studento varda: "; cin >> vardas; temp.setvardas(vardas);
    cout << "Iveskite studento pavarde: "; cin >> pavarde; temp.setpavarde(pavarde);
    do {
        do {
            cout << "Ar " << temp.getn() + 1 << " studento pazymi generuoti atsitiktinai (t/n)? "; cin >> gen;
            check = 1;
            if (gen == 'n') {
                cout << "Iveskite " << temp.getn() + 1 << "-a pazymi: ";
                while (!(cin >> skaicius)) {
                    cout << "Neteisinga ivestis. Bandykite dar karta " << endl;
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "Iveskite " << temp.getn() + 1 << "-a pazymi: ";
                };
                temp.pushv(skaicius);
            }
            else if (gen == 't') {
                temp.pushv(Generavimas());
                cout << temp.getn() + 1 << "-as pazymys yra " << temp.getv(temp.getn()) << endl;
            }
            else { cout << "Neteisinga ivestis. Bandykite dar karta " << endl; check = 0; }
        } while (!check);
        do {
            cout << "Ar dar yra pazymiu (t/n)? "; cin >> paz;
            check = 1;
            if (paz == 'n') { temp.setn(temp.getn() + 1); break; }
            else if (paz == 't') temp.setn(temp.getn()+1);
            else { cout << "Neteisinga ivestis. Bandykite dar karta" << endl; check = 0; }
        } while (!check);
    } while (paz == 't');
    do {
        cout << "Ar studento egzamino rezultata generuoti atsitiktinai (t/n)? "; cin >> gen;
        check = 1;
        if (gen == 'n') {
            cout << "Iveskite egzamino rezultata: ";
            while (!(cin >> egzaminas)) {
                cout << "Neteisinga ivestis. Bandykite dar karta " << endl;
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Iveskite egzamino rezultata: ";
            };
            temp.setegzaminas(egzaminas);
        }
        else if (gen == 't') {
            temp.setegzaminas(Generavimas());
            cout << "Egzamino pazymys yra " << temp.getegzaminas() << endl;
        }
        else { cout << "Neteisinga ivestis. Bandykite dar karta" << endl; check = 0; }
    } while (!check);
}
//Isveda rezultatus
void Isvestis(Mokinys& temp, char stud) {
    if (stud == 'v') Vidurkis(temp);
    else Mediana(temp);
    cout << left << setw(15) << temp.getvardas() << left << setw(15) << temp.getpavarde() << std::fixed << std::setprecision(2) << left << setw(15) << temp.getgalutinis() << endl;
}
void Isvedimas(vector<Mokinys>& mas, string failas) {
    std::ofstream fr(failas);
    std::stringstream my_buffer;
    my_buffer << "Vardas              Pavarde             Galutinis" << endl;
    my_buffer << "-------------------------------------------------" << endl;
    for (int i = 0; i < mas.size(); i++) {
        my_buffer << left << setw(20) << mas[i].getvardas() << left << setw(20) << mas[i].getpavarde() << std::fixed << std::setprecision(2) << left << setw(20) << mas[i].getgalutinis() << "\n";
    };
    fr << my_buffer.str();
    fr.close();
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
    string vardas, pavarde;
    int egzaminas;
    auto start = std::chrono::high_resolution_clock::now(); auto st=start;
    while (my_buffer) {
        if (!my_buffer.eof()) {
            std::getline(my_buffer, eil);
            if (sk == 1) {
                n = Tarpai(eil) - 2;
                sk = 0;
            }
            else {
                std::stringstream s(eil);
                s >> vardas >> pavarde;
                mas[i].setvardas(vardas);
                mas[i].setpavarde(pavarde);
                for (int j = 0; j < n; j++) {
                    s >> paz;
                    mas[i].pushv(paz);
                }
                s >> egzaminas;
                mas[i].setegzaminas(egzaminas);
                mas[i].setn(n);
                mas.push_back(Mokinys());
                i++;
            }
        }
        else break;
    }
    mas.resize(i);
    std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now()-start;
    cout << "Failo duomenu nuskaitymas uztruko: "<< diff.count() << " s\n";
}
void FailoGeneravimas(int n, int paz, string & failas) {
    mt19937 mt(static_cast<int>(hrClock::now().time_since_epoch().count()));
    int_distribution dist(0, 10);

    std::stringstream my_buffer;
    auto start = std::chrono::high_resolution_clock::now(); auto st=start;
    my_buffer << left << setw(20) << "Vardas" << left << setw(20) << "Pavarde";
    for (int i = 0; i < paz; i++) my_buffer << "ND" << left << setw(6) << i + 1;
    my_buffer << "Egz." << endl;
    for (int i = 0; i < n; i++) {
        my_buffer << "Vardas" << left << setw(14) << i + 1 << "Pavarde" << left << setw(13) << i + 1;
        for (int j = 0; j < paz; j++) my_buffer << left << setw(8) << dist(mt);
        my_buffer << dist(mt);
        if(i != n-1) my_buffer << "\n";
    }
    failas = "studentai" + std::to_string(n) + ".txt";
    std::ofstream fr(failas);
    fr << my_buffer.str();
    fr.close();
    std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now()-start;
    cout << "Failo kurimas ir uzdarymas uztruko: "<< diff.count() << " s\n";
    my_buffer.clear();
}
bool Palyginti(Mokinys a, Mokinys b) {
    return a.getgalutinis() < b.getgalutinis();
}
bool Neislaikyta(Mokinys a) {
    return a.getgalutinis() < 5;
}
bool Islaikyta(Mokinys a) {
    return a.getgalutinis() >= 5;
}
void Rusiavimas(vector<Mokinys>& mas, int n)
{
    string failas1 = "vargsiukai" + std::to_string(n) + ".txt";
    string failas2 = "galvociai" + std::to_string(n) + ".txt";
    vector<Mokinys> vargsiukai;
    auto start = std::chrono::high_resolution_clock::now(); auto st = start;
    std::sort(mas.begin(), mas.end(), Palyginti);
    vector<Mokinys>::iterator it = std::find_if(mas.begin(), mas.end(), Islaikyta);
   // vector<Mokinys>::iterator it = std::stable_partition(mas.begin(), mas.end(), Neislaikyta);
    std::copy(mas.begin(), it, back_inserter(vargsiukai));
    mas.erase(mas.begin(), it);

    std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now()-start;
    cout << "Studentu rusiavimas i dvi grupes uztruko: "<< diff.count() << " s\n";
    start = std::chrono::high_resolution_clock::now(); st = start;
    Isvedimas(vargsiukai, failas1);
    Isvedimas(mas, failas2);
     diff = std::chrono::high_resolution_clock::now()-start;
     cout << "Surusiuotu failu isvedimas uztruko: "<< diff.count() << " s\n";
}
