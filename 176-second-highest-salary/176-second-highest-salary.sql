select
(select distinct salary as SecondHighestSalary from employee order by salary desc limit 1 offset 1) as SecondHighestSalary;

# distinct if(salary is null,null,salary) as SecondHighestSalary

