第一题
最小点积和，将向量分别按升序和降序排序，对应维度相乘得到的积是最小的。
证明：4个数a,b,c,d，其中  a < b; c < d；这样有：
 ac+bd  > ad + bc <=> (b-a)(d-c) > 0
 所以任意这样的从向量x,y中挑两个数，他们乘的时候顺序都应该是相反的，否则可以得到更小的值。从而可以反正得到，两个向量分别应该对应相反的排序，之后相乘。

第二题
有点匹配的意思，制作奶昔有N种，其中每种又分了两种（加或者不加麦芽处理），在制作的时候只能采取一种方式，并且要求加麦芽处理的batch最小。
每个用户需要的种类以及加麦芽的方式不一样，如何找到最小代价，符合要求的匹配？
题目要求：每个用户至少有一个喜欢的type，至多有一个type是malted。如果仅有一个，并且是malted，那么优先满足；如果有多个，有一个是malted，先看那个type是否已经标记，标记可以略过，未标记则看unmalted，如果unmalted不能满足，那么则为impossible。

第三题
