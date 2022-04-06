j=k-1;
while(i<j){
while(i<j && arr[j]==arr[j-1]){
j--;
}
if(arr[i]+arr[j]+arr[k]==target){
cnt+=(pre_i*pre_j*pre_k);
}
else{
pre_j=0;
}
j--;
}
if((j+1)<k && arr[i]+arr[j+1]+arr[k]>=target){
k--;
if(pre_k>=3 && (3*pre_k)==target){
}
pre_k=1;
}
else{
i++;
if(pre_i>=3 && (3*pre_i)==target){
}
pre_i=1;
}
}
return cnt;
}
};