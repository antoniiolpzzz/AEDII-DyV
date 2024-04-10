# AEDII-DyV (Algoritmos y Estructuras de Datos II - Divide y Vencerás)

## Descripción del Proyecto

Este proyecto está destinado a implementar algoritmos de tipo "Divide y Vencerás" para resolver ciertos problemas específicos. El objetivo principal es analizar el rendimiento y la eficiencia de estos algoritmos en diferentes casos de prueba.

## Estructura del Proyecto

El proyecto sigue la siguiente estructura de carpetas:

- **src**: Contiene el código fuente del proyecto.
- **CASOS DE PRUEBA**: Alberga los casos de prueba a ejecutar.
- **COMPILADO**: Contiene los binarios resultantes de la ejecución del makefile.
- **RESULTADOS**: Guarda los resultados producidos por la salida de los algoritmos.
- **INFORMACION DE TIEMPOS**: Contiene información de los tiempos de ejecución.
- **graphs**: Alberga gráficos tamaño-tiempo y casos de prueba con tiempos de ejecución.

## Instrucciones de Ejecución

Para ejecutar el algoritmo, sigue estos pasos:

1. Ejecutar el script `run.sh` o utilizar el comando `make run`.
2. Esto compilará el proyecto, generará casos de prueba y ejecutará los algoritmos `SolucionDirecta` y `DivideyVenceras`.
3. Los ejecutables tomarán como caso de prueba el archivo `casosPrueba.txt` ubicado en el directorio `CASOS DE PRUEBA`, el cual sera previamente introducido por el usuario en la ruta o sera generado por el script.
4. El script ofrece varias opciones:
- `0`: Utiliza el fichero `casosPrueba.txt` directamente, sin generar uno nuevo.
- `1`: Generador de casos (X casos de tamaño de cadena aleatorio entre y ).
- `2`: Generador incremental (100 casos de , incrementos de por caso).

## Estructura de Casos de Prueba

Los casos de prueba deben seguir la siguiente estructura:

```
NUMERO_DE_CASOS_TOTALES'
CADENA_0'
M_0'
CADENA_1'
M_1'
...
CADENA_i'
M_i
```

## Resultados

Después de la ejecución, encontrarás los siguientes archivos en los directorios correspondientes:

Directorio 'RESULTADOS':
- `resultados.txt` y `resultadosDirecta.txt`: presentan un formato como este:
```
CADENAX_0 [0-99]
Posición de inicio: pX_0
Diferencia máxima: dX_0
...
CADENAX_i [0-99]
Posición de inicio: pX_i
Diferencia máxima: dX_i
```
Directorio 'INFORMACION DE TIEMPOS':
- `infoTiempos.csv` y `infoTiemposDirecta.csv`: presentan un formato como este:
```
TAMAÑO_CADENA, TIEMPO (s), M_(N/1000) X_0
...
TAMAÑO_CADENA, TIEMPO (s), M_(N/1000) X_i
```

--- 

Siéntete libre de agregar cualquier información adicional que consideres relevante.
