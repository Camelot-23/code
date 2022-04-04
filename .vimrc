colorscheme desert

"光标移动到buffer的顶部和底部时保持3行距离
set scrolloff=6"

"set hlsearch

"映射全选+复制 ctrl+a
map <C-A> ggVGY
"自动缩进
map <F12> gg=G
"回退的回退
nnoremap U <C-r>

"共享剪贴板  
set clipboard=unnamed 
" 突出显示当前行
set cursorline
" 去掉输入错误的提示声音
set noeb
" 在处理未保存或只读文件的时候，弹出确认
set confirm
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
set fencs=utf-8,gbk,ucs-bom,shift-jis,gb18030,gbk,gb2312,cp936
"语言设置
set langmenu=zh_CN.UTF-8
set helplang=cn
" 我的状态行显示的内容（包括文件类型和解码）
"set statusline=[Line:%l/%L,Column:%c][%p%%]

"自动补全
:inoremap ( ()<ESC>i
		:inoremap ) <c-r>=ClosePair(')')<CR>
:inoremap { {<CR>}<ESC>O
	:inoremap } <c-r>=ClosePair('}')<CR>
	:inoremap [ []<ESC>i
	:inoremap ] <c-r>=ClosePair(']')<CR>
	":inoremap " ""<ESC>i
	:inoremap ' ''<ESC>i
function! ClosePair(char)
	if getline('.')[col('.') - 1] == a:char
	return "\<Right>"
	else
	return a:char
	endif
	endfunction

	"新建.c,.h,.sh,.java文件，自动插入文件头 
	autocmd BufNewFile *.cpp,*.[ch],*.sh,*.java exec ":call SetTitle()" 
	""定义函数SetTitle，自动插入文件头 

func SetTitle() 
	"如果文件类型为.sh文件 
	if &filetype == 'sh' 
	call setline(1, "##########################################################################") 
	call append(line("."), "# File Name: ".expand("%")) 
	call append(line(".")+1, "# Author: camelot") 
	call append(line(".")+2, "# mail: 1420494366@qq.com") 
	call append(line(".")+3, "# Created Time: ".strftime("%c")) 
	call append(line(".")+4, "#########################################################################") 
	call append(line(".")+5, "#!/bin/zsh")
	call append(line(".")+6, "PATH=/home/edison/bin:/home/edison/.local/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin:/work/tools/gcc-3.4.5-glibc-2.3.6/bin")
	call append(line(".")+7, "export PATH")
	call append(line(".")+8, "")
	else 
	call setline(1, "/*************************************************************************") 
	call append(line("."), "	> File Name: ".expand("%")) 
	call append(line(".")+1, "	> Author: camelot") 
	call append(line(".")+2, "	> Mail: 1420494366@qq.com ") 
	call append(line(".")+3, "	> Created Time: ".strftime("%c")) 
	call append(line(".")+4, " ************************************************************************/") 
	call append(line(".")+5, "")
	endif
	if &filetype == 'cpp'
	call append(line(".")+6, "#include <stdio.h>")
	call append(line(".")+7, "#include <iostream>")
	call append(line(".")+8, "")
	call append(line(".")+9, "using namespace std;")
	call append(line(".")+10, "")
	call append(line(".")+11, "int main(int argc,char *argv[])")
	call append(line(".")+12, "{")
	call append(line(".")+13, "")
	call append(line(".")+14, "	return 0;")
	call append(line(".")+15, "}")
	endif
	if &filetype == 'c'
	call append(line(".")+6, "#include <stdio.h>")
	call append(line(".")+7, "")
	call append(line(".")+8, "int main(int argc,char *argv[])")
	call append(line(".")+9, "{")
	call append(line(".")+10, "")
	call append(line(".")+11, "	return 0;")
	call append(line(".")+12, "}")
	endif
	"	if &filetype == 'java'
	"		call append(line(".")+6,"public class ".expand("%"))
	"		call append(line(".")+7,"")
	"	endif
	"新建文件后，自动定位到文件末尾--_不知道为什么不生效
	autocmd BufNewFile * normal G
	endfunction




