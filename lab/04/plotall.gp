# Set up the output format and dimensions
set terminal pngcairo size 1600, 1000
set output 'dissemination.png'

# Set up plot titles and labels
set title "Dissemination with different probability"
set xlabel "Timestep"
set ylabel "Informed sensors"
set grid

# Set the x-axis range
set xrange [0:5000]

# Plot the data from the three CSV files with distinct colors
plot "lab04b.txt" using 1:2 with lines linecolor rgb "#1f77b4" title "Informed sensor β = 1", \
     "lab04b=0.8.txt" using 1:2 with lines linecolor rgb "#2ca02c" title "Informed sensor β = 0.8", \
     "lab04b=0.5.txt" using 1:2 with lines linecolor rgb "#ff7f0e" title "Informed sensor β = 0.5", \
     "lab04b=0.3.txt" using 1:2 with lines linecolor rgb "#876404" title "Informed sensor β = 0.3"


