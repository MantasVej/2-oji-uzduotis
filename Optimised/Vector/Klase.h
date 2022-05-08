#pragma once

using std::string;
using std::vector;

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
    ~Mokinys() {}

    //copy konstruktorius
    Mokinys(const Mokinys& m) : vardas(m.vardas), pavarde(m.pavarde), egzaminas(m.egzaminas), galutinis(m.galutinis), n(m.n), v(m.v) {}

    //copy priskyrimo operatorius
    Mokinys& operator=(Mokinys m) {
        swap(m);
        return *this;
    }
    void swap(Mokinys& m)
    {
        using std::swap;
        swap(vardas, m.vardas);
        swap(pavarde, m.pavarde);
        swap(egzaminas, m.egzaminas);
        swap(galutinis, m.galutinis);
        swap(n, m.n);
        swap(v, m.v);
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
