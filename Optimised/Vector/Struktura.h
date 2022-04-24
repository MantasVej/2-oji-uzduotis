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
    Mokinys() : egzaminas(0) { }  // default konstruktorius

    //set'eriai
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
