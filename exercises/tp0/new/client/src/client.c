#include "client.h"

int main(void)
{
	/*---------------------------------------------------PARTE 2-------------------------------------------------------------*/
	int conexion;
	char* ip;
	char* puerto;
	char* valor;

	t_log* logger;
	t_config* config;

	logger = iniciar_logger();

	// Usando el logger creado previamente
	// Escribi: "Hola! Soy un log"

	log_debug(logger, "Hola! Soy un log");

	config = iniciar_config();

	// Usando el config creado previamente
	// Lee las variables de IP, Puerto y Valor

	ip = config_get_string_value(config, "IP");
	puerto = config_get_string_value(config, "PUERTO");
	valor = config_get_string_value(config, "CLAVE");

	//Loggear valor de config

	log_debug(logger, "IP: %s", ip);
	log_debug(logger, "PUERTO: %s", puerto);
	log_debug(logger, "CLAVE: %s", valor);

	leer_consola(logger);

	/*---------------------------------------------------PARTE 3-------------------------------------------------------------*/

	// Antes de continuar, tenemos que asegurarnos que el servidor esté corriendo porque lo necesitaremos para lo que sigue.

	// Creamos una conexión hacia el servidor
	conexion = crear_conexion(ip, puerto);

	//enviar CLAVE al servidor
    if(conexion != -1) {
        enviar_mensaje(valor, conexion);
    }

	paquete(conexion);

	terminar_programa(conexion, logger, config);

	/*---------------------------------------------------PARTE 5-------------------------------------------------------------*/
	// Proximamente

	return 0;
}

t_log* iniciar_logger(void)
{
	t_log* nuevo_logger = log_create(LOG_FILE, PROGRAM_NAME, true, LOG_LEVEL_DEBUG);

	return nuevo_logger;
}

t_config* iniciar_config(void)
{
	t_config* nuevo_config = config_create(CONFIGURATION_FILE);

	return nuevo_config;
}

void leer_consola(t_log* logger)
{
	char* leido = NULL;

	//El primero te lo dejo de yapa
	leido = readline(">");

	// Acá la idea es que imprimas por el log lo que recibis de la consola.
	if (leido != NULL) {
		log_info(logger, leido);
		free(leido);
	}

}

void paquete(int conexion)
{
	//Ahora toca lo divertido!

	char* leido = NULL;
	t_paquete* paquete;

	leido = readline(">");

	paquete = crear_paquete();		

    while(leido != NULL) {
        agregar_a_paquete(paquete, (char *) leido, strlen(leido) + 1);
        free(leido);
        leido = readline(">");
    }

	if (leido != NULL) {
		free(leido);
	}

	enviar_paquete(paquete, conexion);
	eliminar_paquete(paquete);
}

void terminar_programa(int conexion, t_log* logger, t_config* config)
{
    config_destroy(config);
    log_destroy(logger);
    if(conexion) {
        liberar_conexion(conexion);
    }
}
