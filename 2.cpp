#include <iostream>

#define TAM 3

using namespace std;

//Metodo que popula um vetor de inteiros qualquer de maneira aleatoria, com numeros de 1 a 100, dado o seu tamanho.
void populaInteiros(int *v, int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        v[i] = rand() % 100;
    }
}

//Metodo que exibe um vetor de numeros inteiros qualquer dado o seu tamanho.
void exibe(int *v, int n) {
    for (int i = 0; i < n; i++) {
        cout << v[i] << endl;
    }
}

//Metodo que dado um vetor de numeros inteiros seleciona os pares e aloca em vetor exclusivo para este tipo.
void seletorDePares(int *v, int n, int *pares){
    int qtdPares = 0;
    for(int i = 0; i < n; i++){
        if(v[i] % 2 == 0){
            pares[i] = v[i];
            qtdPares++;
        }
    }

    cout << qtdPares << endl;
}

int main(){

    int numeros[TAM];
    int numerosPares[TAM];

    populaInteiros(numeros, TAM);

    cout << "Vetor original:" << endl;
    exibe(numeros, TAM);

    cout << "Quantidade de numeros pares realocados:" << endl;
    seletorDePares(numeros, TAM, numerosPares);

    return 0;
}