#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Sistema que Cadastra e calcula o IMC dos Usuários

struct Pessoas {
	string nome;
	int idade;
	float peso;
	float altura;
	float imc;
	int tamanho = 0;
};

// Declarar o vetor de forma "global" para ser usado por mais de uma função
vector<Pessoas> pessoa;

//Função que cadastra as pessoas
void CadastrarPessoas(vector<Pessoas>& pessoa) {
	Pessoas pessoas;
	cout << "Digite quantas pessoa voce deseja cadastrar: " << endl;
	cin >> pessoas.tamanho;

	for (int i = 0; i < pessoas.tamanho; i++) {
		cout << "Digite o seu nome: " << endl;
		cin.ignore();
		getline(cin, pessoas.nome);
		cout << "Digite a sua idade: " << endl;
		cin >> pessoas.idade;
		cout << "Digite o seu peso: " << endl;
		cin >> pessoas.peso;
		cout << "Digite a sua altura: " << endl;
		cin >> pessoas.altura;
		pessoas.imc = pessoas.peso / (pessoas.altura * pessoas.altura);

		pessoa.push_back(pessoas); //Utiliza-se o push back para armazenar o valor de 'pessoas' em pessoa
	}

	//laço que printa as informações cadastradas 
	for (const Pessoas& p : pessoa) {
		cout << "\nNome: " << p.nome << endl;
		cout << "Idade: " << p.idade << endl;
		cout << "Peso: " << p.peso << " Kg" << endl;
		cout << "Altura: " << p.altura << " m" << endl;
		cout << "IMC: " << p.imc << endl;

	}
	

}

void ListaDePessoas(const vector<Pessoas>& pessoa) { //Passa o valor constante do vetor para printar os nomes ja existentes
	Pessoas pessoas;


	cout << "------------------------ Lista de Pessoas ----------------------------------------" << endl;
	for (const Pessoas& p : pessoa) {
		cout << "\nNome: " << p.nome << endl;
		cout << "Idade: " << p.idade << endl;
		cout << "Peso: " << p.peso << " Kg" << endl;
		cout << "Altura: " << p.altura << " m" << endl;
		cout << "IMC: " << p.imc << endl;

		cout << "\n----------------------------------------------Atual Condicao---------------------------------------------" << endl;

		if (p.imc < 18.5) {
			cout << p.nome <<": Abaixo do Peso." << endl;
		}
		if (p.imc > 18.6 && p.imc < 24.99) {
			cout << p.nome << ": Peso Ideal." << endl;
		}
		else if (p.imc > 25.0 && p.imc < 29.99) {
			cout << p.nome <<": Levemente acima do peso." << endl;
		}
		else if(p.imc > 30.0 && p.imc < 34.99) {
			cout << p.nome << ": Obesidade Grau I" << endl;
		}
		else if (p.imc > 35.5 && p.imc < 39.99) {
			cout << p.nome << ": Obesidade Grau II (severa)" << endl;
		}
		else if (p.imc>=40.0){
			cout << p.nome << ": Obesidade III (morbida)" << endl;

		}
	}
}

void PesquisarNome(const vector<Pessoas>& pessoa) {
	Pessoas pessoas;
	string nomepesquisa;
	cout << "Digite o nome que voce quer pesquisar: " << endl;
	cin.ignore();
	getline(cin, nomepesquisa);

	bool nome_encontrado = false;
	
	//Laço para comparar se uma string é igual a outra
	for (const Pessoas& p : pessoa) {

		if (nomepesquisa == p.nome) {
			for(int i=0; i < p.tamanho; i++)
			cout << "\nNome: " << p.nome << endl;
			cout << "Idade: " << p.idade << endl;
			cout << "Peso: " << p.peso << " Kg" << endl;
			cout << "Altura: " << p.altura << " cm" << endl;
			cout << "IMC: " << p.imc << endl;

			cout << "\n----------------------------------------------Atual Condicao---------------------------------------------" << endl;

			if (p.imc < 18.5) {
				cout << "Abaixo do Peso." << endl;
			}
			if (p.imc > 18.6 and p.imc < 24.99) {
				cout << "Peso Ideal." << endl;
			}
			else if (p.imc > 25.0 and p.imc < 29.99) {
				cout << "Levemente acima do peso." << endl;
			}
			else if (p.imc > 30.0 && p.imc < 34.99) {
				cout << p.nome << ": Obesidade Grau I" << endl;
			}
			else if (p.imc > 35.5 && p.imc < 39.99) {
				cout << p.nome << ": Obesidade Grau II (severa)" << endl;
			}
			else if (p.imc >=40.0){
				cout << p.nome << ": Obesidade III (morbida)" << endl;

			}
			nome_encontrado = true;
		}

		
	}
	if (!nome_encontrado) {
		cout << "Nao encontramos esse usuario. Tente novamente!";
	}
	
	
}


int main() {
	char opcao;
	while (true) {
		cout << "\n-----------------------------------MENU--------------------------------------" << endl;
		cout << "1. Cadastrar pessoas" << endl;
		cout << "2. Listar pessoas cadastradas" << endl;
		cout << "3. Pesquisar pessoas por nome" << endl;
		cout << "4. Sair" << endl;
		cin >> opcao;

		switch (opcao) {
		case '1': {
			CadastrarPessoas(pessoa);
			break;
		}

		case '2': {
			ListaDePessoas(pessoa);
			break;
		}

		case '3': {
			PesquisarNome(pessoa);
			break;
		}

		case '4': {
			return 0;
		}

		default: {
			cout << "Opcao invalida tente novamente." << endl;
		}
		}
	}


	return 0;
}