#include <iostream>
#include "pet.h"

class Cat : public Pet {

public:
    Cat(const std::string &name, int age);

    Cat(const Cat &other_cat) : Cat(other_cat.name, other_cat.age) {
    }

    std::vector<Cat> operator*(int num);

    void play(const std::string &) override;

    const std::string as_string() override;
};