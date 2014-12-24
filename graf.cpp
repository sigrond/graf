/** \file graf.cpp
 * \author Tomasz Jakubczyk
 * \date 23.12.2014
 * \brief Plik z implementacjami metod klasy graf
 */
#include "graf.h"

/** \brief konstruktor grafu
 */
graf::graf() : V(0), E(0)
{

}

/** \brief destruktor grafu
 */
graf::~graf()
{

}

/** \brief wstawienie nowego wierzchołka do grafu
 * \param X współrzędna x wierzchołka
 * \param Y współrzędna y wierzchołka
 * \return void
 */
void graf::insert_wierzcholek(double X, double Y)
{
    tab.push_back(std::make_pair(new wierzcholek(X,Y,tab.size()), new std::vector<krawedz*>));
    //tab[tab.size()-1].first->numer=tab.size()-1;
    V++;
}

/** \brief wstawienie krawędzi do grafu
 * \param a krawędź z
 * \param b krawędź do
 * \param Waga waga krawędzi
 * \return void
 * \throw std::out_of_range exception
 */
void graf::insert_krawedz(unsigned int a, unsigned int b, double Waga)
{
    tab.at(a).second->push_back(new krawedz(Waga,tab.at(b).first));
    E++;
}

/** \brief konstruktor inicjalizujący dane dla DFSa
 * \param n ilość wierzchołków
 * \param Tab referencja do listy połączeń w grafie
 */
graf::DFSdata::DFSdata(unsigned int n, std::vector<std::pair<wierzcholek*, std::vector<krawedz*>* > > &Tab)
{
    tab=Tab;
    VN=std::vector<unsigned int> (n, 0); //Utwórz n elementową tablicę VN i wyzeruj ją
    VS=std::vector<bool> (n, false); //Utwórz n elementową tablicę VS i wyzeruj ją
    VLow=std::vector<unsigned int> (n); //Utwórz n elementową tablicę VLow
    cvn=0; //zerujemy numer wierzchołka
}

/** \brief DFS przeszukujący
 * \param v numer wierzchołka początkowego
 */
void graf::DFSdata::DFSscc(unsigned int v)
{
    cvn++; //zwiększamy numer wierzchołka
    VN[v]=cvn; //i zapamiętujemy go w tablicy VN
    VLow[v]=cvn; //oraz wstępnie w tablicy VLow
    S.push(v); //wierzchołek umieszczamy na stosie
    VS[v]=true; //i zapamiętujemy w VS, że jest on na stosie
    unsigned int u;
    std::vector<int> skladowa;
    for(unsigned int i=0;i<tab.at(v).second->size();i++) //przeglądamy kolejnych sąsiadów wierzchołka v
    {
        u=tab.at(v).second->at(i)->kierunek->numer;
        if(VN[u]==0) //sprawdzamy, czy wierzchołek był odwiedzony
        {
            DFSscc(u); //wierzchołek nieodwiedzony: rekurencyjnie wywołujemy dla niego DFSscc()
            VLow[v]=std::min(VLow[v],VLow[u]); //i wyznaczamy najmniejszy numer dostępnego wierzchołka z v
        }
        else if(VS[u]) //sprawdzamy, czy wierzchołek u jest na stosie
        {
            VLow[v]=std::min(VLow[v],VN[u]); //jeśli tak, to wyznaczamy najmniejszy numer dostępnego wierzchołka z v
        }
    }
    if(VLow[v]==VN[v]) //sprawdzamy, czy znaleźliśmy całą silnie spójną składową
    {
        do
        {
            u=S.top(); //pobieramy ze stosu wierzchołek silnie spójnej składowej
            S.pop(); //pobrany wierzchołek usuwamy ze stosu
            VS[u]=false; //zaznaczamy, że wierzchołka już nie ma na stosie
            skladowa.push_back(u);
        }
        while(u!=v);
        wynik.push_back(skladowa);
    }
}

/** \brief znajduje i wpisuje do wektora silnie spójne składowe
 * \return std::vector<std::vector<int>> wektor silnie spójnych składowych,
 * każda to wektor numerów wierzchołków składowych
 */
std::vector<std::vector<int> > graf::znajdz_silnie_spojne_skladowe()
{
    DFSdata dane(V, tab);
    for(unsigned int i=0;i<V;i++) //przeglądamy kolejne wierzchołki grafu
    {
        if(dane.VN[i]==0) //w wierzchołkach nieodwiedzonych uruchamiamy DFS
        {
            dane.DFSscc(i);
        }
    }
    return dane.wynik;
}





























