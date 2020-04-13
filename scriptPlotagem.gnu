set xlabel "Frequência"
set ylabel "Amplitude"
set grid
plot "dados.txt" smooth csplines
pause 1
reread