-- 5TH 실습활동

-- 1. 직급별 사원이 3명 이상인 직급에 한하여 직급별 최대급여, 인원수 검색

select job 직급, max(sal) 최대급여, count(ename) 인원수
from emp
group by job 
having count(ename) >= 3;


-- 2. 직급별 평균봉급, 부서번호별 평균봉급, 전체 평균봉급 검색

select job 직급, deptno 부서번호, round(avg(sal)) 평균봉급
from emp
group by grouping sets(job, deptno, ());


-- 3. 직급별 부서별 평균봉급, 직급별 평균봉급, 부서번호별 평균봉급, 전체 평균봉급 검색
select job 직급, deptno 부서번호, round(avg(sal)) 평균봉급
from emp
group by grouping sets((job, deptno), deptno, job, ())
order by job, deptno;


-- 4. 직급별 사원명을 입사순서대로 가로로 출력 
select job 직급, listagg(ename, ',') within group (order by hiredate)사원명
from emp
group by job
order by job;