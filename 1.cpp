#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

#define TAM 10

using namespace std;

//Metodo que deixa uma string qualquer em maisculo.
string toUpper(const string &s) {
    string temp = s;
    transform(temp.begin(), temp.end(), temp.begin(),
              [](unsigned char c){ return toupper(c); });
    return temp;
}

//Metodo que verifica se a string (nome) inserida tem apenas uma palavra
bool contadorDePalavras(string nome)
{
	int numerosDeEspacos = 0;
	char proximaLetra;
	//Checa cada caractere na string
	for (int i=0; i<int(nome.length()); i++)
	{
		proximaLetra = nome.at(i);
		if (isspace(nome[i]))
			numerosDeEspacos++;
	}

    if(numerosDeEspacos<1){
        return false;
    }
    else{
        return true;
    }
}

//Metodo que popula um vetor de string de TAM nomes completos.
void populaString(string *v, int n) {

    for (int qtdInseridos = 0; qtdInseridos < n ;){
        string nome;
        cout << "Insira um nome:" << endl;
        getline(cin, nome);
        if(contadorDePalavras(nome)){
            v[qtdInseridos] = toUpper(nome);
            qtdInseridos++;
        }else{
            cout << "O nome inserido nao e um nome completo. Insira um nome completo." << endl;
        }    
     }   
}

//Metodo que exibe um vetor de strings qualquer dado o seu tamanho.
void exibe(string *v, int n) {
    cout << "Nomes inseridos:" << endl;
    for (int i = 0; i < n; i++) {
        cout << v[i] << endl;
    }
}

int main(){

    string nomesCompletos[TAM];

    populaString(nomesCompletos, TAM);

    exibe(nomesCompletos,TAM);

    return 0;
}