#include <iostream>

// Classe Singleton: Cozinha
class Cozinha {
private:
    static Cozinha* instancia;
    Cozinha() {} // Construtor privado

public:
    static Cozinha* getInstancia() {
        if (instancia == nullptr) {
            instancia = new Cozinha();
        }
        return instancia;
    }

    void fazerBolo() const {
        std::cout << "Preparando o bolo na cozinha." << std::endl;
    }
};

// Inicializa o ponteiro da instância
Cozinha* Cozinha::instancia = nullptr;

int main() {
    Cozinha* cozinha1 = Cozinha::getInstancia();
    Cozinha* cozinha2 = Cozinha::getInstancia();

    cozinha1->fazerBolo(); // Output: Preparando o bolo na cozinha.
    cozinha2->fazerBolo(); // Output: Preparando o bolo na cozinha.

    if (cozinha1 == cozinha2) {
        std::cout << "Ambas as instâncias apontam para a mesma cozinha." << std::endl;
    }

    return 0;
}
