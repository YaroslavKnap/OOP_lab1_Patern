#include <iostream>
#include <string>

// ���� ��� ��������� ��������� ���������������� �����
class TechnicalCharacteristics 
{
public:
    TechnicalCharacteristics(int floors, double area, const std::string& communications)
        : floors_(floors), area_(area), communications_(communications) {}

    void printTechnicalInfo() const 
    {
        std::cout << "������ �������������� �����:\n";
        std::cout << "ʳ������ ��������: " << floors_ << "\n";
        std::cout << "�����: " << area_ << " ��.�\n";
        std::cout << "����������: " << communications_ << "\n";
    }

private:
    int floors_; // ʳ������ ��������
    double area_; // ����� �����
    std::string communications_; // ���������� (���, ����, ���������)
};

// ���� ��� ��������� ����������� ��� �������� �����
class OwnerInfo 
{
public:
    OwnerInfo(const std::string& companyName, const std::string& address)
        : companyName_(companyName), address_(address) {}

    void printOwnerInfo() const {
        std::cout << "���������� ��� ��������:\n";
        std::cout << "����� ����������: " << companyName_ << "\n";
        std::cout << "������: " << address_ << "\n";
    }

private:
    std::string companyName_; // ����� ����������
    std::string address_; // ������ ����������
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
    TechnicalCharacteristics tech_; // ������� ��� �������� �������������
    OwnerInfo owner_; // ������� ��� ���������� ��� -- �������� �����
};

int main() {
    setlocale(LC_ALL, "ukr");
    // ��������� ��'���� �������� ������������� �� ���������� ��� ��������
    TechnicalCharacteristics tech(5, 1500.5, "���, ����, ���������");
    OwnerInfo owner("��� '����������'", "�. ���, ���. ��������, 1");

    // ��������� ��'���� ����� � ������������ ��'������
    Building building(tech, owner);

    // ��������� ���������� ��� ������
    building.printBuildingInfo();

    return 0;
}
