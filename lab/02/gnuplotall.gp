# Set up the output format and dimensions
set terminal pngcairo size 800, 600
set output 'infection_evolution_all.png'

# Set up plot titles and labels
set title "Infection Spread Over Time with Different β Values"
set xlabel "Timestep"
set ylabel "Infected Computers"
set grid

# Set the x-axis range
set xrange [0:100]

# Plot the data from the three CSV files with distinct colors
plot "lab02bstable0.2.csv" using 1:2 with lines linecolor rgb "#1f77b4" title "Infected PCs stable β = 0.2", \
     "lab02bstable0.4.csv" using 1:2 with lines linecolor rgb "#ff7f0e" title "Infected PCs stable β = 0.4", \
     "lab02bstable0.7.csv" using 1:2 with lines linecolor rgb "#2ca02c" title "Infected PCs stable β = 0.7"

