/** \file main.cpp
 * \author Tomasz Jakubczyk
 * \date 23.12.2014
 * \brief Plik wywołujący zadanie
 */
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<algorithm>
#include "graf.h"
#include "main_page_project_documentation.h"

using namespace std;

int main()
{
DEBUG cout << "silnie spojne skladowe testy" << endl;
    graf g;
    double x,y;/**< \var x,y współrzędne wierzchołków */
    unsigned int a,b;/**< \var a,b numery wierchołków krawędzi */
    double w;/**< \var w waga */
    string s;
    int count_space;
    size_t poz;
    while(getline(cin,s))
    {
        count_space=count(s.begin(),s.end(),' ');
DEBUG   cout<<s<<endl;
        if(count_space==1)
        {
            x=stod(s,&poz);
            y=stod(s.substr(poz));
DEBUG       cout<<x<<", "<<y<<endl;
            g.insert_wierzcholek(x,y);
        }
        else if(count_space==2)
        {
            a=stoi(s,&poz);//do pierwszej spacji
            b=stoi(s.substr(poz),&poz);//od pierwszej do drugiej spacji
            w=stod(s.substr(poz));//do końca
DEBUG       cout<<a<<", "<<b<<", "<<w<<endl;
            g.insert_krawedz(a,b,w);
        }
        else
        {
            cout<<"wczytano: "<<count_space<<" spacji w lini, błędne dane!"<<endl;
        }
    }
    vector<vector<int> > wynik=g.znajdz_silnie_spojne_skladowe();
    for(int i=0;i<wynik.size();i++)
    {
DEBUG   cout<<"skladowa: "<<i<<" rozmiar: "<<wynik[i].size()<<endl;
        if((wynik[i].size()+1)%2==0)
        {
            for(int j=0;j<wynik[i].size();j++)
            {
                cout<<wynik[i][j]<<" ";
            }
            cout<<endl;
        }
    }
DEBUG system("pause");
    return 0;
}
