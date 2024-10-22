set terminal pngcairo size 800,600
set output 'infection_plot_random.png'
set title "Infection Spread w/ Random Immunity"
set xlabel "Timestep"
set ylabel "Infected Computers"
set grid
set xrange [0:35]
set yrange [0:1000]
plot "lab03rand.txt" using 1:2 with lines title "Infected PCs"
