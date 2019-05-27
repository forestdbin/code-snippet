#include <glib.h>

int main()
{
    g_print("stdout: hello, world.\n");
    g_printerr("stderr: hello, world.\n");
    g_warn_if_fail(FALSE);

    return 0;
}
