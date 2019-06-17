#include <glib.h>

int main()
{
    g_message("    MD5 has %" G_GSSIZE_FORMAT " bytes of digests",
            g_checksum_type_get_length(G_CHECKSUM_MD5));
    g_message("  SHA-1 has %" G_GSSIZE_FORMAT " bytes of digests",
            g_checksum_type_get_length(G_CHECKSUM_SHA1));
    g_message("SHA-256 has %" G_GSSIZE_FORMAT " bytes of digests",
            g_checksum_type_get_length(G_CHECKSUM_SHA256));
    g_message("SHA-512 has %" G_GSSIZE_FORMAT " bytes of digests",
            g_checksum_type_get_length(G_CHECKSUM_SHA512));

    const gchar * s = "hello, world.";
    int length = strlen(s);
    gchar * digest = NULL;

    digest = g_compute_checksum_for_string(
            G_CHECKSUM_MD5, s, length);
    g_message("    MD5 digest for \"%s\" is:\n%s", s, digest);
    g_free(digest);
    digest = NULL;

    digest = g_compute_checksum_for_string(
            G_CHECKSUM_SHA1, s, length);
    g_message("  SHA-1 digest for \"%s\" is:\n%s", s, digest);
    g_free(digest);
    digest = NULL;

    digest = g_compute_checksum_for_string(
            G_CHECKSUM_SHA256, s, length);
    g_message("SHA-256 digest for \"%s\" is:\n%s", s, digest);
    g_free(digest);
    digest = NULL;

    digest = g_compute_checksum_for_string(
            G_CHECKSUM_SHA512, s, length);
    g_message("SHA-512 digest for \"%s\" is:\n%s", s, digest);
    g_free(digest);
    digest = NULL;

    return 0;
}
