/*
 * Cliente.h
 *
 *  Created on: 28 feb. 2019
 *      Author: utnso
 */

#ifndef TP0_H_
#define TP0_H_

#include<stdio.h>
#include<stdlib.h>
#include<commons/log.h>
#include<commons/string.h>
#include<commons/config.h>
#include<readline/readline.h>

#include "utils.h"

#define CFG_FILE "tp0.config"
#define LOG_FILE "tp0.log"

t_log* iniciar_logger(void);
t_config* leer_config(void);
void paquete(int, t_log*);
void terminar_programa(int, t_log*, t_config*);

#endif /* TP0_H_ */
