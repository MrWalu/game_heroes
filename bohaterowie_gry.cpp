#include <iostream>
#include <cstdlib>

using namespace std;

//Klasa Bohater
class Bohater{
private:
    string pseudonim;
    string klasa;
    int sila_ataku;
    static int licznik;
public:
    //Konstruktor domy�lny. Przy ka�dym utworzeniu obiektu licznik wzrasta o 1.
    Bohater(){
        licznik++;
    };
    //Konstruktor parametryzuj�cy
    Bohater(string pseudonim, string klasa, int sila_ataku){
        this->pseudonim=pseudonim;
        this->klasa=klasa;
        this->sila_ataku=sila_ataku;
        licznik++;
    }
    //Funkcja wy�wietlaj�ca pola ka�dego utworzonego obiektu.
    void wyswietl(){
        cout<<"Bohater:"<<endl;
        cout<<"Pseudonim: "<<pseudonim<<endl;
        cout<<"Klasa: "<<klasa<<endl;
        cout<<"Sila ataku: "<<sila_ataku<<endl;
        }
    //Destrukor, kt�ry przy ka�dym usuni�ciu obiektu obni�a warto�� licznika.
    ~Bohater(){
        licznik--;
    }
    //AKCESORY
    //Akcesory pozwalaj� na dzia�anie na polach klasy, kt�re s� prywatne, poza sam� klas�.
    //Wszystkie funkcje nazwane przeze mnie "Get*()" pozwalaj� w funkcji main() na pobranie warto�ci w dane miejsce poza klas�.
    //Wszystkie funkcje nazwane przeze mnie "Set*()" pozwalaj� w funkcji main() na ustawienie ich warto�ci w danym miejscu poza klas�.
    int GetAtak(){
        return this->sila_ataku;
    }
    void SetAtak(int at){
        this->sila_ataku=at;
    }
    void SetNick(string name){
        this->pseudonim=name;
    }
    string GetKl(){
        return this->klasa;
    }
    void SetKl(string kl){
        this->klasa=kl;
    }
    static int licz(){
        return licznik;
    }
};
//Ustalenie pocz�tkowej warto�ci zmiennej statycznej.
int Bohater::licznik=0;

//Klasa Ekwipunek
class Ekwipunek{
private:
    string rodzaj;
    string material;
    int wartosc;
    Bohater *bohater_wsk;
public:
    Ekwipunek(){
        rodzaj="miecz";
        material="srebro";
        wartosc=1000;
        bohater_wsk=new Bohater;
    }
    Ekwipunek(string rodzaj, string material, int wartosc, Bohater* bohater_wsk){
        this->rodzaj=rodzaj;
        this->material=material;
        this->wartosc=wartosc;
        this->bohater_wsk=bohater_wsk;
    }
    ;
    void wyswietl(){
        cout<<"Rodzaj: "<<rodzaj<<endl;
        cout<<"Material: "<<material<<endl;
        cout<<"Wartosc: "<<wartosc<<endl;
        cout<<"Klasa: "<<this->bohater_wsk->GetKl()<<endl;
    }
    ~Ekwipunek(){
        cout<<"Obiekty zostaly zniszczone"<<endl;
    }
};

int main(){
    //Zainicjowanie i ustalenie warto�ci pocz�tkowej zmiennej suma, potrzebnej do zliczania sumy si�y ataku wszystkich bohater�w.
    int suma=0;

    //Pierwszy obiekt bohater_1 utworzony dynamicznie.
    Bohater* bohater_1=new Bohater("Geralt","wiedzmin",200);
        bohater_1->SetAtak(350);
        bohater_1->wyswietl();
        suma+=bohater_1->GetAtak();

    //Tworzenie tablicy dynamicznej 2D o wymiarach 2x2.
    Bohater** tab=new Bohater* [2];              //tablica na wskazniki
    for(int i=0; i<2; i++){                      //generowanie poszczegolnych wymiar�w
        tab[i]=new Bohater[2];
    }

    //Ustawienie warto�ci p�l poszczeg�lnych bohater�w znajduj�cych si� w tablicy za pomoc� akcesor�w.
    tab[0][0].SetNick("Vesemir");
    tab[0][0].SetKl("medrzec");
    tab[0][0].SetAtak(150);
    tab[0][1].SetNick("Yennefer");
    tab[0][1].SetKl("czarodziej");
    tab[0][1].SetAtak(250);
    tab[1][0].SetNick("Jaskier");
    tab[1][0].SetKl("bard");
    tab[1][0].SetAtak(30);
    tab[1][1].SetNick("Ciri");
    tab[1][1].SetKl("wiedzmin");
    tab[1][1].SetAtak(200);

    //P�tla wy�wietlaj�ca elementy bohater�w w tablicy oraz pozwalaj�ca sumowa� si�� ataku wszystkich bohater�w.
    for (int i=0;i<2;i++){
        for (int j=0;j<2;j++){
            tab[i][j].wyswietl();
            suma+=tab[i][j].GetAtak();
        }
    }

    cout<<"Ilosc obiektow razem z tablica: "<<Bohater::licz()<<endl;
    cout<<"Suma sil ataku bohaterow wynosi "<<suma<<endl;

    //Tworzenie obiekt�w klasy Ekwipunek.
    Ekwipunek obiekt_ekw1;
    obiekt_ekw1.wyswietl();
    Ekwipunek* obiekt_ekw2=new Ekwipunek("Kusza","metal",400,bohater_1);
    obiekt_ekw2->wyswietl();

    //Zwalnianie pamieci poprzez usuwanie element�w tablicy.
    for (int i=0; i<2; i++){
        delete [] tab[i];
    }
    delete [] tab;

    cout<<"Ilosc obiektow po usunieciu tablicy: "<<Bohater::licz()<<endl;

    //Usuwanie obiekt�w.
    delete obiekt_ekw2;
    delete bohater_1;
    system("pause");
    return 0;
}
