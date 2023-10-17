#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std; 

void shellSort(int vet[], int N){
    //N = Tamanho máx do vetor
    int gap = 1;
    while(gap < N){
        //Acho o valor inicial da sequência de Knuth
        gap = 3 * gap + 1;
    }
    while(gap > 0){
        for(int i = gap; i < N; i += gap){
            int j = i;
            int aux = vet[i];
            while((j >= gap) && (aux < vet[j - gap])){
                vet[j] = vet[j - gap];
                j -= gap;
            }
            vet[j] = aux;
        }
        gap /= 3;
    }
}
   
int main(){ 
    int tamanho = 1000;
    int vet[tamanho];

    //Entradas Aleatórias
    /*srand(time(0));
    for (int i = 0; i < tamanho; i++) {
        vet[i] = rand() % 500000;
    }*/

    //Melhor caso
    /*for(int i = 0; i < tamanho; i++){
        vet[i] = i;
    }*/

    //Pior caso
    for(int i = 0; i < tamanho; i++){
        vet[i] = tamanho - i;
    }

    clock_t inicio = clock();
    shellSort(vet, tamanho);
    clock_t fim = clock();

    double tempoGasto = (double)(fim - inicio) / CLOCKS_PER_SEC * 1000;

    cout << "Vetor ordenado:" << endl;
    for (int i = 0; i < tamanho; i++) {
        cout << vet[i] << " ";
    }
    cout << endl;
    cout << fixed << setprecision(2) << "Tempo gasto: " << tempoGasto << " milissegundos" << endl;

    return 0;
}