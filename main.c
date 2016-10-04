#include <stdlib.h>
#include <stdio.h>
#include <gio/gio.h>


static void onChangeEvent (GSettings *settings, const GQuark *keys, gint n_keys)
{
    GVariant *variant;
    // GConverter *converter;
    gchar *result;

    variant = g_settings_get_value (settings, "idle-brightness");
    g_variant_get (variant, "s", &result);
    g_print(result);
    g_free(result);
}


int main (int argc, char *argv[])
{
    GSettings *settings;
    settings = g_settings_new ("org.gnome.settings-daemon.plugins.power");

    int rcode;
    rcode = g_signal_connect_after (settings, "change-event", G_CALLBACK (onChangeEvent), NULL);
    if (rcode <= 0)
        fprintf(stderr, "Signal connect KO to org.gnome.settings-daemon.plugins.power: change-event\n");

    GMainLoop *mainLoop;
    mainLoop = g_main_loop_new (NULL, TRUE);
    g_main_loop_run (mainLoop);

    return 0;
}
