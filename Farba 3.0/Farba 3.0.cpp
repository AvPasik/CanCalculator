//Version 0.001 alpha








#include <iostream>
#include <stdio.h>    
#include <math.h>  

using namespace std;

int main()
{
    //deklaracja zmiennych
    int liczbaPuszekFarby;
    double pojemnoscPuszkiFarby = 1.25;
    double dlugoscPomieszczenia;
    double szerokoscPomieszczenia;
    double wysokoscPomieszczenia;
    double wydajnoscFarby;

    double szerokoscObiektu = 0.9;
    double wysokoscOkna = 1.0;
    double wysokoscDrzwi = 2.0;
    double powierzchniaOkna = wysokoscOkna * szerokoscObiektu;
    double powierzchniaDrzwi = wysokoscDrzwi * szerokoscObiektu;
    double lacznaPowierzchniaElementow = 0;

    int liczbaDrzwi = 0;
    int liczbaOkien = 0;
    int maksymalnaLiczbaElementow = 5;


    int liczbaObiektowJakieSieMieszcza = 0;

    cout << "Obliczanie ilosci puszek farby do pomalowania pomieszczen" << endl;

    cout << "Podaj dlugosc pomieszczenia w metrach" << endl;
    cin >> dlugoscPomieszczenia;

    cout << "Podaj szerokosc pomieszczenia w metrach" << endl;
    cin >> szerokoscPomieszczenia;

    cout << "Podaj wysokosc pomieszczenia w metrach" << endl;
    cin >> wysokoscPomieszczenia;

    cout << "Podaj wydajnosc farby, ktora planujesz zakupic" << endl;
    cin >> wydajnoscFarby;



    //oblicz liczbe obiektow mieszczacych sie na dlugosci pomieszczenia (dlugosc pomieszczenia to szerokosc jednej ze scian)
    if (dlugoscPomieszczenia * 0.3 > szerokoscObiektu && wysokoscPomieszczenia > wysokoscDrzwi) {
        int liczbaObiektow = 2 * ((dlugoscPomieszczenia * 0.3) / szerokoscObiektu);
        liczbaObiektowJakieSieMieszcza += liczbaObiektow;
    }

    //oblicz liczbe obiektow mieszczacych sie na szerokosci pomieszczenia
    if (szerokoscPomieszczenia * 0.3 > szerokoscObiektu && wysokoscPomieszczenia > wysokoscDrzwi) {
        int liczbaObiektow = 2 * ((szerokoscPomieszczenia * 0.3) / szerokoscObiektu);
        liczbaObiektowJakieSieMieszcza += liczbaObiektow;
    }

    if (liczbaObiektowJakieSieMieszcza < 1) {
        cout << "Pomieszczenie jest zbyt male" << endl;
        return 0;
    }

    //oblicz ilosc konkretnych elementow, jakie zmieszcza sie w pomieszczeniu uwzgledniajac stos liczbaObiektowJakieSieMieszcza
    if (liczbaObiektowJakieSieMieszcza >= maksymalnaLiczbaElementow) {
        for (int i = 0; i < maksymalnaLiczbaElementow; i++) {
            if (i == 0 || i == 4) {
                liczbaDrzwi += 1;
            }
            else {
                liczbaOkien += 1;
            }
        }
    }
    else {
        for (int i = 0; i < liczbaObiektowJakieSieMieszcza; i++) {
            if (i == 0 || i == 4) {
                liczbaDrzwi += 1;
            }
            else {
                liczbaOkien += 1;
            }
        }
    }

    lacznaPowierzchniaElementow = ((liczbaDrzwi * powierzchniaDrzwi) + (liczbaOkien * powierzchniaOkna));

    liczbaPuszekFarby = ceil((2 * (szerokoscPomieszczenia * wysokoscPomieszczenia) + 2 * (dlugoscPomieszczenia * wysokoscPomieszczenia) - lacznaPowierzchniaElementow) / (wydajnoscFarby * pojemnoscPuszkiFarby));


    cout << "Liczba drzwi: " << liczbaDrzwi << endl;
    cout << "Liczba okien: " << liczbaOkien << endl;

    cout << " Do pomalowania pomieszczenia potrzeba kupic " << liczbaPuszekFarby << " puszek farby." << endl;


    return 0;
}