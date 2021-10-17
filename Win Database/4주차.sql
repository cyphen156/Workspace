-- 일반함수
-- 사원명, 봉급, 커미션, 연봉(봉급*12+comn)
--nvl, nvl2색
select ename, sal, comm, nvl2(comm, 'Yes', 'No') 비고
from emp;

--decode('sel', '', '')/case문 == case when '' end
select ename, deptno, decode(deptno, 10, '10번부서소속')
from emp;
select ename, job, decode(job, 'CLERK', sal*0.05, 'SALESMAN', sal*0.1, sal*0.03) DECODE문,
case when job = 'CLERK' then sal*0.05 when job = 'SALESMAN' then sal*0.1 else  sal*0.03 end CASE문
from emp;

--사원명, 입사일, 입사시기(분기)
--select ename, hiredate, hiredate 입사시기(분기)
--from emp;

--regexp_like
select regexp_replace(ename, '$', '*') 사원명, regexp_replace(hiredate, '/', '-') 입사일
from emp;

--regexp_count
select ename, sal, regexp_count(ename, 'S') "S문자갯수", regexp_count(sal, 0) "0의갯수"
from emp;