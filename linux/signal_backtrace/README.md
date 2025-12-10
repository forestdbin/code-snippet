# Linux Signal Handling Demo

This C++ program demonstrates how signals are handled in Linux applications and shows how the stack looks like for signal handlers.

## Features

- **SIGINT Handler (Ctrl+C)**: Shows stack trace and exits gracefully
- **SIGUSR1 Handler**: Shows detailed signal information, register context, and stack trace
- **Stack Trace Display**: Uses `backtrace()` to show the call stack when signals are received
- **Normal Business Logic**: Simulates typical application work with multiple function calls
- **Register Context**: Shows stack pointer and instruction pointer when signal occurs

## Testing Signal Handling

### Method 1: Using Ctrl+C (SIGINT)

Press `Ctrl+C`

### Method 2: Using SIGUSR1

```bash
kill -USR1 <PID>
```
