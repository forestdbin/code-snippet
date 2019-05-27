#ifndef _ALL_COMMON_H_
#define _ALL_COMMON_H_

// #define _GNU_SOURCE

#ifdef __cplusplus
// standard C++ library

// #include <concepts> // C++20-
// #include <coroutine> // C++20-
#include <cstdlib>
// #include <csignal>
// #include <csetjmp>
#include <cstdarg>
#include <typeinfo>
// #include <typeindex> // C++11-
#include <type_traits> // C++11-
// #include <bitset>
#include <functional>
#include <utility>
#include <ctime>
// #include <chrono> // C++11-
#include <cstddef>
#include <initializer_list> // C++11-
#include <tuple> // C++11-
// #include <any> // C++17-
// #include <optional> // C++17-
// #include <variant> // C++17-
// #include <compare> // C++20-
// #include <version> // C++20-
#include <new>
#include <memory>
// #include <scoped_allocator> // C++11-
// #include <memory_resource> // C++17-
#include <climits>
// #include <cfloat>
#include <cstdint> // C++11-
#include <cinttypes> // C++11-
#include <limits>
#include <exception>
#include <stdexcept>
#include <cassert>
// #include <system_error> // C++11-
// #include <cerrno>
// #include <contract> // C++20-
#include <cctype>
// #include <cwctype>
#include <cstring>
// #include <cwchar>
// #include <cuchar> // C++11-
#include <string>
// #include <string_view> // C++17-
// #include <charconv> // C++17-
#include <array> // C++11-
#include <vector>
#include <deque>
#include <list>
#include <forward_list> // C++11-
#include <set>
#include <map>
#include <unordered_set> // C++11-
#include <unordered_map> // C++11-
#include <stack>
#include <queue>
// #include <span> // C++20-
#include <iterator>
// #include <ranges> // C++20-
#include <algorithm>
// #include <execution> // C++17-
// #include <cmath>
// #include <complex>
#include <valarray>
#include <random> // C++11-
#include <numeric>
#include <ratio> // C++11-
// #include <cfenv> // C++11-
// #include <bit> // C++20-
#include <iosfwd>
#include <ios>
#include <istream>
#include <ostream>
#include <iostream>
#include <fstream>
#include <sstream>
// #include <syncstream> // C++20-
#include <iomanip>
#include <streambuf>
#include <cstdio>
// #include <locale>
// #include <clocale>
// #include <codecvt> // C++11-C++17
#include <regex> // C++11-
#include <atomic> // C++11-
#include <thread> // C++11-
#include <mutex> // C++11-
// #include <shared_mutex> // C++14-
#include <future> // C++11-
#include <condition_variable> // C++11-
// #include <filesystem> // C++17-

#else
// standard C library

#include <assert.h>
// #include <complex.h>
#include <ctype.h>
// #include <errno.h>
// #include <fenv.h>
// #include <float.h>
#include <inttypes.h>
#include <iso646.h>
#include <limits.h>
// #include <locale.h>
// #include <math.h>
// #include <setjmp.h>
// #include <signal.h>
// #include <stdalign.h>
#include <stdarg.h>
#include <stdatomic.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
// #include <stdnoreturn.h>
#include <string.h>
// #include <tgmath.h>
// #include <threads.h>
#include <time.h>
// #include <uchar.h>
// #include <wchar.h>
// #include <wctype.h>

#endif // __cplusplus

// common Linux library

#include <unistd.h>
#include <pthread.h>
#include <syslog.h>
#include <getopt.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <semaphore.h>
#include <mqueue.h>

#include <sys/types.h>
#include <sys/socket.h>
// #include <sys/ipc.h>
// #include <sys/sem.h>
// #include <sys/shm.h>
// #include <sys/msg.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <sys/select.h>
#include <sys/poll.h>
#include <sys/epoll.h>
#include <sys/eventfd.h>
#include <sys/fanotify.h>
#include <sys/inotify.h>
#include <sys/file.h>
#include <sys/mman.h>
#include <sys/mount.h>
#include <sys/ptrace.h>
#include <sys/resource.h>
#include <sys/sendfile.h>
#include <sys/sysinfo.h>
#include <sys/time.h>
#include <sys/times.h>
#include <sys/uio.h>
#include <sys/utsname.h>
#include <sys/wait.h>

#include <linux/unistd.h>
#include <linux/futex.h>
#include <linux/sysctl.h>

#endif // _ALL_COMMON_H_
