--1.jones 보다 많은 봉급을 받는 사원명, 직급 검색
select ename 사원명, job 직급
from emp
where sal > (select sal from emp where ename = 'JONES');

--2. 직속상사가 'jones'인 사원의 사원명, 입사일, 소속부서명 검색
select e.ename 사원명, e.hiredate 입사일, d.dname 소속부서명
from emp e join dept d on e.deptno = d.deptno
where mgr = (select empno from emp where ename = 'JONES');

-- 3. 부서명 RESEARCH에 소속된 사원명, 봉급 검색(서브쿼리, exists 사용)
select ename 사원명, sal 봉급
from emp
where exists (select * from dept where emp.deptno = dept.deptno and dept.dname = 'RESEARCH');

-- 4. 30번에 근무하는 사원들의 모든 급여보다 많은 급여를 받는 사원명
select ename 사원명
from emp 
where sal > (select sum(sal) from emp where deptno = 30);


-- 5. 직급별 최소봉급을 받는 사원명, 봉급 검색
select job 직급, ename 사원명, min(sal) 봉급
from emp
group by job;
