#!/bin/bash

# https://en.wikipedia.org/wiki/ANSI_escape_code

# Control Sequence Introducer
CSI='['

# Select Graphic Rendition
SGR=m

# Colors
# foreground
  BLACK_FG=30
    RED_FG=31
  GREEN_FG=32
 YELLOW_FG=33
   BLUE_FG=34
MAGENTA_FG=35
   CYAN_FG=36
  WHITE_FG=37

# background
  BLACK_BG=40
    RED_BG=41
  GREEN_BG=42
 YELLOW_BG=43
   BLUE_BG=44
MAGENTA_BG=45
   CYAN_BG=46
  WHITE_BG=47

colored_string()
{
    string=$1
    fg_color=${2^^}_FG
    fg_color=${!fg_color}

    echo ${CSI}${fg_color}${SGR}${string}${CSI}${SGR}
}

test_colored_string()
{
    for color in black red green yellow blue magenta cyan white
    do
        printf "%8s: %s\n" ${color^} "$(colored_string 'hello world' $color)"
    done
}

test_colored_string
