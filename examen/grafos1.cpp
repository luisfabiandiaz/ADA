#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Función para calcular la suma de las diferencias absolutas
int calculateDifference(const vector<int>& heights, const vector<int>& assignment, const vector<int>& lengths) {
    int sum = 0;
    for (size_t i = 0; i < heights.size(); ++i) {
        sum += abs(heights[i] - lengths[assignment[i]]);
    }
    return sum;
}

// Backtracking para encontrar la asignación óptima
void backtrack(int level, const vector<int>& heights, const vector<int>& lengths, vector<int>& assignment, vector<bool>& used, int& minSum, vector<int>& bestAssignment) {
    if (level == heights.size()) {
        // Evaluar la asignación actual
        int currentSum = calculateDifference(heights, assignment, lengths);
        if (currentSum < minSum) {
            minSum = currentSum;
            bestAssignment = assignment;
        }
        return;
    }

    for (size_t i = 0; i < lengths.size(); ++i) {
        if (!used[i]) {
            // Intentar asignar el esquí `i` al alumno `level`
            used[i] = true;
            assignment[level] = i;

            // Avanzar al siguiente nivel
            backtrack(level + 1, heights, lengths, assignment, used, minSum, bestAssignment);

            // Retroceder
            used[i] = false;
        }
    }
}

int main() {
    // Datos de entrada
    vector<int> heights = { 178, 168, 190, 170 };
    vector<int> lengths = { 183, 188, 168, 175 };

    // Ordenar las alturas y longitudes para mejorar la eficiencia
    sort(heights.begin(), heights.end());
    sort(lengths.begin(), lengths.end());

    // Variables para Backtracking
    vector<int> assignment(heights.size()); // Asignación actual
    vector<bool> used(lengths.size(), false); // Esquís ya asignados
    int minSum = INT_MAX; // Suma mínima encontrada
    vector<int> bestAssignment; // Mejor asignación encontrada

    // Llamar al Backtracking
    backtrack(0, heights, lengths, assignment, used, minSum, bestAssignment);

    // Mostrar el resultado
    cout << "Suma mínima de diferencias: " << minSum << endl;
    cout << "Asignación óptima:\n";
    for (size_t i = 0; i < heights.size(); ++i) {
        cout << "Alumno con altura " << heights[i] << " recibe esquí de longitud " << lengths[bestAssignment[i]] << endl;
    }

    return 0;
}
