set terminal pngcairo size 800,600
set output 'infection_plot_beta.png'
set title "Infection Spread w/ decreasing β"
set xlabel "Timestep"
set ylabel "Infected Computers"
set grid
set xrange [0:35]
plot "lab03b.txt" using 1:2 with lines title "Infected PCs"
