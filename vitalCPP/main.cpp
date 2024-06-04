#include <iostream>
#include <cstring>
using namespace std;

const int maxProdutos = 100;

struct Produto {
    char nome[50];
    int quantidade;
    float preco;
};

void adicionarProduto(Produto inventario[], int &numProdutos) {
    if (numProdutos >= maxProdutos) {
        cout << "Inventario cheio. Nao e possivel adicionar mais produtos." << endl;
        return;
    }
    cout << "Digite o nome do produto: ";
    cin.ignore();
    cin.getline(inventario[numProdutos].nome, 50);
    cout << "Digite a quantidade: ";
    cin >> inventario[numProdutos].quantidade;
    cout << "Digite o preco: ";
    cin >> inventario[numProdutos].preco;
    numProdutos++;
}

void removerProduto(Produto inventario[], int &numProdutos) {
    if (numProdutos == 0) {
        cout << "Nenhum produto cadastrado." << endl;
        return;
    }
    cout << "Digite o nome do produto a ser removido: ";
    char nome[50];
    cin.ignore();
    cin.getline(nome, 50);
    
    for (int i = 0; i < numProdutos; i++) {
        if (strcmp(inventario[i].nome, nome) == 0) {
            for (int j = i; j < numProdutos - 1; j++) {
                inventario[j] = inventario[j + 1];
            }
            numProdutos--;
            cout << "Produto removido com sucesso." << endl;
            return;
        }
    }
    cout << "Produto nao encontrado." << endl;
}

void listarProdutos(const Produto inventario[], int numProdutos) {
    if (numProdutos == 0) {
        cout << "Nenhum produto cadastrado." << endl;
        return;
    }
    cout << "Produtos cadastrados:" << endl;
    for (int i = 0; i < numProdutos; i++) {
        cout << "Nome: " << inventario[i].nome << ", Quantidade: " << inventario[i].quantidade << ", Preco: " << inventario[i].preco << endl;
    }
}

void buscarProduto(const Produto inventario[], int numProdutos) {
    if (numProdutos == 0) {
        cout << "Nenhum produto cadastrado." << endl;
        return;
    }
    cout << "Digite o nome do produto a ser buscado: ";
    char nome[50];
    cin.ignore();
    cin.getline(nome, 50);
    
    for (int i = 0; i < numProdutos; i++) {
        if (strcmp(inventario[i].nome, nome) == 0) {
            cout << "Produto encontrado: Nome: " << inventario[i].nome << ", Quantidade: " << inventario[i].quantidade << ", Preco: " << inventario[i].preco << endl;
            return;
        }
    }
    cout << "Produto nao encontrado." << endl;
}

int main() {
    Produto inventario[maxProdutos];
    int numProdutos = 0;
    int opcao;

    do {
        cout << "Menu:" << endl;
        cout << "1. Adicionar produto" << endl;
        cout << "2. Remover produto" << endl;
        cout << "3. Listar produtos" << endl;
        cout << "4. Buscar produto por nome" << endl;
        cout << "5. Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                adicionarProduto(inventario, numProdutos);
                break;
            case 2:
                removerProduto(inventario, numProdutos);
                break;
            case 3:
                listarProdutos(inventario, numProdutos);
                break;
            case 4:
                buscarProduto(inventario, numProdutos);
                break;
            case 5:
                cout << "Saindo..." << endl;
                break;
            default:
                cout << "Opcao invalida." << endl;
        }
        cout << endl;
    } while (opcao != 5);

    return 0;
}