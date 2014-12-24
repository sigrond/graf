/** \file main_page_project_documentation.h
 * \author Tomasz Jakubczyk
 * \date 23.12.2014
 * \brief Plik z dokumentacją
 * \mainpage Zadanie grafowe na AISDI
 * \section AISDI 2014Z zadanie GRAF
Proszę napisać program, który:
1. wczyta ze standardowego wejścia graf skierowany
2. wyszuka w zadanym grafie wszystkie silnie spójne składowe
3. wypisze na standardowe wyjście numery wierzchołków należących do
kolejnych silnie spójnych składowych, ale tylko takich co zawierają
nieparzystą liczbę wierzchołków
 \subsection Dodatkowe Dodatkowe założenia:
1. Krawędzie mogą być tylko jednokrotne – nie rozważamy przypadku
multigrafu. Próba dodania kolejny raz wagi dla istniejącej już krawędzi
powinna nadpisać dotychczasową wartość.
2. Dla wszystkich danych ułamkowych separatorem dziesiętnym jest '.'
(kropka).
Silnie spójna składowa grafu skierowanego jest to taki maksymalny podgraf, w
którym istnieje w obie strony ścieżka skierowana pomiędzy każdymi dwoma
wierzchołkami tego podgrafu. Należy zwrócić uwagę, że szczególnym przypadkiem
silnie spójnej składowej może być też pojedynczy punkt.
 \subsection Wejście Wejście
W pierwszej sekcji znajduje się v linii z dwoma liczbami rzeczywistymi oznaczającymi
współrzędne x oraz y kolejnych wierzchołków.
Po pierwszej sekcji następuje druga sekcja, w której znajduje się e linii z dwoma
całkowitymi liczbami nieujemnymi oraz jedna nieujemną liczbą rzeczywistą
oznaczającymi: nr wierzchołka początkowego, końcowego oraz wagę krawędzi.
Liczby v, e należą do zbioru liczb naturalnych.
 \subsection Wyjście Wyjście standardowe
Wyjście ma zawierać n linii (dla każdego silnie spójnej składowej jedna linia).
Każda linia składa się z liczb całkowitych - numery kolejnych wierzchołków
należących do danej silnie spójnej składowej. Wszystkie wartości oddzielone są
pojedynczym znakiem spacji.
UWAGA!
Proszę nie robić żadnych interfejsów tekstowych np. pytających się o kolejne
wierzchołki, po prostu czytamy ze strumienia dane i do strumienia piszemy.
 \subsection Przykład Przykład działania:
Dane wejściowe (cin):
0.2 0.1
1.2 0.2
1.2 1.1
0.2 1.1
0.3 1.2
0.4 2.1
0 1 12.3
1 2 10
2 3 2.4
3 1 1.1
3 4 5.0
5 4 5.0
4 5 5.4
Dane wyjściowe (cout):
0
1 2 3
 \page Realizacja Realizacja zadania
 \section Algorytm Algorytm
Do znalezienia silnie spójnych składowych używam algorytmu Roberta Tarjana.
 \subsection Kod Kod
 \code {.unparsed}
 Algorytm Tarjana wyszukiwania silnie spójnych składowych w grafie skierowanym

Algorytm przejścia DFSscc(v,cvn,VN,VLow,VS,S,Lscc,graf)

Wszystkie parametry za wyjątkiem v mogą być zrealizowane jako globalne, co zmniejszy zapotrzebowanie na pamięć przy wywoływaniach rekurencyjnych.
Wejście

v	 – 	wierzchołek startowy, v  C
cvn	 – 	numer bieżącego wierzchołka, cvn  C
VN	 – 	tablica numerów wierzchołków, które ustala DFSscc()
VLow	 – 	tablica parametrów Low
VS	 – 	tablica logiczna, która informuje, czy dany wierzchołek jest na stosie S
S	 – 	stos wierzchołków
Lscc	 – 	jednokierunkowa lista silnie spójnych składowych. Każda silnie spójna składowa jest jednokierunkową listą wierzchołków, które do niej należą.
graf	 – 	graf zadany w dowolny sposób, algorytm tego nie precyzuje
Wyjście:

Lista silnie spójnych składowych Lscc.
Elementy pomocnicze:

u	 – 	wierzchołek, u  C
sccp,p	 – 	wskaźniki do elementu listy wierzchołków
listp	 – 	wskaźnik do elementu listy list
Lista kroków:

K01:	cvn ← cvn + 1	; zwiększamy numer wierzchołka
K02:	VN[v] ← cvn	; i zapamiętujemy go w tablicy VN
K03:	VLow[v] ← cvn	; oraz wstępnie w tablicy VLow
K04:	S.push(v)	; wierzchołek umieszczamy na stosie
K05:	VS[v] ← true	; i zapamiętujemy w VS, że jest on na stosie
K06:	Dla każdego sąsiada u wierzchołka v wykonuj K07...K12	; przeglądamy kolejnych sąsiadów wierzchołka v
K07:	    Jeśli VN[u] = 0, to idź do K11	; sprawdzamy, czy wierzchołek był odwiedzony
K08:	    Jeśli VS[u] = false, to następny obieg pętli K06	; sprawdzamy, czy wierzchołek u jest na stosie
K09:	    VLow[v] ← min(VLow[v], VN[u])	; jeśli tak, to wyznaczamy najmniejszy numer dostępnego wierzchołka z v
K10:	    Następny obieg pętli K06	; i kontynuujemy pętlę
K11:	    DFSscc(u,cvn,VN,VLow,VS,S,Lscc,graf)	; wierzchołek nieodwiedzony: rekurencyjnie wywołujemy dla niego DFSscc()
K12:	    VLow[v] ← min(VLow[v], VLow[u])	; i wyznaczamy najmniejszy numer dostępnego wierzchołka z v
K13:	Jeśli VLow[v] ≠ VN[v], to zakończ	; sprawdzamy, czy znaleźliśmy całą silnie spójną składową
K14:	sccp ← nil	; tworzymy pustą listę wierzchołków
K15:	    u ← S.top()	; pobieramy ze stosu wierzchołek silnie spójnej składowej
K16:	    S,pop()	; pobrany wierzchołek usuwamy ze stosu
K17:	    VS[u] ← false	; zaznaczamy, że wierzchołka już nie ma na stosie
K18:	    Utwórz nowy element listy wierzchołków	; wierzchołek dodajemy do listy silnie spójnej składowej
K19	    p ← adres nowego elementu listy wierzchołków
K20:	    (p→v) ← u
K21:	    (p→next) ← sccp
K22:	    sccp ← p
K23:	Jeśli u ≠ v, to idź do K15	; pętlę kontynuujemy, aż do dotarcia do korzenia składowej
K24:	Utwórz nowy element listy list	; listę wierzchołków sccp dodajemy do listy Lscc
K25:	listp ← adres nowego elementu listy list
K26:	(listp→v) ← sccp
K27	(listp→next) ← Lscc
K28:	Lscc ← listp
K29:	Zakończ

Algorytm główny

Wejście

n	 – 	liczba wierzchołków w grafie, n  C
graf	 – 	graf zadany w dowolny sposób, algorytm tego nie precyzuje
Wyjście:

Wypisuje na wyjście wierzchołki należące do silnie spójnych składowych.
Elementy pomocnicze:

v	 – 	numer wierzchołka, v  C
cvn	 – 	numer bieżącego wierzchołka, cvn  C
VN	 – 	tablica numerów wierzchołków, które ustala DFSscc()
VLow	 – 	tablica parametrów Low
VS	 – 	tablica logiczna, która informuje, czy dany wierzchołek jest na stosie S
S	 – 	stos wierzchołków
Lscc	 – 	jednokierunkowa lista silnie spójnych składowych. Każda silnie spójna składowa jest jednokierunkową listą wierzchołków, które do niej należą.
listp	 – 	wskaźnik elementu listy składowych
p	 – 	wskaźnik listy wierzchołków
Lista kroków:

K01:	Utwórz pusty stos S
K02:	Utwórz n elementową tablicę VN i wyzeruj ją
K03:	Utwórz n elementową tablicę VS i wyzeruj ją
K04:	Utwórz n elementową tablicę VLow
K05:	cvn ← 0	; zerujemy numer wierzchołka
K06:	Lscc ← nil	; tworzymy pustą listę silnie spójnych składowych
K07:	Dla v = 0,1,...,n - 1 wykonuj K08	; przeglądamy kolejne wierzchołki grafu
K08:	    Jeśli VN[v] = 0, to DFSscc(v,cvn,VN,VLow,VS,S,Lscc,graf)	; w wierzchołkach nieodwiedzonych uruchamiamy DFS
K09:	listp ← Lscc	; przeglądamy listę silnie spójnych składowych
K10:	Dopóki listp ≠ nil, wykonuj K11...K16
K11:	    p ← (listp→v)	; przeglądamy listę wierzchołków
K12:	    Dopóki p ≠ nil, wykonuj K13...K14
K13:	        Pisz (p→v)	; wypisujemy wierzchołki silnie spójnej składowej
K14:	        p ← (p→next)	; następny wierzchołek
K15:	    Przejdź do następnego wiersza wydruku
K16:	    listp ← (listp→next)	; następna lista
K17:	Zakończ
 \endcode
 \section Wejście Obsługa wejścia
Ze standardowego strumienia wczytuję po lini, aż do EOF lub innego znaku końca strumienia.
while(getline(cin,s))
Żeby odróżnić wierzchołki od krawędzi zliczam spacje, 1 -> wierzchołek, 2 -> krawędź.
Liczby uzyskuję funkcjami z c++11 stod i stoi, a do wyboru fragmentu stringa substr.
 */
