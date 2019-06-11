# A simple way to build googletest archive

```bash
$ git clone https://github.com/google/googletest.git
$ cd googletest
$ git checkout -b release-1.8.1 tags/release-1.8.1
$ cp ../make.bash .
$ chmod +x make.bash
$ ./make.bash
```
