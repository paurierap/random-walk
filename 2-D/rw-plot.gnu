# Plot the random walk using GNUPLOT

set title "2-D Random Walk"
set parametric
NO_ANIMATION=1
# plot "random-walk.dat" using 2:3 with lines
filename(n) = sprintf("particle%d-rw.dat", n)
plot for [i=1:1] filename(i) u 2:3 w lines notitle