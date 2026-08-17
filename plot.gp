set title "Generated value by ram0"
set xlabel "index"
set ylabel "value"
set terminal png size 800,600
set output "result.png"
plot "result.txt" using 1:2 with points pt 7 ps 0.5 notitle
