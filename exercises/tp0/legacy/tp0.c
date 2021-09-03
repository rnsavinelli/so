/*
 * main.c
 *
 *  Created on: 28 feb. 2019
 *      Author: utnso
 */

#include "tp0.h"

#define PROGRAM_NAME "tp0.c"

int main(void)
{
	int conexion;

	t_log* logger;
	t_config* config;

	logger = iniciar_logger();

    log_debug(logger, "Inicializando tp0");

	config = leer_config();

    conexion = crear_conexion(
           config_get_string_value(config, "IP"),
           config_get_string_value(config, "PUERTO")
    );

    if(conexion != -1) {
        enviar_mensaje(config_get_string_value(config, "CLAVE"), conexion);
    }

	paquete(conexion, logger);

	terminar_programa(conexion, logger, config);
}

t_log* iniciar_logger(void)
{
    return log_create(LOG_FILE, PROGRAM_NAME, true, LOG_LEVEL_DEBUG);
}

t_config* leer_config(void)
{
    return config_create(CFG_FILE);
}


void paquete(int conexion, t_log* logger)
{
    char* leido;
    leido = readline(">");

    while(strlen(leido) > 0) {
	    t_paquete* paquete = crear_paquete();
        log_info(logger, leido);
        agregar_a_paquete(paquete, (char *) leido, strlen(leido) + 1);
        enviar_paquete(paquete, conexion);
        eliminar_paquete(paquete);
        free(leido);
        leido = readline(">");
    }

    free(leido);
}

void terminar_programa(int conexion, t_log* logger, t_config* config)
{
    config_destroy(config);
    log_destroy(logger);
    if(conexion) {
        liberar_conexion(conexion);
    }
}
