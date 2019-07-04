sink('test.log')

cat("test start\n")

cat("\nlimpiar todo el enviroment de r antes de comenzar\n")
rm(list=ls())

cat("\nlibrería para que read_table2 funcione\n")
library(readr)

cat("\ncargar los resultados como numeros\n")
cat("abrierto\n")
open <- read_table2("data-open.csv",
    locale = locale(decimal_mark = ","))
open

cat("\n\nwap\n")
wap <- read_table2("data-wpa-aes.csv",
    locale = locale(decimal_mark = ","))
wap

cat("\n\nwap2\n")
wap2 <- read_table2("data-wpa2-aes.csv",
    locale = locale(decimal_mark = ","))
wap2

# ver los resultados en una ventana aparte
View(open)
View(wap)
View(wap2)


cat("\n\n=============================\n")
cat("Open Pruebas de normalidad con Shapiro-Wilk\n")
cat("=============================\n")

shapiro.test(open$'1mb.mp4')
shapiro.test(open$'2mb.mp4')
shapiro.test(open$'5mb.mp4')
shapiro.test(open$'10mb.mp4')
shapiro.test(open$'1m.txt')
shapiro.test(open$'3m.txt')
shapiro.test(open$'5m.txt')
shapiro.test(open$'10m.txt')
shapiro.test(open$'1m.png')
shapiro.test(open$'3mb.png')
shapiro.test(open$'5mb.png')
shapiro.test(open$'10mb.png')

cat("\n\n=============================\n")
cat("WPA Pruebas de normalidad con Shapiro-Wilk\n")
cat("=============================\n")

shapiro.test(wap$'1mb.mp4')
shapiro.test(wap$'2mb.mp4')
shapiro.test(wap$'5mb.mp4')
shapiro.test(wap$'10mb.mp4')
shapiro.test(wap$'1m.txt')
shapiro.test(wap$'3m.txt')
shapiro.test(wap$'5m.txt')
shapiro.test(wap$'10m.txt')
shapiro.test(wap$'1m.png')
shapiro.test(wap$'3mb.png')
shapiro.test(wap$'5mb.png')
shapiro.test(wap$'10mb.png')

cat("\n\n=============================\n")
cat("WPA2 Pruebas de normalidad con Shapiro-Wilk\n")
cat("=============================\n")

shapiro.test(wap2$'1mb.mp4')
shapiro.test(wap2$'2mb.mp4')
shapiro.test(wap2$'5mb.mp4')
shapiro.test(wap2$'10mb.mp4')
shapiro.test(wap2$'1m.txt')
shapiro.test(wap2$'3m.txt')
shapiro.test(wap2$'5m.txt')
shapiro.test(wap2$'10m.txt')
shapiro.test(wap2$'1m.png')
shapiro.test(wap2$'3mb.png')
shapiro.test(wap2$'5mb.png')
shapiro.test(wap2$'10mb.png')

# sink()
# sink('test.log', append=TRUE)

cat("\n\n=============================\n")
cat("Pruebas de student-t\n")
cat("=============================\n")

cat("\nopen contra los otros")
cat("\n1mb\n")
t.test(open$'1mb.mp4', wap$'1mb.txt')
t.test(open$'1mb.mp4', wap$'1mb.png')
t.test(open$'1mb.mp4', wap2$'1mb.txt')
t.test(open$'1mb.mp4', wap2$'1mb.png')

cat("\ndos mb de mp4 no se copara contra tres mb de los otros\n")

cat("\n5mb\n")
t.test(open$'5mb.mp4', wap$'5mb.txt')
t.test(open$'5mb.mp4', wap$'5mb.png')
t.test(open$'5mb.mp4', wap2$'5mb.txt')
t.test(open$'5mb.mp4', wap2$'5mb.png')

cat("\n10mb\n")
t.test(open$'10mb.mp4', wap$'10mb.txt')
t.test(open$'10mb.mp4', wap$'10mb.png')
t.test(open$'10mb.mp4', wap2$'10mb.txt')
t.test(open$'10mb.mp4', wap2$'10mb.png')

sink()
