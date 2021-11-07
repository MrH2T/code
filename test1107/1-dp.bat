:loop
gen >1-dat.in
me <1-dat.in >me.out
sol <1-dat.in >sol.out
fc me.out sol.out
if ERRORLEVEL 1 pause

goto loop