#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    // Nombre del archivo a leer
    string archivo = "datos.txt";

    // Inicializar variables
    int cantidad_datos = 0;
    int sumatoria = 0;
    int dato;

    // Leer el archivo
    ifstream file(archivo);
    if (file.is_open()) {
        while (file >> dato) {
            // Incrementar la cantidad de datos leídos
            cantidad_datos++;
            // Sumar el valor al total
            sumatoria += dato;
        }

        // Cerrar el archivo
        file.close();

        // Calcular el promedio
        double promedio = static_cast<double>(sumatoria) / cantidad_datos;

        // Imprimir los resultados
        cout << "Cantidad de datos leídos: " << cantidad_datos << endl;
        cout << "Sumatoria: " << sumatoria << endl;
        cout << "Promedio: " << promedio << endl;
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }

    return 0;
}
