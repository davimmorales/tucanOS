noo 0 0 0 0
loadi 0 0 0 0
loadi 21 0 0 3
store 21 0 0 249
store 0 0 0 266
store 0 0 0 267
store 0 0 0 268
loadi_hd 21 1 0 0
store 21 0 0 248
load 21 0 0 248
load_hd 21 0 22 0
setlt 0 22 23 0
pbranch 23 0 0 0
branchz 0 0 0 20
loadi 23 0 0 1
setlt 23 22 24 0
pbranch 24 0 0 0
branchz 0 0 0 13
addi 21 0 21 3
load_hd 21 0 22 0
setlt 22 23 24 0
setlt 23 22 25 0
or 25 24 24 0
not 24 0 24 0
pbranch 24 0 0 0
branchz 0 0 0 5
subi 21 0 21 2
load_hd 21 0 22 0
loadi 24 0 0 6
add 22 24 22 0
storer 22 0 23 0
load 21 0 0 248
addi 21 0 21 32
jump 0 0 0 264
load 21 0 0 267
setlt 0 21 22 0
not 22 0 22 0
pbranch 22 0 0 0
branchz 0 0 0 3
loadi 23 0 0 1
store 23 0 0 249
jump 0 0 0 305
load 21 0 0 268
setlt 0 21 22 0
not 22 0 22 0
pbranch 22 0 0 0
branchz 0 0 0 2
loadi 23 0 0 2
store 23 0 0 249
load 18 0 0 249
output 18 0 0 0
halt 0 0 0 0
add 0 0 0 0
