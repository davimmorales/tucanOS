noo 0 0 0 0
loadi 0 0 0 0
store 0 0 0 224
store 0 0 0 226
loadi 21 0 0 12
store 21 0 0 227
load 21 0 0 227
loadr 21 0 22 0
setlt 22 0 23 0
setlt 0 22 24 0
or 23 24 23 0
pbranch 23 0 0 0
branchz 0 0 0 20
loadi 24 0 0 1
setlt 24 22 24 0
pbranch 24 0 0 0
branchz 0 0 0 12
load 21 0 0 227
addi 21 0 21 1
loadr 21 0 22 0
setlt 22 0 23 0
setlt 0 22 24 0
or 23 24 23 0
not 23 0 23 0
pbranch 23 0 0 0
branchz 0 0 0 3
load 24 0 0 226
addi 24 0 24 1
store 24 0 0 226
load 21 0 0 227
addi 21 0 21 2
store 21 0 0 227
jump 0 0 0 6
load 21 0 0 226
loadi 22 0 0 2
setlt 22 21 22 0
pbranch 22 0 0 0
branchz 0 0 0 2
loadi 21 0 0 1
store 21 0 0 224
