### 注意事項：
## 零、這是成果報告樣板，不是練習樣板。請在其他「.R」練習，有信心了，才把個人練習的成果一步一腳印的搬過來，並且放在適當的位置。
## 一、師長提供的路徑名稱，只能改掉「/home/fcu/ShinyApps/」這一段變成你的機器合法的路徑名。
## 二、各種物件的命名規則必須跟師長一模一樣，要是不一樣，程式抓不到，分數辦不到。
## 三、師長在這一份文件示範五個解釋變數，純粹為了教學，不具任何建模上的實務意義，必須改成自己的創意。
## 四、如果加「類似師長提供的程式碼」，程式碼一定要連同註記(###)一起加起來放在新的、漂亮的、合理的位置。
## 五、如果加「不類似師長提供的程式碼」一定要自行設計加「可讀性高的註記(###)」。
## 六、重點在於發展模型的個人心路歷程。
## 七、請同時撰寫自己的「個人期末小專題」。
## 八、如果「個人期末小專題」充滿程式碼，沒有自己的文字，分數一樣辦不到。
#####################################################################

#####################################################################
# 一、讀取全部或是部分數據####
### 期末考每題得分細節
library(readxl) # 有請套件「readxl」幫忙！
grade <- read_excel("./FMsources/data/insurance/grade_insurance_2015-01-07.xlsx")
x <- grade[, c("ID", "semester_grade")]
colnames(x)[2] <- "y"
### 紀錄抓了什麼欄位
whatIhave <- data.frame(來源 = c("grade_insurance_2015-01-07.xlsx"),
                          欄位 = c("ID", "semester_grade"),
                          建模代碼 = c("ID", "y"),
                          新創欄位 = c(FALSE, FALSE),
                          stringsAsFactors = FALSE)

### 讀取期初調查
Q1 <- read_excel("./FMsources/data/insurance/Q1_insurance_2014-09-24.xlsx")
### 挑選原始數據的解釋變數，「x1, x2, x3, ...」
### 選擇欄位，再併入「x」，並且更新「whatIhave」
x$x1 <- Q1$Q1V9
### 正規化
x$x1 <- (x$x1 - min(x$x1))/(max(x$x1) - min(x$x1))
### 寫入總表
whatIhave <- rbind(whatIhave,
                   c("Q1_insurance_2014-09-24.xlsx",
                     "Q1V9",
                     "x1",
                     FALSE))
### 選擇欄位，再併入「x」，並且更新「whatIhave」
x$x2 <- Q1$Q1V6_3
### 正規化
x$x2 <- (x$x2 - min(x$x2))/(max(x$x2) - min(x$x2))
### 寫入總表
whatIhave <- rbind(whatIhave,
                   c("Q1_insurance_2014-09-24.xlsx",
                     "Q1V6_3",
                     "x2",
                     FALSE))
### 讀取期中調查
Q2 <- read_excel("./FMsources/data/insurance/Q2_insurance_2014-11-19.xlsx")
### 選擇欄位，再併入「x」，並且更新「whatIhave」
x$x3 <- Q2$Q2V2
### 正規化
x$x3 <- (x$x3 - min(x$x3))/(max(x$x3) - min(x$x3))
### 寫入總表
whatIhave <- rbind(whatIhave,
                   c("Q2_insurance_2014-11-19.xlsx",
                     "Q2V2",
                     "x3",
                     FALSE))
### 選擇欄位，再併入「x」，並且更新「whatIhave」
x$x4 <- Q2$Q2V6
### 正規化
x$x4 <- (x$x4 - min(x$x4))/(max(x$x4) - min(x$x4))
### 寫入總表
whatIhave <- rbind(whatIhave,
                   c("Q2_insurance_2014-11-19.xlsx",
                     "Q2V6",
                     "x4",
                     FALSE))
### 選擇欄位，再併入「x」，並且更新「whatIhave」
x$x5 <- Q2$Q2V8
### 正規化
x$x5 <- (x$x5 - min(x$x5))/(max(x$x5) - min(x$x5))
### 寫入總表
whatIhave <- rbind(whatIhave,
                   c("Q2_insurance_2014-11-19",
                     "Q2V8",
                     "x5",
                     FALSE))
### 選擇欄位，再併入「x」，並且更新「whatIhave」
x$x6 <- Q2$Q2V13
### 正規化
x$x6 <- (x$x6 - min(x$x6))/(max(x$x6) - min(x$x6))
### 寫入總表
whatIhave <- rbind(whatIhave,
                   c("Q2_insurance_2014-11-19",
                     "Q2V13",
                     "x6",
                     FALSE))
### 選擇欄位，再併入「x」，並且更新「whatIhave」
x$x7 <- Q2$Q2V14
### 正規化
x$x7 <- (x$x7 - min(x$x7))/(max(x$x7) - min(x$x7))
### 寫入總表
whatIhave <- rbind(whatIhave,
                   c("Q2_insurance_2014-11-19",
                     "Q2V14",
                     "x7",
                     FALSE))
### 選擇欄位，再併入「x」，並且更新「whatIhave」
x$x8 <- Q2$Q2V15
### 正規化
x$x8 <- (x$x8 - min(x$x8))/(max(x$x8) - min(x$x8))
### 寫入總表
whatIhave <- rbind(whatIhave,
                   c("Q2_insurance_2014-11-19",
                     "Q2V15",
                     "x8",
                     FALSE))

### 選擇欄位，再併入「x」，並且更新「whatIhave」
x$x9 <- Q2$Q2V16
### 正規化 

x$x9 <- (x$x9 - min(x$x9))/(max(x$x9) - min(x$x9))
### 寫入總表
whatIhave <- rbind(whatIhave,
                   c("Q2_insurance_2014-11-19",
                     "Q2V16",
                     "x9",
                     FALSE))

### 讀取第一次小考紀錄
quiz1<-read_excel("./FMsources/data/insurance/quiz01_insurance_2014-10-15.xlsx")
### 處理數據(第一題)
quiz1<-as.data.frame(quiz1)
### 轉成數字
quiz1$Q1_1<-as.numeric(quiz1$Q1_1)
### 用平均代替NA
quiz1[which(is.na(quiz1$Q1_1)),2]<-mean(quiz1$Q1_1,na.rm=T)
### 正規化
quiz1$Q1_1<-(quiz1$Q1_1-min(quiz1$Q1_1))/(max(quiz1$Q1_1)-min(quiz1$Q1_1))
### 塞進表
x$x10<-quiz1$Q1_1
whatIhave<-rbind(whatIhave,
                 c("quiz01_insurance_2014-10-15.xlsx",
                   "Q1_1",
                   "x10",
                   FALSE))
### 處理數據(第二題)
### 轉成數字
quiz1$Q1_2<-as.numeric(quiz1$Q1_2)
### 用平均代替NA
quiz1[which(is.na(quiz1$Q1_2)),4]<-mean(quiz1$Q1_2,na.rm=T)
### 正規化
quiz1$Q1_2<-(quiz1$Q1_2-min(quiz1$Q1_2))/(max(quiz1$Q1_2)-min(quiz1$Q1_2))
### 塞進表
x$x11<-quiz1$Q1_2
whatIhave<-rbind(whatIhave,
                 c("quiz01_insurance_2014-10-15.xlsx",
                   "Q1_2",
                   "x11",
                   FALSE))

### 處理數據(第三題)
### 轉成數字
quiz1$Q1_3<-as.numeric(quiz1$Q1_3)
### 用平均代替NA
quiz1[which(is.na(quiz1$Q1_3)),11]<-mean(quiz1$Q1_3,na.rm=T)
### 正規化
quiz1$Q1_3<-(quiz1$Q1_3-min(quiz1$Q1_3))/(max(quiz1$Q1_3)-min(quiz1$Q1_3))
### 塞進表
x$x12<-quiz1$Q1_3
whatIhave<-rbind(whatIhave,
                 c("quiz01_insurance_2014-10-15.xlsx",
                   "Q1_3",
                   "x12",
                   FALSE))
### 處理數據(第四題)
### 轉成數字
quiz1$Q1_4<-as.numeric(quiz1$Q1_4)
### 用平均代替NA
quiz1[which(is.na(quiz1$Q1_4)),5]<-mean(quiz1$Q1_4,na.rm=T)
### 正規化
quiz1$Q1_4<-(quiz1$Q1_4-min(quiz1$Q1_4))/(max(quiz1$Q1_4)-min(quiz1$Q1_4))
### 塞進表
x$x13<-quiz1$Q1_4
whatIhave<-rbind(whatIhave,
                 c("quiz01_insurance_2014-10-15.xlsx",
                   "Q1_4",
                   "x13",
                   FALSE))


### 處理數據(第五題)
### 轉成數字
quiz1$Q1_5<-as.numeric(quiz1$Q1_5)
### 用平均代替NA
quiz1[which(is.na(quiz1$Q1_5)),9]<-mean(quiz1$Q1_5,na.rm=T)
### 正規化
quiz1$Q1_5<-(quiz1$Q1_5-min(quiz1$Q1_5))/(max(quiz1$Q1_5)-min(quiz1$Q1_5))
### 塞進表
x$x14<-quiz1$Q1_5
whatIhave<-rbind(whatIhave,
                 c("quiz01_insurance_2014-10-15.xlsx",
                   "Q1_5",
                   "x14",
                   FALSE))

### 處理數據(第六題)
### 轉成數字
quiz1$Q1_6<-as.numeric(quiz1$Q1_6)
### 用平均代替NA
quiz1[which(is.na(quiz1$Q1_6)),6]<-mean(quiz1$Q1_6,na.rm=T)
### 正規化
quiz1$Q1_6<-(quiz1$Q1_6-min(quiz1$Q1_6))/(max(quiz1$Q1_6)-min(quiz1$Q1_6))
### 塞進表
x$x15<-quiz1$Q1_6
whatIhave<-rbind(whatIhave,
                 c("quiz01_insurance_2014-10-15.xlsx",
                   "Q1_6",
                   "x15",
                   FALSE))

### 處理數據(第七題)
### 轉成數字
quiz1$Q1_7<-as.numeric(quiz1$Q1_7)
### 用平均代替NA
quiz1[which(is.na(quiz1$Q1_7)),8]<-mean(quiz1$Q1_7,na.rm=T)
### 正規化
quiz1$Q1_7<-(quiz1$Q1_7-min(quiz1$Q1_7))/(max(quiz1$Q1_7)-min(quiz1$Q1_7))
### 塞進表
x$x16<-quiz1$Q1_7
whatIhave<-rbind(whatIhave,
                 c("quiz01_insurance_2014-10-15.xlsx",
                   "Q1_7",
                   "x16",
                   FALSE))

### 處理數據(第八題)
### 轉成數字
quiz1$Q1_8<-as.numeric(quiz1$Q1_8)
### 用平均代替NA
quiz1[which(is.na(quiz1$Q1_8)),3]<-mean(quiz1$Q1_8,na.rm=T)
### 正規化
quiz1$Q1_8<-(quiz1$Q1_8-min(quiz1$Q1_8))/(max(quiz1$Q1_8)-min(quiz1$Q1_8))
### 塞進表
x$x17<-quiz1$Q1_8
whatIhave<-rbind(whatIhave,
                 c("quiz01_insurance_2014-10-15.xlsx",
                   "Q1_8",
                   "x17",
                   FALSE))

### 處理數據(第九題)
### 轉成數字
quiz1$Q1_9<-as.numeric(quiz1$Q1_9)
### 用平均代替NA
quiz1[which(is.na(quiz1$Q1_9)),10]<-mean(quiz1$Q1_9,na.rm=T)
### 正規化
quiz1$Q1_9<-(quiz1$Q1_9-min(quiz1$Q1_9))/(max(quiz1$Q1_9)-min(quiz1$Q1_9))
### 塞進表
x$x18<-quiz1$Q1_9
whatIhave<-rbind(whatIhave,
                 c("quiz01_insurance_2014-10-15.xlsx",
                   "Q1_9",
                   "x18",
                   FALSE))


### 處理數據(第十題)
### 轉成數字
quiz1$Q1_10<-as.numeric(quiz1$Q1_10)
### 用平均代替NA
quiz1[which(is.na(quiz1$Q1_10)),7]<-mean(quiz1$Q1_10,na.rm=T)
### 正規化
quiz1$Q1_10<-(quiz1$Q1_10-min(quiz1$Q1_10))/(max(quiz1$Q1_10)-min(quiz1$Q1_10))
### 塞進表
x$x19<-quiz1$Q1_10
whatIhave<-rbind(whatIhave,
                 c("quiz01_insurance_2014-10-15.xlsx",
                   "Q1_10",
                   "x19",
                   FALSE))


### 讀取第二次小考紀錄
quiz2<-read_excel("./FMsources/data/insurance/quiz02_insurance_2014-11-05.xlsx")
### 處理數據(第一題)
quiz2<-as.data.frame(quiz2)
### 轉成數字
quiz2$Q2_1<-as.numeric(quiz2$Q2_1)
### 用平均代替NA
quiz2[which(is.na(quiz2$Q2_1)),5]<-mean(quiz2$Q2_1,na.rm=T)
### 正規化
quiz2$Q2_1<-(quiz2$Q2_1-min(quiz2$Q2_1))/(max(quiz2$Q2_1)-min(quiz2$Q2_1))
### 塞進表
x$x20<-quiz2$Q2_1
whatIhave<-rbind(whatIhave,
                 c("quiz02_insurance_2014-11-05.xlsx",
                   "Q2_1",
                   "x20",
                   FALSE))


### 轉成數字
quiz2$Q2_2a<-as.numeric(quiz2$Q2_2a)
### 用平均代替NA
quiz2[which(is.na(quiz2$Q2_2a)),8]<-mean(quiz2$Q2_2a,na.rm=T)
### 正規化
quiz2$Q2_2a<-(quiz2$Q2_2a-min(quiz2$Q2_2a))/(max(quiz2$Q2_2a)-min(quiz2$Q2_2a))
### 塞進表
x$x21<-quiz2$Q2_2a
whatIhave<-rbind(whatIhave,
                 c("quiz02_insurance_2014-11-05.xlsx",
                   "Q2_2a",
                   "x21",
                   FALSE))

### 轉成數字
quiz2$Q2_2b<-as.numeric(quiz2$Q2_2b)
### 用平均代替NA
quiz2[which(is.na(quiz2$Q2_2b)),6]<-mean(quiz2$Q2_2b,na.rm=T)
### 正規化
quiz2$Q2_2b<-(quiz2$Q2_2b-min(quiz2$Q2_2b))/(max(quiz2$Q2_2b)-min(quiz2$Q2_2b))
### 塞進表
x$x22<-quiz2$Q2_2b
whatIhave<-rbind(whatIhave,
                 c("quiz02_insurance_2014-11-05.xlsx",
                   "Q2_2b",
                   "x22",
                   FALSE))

### 轉成數字
quiz2$Q2_2c<-as.numeric(quiz2$Q2_2c)
### 用平均代替NA
quiz2[which(is.na(quiz2$Q2_2c)),7]<-mean(quiz2$Q2_2c,na.rm=T)
### 正規化
quiz2$Q2_2c<-(quiz2$Q2_2c-min(quiz2$Q2_2c))/(max(quiz2$Q2_2c)-min(quiz2$Q2_2c))
### 塞進表
x$x23<-quiz2$Q2_2c
whatIhave<-rbind(whatIhave,
                 c("quiz02_insurance_2014-11-05.xlsx",
                   "Q2_2c",
                   "x23",
                   FALSE))


### 轉成數字
quiz2$Q2_3<-as.numeric(quiz2$Q2_3)
### 用平均代替NA
quiz2[which(is.na(quiz2$Q2_3)),9]<-mean(quiz2$Q2_3,na.rm=T)
### 正規化
quiz2$Q2_3<-(quiz2$Q2_3-min(quiz2$Q2_3))/(max(quiz2$Q2_3)-min(quiz2$Q2_3))
### 塞進表
x$x24<-quiz2$Q2_3
whatIhave<-rbind(whatIhave,
                 c("quiz02_insurance_2014-11-05.xlsx",
                   "Q2_3",
                   "x24",
                   FALSE))

### 轉成數字
quiz2$Q2_4<-as.numeric(quiz2$Q2_4)
### 用平均代替NA
quiz2[which(is.na(quiz2$Q2_4)),10]<-mean(quiz2$Q2_4,na.rm=T)
### 正規化
quiz2$Q2_4<-(quiz2$Q2_4-min(quiz2$Q2_4))/(max(quiz2$Q2_4)-min(quiz2$Q2_4))
### 塞進表
x$x25<-quiz2$Q2_4
whatIhave<-rbind(whatIhave,
                 c("quiz02_insurance_2014-11-05.xlsx",
                   "Q2_4",
                   "x25",
                   FALSE))

### 轉成數字
quiz2$Q2_5<-as.numeric(quiz2$Q2_5)
### 用平均代替NA
quiz2[which(is.na(quiz2$Q2_5)),2]<-mean(quiz2$Q2_5,na.rm=T)
### 正規化
quiz2$Q2_5<-(quiz2$Q2_5-min(quiz2$Q2_5))/(max(quiz2$Q2_5)-min(quiz2$Q2_5))
### 塞進表
x$x26<-quiz2$Q2_5
whatIhave<-rbind(whatIhave,
                 c("quiz02_insurance_2014-11-05.xlsx",
                   "Q2_5",
                   "x26",
                   FALSE))

### 轉成數字
quiz2$Q2_6<-as.numeric(quiz2$Q2_6)
### 用平均代替NA
quiz2[which(is.na(quiz2$Q2_6)),3]<-mean(quiz2$Q2_6,na.rm=T)
### 正規化
quiz2$Q2_6<-(quiz2$Q2_6-min(quiz2$Q2_6))/(max(quiz2$Q2_6)-min(quiz2$Q2_6))
### 塞進表
x$x27<-quiz2$Q2_6
whatIhave<-rbind(whatIhave,
                 c("quiz02_insurance_2014-11-05.xlsx",
                   "Q2_6",
                   "x27",
                   FALSE))

### 轉成數字
quiz2$Q2_7<-as.numeric(quiz2$Q2_7)
### 用平均代替NA
quiz2[which(is.na(quiz2$Q2_7)),4]<-mean(quiz2$Q2_7,na.rm=T)
### 正規化
quiz2$Q2_7<-(quiz2$Q2_7-min(quiz2$Q2_7))/(max(quiz2$Q2_7)-min(quiz2$Q2_7))
### 塞進表
x$x28<-quiz2$Q2_7
whatIhave<-rbind(whatIhave,
                 c("quiz02_insurance_2014-11-05.xlsx",
                   "Q2_7",
                   "x28",
                   FALSE))

### 讀取第三次小考紀錄
quiz3<-read_excel("./FMsources/data/insurance/quiz03_insurance_2014-12-10.xlsx")

### 處理數據(第一題)
quiz3<-as.data.frame(quiz3)
### 轉成數字
quiz3$Q3_1<-as.numeric(quiz3$Q3_1)
### 用平均代替NA
quiz3[which(is.na(quiz3$Q3_1)),6]<-mean(quiz3$Q3_1,na.rm=T)
### 正規化
quiz3$Q3_1<-(quiz3$Q3_1-min(quiz3$Q3_1))/(max(quiz3$Q3_1)-min(quiz3$Q3_1))
### 塞進表
x$x29<-quiz3$Q3_1
whatIhave<-rbind(whatIhave,
                 c("quiz03_insurance_2014-12-10.xlsx",
                   "Q3_1",
                   "x29",
                   FALSE))

### 轉成數字
quiz3$Q3_2<-as.numeric(quiz3$Q3_2)
### 用平均代替NA
quiz3[which(is.na(quiz3$Q3_2)),10]<-mean(quiz3$Q3_2,na.rm=T)
### 正規化
quiz3$Q3_2<-(quiz3$Q3_2-min(quiz3$Q3_2))/(max(quiz3$Q3_2)-min(quiz3$Q3_2))
### 塞進表
x$x30<-quiz3$Q3_2
whatIhave<-rbind(whatIhave,
                 c("quiz03_insurance_2014-12-10.xlsx",
                   "Q3_2",
                   "x30",
                   FALSE))

### 轉成數字
quiz3$Q3_3<-as.numeric(quiz3$Q3_3)
### 用平均代替NA
quiz3[which(is.na(quiz3$Q3_3)),8]<-mean(quiz3$Q3_3,na.rm=T)
### 正規化
quiz3$Q3_3<-(quiz3$Q3_3-min(quiz3$Q3_3))/(max(quiz3$Q3_3)-min(quiz3$Q3_3))
### 塞進表
x$x31<-quiz3$Q3_3
whatIhave<-rbind(whatIhave,
                 c("quiz03_insurance_2014-12-10.xlsx",
                   "Q3_3",
                   "x31",
                   FALSE))

### 轉成數字
quiz3$Q3_4<-as.numeric(quiz3$Q3_4)
### 用平均代替NA
quiz3[which(is.na(quiz3$Q3_4)),9]<-mean(quiz3$Q3_4,na.rm=T)
### 正規化
quiz3$Q3_4<-(quiz3$Q3_4-min(quiz3$Q3_4))/(max(quiz3$Q3_4)-min(quiz3$Q3_4))
### 塞進表
x$x32<-quiz3$Q3_4
whatIhave<-rbind(whatIhave,
                 c("quiz03_insurance_2014-12-10.xlsx",
                   "Q3_4",
                   "x32",
                   FALSE))

### 轉成數字
quiz3$Q3_5<-as.numeric(quiz3$Q3_5)
### 用平均代替NA
quiz3[which(is.na(quiz3$Q3_5)),11]<-mean(quiz3$Q3_5,na.rm=T)
### 正規化
quiz3$Q3_5<-(quiz3$Q3_5-min(quiz3$Q3_5))/(max(quiz3$Q3_5)-min(quiz3$Q3_5))
### 塞進表
x$x33<-quiz3$Q3_5
whatIhave<-rbind(whatIhave,
                 c("quiz03_insurance_2014-12-10.xlsx",
                   "Q3_5",
                   "x33",
                   FALSE))
### 轉成數字
quiz3$Q3_6<-as.numeric(quiz3$Q3_6)
### 用平均代替NA
quiz3[which(is.na(quiz3$Q3_6)),7]<-mean(quiz3$Q3_6,na.rm=T)
### 正規化
quiz3$Q3_6<-(quiz3$Q3_6-min(quiz3$Q3_6))/(max(quiz3$Q3_6)-min(quiz3$Q3_6))
### 塞進表
x$x34<-quiz3$Q3_6
whatIhave<-rbind(whatIhave,
                 c("quiz03_insurance_2014-12-10.xlsx",
                   "Q3_6",
                   "x34",
                   FALSE))
### 轉成數字
quiz3$Q3_7<-as.numeric(quiz3$Q3_7)
### 用平均代替NA
quiz3[which(is.na(quiz3$Q3_7)),2]<-mean(quiz3$Q3_7,na.rm=T)
### 正規化
quiz3$Q3_7<-(quiz3$Q3_7-min(quiz3$Q3_7))/(max(quiz3$Q3_7)-min(quiz3$Q3_7))
### 塞進表
x$x35<-quiz3$Q3_7
whatIhave<-rbind(whatIhave,
                 c("quiz03_insurance_2014-12-10.xlsx",
                   "Q3_7",
                   "x35",
                   FALSE))

### 轉成數字
quiz3$Q3_8<-as.numeric(quiz3$Q3_8)
### 用平均代替NA
quiz3[which(is.na(quiz3$Q3_8)),5]<-mean(quiz3$Q3_8,na.rm=T)
### 正規化
quiz3$Q3_8<-(quiz3$Q3_8-min(quiz3$Q3_8))/(max(quiz3$Q3_8)-min(quiz3$Q3_8))
### 塞進表
x$x36-quiz3$Q3_8
whatIhave<-rbind(whatIhave,
                 c("quiz03_insurance_2014-12-10.xlsx",
                   "Q3_8",
                   "x36",
                   FALSE))

### 轉成數字
quiz3$Q3_9<-as.numeric(quiz3$Q3_9)
### 用平均代替NA
quiz3[which(is.na(quiz3$Q3_9)),3]<-mean(quiz3$Q3_9,na.rm=T)
### 正規化
quiz3$Q3_9<-(quiz3$Q3_9-min(quiz3$Q3_9))/(max(quiz3$Q3_9)-min(quiz3$Q3_9))
### 塞進表
x$x37<-quiz3$Q3_9
whatIhave<-rbind(whatIhave,
                 c("quiz03_insurance_2014-12-10.xlsx",
                   "Q3_9",
                   "x37",
                   FALSE))

### 轉成數字
quiz3$Q3_10<-as.numeric(quiz3$Q3_10)
### 用平均代替NA
quiz3[which(is.na(quiz3$Q3_10)),4]<-mean(quiz3$Q3_10,na.rm=T)
### 正規化
quiz3$Q3_10<-(quiz3$Q3_10-min(quiz3$Q3_10))/(max(quiz3$Q3_10)-min(quiz3$Q3_10))
### 塞進表
x$x38<-quiz3$Q3_10
whatIhave<-rbind(whatIhave,
                 c("quiz03_insurance_2014-12-10.xlsx",
                   "Q3_10",
                   "x38",
                   FALSE))


### 讀取第一次作業紀錄
hw1<-read_excel("./FMsources/data/insurance/hw01_insurance_2014-10-01.xlsx")
hw1<-as.data.frame(hw1)
### 清洗「hw1」
hw1[,2]<-as.numeric(hw1[,2])
hw1[which(is.na(hw1[,2])),2]<-0
### 選擇欄位，再併入「x」，並且更新「whatIhave」
x$x39<-hw1$hw_ch1
### 正規化 
x$x39 <- (x$x39 - min(x$x39))/(max(x$x39) - min(x$x39))
whatIhave<-rbind(whatIhave,
                 c("hw01_insurance_2014-10-01.xlsx",
                   "hw_ch1",
                   "x39",
                   FALSE))
### 讀取第二次作業紀錄
hw2<-read_excel("./FMsources/data/insurance/hw02_insurance_2014-10-08.xlsx")
hw2<-as.data.frame(hw2)
### 清洗「hw2」
hw2[,2]<-as.numeric(hw2[,2])
hw2[which(is.na(hw2[,2])),2]<-0
### 選擇欄位，再併入「x」，並且更新「whatIhave」
x$x40<-hw2$hw_ch5
### 正規化 
x$x40 <- (x$x40 - min(x$x40))/(max(x$x40) - min(x$x40))
whatIhave<-rbind(whatIhave,
                 c("hw02_insurance_2014-10-08.xlsx",
                   "hw_ch5",
                   "x40",
                   FALSE))
### 讀取第三次作業紀錄
hw3<-read_excel("./FMsources/data/insurance/hw03_insurance_2014-10-22.xlsx")
hw3<-as.data.frame(hw3)
### 清洗「hw3」
hw3[,2]<-as.numeric(hw3[,2])
hw3[which(is.na(hw3[,2])),2]<-0
### 選擇欄位，再併入「x」，並且更新「whatIhave」
x$x41<-hw3$hw_ch9
### 正規化 
x$x41 <- (x$x41 - min(x$x41))/(max(x$x41) - min(x$x41))
whatIhave<-rbind(whatIhave,
                 c("hw03_insurance_2014-10-22.xlsx",
                   "hw_ch9",
                   "x41",
                   FALSE))
### 讀取第四次作業紀錄
hw4<-read_excel("./FMsources/data/insurance/hw04_insurance_2014-10-29.xlsx")
hw4<-as.data.frame(hw4)
### 清洗「hw4」
hw4[,2]<-as.numeric(hw4[,2])
hw4[which(is.na(hw4[,2])),2]<-0
### 選擇欄位，再併入「x」，並且更新「whatIhave」
x$x42<-hw4$hw_ch10
### 正規化 
x$x42 <- (x$x42 - min(x$x42))/(max(x$x42) - min(x$x42))
whatIhave<-rbind(whatIhave,
                 c("hw04_insurance_2014-10-29.xlsx",
                   "hw_ch10",
                   "x42",
                   FALSE))
### 讀取第五次作業紀錄
hw5<-read_excel("./FMsources/data/insurance/hw05_insurance_2014-11-19.xlsx")
hw5<-as.data.frame(hw5)
### 清洗「hw5」
hw5[,2]<-as.numeric(hw5[,2])
hw5[which(is.na(hw5[,2])),2]<-0
### 選擇欄位，再併入「x」，並且更新「whatIhave」
x$x43<-hw5$hw_ch4
### 正規化 
x$x43 <- (x$x43 - min(x$x43))/(max(x$x43) - min(x$x43))
whatIhave<-rbind(whatIhave,
                 c("hw05_insurance_2014-11-19.xlsx",
                   "hw_ch4",
                   "x43",
                   FALSE))
### 讀取第六次作業紀錄
hw6<-read_excel("./FMsources/data/insurance/hw06_insurance_2014-11-26.xlsx")
hw6<-as.data.frame(hw6)
### 清洗「hw6」
hw6[,2]<-as.numeric(hw6[,2])
hw6[which(is.na(hw6[,2])),2]<-0
### 選擇欄位，再併入「x」，並且更新「whatIhave」
x$x44<-hw6$hw_ch11
### 正規化 
x$x44 <- (x$x44 - min(x$x44))/(max(x$x44) - min(x$x44))
whatIhave<-rbind(whatIhave,
                 c("hw06_insurance_2014-11-26.xlsx",
                   "hw_ch11",
                   "x44",
                   FALSE))
### 讀取第七次作業紀錄
hw7<-read_excel("./FMsources/data/insurance/hw07_insurance_2014-12-03.xlsx")
hw7<-as.data.frame(hw7)
### 清洗「hw7」
hw7[,2]<-as.numeric(hw7[,2])
hw7[which(is.na(hw7[,2])),2]<-0
### 選擇欄位，再併入「x」，並且更新「whatIhave」
x$x45<-hw7$hw_ch12
### 正規化 
x$x45 <- (x$x45 - min(x$x45))/(max(x$x45) - min(x$x45))
whatIhave<-rbind(whatIhave,
                 c("hw07_insurance_2014-12-03.xlsx",
                   "hw_ch12",
                   "x45",
                   FALSE))
### 讀取第九次作業紀錄
hw9<-read_excel("./FMsources/data/insurance/hw09_insurance_2014-12-24.xlsx")
hw9<-as.data.frame(hw9)
### 清洗「hw9」
hw9[,2]<-as.numeric(hw9[,2])
hw9[which(is.na(hw9[,2])),2]<-0
### 選擇欄位，再併入「x」，並且更新「whatIhave」
x$x46<-hw9$hw_ch15
### 正規化 
x$x46 <- (x$x46 - min(x$x46))/(max(x$x46) - min(x$x46))
whatIhave<-rbind(whatIhave,
                 c("hw09_insurance_2014-12-24.xlsx",
                   "hw_ch15",
                   "x46",
                   FALSE))
###讀取全部出席紀錄
### 第一次
week1<-read_excel("./FMsources/data/insurance/insurance_2014-10-01.xlsx")
week1<-as.data.frame(week1)
### 第二次
week2<-read_excel("./FMsources/data/insurance/insurance_2014-10-08.xlsx")
week2<-as.data.frame(week2)
### 第三次
week3<-read_excel("./FMsources/data/insurance/insurance_2014-10-15.xlsx")
week3<-as.data.frame(week3)
### 第四次
week4<-read_excel("./FMsources/data/insurance/insurance_2014-10-22.xlsx")
week4<-as.data.frame(week4)
### 第五次
week5<-read_excel("./FMsources/data/insurance/insurance_2014-10-29.xlsx")
week5<-as.data.frame(week5)
### 第六次
week6<-read_excel("./FMsources/data/insurance/insurance_2014-11-05.xlsx")
week6<-as.data.frame(week6)
### 第七次
week7<-read_excel("./FMsources/data/insurance/insurance_2014-11-19.xlsx")
week7<-as.data.frame(week7)
### 第八次
week8<-read_excel("./FMsources/data/insurance/insurance_2014-11-26.xlsx")
week8<-as.data.frame(week8)
### 第九次
week9<-read_excel("./FMsources/data/insurance/insurance_2014-12-03.xlsx")
week9<-as.data.frame(week9)
### 第十次
week10<-read_excel("./FMsources/data/insurance/insurance_2014-12-10.xlsx")
week10<-as.data.frame(week10)
### 第十一次
week11<-read_excel("./FMsources/data/insurance/insurance_2014-12-17.xlsx")
week11<-as.data.frame(week11)
### 第十二次
week12<-read_excel("./FMsources/data/insurance/insurance_2014-12-24.xlsx")
week12<-as.data.frame(week12)
### 第十三次
week13<-read_excel("./FMsources/data/insurance/insurance_2014-12-31.xlsx")
week13<-as.data.frame(week13)
### 清理全部出席紀錄
### 第一次
week1[,2]<-as.numeric(week1[,2])
week1[which(week1[,2]>1|is.na(week1[,2])),2]<-0
week1[,3]<-as.numeric(week1[,3])
week1[which(week1[,3]>1|is.na(week1[,3])),3]<-0
week1[,4]<-as.numeric(week1[,4])
week1[which(week1[,4]>1|is.na(week1[,4])),4]<-0
week1[,5]<-as.numeric(week1[,5])
week1[which(week1[,5]>1|is.na(week1[,5])),5]<-0
### 第二次
week2[,2]<-as.numeric(week2[,2])
week2[which(week2[,2]>1|is.na(week2[,2])),2]<-0
week2[,3]<-as.numeric(week2[,3])
week2[which(week2[,3]>1|is.na(week2[,3])),3]<-0
week2[,4]<-as.numeric(week2[,4])
week2[which(week2[,4]>1|is.na(week2[,4])),4]<-0
week2[,5]<-as.numeric(week2[,5])
week2[which(week2[,5]>1|is.na(week2[,5])),5]<-0
### 第三次
week3[,2]<-as.numeric(week3[,2])
week3[which(week3[,2]>1|is.na(week3[,2])),2]<-0
week3[,3]<-as.numeric(week3[,3])
week3[which(week3[,3]>1|is.na(week3[,3])),3]<-0
week3[,4]<-as.numeric(week3[,4])
week3[which(week3[,4]>1|is.na(week3[,4])),4]<-0
week3[,5]<-as.numeric(week3[,5])
week3[which(week3[,5]>1|is.na(week3[,5])),5]<-0
### 第四次
week4[,2]<-as.numeric(week4[,2])
week4[which(week4[,2]>1|is.na(week4[,2])),2]<-0
week4[,3]<-as.numeric(week4[,3])
week4[which(week4[,3]>1|is.na(week4[,3])),3]<-0
week4[,4]<-as.numeric(week4[,4])
week4[which(week4[,4]>1|is.na(week4[,4])),4]<-0
week4[,5]<-as.numeric(week4[,5])
week4[which(week4[,5]>1|is.na(week4[,5])),5]<-0
### 第五次
week5[,2]<-as.numeric(week5[,2])
week5[which(week5[,2]>1|is.na(week5[,2])),2]<-0
week5[,3]<-as.numeric(week5[,3])
week5[which(week5[,3]>1|is.na(week5[,3])),3]<-0
week5[,4]<-as.numeric(week5[,4])
week5[which(week5[,4]>1|is.na(week5[,4])),4]<-0
week5[,5]<-as.numeric(week5[,5])
week5[which(week5[,5]>1|is.na(week5[,5])),5]<-0
### 第六次
week6[,2]<-as.numeric(week6[,2])
week6[which(week6[,2]>1|is.na(week6[,2])),2]<-0
week6[,3]<-as.numeric(week6[,3])
week6[which(week6[,3]>1|is.na(week6[,3])),3]<-0
week6[,4]<-as.numeric(week6[,4])
week6[which(week6[,4]>1|is.na(week6[,4])),4]<-0
week6[,5]<-as.numeric(week6[,5])
week6[which(week6[,5]>1|is.na(week6[,5])),5]<-0
### 第七次
week7[,2]<-as.numeric(week7[,2])
week7[which(week7[,2]>1|is.na(week7[,2])),2]<-0
week7[,3]<-as.numeric(week7[,3])
week7[which(week7[,3]>1|is.na(week7[,3])),3]<-0
week7[,4]<-as.numeric(week7[,4])
week7[which(week7[,4]>1|is.na(week7[,4])),4]<-0
week7[,5]<-as.numeric(week7[,5])
week7[which(week7[,5]>1|is.na(week7[,5])),5]<-0
### 第八次
week8[,2]<-as.numeric(week8[,2])
week8[which(week8[,2]>1|is.na(week8[,2])),2]<-0
week8[,3]<-as.numeric(week8[,3])
week8[which(week8[,3]>1|is.na(week8[,3])),3]<-0
week8[,4]<-as.numeric(week8[,4])
week8[which(week8[,4]>1|is.na(week8[,4])),4]<-0
week8[,5]<-as.numeric(week8[,5])
week8[which(week8[,5]>1|is.na(week8[,5])),5]<-0
### 第九次
week9[,2]<-as.numeric(week9[,2])
week9[which(week9[,2]>1|is.na(week9[,2])),2]<-0
week9[,3]<-as.numeric(week9[,3])
week9[which(week9[,3]>1|is.na(week9[,3])),3]<-0
week9[,4]<-as.numeric(week9[,4])
week9[which(week9[,4]>1|is.na(week9[,4])),4]<-0
week9[,5]<-as.numeric(week9[,5])
week9[which(week9[,5]>1|is.na(week9[,5])),5]<-0
### 第十次
week10[,2]<-as.numeric(week10[,2])
week10[which(week10[,2]>1|is.na(week10[,2])),2]<-0
week10[,3]<-as.numeric(week10[,3])
week10[which(week10[,3]>1|is.na(week10[,3])),3]<-0
week10[,4]<-as.numeric(week10[,4])
week10[which(week10[,4]>1|is.na(week10[,4])),4]<-0
week10[,5]<-as.numeric(week10[,5])
week10[which(week10[,5]>1|is.na(week10[,5])),5]<-0
### 第十一次
week11[,2]<-as.numeric(week11[,2])
week11[which(week11[,2]>1|is.na(week11[,2])),2]<-0
week11[,3]<-as.numeric(week11[,3])
week11[which(week11[,3]>1|is.na(week11[,3])),3]<-0
week11[,4]<-as.numeric(week11[,4])
week11[which(week11[,4]>1|is.na(week11[,4])),4]<-0
week11[,5]<-as.numeric(week11[,5])
week11[which(week11[,5]>1|is.na(week11[,5])),5]<-0
### 第十二次
week12[,2]<-as.numeric(week12[,2])
week12[which(week12[,2]>1|is.na(week12[,2])),2]<-0
week12[,3]<-as.numeric(week12[,3])
week12[which(week12[,3]>1|is.na(week12[,3])),3]<-0
week12[,4]<-as.numeric(week12[,4])
week12[which(week12[,4]>1|is.na(week12[,4])),4]<-0
week12[,5]<-as.numeric(week12[,5])
week12[which(week12[,5]>1|is.na(week12[,5])),5]<-0
### 第十三次
week13[,2]<-as.numeric(week13[,2])
week13[which(week13[,2]>1|is.na(week13[,2])),2]<-0
week13[,3]<-as.numeric(week13[,3])
week13[which(week13[,3]>1|is.na(week13[,3])),3]<-0
week13[,4]<-as.numeric(week13[,4])
week13[which(week13[,4]>1|is.na(week13[,4])),4]<-0
week13[,5]<-as.numeric(week13[,5])
week13[which(week13[,5]>1|is.na(week13[,5])),5]<-0
### 總出席率(含實習)
week<-data.frame(week1,
                 week2[,2:5],
                 week3[,2:5],
                 week4[,2:5],
                 week5[,2:5],
                 week6[,2:5],
                 week7[,2:5],
                 week8[,2:5],
                 week9[,2:5],
                 week10[,2:5],
                 week11[,2:5],
                 week12[,2:5],
                 week13[,2:5])
week$sum<-apply(week[,2:53],1,sum)
week$rate<-week$sum/ncol(week[,2:53])
week$rate<-(week$rate-min(week$rate))/(max(week$rate)-min(week$rate))

x$x47<-week$rate
whatIhave<-rbind(whatIhave,
                 c(paste("insurance_2014-10-01.xlsx","insurance_2014-10-08.xlsx",
                         "insurance_2014-10-15.xlsx","insurance_2014-10-22.xlsx",
                         "insurance_2014-10-29.xlsx","insurance_2014-11-05.xlsx",
                         "insurance_2014-11-19.xlsx","insurance_2014-11-26.xlsx",
                         "insurance_2014-12-03.xlsx","insurance_2014-12-10.xlsx",
                         "insurance_2014-12-17.xlsx","insurance_2014-12-24.xlsx",
                         "insurance_2014-12-31.xlsx",sep=","),
                   "總出席率(含實習)",
                   "x47",
                   FALSE))
### 實習課總出席率
experiment<-data.frame(week1,
                       week2[,5],
                       week3[,5],
                       week4[,5],
                       week5[,5],
                       week6[,5],
                       week7[,5],
                       week8[,5],
                       week9[,5],
                       week10[,5],
                       week11[,5],
                       week12[,5],
                       week13[,5])
experiment$sum<-apply(experiment[,2:14],1,sum)
experiment$rate<-experiment$sum/ncol(experiment[,2:14])
experiment$rate<-(experiment$rate-min(experiment$rate))/(max(experiment$rate)-min(experiment$rate))

x$x48<-experiment$rate
whatIhave<-rbind(whatIhave,
                 c(paste("insurance_2014-10-01.xlsx","insurance_2014-10-08.xlsx",       
                         "insurance_2014-10-15.xlsx","insurance_2014-10-22.xlsx",      
                         "insurance_2014-10-29.xlsx","insurance_2014-11-05.xlsx",     
                         "insurance_2014-11-19.xlsx","insurance_2014-11-26.xlsx",       
                         "insurance_2014-12-03.xlsx","insurance_2014-12-10.xlsx",       
                         "insurance_2014-12-17.xlsx","insurance_2014-12-24.xlsx",       
                         "insurance_2014-12-31.xlsx",sep=","),
                   "實習課總出席率",
                   "x48",
                   FALSE))


### 原始數據「命名規則」
# 1. 問卷用「Q」，諸如，Q1, Q2, Q3
# 2. 出缺席紀錄用「week」，諸如，week1, week2, week3, ...
# 3. 作業繳交紀錄用「hw」，諸如，hw1, hw2, hw3, ...
# 4. 小考對錯紀錄或是得分紀錄用「quiz」，諸如，quiz1, quiz2, quiz3, ...
# 5. 期中考紀錄用「midterm」
# 6. 期末考紀錄用「final」
# 7. 期末報告用「report」
### 原始數據「命名規則」

### 請特別注意：「變數變換」不列入「新創欄位」。
### 請特別注意：「變數變換」不列入「新創欄位」。
### 請特別注意：「變數變換」不列入「新創欄位」。


# 一、讀取全部或是部分數據####
#####################################################################

#####################################################################
# 二、特徵值工程####
### 新創解釋變數，「x1, x2, x3, ...」(跟原始欄位的解釋變數一起順號)
### 清洗「Q2」
Q2$Q2V9[which(Q2$Q2V9 == "NA")] <- "0"
Q2$Q2V9 <- as.numeric(Q2$Q2V9)
### 我要新創欄位。上課專注度(利用Q2的2 4 6 8 9 題)。
x$x49 <- ((Q2$Q2V8+Q2$Q2V9)/2)/((Q2$Q2V8+Q2$Q2V9)/2 + (Q2$Q2V2+Q2$Q2V4+Q2$Q2V6)/3)
### 正規化
x$x49 <- (x$x49 - min(x$x49))/(max(x$x49) - min(x$x49))
### 寫入總表
whatIhave <- rbind(whatIhave,
                   c("Q2_insurance_2014-11-19",
                     "((Q2$Q2V8+Q2$Q2V9)/2)/((Q2$Q2V8+Q2$Q2V9)/2 + (Q2$Q2V2+Q2$Q2V4+Q2$Q2V6)/3)",
                     "x49",
                     TRUE))
### 主成分分析
### (非常重要)每一次你有新解釋變數，這裡都要「重跑一次」！
pca <- prcomp(x[,-c(1,2)], scale=TRUE)
x$x50<- summary(pca)$x[,"PC1"]
whatIhave <- rbind(whatIhave,
                   c("所有X除去ID及y",
                     "第一主成分",
                     "x50",
                     TRUE))
x$x51<- summary(pca)$x[,"PC2"]
whatIhave <- rbind(whatIhave,
                   c("所有X除去ID及y",
                     "第二主成分",
                     "x51",
                     TRUE))
x$x52<- summary(pca)$x[,"PC3"]
whatIhave <- rbind(whatIhave,
                   c("所有X除去ID及y",
                     "第三主成分",
                     "x52",
                     TRUE))

### 請特別注意：「變數變換」不列入「新創欄位」。
### 請特別注意：「變數變換」不列入「新創欄位」。
### 請特別注意：「變數變換」不列入「新創欄位」。

# 二、特徵值工程####
#####################################################################

#####################################################################
# 三、切割為「80-20」####
testID <- c("D0025361", "D0036251", "D0062728", "D0079729", "D0079937",
            "D0229859", "D0229982", "D0230097", "D0230201", "D0230317",
            "D0230470", "D0269263", "D0275878", "D0275953", "D0276007",
            "D0391809", "D9979704")

trainID <- setdiff(grade$ID, testID)

### (非常重要)每一次你有新解釋變數，這裡都要「重跑一次」！
x.train <- x[which(x$ID %in% trainID),]
x.test <- x[which(x$ID %in% testID),]
# 三、切割為「80-20」####
#####################################################################

#####################################################################
# 四、(01)單一解釋變數的建模工程####
### (非常重要)每一次你有新增解釋變數，這裡都要「重跑一次」！
### 開始大量建模
model <- character(0)
R2 <- numeric(0)
for (Var in colnames(x.train)[-c(1,2)]) {
  FMlm <- as.formula(paste(colnames(x.train)[2], "~", Var))
  model <- c(model, paste(colnames(x.train)[2], "~", Var))
  R2 <- c(R2, summary(lm(FMlm, data = x.train))$r.squared)
}
models01 <- data.frame(model = model, 
                       R2 = R2, 
                       stringsAsFactors = FALSE)

### 請注意，經過師長的實驗與研究，R2最佳模型不一定是預測誤差均方最佳模型！
### 挑R2最佳模型
models01$model[which.max(models01$R2)]

### 接下來用「明碼」表達挑到的模型，並且進行預測與計算預測誤差均方。
### 既然這裡是「明碼」，每一次你有新解釋變數，這裡的「y ~ x5」就有可能需要修正？
bestModel01 <- lm(y ~ x50, data = x.train)
pred01 <- predict(bestModel01, newdata = x.test)
mspe01 <- mean((x.test$y - pred01)^2)
mspe01

### 挑預測誤差均方最佳模型
### 請自行發展相關程式
### 開始大量預測
model <- character(0)
mspe <- numeric(0)
for (Var in colnames(x.train)[-c(1,2)]) {
  FMlm <- as.formula(paste(colnames(x.train)[2], "~", Var))
  model <- c(model, paste(colnames(x.train)[2], "~", Var))
  pred <- predict(lm(FMlm, data = x.train),newdata = x.test)
  mspe <- c(mspe, mean((x.test$y - pred)^2))
}
m1_mspe <- data.frame(model = model, 
                       mspe = mspe, 
                       stringsAsFactors = FALSE)

### 挑mspe最佳模型
m1_mspe$model[which.min(m1_mspe$mspe)]

### 接下來用「明碼」表達挑到的模型，並且進行預測與計算預測誤差均方。
bestmspeModel01 <- lm(y ~ x50, data = x.train)
bestpred01 <- predict(bestmspeModel01, newdata = x.test)
bestmspe01 <- mean((x.test$y - bestpred01)^2)
bestmspe01
# 四、(01)單一解釋變數的建模工程####
#####################################################################

#####################################################################
# 五、(02)雙解釋變數的建模工程####
### (非常重要)每一次你有新增解釋變數，這裡都要「重跑一次」！
### 開始大量建模
model <- character(0)
R2 <- numeric(0)
for (Var1 in colnames(x.train)[-c(1,2)]) {
  for (Var2 in colnames(x.train)[-c(1,2)]) {
    if(Var1 != Var2){
      ### 產生模型的「formula」不只這一個辦法，這個辦法只是師長的示範作法。請自行研發。
      Vars <- sort(c(Var1, Var2))
      modelBefore <- paste("y", "~", Vars[1], "+", Vars[2])
      if(modelBefore %in% model){
        next
      } else {
        FMlm <- as.formula(paste(colnames(x.train)[2], "~", Var1, "+", Var2))
        model <- c(model, paste(colnames(x.train)[2], "~", Var1, "+", Var2))
        R2 <- c(R2, summary(lm(FMlm, data = x.train))$r.squared)  
      }
      
    } else {
      next
    }
    
  }
}
models02 <- data.frame(model = model, 
                       R2 = R2, 
                       stringsAsFactors = FALSE)

### 請注意，經過師長的實驗與研究，R2最佳模型不一定是預測誤差均方最佳模型！
### 挑R2最佳模型
models02$model[which.max(models02$R2)]

### 接下來用「明碼」表達挑到的模型，並且進行預測與計算預測誤差均方
bestModel02 <- lm(y ~ x50 + x51, data = x.train)
pred02 <- predict(bestModel02, newdata = x.test)
mspe02 <- mean((x.test$y - pred02)^2)
mspe02

### 挑預測誤差均方最佳模型
### 請自行發展相關程式
### 開始大量預測
model <- character(0)
mspe <- numeric(0)
for (Var1 in colnames(x.train)[-c(1,2)]) {
  for (Vamspe in colnames(x.train)[-c(1,2)]) {
    if(Var1 != Vamspe){
      ### 產生模型的「formula」不只這一個辦法，這個辦法只是師長的示範作法。請自行研發。
      Vars <- sort(c(Var1, Vamspe))
      modelBefore <- paste("y", "~", Vars[1], "+", Vars[2])
      if(modelBefore %in% model){
        next
      } else {
        FMlm <- as.formula(paste(colnames(x.train)[2], "~", Var1, "+", Vamspe))
        model <- c(model, paste(colnames(x.train)[2], "~", Var1, "+", Vamspe))
        pred <- predict(lm(FMlm, data = x.train),newdata = x.test)
        mspe <- c(mspe, mean((x.test$y - pred)^2))  
      }
      
    } else {
      next
    }
    
  }
}
m2_mspe <- data.frame(model = model, 
                      mspe = mspe, 
                      stringsAsFactors = FALSE)

### 挑mspe最佳模型
m2_mspe$model[which.min(m2_mspe$mspe)]

### 接下來用「明碼」表達挑到的模型，並且進行預測與計算預測誤差均方。
bestmspeModel02 <- lm(y ~ x50 + x51, data = x.train)
bestpred02 <- predict(bestmspeModel02, newdata = x.test)
bestmspe02 <- mean((x.test$y - bestpred02)^2)
bestmspe02

# 五、(02)雙解釋變數的建模工程####
#####################################################################

#####################################################################
# 六、(03)三解釋變數的建模工程####
### (非常重要)每一次你有新增解釋變數，這裡都要「重跑一次」！
### 開始大量建模
model <- character(0)
R2 <- numeric(0)
for (Var1 in colnames(x.train)[-c(1,2)]) {
  for (Var2 in colnames(x.train)[-c(1,2)]) {
    for (Var3 in colnames(x.train)[-c(1,2)]) {
      if(Var1 != Var2 & Var1 != Var3 & Var2 != Var3){
        ### 產生模型的「formula」不只這一個辦法，這個辦法只是師長的示範作法。請自行研發。
        Vars <- sort(c(Var1, Var2, Var3))
        modelBefore <- paste("y", "~", Vars[1], "+", Vars[2], "+", Vars[3])
        if(modelBefore %in% model){
          next
        } else {
          FMlm <- as.formula(paste(colnames(x.train)[2], "~", Var1, "+", Var2, "+", Var3))
          model <- c(model, paste(colnames(x.train)[2], "~", Var1, "+", Var2, "+", Var3))
          R2 <- c(R2, summary(lm(FMlm, data = x.train))$r.squared)
        }
        
      } else {
        next
      }
      
    }
    
  }
  
}
models03 <- data.frame(model = model, R2 = R2, stringsAsFactors = FALSE)
### 請注意，經過師長的實驗與研究，R2最佳模型不一定是預測誤差均方最佳模型！
### 挑R2最佳模型
models03$model[which.max(models03$R2)]

### 接下來用「明碼」表達挑到的模型，並且進行預測與計算預測誤差均方
bestModel03 <- lm(y ~ x47 + x50 + x51, data = x.train)
pred03 <- predict(bestModel03, newdata = x.test)
mspe03 <- mean((x.test$y - pred03)^2)
mspe03

### 挑預測誤差均方最佳模型
### 請自行發展相關程式
### 開始大量預測
model <- character(0)
mspe <- numeric(0)
for (Var1 in colnames(x.train)[-c(1,2)]) {
  for (Var2 in colnames(x.train)[-c(1,2)]) {
    for (Var3 in colnames(x.train)[-c(1,2)]) {
      if(Var1 != Var2 & Var1 != Var3 & Var2 != Var3){
        ### 產生模型的「formula」不只這一個辦法，這個辦法只是師長的示範作法。請自行研發。
        Vars <- sort(c(Var1, Var2, Var3))
        modelBefore <- paste("y", "~", Vars[1], "+", Vars[2], "+", Vars[3])
        if(modelBefore %in% model){
          next
        } else {
          FMlm <- as.formula(paste(colnames(x.train)[2], "~", Var1, "+", Var2, "+", Var3))
          model <- c(model, paste(colnames(x.train)[2], "~", Var1, "+", Var2, "+", Var3))
          pred <- predict(lm(FMlm, data = x.train),newdata = x.test)
          mspe <- c(mspe, mean((x.test$y - pred)^2))  
        }
        
      } else {
        next
      }
      
    }
    
  }
  
}
m3_mspe <- data.frame(model = model, mspe = mspe, stringsAsFactors = FALSE)

### 挑mspe最佳模型
m3_mspe$model[which.min(m3_mspe$mspe)]

### 接下來用「明碼」表達挑到的模型，並且進行預測與計算預測誤差均方。
bestmspeModel03 <- lm(y ~ x40 + x50 + x51, data = x.train)
bestpred03 <- predict(bestmspeModel03, newdata = x.test)
bestmspe03 <- mean((x.test$y - bestpred03)^2)
bestmspe03

# 六、(03)三解釋變數的建模工程####
#####################################################################

#####################################################################
# 七、(final)任意個數解釋變數的建模工程####
### (非常重要)每一次你有新解釋變數，這裡都要「重跑一次」！
### 開始大量建模
### 請自行發展相關程式
model <- character(0)
R2 <- numeric(0)
for (Var1 in colnames(x.train)[-c(1,2)]) {
  for (Var2 in colnames(x.train)[-c(1,2)]) {
    for (Var3 in colnames(x.train)[-c(1,2)]) {
      if(Var1 != Var2 & Var1 != Var3 & Var2 != Var3){
        ### 產生模型的「formula」不只這一個辦法，這個辦法只是師長的示範作法。請自行研發。
        Vars <- sort(c(Var1, Var2, Var3))
        modelBefore <- paste("y", "~", Vars[1], "+", Vars[2], "+", Vars[3])
        if(modelBefore %in% model){
          next
        } else {
          FMlm <- as.formula(paste(colnames(x.train)[2], "~", Var1, "+", Var2, "+", Var3))
          model <- c(model, paste(colnames(x.train)[2], "~", Var1, "+", Var2, "+", Var3))
          R2 <- c(R2, summary(lm(FMlm, data = x.train))$r.squared)
        }
        
      } else {
        next
      }
      
    }
    
  }
  
}
modelsfinal <- data.frame(model = model, R2 = R2, stringsAsFactors = FALSE)
### 請注意，經過師長的實驗與研究，R2最佳模型不一定是預測誤差均方最佳模型！
### 挑R2最佳模型
modelsfinal$model[which.max(modelsfinal$R2)]

### 接下來用「明碼」表達挑到的模型，並且進行預測與計算預測誤差均方
bestModelfinal <- lm(y ~ x47 + x50 + x51, data = x.train)
predfinal <- predict(bestModelfinal, newdata = x.test)
mspefinal <- mean((x.test$y - predfinal)^2)
mspefinal

### 挑預測誤差均方最佳模型
### 請自行發展相關程式
### 開始大量預測
model <- character(0)
mspe <- numeric(0)
for (Var1 in colnames(x.train)[-c(1,2)]) {
  for (Var2 in colnames(x.train)[-c(1,2)]) {
    for (Var3 in colnames(x.train)[-c(1,2)]) {
      if(Var1 != Var2 & Var1 != Var3 & Var2 != Var3){
        ### 產生模型的「formula」不只這一個辦法，這個辦法只是師長的示範作法。請自行研發。
        Vars <- sort(c(Var1, Var2, Var3))
        modelBefore <- paste("y", "~", Vars[1], "+", Vars[2], "+", Vars[3])
        if(modelBefore %in% model){
          next
        } else {
          FMlm <- as.formula(paste(colnames(x.train)[2], "~", Var1, "+", Var2, "+", Var3))
          model <- c(model, paste(colnames(x.train)[2], "~", Var1, "+", Var2, "+", Var3))
          pred <- predict(lm(FMlm, data = x.train),newdata = x.test)
          mspe <- c(mspe, mean((x.test$y - pred)^2))  
        }
        
      } else {
        next
      }
      
    }
    
  }
  
}
mf_mspe <- data.frame(model = model, mspe = mspe, stringsAsFactors = FALSE)

### 挑mspe最佳模型
mf_mspe$model[which.min(mf_mspe$mspe)]

### 接下來用「明碼」表達挑到的模型，並且進行預測與計算預測誤差均方。
bestmspeModelfinal <- lm(y ~ x40 + x50 + x51, data = x.train)
bestpredfinal <- predict(bestmspeModelfinal, newdata = x.test)
bestmspefinal <- mean((x.test$y - bestpredfinal)^2)
bestmspefinal

# 七、(final)任意個數解釋變數的建模工程####
#####################################################################

#####################################################################
# 八、確定完工後，再儲存「whatIhave」並準備上傳檔案####
saveRDS(whatIhave, "./FMfinal/output/data/whatIhave.rds")

# 八、確定完工後，再儲存「whatIhave」並準備上傳檔案####
#####################################################################

#####################################################################
# 九、確定完工後，再儲存「models01, models02, models03, modelsfinal」並準備上傳檔案####
saveRDS(models01, "./FMfinal/output/data/models01.rds")
saveRDS(models02, "./FMfinal/output/data/models02.rds")
saveRDS(models03, "./FMfinal/output/data/models03.rds")
saveRDS(modelsfinal, "./FMfinal/output/data/modelsfinal.rds")
saveRDS(m1_mspe, "./FMfinal/output/data/m1_mspe.rds")
saveRDS(m2_mspe, "./FMfinal/output/data/m2_mspe.rds")
saveRDS(m3_mspe, "./FMfinal/output/data/m3_mspe.rds")
saveRDS(mf_mspe, "./FMfinal/output/data/mf_mspe.rds")

# 九、確定完工後，再儲存「models01, models02, models03, modelsfinal」並準備上傳檔案####
#####################################################################

#####################################################################
# 十、確定完工後，再儲存「bestModel01, bestModel02, bestModel03, bestModelfinal」並準備上傳檔案####
saveRDS(bestModel01, "./FMfinal/output/data/bestModel01.rds")
saveRDS(bestModel02, "./FMfinal/output/data/bestModel02.rds")
saveRDS(bestModel03, "./FMfinal/output/data/bestModel03.rds")
saveRDS(bestModelfinal, "./FMfinal/output/data/bestModelfinal.rds")
saveRDS(bestmspe01, "./FMfinal/output/data/bestmspeModel01.rds")
saveRDS(bestmspe02, "./FMfinal/output/data/bestmspeModel02.rds")
saveRDS(bestmspe03, "./FMfinal/output/data/bestmspeModel03.rds")
saveRDS(bestmspefinal, "./FMfinal/output/data/bestmspeModelfinal.rds")


# 十、確定完工後，再儲存「bestModel01, bestModel02, bestModel03, bestModelfinal」並準備上傳檔案####
#####################################################################

