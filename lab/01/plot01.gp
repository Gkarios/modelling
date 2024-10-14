set terminal pngcairo size 1280,960
set output 'frequency_plot.png'
set multiplot layout 2,1 title "Frequency of Die Rolls"

#Plot for 100 rolls
set title "100 Rolls"
set xlabel "Die Face"
set ylabel "Frequency" 
set grid
set style data histograms
set style fill solid 1.0 border -1
set yrange [0:25]
plot "lab01_100.txt" using 2:xtic(1) title "Frequency (100 rolls)"

#Plot for 1000 rolls
set title "1000 Rolls"
set xlabel "Die Face"
set ylabel "Frequency"
set grid
set style data histograms
set style fill solid 1.0 border -1
set yrange [0:250]
plot "lab01_1000.txt" using 2:xtic(1) title "Frequency (1000 rolls)"

unset multiplot
