#include <iostream>
using namespace std;

class Gauss {
    float a[50][50];
    int n;

public:
    void accept() {
        cout << "\nINGRESA NUMERO DE VARIABLES: ";
        cin >> n;
        cout << "\n\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n + 1; j++) {
                if (j == n)
                    cout << "CONSTANTE No." << i + 1 << " = ";
                else
                    cout << "a[" << i + 1 << "][" << j + 1 << "] = ";
                cin >> a[i][j];
            }
            cout << "\n";
        }
    }

    void display() {
        for (int i = 0; i < n; i++) {
            cout << "\n";
            for (int j = 0; j < n + 1; j++) {
                if (j == n)
                    cout << " ";
                cout << a[i][j] << "\t";
            }
        }
        cout << "\n";
    }

    void gauss() {
        float temp;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                temp = a[j][i] / a[i][i];
                for (int k = i; k < n + 1; k++) {
                    a[j][k] -= temp * a[i][k];
                }
            }
        }
    }

    void EnterJordan() {
        float temp;
        for (int i = n - 1; i >= 0; i--) { // Corrección en la iteración
            temp = a[i][i];
            for (int j = n; j >= 0; j--) {
                a[i][j] /= temp;
            }
            for (int j = i - 1; j >= 0; j--) {
                temp = a[j][i];
                for (int k = n; k >= 0; k--) {
                    a[j][k] -= temp * a[i][k];
                }
            }
        }
    }

    void credits() {
        for (int i = 0; i < n; i++) {
            cout << "x" << i + 1 << " = " << a[i][n] << endl;
        }
    }
};

int main() {
    cout << "\n\t\tRESOLUCION DE ECUACIONES POR GAUSS-JORDAN\n\n\n";
	cout << "\n\t\tTE AMO RORRO\n\n"
    Gauss obj;
    obj.accept();
    cout << "\n\n\n\nMATRIZ INICIAL: \n\n\n";
    obj.display();
    obj.gauss();
    cout << "\n\n\n\nDESPUES DE ELIMINACION GAUSSIANA: \n\n\n";
    obj.display();
    obj.EnterJordan();
    cout << "\n\n\n\nMATRIZ IDENTIDAD: \n\n\n";
    obj.display();
    cout << "\n\n\n\nSOLUCION: \n\n\n";
    obj.credits();
    return 0;
}
