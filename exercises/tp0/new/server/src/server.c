#include "server.h"

t_log* g_logger;

int main(void) {
	g_logger = log_create("server.log", "Servidor", 1, LOG_LEVEL_DEBUG);

	int server_fd = iniciar_servidor();
	log_info(g_logger, "Servidor listo para recibir al cliente");
	int cliente_fd = esperar_cliente(server_fd);

	forever() {
		int cod_op = recibir_operacion(cliente_fd);
		switch (cod_op) {
		case MENSAJE:
			recibir_mensaje(cliente_fd);
			break;
		case PAQUETE:
			t_list* lista = NULL;
			lista = recibir_paquete(cliente_fd);
			log_info(g_logger, "Me llegaron los siguientes valores:\n");
			list_iterate(lista, (void*) iterator);
			list_clean_and_destroy_elements(lista, element_destroyer);
			break;
		case -1:
			log_error(g_logger, "el cliente se desconecto. Terminando servidor");
			return EXIT_FAILURE;
		default:
			log_warning(g_logger, "Operacion desconocida. No quieras meter la pata");
			break;
		}
	}

	terminar_programa(server_fd, g_logger);

	return EXIT_SUCCESS;
}

void iterator(char* value) {
	log_info(g_logger,"%s\n", value);
}

void terminar_programa(int conexion, t_log* logger)
{
    log_destroy(logger);
    if(conexion) {
        liberar_conexion(conexion);
    }
}

void element_destroyer(void* element) {
	if (element != NULL) {
		free(element);
	}
}