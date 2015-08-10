#!/usr/bin/gnuplot

set terminal postscript



set xlabel "x [nm]"
set ylabel "y [nm]"
set zlabel "U [mV]"
set contour

########### to comment

set view 60, 30, 1, 1.1
set contour base

set cntrparam levels auto 10
###########

set palette defined ( 0 "blue", 1 "green", 2 "yellow", 3 "orange", 4 "brown" )

set key lmargin

set output '| ps2pdf - output/pict/vxy_3d.pdf'
splot "output/vxy.dat" u 1:2:3 w pm3d t ""
set pm3d map
set output '| ps2pdf - output/pict/vxy_iso.pdf'
splot "output/vxy.dat" u 1:2:3 w pm3d t ""



set key default

set xrange [0:500]
set yrange [0:500]

set output '| ps2pdf - output/pict/vxy_map.pdf'
plot "output/vxy.dat" u 1:2:3 w image

unset contour

set output '| ps2pdf - output/pict/map.pdf'
set palette defined ( 0 "white", 1 "grey")
plot "output/map.dat" u 1:2:3 w image

reset
set key off
set grid
set xlabel "numer iteracji"
set ylabel "mV"
set output '| ps2pdf - output/pict/pot.pdf'
plot "output/pot.dat" u 1:2 w l lw 3 lt 1 lc 8


reset
set output '| ps2pdf - output/pict/nz.pdf'
set key l b
set grid
set xlabel "numer iteracji"
set ylabel "mV"
plot "output/pot_25.dat" u 1:2 w l lw 3 lt 1 lc 8 t "nz = 25", "output/pot_30.dat" u 1:2 w l lw 3 lt 1 lc 2 t "nz = 30", "output/pot_40.dat" u 1:2 w l lw 3 lt 1 lc 5 t "nz = 40", "output/pot_50.dat" u 1:2 w l lw 3 lt 1 lc 4 t "nz = 50", "output/pot_70.dat" u 1:2 w l lw 3 lt 1 lc 9 t "nz = 70"

reset
set output '| ps2pdf - output/pict/nz2.pdf'
set key r b
set grid
set xlabel "nz"
set ylabel "mV"
plot "output/nz.dat" u 1:2 w linespoints lw 7 lt 2 lc 8 pt 7 pi -1 ps 2 t "V(nz)"

