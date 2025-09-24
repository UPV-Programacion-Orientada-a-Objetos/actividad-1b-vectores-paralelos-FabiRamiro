#include <iostream>
#include <string>

// Constante global que indicara el tamaño maximo de los arreglos
const int max_Productos = 100;

// Inicializacion de los arreglos paralelos
int cod_Productos[max_Productos];
std::string nom_Productos[max_Productos];
int cant_Stock[max_Productos];
float precio_Unit[max_Productos];

// Contador de cuantos productos se llevan
int cont_Productos = 0;

// Cargar los 5 productos base en venta
void datosIniciales()
{
    // Producto 0
    cod_Productos[0] = 101;
    nom_Productos[0] = "Martillo";
    cant_Stock[0] = 50;
    precio_Unit[0] = 34.50f;

    // Producto 1
    cod_Productos[1] = 102;
    nom_Productos[1] = "Destornillador";
    cant_Stock[1] = 45;
    precio_Unit[1] = 37.65f;

    // Producto 2
    cod_Productos[2] = 103;
    nom_Productos[2] = "Llave Allen";
    cant_Stock[2] = 70;
    precio_Unit[2] = 21.76f;

    // Producto 3
    cod_Productos[3] = 104;
    nom_Productos[3] = "Bolsa de Clavos de 1 1/2";
    cant_Stock[3] = 60;
    precio_Unit[3] = 10.45f;

    // Producto 4
    cod_Productos[4] = 105;
    nom_Productos[4] = "Martillo de Goma";
    cant_Stock[4] = 30;
    precio_Unit[4] = 50.99f;

    cont_Productos = 5;
}

// Prototipos de funciones
void consProducto();
void actInventario();
void genReporte();
void busProductoCaro();

int main()
{
    datosIniciales();

    int op;
    do
    {
        std::cout << "--- SISTEMA DE INVENTARIO DE LA FERRETERIA EL MARTILLO ---\n";
        std::cout << "Seleccione una opción: \n";
        std::cout << "1. Consultar un Producto \n";
        std::cout << "2. Actualizar el Inventario \n";
        std::cout << "3. Generar Reporte Completo \n";
        std::cout << "4. Encontrar el Producto mas Caro \n";
        std::cout << "5. Salir \n";
        std::cout << "Opción Seleccionada: \n";

        std::cin >> op;

        switch (op)
        {
        case 1:
            consProducto();
            break;
        case 2:
            actInventario();
            break;
        case 3:
            genReporte();
            break;
        case 4:
            busProductoCaro();
            break;

        default:
            if (op != 0 || op > 4)
            {
                std::cout << "\nOpcion incorrecta. Intente de nuevo.\n";
            }
            break;
        }
    } while (op != 5);

    std::cout << "Bye bye\n";
    return 0;
}

void consProducto()
{
    int codigoBus;

    std::cout << "Ingrese el código del producto a buscar: ";
    std::cin >> codigoBus;

    // Variable bandera para saber si se ha encontrado el producto
    bool prod_Encontrado = false;

    for (int i = 0; i < cont_Productos; i++)
    {
        if (cod_Productos[i] == codigoBus)
        {
            std::cout << "\n--- Información del Producto ---\n";
            std::cout << "Código: " << cod_Productos[i] << "\n";
            std::cout << "Nombre: " << nom_Productos[i] << "\n";
            std::cout << "Cantidad en stock: " << cant_Stock[i] << "\n";
            std::cout << "Precio unitario: $" << precio_Unit[i] << "\n\n";

            prod_Encontrado = true;
            break;
        }
    }

    if (!prod_Encontrado)
    {
        std::cout << "El código de producto " << codigoBus << " no existe \n\n";
    }
}

void actInventario()
{
}

void genReporte()
{
}

void busProductoCaro()
{
}