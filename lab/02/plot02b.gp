set terminal pngcairo size 800, 600
set output 'infection_evolution_decreasing_b.png'
set title "Infection Spread Over Time with decreasing β"
set xlabel "Timestep"
set ylabel "Infected Computers"
set grid
set xrange [0:50]
plot "lab02b.csv" using 1:2 with lines title "Infected PCs"
