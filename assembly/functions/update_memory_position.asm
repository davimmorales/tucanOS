noo 0 0 0 0
loadi 0 0 0 0
input 21 0 0 0
loadi 22 0 0 0
loadi 23 0 0 1
store 21 0 0 5
store 22 0 0 6
store 23 0 0 7
loadi_hd 21 1 0 0
store 21 0 0 4
load 21 0 0 4
load_hd 21 0 22 0
setlt 22 0 23 0
setlt 0 22 24 0
or 23 24 23 0
pbranch 23 0 0 0
branchz 0 0 0 15
load 21 0 0 5
setlt 21 22 23 0
setlt 22 21 24 0
or 23 24 23 0
not 23 0 23 0
pbranch 23 0 0 0
branchz 0 0 0 5
load 21 0 0 4
addi 21 0 21 1
load 23 0 0 7
store_hd 21 0 23 0
jump 0 0 0 3
load 21 0 0 4
addi 21 0 21 12
jump 0 0 0 9
store 0 0 0 4
loadi 21 0 0 20
load 22 0 0 6
times 21 22 22 0
store 22 0 0 6
load 22 0 0 7
times 21 22 22 0
store 22 0 0 7
loadi 21 0 0 20
load 22 0 0 4
setlt 21 22 23 0
pbranch 23 0 0 0
branchz 0 0 0 10
load 23 0 0 6
add 22 23 23 0
load 24 0 0 7
add 22 24 24 0
loadr 23 0 22 0
storer 24 0 22 0
load 22 0 0 4
addi 22 0 22 1
store 22 0 0 4
jump 0 0 0 41
loadi 21 0 0 0
load 22 0 0 7
loadi 23 0 0 20
times 22 23 22 0
setlt 21 22 23 0
pbranch 23 0 0 4
loadr 22 0 24 0
output 24 0 0 0
addi 22 0 22 1
jump 0 0 0 59
loadi 5 0 0 555
output 5 0 0 0