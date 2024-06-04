#include <iostream>

int main() {
    std::cout << "ola mundo";
    // altera a cor do terminal
    // 5 é a cor de fundo
    // F é a cor da fonte
    system("color 5F");
    // executa o shell do Win e coloca o comando PAUSE
    system("PAUSE");
    return 0;
}