#include "Zombie.hpp"

int main() {
    int N = 4;
    Zombie *Horde = zombieHorde(N, "Carl");
    for (int i = 0; i < N; i++)
        Horde[i].announce();
    delete [] Horde;
    return (0);
}
