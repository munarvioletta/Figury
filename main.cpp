#include <iostream>
#include <math.h>
#include <cstdlib>
#include <string>


using namespace std;



class Ksztalt{ //klasa abstrakcyjna

public:
    virtual float oblicz_pole() = 0; //metody wirtualne
    virtual void wczytaj() = 0; //metody wirtualne
};

class Kwadrat;
class Prostokat;

class Kolo: public Ksztalt{

    private:

        float r;
        int x,y;
        float P1; //wspolrzedne punktu


    public:

    Kolo(float promien)
    {

    r = promien;

    };

    ~Kolo(){};

    virtual float oblicz_pole(){

        P1 = M_PI*r*r;
        cout<<" Pole kola wynosi: "<<P1<<endl;
        return P1;

    }

    virtual void wczytaj(){

        cout<<" Podaj promien kola: "; cin>>r;

    }

    friend void porownanie(Kolo P1, Kwadrat P2, Prostokat P3);


};


class Kwadrat: public Ksztalt{

    private:

        float a;
        float P2; // szerokosc boku

    public:

    Kwadrat(float bok){

        a = bok ;
    }

    ~Kwadrat(){}

    virtual float oblicz_pole(){

         P2 = a*a;
         cout<<" Pole kwadratu wynosi: "<<P2<<endl;
         return P2;

    }

    virtual void wczytaj(){

        cout<<" Podaj bok kwadratu: "; cin>>a;

    }

    friend void porownanie(Kolo P1, Kwadrat P2, Prostokat P3);


};


class Prostokat: public Ksztalt{

    private:

        float a,b;
        float P3;// szerokosc boku

    public:

    Prostokat(float bok1, float bok2){

        a = bok1;
        b = bok2;

    }

    ~Prostokat(){}

    virtual float oblicz_pole(){

         P3 = a*b;
         cout<<" Pole prostokata wynosi: "<<P3<<endl;
         return P3;

    }

    virtual void wczytaj(){

        cout<<" Podaj bok 1 prostokata: "; cin>>a;
        cout<<" Podaj bok 2 prostokata: "; cin>>b;

    }

    friend void porownanie(Kolo P1, Kwadrat P2, Prostokat P3);
};



int main()
{
    int ile = 2; // liczba obliczonych pol figur
    Kolo k(2);
    Kwadrat kw(2);
    Prostokat p(5,2);

    float *tablica = new float[ile];

    Ksztalt *wsk;
    wsk = &k;
    wsk -> wczytaj();
    tablica[0] = wsk->oblicz_pole();
    wsk = &kw;
    wsk -> wczytaj();
    tablica[1] = wsk->oblicz_pole();
    wsk = &p;
    wsk -> wczytaj();
    tablica[2] = wsk->oblicz_pole();


    porownanie(k, kw, p);

    float *tab;
    tab = new float[ile];

     cout<<"Tablica pol"<<endl<<endl;
    for (int i = 0; i<3; i++){


       *tab = tablica[i];
       cout<<"P"<<i+1<<": "<<(float)*tab<<endl<<endl;
       tab++;
        // ---- to do - wyswietlanie tablicy z polami figur

    }

    delete [] tab;
    delete [] tablica;

    return 0;
}

 //template <class figura>
void porownanie(Kolo k, Kwadrat kw, Prostokat p){

     float min_value;

     if (k.P1 > kw.P2 && p.P3 > kw.P2){

     min_value = kw.P2;
     cout << "Najmniejsza wartosc pola to: "<<min_value<<" - pole Kwadratu"<<endl;

     }

     else if (kw.P2 > k.P1 && p.P3 > k.P1)
     {
      min_value = k.P1;
      cout << "Najmniejsza wartosc pola to: "<<min_value<<" - pole Kola"<<endl;

     }

     else {

     int min_value = p.P3;
     cout << "Najmniejsza wartosc pola to: "<<min_value<<" - pole Prostokata"<<endl;

     }


}
