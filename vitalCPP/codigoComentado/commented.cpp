#include <iostream>  // Biblioteca para entrada e saída de dados
#include <cstring>   // Biblioteca para manipulação de strings em C
using namespace std; // Para evitar usar std:: antes de cada comando do namespace std

const int maxProdutos = 100; // Define a constante para o número máximo de produtos no inventário

// Estrutura que define um Produto
struct Produto {
    char nome[50];  // Nome do produto, com até 49 caracteres + 1 caractere nulo
    int quantidade; // Quantidade do produto em estoque
    float preco;    // Preço do produto
};

// Função para adicionar um produto ao inventário
void adicionarProduto(Produto inventario[], int &numProdutos) { // Em "&numProdutos" o "&" é utilizado para informar que numProdutos é uma variavel que pode ser alterada na função e recebida, alterada, na main.
    if (numProdutos >= maxProdutos) { // Verifica se o inventário está cheio
        cout << "Inventario cheio. Nao e possivel adicionar mais produtos." << endl;
        return; // Sai da função se não for possível adicionar mais produtos
    }
    cout << "Digite o nome do produto: ";
    cin.ignore(); // Ignora o caractere de nova linha pendente no buffer de entrada
    cin.getline(inventario[numProdutos].nome, 50); // Lê o nome do produto
    cout << "Digite a quantidade: ";
    cin >> inventario[numProdutos].quantidade; // Lê a quantidade do produto
    cout << "Digite o preco: ";
    cin >> inventario[numProdutos].preco; // Lê o preço do produto
    numProdutos++; // Incrementa o contador de produtos no inventário / So funciona por conta do "&" 
}

// Função para remover um produto do inventário
void removerProduto(Produto inventario[], int &numProdutos) {
    if (numProdutos == 0) { // Verifica se o inventário está vazio
        cout << "Nenhum produto cadastrado." << endl;
        return; // Sai da função se não houver produtos para remover
    }
    cout << "Digite o nome do produto a ser removido: ";
    char nome[50];
    cin.ignore(); // Ignora o caractere de nova linha pendente no buffer de entrada
    cin.getline(nome, 50); // Lê o nome do produto a ser removido
    
    for (int i = 0; i < numProdutos; i++) { // Percorre o inventário para encontrar o produto
        if (strcmp(inventario[i].nome, nome) == 0) { // Compara o nome do produto com o nome fornecido
            for (int j = i; j < numProdutos - 1; j++) { // Remove o produto deslocando os elementos seguintes
                inventario[j] = inventario[j + 1];
            }
            numProdutos--; // Decrementa o contador de produtos
            cout << "Produto removido com sucesso." << endl;
            return; // Sai da função após remover o produto
        }
    }
    cout << "Produto nao encontrado." << endl; // Informa se o produto não foi encontrado
}

// Função para listar todos os produtos no inventário
void listarProdutos(const Produto inventario[], int numProdutos) {
    if (numProdutos == 0) { // Verifica se o inventário está vazio
        cout << "Nenhum produto cadastrado." << endl;
        return; // Sai da função se não houver produtos para listar
    }
    cout << "Produtos cadastrados:" << endl;
    for (int i = 0; i < numProdutos; i++) { // Percorre o inventário para listar os produtos
        cout << "Nome: " << inventario[i].nome << ", Quantidade: " << inventario[i].quantidade << ", Preco: " << inventario[i].preco << endl;
    }
}

// Função para buscar um produto no inventário pelo nome
void buscarProduto(const Produto inventario[], int numProdutos) {
    if (numProdutos == 0) { // Verifica se o inventário está vazio
        cout << "Nenhum produto cadastrado." << endl;
        return; // Sai da função se não houver produtos para buscar
    }
    cout << "Digite o nome do produto a ser buscado: ";
    char nome[50];
    cin.ignore(); // Ignora o caractere de nova linha pendente no buffer de entrada
    cin.getline(nome, 50); // Lê o nome do produto a ser buscado
    
    for (int i = 0; i < numProdutos; i++) { // Percorre o inventário para encontrar o produto
        if (strcmp(inventario[i].nome, nome) == 0) { // Compara o nome do produto com o nome fornecido / A função strcmp em C++ é usada para comparar duas strings. Ela está definida na biblioteca <cstring>.
            cout << "Produto encontrado: Nome: " << inventario[i].nome << ", Quantidade: " << inventario[i].quantidade << ", Preco: " << inventario[i].preco << endl;
            return; // Sai da função após encontrar o produto
        }
    }
    cout << "Produto nao encontrado." << endl; // Informa se o produto não foi encontrado
}

int main() {
    Produto inventario[maxProdutos]; // Declara o array de produtos
    int numProdutos = 0; // Inicializa o contador de produtos
    int opcao; // Variável para armazenar a opção do menu

    do {
        // Exibe o menu de opções
        cout << "Menu:" << endl;
        cout << "1. Adicionar produto" << endl;
        cout << "2. Remover produto" << endl;
        cout << "3. Listar produtos" << endl;
        cout << "4. Buscar produto por nome" << endl;
        cout << "5. Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao; // Lê a opção do usuário

        // Executa a função correspondente à opção escolhida
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
                cout << "Saindo..." << endl; // Mensagem de saída
                break;
            default:
                cout << "Opcao invalida." << endl; // Mensagem de opção inválida
        }
        cout << endl; // Linha em branco para melhor visualização
    } while (opcao != 5); // Repete o menu até o usuário escolher sair

    return 0; // Retorna 0 indicando que o programa terminou com sucesso
}