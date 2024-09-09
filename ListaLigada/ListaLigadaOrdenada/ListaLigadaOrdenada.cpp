//Danilo de Sena Santos - danilo.santos141@fatec.sp.gov.br

#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* primeiro = NULL;

// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
bool encontrarElemento(int numero);
//--------------------------


int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 7) {
		system("cls"); // somente no windows
		cout << "Menu Lista Ligada";
		cout << endl << endl;
		cout << "1 - Inicializar Lista \n";
		cout << "2 - Exibir quantidade de elementos \n";
		cout << "3 - Exibir elementos \n";
		cout << "4 - Buscar elemento \n";
		cout << "5 - Inserir elemento \n";
		cout << "6 - Excluir elemento \n";
		cout << "7 - Sair \n\n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2: exibirQuantidadeElementos();
			break;
		case 3: exibirElementos();
			break;
		case 4: buscarElemento();
			break;
		case 5: inserirElemento();
			break;
		case 6: excluirElemento();
			break;
		case 7:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{
	// se a lista já possuir elementos
// libera a memoria ocupada
	NO* aux = primeiro;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	primeiro = NULL;
	cout << "Lista inicializada \n";

}

void exibirQuantidadeElementos() {

	int nElementos = 0;
	NO* aux = primeiro;
	while (aux != NULL) {
		nElementos++;
		aux = aux->prox;
	}
	cout << "Quantidade de elementos: " << nElementos << endl;

}

void exibirElementos()
{
	if (primeiro == NULL) {
		cout << "Lista vazia \n";
		return;
	}
	else {
		cout << "Elementos: \n";
		NO* aux = primeiro;
		while (aux != NULL) {
			cout << aux->valor << endl;
			aux = aux->prox;
		}
	}
}

void inserirElemento()
{
	// aloca memoria dinamicamente para o novo elemento
	NO* novo = (NO*)malloc(sizeof(NO));
	if (novo == NULL)
	{
		return;
	}

	cout << "Digite o elemento: ";
	cin >> novo->valor;
	novo->prox = NULL;

	if (primeiro == NULL)
	{
		primeiro = novo;
	}
	else
	{
		NO* aux = primeiro;
		NO* ante = aux;
		bool exist = false;
		
		if (novo->valor > 0) {
			while (novo->valor >= aux->valor) {
				if (novo->valor == aux->valor) {
					exist = true;
				}
				ante = aux;
				aux = aux->prox;
				if (aux == NULL) {
					break;
				}
			}


			if (exist == true) {
				cout << "Valor ja contido na lista!" << endl;
			}
			else {
				ante->prox = novo;
				novo->prox = aux;
			}
		}
		else {
			if (aux->valor > novo->valor) {
				primeiro = novo;
				novo->prox = aux;
			}
			else {
				while (aux->valor <= novo->valor) {
					if (novo->valor == aux->valor) {
						exist = true;
					}
					aux = aux->prox;
					ante = aux;
					aux = aux->prox;
					if (aux == NULL) {
						break;
					}
				}
				if (exist == true) {
					cout << "Valor ja contido na lista!" << endl;
				}
				else {
					ante->prox = novo;
					novo->prox = aux;
				}
			}
		}
	}
}

void excluirElemento()
{
	bool found = false;
	int num;

	cout << "Digite um numero para excluir: ";
	cin >> num;
	found = encontrarElemento(num);

	if (found == false) {
		cout << "Este elemento nao existe" << endl;
	}
	else {
		if (num == primeiro->valor) {
			primeiro = primeiro->prox;
		}
		else {
			NO* aux = primeiro;
			NO* ante = aux;
			NO* paraExcluir = NULL;

			while (aux->valor <= num) {
				ante = aux;
				aux = aux->prox;

				if (num == aux->valor) {
					ante->prox = aux->prox;
					paraExcluir = aux;
					free(paraExcluir);
					break;
				}

				if (aux == NULL) {
					break;
				}
			}
		}
	}
}

void buscarElemento()
{
	bool found = false;
	NO* aux = primeiro;
	int num;
	cout << "Digite um numero para pesquisar: ";
	cin >> num;
	found = encontrarElemento(num);

	if (found == false) {
		cout << "Elemento nao encontrado" << endl;
	}
	else {
		cout << "Elemento encontrado" << endl;
	}
}


bool encontrarElemento(int numero)
{
	bool found = false;
	NO* aux = primeiro;
	while (aux->valor <= numero) {
		if (aux->valor == numero) {
			found = true;
			break;
		}
		aux = aux->prox;
		if (aux == NULL) {
			break;
		}
	}

	return found;
}