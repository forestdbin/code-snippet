#include <glib.h>

using namespace std;

void worker_func(gpointer data, gpointer)
{
    string * s = (string *)data;
    if (s)
    {
        cout << *s << endl;
        delete s;
    }
}

int main()
{
    GThreadPool * threadpool = g_thread_pool_new(
            worker_func,
            NULL,
            5,
            TRUE,
            NULL);

    string s;
    while (cin >> s)
    {
        if (s == "quit" || s == "exit")
            break;
        string * data = new string(s);
        g_thread_pool_push(threadpool, data, NULL);
    }

    g_thread_pool_free(threadpool, FALSE, TRUE);

    return 0;
}
