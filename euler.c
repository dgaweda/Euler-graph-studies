#include <stdio.h>

int main(){
  int n,n1,n2, i,j, x = 1,nieparz=0, warunek_spojnosc=1;
  printf("Podaj ilosc wierzcholkow:\n");
  scanf("%d", &n);

  int macierz[n][n];// wyzerowanie
  for(i = 1;i <= n;i++){
    for(j = 1;j <= n;j++){
      macierz[i][j]=0;
    }
  }
  // wczytanie grafu
  printf("Podaj polaczenia wierzcholkow.\nZakres [1,%d]\n", n);
  while(x == 1){
    scanf("%d", &n1);//polaczenia wierzcholków n1 z n2
    scanf("%d", &n2);//
    if(n1 >= 1 && n1 <= n && n2 >= 1 && n2 <= n && n1 != n2){
      macierz[n1][n2]++; // +1 do podanego punktu w macierzy z gornej czesci
      macierz[n2][n1]++; // +1 do podanego punktu w macierzy z dolnej czesci
    }else{
      printf("Nie ma takiego wierzcholka\n\n  ");
      break;
    }
    printf("Czy chcesz podawać dalej?(1/0)");// Umozliwia zakonczenie wczytywania grafu
    scanf("%d", &x);
  }
  //spojnosc
  int visit; //zmienna okreslajaca czy wierzcholek zostal dowiedzony poprzez wartosc 1 lub 0

  for(i = 1; i <= n; i++){
    visit=0;
    for(j = 1; j <= n; j++){
      if(macierz[i][j] != 0 && j>i){
        visit = 1;
      }
      if(visit != 1 && j < n){
        printf("\nTen graf jest niespojny.\n");
        warunek_spojnosc = 0;
        break;
      }
      printf("\n");
    }

    int deg;
    // okreslenie stopni wierzcholkow
    for(i = 1; i <= n; i++){
      deg = 0;
      for(j = 1; j <= n; j++){
        printf("%d  ",macierz[i][j]);
        if(macierz[i][j] != 0)deg += macierz[i][j];
      }
      printf("  %d\n", deg);
      if(deg !=0 && deg % 2 != 0)nieparz++; // sprawdzenie nieparzystosci wierzcholkow
    }
    if(nieparz == 2 && n > 2 && warunek_spojnosc != 0)printf("Jest Poleulerowski\n");
    else if(nieparz == 0 && warunek_spojnosc != 0)printf("Jest Eulerowski\n");
    else if(warunek_spojnosc != 0)printf("Jest nieeulerowski");
  }
}
