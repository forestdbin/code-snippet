#include <glib.h>

int main()
{
    g_message("The GLib header is %d.%d.%d",
            GLIB_MAJOR_VERSION,
            GLIB_MINOR_VERSION,
            GLIB_MICRO_VERSION);

    if (GLIB_CHECK_VERSION(2, 48, 2))
        g_message("The GLib header is compatible");
    else
        g_warning("The GLib header is not compatible");

    g_message("The GLib runtime is %d.%d.%d",
            glib_major_version,
            glib_minor_version,
            glib_micro_version);

    const gchar * result = glib_check_version(
            GLIB_MAJOR_VERSION,
            GLIB_MINOR_VERSION,
            GLIB_MICRO_VERSION);
    if (result)
        g_warning("The GLib runtime is not compatible: %s", result);
    else
        g_message("The GLib runtime is compatible");

    return 0;
}
