select if(s.id%2=0 or s.id<(select count(id) from seat),if(s.id%2=0,s.id-1,s.id+1),s.id) as id,s.student from seat as s order by id;