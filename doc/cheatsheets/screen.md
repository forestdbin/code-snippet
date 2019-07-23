# screen cheatsheet

## command lines

```
screen -ls
    -list

screen [-S session]
    new

screen -r [session]
    resume

screen -d [session]
    detach
```

## key bindings

```
C-a                     # (^A)

?   help
a   meta                # literal ^A
:   colon               # enter command line mode

c   screen              # new window

^A  other               # toggle to the previous window
"   windowlist -b       # list all windows for selection
0   select 0            # switch to window 0

-   select -            # switch to blank window
'   select              # prompt for a window
n   next                # (space) next window
p   prev                # (backspace,^H) previous window

S   split               # split region horizontally
|   split -v            # split region vertically
tab focus               # (^I) next region
Q   only                # current region only
X   remove              # kill current region

d   detach              # detach screen
k   kill                # destroy current window
A   title               # set current window name
\   quit                # kill all windows and terminate screen
x   lockscreen          # lock this terminal
z   suspend             # suspend screen (fg)

w   windows             # show window list
N   number              # show window number/title
i   info                # show window info
*   displays            # show all displays
t   time                # show system info

^G  vbell               # visual bell mode
l   redisplay           # refresh current window
C   clear               # clear the screen
Z   reset               # reset virtual terminal

[   copy                # (esc) enter copy/scrollback mode
]   paste .             # paste
```

## tips

### show current session

```
$ echo $STY
9774.screen
```

### always show window list

```
hardstatus on
hardstatus alwayslastline
hardstatus string "%w"
```
