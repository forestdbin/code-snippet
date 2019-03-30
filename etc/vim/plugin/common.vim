syntax on

filetype plugin indent on

autocmd BufReadPost *
  \ if line("'\"") >= 1 && line("'\"") <= line("$") |
  \   exe "normal! g`\"" |
  \ endif

autocmd BufWritePre * :%s/\s\+$//e

autocmd FileType * setlocal formatoptions-=cro

packadd! matchit
