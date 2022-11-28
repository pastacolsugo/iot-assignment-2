
#include "SerialTask.h"
#include <string.h>

const char * SerialTask::generateStateMessage(){
    return strcat("state: ",(const char *[]) {
    "bananas & monkeys",
    "Round and orange", 
    "APPLE",
}[status->getState()]);
}