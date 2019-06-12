#include <glib.h>
#include <glib/gprintf.h>

int main()
{
    g_message("This sample demonstrates the string utility.");

    gchar * string = NULL;
    string = g_strdup("hello, world.");
    g_message("This is a duplication of %s", string);
    g_free(string);
    string = NULL;

    const gchar * string_array[] = {
        "hello, world.",
        "bye, world.",
        NULL
    };
    gchar ** string_array_dup = g_strdupv(const_cast<gchar **>(string_array));
    for (gchar ** s = string_array_dup; *s; s++)
        g_message("This is a duplication of %s", *s);
    g_strfreev(string_array_dup);
    string_array_dup = NULL;

    string = g_strnfill(10, '*');
    g_message("* repeats 10 times: %s", string);
    g_free(string);
    string = NULL;

    gchar dest[20] = "";
    string = g_stpcpy(dest, "hello, ");
    string = g_stpcpy(string, "world.");
    g_message("This is the concatenating of %s", dest);
    string = NULL;

    string = g_strdup_printf("%s", "hello, world.");
    g_message("%s", string);
    g_free(string);
    string = NULL;

    g_printf("hello, world.\n");

    string = g_strdup("hello, world.");
    g_message("%s", g_strreverse(string));
    g_free(string);
    string = NULL;

    return 0;
}
