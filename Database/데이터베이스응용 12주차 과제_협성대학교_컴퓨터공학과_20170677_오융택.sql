--1. emp 테이블와 동일한 구조로 된 테이블 복사(empcp)
--dept 테이블와 동일한 구조로 된 테이블 복사(deptcp)
create table empcp
as 
select * from emp
where 1=2;

create table deptcp
as 
select * from dept
where 1=2;


--2. emp 테이블에서 dept가 10, 20인 데이터  empcp 테이블에 삽입
--  모든 dept 데이터 deptcp 테이블에 삽입
insert into empcp
select *
from emp
where deptno = 20 or deptno = 10;

insert into deptcp
select *
from dept;

--3. empcp 테이블 empno에 기본키 제약 조건, deptno에 deptcp 테이블의 deptno를 참조하는 외래키 제약   조건 추가
--  (오류 발생 시 원인 이유 설명 및 해결)
alter table empcp
add constraint empcp_empno_pk primary key(empno);
alter table empcp
add constraint empcp_deptno_fk foreign key(deptno) REFERENCES deptcp(deptno)
on delete cascade;
alter table deptcp
add constraint deptcp_deptno_pk primary key(deptno);
-->deptcp 에 기본키가 없습니다. deptcp테이블의 deptno를 기본키로 지정해줍니다


--4. empcp 테이블의 ename에 not null 제약 조건 지정
alter table empcp
modify empno constraint empcp_empno_nn not null;

--5. 사용자 소유의 테이블 목록 조회
select *
from tabs;

--6. 생성된 제약 조건 정보 조회
select constraint_name, constraint_type, table_name
from user_constraints;

--7. empcp 테이블에 새로운 데이터 삽입
--(7777,'hyupsung','CLERK',7782,'2000-01-23',1300,500,50);
--삽입 가능 한가? 오류가 발생했다면 오류 원인은?
insert into empcp
values (7777,'hyupsung','CLERK',7782,'2000-01-23',1300,500,50);
--> 삽입되지 않습니다 무결성 제약조건-parent키가 없기 때문에

--8. exceptions 테이블 생성(@?/rdbms/admin/utlexcpt.sql)
--   sql command line에서 실행
--SQL> conn c##scott
--비밀번호 입력:tiger
--연결되었습니다.
--SQL> @?/rdbms/admin/utlexcpt.sql

--9. empcp 테이블 deptno에 지정된 외래키 제약 조건 비활성화
alter table empcp
disable constraint empcp_deptno_fk;

--10. 다시 empcp 테이블에 새로운 데이터 삽입
--(7777,'hyupsung','CLERK',7782,'2000-01-23',1300,500,50);
--삽입 가능한가?
insert into empcp
values (7777,'hyupsung','CLERK',7782,'2000-01-23',1300,500,50);
-->삽입가능합니다

--11. empcp 테이블 deptno에 지정된 외래키 제약 조건 다시 활성화
--(제약조건에 위배되는 데이터 행은 exceptions 테이블에 저장하도록 지정)
alter table empcp
enable validate constraint empcp_deptno_fk
exceptions into exceptions;

--12. exceptions 테이블 내용 조회
select * from exceptions;

--13. empcp 테이블에서 exceptions 테이블에 기록된 행과 일치하는 데이터(rowid, empno, deptno)을 조회
select rowid, empno, deptno
from empcp
where rowid in (select row_id from exceptions);

--14.위에서 조회된 데이터를 참고하여 무결성 제약조건에 위배되는 데이터 수정 
update empcp
set deptno = 30
where rowid='AAAUexAAHAAAACdAAH';

--15. deptcp 테이블의 기본키 제약 조건 삭제 (참조하는 테이블이 존재할 경우 마지막에 cascade 옵션 사용)
alter table deptcp
drop constraint deptcp_deptno_pk
cascade;

--16. empcp, deptcp 테이블의 모든 데이터 삭제, exceptions 테이블 데이터도 삭제
delete from empcp;
delete from deptcp;
delete from exceptions;
--17. empcp, deptcp 테이블 삭제
drop table empcp;
drop table deptcp;



