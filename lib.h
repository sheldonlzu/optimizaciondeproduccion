#include <stdio.h>
#include <string.h>

// Estructuras usadas en el programa
struct Materiales
{
    int plastico;
    int metal;
    int madera;
};
struct Empresa
{
    struct Materiales EmpresaMateriales[3];
};

struct Opciones
{
    int NumberProdcut;
    char NameProducts[50];
    int IdProducts;
    int Cuantity;
    struct Materiales materiales1[3];
    int time;
    int demand;
};

// Funcion Recursos iniciales de la empresa
void get_resources_em(int numberProduct, struct Empresa materialesProductos[numberProduct])
{
    printf("------------------RECURSOS DE LA EMPRESA-----------------\n");
    printf("Ingrese la cantidad de Plastico que posee la empresa: ");
    scanf("%d", &materialesProductos[0].EmpresaMateriales[0].plastico);
    printf("Ingrese la cantidad de Metal que posee la empresa: ");
    scanf("%d", &materialesProductos[0].EmpresaMateriales[0].metal);
    printf("Ingrese la cantidad de Cobre que posee la empresa: ");
    scanf("%d", &materialesProductos[0].EmpresaMateriales[0].madera);
}

// Funcion Cambiar recursos de la empresa

void change_resources_em(int numberProduct, struct Empresa materialesProductos[numberProduct])
{
    printf("------------------ CAMBIO RECURSOS DE LA EMPRESA-----------------\n");
    printf("Perfecto, Ingrese nuevamente todos los valores:\n");
    printf("Ingrese la cantidad de Plastico que posee la empresa:");
    scanf("%d", &materialesProductos[0].EmpresaMateriales[0].plastico);
    printf("Ingrese la cantidad de Metal que posee la empresa: ");
    scanf("%d", &materialesProductos[0].EmpresaMateriales[0].metal);
    printf("Ingrese la cantidad de Cobre que posee la empresa: ");
    scanf("%d", &materialesProductos[0].EmpresaMateriales[0].madera);
}

// Funcion para obtener el nombre de productos
void getname_data(int numberProduct, struct Opciones productos[numberProduct])
{
    printf("------------------ NOMBRE DE PRODUCTOS -----------------\n");
    getchar();
    for (size_t i = 0; i < numberProduct; i++)
    {
        printf("Ingrese el nombre de el producto %ld: ", i + 1);
        fgets(productos[i].NameProducts, 50, stdin);
    }
}

// Funcion de creación automatica de ID de productos
void createID(int numberProduct, struct Opciones productos[numberProduct])
{
    printf("------------------ ID DE PRODUCTOS -----------------\n");
    for (size_t i = 0; i < numberProduct; i++)
    {
        productos[i].IdProducts = i;
        printf("El ID del producto %ld es = %ld\n", (i + 1), (i));
    }
}

// Funcion para obtener la cantidad de elementos de cada producto
void get_cuantity(int numberProdcut, struct Opciones productos[numberProdcut])
{
    printf("------------------ CANTIDAD DE PRODUCTOS -----------------\n");
    for (size_t i = 0; i < numberProdcut; i++)
    {
        printf("Ingrese la cantidad del producto con ID %d: ", (productos[i].IdProducts));
        scanf("%d", &productos[i].Cuantity);
    }
}

// Funcion para obtener la cantidad de materiales de cada producto
void get_materials(int numberProdcut, struct Opciones productos[numberProdcut])
{
    printf("------------------ MATERIALES DE PRODUCTOS -----------------\n");
    for (size_t i = 0; i < numberProdcut; i++)
    {
        printf("Ingrese la cantidad de plastico del producto con ID %d: ", (productos[i].IdProducts));
        scanf("%d", &productos[i].materiales1[0].plastico);
        printf("Ingrese la cantidad de metal del producto con ID %d: ", (productos[i].IdProducts));
        scanf("%d", &productos[i].materiales1[0].metal);
        printf("Ingrese la cantidad de cobre del producto con ID %d: ", (productos[i].IdProducts));
        scanf("%d", &productos[i].materiales1[0].madera);
    }
}

// Funcion para obtener el tiempo de fabricación de cada producto
void get_time(int numberProdcut, struct Opciones productos[numberProdcut])
{
    printf("------------------ TIEMPO DE PRODUCTOS -----------------\n");
    for (size_t i = 0; i < numberProdcut; i++)
    {
        printf("Ingrese el tiempo necesario para fabricar (en días) del producto con ID %d: ", (productos[i].IdProducts));
        scanf("%d", &productos[i].time);
    }
}

// Funcion para obtener la demanda de cada producto
void get_demand(int numberProdcut, struct Opciones productos[numberProdcut])
{
    printf("------------------ DEMANDA DE PRODUCTOS -----------------\n");
    for (size_t i = 0; i < numberProdcut; i++)
    {
        printf("Ingrese la demanda del producto con ID %d: ", (productos[i].IdProducts));
        scanf("%d", &productos[i].demand);
    }
}

// Funcion para buscar el ID de un producto y editarlo
void findID(int numberProdcut, struct Opciones productos[numberProdcut])
{

    int ID, temp = 0;
    printf("Ingrese el ID del producto que desea editar: ");
    scanf("%d", &ID);
    getchar();
    for (size_t i = 0; i < numberProdcut; i++)
    {
        // Comprobando si el ID existe
        if (ID == productos[i].IdProducts)
        {

            printf("El ID buscado fue el %d, que tenia como nombre %s\n", ID, productos[i].NameProducts);
            printf("Ingrese el nombre de el producto %ld:", i + 1);
            fgets(productos[i].NameProducts, 50, stdin);
            printf("Ingrese la cantidad del producto con ID %d:", (productos[i].IdProducts));
            scanf("%d", &productos[i].Cuantity);
            printf("Ingrese el tiempo necesario para fabricar el producto con ID %d:", (productos[i].IdProducts));
            scanf("%d", &productos[i].time);
            printf("Ingrese la demanda del producto con ID %d:", (productos[i].IdProducts));
            scanf("%d", &productos[i].demand);
            printf("El producto se ha actualizado con exito\n");
            temp = 1;
            break;
        }
    }
    // Si el ID no existe, se valida
    if (temp == 0)
    {
        printf("El ID no existe\n");
    }
}

// Funcion para eliminar un producto
void deleteProduct(int numberProdcut, struct Opciones productos[numberProdcut])
{
    int ID, temp = 0;
    printf("Ingrese el ID del rpoducto que desea editar:");
    scanf("%d", &ID);
    getchar();
    for (size_t i = 0; i < numberProdcut; i++)
    {
        // Comprobando si el ID existe
        if (ID == productos[i].IdProducts)
        {
            printf("El ID eliminado fue el %d, que tenia como nombre %s\n", ID, productos[i].NameProducts);
            // colocando el ID mayor a 5, hace que el producto no entre en los parametros. Eliminandolo
            productos[i].IdProducts = 6;
            temp = 1;
        }
    }
    // Si el ID no existe, se valida
    if (temp == 0)
    {
        printf("El ID no existe\n");
    }
}
// Funcion para calcular el tiempo total de fabricacion
void calculate_time(int numberProdcut, struct Opciones productos[numberProdcut])
{
    int totalTime = 0;
    for (size_t i = 0; i < numberProdcut; i++)
    {
        totalTime += productos[i].time;
    }
    printf("El tiempo total de fabricacion es: %d\n", totalTime);
}

// Funcion para mostrar el menu de opciones
void menu_data(int numberProdcut, struct Opciones productos[numberProdcut], struct Empresa materialesProductos[numberProdcut])
{
    printf("---------------MENU Opciones ACCIONES-----------------\n");
    printf("1. Edicion del producto\n2. Eliminacion de producto\n3. Edicion de cantidad de recursos de la empresa\n4. Calcular Tiempo de Fabricación  \n5. Salir\n");
    printf("------------------------------------\n");

    int option, salida = 0;

    printf("\nIngrese la accion que va a realizar: ");
    scanf("%d", &option);

    // Validando la opcion
    switch (option)
    {
    case 1:
        findID(numberProdcut, productos);
        break;
    case 2:
        deleteProduct(numberProdcut, productos);
        break;
    case 3:
        change_resources_em(numberProdcut, materialesProductos);
        break;
    case 4:
        calculate_time(numberProdcut, productos);
        break;
    case 5:
        // Salida del programa
        printf("Saliendo del programa...\n");
        salida = 1;
        break;
    default:
        printf("Opcion invalida...\n");
        break;
    }
    // Si la salida es 0, se vuelve a mostrar el menu
    if (salida == 0)
    {
        menu_data(numberProdcut, productos, materialesProductos);
    }
}
