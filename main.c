#include "lib.h"

int main()
{
    // variables locales principales
    int numberProduct;
    numberProduct = 5;

    // Estructuras usadas en el programa
    struct Productos productos1[numberProduct];

    // Funciones principales

    getname_data(numberProduct, productos1);

    createID(numberProduct, productos1);

    get_cuantity(numberProduct, productos1);

    get_materials(numberProduct, productos1);

    get_time(numberProduct, productos1);

    get_demand(numberProduct, productos1);

    menu_data(numberProduct, productos1);

    return 0;
}
