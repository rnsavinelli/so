# Procesos

## Introducción

Un proceso es: un programa en ejecución una instancia de un programa funcionando en una computadora; la entidad que puede ser asignada al procesador y ejecutada por él.

Un proceso es una entidad formada por:

- Una secuencia de instrucciones (código).
- Un conjunto de datos (variables, pila de ejecución).
- Un estado (contexto de ejecución, prioridad, exit status, etc).
- Un conjunto de atributos (process id, user id, etc).
- Recursos asignados (archivos abiertos, etc).



Los procesos son entidades aisladas:
- Por defecto no comparten recursos con otros procesos.
- Para compartir recursos o comunicarse con otros procesos, dependen del SO (herramientas IPC -interprocess communication- provistas por syscalls).

Los procesos son entidades independientes:
- No necesitan de la existencia de otro proceso (sea padre, hijo, etc).

**Programa:** secuencia de instrucciones compiladas a código de máquina. La CPU ejecuta un sólo programa a la vez. Cuando el programa realiza una operación de E/S (ej: leer bytes de un archivo), no usa la CPU.

**Ejecución concurrente:** ejecución de dos o más programas durante un mismo intervalo de tiempo, bajo el cual podrían compartir (o competir por) recursos.

**Multiprogramación:** modo de operación en el cual dos o más programas ejecutan concurrentemente.

**Sistema operativo monoprogramado:** corre un solo proceso a la vez.

**Sistema operativo multiprogramado:** corre más de un proceso "a la vez".

## Estructura del PCB (Process Control Block)

+ **Identificación del proceso:** PID, PPID, UID.
+ **Estado del procesador:**
 - Registros visibles al usuario (AX, BX, etc).
 - Registros de control y estado (PC,IR, FLAGS, etc).
 - Stack pointers.
+ **Control de proceso:**
 - Planificación: estado (READY, RUNNING, etc), prioridad, quantum, evento de espera.
+ **Memoria:** punteros a segmentos de código/datos/heap.
+ **Recursos asignados:** archivos/semáforos abiertos, etc.

## Modos de ejecución

**Modo usuario:**

**Modo kernel:**

## Creación y terminación de un proceso

### Creación de procesos

¿Quién los crea?

El SO u otro proceso.

1. Asignar un único identificador al nuevo proceso.
2. Asignar espacio para el proceso.
3. Iniciar el bloque de control del proceso.
4.

### Terminación de procesos

Quién los finaliza?

El SO, otro proceso , el propio proceso (Normal exit, Abnormal exit). Siempre finaliza a través de una syscall.
