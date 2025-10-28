#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#define N 100

//Metodo que verifica que o nome esta ou não repetido em uma lista de nomes.
int verificaRepetidos(string nomes[], int n){
    int qtdRepetidos = 0;
    for ( int i = 0; i <= n; i++) {
        string nome = nomes[i];
        for (int j = i + 1; j < n; j++) {
            if (nomes[j] == nome){
                qtdRepetidos++;
                cout << nome << endl;
            }
        }
    }
    cout << "Quantidade de nomes repetidos" << endl;
    return qtdRepetidos;
}

// Metodo que lê nomes de um arquivo e os armazena no vetor, retornando a quantidade de nomes lidos
int lerNomes(string nomes[], const string& arquivoOrigem) {
    ifstream arq(arquivoOrigem);
    if (!arq.is_open()) {
        cerr << "Arquivo \"" << arquivoOrigem << "\" não encontrado" << endl;
        return 0;
    }

    string linha;
    string nome;
    int count = 0;
    while (getline(arq, linha) && count < N) {
        nomes[count] = linha;
        count++;
    }

    arq.close();
    return count;
}

//Metodo que exibe os nomes de um vetor qualquer de strings dado o seu tamanho.
void exibe(string *v, int n) {
    cout << "Nomes:" << endl;
    for (int i = 0; i < n; i++) {
        cout << v[i] << endl;
    }
}


int main() {
    string nomes[N];
    string arquivoOrigem;
    string nomesRepetidos[N];

    cout << "Digite o arquivo de origem: ";
    getline(cin, arquivoOrigem);

    int n = lerNomes(nomes, arquivoOrigem);

    if (n == 0) {
        cout << "Nenhum nome foi lido." << endl;
        return 1;
    }

    cout << "Quantidade de nomes lidos: " << n <<endl;
    exibe(nomes, n);

    cout << "\nNomes repetidos:" << endl;
    cout << verificaRepetidos(nomes, n) << endl;

    return 0;
}
