#include <glib.h>

int main()
{
    g_debug("This is a debug message");
    g_info("This is an info message");
    g_message("This is a normal message");
    g_warning("This is a warning message");
    g_critical("This is a critical message");
    g_error("This is an error message");

    return 0;
}
