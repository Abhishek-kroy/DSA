# Write your MySQL query statement below
-- update ans 
select s.student_id,s.student_name,sub.subject_name,coalesce(t.cnt,0) as attended_exams from students s cross join subjects sub left join 
(select e.student_id, e.subject_name,count(e.student_id) as cnt from examinations e
group by e.student_id,e.subject_name) as t
on s.student_id = t.student_id and sub.subject_name=t.subject_name
order by s.student_id,sub.subject_name
-- set ans.attended_exams as 0 where ans.attended_exams is null    