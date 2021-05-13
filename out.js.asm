CsteNb 10
SetVar x
GetVar x
CsteNb 5
GrStNb
ConJmp 4
GetVar x
CsteNb 20
LoStNb
Jump 1
CsteBo false
ConJmp 3
CsteNb 1
SetVar y
Jump 2
CsteNb 0
SetVar y
GetVar x
CsteNb 5
LoStNb
ConJmp 2
CsteBo true
Jump 3
GetVar x
CsteNb 2
GrStNb
ConJmp 3
CsteNb 1
SetVar z
Jump 2
CsteNb 0
SetVar z
GetVar x
CsteNb 10
LoStNb
ConJmp 4
GetVar x
CsteNb 5
GrStNb
Jump 1
CsteBo false
ConJmp 3
CsteNb 0
SetVar f
Jump 2
CsteNb 1
SetVar f
GetVar x
CsteNb 100
GrStNb
ConJmp 2
CsteBo true
Jump 3
GetVar x
CsteNb 5
LoStNb
ConJmp 3
CsteNb 0
SetVar g
Jump 2
CsteNb 1
SetVar g
Halt
