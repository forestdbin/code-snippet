#include <glib.h>

gpointer thread_entry(gpointer)
{
    for (int i = 10; i > 0; i--)
    {
        g_message("%i", i);
        g_usleep(1000 * 1000);
    }
    return NULL;
}

int main()
{
    GThread * thread = g_thread_new(NULL, thread_entry, NULL);
    g_thread_join(thread);

    return 0;
}
