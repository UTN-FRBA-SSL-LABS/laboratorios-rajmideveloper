#include <stdio.h>
#include "../src/carrito.h"
#include "minunit/minunit.h"

/*
 * Tests de integracion: verifican que las funciones trabajan bien
 * en combinacion, no de forma aislada.
 */

/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE D — Escribir el test guiado (ver README.md, Parte 8)
 * ═══════════════════════════════════════════════════════════════════════════ */

void test_compra_con_descuento(void) {
    printf("\nCompra con descuento\n");
    Carrito c;
    carrito_init(&c);
    carrito_agregar(&c, (Producto){"Pan", 200, 3});
    carrito_agregar(&c, (Producto){"Leche", 350, 2});
    ASSERT_IGUAL(1300, carrito_total(&c));
    ASSERT_IGUAL(1170, carrito_descuento(carrito_total(&c), 10));
}

/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE E — Disenar un test propio (ver README.md, Parte 9)
 * ═══════════════════════════════════════════════════════════════════════════ */

void test_agregar_hasta_llenar(void){
    printf("\nAgregar hasta llenar\n");
    Carrito c;
    carrito_init(&c);
    for (int i = 0; i < MAX_ITEMS; i++) {
        carrito_agregar(&c, (Producto){"Leche", 350, 1});
    }
    ASSERT_IGUAL(MAX_ITEMS, carrito_contar(&c));
    ASSERT_IGUAL(0, carrito_agregar(&c, (Producto){"Leche", 350, 1}));
}

int main(void) {
    printf("=== Tests de integracion ===");
    /* Descomentar a medida que agregues las funciones: */
    test_compra_con_descuento();
    test_agregar_hasta_llenar();
    RESUMEN();
    return EXIT_CODE();
}
