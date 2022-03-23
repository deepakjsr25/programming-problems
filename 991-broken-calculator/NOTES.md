if(startValue==1){
return v[startValue]=1+func(startValue*2,target,dp,v);
}
int op1;
int op2;
// if(dp[startValue-1]==-1){
op1=1+func(startValue-1,target,dp,v);//1,3
// }
// if(dp[startValue*2]==-1){
op2=1+func(startValue*2,target,dp,v);//4,3
// }
return dp[startValue]=min(op1,op2);
}
};
​
//2-->1,4
//3-->2,6
//4-->3,8
//5-->4,10
​
//target=n
//n+1 , n/2;
//odd = n+1
//even = n+1 , n/2;