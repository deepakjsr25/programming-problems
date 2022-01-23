select DISTINCT num as ConsecutiveNums FROM
(select num,
	case 
		when @record = num then @count:=@count+1
		when @record <> @record:=num then @count:=1 end as n
    from 
	    Logs ,(select @count:=0,@record:=(SELECT num from Logs limit 1)) r #this select statement is only for initialization it will only give you count:=0 and @record:=1;
) a
where a.n>=3;