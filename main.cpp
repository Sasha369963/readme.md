#include <iostream>
#include <string>

using namespace std;

class Animal {
private:
    string name;
    string sound;
    int age; 

public:
    Animal() : name("Unknown"), sound("Unknown"), age(0) {}
    Animal(string _name, string _sound, int _age) : name(_name), sound(_sound), age(_age) {}
    Animal(const Animal& other) : name(other.name), sound(other.sound), age(other.age) {}

    ~Animal() {}

    string getName() const { return name; }
    string getSound() const { return sound; }
    int getAge() const { return age; } 
    void setName(string _name) { name = _name; }
    void setSound(string _sound) { sound = _sound; }
    void setAge(int _age) { age = _age; } 

    void printInfo() const {
        cout << "Name: " << name << endl;
        cout << "Sound: " << sound << endl;
        cout << "Age: " << age << endl; 
    }

    Animal& operator=(const Animal& other) {
        if (this != &other) {
            name = other.name;
            sound = other.sound;
            age = other.age;
        }
        return *this;
    }

    bool operator==(const Animal& other) const {
        return (name == other.name && sound == other.sound && age == other.age);
    }

    Animal operator+(int years) const {
        Animal temp(*this);
        temp.age += years;
        return temp;
    }
};

class Cat : public Animal {
public:
    Cat() : Animal("Кіт", "Мяу", 0) {}
    Cat(string _name) : Animal(_name, "Муркає", 0) {}
    Cat(const Cat& other) : Animal(other) {}

    ~Cat() {}

    string getName() const { return Animal::getName(); }
    string getSound() const { return Animal::getSound(); }
    void setName(string _name) { Animal::setName(_name); }

    void printInfo() const {
        cout << "Type: Кіт" << endl;
        Animal::printInfo();
    }
};

int main() {
    Animal animal1("Собака", "Гавкає", 3);
    animal1.printInfo();

    cout << endl;

    Cat cat1("Мурко");
    cat1.printInfo();

    cout << endl;

    Animal animal2;
    animal2 = animal1; 
    cout << "After assignment:" << endl;
    animal2.printInfo();

    cout << endl;

    cout << "Testing comparison operator:" << endl;
    if (animal1 == animal2)
        cout << "The animals are the same." << endl;
    else
        cout << "The animals are different." << endl;

    cout << endl;

    cout << "Testing addition operator:" << endl;
    Animal agedCat = cat1 + 2; 
    agedCat.printInfo();

    return 0;
}