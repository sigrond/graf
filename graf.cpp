/** \file graf.cpp
 * \author Tomasz Jakubczyk
 * \date 23.12.2014
 * \brief Plik z implementacjami metod klasy graf
 */
#include "graf.h"

/** \brief konstruktor grafu
 */
graf::graf()
{
    V=0;
    E=0;
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
    tab.push_back(std::make_pair(new wierzcholek(X,Y), new std::vector<krawedz*>));
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

/** \brief znajduje i wpisuje do wektora silnie spójne składowe
 * \return std::vector<std::vector<int>> wektor silnie spójnych składowych,
 * każda to wektor numerów wierzchołków składowych
 */
std::vector<std::vector<int> > graf::znajdz_silnie_spojne_skladowe()
{
    std::vector<std::vector<int> > wynik;
    std::vector<int> skladowa;
    int cvn,*VN,*VLow;
    stack<int> S;
}





























