#include "dog.h"

Dog::Dog(const std::string &name, int age, const std::string &owner,
         Pet **friends, int num_of_friends) : Dog(name, age, owner) {
    if (num_of_friends <= 0) {
        return;
    }

    make_friends(friends, num_of_friends);
}

void Dog::make_friends(Pet *const *friends_to_make, int num_of_friends_to_make) {
    num_of_friends = num_of_friends_to_make + 1;
    this->friends = new Pet *[num_of_friends];
    if (friends_to_make != nullptr) {
        for (int i = 0; i < num_of_friends_to_make; ++i) {
            Dog::friends[i] = friends_to_make[i];
        }
    }
    friends[num_of_friends] = this;
}

const std::string Dog::as_string() {
    return "dog{name:" + name + ", age:" + std::to_string(age) + "}";
}

void Dog::play(const std::string &toy) {
    if (!toy.empty()) {
        PRINT(as_string() + ": " + toy);
        return;
    }
    PRINT(as_string() + " is playing with a stick found somewhere)");
}

Pet **Dog::getFriends() const {
    return friends;
}

int Dog::getNumOfFriends() const {
    return num_of_friends;
}
