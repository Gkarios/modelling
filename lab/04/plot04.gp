set terminal pngcairo size 800,600
set output 'informed.png'
set title "Infection Spread w/ Immunity"
set xlabel "Timestep"
set ylabel "Informed sensors"
set grid
set xrange [0:2500]
plot "lab04.txt" using 1:2 with lines title "Infected Sensors"
