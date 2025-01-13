#include <iostream>
#include<stdlib.h>
using namespace std;

class Tower {
public:
    // Função para resolver o problema da Torre de Hanói
    void hanoi(int noDisk, char fromTower, char toTower, char auxTower) {
        // Caso base: mover um único disco
        if (noDisk == 1) {
            cout << "Move disk 1 from tower " << fromTower << " to tower " << toTower << endl;
            return;
        }

        // Mover n-1 discos da torre de origem para a torre auxiliar
        hanoi(noDisk - 1, fromTower, auxTower, toTower);

        // Mover o disco restante da torre de origem para a torre de destino
        cout << "Move disk " << noDisk << " from tower " << fromTower << " to tower " << toTower << endl;

        // Mover n-1 discos da torre auxiliar para a torre de destino
        hanoi(noDisk - 1, auxTower, toTower, fromTower);
    }
};

int main() {
    int noDisks;
    Tower towerObj;

    // Entrada do número de discos
    cout << "--- Tower of Hanoi Simulation ---" << endl;
    cout << "Enter the number of disks: ";
    cin >> noDisks;

    // Resolver o problema assumindo as torres X, Y, Z
    towerObj.hanoi(noDisks, 'X', 'Z', 'Y');
	system("pause");
    return 0;
}
