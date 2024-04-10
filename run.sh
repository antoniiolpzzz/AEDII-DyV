#!/bin/bash

# Ejecucion del make
clear
make
clear

# Eleccion del generador
echo "¿Qué generador de casos desea ejecutar?"
echo
echo "  ·0 - Usar una caso de prueba previamente generado."
echo "  ·1 - Generador de casos (X casos de tamaño de cadena aleatorio entre 10^4 y 10^6)."
echo "  ·2 - Generador incremental (100 casos desde N = 10^4 hasta N = 10^6, incrementos de 10^4 por caso)."
echo

echo -n "Introduzca su elección (0, 1, 2): "

read opcion
echo

# Ejecucion del generador
case $opcion in
    0)
        # PREVIAMENTE GENERADO
        echo "Introduzca el fichero en la carpeta 'CASOS DE PRUEBA'."
        echo "El nombre del fichero debe ser 'casosPrueba.txt'."
        echo "Pulsa enter para continuar..."
        read
        
        if [ ! -f "CASOS DE PRUEBA/casosPrueba.txt" ]; then
            echo "Archivo no encontrado. Deteniendo la ejecución del script."
            exit 1
        fi
        ;;
    1)
        # NORMAL
        ./COMPILADO/GeneradorDeCasos
        echo "Fichero creado."
        ;;
    2)
        # INCREMENTAL
        ./COMPILADO/GeneradorDeCasosIncremental
        echo "Fichero creado."
        ;;
    *)
        # OTRA OPCION
        echo "Opción no válida. Por favor, ingrese 0 o 1. Deteniendo la ejecución del script." >&2
        exit 1
        ;;
esac


# Ejecuta Solucion Directa
echo
echo "Ejecutando 'Solucion Directa'..."
./COMPILADO/SolucionDirecta

# Ejecucion Divide y Venceras
echo "Ejecutando 'Divide y Venceras'..."
./COMPILADO/DivideyVenceras

echo "Todos los casos ejecutados."
