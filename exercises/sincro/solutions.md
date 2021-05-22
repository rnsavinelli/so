### Exercise 1

```
variables_compartidas a = b = 1;
```
```
semaphore sa = sb = 1;
```

#### Proceso 1

```
variable_local d = 1;

While (TRUE){
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

```
variable_local e = 2;

While (TRUE){
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

```
    #define RECURSOS 3
    #define INSTANCIAS M

    semaforo s[RECURSOS] = {INSTANCIAS};

    while (TRUE){
        id_recurso = pedir_recurso();
        WAIT(s[id_recurso])
        usar_recurso(id_recurso);
        SIGNAL(s[id_recurso]);
    }
```

### Exercise 2.b


