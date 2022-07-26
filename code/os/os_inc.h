/* date = June 20th 2022 6:18 pm */

#ifndef OS_INC_H
#define OS_INC_H

#include "os_files.h"
#include "os_network.h"
#include "os_time.h"

#if OS_LINUX
#include "linux/linux_inc.h"
#else
# error Provide Platform Implementations
#endif

#include "os_semaphore.h"

#endif //OS_INC_H
