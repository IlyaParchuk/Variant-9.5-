#include <iostream>
#include <string>
using namespace std;

    // базовый абстрактный класс
    class Document {
    public:
        // чистый виртуальный метод
        virtual void printInfo() const = 0;

        // виртуальные методы, которые могут быть переопределены в производных классах
        virtual void sign() const {
            cout << "Документ подписан." << endl;
        }

        virtual void stamp() const {
            cout << "Документ проштампован." << endl;
        }
    };

// производный класс "Квитанция"
class Receipt : public Document {
private:
    int amount;

public:
    Receipt(int amount) : amount(amount) {}

    void printInfo() const override {
        cout << "Это квитанция на сумму " << amount << " рублей." << endl;
    }

    void sign() const override {
        cout << "Квитанция подписана получателем." << endl;
    }
};

// производный класс "Накладная"
class Invoice : public Document {
private:
    string sender;
    string receiver;

public:
    Invoice(string sender, string receiver) : sender(sender), receiver(receiver) {}

    void printInfo() const override {
        cout << "Это счет-фактура от " << sender << " к " << receiver << "." << endl;
    }

    void stamp() const override {
        cout << "Счет-фактура проштампован отправителем." << endl;
    }
};

// производный класс "Счет"
class Bill : public Document {
private:
    string recipient;
    int amount;

public:
    Bill(string recipient, int amount) : recipient(recipient), amount(amount) {}

    void printInfo() const override {
        cout << "Это счет на сумму " << amount << " рублей, подлежащих выплате " << recipient << "." << endl;
    }

    void sign() const override {
        cout << "Законопроект подписан эмитентом." << endl;
    }

    void stamp() const override {
        cout << "Вексель проштампован эмитентом." << endl;
    }
};

// производный класс "Документ"
class GenericDocument : public Document {
public:
    void printInfo() const override {
        cout << "Это универсальный документ." << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    // массив объектов базового класса
    const int SIZE = 4;
    Document* documents[SIZE];

    // занести в этот массив объекты дочерних классов
    documents[0] = new Receipt(100);
    documents[1] = new Invoice("Компания A", "Компания B");
    documents[2] = new Bill("Компания C", 500);
    documents[3] = new GenericDocument();

    // продемонстрировать работу методов класса у всех элементов этого массива
    for (int i = 0; i < SIZE; i++) {
        documents[i]->printInfo();
        documents[i]->sign();
        documents[i]->stamp();
        cout << endl;
    }

    return 0;
}


//В данном примере мы создали базовый абстрактный класс Document и четыре его производных класса : Receipt, Invoice, Bill, GenericDocument.В базовом классе объявлены два виртуальных метода, которые могут быть переопределены в производных классах.Также объявлен чистый виртуальный метод printInfo(), который обязательно должен быть реализован в производных классах.

//В функции main() мы создаем массив объектов базового класса, заносим в этот массив объекты дочерних классов и демонстрируем работу методов классов у всех элементов массива.
