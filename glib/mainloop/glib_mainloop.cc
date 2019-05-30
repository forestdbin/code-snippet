#include <glib.h>

gboolean timeout_handler(gpointer user_data)
{
    static gint i = 10;
    g_message("%d", i);
    i--;
    if (i == 0)
    {
        GMainLoop * loop = (GMainLoop *)user_data;
        g_main_loop_quit(loop);
        return FALSE;
    }
    else
        return TRUE;
}

int main()
{
    GMainLoop * loop = g_main_loop_new(NULL, FALSE);
    g_timeout_add_seconds(1, timeout_handler, loop);
    g_main_loop_run(loop);
    g_main_loop_unref(loop);

    return 0;
}
