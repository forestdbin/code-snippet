#include <glib.h>

using namespace std;

gpointer producer(gpointer data)
{
    string s;
    while (cin >> s)
    {
        g_async_queue_push((GAsyncQueue *)data, new string(s));
        if (s == "exit" || s == "quit")
            break;
    }
    return NULL;
}

gpointer consumer(gpointer data)
{
    gpointer item = NULL;
    GAsyncQueue * asyncqueue = (GAsyncQueue *)data;
    bool should_exit = false;
    while ((item = g_async_queue_pop(asyncqueue)))
    {
        string * s = (string *)item;
        cout << *s << endl;
        if (*s == "exit" || *s == "quit")
            should_exit = true;
        delete s;
        if (should_exit)
            break;
    }

    return NULL;
}

int main()
{
    GAsyncQueue * asyncqueue = g_async_queue_new();
    GThread * producer_thread = g_thread_new("producer", producer, asyncqueue);
    GThread * consumer_thread = g_thread_new("consumer", consumer, asyncqueue);
    g_thread_join(producer_thread);
    g_thread_join(consumer_thread);
    g_async_queue_unref(asyncqueue);

    return 0;
}
