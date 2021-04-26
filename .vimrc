set guifont=Courier_New:h10:cANSI:qDRAFT
"""" Enable Vundle: vim plugin manager

" required before Vundle initialization
" set nocompatible        " disable compatibility mode with vi
" filetype off            " disable filetype detection (but re-enable later, see below)



" set the runtime path to include Vundle, and initialize
" set rtp+=~/.vim/bundle/Vundle.vim
" call vundle#begin()
" Plugin 'VundleVim/Vundle.vim'
" Plugin 'wting/rust.vim' " enable syntax highlighting for rust
" call vundle#end()


"""" Basic Behavior

set number              " show line numbers
set wrap                " wrap lines
set encoding=utf-8      " set encoding to UTF-8 (default was "latin1")
set mouse=a             " enable mouse support (might not work well on Mac OS X)
set wildmenu            " visual autocomplete for command menu
set lazyredraw          " redraw screen only when we need to
set showmatch           " highlight matching parentheses / brackets [{()}]
set laststatus=2        " always show statusline (even with only single window)
set ruler               " show line and column number of the cursor on right side of statusline
set visualbell          " blink cursor on error, instead of beeping


"""" Key Bindings

" move vertically by visual line (don't skip wrapped lines)
nmap j gj
nmap k gk


"""" Vim Appearance
" put colorscheme files in ~/.vim/colors/
" 컬러 스킴 사용
"colorscheme jellybeans
colorscheme torte     " good colorschemes: murphy, slate, molokai, badwolf, solarized

" use filetype-based syntax highlighting, ftplugins, and indentation
syntax enable
filetype plugin indent on


"""" Tab settings

set tabstop=4           " width that a <TAB> character displays as
"set expandtab           " convert <TAB> key-presses to spaces
set shiftwidth=4        " number of spaces to use for each step of (auto)indent
set softtabstop=4       " backspace after pressing <TAB> will remove up to this many spaces

set autoindent          " copy indent from current line when starting a new line
set smartindent         " even better autoindent (e.g. add indent after '{')
set cindent

"""" Search settings
set incsearch           " search as characters are entered
set hlsearch            " highlight matches

" turn off search highlighting with <CR> (carriage-return)
nnoremap<silent> <CR> :nohlsearch<CR><CR>

"""" Miscellaneous settings that might be worth enabling

"set cursorline         " highlight current line
"set background=dark    " configure Vim to use brighter colors
"set autoread           " autoreload the file in Vim if it has been changed outside of Vim

" 파일 인코딩을 한국어로
if $LANG[0]=='k' && $LANG[1]=='o'
set fileencoding=korea
endif

"Latex setting
source $HOME/.vim/latexrc
au BufRead *latexrc set filetype=vim

map ,k :w<cr>:!./a.out <% <cr>
au Filetype c,cpp vmap <buffer> i :norm i//<cr>
au Filetype c,cpp vmap <buffer> x :norm 2x<cr>
au Filetype c,cpp map <buffer> <C-J> :w<cr>:!g++ %<cr>
au FIletype c,cpp map <C-K> :!./a.out<cr>
au Filetype c,cpp map ,k :w<cr>:!./a.out <input <cr>
au Filetype c,cpp map <buffer> <C-L> :w<cr>:!g++ %<cr>:!./a.out<cr>
au Filetype c,cpp iab <buffer> FOR for(int i=0;i<;i++){<cr>~<cr>}<Esc>kk$5hi
au Filetype c,cpp iab <buffer> PB push_back);<Esc>hi
au Filetype c,cpp iab <buffer> endl '\n'
au BufNewFile *.cpp 0r ~/.vim/template/template.cpp
au Filetype c,cpp command! -nargs=1 FOR :normal ofor(int <args>=0;<args><;<args>++){<cr>~<cr>}<Esc>kk$5h
au Filetype c,cpp command! FIO :normal oios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);<Esc>

au Filetype python map <buffer> <C-L> :w<cr>:!python %<cr>
au Filetype python map <buffer> <C-k> :w<cr>:!python % <input <cr>
au Filetype python map <buffer> ,l :w<cr>:!python % <input <cr>
au Filetype python vmap <buffer> i :norm i#<cr>
au Filetype python vmap <buffer> x :norm x<cr>
au Filetype python command! Input :normal alist(map(int,sys.stdin.readline().split()))

" keep folding
set foldmethod=marker

if has("autocmd")
	" When editing a file, always jump to the last cursor position
	autocmd BufReadPost *
	\ if line("'\"") > 0 && line ("'\"") <= line("$") |
	\ exe "normal g'\"" |
	\ endif
endif
" https://blog.naver.com/101story/100122854668

" misc
nmap ,w :w<cr>
nmap <space> /
set whichwrap+=h,l
set backspace=indent,eol,start
map ' `
vmap / :norm i//<cr>
vmap x :norm xx<cr>
nmap <Tab> :bn<cr>
nmap <S-Tab> :bp<cr>
command Q q
