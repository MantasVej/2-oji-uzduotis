#include "Header.h"
#include "Struktura.h"

int main()
{
    auto start = std::chrono::high_resolution_clock::now(); auto st=start;
    deque<Mokinys> mas;
    mas.push_back(Mokinys());
    Studentai(mas);
    std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now()-start;
    cout << "Visos programos veikimas uztruko: "<< diff.count() << " s\n";
    return 0;
}
