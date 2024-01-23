excel <- dir("./FMfinal/Data/")
excel
grade<-excel[grep("^grade_|xlsx&",excel)]
grade
grade_data <- read_excel(paste0("./FMfinal/Data/",grade))
data<-grade_data[2:5]
data$predict <- 0
for (i in colnames(data)[-c(4,5)]){
  tmp<-paste(colnames(data)[4],"~",
             paste(colnames(data)[-c(4,5)],
                   collapse = "+"))
  
}
round2 <- function(x, n) {
  posneg <- sign(x)
  z <- abs(x)*10^n
  z <- z + 0.5 + sqrt(.Machine$double.eps)
  z <- trunc(z)
  z <- z/10^n
  z*posneg
}

dataML<-as.formula(paste(tmp,"-1"))

mS<-lm(dataML, data=data)
s<-summary(mS)
coff<-round2(s$coefficients[,1],2)
coff

for( i in 1:dim(data)[1]){
  data[i,5]<-round2(rowSums(data[i,1:3]*coff),0)
}

mean((as.numeric(data[[5]])-as.numeric(data[[4]]))^2)
