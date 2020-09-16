#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/** \brief Bazowa struktura, ktorej uzywamy do tworzenia bazy kontaktow.
 *
 * Struktura sklada sie ze wskaznika na nastepny element oraz na dwie
 * oddzielne struktury przechowujace numery telefonow oraz adresy email.
 * Posiada takze pole typu int, w ktorym znajduje sie numer ID oraz tablice znakow,
 * w ktorych przechowywane sa dane.
 *
 *
 */
struct dane{
    int id;
    char nazwisko[15];
    char imie[15];
    char miasto[15];
    char ulica[20];
    char numer[6];
    char kod_pocztowy[7];
    char poczta[15];
    struct adresy *pierwszyadres;
    struct numery *pierwszynumer;
    struct dane *nastepna;
};
/** \brief Podrzedna struktura, ktorej uzywamy do przechowywania adresow email.
 *
 * Struktura sklada sie ze wskaznika na nastepny element
 * oraz tablicy znakow,w ktorej przechowywany jest adres email.
 *
 */
struct adresy{
    char mail[20];
    struct adresy *nastepny;
};
/** \brief Podrzedna struktura, ktorej uzywamy do przechowywania numerow telefonow.
 *
 * Struktura sklada sie ze wskaznika na nastepny element
 * oraz tablicy znakow,w ktorej przechowywany jest numer telefonu.
 *
 */
struct numery{
    char telefon[10];
    struct numery *nastepny;
};
/** \brief Funkcja zabezpieczajaca wprowadzane dane.
 *  Sprawdza czy wszystkie elementy tablicy sa literami.
 *
 * \param *slowo - tablica znakow z wprowadzonym slowem, ktorego znaki chcemy sprawdzic.
 * \return wartosc typu int
 */
int walidacja(char *slowo);
/** \brief Funkcja zabezpieczajaca wprowadzany numer budynku.
 *  Dopuszcza cyfry, litery i znak '/'.
 *
 * \param *slowo - tablica znakow z wprowadzonym slowem, ktorego znaki chcemy sprawdzic.
 * \return wartosc typu int
 */
int walidacjanrb(char *slowo);
/** \brief Funkcja zabezpieczajaca wprowadzany kod pocztowy.
 * Dopuszcza wprowadzenie 6 znakow: 5 cyfr oraz znak '-' na 3 miejscu.
 *
 * \param *slowo - tablica znakow z wprowadzonym slowem, ktorego znaki chcemy sprawdzic.
 * \return zwraca wartosc typu int
 */
int walidacjakod(char *slowo);
/** \brief Funkcja zabezpieczajaca wprowadzany numer telefonu.
 * Dopuszcza wprowadzenie 9 cyfr.
 *
 * \param *slowo - tablica znakow z wprowadzonym slowem, ktorego znaki chcemy sprawdzic.
 * \return zwraca wartosc typu int
 */
int walidacjanumer(char *slowo);
/** \brief Funkcja zabezpieczajaca wprowadzany adres email.
 * Dopuszcza wprowadzenie cyfr, liter oraz znakow '@' i '.'.
 * Przy tym '@' musi znajdowac sie w odstepie minimum 5 znakow od konca oraz minimum 1 znaku od '.',
 *  a '.' minimum 2 znaki od konca.
 *
 * \param *slowo - tablica znakow z wprowadzonym slowem, ktorego znaki chcemy sprawdzic.
 * \return zwraca wartosc typu int
 */
int walidacjamail(char *slowo);
/** \brief Funkcja sluzaca do wprowadzania adresu email.
 * Jezeli lista jest pusta dodaje adres na poczatek, w innym wypadku na koniec listy adresow.
 *
 * \param *pierwszy - wskaznik na poczatek listy adresy.
 * \return zwraca wskaznik na pierwszy element listy.
 */
struct adresy *dodawanieadresu(struct adresy *pierwszy);
/** \brief Funkcja sluzaca do wprowadzania numeru telefonu.
 * Jezeli lista jest pusta dodaje adres na poczatek, w innym wypadku na koniec listy numerow.
 *
 * \param *pierwszy - wskaznik na poczatek listy numery.
 * \return  zwraca wskaznik na pierwszy element listy.
 */
struct numery *dodawanienumeru(struct numery *pierwszy);
/** \brief Funkcja sluzaca do wprowadzania danych.
 *
 *  Wprowadzamy dane kontaktu: imie, nazwisko, miasto, ulica, nr domu/mieszkania, kod pocztowy, poczta,
 *  telefon, email. W przypadku dwoch ostatnich mozna dodac ich wiele, poniewaz sa przechowywane w osobnych
 *  zagniezdzonych strukturach. Numer ID jest przydzielany automatycznie.
 *  Korzysta z funkcji dodawanienumeru oraz dodawanieadresu.
 * \param *pierwsza - wskaznik na poczatek listy dane.
 * \return zwraca wskaznik na pierwszy element listy.
 */
struct dane *wypelnianie(struct dane *pierwsza);
/** \brief Funkcja sluzaca do wyswietlenia danych osoby.
 *
 * \param *pierwsza - wskaznik na element ktory ma byc wyswietlony.
 * \return zwraca wartosc typu VOID.
 */
void wyswietl_kontakt(struct dane *pierwsza);
/** \brief Funkcja sluzaca do wyswietlenia danych listy osob.
 *  Korzysta z funkcji wyswietl_kontakt().
 * \param *pierwsza - wskaznik na poczatek listy dane.
 * \return zwraca wartosc typu VOID.
 */
void wyswietl_liste(struct dane *pierwsza);
/** \brief Funkcja sluzaca do edytowania danych.
 *  Korzysta z funkcji wyswiet_kontakt.
 *  Znajduje kontakt po numerze ID.
 *  Zawiera menu, z ktorego mozna wybrac pole do edycji.
 * \param *pierwsza - wskaznik na poczatek listy dane.
 * \return zwraca wartosc typu VOID.
 */
void edycja(struct dane *pierwsza);
/** \brief Funkcja sluzaca do usuniecia pierwszego elementu.
 *
 * Element nastepny po pierwszym staje sie poczatkiem listy.
 * Wskaznik na pierwszy element listy adresow i pierwszy element listy numerow
 * wskazuja takze na ich nastepne elementy.
 * \param *pierwsza - wskaznik na poczatek listy dane.
 * \return zwraca wskaznik na nastepny element.
 */
struct dane *usunpocz(struct dane *pierwsza);
/** \brief Funkcja sluzaca do znalezienia elementu poprzedzajacego szukany element.
 *
 * \param *pierwsza - wskaznik na poczatek listy dane.
 * \param data - numer ID
 * \return zwraca wskaznik na element poprzedzajacy szukany element.
 */
struct dane *znajdz_poprzedni(struct dane *pierwsza, int data);
/** \brief Funkcja sluzaca do usuniecia ostatniego elementu lub elementu wewnatrz listy.
 *
 * \param *poprzedni - wskaznik na element poprzedzajacy element do usuniecia.
 * \return zwraca wartosc typu VOID.
 */
void usunkoniec(struct dane *poprzedni);
/** \brief Funkcja glowna usuwania sluzaca do usuniecia elementu z listy.
 *
 * Jezeli pobrany numer ID jest pierwszym elementem listy wywoluje sie funkcja usun_poczatek(),
 * w innym wypadku znajdowany jest poprzez funkcje znajdz_poprzedni() element poprzedzajacy element
 * do usuniecia i wywolywana jest funkcja usun_koniec().
 * \param *pierwsza - wskaznik na poczatek listy dane.
 * \return zwraca wskaznik na poczatek listy.
 */
struct dane *usuwanie(struct dane *pierwsza);
/** \brief Funkcja sluzaca do znalezienia kontaktu.
 *
 *
 *  Funkcja zawiera menu, w ktorym mozemy wybrac pole po jakim chcemy szukac osoby.
 *  Po znalezieniu funkcja wypisuje dane.
 * \param *pierwsza - wskaznik na poczatek listy dane.
 * \return zwraca wartosc typu VOID.
 */
void znajdz_kontakt(struct dane *pierwsza);
/** \brief Funkcja sluzaca do zapisu wszystkich wprowadzonych kontaktow do pliku.
 *
 *  Funkcja tworzy plik tekstowy, do ktorego zapisuje kontakty. Liste mozna aktualizowac.
 *  Aby podczas wczytywania kontaktow wiadoma byla liczba telefonow i email po ich zapisaniu
 *  wczytuje slowo "koniec" oraz "koniec2".
 * \param *pierwsza - wskaznik na poczatek listy dane.
 * \return zwraca wartosc typu VOID.
 */
void zapis_do_pliku(struct dane *pierwsza);
/** \brief Funkcja sluzaca do wczytania wszystkich kontaktow z pliku.
 *
 *  Funkcja sczytuje z pliku slowo po slowie i dodaje je do poszczegolnych pol struktury.
 *  Wczytuje numery telefonow do napotkania slowa "koniec" oraz mail do napotkania slowa "koniec2".
 *  Nastepnie tworzy nowy kontakt. Do napotkania znaku konca pliku EOF.
 * \param *pierwsza - wskaznik na poczatek listy dane.
 * \return zwraca wartosc typu VOID.
 */
struct dane *wczytaj_z_pliku(struct dane *pierwsza);
/** \brief Funkcja sluzaca do porownania dwoch liczb typu int.
 *
 *  Sprawdza czy pierwsza liczba jest mniejsza badz rowna od drugiej.
 *
 * \param pierwsza - wartosc typu int.
 * \param druga - wartosc typu int.
 * \return zwraca wartosc typu  int.
 */
inline int porownajint(int pierwsza,int druga);
/** \brief Funkcja sluzaca do porownania dwoch liczb typu int.
 *
 *  Sprawdza czy pierwsza liczba jest wieksza badz rowna od drugiej.
 *
 * \param pierwsza - wartosc typu int.
 * \param druga - wartosc typu int.
 * \return zwraca wartosc typu  int.
 */
inline int porownajint2(int pierwsza,int druga);
/** \brief Funkcja sluzaca do porownania dwoch ciagow znakow.
 *
 *  Sprawdza czy pierwsze slowo jest wieksze od drugiego.
 *
 * \param *pierwsza - ciag znakow.
 * \param *druga - ciag znakow.
 * \return zwraca wartosc typu  int.
 */
inline int porownajchar(char *pierwsza,char *druga);
/** \brief Funkcja sluzaca do porownania dwoch ciagow znakow.
 *
 *  Sprawdza czy pierwsze slowo jest mniejsze od drugiego.
 *
 * \param *pierwsza - ciag znakow.
 * \param *druga - ciag znakow.
 * \return zwraca wartosc typu  int.
 */
 inline int porownajchar2(char *pierwsza,char *druga);
 /** \brief Funkcja sluzaca do sortowania numerow telefonow.
 *
 *  Funkcja znajduje najmniejszy lub najwiekszy element listy, i odklada go na nowa
 *  liste jednoczesnie wylaczajac go z poprzedniej.Funkcja dziala dopoki nie sprawdzi
 *  wszystkich elementow listy ktora zostala przekazana przez podwojny wskaznik,
 *  po zakonczeniu sprawdzania wszystkich elementow listy, zamienia wskaznik listy
 *  na wskaznik nowo powstalej listy. Elementy nie sa kopiowane, zmieniane sa adresy
 *  znajdujace sie w polach nastepny.
 *
 * \param **pierwsza - wskaznik na pocztek listy dane.
 * \param test2 - wartosc typu int, decyduje o kolejnosci sortowania rosnacej lub malejacej.
 * \return zwraca wartosc typu VOID.
 */
 void sortujnumery(struct numery **pierwsza,int test2);
  /** \brief Funkcja sluzaca do sortowania adresow email.
 *
 *  Funkcja dziala analogicznie do funkcji sortujnumery(), jednak ze wzgledu na
 *  inny typ przekazywanej struktury jest to osobna funkcja.
 *
 * \param **pierwsza - wskaznik na pocztek listy dane.
 * \param test2 - wartosc typu int, decyduje o kolejnosci sortowania rosnacej lub malejacej.
 * \return zwraca wartosc typu VOID.
 */
 void sortujadresy(struct adresy **pierwsza,int test2);
 /** \brief Funkcja sluzaca do sortowania.
 *
 *  Funkcja ktora jest rozszerzona wersja funkcji sortujnumery() i sortujadresy();
 *  Ze wzgledu na inny typ przekazywanej struktuy jest osobna funkcja.
 *  Do funkcji tej przekazujemy jeden parametr wiecej. Odpowiada on za wybor pola
 *  po ktorym nastapi sortowanie. Dla sortowania po adresach email, oraz numerze telefonu
 *  niezbedne jest uzycie funkcji sortujadresy() i sortujnumery() dla kazdego elementu
 *  listy dane ze wzgledu na to ze sa to listy zagniezdzone w liscie bazowej.
 *
 * \param **pierwsza - wskaznik na pocztek listy dane.
 * \param test1 - wartosc typu int, decyduje o polu, po ktorym bedzie sortowac.
 * \param test2 - wartosc typu int, decyduje o kolejnosci sortowania rosnacej lub malejacej.
 * \return zwraca wartosc typu VOID.
 */
 void sortuj(struct dane **pierwsza,int test1,int test2);
 /** \brief Funkcja sluzaca do decydowania o sposobie sortowania.
 *
 *  Wybieramy pole, po ktorym chcemy sortowac baze kontaktow oraz sposob sortownia
 *  majelacy lub rosnacy. Wywoluje funkcje sortuj().
 *
 * \param *pierwsza - wskaznik na pocztek listy dane.
 * \return zwraca wartosc typu VOID.
 */
 struct dane *sortowanie(struct dane *pierwsza);
   /** \brief Funkcja glowna zarzadzajaca programem.
 *
 *  Zawiera glowne menu.
 *
 * Wywoluje glowne menu. Do wyboru mamy opcje: dodawanie,
 * wyswietlanie, usuwanie, edycja, wyszukiwanie, zapis do pliku,
 * wczytywanie z pliku, sortowanie oraz wyjscie.
 * \param *pierwsza - wskaznik na pocztek listy dane.
 * \return zwraca wskaznik na pocztek listy dane.
 */
 struct dane *menu(struct dane *pierwsza);

 /** \brief Funkcja main()
 * Wywoluje funkcje menu().
 *
 *\return zwraca wartosc typu INT.
 */
int main()
{
    struct dane *pierwsza=NULL;
    pierwsza=menu(pierwsza);
    return 0;
}




int walidacja(char *slowo){
    int i;
    if(strlen(slowo)<3)
        return 0;
    for(i=0;i<strlen(slowo);i++){
        if(!isalpha(slowo[i]))
            return 0;
    }
    return 1;
}
int walidacjanrb(char *slowo){
    int i;
    for(i=0;i<strlen(slowo);i++){
        if(!isalnum(slowo[i])&&slowo[i]!='/')
            return 0;
    }
    return 1;
}
int walidacjakod(char *slowo){
    int i;
    if(strlen(slowo)<6)
        return 0;
    if(slowo[2]!='-')
        return 0;
    for(i=0;i<strlen(slowo);i++){
        if(!isdigit(slowo[i])&&i!=2)
            return 0;
    }
    return 1;
}
int walidacjanumer(char *slowo){
    int i;
    if(strlen(slowo)!=9){
        return 0;
    }
    for(i=0;i<strlen(slowo);i++){
        if(!isdigit(slowo[i]))
            return 0;
    }
    return 1;
}
int walidacjamail(char *slowo){
int i;
if(strlen(slowo)<9)
    return 0;
int malpa_miejsce;
int malpa_ile=0;
int kropka;
int kropka_ile=0;
    for(i=0;i<strlen(slowo);i++){
            if(slowo[i]=='@'){
                malpa_miejsce=i;
                malpa_ile+=1;
            }
            if(slowo[i]=='.'){
                kropka=i;
                kropka_ile+=1;
            }
            if((!isalnum(slowo[i]))&&slowo[i]!='@'&&slowo[i]!='.'){
                return 0;
            }
    }
    if(malpa_ile>1||kropka_ile>1){
        return 0;
    }
    if(malpa_miejsce>kropka||malpa_miejsce<3||malpa_miejsce>strlen(slowo)-5){
        return 0;
    }
    if(slowo[malpa_miejsce+1]=='.'||kropka>(strlen(slowo)-2)){
        return 0;
    }
        return 1;
}
struct adresy *dodawanieadresu(struct adresy *pierwszy){

    struct adresy *adres = (struct adresy *)malloc(sizeof(struct adresy));
    struct adresy *tmp;
    scanf(" %s",adres->mail);
    while(!walidacjamail(adres->mail)){
    printf("Mail niepoprawny, podaj nowy:\n");
    scanf(" %s",adres->mail);
    }
    adres->nastepny=NULL;
    if(pierwszy==NULL)
    pierwszy=adres;
    else{
        tmp=pierwszy;
        while(tmp->nastepny!=NULL){
            tmp=tmp->nastepny;
        }
        tmp->nastepny=adres;
    }
    return pierwszy;
}
struct numery *dodawanienumeru(struct numery *pierwszy){

    struct numery *numer = (struct numery *)malloc(sizeof(struct numery));
    struct numery *tmp;
    scanf(" %s",numer->telefon);
    while(!walidacjanumer(numer->telefon)){
    printf("Telefon niepoprawny, podaj 9 cyfrowy numer: \n");
    scanf(" %s",numer->telefon);
    }

    numer->nastepny=NULL;
    if(pierwszy==NULL){
        pierwszy=numer;
        }
    else {
        tmp=pierwszy;
        while(tmp->nastepny!=NULL){
            tmp=tmp->nastepny;
        }
        tmp->nastepny=numer;
    }
    return pierwszy;
}

struct dane *wypelnianie(struct dane *pierwsza){

    char i;
    system("cls");
    struct dane *osoba = (struct dane *)malloc(sizeof(struct dane));
    if(pierwsza==0){
    osoba->id=1;
    }
    else{
    osoba->id=(pierwsza->id+1);
    }
    printf("Nazwisko: \n");
    scanf(" %s",osoba->nazwisko);
    while(!walidacja(osoba->nazwisko)){
    printf("Nazwisko niepoprawne, podaj nowe: \n");
    scanf(" %s",osoba->nazwisko);
    }
    printf("Imie: \n");
    scanf(" %s",osoba->imie);
    while(!walidacja(osoba->imie)){
    printf("Imie niepoprawne, podaj nowe: \n");
    scanf(" %s",osoba->imie);
    }
    printf("Miasto: \n");
    scanf(" %s",osoba->miasto);
    while(!walidacja(osoba->miasto)){
    printf("Miasto niepoprawne, podaj nowe: \n");
    scanf(" %s",osoba->miasto);
    }
    printf("Ulica: \n");
    scanf(" %s",osoba->ulica);
    while(!walidacja(osoba->ulica)){
    printf("Ulica niepoprawna,podaj nowa: \n");
    scanf(" %s",osoba->ulica);
    }
    printf("Numer budynku/mieszkania: \n");
    scanf(" %s",osoba->numer);
    while(!walidacjanrb(osoba->numer)){
    printf("Numer budynku/mieszkania niepoprawny,podaj nowy: \n");
    scanf(" %s",osoba->numer);
    }
    printf("Kod pocztowy: \n");
    scanf(" %s",osoba->kod_pocztowy);
    while(!walidacjakod(osoba->kod_pocztowy)){
    printf("Kod pocztowy niepoprawny,podaj nowy: \n");
    scanf(" %s",osoba->kod_pocztowy);
    }
    printf("Poczta: \n");
    scanf(" %s",osoba->poczta);
    while(!walidacja(osoba->poczta)){
    printf("Poczta niepoprawna, podaj nowa: \n");
    scanf(" %s",osoba->poczta);
    }
    osoba->pierwszynumer=NULL;
    osoba->pierwszyadres=NULL;
    do {
    printf("Telefon: \n");
    osoba->pierwszynumer=dodawanienumeru(osoba->pierwszynumer);
    puts("czy chcesz podac wiecej numerow T/N");
    scanf(" %c",&i);
    } while(i!='N'&&i!='n');
    do {
    printf("Mail: \n");
    osoba->pierwszyadres=dodawanieadresu(osoba->pierwszyadres);
    puts("czy chcesz podac wiecej emaili T/N");
    scanf(" %c",&i);
    } while(i!='N'&&i!='n');
    osoba->nastepna=pierwsza;
    pierwsza=osoba;
return pierwsza;
}
void wyswietl_kontakt(struct dane *pierwsza){
    if(pierwsza==NULL){
    return;
    }
    printf("ID: %d \n", pierwsza->id);
    printf("Nazwisko i imie: \n%s ", pierwsza->nazwisko);
    printf("%s \n", pierwsza->imie);
    printf("Adres:\n%s ", pierwsza->miasto);
    printf("%s ", pierwsza->ulica);
    printf("%s ", pierwsza->numer);
    printf("%s ", pierwsza->kod_pocztowy);
    printf("%s \n", pierwsza->poczta);
    printf("Numery telefonow:\n");
    struct numery *tmp=(pierwsza->pierwszynumer);
    while(tmp)
    {
        printf("%s ",tmp->telefon);
        tmp=(tmp->nastepny);
    }
    struct adresy *tmp2=(pierwsza->pierwszyadres);
    printf("\nMaile:\n");
    while(tmp2)
    {
        printf("%s ",tmp2->mail);
        tmp2=(tmp2->nastepny);
    }
    puts("\n");
}

void wyswietl_liste(struct dane *pierwsza){
    if(pierwsza==NULL){
            puts("Brak kontaktow, nie mozna wyswietlic");
    return;
    }
    while (pierwsza)
    {
        wyswietl_kontakt(pierwsza);
        pierwsza=pierwsza->nastepna;
    }

}
void edycja(struct dane *pierwsza){
    if(pierwsza==NULL){
            puts("Brak kontaktow, nie mozna edytowac");
            system("pause");
    return;
    }
    int i;
    char j;
    system("cls");
        wyswietl_liste(pierwsza);
    printf("Podaj indeks osoby: \n" );
    scanf(" %d", &i);
        struct dane *tmp = pierwsza;
        while(tmp)
        {
            if(tmp->id==i)
            break;
            tmp=tmp->nastepna;
        }
        system("cls");
        if(tmp){
        wyswietl_kontakt(tmp);
        puts("Co chcesz zmienic?");

    printf("1. Edytuj nazwisko \n");
    printf("2. Edytuj imie\n");
    printf("3. Edytuj miasto\n");
    printf("4. Edytuj ulice \n");
    printf("5. Edytuj numer budynku/mieszkania\n");
    printf("6. Edytuj kod pocztowy\n");
    printf("7. Edytuj poczte\n");
    printf("8. Edytuj telefon\n");
    printf("9. Edytuj adres email\n");
    printf("Twoj wybor: ");
    scanf(" %c",&j);

    if (j == '1'){
        printf("Nazwisko: \n");
        scanf(" %s",tmp->nazwisko);
        while(!walidacja(tmp->nazwisko)){
            printf("Nazwisko niepoprawne, podaj nowe: \n");
            scanf(" %s",tmp->nazwisko);
        }
    }
    else if (j == '2'){
        printf("Imie: \n");
        scanf(" %s",tmp->imie);
        while(!walidacja(tmp->imie)){
            printf("Imie niepoprawne, podaj nowe: \n");
            scanf(" %s",tmp->imie);
        }
    }
    else if (j == '3'){
       printf("Miasto: \n");
        scanf(" %s",tmp->miasto);
        while(!walidacja(tmp->miasto)){
            printf("Miasto niepoprawne, podaj nowe: \n");
            scanf(" %s",tmp->miasto);
        }
    }
    else if (j == '4'){
        printf("Ulica: \n");
        scanf(" %s",tmp->ulica);
        while(!walidacja(tmp->ulica)){
            printf("Ulica niepoprawna,podaj nowa: \n");
            scanf(" %s",tmp->ulica);
        }
    }

    else if (j == '5'){
        printf("Numer budynku/mieszkania: \n");
        scanf(" %s",tmp->numer);
        while(!walidacjanrb(tmp->numer)){
            printf("Numer budynku/mieszkania niepoprawny,podaj nowy: \n");
            scanf(" %s",tmp->numer);
        }
    }
    else if (j == '6'){
        printf("Kod pocztowy: \n");
        scanf(" %s",tmp->kod_pocztowy);
        while(!walidacjakod(tmp->kod_pocztowy)){
            printf("Kod pocztowy niepoprawny,podaj nowy: \n");
            scanf(" %s",tmp->kod_pocztowy);
        }
    }
    else if (j == '7'){
        printf("Poczta: \n");
        scanf(" %s",tmp->poczta);
        while(!walidacja(tmp->poczta)){
            printf("Poczta niepoprawna, podaj nowa: \n");
            scanf(" %s",tmp->poczta);
        }
    }
    else if (j == '8'){
        while(tmp->pierwszynumer){
            tmp->pierwszynumer=tmp->pierwszynumer->nastepny;
            free(tmp->pierwszynumer);
        }
        char a;
        tmp->pierwszynumer=NULL;
        do{
            printf("Telefon: \n");
            tmp->pierwszynumer=dodawanienumeru(tmp->pierwszynumer);
            puts("czy chcesz podac wiecej numerow T/N");
            scanf(" %c",&a);
        }
        while(a!='N'&&a!='n');

    }
    else if (i == '9'){
        while(tmp->pierwszyadres){
            tmp->pierwszyadres=tmp->pierwszyadres->nastepny;
            free(tmp->pierwszyadres);
        }
        char a;

        tmp->pierwszyadres=NULL;
        do{
            printf("Mail: \n");
            tmp->pierwszyadres=dodawanieadresu(tmp->pierwszyadres);
            puts("czy chcesz podac wiecej emaili T/N");
            scanf(" %c",&a);
        }
        while(a!='N'&&a!='n');
    }
    }
    else {
        puts("Brak kontaktu o takim ID");
        system("pause");
    }
}

struct dane *usunpocz(struct dane *pierwsza){
    struct dane *nastepny = pierwsza->nastepna;
    while(pierwsza->pierwszyadres){
            pierwsza->pierwszyadres=pierwsza->pierwszyadres->nastepny;
            free(pierwsza->pierwszyadres);
        }
        while(pierwsza->pierwszynumer){
            pierwsza->pierwszynumer=pierwsza->pierwszynumer->nastepny;
            free(pierwsza->pierwszynumer);
        }
    free(pierwsza);
    return nastepny;
}

struct dane *znajdz_poprzedni(struct dane *pierwsza, int data){
    struct dane *poprzedni = NULL;
    while(pierwsza && pierwsza->id!=data) {
        poprzedni=pierwsza;
        pierwsza=pierwsza->nastepna;
    }
    return poprzedni;
}

void usunkoniec(struct dane *poprzedni){
    struct dane *tmp = poprzedni->nastepna;
    if(tmp) {
        poprzedni->nastepna = tmp->nastepna;
        while(tmp->pierwszyadres){
            tmp->pierwszyadres=tmp->pierwszyadres->nastepny;
            free(tmp->pierwszyadres);
        }
        while(tmp->pierwszynumer){
            tmp->pierwszynumer=tmp->pierwszynumer->nastepny;
            free(tmp->pierwszynumer);
        }
        free(tmp);
    }
}

struct dane *usuwanie(struct dane *pierwsza){
    struct dane *tmp = pierwsza;
    if(pierwsza==NULL){
            puts("Brak kontaktow, nie mozna usuwac");
            system("pause");
    return pierwsza;
    }
    int i;
    printf("Podaj indeks osoby: " );
    scanf("%d", &i);

        if(pierwsza) {
        if(pierwsza->id==i){
            return usunpocz(pierwsza);}
        else {
            struct dane *poprzedni = znajdz_poprzedni(pierwsza,i);
            if(poprzedni){
            while(tmp!=poprzedni->nastepna){
                tmp->id-=1;
                tmp=tmp->nastepna;
            }
            usunkoniec(poprzedni);
            }
        }
    }
    puts("Kontakt usuniety");
    return pierwsza;
}

void znajdz_kontakt(struct dane *pierwsza){
    if(pierwsza==NULL){
            puts("Brak kontaktow, nie mozna wyszukac");
            system("pause");
    return;
    }
    system("cls");
    char i;
    char buffor[20];
    puts("Po jakim polu chcesz szukac?");
    printf("1.  nazwisko \n");
    printf("2.  imie\n");
    printf("3.  miasto\n");
    printf("4.  ulice \n");
    printf("5.  numer budynku/mieszkania\n");
    printf("6.  kod pocztowy\n");
    printf("7.  poczta\n");
    printf("8.  telefon\n");
    printf("9.  adres email\n");
    scanf("%s",&i);
    if(i=='1'){
        puts("Wpisz nazwisko ktorego szukasz");
        scanf("%s",buffor);
        while(pierwsza){
            if(strcmp(buffor,pierwsza->nazwisko)==0){
                wyswietl_kontakt(pierwsza);
            }
            pierwsza=pierwsza->nastepna;
        }
    }
    if(i=='2'){
        puts("Wpisz imie ktorego szukasz");
        scanf("%s",buffor);
        while(pierwsza){
            if(strcmp(buffor,pierwsza->imie)==0){
                wyswietl_kontakt(pierwsza);
            }
            pierwsza=pierwsza->nastepna;
        }
    }
    if(i=='3'){
        puts("Wpisz miasto ktorego szukasz");
        scanf("%s",buffor);
        while(pierwsza){
            if(strcmp(buffor,pierwsza->miasto)==0){
                wyswietl_kontakt(pierwsza);
            }
            pierwsza=pierwsza->nastepna;
        }
    }
    if(i=='4'){
        puts("Wpisz ulice ktorej szukasz");
        scanf("%s",buffor);
        while(pierwsza){
            if(strcmp(buffor,pierwsza->ulica)==0){
                wyswietl_kontakt(pierwsza);
            }
            pierwsza=pierwsza->nastepna;
        }
    }
    if(i=='5'){
        puts("Wpisz numer budynku/mieszkania ktorego szukasz");
        scanf("%s",buffor);
        while(pierwsza){
            if(strcmp(buffor,pierwsza->numer)==0){
                wyswietl_kontakt(pierwsza);
            }
            pierwsza=pierwsza->nastepna;
        }
    }
    if(i=='6'){
        puts("Wpisz kod pocztowy ktorego szukasz");
        scanf("%s",buffor);
        while(pierwsza){
            if(strcmp(buffor,pierwsza->kod_pocztowy)==0){
                wyswietl_kontakt(pierwsza);
            }
            pierwsza=pierwsza->nastepna;
        }
    }
    if(i=='7'){
        puts("Wpisz poczte ktorej szukasz");
        scanf("%s",buffor);
        while(pierwsza){
            if(strcmp(buffor,pierwsza->poczta)==0){
                wyswietl_kontakt(pierwsza);
            }
            pierwsza=pierwsza->nastepna;
        }
    }
    if(i=='8'){
        struct numery *tmp=pierwsza->pierwszynumer;
        puts("Wpisz numer ktorego szukasz");
        scanf("%s",buffor);
        while(pierwsza){
            while(tmp){
                if(strcmp(buffor,tmp->telefon)==0){
                wyswietl_kontakt(pierwsza);
                }
                tmp=tmp->nastepny;
            }
            pierwsza=pierwsza->nastepna;
        }
    }
    if(i=='9'){
        struct adresy *tmp2=pierwsza->pierwszyadres;
        puts("Wpisz numer ktorego szukasz");
        scanf("%s",buffor);
        while(pierwsza){
            while(tmp2){
                if(strcmp(buffor,tmp2->mail)==0){
                wyswietl_kontakt(pierwsza);
                }
                tmp2=tmp2->nastepny;
            }
            pierwsza=pierwsza->nastepna;
        }
    }
    system("pause");
}
void zapis_do_pliku(struct dane *pierwsza){
    FILE *plik=fopen("baza.txt","w");
    if(plik==NULL){
        printf("Blad otwarcia pliku!\n");
        return;
    }

    while(pierwsza!=NULL){
        fprintf(plik,"%d ", pierwsza->id);
        fprintf(plik,"%s ", pierwsza->nazwisko);
        fprintf(plik,"%s ", pierwsza->imie);
        fprintf(plik,"%s ", pierwsza->miasto);
        fprintf(plik,"%s ", pierwsza->ulica);
        fprintf(plik,"%s ", pierwsza->numer);
        fprintf(plik,"%s ", pierwsza->kod_pocztowy);
        fprintf(plik,"%s ", pierwsza->poczta);
        struct numery *tmp=(pierwsza->pierwszynumer);
        while(tmp){
            fprintf(plik,"%s ",tmp->telefon);
            tmp=(tmp->nastepny);
        }
        fprintf(plik,"%s ","koniec1");

        struct adresy *tmp2=(pierwsza->pierwszyadres);

        while(tmp2){
            fprintf(plik,"%s ",tmp2->mail);
            tmp2=(tmp2->nastepny);
        }
        fprintf(plik,"%s ","koniec2");
        fprintf(plik,"\n");
        pierwsza=pierwsza->nastepna;
    }
    if(fclose(plik)){
        printf("Blad zamkniecia pliku!\n");
    }
}
struct dane *wczytaj_z_pliku(struct dane *pierwsza){
    FILE *plik=fopen("baza.txt","r");
    if(plik==NULL){
        printf("Blad otwarcia pliku!\n");
        return 0;
    }
    struct dane *pom;
    char tmp[20];
    while(fscanf(plik,"%s", tmp) != EOF){
        struct dane *osoba = (struct dane *)malloc(sizeof(struct dane));
        osoba->pierwszynumer=NULL;
        osoba->pierwszyadres=NULL;
        osoba->nastepna=NULL;
        osoba->id=atoi(tmp);
        fscanf(plik,"%s",tmp);
        strcpy(osoba->nazwisko,tmp);
        fscanf(plik,"%s",tmp);
        strcpy(osoba->imie,tmp);
        fscanf(plik,"%s",tmp);
        strcpy(osoba->miasto,tmp);
        fscanf(plik,"%s",tmp);
        strcpy(osoba->ulica,tmp);
        fscanf(plik,"%s",tmp);
        strcpy(osoba->numer,tmp);
        fscanf(plik,"%s",tmp);
        strcpy(osoba->kod_pocztowy,tmp);
        fscanf(plik,"%s",tmp);
        strcpy(osoba->poczta,tmp);
        fscanf(plik,"%s",tmp);
         while(strcmp(tmp,"koniec1")!=0){
            struct numery *tmp2,*numer = (struct numery *)malloc(sizeof(struct numery));
            strcpy(numer->telefon,tmp);
            fscanf(plik,"%s",tmp);
            numer->nastepny=NULL;
            if(osoba->pierwszynumer==NULL){
                osoba->pierwszynumer=numer;
            }
            else {
                tmp2=osoba->pierwszynumer;
                while(tmp2->nastepny!=NULL){
                    tmp2=tmp2->nastepny;
                }
                tmp2->nastepny=numer;
            }
        }
         fscanf(plik,"%s",tmp);
         while(strcmp(tmp,"koniec2")!=0){
            struct adresy *tmp3,*adres = (struct adresy *)malloc(sizeof(struct adresy));
            strcpy(adres->mail,tmp);
            fscanf(plik,"%s",tmp);
            adres->nastepny=NULL;
            if(osoba->pierwszyadres==NULL){
                osoba->pierwszyadres=adres;
            }
            else {
                tmp3=osoba->pierwszyadres;
                while(tmp3->nastepny!=NULL){
                    tmp3=tmp3->nastepny;
                }
                tmp3->nastepny=adres;
            }
        }
        if(pierwsza==NULL){
            pierwsza=osoba;
        }
        else {
           pom=pierwsza;
           while(pom->nastepna!=NULL){
            pom=pom->nastepna;
           }
           pom->nastepna=osoba;
        }

    }
    if(fclose(plik)){
        printf("Blad zamkniecia pliku!\n");
    }
    return pierwsza;
}
inline int porownajint(int pierwsza,int druga){
    if(pierwsza>=druga)
    return 1;
    else return 0;
}
inline int porownajint2(int pierwsza,int druga){
    if(pierwsza<=druga)
    return 1;
    else return 0;
}
inline int porownajchar(char *pierwsza,char *druga){
        if(strcmp(pierwsza,druga)>=0)
            return 1;
        else return 0;
}
inline int porownajchar2(char *pierwsza,char *druga){
        if(strcmp(pierwsza,druga)<=0)
            return 1;
        else return 0;
}
void sortujnumery(struct numery **pierwsza,int test2)
{
struct numery *posortowana = NULL;
int tmp;
   while((*pierwsza) != NULL)
   {
      struct numery *szukany = *pierwsza;
      struct numery *przed_szukany = NULL;
      struct numery *poprzedni = *pierwsza;
      struct numery *i = (*pierwsza)->nastepny;
			while(i!= NULL)
      {
            if(test2==2)
                tmp=porownajchar(i->telefon,szukany->telefon);
            else
                tmp=porownajchar2(i->telefon,szukany->telefon);

         if(tmp>0)
         {
            szukany = i;
            przed_szukany = poprzedni;
         }
         poprzedni=i;
         i =i->nastepny;
      }
      if(przed_szukany != NULL)
         przed_szukany->nastepny = szukany->nastepny;
      else
         *pierwsza = szukany->nastepny;
      szukany->nastepny = posortowana;
      posortowana = szukany;
   }
   *pierwsza = posortowana;
}
void sortujadresy(struct adresy **pierwsza,int test2)
{
struct adresy *posortowana = NULL;
int tmp;
   while((*pierwsza) != NULL)
   {
      struct adresy *szukany = *pierwsza;
      struct adresy *przed_szukany = NULL;
      struct adresy *poprzedni = *pierwsza;
      struct adresy *i = (*pierwsza)->nastepny;
			while(i!= NULL)
      {
            if(test2==2)
                tmp=porownajchar(i->mail,szukany->mail);
            else
                tmp=porownajchar2(i->mail,szukany->mail);

         if(tmp>0)
         {
            szukany = i;
            przed_szukany = poprzedni;
         }
         poprzedni=i;
         i =i->nastepny;
      }
      if(przed_szukany != NULL)
         przed_szukany->nastepny = szukany->nastepny;
      else
         *pierwsza = szukany->nastepny;
      szukany->nastepny = posortowana;
      posortowana = szukany;
   }
   *pierwsza = posortowana;
}

void sortuj(struct dane **pierwsza,int test1,int test2)
{
struct dane *posortowana = NULL;
int tmp;
   while((*pierwsza) != NULL)
   {
      struct dane *szukany = *pierwsza;
      struct dane *przed_szukany = NULL;
      struct dane *poprzedni = *pierwsza;
      struct dane *i = (*pierwsza)->nastepna;
			while(i!= NULL)
      {
          if(test1==1){
            if(test2==1)
                tmp=porownajint(i->id,szukany->id);
            else
                tmp=porownajint2(i->id,szukany->id);
          }
          if(test1==2){
            if(test2==1)
                tmp=porownajchar(i->nazwisko,szukany->nazwisko);
            else
                tmp=porownajchar2(i->nazwisko,szukany->nazwisko);
          }
          if(test1==3){
            if(test2==1)
                tmp=porownajchar(i->imie,szukany->imie);
            else
                tmp=porownajchar2(i->imie,szukany->imie);
          }
          if(test1==4){
            if(test2==1)
                tmp=porownajchar(i->miasto,szukany->miasto);
            else
                tmp=porownajchar2(i->miasto,szukany->miasto);
          }
          if(test1==5){
            if(test2==1)
                tmp=porownajchar(i->ulica,szukany->ulica);
            else
                tmp=porownajchar2(i->ulica,szukany->ulica);
          }
          if(test1==6){
            if(test2==1)
                tmp=porownajchar(i->numer,szukany->numer);
            else
                tmp=porownajchar2(i->numer,szukany->numer);
          }
          if(test1==7){
            if(test2==1)
                tmp=porownajchar(i->kod_pocztowy,szukany->kod_pocztowy);
            else
                tmp=porownajchar2(i->kod_pocztowy,szukany->kod_pocztowy);
          }
          if(test1==8){
            if(test2==1)
                tmp=porownajchar(i->poczta,szukany->poczta);
            else
                tmp=porownajchar2(i->poczta,szukany->poczta);
          }
          if(test1==9){
            sortujnumery(&(i->pierwszynumer),test2);
          }
          if(test1==0){
            sortujadresy(&(i->pierwszyadres),test2);
          }

         if(tmp>0)
         {
            szukany = i;
            przed_szukany = poprzedni;
         }
         poprzedni=i;
         i =i->nastepna;
      }
      if(przed_szukany != NULL)
         przed_szukany->nastepna = szukany->nastepna;
      else
         *pierwsza = szukany->nastepna;
      szukany->nastepna = posortowana;
      posortowana = szukany;
   }
   *pierwsza = posortowana;
}

struct dane *sortowanie(struct dane *pierwsza){
    system("cls");
    int i,j;
    do{
    puts("Sortowanie po: ");
    puts("1.id");
    puts("2.Nazwisko");
    puts("3.Imie");
    puts("4.Miasto");
    puts("5.Ulica");
    puts("6.Numer mieszkania/budynku");
    puts("7.Kod pocztowy");
    puts("8.Poczta");
    puts("9.Numer telefonu");
    puts("0.Adres email");
    scanf("%d",&i);
    system("cls");
   } while(((i<0)||(i>9)));
    system("cls");
    do{
    puts("1.Rosnaco\n2.Malejaco");
    scanf("%d",&j);
    system("cls");
    }while(((j<1)||(j>2)));
    sortuj(&pierwsza,i,j);
    wyswietl_liste(pierwsza);
    system("pause");

return pierwsza;
}
struct dane *menu(struct dane *pierwsza){
    char i;
    pierwsza=wczytaj_z_pliku(pierwsza);

    do{
        system("cls");
        printf("1. Dodawanie \n");
        printf("2. Wyswietlanie\n");
        printf("3. Usuwanie\n");
        printf("4. Edycja\n");
        printf("5. Znajdz kontakt\n");
        printf("6. Zapis do pliku\n");
        printf("7. Wczytaj z pliku\n");
        printf("8. Opcje sortowania\n");
        printf("0. Wyjscie\n\n");
        printf("Twoj wybor: ");
        scanf(" %c",&i);
        if (i == '1') {
                sortuj(&pierwsza,1,2);
                pierwsza=wypelnianie(pierwsza);
        }
        else if (i == '2') {
                wyswietl_liste(pierwsza);
                system("pause");
        }
        else if (i == '3') {
                wyswietl_liste(pierwsza);
                pierwsza=usuwanie(pierwsza);
                system("pause");
        }
        else if (i == '4') edycja(pierwsza);
        else if (i == '5') znajdz_kontakt(pierwsza);
        else if (i == '6') {
                zapis_do_pliku(pierwsza);
                puts("Zapisano do pliku");
                system("pause");
        }
        else if (i == '7') pierwsza=wczytaj_z_pliku(pierwsza);
        else if (i == '8') pierwsza=sortowanie(pierwsza);
    }
    while (i != '0');
return pierwsza;
}
