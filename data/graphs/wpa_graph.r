library(readr)

data <- read_table2("wpa.csv",
    locale = locale(decimal_mark = ","))

max_y <- max(data)

plot_colors <- c("blue","red","forestgreen")

png(filename="wpa.png", height=395, width=400, bg="white")

plot(data$mp4, type="o", col=plot_colors[1],
   ylim=c(0,max_y), axes=FALSE, ann=FALSE)

axis(1, at=1:4, lab=c("1mb", "3mb", "5mb", "10mb"))

axis(2, las=2, labels=NULL)

box()

lines(data$txt, type="o", pch=22, lty=2,
   col=plot_colors[2])

lines(data$png, type="o", pch=23, lty=3,
   col=plot_colors[3])

title(main="WPA", col.main="red", font.main=4)
title(xlab= "Tamaño", col.lab=rgb(0,0.5,0))
title(ylab= "Tiempo (s)", col.lab=rgb(0,0.5,0))

legend(1, max_y, names(data), cex=0.8, col=plot_colors,
   pch=21:23, lty=1:3);

dev.off()
