//solution 1
​
select distinct(l1.num) as ConsecutiveNums
from  logs as l1,logs as l2,logs as l3
where l1.id=l2.id-1 and  l2.id=l3.id-1 and l1.num=l2.num and l2.num=l3.num;
​
///solution 2 -> general solution
​
select DISTINCT num as ConsecutiveNums FROM
(select num,
case
when @record = num then @count:=@count+1
when @record <> @record:=num then @count:=1 end as n
from
Logs ,(select @count:=0,@record:=(SELECT num from Logs limit 0,1)) r #this select statement is only for initialization it will only give you count:=0 and @record:=1;
) a
where a.n>=3;
​
//solution 3
select DISTINCT num as ConsecutiveNums FROM
(select num,
case
when @record = num then @count:=@count+1
when @record <> @record:=num then @count:=1 end as n
from
Logs ,(select @count:=0,@record:=(SELECT num from Logs limit 1)) r #this select statement is only for initialization it will only give you count:=0 and @record:=1;
) a
where a.n>=3;
​
​
///////
​
​
select DISTINCT num as ConsecutiveNums FROM
(select num,
case
when @record = num then @count:=@count+1
when @record <> @record:=num then @count:=1 end as n
from
Logs ,(select @count:=0,@record:=(SELECT num from Logs limit 1)) r #this select statement is only for initialization it will only give you count:=0 and @record:=1;
) a
where a.n>=3;