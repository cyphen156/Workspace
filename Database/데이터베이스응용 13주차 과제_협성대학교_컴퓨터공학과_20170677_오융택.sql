--1. 인덱스 생성
-- emp테이블의 job 칼럼에 인덱스를 생성 (사용자가 인덱스명 지정)
create index emp_job
on emp(job);
-- 생성된 인덱스 정보 확인
select table_name, index_name from user_indexes where table_name = 'EMP';
-- 위에서 생성된 인덱스 삭제
drop index emp_job;

--2. 봉급 최소값을 검색하기 위한 질의문을 정렬(order by 절)을 사용하지 않고 인덱스를 활용하여 검색
create index emp_sal
on emp(sal);

select sal
from emp
where sal > '0' and rownum = 1;

--3. 시퀀스 생성
-- emp 테이블의 empno열에 유일한 값을 생성해서 삽입하기 위한 시퀀스 생성 
--시작값 : 2107001
--증가값 : 1
--최대값 : 2107100
--nocycle 
create sequence emp_empno_seq_uk
increment by 1
start with 2107001
MAXVALUE 2107100
MINVALUE 2107001
NOCYCLE;


-- 시퀀스를 이용하여 emp 테이블에 새로운 행을 삽입
create table emp_empno
as 
select empno
from emp
where 1=2;
insert into emp_empno
values(EMP_EMPNO_SEQ_UK.nextval);

-- 현재까지 생성된 시퀀스 값 조회
SELECT *
FROM user_sequences;

--4. 계층형 질의
-- jones 사원을 시작으로 부하 직원 목록 검색 (sys_connect_by_path 활용)
select level, ename, empno, mgr, sys_connect_by_path(ename, '/') enamepath
from emp
start with ename = 'JONES'
connect by prior empno = mgr;
-- smith를 기준으로 상사 목록 검색
select level, ename, empno, mgr, sys_connect_by_path(ename, '/') enamepath
from emp
start with ename = 'SMITH'
connect by empno = PRIOR MGR;
-- 계층 데이터에서 LEAF 노드(관리사원이 있는 사원들에 한하여)가 아닌 사원들의 사원명, 봉급 검색 (king을 기준으로 순방향 전개)
-- connect_by_isleaf 사용
select level, ename, empno, mgr, sys_connect_by_path(ename, '/') enamepath
from emp
where CONNECT_BY_ISLEAF = 0
start with mgr is null
connect by prior empno = mgr;


--계층형 쿼리를 활용하여 사원명, 관리자명을 검색(동일 레벨에서는 ename순으로 출력되도록)            
select level, ename 사원명, prior ename 관리자명, sys_connect_by_path(ename, '/') enamepath
from emp
start with mgr is null
connect by prior empno = mgr
order by level, 관리자명, ename;


