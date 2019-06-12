#include <glib.h>

int main()
{
    const gchar * s = "hello, world.";
    gchar * base64 = g_base64_encode(reinterpret_cast<const guchar *>(s), strlen(s));
    g_message("%s", base64);
    gsize len = 0;
    g_base64_decode_inplace(base64, &len);
    base64[len] = 0;
    g_message("%s", base64);
    g_free(base64);
    base64 = NULL;

    return 0;
}
