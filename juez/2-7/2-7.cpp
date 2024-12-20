// Nombre del alumno ..... Cynthia Tristán
// Usuario del Juez ...... EDA-GDV73 


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// O(log n) - busqueda binaria
// función que resuelve el problema
int minimo(const vector<int>& sec, int ini, int fin)
{
	const int diff = fin - ini;

	if (diff == 1)
		return sec[ini];

	const int mit = (ini + fin) / 2;

	if (sec[mit] > sec[mit - 1]) // si la mitad es mayor que la anterior, estara a la izq
		return minimo(sec, ini, mit);

	return minimo(sec, mit, fin);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
	// leer los datos de la entrada
	int n;
	cin >> n;
	if (!cin) return false;
	vector<int> sec(n);
	for (int& e : sec) cin >> e;
	cout << minimo(sec, 0, n) << endl;
	return true;
}

int main()
{
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

	while (resuelveCaso());


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	//system("PAUSE");
#endif

	return 0;
}
