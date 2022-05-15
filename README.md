# 1-oji užduotis
Programos diegimo ir naudojimo instrukcija:

1. Atveriamas projekto aplnkas ir paleidžiamas failas "Studentai.msi".
2. Pasirenkamas programos diegimo aplankas.
3. Atidaromas įdiegtos programos aplankas ir paleidžiamas failas "Laboratorinis2.exe".
4. Norint generuoti naują duomenų failą rašomas simbolis "t", kitu atveju rašoma "n".
5. Pasirinkus generuoti naują duomenų failą reikės įvesti mokinių skaičių ir pažymių kiekį.
6. Norint skaityti duomenis iš failo rašomas simbolis "t", o norint suvesti duomenis ranka rašoma "n". 
7. Pasirinkus skaityti duomenis iš failo, reikės įvesti failo duomenų failo pavadinimą, o jei tokio failo aplanke nėra, programa baigs darbą.
8. Pasirinkus skaityti duomenis iš failo reikės pasirinkti galutinį pažymį skaičiuoti pagal vidurkį (įvedus "v") arba medianą (įvedus "m"). Programos rezultatai išvedami į rezultatų failius "galvociai.txt" ir "vargsiukai.txt".
9. Pasirinkus duomenis suvesti ranka reikės įvesti kiekvieno studento vardą, pavardę, pažymius ir egzamino rezultatą.
10. Baigus suvesti visus studentus reikės reikės pasirinkti galutinį pažymį skaičiuoti pagal vidurkį (įvedus "v") arba medianą (įvedus "m'). Programos rezultatai išvedami į ekraną.

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

Programos versija v0.5
1. Šioje versijoje yra 3 programos, kurios studentų duomenis saugo vector, list ir deque tipo konteineriuose.

Programų darbo laikai dirbant su skirtingo tipo konteineriais: 
![Vector](https://user-images.githubusercontent.com/92882227/163442668-dc3ef4ed-b841-40a9-a719-620fbbcf31f5.PNG)
![List](https://user-images.githubusercontent.com/92882227/163442676-5c840900-c091-4409-afa6-a5cdaf5cf721.PNG)
![Deque](https://user-images.githubusercontent.com/92882227/163442864-7a842eee-b67b-4dd7-9114-1901b0284b45.PNG)
(Visuose failuose studentai turi po 5 pažymius, o galutinis pažymis skaičiuojamas pagal vidurkį)

Dirbant su nedideliais duomenų failais programų su skirtingais konteineriais darbo laiko skirtumai labai nežymūs, tačiau su didesniais failais (1000000, 10000000 studentų) programa su vector tipo konteineriais dirba kur kas greičiau už list ir deque tipo konteinerius.

Testų metu naudoto kompiuterio parametrai: 
1. 11th Gen Intel(R) Core(TM) i7-11800H @ 2.30GHz CPU
2. 16GB RAM
3. Kingston 512GB SSD Solid State Drive NVMe PCle 3.0 x4

Programos versija v1.0
1. Studentų rūšiavimas realizuotas 2 strategijomis. 
2. Paruoštas programos Makefile

Strategijų laikų palyginimas:

1 Strategija: Bendro studentų konteinerio skaidymas į du naujus to paties tipo konteinerius:
![Vec](https://user-images.githubusercontent.com/92882227/163689096-614ae56f-74ac-460c-aba1-a9434e4469cc.PNG)
![Lis](https://user-images.githubusercontent.com/92882227/163689098-82876601-5515-447d-90a5-6cbe68921590.PNG)
![Deq](https://user-images.githubusercontent.com/92882227/163689100-65e2180f-e18c-42ab-9d1c-763754afa9a0.PNG)

2 Strategija: Bendro studentų konteinerio skaidymas panaudojant tik vieną naują konteinerį:
![Vec](https://user-images.githubusercontent.com/92882227/163689147-dcc5cd02-541a-4390-b8ae-9daf28e65acc.PNG)
![Lis](https://user-images.githubusercontent.com/92882227/163689152-16c8b786-c544-46b6-b8c7-cb3c6c26ac4e.PNG)
![Deq](https://user-images.githubusercontent.com/92882227/163689153-aa51cf1e-b1a0-409a-ae1a-f46e89cd7620.PNG)
(Visuose failuose studentai turi po 5 pažymius, o galutinis pažymis skaičiuojamas pagal vidurkį)

Taikant bet kurią iš dviejų strategijų greičiausiai vis tiek dirba programa su vector tipo konteineriais. Visos realizacijos greičiau veikia naudojant 2 strategiją, tačiau žymiausias pokytis jaučiamas su list tipo konteineriu ~15s greičiau, kur vector ir deque suveikia mažiau negu 10s greičiau.

Programos versija v1.1
1. Struktūra pakeista į klasę.
2. Atlikti testai:

Su 1000000 studentų:

![1000000](https://user-images.githubusercontent.com/92882227/166112466-550e4f4e-8951-4cd6-acd0-bb3a4a58bc64.PNG)

Su 10000000 studentų:

![10000000](https://user-images.githubusercontent.com/92882227/166112487-491f76cc-cc89-4493-8463-2c2e45534311.PNG)

Make file su -O1 flag:

![1](https://user-images.githubusercontent.com/92882227/166112518-23443090-32da-44c8-a842-90c403d069d1.PNG)

Make file su -O2 flag:

![2](https://user-images.githubusercontent.com/92882227/166112528-342c0bf0-4b39-4748-ae65-cbeb5adc6828.PNG)

Make file su -O3 flag:

![3](https://user-images.githubusercontent.com/92882227/166112551-419ecd61-49d2-43ce-991a-f1d5f7ecc29c.PNG)

Programos versija v1.2

1. Programa realizuota pritaikant "Rule of three" principą.
2. Realizuotas išvesties operatoriaus << perdengimas.

Programos versija v1.5

1. Sukurta abstrakčioji bazinė klasė "Žmogus".
2. Klasė "Mokinys" dabar yra derived iš bazinės klasės.

Programos versija v2.0
1. Parengta programos dokumentacija.
2. Sukurtas programos įdiegimo failas "Studentai.msi".
