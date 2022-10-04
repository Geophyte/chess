# Chess

## Autorzy
Ignacy Dąbkowski,
Nikita Sushko,

## Podział pracy
Ignacy Dąbkowski: implemetacja szachownicy, wszystkich pionków, wyświetlenia szacownicy oraz gracza komputerowego; napisanie testów jednostkowych i dokumentacji.
Nikita Sushko: implemetcja graczy, klasy Game oraz klasy do zapisywania ruchów do pliku; napisanie testów jednostkowych i dokumetacji.

## Ogólny opis projektu
Celem projektu było zaprojektowanie gry Chess. Nasza wersja gry została napisana w języku C++ zgodnie ze standardami programowania objektowego.
Gra zawiera w sobie oprócz podstawowych elementów gry (takich jak pionki i szachownica), ładny interfejs konsolowy, który umożliwia wizualizację dostępnych ruchów oraz podświetlenie pionków należących do drużyny gracza.
Nasza wersja szachów umożliwia również:
* grę z drugim graczem oraz komputerem (robi losowe ruchy)
* zapis ruchów do pliku zgodnie z przyjętą szachową notacją algebraiczną

## Praca wykonana oraz wnioski
Projekt jest w fazie rozwoju od 4 tygodni. W tym czasie przeprowadzono pracę nad analizą struktury i organizacji projektu. Aby napisać tę grę, pogłębiliśmy swoją wiedzę na temat programowania objektowego (a dokładnie polimorfizmu dynamicznego, inkapsulacji itd).
Oczywiście, że do projetu można by było dodać jeszcze wiele rzeczy, takich jak np:
* odtworzenie gry na planszy na podstawie zapisu rozrywki
* mądrzejszy algorytm dla komputera

Ale ogólnie rzecz biorąc, wszystkie początkowe wymagania projektu zostały spełnione.
Zdobyliśmy doświadczenie w pisaniu projektów oraz polepszyliśmy swoje zdolności pracy w zespole.
Efekt końcowy bardzo nam się spodobał.

## Generowanie plików VS
Do Wygenerowania plików używam CMake. W głównym folderze projektu znajduje się plik generate.bat, który generuje pliki Visual Studio do folderu _build
