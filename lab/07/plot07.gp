set terminal pngcairo size 1200,800
set output 'OFC.png'
set title "Earthquake"
set xlabel "Timestep"
set ylabel "Magnitude"
set grid
set xrange [0:100000]
plot "results.csv" using 1:2 with lines title "Earthquake"
