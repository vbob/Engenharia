.global _start
_start:
MOV R0, #2
B end
MOV R0, #4
end:
MOV R7, #1
SWI 0
