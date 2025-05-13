# ProyectoLenguajes

## Descripción
Este proyecto es una aplicación de escritorio en C que calcula el **Mínimo Común Múltiplo (MCM)** de dos números enteros positivos. Utiliza la API de Windows para crear una interfaz gráfica de usuario (GUI).

## Características
- Interfaz gráfica para ingresar dos números enteros.
- Cálculo del **Máximo Común Divisor (MCD)** como paso intermedio.
- Cálculo del **Mínimo Común Múltiplo (MCM)**.
- Mensajes de error si los números ingresados no son válidos.

## Requisitos
- Sistema operativo: Windows.
- Compilador compatible con C (por ejemplo, GCC con MinGW).
- Biblioteca `gdi32` para la GUI.

## Cómo Compilar
1. Asegúrate de tener instalado un compilador como MinGW.
2. Abre una terminal y navega al directorio del proyecto:
   ```bash
   cd "c:\Users\...\ProyectoLenguajes"
3. Compila el programa con el siguiente comando:
    gcc gui.c -o gui.exe -lgdi32

## Cómo Ejecutar
1. Después de compilar, ejecuta el programa con:
    gui.exe
2. Ingresa dos números enteros positivos en los campos de texto.
3. Haz clic en el botón Calcular MCM para ver el resultado.

## Estructura del Proyecto
- gui.c: Código fuente principal que implementa la lógica del cálculo y la GUI.

## Ejemplo de Uso
1. Ingresa 12 y 18 como números.
2. Haz clic en Calcular MCM.
3. El resultado mostrado será: MCM: 36.