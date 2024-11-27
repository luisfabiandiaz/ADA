#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Función para resolver el problema de la mochila
pair<int, vector<int>> knapsack(int n, int P, vector<int> weights, vector<int> benefits) {
    // Crear una tabla de DP de tamaño (n+1) x (P+1)
    vector<vector<int>> dp(n + 1, vector<int>(P + 1, 0));

    // Llenar la tabla de DP
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= P; ++j) {
            if (weights[i - 1] <= j) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weights[i - 1]] + benefits[i - 1]);
            }
            else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    // Reconstruir la solución
    vector<int> selected(n, 0);
    int j = P;
    for (int i = n; i >= 1; --i) {
        if (dp[i][j] != dp[i - 1][j]) {
            selected[i - 1] = 1; // Se selecciona el objeto i-1
            j -= weights[i - 1]; // Reducir la capacidad restante
        }
    }

    return { dp[n][P], selected };
}

int main() {
    int n, P;

    // Leer la entrada
    cout << "Ingrese el número de objetos: ";
    cin >> n;
    cout << "Ingrese la capacidad máxima de la mochila: ";
    cin >> P;

    vector<int> weights(n), benefits(n);
    cout << "Ingrese los pesos de los objetos:\n";
    for (int i = 0; i < n; ++i) {
        cin >> weights[i];
    }

    cout << "Ingrese los beneficios de los objetos:\n";
    for (int i = 0; i < n; ++i) {
        cin >> benefits[i];
    }

    // Resolver el problema de la mochila
    pair<int, vector<int>> result = knapsack(n, P, weights, benefits);
    int maxBenefit = result.first;        // Extraer el beneficio máximo
    vector<int> selected = result.second; // Extraer los objetos seleccionados


    // Imprimir el resultado
    cout << "Beneficio máximo: " << maxBenefit << "\n";
    cout << "Objetos seleccionados:\n";
    for (int i = 0; i < n; ++i) {
        if (selected[i] == 1) {
            cout << "Objeto " << i + 1 << " (peso: " << weights[i] << ", beneficio: " << benefits[i] << ")\n";
        }
    }

    return 0;
}
