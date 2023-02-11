## VScode with wsl
install vscode from app store
open it and install WSL extension

close vscode and WSL terminal.
open WSL and now "$ code ." should work


## simAvr
simAVR source
https://github.com/buserror/simavr


## Control wsl resources
on windows goto %UserProfile%
create .wslconfig
add:

[wsl2]
memory = 4gb

https://learn.microsoft.com/en-us/windows/wsl/wsl-config for more examples


## clang formatter options
https://clang.llvm.org/docs/ClangFormatStyleOptions.html
