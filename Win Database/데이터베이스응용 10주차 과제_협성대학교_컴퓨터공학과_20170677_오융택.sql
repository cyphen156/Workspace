--10th_실습활동         
-- 1.사원명, 소속부서명, 직급, 봉급을 검색하는 view(view_ed) 생성
create or replace view view_ed
as
select ename, dname, job, sal
from emp e, dept d
where d.deptno = e.deptno;

-- 2.생성된 뷰을 활용하여 3명이상 소속사원이 있는 부서들의 부서명, 사원수, 평균급여 검색 
select dname 부서명, count(dname) 사원수, avg(sal) 평균급여
from view_ed
group by dname;

-- 3. 사용자가 생성한 뷰 정보 조회
desc user_views;

-- 4. 1에서 생성된 뷰 삭제
drop view view_ed;

-- 5. 생성된 뷰를 통해 새로운 사원 정보(이름, 봉급, 직급)를 입력해보자, 삽입가능한가?
insert into view_ed(ename, sal, job) values ("오융택", 1500, "salesman");
--삽입되지 않습니다 Why? dname정보가 입력되지 않아서??

-- 6. 가장 최근에 입사한 사원 5명의 정보(사원명, 직급, 소속부서번호, 입사일) 검색
-- 인라인 뷰 사용
select *
from (select ename 사원명, job 직급, deptno 소속부서번호, hiredate 입사일
from emp 
order by hiredate desc)
where rownum <= 5;

-- 7.1981년대에 입사한 사원들의 사원명, 봉급, 소속부서평균봉급 검색
-- 스칼라 서브쿼리 사용
select ename 사원명, sal 봉급, (select avg(sal) from emp e where e.deptno = d.deptno) 소속부서평균봉급
from emp e, dept d
where to_char(hiredate, 'yyyy') = 1981 and e.deptno = d.deptno;

-- 8. 소속사원이 있는 부서명 검색(다중행 서브쿼리, exists 서브쿼리 사용) 
select dname
from dept d
where exists (select dname
from emp e where d.deptno = e.deptno)

