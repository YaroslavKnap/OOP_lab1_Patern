#include <iostream>
#include <string>

// Клас для управління технічними характеристиками будівлі
class TechnicalCharacteristics 
{
public:
    TechnicalCharacteristics(int floors, double area, const std::string& communications)
        : floors_(floors), area_(area), communications_(communications) {}

    void printTechnicalInfo() const 
    {
        std::cout << "Технічні характеристики будівлі:\n";
        std::cout << "Кількість поверхів: " << floors_ << "\n";
        std::cout << "Площа: " << area_ << " кв.м\n";
        std::cout << "Комунікації: " << communications_ << "\n";
    }

private:
    int floors_; // Кількість поверхів
    double area_; // Площа будівлі
    std::string communications_; // Комунікації (газ, вода, електрика)
};

// Клас для управління інформацією про власника будівлі
class OwnerInfo 
{
public:
    OwnerInfo(const std::string& companyName, const std::string& address)
        : companyName_(companyName), address_(address) {}

    void printOwnerInfo() const {
        std::cout << "Інформація про власника:\n";
        std::cout << "Назва підприємства: " << companyName_ << "\n";
        std::cout << "Адреса: " << address_ << "\n";
    }

private:
    std::string companyName_; // Назва підприємства
    std::string address_; // Адреса підприємства
};


class Building 
{
public:
    Building(const TechnicalCharacteristics& tech, const OwnerInfo& owner)
        : tech_(tech), owner_(owner) {}

    void printBuildingInfo() const 
    {
        tech_.printTechnicalInfo();
        owner_.printOwnerInfo();
    }

private:
    TechnicalCharacteristics tech_; // Делегат для технічних характеристик
    OwnerInfo owner_; // Делегат для інформації про -- власника будівлі
};

int main() {
    setlocale(LC_ALL, "ukr");
    // Створення об'єктів технічних характеристик та інформації про власника
    TechnicalCharacteristics tech(5, 1500.5, "Газ, Вода, Електрика");
    OwnerInfo owner("ТОВ 'Будівельник'", "м. Київ, вул. Хрещатик, 1");

    // Створення об'єкта будівлі з делегованими об'єктами
    Building building(tech, owner);

    // Виведення інформації про будівлю
    building.printBuildingInfo();

    return 0;
}
