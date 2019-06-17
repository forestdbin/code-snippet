#include <glib.h>

int main()
{
    const gchar * s = "hello, world.";
    const gchar * key1 = "123456";
    int length1 = strlen(key1);
    const gchar * key2 = "654321";
    int length2 = strlen(key2);
    gchar * hmac = NULL;

    hmac = g_compute_hmac_for_string(
            G_CHECKSUM_MD5, (const guchar *)key1, length1, s, -1);
    g_message("HMAC(MD5) for \"%s\" with key(%s) is:\n%s", s, key1, hmac);
    g_free(hmac);
    hmac = NULL;

    hmac = g_compute_hmac_for_string(
            G_CHECKSUM_MD5, (const guchar *)key2, length2, s, -1);
    g_message("HMAC(MD5) for \"%s\" with key(%s) is:\n%s", s, key2, hmac);
    g_free(hmac);
    hmac = NULL;

    hmac = g_compute_hmac_for_string(
            G_CHECKSUM_SHA1, (const guchar *)key1, length1, s, -1);
    g_message("HMAC(SHA-1) for \"%s\" with key(%s) is:\n%s", s, key1, hmac);
    g_free(hmac);
    hmac = NULL;

    hmac = g_compute_hmac_for_string(
            G_CHECKSUM_SHA1, (const guchar *)key2, length2, s, -1);
    g_message("HMAC(SHA-1) for \"%s\" with key(%s) is:\n%s", s, key2, hmac);
    g_free(hmac);
    hmac = NULL;

    hmac = g_compute_hmac_for_string(
            G_CHECKSUM_SHA256, (const guchar *)key1, length1, s, -1);
    g_message("HMAC(SHA-256) for \"%s\" with key(%s) is:\n%s", s, key1, hmac);
    g_free(hmac);
    hmac = NULL;

    hmac = g_compute_hmac_for_string(
            G_CHECKSUM_SHA256, (const guchar *)key2, length2, s, -1);
    g_message("HMAC(SHA-256) for \"%s\" with key(%s) is:\n%s", s, key2, hmac);
    g_free(hmac);
    hmac = NULL;

    hmac = g_compute_hmac_for_string(
            G_CHECKSUM_SHA512, (const guchar *)key1, length1, s, -1);
    g_message("HMAC(SHA-512) for \"%s\" with key(%s) is:\n%s", s, key1, hmac);
    g_free(hmac);
    hmac = NULL;

    hmac = g_compute_hmac_for_string(
            G_CHECKSUM_SHA512, (const guchar *)key2, length2, s, -1);
    g_message("HMAC(SHA-512) for \"%s\" with key(%s) is:\n%s", s, key2, hmac);
    g_free(hmac);
    hmac = NULL;

    return 0;
}
