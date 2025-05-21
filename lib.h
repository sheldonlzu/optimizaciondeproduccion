#include <stdio.h>
#include <string.h>

// Estructuras usadas en el programa
struct Materiales
{
    char Name_resources;
    float Cuantity_resources;
};

struct Productos
{
    int NumberProdcut;
    char NameProducts[50];
    int IdProducts;
    int Cuantity;
    struct Materiales materiales1[20];
    int time;
    int demand;
};

int validNumber(int number)
{
    if (number < 0)
    {
        printf("El numero no puede ser negativo\n");
        return 0;
    }
    else
    {
        return 1;
    }
}

// Funcion para obtener el nombre de productos
void getname_data(int numberProduct, struct Productos productos1[numberProduct])
{
    printf("----------------Bienvenido a la aplicacion--------------\n");
    printf("------------------ NOMBRE DE PRODUCTOS -----------------\n");
    for (size_t i = 0; i < numberProduct; i++)
    {
        printf("Ingrese el nombre de el producto %ld: ", i + 1);
        fgets(productos1[i].NameProducts, 50, stdin);
    }
}

// Funcion de creación automatica de ID de productos
void createID(int numberProduct, struct Productos productos1[numberProduct])
{
    printf("------------------ ID DE PRODUCTOS -----------------\n");
    for (size_t i = 0; i < numberProduct; i++)
    {
        productos1[i].IdProducts = i + 1;
        printf("El ID del producto %ld es = %d\n", (i + 1), productos1[i].IdProducts);
    }
}

// Funcion para obtener la cantidad de elementos de cada producto
void get_cuantity(int numberProdcut, struct Productos productos1[numberProdcut])
{
    printf("------------------ CANTIDAD DE PRODUCTOS -----------------\n");
    for (size_t i = 0; i < numberProdcut; i++)
    {
        do
        {
            printf("Ingrese la cantidad del producto con ID %d: ", (productos1[i].IdProducts));
            scanf("%d", &productos1[i].Cuantity);
        } while (validNumber(productos1[i].Cuantity) == 0);
    }
}

// Funcion para obtener la cantidad de materiales de cada producto
void get_materials(int numberProdcut, struct Productos productos1[numberProdcut])
{
    int temp;
    printf("------------------ MATERIALES DE PRODUCTOS -----------------\n");
    for (size_t i = 0; i < numberProdcut; i++)
    {
        printf("------ PRODUCTO %ld ------\n", (i + 1));
        do
        {

            printf("Ingrese la cantidad de materiales que componene al producto con el ID %d: ", (productos1[i].IdProducts));
            scanf("%d", &temp);
        } while (validNumber(temp) == 0);

        for (size_t j = 0; j < temp; j++)
        {
            printf("Ingrese el nombre del material %ld que tiene el producto  con el ID %d: ", (j + 1), (productos1[i].IdProducts));
            scanf("%s", &productos1[i].materiales1[j].Name_resources);
            do
            {
                printf("Ingrese la cantidad en Kg del material: ");
                scanf("%f", &productos1[i].materiales1[j].Cuantity_resources);
            } while (validNumber(productos1[i].materiales1[j].Cuantity_resources) == 0);
        }
    }
}
// esta funcion cambia los materiales del ID seleccionao
void change_materials(int numberProdcut, struct Productos productos1[numberProdcut])
{
    int ID, temp = 0;
    printf("------------------ CAMBIO DE MATERIALES DE PRODUCTOS -----------------\n");
    printf("Ingrese el ID del producto que desea editar: ");
    scanf("%d", &ID);
    getchar();
    for (size_t i = 0; i < numberProdcut; i++)
    {
        // Comprobando si el ID existe
        if (ID == productos1[i].IdProducts)
        {
            do
            {

                printf("Ingrese la cantidad de materiales que componene al producto con el ID %d: ", (ID));
                scanf("%d", &temp);
            } while (validNumber(temp) == 0);
            for (size_t j = 0; j < temp; j++)
            {
                printf("Ingrese el nombre del material %ld que tiene el producto  con el ID %d: ", (j + 1), (productos1[i].IdProducts));
                scanf("%s", &productos1[i].materiales1[0].Name_resources);
                do
                {

                    printf("Ingrese la cantidad en Kg del material: ");
                    scanf("%f", &productos1[i].materiales1[0].Cuantity_resources);
                } while (validNumber(productos1[i].materiales1[0].Cuantity_resources) == 0);
            }
        }
        temp = 1;
        break;
    }
    // Si el ID no existe, se valida
    if (temp == 0)
    {
        printf("El ID no existe\n");
    }
}

// Funcion para obtener el tiempo de fabricación de cada producto
void get_time(int numberProdcut, struct Productos productos1[numberProdcut])
{
    printf("------------------ TIEMPO DE PRODUCTOS -----------------\n");
    for (size_t i = 0; i < numberProdcut; i++)
    {
        do
        {

            printf("Ingrese el tiempo necesario para fabricar (en días) del producto con ID %d: ", (productos1[i].IdProducts));
            scanf("%d", &productos1[i].time);
        } while (validNumber(productos1[i].time) == 0);
    }
}

// Funcion para obtener la demanda de cada producto
void get_demand(int numberProdcut, struct Productos productos1[numberProdcut])
{
    printf("------------------ DEMANDA DE PRODUCTOS -----------------\n");
    for (size_t i = 0; i < numberProdcut; i++)
    {
        do
        {

            printf("Ingrese la demanda del producto con ID %d: ", (productos1[i].IdProducts));
            scanf("%d", &productos1[i].demand);
        } while (validNumber(productos1[i].demand) == 0);
    }
}

// Funcion para buscar el ID de un producto y editarlo
void findID(int numberProdcut, struct Productos productos1[numberProdcut])
{

    int ID, temp = 0;
    printf("Ingrese el ID del producto que desea editar: ");
    scanf("%d", &ID);
    getchar();
    for (size_t i = 0; i < numberProdcut; i++)
    {
        // Comprobando si el ID existe
        if (ID == productos1[i].IdProducts)
        {
            printf("------MODIFICANDO PRODUCTO %ld ------\n", (i + 1));
            printf("El ID buscado fue el %d, que tenia como nombre %s\n", ID, productos1[i].NameProducts);
            printf("Ingrese el nombre de el producto %ld:", i + 1);
            fgets(productos1[i].NameProducts, 50, stdin);
            do
            {
                printf("Ingrese la cantidad del producto con ID %d:", (productos1[i].IdProducts));
                scanf("%d", &productos1[i].Cuantity);
            } while (validNumber(productos1[i].Cuantity) == 0);
            do
            {
                printf("Ingrese el tiempo necesario para fabricar el producto con ID %d:", (productos1[i].IdProducts));
                scanf("%d", &productos1[i].time);
            } while (validNumber(productos1[i].time) == 0);

            do
            {

                printf("Ingrese la demanda del producto con ID %d:", (productos1[i].IdProducts));
                scanf("%d", &productos1[i].demand);
            } while (validNumber(productos1[i].demand) == 0);
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
void deleteProduct(int numberProdcut, struct Productos productos1[numberProdcut])
{
    int ID, temp = 0;
    printf("Ingrese el ID del rpoducto que desea editar:");
    scanf("%d", &ID);
    getchar();
    for (size_t i = 0; i < numberProdcut; i++)
    {
        // Comprobando si el ID existe
        if (ID == productos1[i].IdProducts)
        {
            printf("El ID eliminado fue el %d, que tenia como nombre %s\n", ID, productos1[i].NameProducts);
            // colocando el ID mayor a 5, hace que el producto no entre en los parametros. Eliminandolo
            productos1[i].IdProducts = 6;
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
void calculate_time(int numberProdcut, struct Productos productos1[numberProdcut])
{
    int totalTime = 0;
    for (size_t i = 0; i < numberProdcut; i++)
    {
        totalTime += productos1[i].time;
    }
    printf("El tiempo total de fabricacion es: %d días\n", totalTime);
}

void calculate_demand(int numberProdcut, struct Productos productos1[numberProdcut])
{
    int totalDemand = 0;
    for (size_t i = 0; i < numberProdcut; i++)
    {
        totalDemand += productos1[i].demand;
    }
    printf("La demanda total es: %d productos.\n", totalDemand);
}

// Funcion para mostrar el menu de opciones
void menu_data(int numberProdcut, struct Productos productos1[numberProdcut])
{
    printf("---------------MENU Opciones ACCIONES-----------------\n");
    printf("1. Edicion del producto\n2. Eliminacion de producto\n3. Edicion de los materiales de los productos\n4. Calcular Tiempo de Fabricación\n5. Calcular demanda total  \n6. Salir\n");
    printf("------------------------------------\n");

    int option, salida = 0;

    printf("\nIngrese la accion que va a realizar: ");
    scanf("%d", &option);

    // Validando la opcion
    switch (option)
    {
    case 1:
        findID(numberProdcut, productos1);
        break;
    case 2:
        deleteProduct(numberProdcut, productos1);
        break;
    case 3:
        change_materials(numberProdcut, productos1);
        break;
    case 4:
        calculate_time(numberProdcut, productos1);
        break;
    case 5:
        calculate_demand(numberProdcut, productos1);
        break;
    case 6:
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
        menu_data(numberProdcut, productos1);
    }
}
