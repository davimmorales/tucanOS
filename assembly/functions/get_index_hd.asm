noo 0 0 0 0
loadi 21 0 0 31
store 21 0 0 4
noo 0 0 0 0
loadi_hd 22 1 0 0
store 22 0 0 6
load 21 0 0 6
load_hd 21 0 22 0
setlt 0 22 23 0
setlt 22 0 24 0
or 23 24 23 0
pbranch 23 0 0 0
branchz 0 0 0 14
load 25 0 0 4
setlt 22 25 23 0
setlt 25 22 24 0
or 23 24 23 0
not 23 0 23 0
pbranch 23 0 0 0
branchz 0 0 0 4
addi 21 0 22 5
load_hd 22 0 22 0
store 22 0 0 5
jump 0 0 0 28
addi 21 0 21 12
store 21 0 0 6
jump 0 0 0 6
store 0 0 0 5
load 5 0 0 5
output 5 0 0 0
