#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <commons/log.h>

#include "utils.h"

#define forever() while(1)

void terminar_programa(int conexion, t_log* logger);

void iterator(char* value);

void element_destroyer(void* element);