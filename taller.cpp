#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<double> estaturas;
	bool estaturasIngresadas = false;
	int opcion;

	do {
		cout << "\n===== MENU DE ESTATURAS =====\n";
		cout << "1. Leer estaturas de los atletas\n";
		cout << "2. Imprimir el vector de estaturas\n";
		cout << "3. Imprimir el promedio de las estaturas\n";
		cout << "4. Imprimir la mayor estatura\n";
		cout << "5. Determinar si todos tienen la misma estatura\n";
		cout << "6. Imprimir la desviacion estandar\n";
		cout << "7. Salir\n";
		cout << "Seleccione una opcion: ";

		if (!(cin >> opcion)) {
			cout << "Entrada no valida. El programa finaliza.\n";
			return 1;
		}

		if (opcion >= 2 && opcion <= 6 && !estaturasIngresadas) {
			cout << "Primero debe ingresar las estaturas con la opcion 1.\n";
			continue;
		}

		switch (opcion) {
			case 1: {
				int cantidad;
				cout << "Ingrese la cantidad de atletas: ";
				if (!(cin >> cantidad) || cantidad <= 0) {
					cout << "La cantidad debe ser un entero mayor que cero.\n";
					return 1;
				}

				vector<double> nuevasEstaturas(cantidad);
				bool datosValidos = true;
				for (int i = 0; i < cantidad; ++i) {
					cout << "Estatura del atleta " << i + 1 << " en metros: ";
					if (!(cin >> nuevasEstaturas[i]) || nuevasEstaturas[i] <= 0) {
						datosValidos = false;
						break;
					}
				}

				if (!datosValidos) {
					cout << "Las estaturas deben ser numeros mayores que cero. "
						 << "No se guardaron los datos.\n";
					return 1;
				}

				estaturas = nuevasEstaturas;
				estaturasIngresadas = true;
				cout << "Estaturas ingresadas correctamente.\n";
				break;
			}

			case 2:
				cout << "Estaturas (metros): ";
				for (double estatura : estaturas) {
					cout << fixed << setprecision(2) << estatura << " ";
				}
				cout << '\n';
				break;

			case 3: {
				double suma = 0;
				for (double estatura : estaturas) {
					suma += estatura;
				}
				cout << fixed << setprecision(2)
					 << "Promedio: " << suma / estaturas.size() << " metros\n";
				break;
			}

			case 4: {
				double mayor = estaturas[0];
				for (double estatura : estaturas) {
					if (estatura > mayor) {
						mayor = estatura;
					}
				}
				cout << fixed << setprecision(2)
					 << "Mayor estatura: " << mayor << " metros\n";
				break;
			}

			case 5: {
				bool todasIguales = true;
				for (size_t i = 1; i < estaturas.size(); ++i) {
					if (fabs(estaturas[i] - estaturas[0]) > 1e-9) {
						todasIguales = false;
						break;
					}
				}

				if (todasIguales) {
					cout << "Todos los atletas tienen la misma estatura.\n";
				} else {
					cout << "Los atletas no tienen todos la misma estatura.\n";
				}
				break;
			}

			case 6: {
				double suma = 0;
				for (double estatura : estaturas) {
					suma += estatura;
				}
				double promedio = suma / estaturas.size();
				double sumaCuadrados = 0;
				for (double estatura : estaturas) {
					double diferencia = estatura - promedio;
					sumaCuadrados += diferencia * diferencia;
				}
				double desviacion = sqrt(sumaCuadrados / estaturas.size());

				cout << fixed << setprecision(2)
					 << "Desviacion estandar poblacional: " << desviacion
					 << " metros\n";
				break;
			}

			case 7:
				cout << "Programa finalizado.\n";
				break;

			default:
				cout << "Opcion no valida. Seleccione una opcion del 1 al 7.\n";
		}
	} while (opcion != 7);

	return 0;
}
