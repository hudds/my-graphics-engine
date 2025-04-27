#include "logger.h"
#include "asserts.h"
#include "platform/platform.h"

// TODO: temporary
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

void report_assertion_failure(const char* expression, const char* message, const char* file, i32 line){
    log_output(LOG_LEVEL_FATAL, "Assertion Failure: %s, message: '%s', in file: %s, line: %d\n", expression, message, file, line);
}

b8 initialize_log()
{
    // TODO: create log file
    return TRUE;
}

void shutdown_logging()
{
    // TODO: cleanup logging/write queued entries
}

void log_output(log_level level, const char *message, ...)
{
    char *level_strings[6] = {
        "[FATAL]: ",
        "[ERROR]: ",
        "[WARN]: ",
        "[INFO]: ",
        "[DEBUG]: ",
        "[TRACE]: "
    };

    b8 is_error = level < LOG_LEVEL_WARN;
    const i32 message_length = 32000;
    char out_message[message_length];
    memset(out_message, 0, sizeof(out_message));
    __builtin_va_list arg_ptr;
    va_start(arg_ptr, message);
    vsnprintf(out_message, 32000, message, arg_ptr);
    va_end(arg_ptr);

    char appended_out_message[32000];
    sprintf(appended_out_message, "%s%s\n", level_strings[level], out_message);
    
    if (is_error) {
        platform_console_write_error(appended_out_message, level);
    } else {
        platform_console_write(appended_out_message, level);
    }
}