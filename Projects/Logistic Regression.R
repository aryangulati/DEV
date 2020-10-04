# Logistic Regression 
# import data set from R
data("mtcars")
mtcars
lg= glm(formula = vs~wt+disp, data = mtcars, family = "binomial")

# prediction  of  data
# create new data set 

newdata = data.frame(wt=2.1, disp=180)

#predict value

predict(lg, newdata, type ="response")

# other example logistic 

data1=read.table('http://quantedu.com/wp-content/uploads/2014/04/SAT.txt',header=T)
head(data1,2)
data1$Race=factor(data1$Race)
mylogit <- glm(Admit ~ SAT + GPA + Race, data = data1, family = "binomial")
newdata = data.frame(SAT=1600, GPA=4, Race=factor(1))
predict(mylogit, newdata, type="response") 
newdata1 = data.frame(SAT=1600, GPA=4, Race=factor(2))
predict(mylogit, newdata1, type="response") 


exp(cbind(OR = coef(mylogit), confint(mylogit)))


# Multinominal Logistic Regression


a1= "http://quantedu.com/wp-content/uploads/2014/05/d1.txt"
m11=read.table(a1,header=T)
m11$prog2 <- relevel(m11$prog, ref = "honors")
m2=multinom(prog2 ~ ses + write+read+math, data = m11)
w1=mean(m11$write); r1= mean(m11$read); ma1= mean(m11$math)
newdata = data.frame(ses = c("low", "middle", "high"), write = w1, read= r1, math= ma1 )
newdata
predict(m2, newdata, "probs")
exp(coef(m2));exp(confint(m2))
head(m11)
head(m11,5)

write.csv(m11, file = "course.csv")

# ordinal Logistic

rm(list=ls())
require(MASS)
d1=read.table("http://quantedu.com/wp-content/uploads/2014/04/hSchool.txt",header=T)
head(d1,2);d1$Apply=factor(d1$Apply)
m=polr(Apply ~ pared + public + gpa, data = d1, Hess = TRUE)
n1 = data.frame(pared=1, public=1,  gpa=3.7)
predict(m, n1, type="probs") 
n2 = data.frame(pared=0, public=1,  gpa=3.7)
predict(m, n2, type="probs") 
exp(cbind(OR = coef(m), confint(m)))

#data save in csv file
write.csv(d1, file = "Studentrecords.csv")
