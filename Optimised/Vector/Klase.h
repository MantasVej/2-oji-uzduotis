#pragma once

using std::string;
using std::vector;
using std::left;
using std::setw;

/**
* Bazinė abstrakčioji klasė Žmogus
*/
class Zmogus
{
protected:
    string vardas;
    string pavarde;

public:
    /**
    * Konstruktorius
    */
    Zmogus(): vardas(""), pavarde("") {}
    /**
    * Vardo geter'is
    */
    inline string getvardas() {
        return vardas;
    }
    /**
    * Pavardes geter'is
    */
    inline string getpavarde() {
        return pavarde;
    }
    /**
    * Virtualioji funkcija vardo seter'is
    */
    virtual void setvardas(string a) = 0;
    /**
    * Virtualioji funkcija pavardes seter'is
    */
    virtual void setpavarde(string a) = 0;
};
/**
* Iš klasė Žmogus išvestinė klasė Mokinys
*/
class Mokinys : Zmogus
{
private:
    int egzaminas;
    double galutinis;
    int n;
    vector <int> v;
public:
    /**
    * Konstruktorius
    */
    Mokinys() {
        vardas = "";
        pavarde = "";
        egzaminas = 0;
        galutinis = 0;
        n = 0;
    }

    /**
    * Destruktorius
    */
    ~Mokinys() {
        v.clear();
    }

    /**
    * Copy konstruktorius
    */
    Mokinys(const Mokinys& m){
        vardas = m.vardas;
        pavarde = m.pavarde;
        egzaminas = m.egzaminas;
        galutinis = m.galutinis;
        n = m.n;
        v = m.v;
    }

    /**
    * Copy priskyrimo operatorius
    */
    Mokinys& operator=(const Mokinys& m) {
        if (this == &m) {
            return *this;
        }
        vardas = m.vardas;
        pavarde = m.pavarde;
        egzaminas = m.egzaminas;
        galutinis = m.galutinis;
        n = m.n;
        v = m.v;
        return *this;
    }
    /**
    * Išvesties operatoriaus << perdengimas
    */
    friend std::ostream& operator<<(std::ostream& stream, const Mokinys& m) {
        stream << left << setw(20) << m.vardas << left << setw(20) << m.pavarde << std::fixed << std::setprecision(2) << left << setw(20) << m.galutinis << "\n";
        return stream;
    }

    /**
    * Studento seter'is
    */
    void setstudentas(string a, string b, int c, int d) {
        vardas = a;
        pavarde = b;
        egzaminas = c;
        n = d;
    }
    /**
    * Vardo seter'is
    */
    void setvardas(string a) {
        vardas = a;
    }
    /**
    * Pavardės seter'is
    */
    void setpavarde(string a) {
        pavarde = a;
    }
    /**
    * Pažymių skaičiaus seter'is
    */
    void setn(int a) {
        n = a;
    }
    /**
    * Egzamino pažymio seter'is
    */
    void setegzaminas(int a) {
        egzaminas = a;
    }
    /**
    * Galutinio pažymio seter'is
    */
    void setgalutinis(double a) {
        galutinis = a;
    }
    /**
    * Pažymių vektoriaus seter'is
    */
    void setvector(vector<int> a) { 
        v = a; 
    }
    /**
    * Prideda pažymį į pažymių vektorių
    */
    void pushv(int i)
    {
        v.push_back(i);
    }
    /**
    * Vardo geter'is
    */
    inline string getvardas() {
        return vardas;
    }
    /**
    * Pavardės geter'is
    */
    inline string getpavarde() {
        return pavarde;
    }
    /**
    * Pažymių skaičiaus geter'is
    */
    inline int getn() {
        return n;
    }
    /**
    * Egzamino pažymio geter'is
    */
    inline int getegzaminas() {
        return egzaminas;
    }
    /**
    * Galutinio balo geter'is
    */
    inline double getgalutinis() {
        return galutinis;
    }
    /**
    * Pažymio geter'is
    */
    inline int getv(int i)
    {
        return v[i];
    }
    /**
    * Sukeičia pažymius vietomis
    */
    void swapv(int i, int j)
    {
        std::swap(v[i], v[j]);
    }
};
