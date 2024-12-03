# Set up the output format and dimensions
set terminal pngcairo size 1600, 1000
set output 'coefficient2.png'

# Set up plot titles and labels
set title "infection coefficient comparisson"
set xlabel "Timestep"
set ylabel "Informed sensors"
set grid

# Set the x-axis range
set xrange [0:10000]

# Plot the data from the three CSV files with distinct colors
plot "lab04n=05.txt" using 1:2 with lines linecolor rgb "#2ca02c" title "N = 5", \
"lab04n=10.txt" using 1:2 with lines linecolor rgb "#e64539" title "N = 10", \
"lab04n=30.txt" using 1:2 with lines linecolor rgb "#1f77b4" title "N = 30", \
"lab04n=50.txt" using 1:2 with lines linecolor rgb "#de996a" title "N = 50", \
"lab04n=100.txt" using 1:2 with lines linecolor rgb "#e63998" title "N = 100", \

