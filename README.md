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
