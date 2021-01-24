#include <stdio.h>

int main() {
    int n, m, n1, n2;
    printf("Podaj ilosc wierzcholkow: \n");
    scanf("%d", &n);
    printf("Podaj ilosc krawedzi: \n");
    scanf("%d", &m);
    n++; // +1 dla odpowiedniego definiowania ilosci wierzcholkow (start od 1)
// zerowanie macierzy
    int macierz[n][n];
    for(int i = 1; i < n; i++){
        for(int j = 1; j < n; j++){
            macierz[i][j] = 0;
        }
    }
//wczytanie par wierzcholkow z ktorymi lacza sie krawedzie grafu
    for(int i = 1; i <= m;i++){
        printf("Krawedz e%d laczy wierzcholki: \n", i);
        scanf("%d", &n1);
        scanf("%d", &n2);

        if(n1 != n2)macierz[n1][n2]++; // +1 dla liczby pod adresem macierz[n1][n2]
        if(n1 <= n && n2 <= n && n1>0 && n2>0){
            printf("--------------------------------------", n1 , n2);
        }else{
            printf("Nie ma takiego wierzcholka.\n");
            break;
        }
    }
    //wyswietlenie macierzy
    for(int k = 1; k < n; k++){
        for(int l = 1; l < n; l++){
            printf("%d", macierz[k][l]);
        }
        printf("\n");
    }
// obliczanie stopni wierzcholkow
    int suma,max = 0;
    for(int k = 1; k < n; k++){
        suma = 0;
        for(int l = 1; l < n; l++){
            if(macierz[k][l] == 1) suma++;
        }
        if(max<suma)max=suma;
        printf("\n deg(%d) = %d \n", k, suma);
    }
    printf("Stopien Grafu = %d", max);
}
