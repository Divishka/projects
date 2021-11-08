#include "Zombie.hpp"

int main() {
    Zombie *zombu = newZombie("Carl");
    zombu->announce();
    delete zombu;
    randomChump("John");
    return (0);
}
