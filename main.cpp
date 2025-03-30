/* 
Christopher Rivera Madera
801-24-8062
Asignación 6: Figuras en 3D
*/
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

const double Pi = 3.14;  // Definición de Pi

// Prototipos de las funciones
double volumen(double radio, double altura);
double volumen(double radio);
double volumen(double altura, double ancho, double largo);

double areasuperficie(double radio, double altura);
double areasuperficie(double radio);
double areasuperficie(double largo, double ancho, double altura);


double valida_valor();

int main (){ 

    int figura;

    //Desplega el propósito del programa
    cout << "Este programa calcula el volumen y el área de la superficie de tres figuras." << endl; 
    
    //Se desplega la opciones de las figuras a escoger
    cout << "Escoge una figura:" << endl;
    cout << "  1. Cilindro" << endl;
    cout << "  2. Esfera" << endl;
    cout << "  3. Prisma rectangular" << endl;
    cout << "Selecciona una figura (1/3): ";//Selecciona una figura
    

    // Validación de entrada de figura
    while (true) {
        cin >> figura;  
        if (figura < 1 || figura > 3) {
            cout << "Selección inválida. Por favor elige entre 1, 2 y 3: ";
        } 
        else {
            break;
        }
    }

    char seleccionOperacion;
    
    ///Se desplega la opción de escoger que desea calcular de la figura
    cout << "Escoge una opción para calcular: " << endl;
    cout << " a. Volumen" << endl;
    cout << " b. Área de la superficie" << endl;
    cout << "Seleccione una de ellas: "; //Selecciona la opción

    

    //Se valida la opción escogida
    while (true) {
        cin >> seleccionOperacion;
        if (seleccionOperacion != 'a' && seleccionOperacion != 'b') {
            cout << "Selección inválida. Por favor elige 'a' para volumen o 'b' para área de superficie: ";
        } 
        else {
            break;
        }
    }


    double radio, altura, largo, ancho; //Definición de variables double

    switch (figura) {
        case 1: // De elegir Cilindro
            cout << "Introduce el radio del cilindro: ";
            radio = valida_valor();

            cout << "Introduce la altura del cilindro: ";
            altura = valida_valor();

            if (seleccionOperacion == 'a') {
                double v_result = volumen(radio, altura);
                cout << "El volumen del cilindro es: " << setprecision(2) << fixed << v_result << endl;
            } else if (seleccionOperacion == 'b') {
                double a_result = areasuperficie(radio, altura);
                cout << "El área de superficie del cilindro es: " << setprecision(2) << fixed << a_result << endl;
            }
            break;

        case 2: // De elegir Esfera
            cout << "Introduce el radio de la esfera: ";
            radio = valida_valor();

            if (seleccionOperacion == 'a') {
                double v_result = volumen(radio);
                cout << "El volumen de la esfera es: " << setprecision(2) << fixed << v_result << endl;
            } else if (seleccionOperacion == 'b') {
                double a_result = areasuperficie(radio);
                cout << "El área de superficie de la esfera es: " << setprecision(2) << fixed << a_result << endl;
            }
            break;

        case 3: // De elegir Prisma rectangular
            cout << "Introduce la altura del prisma rectangular: ";
            altura = valida_valor();

            cout << "Introduce el ancho del prisma rectangular: ";
            ancho = valida_valor();

            cout << "Introduce el largo del prisma rectangular: ";
            largo = valida_valor();

            if (seleccionOperacion == 'a') {
                double v_result = volumen(largo, ancho, altura);
                cout << "El volumen del prisma rectangular es: " << setprecision(2) << fixed << v_result << endl;
            } else if (seleccionOperacion == 'b') {
                double a_result = areasuperficie(largo, ancho, altura);
                cout << "El área de superficie del prisma rectangular es: " << setprecision(2) << fixed << a_result << endl;
            }
            break;
    }

    return 0;
}



// Funciones de volumen
double volumen(double radio, double altura) {
    return Pi * pow(radio, 2) * altura; // Volumen de un cilindro
}

double volumen(double radio) {
    return (4.0 / 3.0) * Pi * pow(radio, 3); // Volumen de una esfera
}

double volumen(double largo, double ancho, double altura) {
    return largo * ancho * altura; // Volumen de un prisma rectangular
}



// Funciones de área de la superficie
double areasuperficie(double radio, double altura) {
    return 2 * Pi * radio * (radio + altura); // Área de superficie de un cilindro
}

double areasuperficie(double radio) {
    return 4 * Pi * pow(radio, 2); // Área de superficie de una esfera
}

double areasuperficie(double largo, double ancho, double altura) {
    return 2 * (largo * ancho + largo * altura + ancho * altura); // Área de superficie de un prisma rectangular
}




double valida_valor() {// Función para validar el valor ingresado
    double valor;
    while (true) {
        cin >> valor;
        if (valor > 0) {
            return valor; // Se devuelve el valor de ser positivo
        } else {
            cout << "Por favor ingresa un valor positivo: ";
        }
    }
}