#include <stdio.h>
#include <string.h>
//Permite definir el tamano del arreglo "catalogo" sin romperlo
#define productos 10

int main () {
//Declaracion de arreglos
    char catalogo [productos][20], buscarProducto [20], productoCaro [20], productoBarato [20];
    float precio [productos];
//Declaracion de contadores y acumuladores
    int i, totalIngresados = 0;
    float costoTotal = 0, costopromedio = 0;
//Declaracion de variables comparativas
    float precioMax = 0, precioMin;
//Declaracion de variables de control
    int opc, opc2, opc3, opc4;
    //Bucle para iterar menu segun necesite el usuario
    do{
        printf("\n1.Ingresar productos");
        printf("\n2.Precio Total");
        printf("\n3.Producto mas caro y mas barato");
        printf("\n4.Precio Promedio");
        printf("\n5.Buscar precio del producto");
        printf("\n6.Salir");
        printf("\n>>");
        //Funcion de control para ingresar y desplegar solo informacion solicitada
        scanf("%d", &opc2);
        switch (opc2) {
            case 1:
            if (totalIngresados == productos) {
        printf("\nEl inventario esta lleno.\n");
        break;
        }                
        //Bucle para ingreso de catalogo y precios
        for (i = totalIngresados; i < productos; i++) {
            printf("Ingrese nombre del producto: ");
            scanf("%s", &catalogo[i]);
            printf("Ingrese el precio del producto: ");
            scanf("%f", &precio[i]);
            //Bucle para estar dentro de valores reales positivos.
            while(precio[i] <= 0) {
                printf("Error, valor negativo o cero.\n Ingrese precio valido: ");
                scanf("%f", &precio[i]);
            }
            //Acumulador de precios
            costoTotal += precio[i];
            /*Sentencia comparativa para hallar el precio maximo
            y el nombre del producto al que pertenece, ambos usan
            el mismo indice "i"*/
            if (precioMax < precio[i]) {
                precioMax = precio[i];
            /*Sentencia strcpy permite guardar la cadena de
            caracteres a la que pertenece el indice del catalogo*/
                strcpy(productoCaro, catalogo[i]);
            }
            //Sentencia para asignar un valor inicial a precioMin
            if (i == 0) {
                precioMin = precio[i];
                strcpy(productoBarato, catalogo[i]);
            }
            /*Sentencia comparativa para hallar el precio minimo
            y el nombre del producto al que pertenece, ambos usan
            el mismo indice "i"*/
            if (precioMin > precio[i]) {
                precioMin = precio[i];
                strcpy(productoBarato, catalogo[i]);
            }
                totalIngresados = i + 1; // Registra cuántos van guardados con éxito
    
    //Sentencia para informar sobre la llegada a limite de productos posibles
    if (i == productos - 1) {
        printf("\n Se ha llegado al limite maximo de productos posibles (%d).\n", productos);
        break; 
    }

    // Pregunta si quiere seguir en esta iteración
    printf("¿Desea agregar otro producto? (1: Si / 2: No, ir al Menu): ");
    scanf("%d", &opc);

    /*Sentencia comparativa de desicion para iterar o romper
    el bucle antes de llegar al limite*/
    if (opc != 1) {
        break;
    }
    }
        /*Calculo de costo promedio usando el acumulador
        costoTotal y el contador totalIngresados*/
        costopromedio = costoTotal/totalIngresados;
        break;
    
            case 2:
            //Cada caso remite a ingresar productos si no hay productos
                if ( totalIngresados == 0) {
                    printf("\nAun no hay productos registrados. Use la opcion 1 primero.\n");
                    break;
                }
                printf("El precio total del inventario es: %.2f", costoTotal);
                break;

            case 3:
                if ( totalIngresados == 0) {
                    printf("\nAun no hay productos registrados. Use la opcion 1 primero.\n");
                    break;
                }
                printf("El producto mas caro es %s : (%.2f)", productoCaro, precioMax);
                printf("\nEl producto mas barato es %s : (%.2f)", productoBarato, precioMin);
                break;

            case 4:
                if ( totalIngresados == 0) {
                    printf("\nAun no hay productos registrados. Use la opcion 1 primero.\n");
                    break;
                }
                printf("El precio promedio de todos los productos es: %.2f", costopromedio);
                break;
            
            case 5:
                if ( totalIngresados == 0) {
                printf("\nAun no hay productos registrados. Use la opcion 1 primero.\n");
                break;
                }
                /*Funcion bucle do-while para buscar el precio de los productos por su nombre
                cuantas veces el usuario dese*/
                do {
                    printf("\nIngrese nombre del producto: ");
                    scanf("%s", buscarProducto);
                    int encontrado = 0;
                    //Bucle for permite buscar en cada valor del indice
                    for (i = 0; i < totalIngresados; i++) {
                        /*Sentencia comparativa, igualdad cero representa
                        cadena de caracteres identicas, y se rompe bucle
                        mostrando el producto buscado, sino, no muestra nada*/
                        if (strcmp(buscarProducto, catalogo[i]) == 0) {
                            printf("-> El precio de [%s] es: %.2f\n", catalogo[i], precio[i]);
                            encontrado = 1;
                            break;
                        }
                    }
                    //Por el producto esta mal escrito
                    if (!encontrado) {
                        printf("-> Error: El producto no existe o esta mal escrito.\n");
                    }

                    printf("\n¿Desea buscar otro producto? 1.Si 2.No > ");
                    scanf("%d", &opc3);
                } while (opc3 == 1);
                break;
            
            case 6:
                //Finaliza codigo
                return 0;
                break;
            
            default:
                //Por si valor ingresado no corresponde a ningun caso
                printf("Opcion no valida\n");
                break;
        }
    printf("\nDesea regresar al menu? 1.Si 2.No >");
    scanf("%d", &opc4);
    }while(opc4==1);
        return 0;
}