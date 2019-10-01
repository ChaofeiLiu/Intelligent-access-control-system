import pymysql

def db_connect():
    try:
        conn = pymysql.connect(
            host="localhost",
            port=3306,
            user="root",
            password="carr1998",
            database="school",
            charset="utf8",
            cursorclass=pymysql.cursors.DictCursor
        )
        return conn
    except Exception as e:
        print("database connection error %s" %e )

def creat_table(conn,cursor,sql_table):
    try:
        cursor.execute(sql_table)
        conn.commit()
    except Exception as e:
        db_connect().rollback()
        print(e)
    finally:
        cursor.close()
        conn.close()

def insert_data(conn,cursor,data):
    try:
        # 执行一条insert语句，返回受影响的行数
        # cursor.execute("INSERT INTO para5(name,age) VALUES(%s,%s);",('tom','b'))
        # 执行多次insert并返回受影响的行数

        cursor.executemany("INSERT INTO student_demo(name,sex) VALUES(%s,%s);", data)
        # 提交执行
        conn.commit()
    except Exception as e:
        # 如果执行sql语句出现问题，则执行回滚操作
        conn.rollback()
        print(e)
    finally:
        cursor.close()
        conn.close()

def select_data(conn,cursor,size):
    try:
        cursor.execute("SELECT * FROM students2 ;")
        # fetchall：获取所有的数据，默认以元祖的方式返回
        # 如果你指定了cursorclass = pymysql.cursors.DictCursor，则以dict的方式返回
        # result = cursor.fetchall()
        # for row in result:
        #    print("id是%d,name是%s，age是%d"%(row["id"],row["name"],row["age"]))
        # fetchone：获取剩余数据的第一条数据
        result = cursor.fetchmany(size)
        print(result)
        # fetchmany:获取剩余数据的前2条数据
        # result = cursor.fetchmany(2)
        # print(result)
    except Exception as e:
        conn.rollback()
        print(e)
    finally:
        cursor.close()
        conn.close()

def delete(conn,cursor,data):
    try:
        cursor.executemany("delete from student_demo where id in(%s)",data)
        conn.commit()
    except Exception as e:
        conn.rollback()
        print(e)
    finally:
        cursor.close()
        conn.close()

def update(conn,cursor,sql_update):
    try:
        cursor.execute(sql_update)
        conn.commit()
    except Exception as e:
        conn.rollback()
        print(e)
    finally:
        cursor.close()
        conn.close()


def test_insert():
    # 这里请注意 每个定义的操作函数中的 conn 必须作为函数参数引入；不能直接引用 db_connect() 函数
    # 在定义的操作函数内，直接db_connect() 会直接新建一个新的链接返回对象conn
    # 由于新的conn 和 原来生成游标的conn不同
    # 会直接导致 conn.commit() 提交失败，数据库操作无法完成。
    conn = db_connect()
    cursor = conn.cursor()
    data = [('任我行','男'),('任盈盈','女'),('黄蓉','女')]
    insert_data(conn,cursor,data)

def test_delete():
    conn = db_connect()
    cursor = conn.cursor()
    data = [125,130]
    delete(conn,cursor,data)

def test_update():
    conn = db_connect()
    cursor = conn.cursor()
    sql_update = "update student_demo set name = '任盈盈' where id = '127'"
    update(conn,cursor,sql_update)

def main():
    # test_insert()
    # test_delete()
    test_update()

if __name__ == "__main__":
    main()
