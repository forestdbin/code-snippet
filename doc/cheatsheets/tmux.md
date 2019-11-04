# tmux cheatsheet

## key bindings

```
C-b # (^B)

?   # help
^B  # literal ^B
:   # enter command prompt

c   # create new window
l   # select last window
w   # select window interactively
0   # select window 0
'   # prompt for a window index to select
n   # select next window
p   # select previous window
M-n # select next window (bell)
M-p # select previous window (bell)
.   # prompt for an index to move current window
,   # rename current window
i   # show current window info
&   # kill current window
f   # ??

"   # split current pane horizontally
%   # split current pane vertically
;   # select to last active pane
o   # select next pane
z   # toggle zoom state of current pane
M-1 # 1st laytout (even-horizontal, even-vertical, main-horizontal, main-vertical, tiled)
Space # next layout
{   # swap current pane with previous
}   # swap current pane with next
^O  # rotate panes forward
M-o # rotate panes backward
x   # kill current pane
q   # briefly display pane indexes
!   # make current pane a window
m   # mark current pane
M   # clear marked pane

d   # detach current client
D   # choose client to detach
s   # select session interactively
$   # rename current session
L   # switch to last session
(   # switch to previous session
)   # switch to next session

^Z  # suspend tmux (fg)
r   # redraw client
t   # show time
~   # show previous messages

[   # copy
]   # paste
#   # list all paste buffers
=   # choose paste buffer interactively
-   # delete latest buffer
```

## tips

### set repeat time

```
$ tmux show-options -g repeat-time
$ tmux set-option -g repeat-time 250
```
