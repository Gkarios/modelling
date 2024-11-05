set terminal pngcairo size 800, 600
set output 'infection_evolution b = 0.4.png'
set title "Infection Spread Over Time with stable β"
set xlabel "Timestep"
set ylabel "Infected Computers"
set grid
set xrange [0:100]
plot "lab02bstable0.7.csv" using 1:2 with lines title "Infected PCs stable b = 0.4"
