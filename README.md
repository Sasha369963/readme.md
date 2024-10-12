# readme.md
python -m venv myenv
pip install numpy
class Animal:
    def __init__(self, name="Unknown", sound="Unknown", age=0):
        self.name = name
        self.sound = sound
        self.age = age

    def get_name(self):
        return self.name

    def get_sound(self):
        return self.sound

    def get_age(self):
        return self.age

    def set_name(self, name):
        self.name = name

    def set_sound(self, sound):
        self.sound = sound

    def set_age(self, age):
        self.age = age

    def print_info(self):
        print(f"Name: {self.name}")
        print(f"Sound: {self.sound}")
        print(f"Age: {self.age}")

    def __eq__(self, other):
        return self.name == other.name and self.sound == other.sound and self.age == other.age

    def __add__(self, years):
        return Animal(self.name, self.sound, self.age + years)

class Cat(Animal):
    def __init__(self, name="Кіт"):
        super().__init__(name, "Муркає", 0)

    def print_info(self):
        print("Type: Кіт")
        super().print_info()

# Testing the classes
if __name__ == "__main__":
    animal1 = Animal("Собака", "Гавкає", 3)
    animal1.print_info()

    print()

    cat1 = Cat("Мурко")
    cat1.print_info()

    print()

    animal2 = Animal()
    animal2 = animal1
    print("After assignment:")
    animal2.print_info()

    print()

    print("Testing comparison operator:")
    if animal1 == animal2:
        print("The animals are the same.")
    else:
        print("The animals are different.")

    print()

    print("Testing addition operator:")
    aged_cat = cat1 + 2
    aged_cat.print_info()
pip freeze > requirements.txt
git init
git add .
git commit -m "Initial commit"
git remote add origin https://github.com/yourusername/yourrepository.git
git push -u origin master
