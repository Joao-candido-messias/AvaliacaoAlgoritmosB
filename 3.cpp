#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#define N 100

// Função que lê nomes de um arquivo e os armazena no vetor, retornando a quantidade nomes lidos
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

//Metodo que ecibe um vetor qualquer de strings dado o seu tamanho.
void exibe(string *v, int n) {
    cout << "Nomes:" << endl;
    for (int i = 0; i < n; i++) {
        cout << v[i] << endl;
    }
}


int main() {
    string nomes[N];
    string arquivoOrigem;

    cout << "Digite o arquivo de origem: ";
    getline(cin, arquivoOrigem);

    int n = lerNomes(nomes, arquivoOrigem);

    if (n == 0) {
        cout << "Nenhum nome foi lido." << endl;
        return 1;
    }

    cout << "Quantidade de nomes lidos: " << n <<endl;
    exibe(nomes, n);

    return 0;
}
