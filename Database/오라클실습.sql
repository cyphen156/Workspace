select distinct job || 'Àº' || ename
from emp;
select ename || '(' || job || '), ' || ename || '''job'''
from emp;

select ename, hiredate
from emp
where hiredate >= '85/01/01';