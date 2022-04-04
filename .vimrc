colorscheme desert

" 光标移动到buffer的顶部和底部时保持3行距离
set scrolloff=6"


"map  noremap normal, visual, operator-pending
"nmap nnoremap normal
"xmap xnoremap visual
"cmap cnoremap command-line
"omap onoremap operator-pending
"imap inoremap insert

:map <C-A> ggVGY
:nnoremap U <C-r>

""set clipboard=unnamed

" 突出显示当前行
set cursorline
" 去掉输入错误的提示声音
"set noeb
" 自动缩进
set autoindent
set cindent
" Tab键的宽度
set tabstop=4
" 统一缩进为4
set softtabstop=4
set shiftwidth=4
" 不要用空格代替制表符
set noexpandtab
" 显示行号
set number
"禁止生成临时文件
set nobackup
set noswapfile

"编码设置
set enc=utf-8
set fencs=gbk,ucs-bom,shift-jis,gb18030,gbk,gb2312,cp936
"语言设置
set langmenu=zh_CN.GBK
set helplang=cn

"自动补全
:inoremap ( ()<ESC>i
:inoremap { {<CR>}<ESC>O
:inoremap [ []<ESC>i
:inoremap " ""<ESC>i
:inoremap ' ''<ESC>i



"新建文件，自动插入文件头 
autocmd BufNewFile * exec ":call SetTitle()" 
"定义函数SetTitle，自动插入文件头 
func SetTitle() 
	call setline(1, "/*******************************************************************************") 
	call append(line("."), "> File Name: ".expand("%")) 
	call append(line(".")+1, "> Author: camelot") 
	call append(line(".")+2, "> mail: 1420494366@qq.com") 
	call append(line(".")+3, "> Created Time: ".strftime("%c")) 
	call append(line(".")+4, "> Message: ") 
	call append(line(".")+5, "********************************************************************************/") 
endfunction

autocmd BufReadPost *
\if line("'\'") > 1 && line("'\'") <= line("$")|
\exe "normal! g`\""|
\endif



