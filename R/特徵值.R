library(readxl)
PWD <- "./FMfinal/Data/"
EXCEL <- dir(PWD)
#???
  FL_Ques<-EXCEL[grep("^Q._|xlsx&",EXCEL)]
  FL_quiz<-EXCEL[grep("^quiz|xlsx&",EXCEL)]
  FL_HW <-EXCEL[grep("^hw|xlsx&",EXCEL)]
  FL_attend<-EXCEL[grep("^insurance_|xlsx&",EXCEL)]
  
  RES_quiz <- read_excel(paste0(PWD,FL_quiz[1]))
  RES_quiz2<-read_excel(paste0(PWD,FL_quiz[2]))
  RES_Q1 <- read_excel(paste0(PWD, FL_Ques[1]))
  RES_Q2<-read_excel(paste0(PWD,FL_Ques[2]))
  #?p??
    for( colname in colnames(RES_quiz)[-1]){
      RES_quiz[[colname]]<-as.numeric(gsub("NA",0,RES_quiz[[colname]]))
    }
    rm(colname)
    for( colname in colnames(RES_quiz2)[-1]){
      RES_quiz2[[colname]]<-as.numeric(gsub("NA",0,RES_quiz2[[colname]]))
    }
    rm(colname)
  
  # ?@?~
    for (file_name in FL_HW){
      FR <- read_excel(paste0(PWD ,file_name))
      FR[[2]][which(FR[c(2)]=="NA")] <- 0
      if(file_name==FL_HW[1]){
        DT_HW<-data.frame("ID"=FR$ID)
      }
      DT_HW<-merge(DT_HW,FR, by="ID")
      rm(FR,file_name)
    }



#???S?x(?D?[)
  #???
    #Q1
      #??????
        STE_interest<-data.frame("ID"=RES_Q1$ID,"interest"=0)
        STE_interest[which(RES_Q1$Q1V7_2 == 1 | RES_Q1$Q1V7_3 == 1),2]<-1
    #Q2
      #???{?u?{??
        DT_notSerious <- as.data.frame(cbind(RES_Q2$Q2V2 , RES_Q2$Q2V4, RES_Q2$Q2V6))
        names(DT_notSerious)<-c("Q2","Q4","Q6")
        DT_notSerious$Q2<-as.numeric(DT_notSerious$Q2)
        DT_notSerious$Q4<-as.numeric(DT_notSerious$Q4)
        DT_notSerious$Q6<-as.numeric(DT_notSerious$Q6)
        STE_notSerious<-as.data.frame(cbind(RES_Q2$ID,rowSums(DT_notSerious)/3))
        names(STE_notSerious)<-c("ID","STE_notSerious")
        STE_notSerious$STE_notSerious <- as.numeric(STE_notSerious$STE_notSerious)
      #?{?u?{??
        DT_Serious <- as.data.frame(cbind(RES_Q2$Q2V8 , RES_Q2$Q2V9))
        names(DT_Serious)<-c("Q8","Q9")
        DT_Serious$Q9[which(DT_Serious$Q9=="NA")]<-0
        DT_Serious$Q8<-as.numeric(DT_Serious$Q8)
        DT_Serious$Q9<-as.numeric(DT_Serious$Q9)
        STE_Serious<-as.data.frame(cbind(RES_Q2$ID,rowSums(DT_Serious)/2))
        names(STE_Serious)<-c("ID","STE_Serious")
        STE_Serious$STE_Serious <- as.numeric(STE_Serious$STE_Serious)
      #?W??M?`??
        STE_forcus <- data.frame("ID"=DT_allAttend$ID,"STE_forcus"=0)
        STE_forcus$STE_forcus<-as.numeric(STE_Serious$STE_Serious)/as.numeric(STE_Serious$STE_Serious)+as.numeric(STE_notSerious$STE_notSerious)
      #??????p(?G?i?????F)
        DT_Book <- as.data.frame(cbind(RES_Q2$Q2V12_1, RES_Q2$Q2V12_2, RES_Q2$Q2V12_3, RES_Q2$Q2V12_4))
        STE_Book<-as.data.frame(cbind(RES_Q2$ID,colSums(t(DT_Book)* c(8,4,2,1))))
        names(STE_Book)<-c("ID","STE_Book")
        STE_Book$STE_Book <- as.numeric(STE_Book$STE_Book)
        
  #?X?u(STE_attend(?C?????X?u???p?G?i??))
      for (file_name in FL_attend){
        FR <- read_excel(paste0(PWD ,file_name))
        FR[which(FR[c(2)]>=2)%%dim(FR)[1],c(2)]<-0
        FR[which(FR[c(3)]>=2)%%dim(FR)[1],c(3)]<-0
        FR[which(FR[c(4)]>=2)%%dim(FR)[1],c(4)]<-0
        FR[which(FR[c(5)]>=2)%%dim(FR)[1], c(5)]<-0
        if(file_name==FL_attend[1]){
          DT_allAttend<-data.frame("ID"=FR$ID)
          DT_experiment<-data.frame("ID"=FR$ID)
          STE_attend<-data.frame("ID"=FR$ID)
        }
        STE_attend<-cbind(STE_attend, colSums(t(FR[c(2,3,4)])* c(4,2,1)))
        DT_allAttend<-merge(DT_allAttend,FR, by="ID")
        DT_experiment<-merge(DT_experiment,FR[c(1,5)], by="ID")
        rm(FR,file_name)
      }
      names(STE_attend)<-c("ID",paste0("v",c(1:8)))

#????
    #?`?X?u?v(?t????)
      PER_allAttend <- data.frame("ID"=DT_allAttend$ID,"allAttend"=0)
    #????X?u?v
      PER_experiment <- data.frame("ID"=DT_experiment$ID,"PER_EX"=0)
    #?@?~ú?????
      SUM_HW <- data.frame("ID"=DT_HW$ID,"SUM_HW"=0)
    #?p???`??
      SUM_quiz1 <- data.frame("ID"=RES_quiz$ID,"quiz1"=0)
      SUM_quiz2 <- data.frame("ID"=RES_quiz2$ID,"quiz2"=0)
    for (i in 1:dim(DT_allAttend)[1]){
      PER_allAttend$allAttend[i]<-mean(as.numeric(DT_allAttend[i,-1]))
      PER_experiment$PER_EX[i]<-mean(as.numeric(DT_experiment[i,-1]))
      SUM_HW$SUM_HW[i]<-sum(as.numeric(DT_HW[i,-1]))
      SUM_quiz1$quiz1[i]<-sum(as.numeric(RES_quiz[i,-1]))
      SUM_quiz2$quiz2[i]<-sum(as.numeric(RES_quiz2[i,-1]))
    }
      
      