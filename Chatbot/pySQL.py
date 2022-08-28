import pymysql
db = None
try:
  db = pymysql.connect(
    host="localhost",
    port=8982,
    user="homestead",
    passwd="secret1",
    db="homestead",
    charset="utf8"
  )
  print('db 연결 성공')

except Exception as e:
  print(e)

finally:
  if db is not None:
    db.close()
    print("DB 연결 닫기 성공")