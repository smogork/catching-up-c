# Struktury
*Zadanie nr 3*

Celem tego zadania jest zaimplementowanie listy jednokierunkowej.
Każdy element listy, zamiast przechowywać jedna wartość, przechowuje on tablicę wartości.
Twoim zadaniem jest przygotować operacje *insert* oraz *remove* z takiej listy.
Dane w liście będą reprezentowane jako liczby całkowite, a operacja *insert* musi zachować porządek niemalejący.

W pliku `list.h` znajdziesz dwie struktury: `unrolled_list_node` oraz `unrolled_ordered_list`.
Pierwsza z nich reprezentuje węzeł w liście skierowanej.
To tutaj przechowywane są dane oraz wskaźnik na kolejny węzeł w liście.
Druga struktura reprezentuje listę jako całość.
Jej głównym celem jest przechowywać wskaźnik na pierwszy element list (tzw. *head*).

Zadania:
1. Zdefiniuj struktury `unrolled_list_node` i `unrolled_ordered_list`.
W węźle powinna znajdować się:
    * tablica liczb całkowity o rozmiarze `NODE_CAPACITY`,
    * liczba zajętych miejsc w tablicy,
    * wskaźnik na kolejny element listy.
Struktura reprezentująca listę powinna składać się tylko ze wskaźnika na pierwszy element list.
2. Zaimplementuj fukncje `ordered_list_create` oraz `ordered_list_destroy`.
Pierwsza funkcja tworzy pustą listę na stercie.
Powinna zwrócić wskaźnik do nowo utworzonej listy.
Druga funkcja powinna być użyta do zwolnienia zasobów zaalokowanych przez pierwszą funkcję.
Jej celem jest nie tylko prawidłowe zwolnienie przekazanego wskaźnika, ale także zwolnienie zasobów zajmowanych przez wszystkie węzły znajdujące się aktualnie w liście.
3. Zaimplementuj funkcje `ordered_list_print` oraz `ordered_list_insert_value`.
Pierwsza z nich powinna przejść po wszystkich węzłach listy oraz wypisać zawartość ich tablic w porządku niemalejącym.
Druga natomiast powinna wstawić liczbę do listy, nadal zachowując niemalejący porządek danych.
Rozważ następujące problemy:
    * Co się stanie, gdy nie istnieje *head* (jest NULL)?
    * Co się stanie, gdy węzeł, gdzie powinniśmy wstawić liczbę, jest już w całości zapełniony? Może trzeba rozważyć podzielenie węzła na dwa?
    * Co się stanie, gdy liczbę należy wstawić na początku w danym węźle? Może dałoby się także wstawić tę liczbę na końcu poprzedniego węzła?
    * Jako powinna wyglądać wstawienie liczby pomiędzy istniejące dane w jednym węźle? Jak możemy zapewnić, że nie zniszczymy zastanych danych?
Po zaimplementowaniu dwóch funkcji usuń z funkcji `main` linijkę `TEST_IGNORE()` dla testu `test_ordered_list_insertion`.
4. Zaimplementuj funkcję `ordered_list_remove_value`.
Funkcja ta powinna usunąć podaną wartość z listy (tylko jedną w przypadku powtórzeń).
Oczywiście, po wykonaniu tej operacji należy zachować porządek niemalejący danych oraz zwolnić wszystkie zasoby przez potencjalnie usunięte węzły.
Rozważ następujące problemy:
    * Co się stanie, jeśli nie znajdziemy podanej wartości w liście?
    * Jak możemy usunąć dane z węzła? Tablice nie posiadają operacji `erase` albo `delete`. Zastanów się, co to znaczy tak naprawdę.
    * Co się stanie, jeśli usuniemy ostatnią wartość w węźle (węzeł stanie się pusty). Czy możemy od razu zwolnić zasoby zajmowane przez dany węzeł?
Po zaimplementowaniu tej funkcji usuń dwa pozostałe `TEST_IGNORE()` w pliku `main.c`.

