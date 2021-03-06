### Exercise 1

```c
variables_compartidas a = b = 1;
```
```c
semaphore sa = sb = 1;
```

#### Proceso 1

```c
variable_local d = 1;

while (true){
    WAIT(sa);
    a = a + d;
    SIGNAL(sa);
    d = d * d;
    WAIT(sb);
    b = b – d;
    SIGNAL(sb);
}
```

#### Proceso 2

```c
variable_local e = 2;

while (true){
    WAIT(sb);
    b = b * e;
    SIGNAL(sb);
    e = e ^ e;
    WAIT(sa);
    a++;
    SIGNAL(sa);
}
```

### Exercise 2.a

```c
#define RECURSOS 3
#define INSTANCIAS M

semaphore s[RECURSOS] = {INSTANCIAS};

while (true){
    id_recurso = pedir_recurso();
    WAIT(s[id_recurso])
    usar_recurso(id_recurso);
    SIGNAL(s[id_recurso]);
}
```

### Exercise 2.b

```c
#define RECURSOS M
#define INSTANCIAS 3

semaphore s[RECURSOS] = {INSTANCIAS};

while (TRUE){
    id_recurso = pedir_recurso();
    WAIT(s[id_recurso])
    usar_recurso(id_recurso);
    SIGNAL(s[id_recurso]);
}
```

### Exercise 3

```c
#define IMPRESORAS 3
#define SCANNERS 2
```
```c
int variable_compartida = 0;
```

```c
semaphore s_impresora = IMPRESORAS;
semaphore s_scanners = SCANNERS;
semaphore s_variable_compartida = 1;
```

#### Proceso A

```c
While (true) {
    WAIT(s_impresora);
    usar_impresora();
    SIGNAL(s_impresora);
    WAIT(s_variable_compartida);
    variable_compartida++;
    SIGNAL(s_variable_compartida);
}
```

#### Proceso B

```c
while (true) {
    WAIT(s_variable_compartida);
    variable_compartida++;
    SIGNAL(s_variable_compartida);
    WAIT(s_scanner);
    usar_scanner();
    SIGNAL(s_scanner);
}
```

#### Proceso C

```c
While (true){
    WAIT(s_scanner);
    usar_scanner();
    SIGNAL(s_scanner);
    WAIT(s_impresora);
    usar_impresora();
    SIGNAL(s_impresora);
}
```

### Exercise 4

```c
semaphore sa = 1;
semaphore sb = 0;
```

#### Proceso A

```c
run_a () {
    while(true) {
        WAIT(sa);
        ...
        SIGNAL(sb);
    }
}
```

#### Proceso B

```c
run_b () {
    while(true) {
        WAIT(sb);
        ...
        SIGNAL(sa);
    }
}
```

### Exercise 5

```c
semaphore sa = 1;
semaphore sb = 0;
semaphore sc = 0;
```

#### Proceso A

```c
run_a () {
    while(true) {
        WAIT(sa);
        ...
        SIGNAL(sb);
    }
}
```

#### Proceso B

```c
run_b () {
    while(true) {
        WAIT(sb);
        ...
        SIGNAL(sc);
    }
}
```

#### Proceso C

```c
run_c () {
    while(true) {
        WAIT(sc);
        ...
        SIGNAL(sa);
    }
}
```

### Exercise 6

```c
semaphore sa = 0;
semaphore sb = 1;
semaphore sc = 0;
```

#### Proceso A

```c
run_a () {
    while(true) {
        WAIT(sa);
        ...
        SIGNAL(sc);
        ...
        WAIT(sa);
        ...
        SIGNAL(sb);
    }
}
```

#### Proceso B

```c
run_b () {
    while(true) {
        WAIT(sb);
        ...
        SIGNAL(sa);
    }
}
```

#### Proceso C

```c
run_c () {
    while(true) {
        WAIT(sc);
        ...
        SIGNAL(sa);
    }
}
```

### Exercise 7.a

```c
list_t lista[];
```
```c
semaphore mutex_lista = 1;

semaphore compiladores = N;
semaphore notificaciones = 0;
```

#### Proceso 1

```c
while (true) {
    id_programa = obtener_nuevo_programa();

    wait(compiladores);
    r = compilar_programa(id_programa);
    signal(compiladores);

    wait(mutex_lista);
    depositar_resultado(r, lista);
    signal(mutex_lista);

    signal(notificaciones);
}
```

#### Proceso 2

```c
while (true) {
    wait(notificaciones)

    wait(mutex_lista);
    r2 = retirar_resultado(lista);
    signal(mutex_lista);

    enviar_email(r2);
}
```

### Exercise 7.b

```c
list_t lista[];
```
```c
semaphore mutex_lista = 1;

semaphore compiladores = N;
semaphore notificaciones = 0;
semaphore lista_size = M;
```

#### Proceso 1

```c
while (true) {
    id_programa = obtener_nuevo_programa();

    wait(compiladores);
    r = compilar_programa(id_programa);
    signal(compiladores);

    wait(lista_size);
    wait(mutex_lista);
    depositar_resultado(r, lista);
    signal(mutex_lista);

    signal(notificaciones);
}
```

#### Proceso 2

```c
while (true) {
    wait(notificaciones)

    wait(mutex_lista);
    r2 = retirar_resultado(lista);
    signal(mutex_lista);
    signal(lista_size);

    enviar_email(r2);
}
```

### Exercise 8

```c
// variable compartida
uint32_t pistas_libres = 10;
```
```c
semaphore mutex_pistas = 1;

semaphore solicitud_pista = 0;
semaphore pistas_otorgadas = 0;
semaphore pistas_libres = 10;
semaphore pistas_liberar = 0;
```

#### Proceso 1 (Avión)

```c
while (true) {
    mantenimiento();

    signal(solicitud_pista);

    wait(pistas_otorgadas);
        despegar();
        signal(pistas_librerar);

    volar();

    signal(solicitud_pista);

    wait(pistas_otorgadas);
        aterrizar();
        signal(pistas_liberar);
}
```

#### Proceso 2 (Controlador entrada)

```c
while (true) {
    wait(solicitud_pista);

        wait(pistas_libres);

        otorgarUnaPista();

        wait(mutex_pistas);
        pistasLibres--;
        log(pistasLibres);
        signal(mutex_pistas);

        signal(pistas_otorgadas);

}
```

#### Proceso 3 (Controlador salida)

```c
while (true) {
    wait(pistas_liberar);

        liberarUnaPista();

        wait(mutex_pistas);
        pistasLibres++;
        log(pistasLibres);
        signal(mutex_pistas);

        signal(pistas_libres);
}
```

### Exercise 9

```c
#DEFINE JUGADORES 5
```
```c
// Variable compartida
bool GOL = FALSE;
```
```c
semaphore mutex_gol = 1;

semaphore jugador_posicionado[JUGADORES] = {0};
semaphore habilitado_a_patear[JUGADORES] = {0};

semaphore arquero_posicionado = 0;

semaphore pateo_al_arco = 0;

semaphore tiro_validado = 0;

semaphore reaccion_arquero = 0;
semaphore reaccion_jugador = 0;

semaphore fin_de_jugada = 0;
```

#### Proceso 1 (Árbitro)

```c
pateador_actual = actual();

while (true) {
    wait(jugador_posicionado[pateador_actual]);

        wait(arquero_posicionado);

            dar_orden();
            signal(habilitado_a_patear[pateador_actual]);

    wait(fin_de_jugada);

    wait(mutex_gol);
    validar_tiro();
    signal(mutex_gol);

    signal(tiro_validado);
    signal(tiro_validado);

    wait(reaccion_jugador);
    wait(reaccion_arquero);

    pateador_actual = siguiente();
}
```

#### Proceso 2 (Jugador)

```c
id = get_jugador_id();

while (true) {
    posicionarse();

    signal(jugador_posicionado[id]);

        wait(habilitado_a_patear[id]);

            patear();

            signal(pateo_al_arco);

            wait(tiro_validado);

            wait(mutex_gol);
            if (GOL == TRUE){
                festejar();
            } else {
                lamentarse();
            }
            signal(mutex_gol);

            signal(reaccion_jugador);
}
```

#### Proceso 3 (Arquero)

```c
while (true) {
    posicionarse();

    signal(arquero_posicionado);

    wait(pateo_al_arco);

        atajar();

        signal(fin_de_jugada);

        wait(tiro_validado);

        wait(mutex_gol);
        if (GOL == FALSE){
            festejar();
        } else {
            lamentarse();
        }
        signal(mutex_gol);

        signal(reaccion_arquero);
}
```

### Exercise 10

```c
#DEFINE N_PROCESOS 50
#DEFINE N_PADRES 25
```

```c
semaphore mutex_logs = 1;

semaphore procesos_disponibles = N_PROCESOS - N_PADRES;

semaphore padre_escribio = 0;
```

#### Proceso

```c
int main() {
    while (true) {
        wait(procesos_disponibles);
        wait(procesos_disponibles);

        pid = fork();

        if (pid < 0) {

            wait(mutex_logs);
            log(‘Error’);
            signal(mutex_logs);

            signal(procesos_disponibles);
            signal(procesos_disponibles);

        } else if (pid == 0) { // Hijo

            wait(padre_escribio);

            wait(mutex_logs);
            log(“Y yo soy el hijo”);
            signal(mutex_logs);

            realizarTarea();

            // Finaliza el proceso hijo

            signal(procesos_disponibles);

            exit(0);

        } else { // Padre

            wait(mutex_logs);
            log(pid + “ soy tu padre”);
            signal(mutex_logs);

            signal(padre_escribio);

            wait(pid);

            signal(procesos_disponibles);
        }
    }
}
```