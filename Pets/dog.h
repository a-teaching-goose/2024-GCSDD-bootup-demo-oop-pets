#include "pet.h"

#include <iostream>
#include <utility>

class Dog : public Pet {
private:
    std::string owner;

    Pet **friends = nullptr;

    int num_of_friends = 0;

public:
    Dog(const std::string &name, int age, const std::string &owner) : Pet(name, age) {
        this->owner = owner;
    };

    Dog(const std::string &name, int age, const std::string &owner, Pet **friends, int num_of_friends);

    void play(const std::string &) override;

    Pet **getFriends() const;

    int getNumOfFriends() const;

    const std::string as_string() override;

    virtual ~Dog() {
        delete friends;
    }

    void make_friends(Pet *const *friends_to_make, int num_of_friends_to_make);
};