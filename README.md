# covering-the-board

Program szukający możliwego pokrycia prostokątnej planszy o wymiarach n na m zadaną liczbą domin,tromin i tetramin.

Budowa pliku zawierającego rozmiar planszy i liczby figur:
n m
2 <liczba_domin>
3 <liczba_tromin>
4 <liczba_tetramin>

Program losuje konkretne typy figur, które zostaną wykorystane do rozwiązania. Np dla pliku polecającego użycie 2 tromin, losowo zostanie podjęta decyzja czy będą to 2 tromina o kształcie I, czy może 1 o kształcie L, a drugie I.

Do znalezienia rozwiązania wykorzystywany jest algoryt rekurencyjny z nawrotami.

Niestety dla niektórych rozmiarów planszy i liczb figur nadal występuje Segmentation fault.


English description:

Program which can be used to find possible covering of rectangle board (n x m) by set number of dominos, trominos and tetraminos.

Form of file containing size of the board and numbers of figures:
n m
2 <number_of_dominos>
3 <number_of_trominos>
4 <number_of_tetraminos>

The backtracing algorithm is used to find a solution.

Unfortunately the segmentation fault still occures sometimes for some combination of board size and amount of figures.
