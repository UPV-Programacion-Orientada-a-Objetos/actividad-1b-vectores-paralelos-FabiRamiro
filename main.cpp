#include <iostream>
#include <string>

// Constante global que indicara el tamaño maximo de los arreglos
const int maximos_Productos = 100;

// Inicializacion de los arreglos paralelos
int codigo_Productos[maximos_Productos];
std::string nombres_Productos[maximos_Productos];
int cantidad_Stock[maximos_Productos];
float precio_Unitario[maximos_Productos];

// Contador de cuantos productos se llevan
int contador_Productos = 0;

// Cargar los 5 productos base en venta
void datosIniciales()
{
    // Producto 0
    codigo_Productos[0] = 101;
    nombres_Productos[0] = "Martillo";
    cantidad_Stock[0] = 50;
    precio_Unitario[0] = 34.50f;

    // Producto 1
    codigo_Productos[1] = 102;
    nombres_Productos[1] = "Destornillador";
    cantidad_Stock[1] = 45;
    precio_Unitario[1] = 37.65f;

    // Producto 2
    codigo_Productos[2] = 103;
    nombres_Productos[2] = "Llave Allen";
    cantidad_Stock[2] = 70;
    precio_Unitario[2] = 21.76f;

    // Producto 3
    codigo_Productos[3] = 104;
    nombres_Productos[3] = "Bolsa de Clavos de 1 1/2";
    cantidad_Stock[3] = 60;
    precio_Unitario[3] = 10.45f;

    // Producto 4
    codigo_Productos[4] = 105;
    nombres_Productos[4] = "Martillo de Goma";
    cantidad_Stock[4] = 30;
    precio_Unitario[4] = 50.99f;

    contador_Productos = 5;
}

// Prototipos de funciones
void consultarProducto();
void actualizarInventario();
void generarReporte();
void buscarProductoMasCaro();

int main()
{
    // Inicializar los datos pŕincipales
    datosIniciales();

    int opcion;
    do
    {
        std::cout << "--- SISTEMA DE INVENTARIO DE LA FERRETERIA EL MARTILLO --- \n";
        std::cout << "Seleccione una opción: \n";
        std::cout << "1. Consultar un Producto \n";
        std::cout << "2. Actualizar el Inventario \n";
        std::cout << "3. Generar Reporte Completo \n";
        std::cout << "4. Encontrar el Producto mas Caro \n";
        std::cout << "5. Salir \n";
        std::cout << "Opción Seleccionada: \n\n";

        std::cin >> opcion;

        switch (opcion)
        {
        case 1:
            consultarProducto();
            break;
        case 2:
            actualizarInventario();
            break;
        case 3:
            generarReporte();
            break;
        case 4:
            buscarProductoMasCaro();
            break;
        case 5:
            std::cout << "Bye bye\n";
            break;

        default:
            std::cout << "\nOpcion incorrecta. Intente de nuevo.\n";
            break;
        }
    } while (opcion != 5);

    return 0;
}

// Funcion para hacer la consulta de un producto
void consultarProducto()
{
    int codigoBuscado;

    std::cout << "Ingrese el código del producto a buscar: ";
    std::cin >> codigoBuscado;

    // Variable bandera para saber si se ha encontrado el producto
    bool producto_Encontrado = false;

    for (int i = 0; i < contador_Productos; i++)
    {
        if (codigo_Productos[i] == codigoBuscado)
        {
            std::cout << "\n ----- Información del Producto ----- \n";
            std::cout << "Código: " << codigo_Productos[i] << "\n";
            std::cout << "Nombre: " << nombres_Productos[i] << "\n";
            std::cout << "Cantidad en stock: " << cantidad_Stock[i] << "\n";
            std::cout << "Precio unitario: $" << precio_Unitario[i] << "\n\n";

            producto_Encontrado = true;
            break;
        }
    }

    if (!producto_Encontrado)
    {
        std::cout << "El código de producto " << codigoBuscado << " no existe \n\n";
    }
}

// Funcion para actualizar el inventario de un producto
void actualizarInventario()
{
    int codigo_Buscado;

    std::cout << "Ingrese el código del producto a buscar: ";
    std::cin >> codigo_Buscado;

    bool producto_Encontrado = false;

    for (int i = 0; i < contador_Productos; i++)
    {
        if (codigo_Productos[i] == codigo_Buscado)
        {
            int cantidad_Actualizar;
            std::cout << "El producto a actualizar es: " << nombres_Productos[i] << " \n";
            std::cout << "¿Cuál es la cantidad a sumar o restar (para restar poner un (-) antes del numero): ";
            std::cin >> cantidad_Actualizar;

            int nuevo_Stock = cantidad_Stock[i] + cantidad_Actualizar;

            if (nuevo_Stock >= 0)
            {
                cantidad_Stock[i] = nuevo_Stock;
                std::cout << "Inventario actualizado, el nuevo stock es: " << cantidad_Stock[i] << " \n\n";
            }
            else
            {
                std::cout << "Hay un error, el stock quedaria en negativo " << nuevo_Stock << " , no se realizó el cambio \n";
            }

            producto_Encontrado = true;
            break;
        }
    }

    if (!producto_Encontrado)
    {
        std::cout << "El código de producto " << codigo_Buscado << " no existe \n\n";
    }
}

// Funcion para generar el reporte de inventario
void generarReporte()
{
    std::cout << "\n ----- Reporte de Inventario ----- \n";
    std::cout << "| Código | " << "Nombre | " << "Stock | " << "Precio |" << " \n";

    for (int i = 0; i < contador_Productos; i++)
    {
        std::cout << "| " << codigo_Productos[i] << " | " << nombres_Productos[i] << " | " << cantidad_Stock[i] << " | $" << precio_Unitario[i] << " | \n\n";
    }
}

void buscarProductoMasCaro()
{
    float precio_MasAlto = precio_Unitario[0];
    int indice_DelMasAlto = 0;

    for (int i = 1; i < contador_Productos; i++)
    {
        if (precio_Unitario[i] > precio_MasAlto)
        {
            precio_MasAlto = precio_Unitario[i];
            indice_DelMasAlto = i;
        }
    }

    std::cout << "\nEl producto más caro es: " << nombres_Productos[indice_DelMasAlto]
              << " y su precio es $" << precio_MasAlto << " \n\n";
}