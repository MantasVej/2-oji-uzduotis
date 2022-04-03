# 1-oji užduotis
Programos versija v0.1

1. Programa nuskaito vartotojo įvedamus reikiamus duomenis apie studentus(studento vardą, pavardę, namų darbų ir egzamino rezultatą). Įvedinėdamas duomenis vartotojas pats nusprendžia kelių studentų duomenis bei kiek pažymių kiekvienam studentui nori įvesti. Siekiant išvengti klaidų duomenų įvedimo metu bei, kad programa "neužlūžtų", įvedant duomenis yra patikrinama ar įvestas pažymys yra intenger tipo, priešingu atveju vartotojo yra paprašoma iš naujo įvesti pažymį.
2. Realizuota galimybė prieš įvedant pažymį pasirinkti, kad jis būtų sugeneruotas atsitiktinai.
3. Programa suskaičiuoja galutinius studentų rezultatus pasirinktinai pagal vidurkį arba medianą ir išveda į lentelę.
4. Versija Array.cpp studentų pažymius saugo C tipo masyve, o Vector.cpp - std::vector tipo konteineryje.

Programos versija v0.2

1. Patobulinta atsitiktinių skaičių generacja. Šioje versijoje naudojama random_device.
3. Yra galimybė studentų duomenis skaityti iš failo. Nuskaitymas veikia su bet kokio dydžio duomenų failais.
4. Duomenys rikiuojami pagal studentų vardus.
5. Rezultatai įrašomi į faillą rezultatai.txt.

Programos versija v0.3

1. Šioje versijoje programos antraštės ir struktūros perkeltos į failus Header.h ir Struktura.h.
2. Į failą Funkcijos.cpp buvo perkeltos visos funkcijos iš failo Source.cpp.
3. Patikrinti ar egzistuoja duomenų failas naudojama exception handling (try, catch).

Programos versija v0.4

1. Šioje versijoje padarytas duomenų failų generatorius.
2. Studentai yra išrūšiuojami į du failus: "galvociai.txt" (jei gal. balas >= 5.0) ir "vargsiukai.txt" (jei gal. balas < 5.0)
3. Atliekama programos veikimo greičio analizė.

![image](https://user-images.githubusercontent.com/92882227/159137619-271a8522-7fa0-4961-b2ad-71b224a613d7.png)

