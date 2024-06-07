#include <iostream>
#include <fstream>
#include "bintree_eda.h"
using namespace std;

void explora(const bintree<int>& tree, int& caudal, int& navegables) 
{ // complejidad: lineal porque pasa por cada nodo una única vez
	if (tree.empty()) // árbol vacío
	{
		caudal = 0;
		navegables = 0;
	}
	else if (tree.left().empty() && tree.right().empty()) { // árbol raiz
		caudal = 1;
		navegables = 0;
	}
	else if (tree.left().empty()) { // rama derecha
		int caudalR, navegablesR;
		explora(tree.right(), caudalR, navegablesR);
		caudal = max(caudalR - tree.root(), 0);
		navegables = navegablesR;
		if (caudal >= 3)
			navegables++;
	}
	else if (tree.right().empty()) { // rama izquierda
		int caudalL, navegablesL;
		explora(tree.left(), caudalL, navegablesL);
		caudal = max(caudalL - tree.root(), 0);
		navegables = navegablesL;
		if (caudal >= 3)
			navegables++;
	}
	else {
		int caudalL, caudalR, navegablesL, navegablesR;
		explora(tree.left(), caudalL, navegablesL);
		explora(tree.right(), caudalR, navegablesR);
		caudal = max(caudalL + caudalR - tree.root(), 0);
		navegables = navegablesL + navegablesR;
		if (caudal >= 3)
			navegables++;
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso(){
	const bintree<int> arb = leerArbol(-1); // -1 es la repr. de arbol vacio
	int caudalR, caudalL, navegablesR, navegablesL;
	explora(arb.left(), caudalL, navegablesL);
	explora(arb.right(), caudalR, navegablesR);
	cout << navegablesL + navegablesR << '\n';
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif

    return 0;
}

