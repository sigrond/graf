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
}































