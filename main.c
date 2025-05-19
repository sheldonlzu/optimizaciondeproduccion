#include "lib.h"

int main()
{
    // variables locales principales
    int numberProduct;
    numberProduct = 5;

    // Estructuras usadas en el programa
    struct Opciones productos[numberProduct];
    struct Empresa materialesProductos[numberProduct];

    // Funciones principales

    get_resources_em(numberProduct, materialesProductos);

    getname_data(numberProduct, productos);

    createID(numberProduct, productos);

    get_cuantity(numberProduct, productos);

    get_materials(numberProduct, productos);

    get_time(numberProduct, productos);

    get_demand(numberProduct, productos);

    menu_data(numberProduct, productos, materialesProductos);

    return 0;
}