#pragma once

using std::string;
using std::vector;
using std::left;
using std::setw;

class Mokinys
{
private:
    string vardas;
    string pavarde;
    int egzaminas;
    double galutinis;
    int n;
    vector <int> v;
public:
    Mokinys() {
        vardas = "";
        pavarde = "";
        egzaminas = 0;
        galutinis = 0;
        n = 0;
    }

    //destruktorius
    ~Mokinys() {
        v.clear();
    }

    //copy konstruktorius
    Mokinys(const Mokinys& m){
        vardas = m.vardas;
        pavarde = m.pavarde;
        egzaminas = m.egzaminas;
        galutinis = m.galutinis;
        n = m.n;
        v = m.v;
    }

    //copy priskyrimo operatorius
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

    friend std::ostream& operator<<(std::ostream& stream, const Mokinys& m) {
        stream << left << setw(20) << m.vardas << left << setw(20) << m.pavarde << std::fixed << std::setprecision(2) << left << setw(20) << m.galutinis << "\n";
        return stream;
    }

    //set'eriai
    void setstudentas(string a, string b, int c, int d) {
        vardas = a;
        pavarde = b;
        egzaminas = c;
        n = d;
    }
    void setvardas(string a) {
        vardas = a;
    }
    void setpavarde(string a) {
        pavarde = a;
    }
    void setn(int a) {
        n = a;
    }
    void setegzaminas(int a) {
        egzaminas = a;
    }
    void setgalutinis(double a) {
        galutinis = a;
    }
    void setvector(vector<int> a) { 
        v = a; 
    }
    void pushv(int i)
    {
        v.push_back(i);
    }
    //get'eriai
    inline string getvardas() {
        return vardas;
    }
    inline string getpavarde() {
        return pavarde;
    }
    inline int getn() {
        return n;
    }
    inline int getegzaminas() {
        return egzaminas;
    }
    inline double getgalutinis() {
        return galutinis;
    }
    inline int getv(int i)
    {
        return v[i];
    }
    //-----------
    void swapv(int i, int j)
    {
        std::swap(v[i], v[j]);
    }
};
