#ifndef DEBUG_H
#define DEBUG_H

#include <stdio.h>
#include <stdarg.h>

const int DEBUGGING = 1;

inline int __cdecl debug(const char *name, const char *_format, ...)
{
    int done = 0;

    if (DEBUGGING)
    {
        va_list arg;

        printf("\033[0;35m(%s): ", name); //makes text color purple

        va_start(arg, _format);
        done= vfprintf(stdout, _format, arg);
        va_end(arg);

        printf("\033[0m\n"); //resets the text color
    }

    return done;
}

inline int __cdecl fdebug(FILE *out, const char *name, const char *_format, ...)
{
    int done = 0;

    if (DEBUGGING)
    {
        if (out == NULL)
            out = stdout;
        
        va_list arg;

        printf("\033[0;35m(%s): ", name);

        va_start(arg, _format);
        done = vfprintf(out, _format, arg);
        va_end(arg);

        printf("\033[0m\n");
    }

    return done;
}

inline int __cdecl cprintf(const char *_format, ...)
{
    //TODO: Implement
    return 0;
}

#endif