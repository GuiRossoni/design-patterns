#include <iostream>
#include <string>
#include <memory>

// Interface para o bolo
class Bolo {
public:
    virtual std::string fazer() const = 0;
    virtual ~Bolo() = default;
};

// Implementação básica do bolo
class BoloSimples : public Bolo {
public:
    std::string fazer() const override {
        return "Bolo básico";
    }
};

// Classe base para os decoradores
class BoloDecorator : public Bolo {
protected:
    std::unique_ptr<Bolo> bolo;
public:
    BoloDecorator(std::unique_ptr<Bolo> b) : bolo(std::move(b)) {}
    virtual std::string fazer() const override {
        return bolo->fazer();
    }
};

// Decorador para adicionar cobertura de chocolate
class ChocolateDecorator : public BoloDecorator {
public:
    ChocolateDecorator(std::unique_ptr<Bolo> b) : BoloDecorator(std::move(b)) {}
    std::string fazer() const override {
        return BoloDecorator::fazer() + " com cobertura de chocolate";
    }
};

// Decorador para adicionar frutas
class FrutasDecorator : public BoloDecorator {
public:
    FrutasDecorator(std::unique_ptr<Bolo> b) : BoloDecorator(std::move(b)) {}
    std::string fazer() const override {
        return BoloDecorator::fazer() + " com frutas";
    }
};

int main() {
    std::unique_ptr<Bolo> meuBolo = std::make_unique<BoloSimples>();
    meuBolo = std::make_unique<ChocolateDecorator>(std::move(meuBolo));
    meuBolo = std::make_unique<FrutasDecorator>(std::move(meuBolo));
    std::cout << meuBolo->fazer() << std::endl; // Output: Bolo básico com cobertura de chocolate com frutas

    return 0;
}
