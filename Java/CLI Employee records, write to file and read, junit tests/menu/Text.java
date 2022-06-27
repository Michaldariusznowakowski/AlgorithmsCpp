package menu;

public class Text {
    private Text(){}
    protected static  String[] menu={
        "Lista pracownikow",//0
        "Dodaj pracownika",//1
        "Usuń pracownika",//2
        "Kopia zapasowa",//3
        "MENU",//4
        "Wyjście"//5
    };
    protected static String[] list={
        "Idenfikator PESEL",//0
        "Imię",//1
        "Nazwisko",//2
        "Stanowisko",//3
        "Wynagrodzenie (zł)",//4
        "Telefon służbowy numer",//5
        "Dodatek słuzbowy (zł)",//6-D
        "Karta służbowa numer",//7-D
        "Limit kosztów/miesiąc (zł)",//8-D
        "Prowizja %",//9-H
        "Limit prowizji/miesiąc (zł)"//11-H
    };
    protected static String[] choice={
        "[P]racownik/[D]yrektor/[H]andlowiec:",//0
        "[Z]achowaj/[O]dtwórz",//1
        "Kompresja [G]zip/[Z]ip"//2
    };
    protected static String[] format={
        "\t%-25s\t%s \t%-10s\n",//0
        "%50s %s/%s%s\n",//1
        "\t%-25s\t%s \t",//2
        "\n\t%-25s\t%s \t",//3
        "\t%25s\t%s \t%-10s\n"//4bck
    };
    protected static String[] other={
        "------------------------------------------------------------------",//0
        "Pracownik",//1
        "Dyrektor",//2
        "Handlowiec",//3
        "- brak -",//4
        "[Enter] > ",//5
        "[Q] > ",//6
        ":",//7
        "następny",//8
        "zapisz",//9
        "potwierdź",//10
        "Wybór>",//11
        "powrót",//12
        "porzuć",//13
        "[Pozycja:",//14
        "]",//15
        "usuń",//16
        "Pomyślnie usunięto!",//17
        "Operacja pomyślnie zakończona!"
    };
    protected static String[] err={
        "Błąd! Proszę podać liczbę!",//0
        "Błąd! Proszę podać liczbę od 1 do 5!",//1
        "Błąd! Proszę podać poprawną opcje!",//2
        "Błąd! Proszę zastosować odpowiedni format!",//3
        "Błąd! Pracownik z takim peselem widnieje już na liście pracowników!",//4
        "Błąd! Proszę podać liczbę większą od 0",//5
        "Błąd! Brak pracownika z takim peselem!",//6
        "Błąd! Brak miejsca na dysku lub brak uprawnień do zapisu pliku!",//7
        "Błąd! Brak kopii zapasowej!",//8
        "Błąd! Nie można odczytać kopii zapasowej!",//9
        "Błąd! Brak danych o pracownikach!"//10
    };
}
