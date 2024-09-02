#include <iostream>
#include <vector>
#include <memory>

// Interface para o componente do bolo
class ComponenteBolo {
public:
    virtual void exibir() const = 0;
    virtual ~ComponenteBolo() = default;
};

// Implementação de um componente simples do bolo
class ComponenteSimples : public ComponenteBolo {
private:
    std::string nome;
public:
    ComponenteSimples(const std::string& n) : nome(n) {}
    void exibir() const override {
        std::cout << nome << std::endl;
    }
};

// Implementação de um componente composto do bolo
class ComponenteComposto : public ComponenteBolo {
private:
    std::string nome;
    std::vector<std::unique_ptr<ComponenteBolo>> componentes;
public:
    ComponenteComposto(const std::string& n) : nome(n) {}
    
    void adicionar(std::unique_ptr<ComponenteBolo> componente) {
        componentes.push_back(std::move(componente));
    }

    void exibir() const override {
        std::cout << nome << " composto de:" << std::endl;
        for (const auto& componente : componentes) {
            componente->exibir();
        }
    }
};

int main() {
    auto bolo = std::make_unique<ComponenteComposto>("Bolo de Aniversário");

    auto massa = std::make_unique<ComponenteSimples>("Massa");
    auto recheio = std::make_unique<ComponenteComposto>("Recheio");
    recheio->adicionar(std::make_unique<ComponenteSimples>("Creme de Baunilha"));
    recheio->adicionar(std::make_unique<ComponenteSimples>("Geleia de Morango"));

    auto cobertura = std::make_unique<ComponenteSimples>("Cobertura de Chocolate");

    bolo->adicionar(std::move(massa));
    bolo->adicionar(std::move(recheio));
    bolo->adicionar(std::move(cobertura));

    bolo->exibir();

    return 0;
}
