# SELECT
#     s1.id, COALESCE(s2.student, s1.student) AS student
# FROM
#     seat s1
#         LEFT JOIN
#     seat s2 ON ((s1.id + 1) ^ 1) - 1 = s2.id
# ORDER BY s1.id;


select if(s1.id%2<>0,if((select s2.id from seat as s2 where s2.id=s1.id+1) is not null,s1.id+1,s1.id),s1.id-1) as id,student from seat as s1 order by id asc;