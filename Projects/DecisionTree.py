#!/usr/bin/env python
# coding: utf-8

# In[2]:


from sklearn import datasets
from sklearn.model_selection import train_test_split
from sklearn.tree import DecisionTreeClassifier
from sklearn.tree import export_graphviz


# In[51]:


iris =datasets.load_iris()
#x_train,x_test,y_train,y_test=train_test_split(iris.data,iris.target,random_state=0)
import pandas as pd
iris2=pd.DataFrame(iris.data)
iris2.columns=['sl','sw','pl','pw']
iris2["target"]=iris.target
a=iris2[iris2.target==0].target.count()
b=pd.DataFrame(iris.target)
len(iris2)
a=iris2[iris2["sl"]==10]
b=a[a.target==0].target.count()
iris2["sl"]
#(a.target).count()
#b=iris2.drop("sl",axis=1)
#c=list(iris2.sl)
#set(iris2.target)
#len(iris2.target)

#v=iris.feature_names

iris


# In[4]:


algo=DecisionTreeClassifier()
algo.fit(x_train,y_train)
#algo.fit(x_test,y_test)

y_predtrain=algo.predict(x_train)
y_predtest=algo.predict(x_test)
y_predtrain
y_predtest.shape


# In[5]:


from sklearn.metrics import confusion_matrix 
confusion_matrix(y_predtrain,y_train)
confusion_matrix(y_predtest,y_test)


# In[14]:


import pydotplus
dot_data=export_graphviz(algo,out_file=None,feature_names=iris.feature_names,class_names=iris.target_names)
graph=pydotplus.graph_from_dot_data(dot_data)
graph.write_pdf("iris.pdf")
# This will store Decision tree of iris datset in pdf form.
