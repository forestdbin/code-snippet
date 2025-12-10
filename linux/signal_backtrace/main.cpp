#include <signal.h>
#include <cstdlib>

#include <chrono>
#include <iostream>
#include <thread>

#include <unistd.h>
#include <sys/ucontext.h>

#include <cxxabi.h>
#include <execinfo.h>

using std::cout;
using std::dec;
using std::hex;
using std::endl;
using std::string;


volatile sig_atomic_t keep_running = 1;

string demangle_name(const char* mangled_name) {
    int status = 0;
    char* demangled = abi::__cxa_demangle(mangled_name, nullptr, nullptr, &status);

    if (status == 0 && demangled) { // demangling succeed
        string result(demangled);
        free(demangled);
        return result;
    }

    // If demangling failed, return the original name
    return string(mangled_name);
}

void print_stack_trace() {
    void *array[20];
    size_t size;
    char **strings;

    size = backtrace(array, 20);
    strings = backtrace_symbols(array, size);

    cout << "\n=== Stack Trace (with C++ demangling) ===" << endl;

    for (size_t i = 0; i < size; i++) {
        string symbol_info(strings[i]);
        cout << "[" << i << "] Raw: " << symbol_info << endl;

        // Try to extract and demangle the function name
        // Format is typically: binary(function+offset) [address]
        size_t start = symbol_info.find('(');
        size_t end = symbol_info.find('+');

        if (start != string::npos && end != string::npos && end > start) {
            string mangled_name = symbol_info.substr(start + 1, end - start - 1);
            if (!mangled_name.empty()) {
                string demangled = demangle_name(mangled_name.c_str());
                cout << "[" << i << "] Demangled: " << demangled << endl;
            }
        }
        cout << endl;
    }
    cout << "=========================================" << endl;

    free(strings);
}

// Signal handler for SIGINT (Ctrl+C)
void sigint_handler(int sig) {
    cout << "\n[SIGNAL] Received SIGINT (signal " << sig << ")" << endl;
    cout << "[SIGNAL] Signal handler executing..." << endl;

    print_stack_trace();

    keep_running = 0;

    cout << "[SIGNAL] Signal handler completed, will exit gracefully" << endl;
}

// Signal handler for SIGUSR1 with more detailed context
void sigusr1_handler(int sig, siginfo_t *info, void *context) {
    cout << "\n[SIGNAL] Received SIGUSR1 (signal " << sig << ")" << endl;
    cout << "[SIGNAL] Signal info:" << endl;
    cout << "  - Signal number: " << info->si_signo << endl;
    cout << "  - Sending PID: " << info->si_pid << endl;
    cout << "  - Real user ID: " << info->si_uid << endl;

    // Cast context to ucontext_t to examine registers and stack
    ucontext_t *uc = (ucontext_t *)context;
    cout << "  - Stack pointer: 0x" << hex << uc->uc_mcontext.gregs[REG_RSP] << dec << endl;
    cout << "  - Instruction pointer: 0x" << hex << uc->uc_mcontext.gregs[REG_RIP] << dec << endl;

    print_stack_trace();

    cout << "[SIGNAL] SIGUSR1 handler completed" << endl;
}

void business_function_1() {
    cout << "[BUSINESS] Executing business function 1..." << endl;

    for (int i = 0; i < 3; i++) {
        cout << "[BUSINESS] Processing item " << (i + 1) << "/3" << endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

void business_function_3() {
    cout << "[BUSINESS] Deep function level 3" << endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

void business_function_2() {
    cout << "[BUSINESS] Executing business function 2 (calls function 3)..." << endl;
    business_function_3();
}

void setup_signal_handlers() {
    signal(SIGINT, sigint_handler);

    struct sigaction sa;
    sa.sa_sigaction = sigusr1_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_SIGINFO; // Use extended handler

    if (sigaction(SIGUSR1, &sa, NULL) == -1) {
        perror("sigaction");
        exit(1);
    }

    cout << "[SETUP] Signal handlers installed" << endl;
    cout << "[SETUP] - SIGINT (Ctrl+C): Will show stack and exit gracefully" << endl;
    cout << "[SETUP] - SIGUSR1: Will show detailed signal info and stack" << endl;
    cout << "[SETUP] Send SIGUSR1 with: kill -USR1 " << getpid() << endl;
}

int main() {
    cout << "=== Linux Signal Handling Demo ===" << endl;
    cout << "Process ID: " << getpid() << endl;

    setup_signal_handlers();

    cout << "\n[MAIN] Starting main business loop..." << endl;
    cout << "[MAIN] Press Ctrl+C to trigger SIGINT" << endl;
    cout << "[MAIN] Send 'kill -USR1 " << getpid() << "' from another terminal to trigger SIGUSR1" << endl;

    int iteration = 0;

    while (keep_running) {
        iteration++;
        cout << "\n--- Iteration " << iteration << " ---" << endl;

        business_function_1();

        if (iteration % 3 == 0) {
            business_function_2();
        }

        cout << "[MAIN] Sleeping for 2 seconds..." << endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }

    cout << "\n[MAIN] Graceful shutdown completed." << endl;
    cout << "=== Program End ===" << endl;

    return 0;
}
