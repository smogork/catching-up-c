# Tablice i dynamiczna alokacja pamięci
*Zadanie nr 2*

Twoim zadaniem jest napisać program do zapisu ciągłych funkcji w sposób dyskretny.
Do tego celu wykorzystamy tablice 16 bitowych liczb całkowitych ze znakiem.
Sygnał (funckja ciągła) powinien byc próbkowany 44100 razy na sekundę (standard CD).

Pisząc testy wykorzystaj funkcje `write_wave_file` aby zapisać wygenerowy przebieg do pliku WAV.
Umożliwi on odsłuchanie wyniku twojej pracy.

Zadania:
1. Napisz dwie funkcje generujące falę sinusoidalną oraz ciszę (cisza to same 0).
Zaimplementuj testy generujące przebiegi jednosekundowe tonu A4 (`test_sin_creation`) oraz ciszę (`test_silence_creation`).
2. Zaimplementuj przesunięcie w fazie o zadaną liczbe próbek.
Napisz test generujący przebieg jednosekundowy tonu A4, ale aby był on cosinusem (`test_cos_creation`).
3. Zaimplementuj łączenie fal w jeden przebieg.
Mając wszystkie cztery funkcje zaimplementuj pozostałe dwa testy.
Jeden generuje ciszę skłądając sinus i cosinus ze sobą (`test_phase_shift_silence`),
a drugi powinien stworzyć akord C-dur (`test_c_chord`).