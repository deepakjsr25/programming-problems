# Write your MySQL query statement below
# select ,s.student from (select id,student from seat where id%2=0) s,(select id,student from seat where id%2<>0) ss; 


select if(s.id%2=0 or s.id<(select count(id) from seat),if(s.id%2=0,s.id-1,s.id+1),s.id) as id,s.student from seat as s order by id;
# select s.student,ss.student from seat as s,seat as ss;