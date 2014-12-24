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
 \section Wejście Obsługa wejścia
Ze standardowego strumienia wczytuję po lini, aż do EOF lub innego znaku końca strumienia.
while(getline(cin,s))
Żeby odróżnić wierzchołki od krawędzi zliczam spacje, 1 -> wierzchołek, 2 -> krawędź.
Liczby uzyskuję funkcjami z c++11 stod i stoi, a do wyboru fragmentu stringa substr.
 */
