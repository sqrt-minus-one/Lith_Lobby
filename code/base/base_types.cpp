
internal b32
Compare_u64(u64 A, u64 B, comparison Comparison)
{
    b32 Result = 0;
    switch(Comparison)
    {
        default: break;
        case comparison_EqualTo:               Result = (A == B); break;
        case comparison_NotEqualTo:            Result = (A != B); break;
        case comparison_LessThan:              Result = (A <  B); break;
        case comparison_LessThanOrEqualTo:     Result = (A <= B); break;
        case comparison_GreaterThan:           Result = (A >  B); break;
        case comparison_GreaterThanOrEqualTo:  Result = (A >= B); break;
    }
    return Result;
}


internal void
_DebugLog(i32 flags, char *file, int line, char *format, ...)
{
    // NOTE(fakhri): Log to stdout
    {
        char *name = "Info";
        if(flags & Log_Error)
        {
            name = "Error";
        }
        else if(flags & Log_Warning)
        {
            name = "Warning";
        }
        fprintf(stdout, "%s (%s:%i) ", name, file, line);
        va_list args;
        va_start(args, format);
        vfprintf(stdout, format, args);
        va_end(args);
        fprintf(stdout, "%s", "\n");
    }
    
    // NOTE(fakhri): Log to VS output, etc.
    {
        local_persist char string[4096] = {0};
        va_list args;
        va_start(args, format);
        vsnprintf(string, sizeof(string), format, args);
        va_end(args);
#if OS_WINDOWS
        OutputDebugStringA(string);
        OutputDebugStringA("\n");
#endif
    }
    
}
