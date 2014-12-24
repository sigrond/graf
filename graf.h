/** \file graf.h
 * \author Tomasz Jakubczyk
 * \date 23.12.2014
 * \brief Plik nagłówkowy klasy graf
 */

#include<vector>
#include<utility>
#include<stack>

#ifndef NDEBUG
#define DEBUG if(true)
#endif // NDEBUG
#ifdef NDEBUG
#define DEBUG if(false)
#endif

/** \class graf
 * \brief klasa przechowująca strukturę grafu
 * i wykonująca na nim operacje
 */
class graf
{
private:
    /** \class wierzcholek
     * \brief klasa wewnętrzna reprezentująca wierzchołek grafu
     */
    class wierzcholek
    {
    private:
        double x;/**< współrzędna x */
        double y;/**< współrzędna y */
        //unsigned int numer;
    public:
        /** \brief konstruktor wierzchołka
         * \param X współrzędna x
         * \param Y współrzędna y
         */
        wierzcholek(double X, double Y) : x(X), y(Y) {};
        /** \brief destruktor wierzchołka
         */
        ~wierzcholek() {};
    };
    /** \class krawedz
     * \brief klasa wewnętrzna reprezentująca krawędź grafu
     */
    class krawedz
    {
    private:
        double waga;
        wierzcholek* kierunek;
    public:
        /** \brief konstruktor krawędzi
         * \param Waga waga krawędzi
         * \param Kierunek wierzchołek do którego prowadzi krawędź
         */
        krawedz(double Waga, wierzcholek* Kierunek) : waga(Waga), kierunek(Kierunek) {};
        /** \brief destruktor krawędzi
         */
        ~krawedz() {};
    };
    std::vector<std::pair<wierzcholek*, std::vector<krawedz*>* > > tab;/**< lista sąsiedztwa */
    unsigned int V;/**< wierchołków */
    unsigned int E;/**< krawędzi */
    void DFSscc(unsigned int v);
public:
    graf();
    ~graf();
    void insert_wierzcholek(double X, double Y);
    void insert_krawedz(unsigned int a, unsigned int b, double Waga);
    std::vector<std::vector<int> > znajdz_silnie_spojne_skladowe();
};
