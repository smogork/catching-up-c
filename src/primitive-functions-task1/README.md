# Typy prymitywne oraz wskaźniki
*Zadanie nr 1*

Zadanie składa się z dwóch części: prezentacji typów prymitywnych oraz sposobów przekazywania ich do funkcji.
Do twojej dyspozycji dostępne są testy jednostkowe napisane w pliku `main.c`.

Lista zadań:

1. Zaimplementuj funkcje losujące wartości typów prymitywnych.
W pliku `primitives.h` najdziesz ich deklaracja wraz z opisem.
Przygotuj ich definicje w pliku `primitives.c`.
Testy zawierajace słowo `rand` powinny przechodzić po zakończeniu tego zadania.

2. Zaimplementuj funkcje dodające dwie liczby całkowite.
W pliku `pointers.h` najdziesz ich deklaracja wraz z opisem.
Przeczytaj dokładnie opis nagłowka funkcji i zaimplementuj ich definicje w pliku `pointers.c`.

3. Napisz testy do twoich funkcji wykonujących dodawanie w pliku `main.c`.
Szukaj komentarzy z `TODO` aby znaleźc odpowiednie funkcje.


Podpowiedzi:
1. Do losowania najlepiej użyć funkcji `rand()`, która zwraca 32 bitowa liczbe całkowitą ze znakiem.
2. Do generowania liczb zmienno przecinkowych może być uzyteczna definicja `RAND_MAX`. W taki sposób można wygenerować liczbę z zakresu [0,1);
3. Znaki ASCII czytelne dla człowieka można znaleźć tutaj https://en.wikipedia.org/wiki/ASCII#Printable_character_table
