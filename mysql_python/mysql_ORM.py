# Integer  整数
# Float  浮点数
# Boolean  布尔值
# ForeignKey   外界
# Date/DateTime
# String  字段
from sqlalchemy import create_engine
from sqlalchemy.ext.declarative import declarative_base
from sqlalchemy import Column,String,Integer,DateTime,Boolean
from sqlalchemy.orm import sessionmaker

HOSTNAME = 'localhost'
PORT = '3306'
DATABASE = 'new_demo'
USERNAME = 'root'
PASSWORD = 'carr1998'
CHARSET = 'charset'
db_url = "mysql+pymysql://{}:{}@{}:{}/{}?{}".format(USERNAME, PASSWORD,HOSTNAME, PORT, DATABASE,CHARSET)
engine = create_engine(db_url)
Base = declarative_base(engine)

class News(Base):
    __tablename__ = 'news'
    id = Column(Integer,primary_key=True,autoincrement=True)
    title = Column(String(200),nullable=False)
    content = Column(String(3000), nullable=False)
    types = Column(String(10), nullable=False)
    image = Column(String(300), )
    author= Column(String(10), )
    view_count = Column(Integer)
    create_time = Column(DateTime)
    is_valid = Column(Boolean)
News.metadata.create_all()
Session = sessionmaker(bind= engine)

class Ormtest():

    def __init__(self):
        self.session = Session()

    def add_one(self):
        news_obj = News(
            title= '标题',
            content= '内容',
            types= '类型'
        )
        # session.add_all(list)
        self.session.add(news_obj)
        self.session.commit()
        return news_obj

    def get_one(self,pk):
        return self.session.query(News).get(pk)

    def get_more(self):
        return self.session.query(News).filter_by(title = '标题')
        # 用filter()  则为 filter(title == '标题')

    def update_data(self,pk):
        new_obj = self.session.query(News).get(pk)
        # 如需修改多条数据 可以利用filter_by 获得datalist，再用for 循环遍历更改
        if new_obj:
            new_obj.is_valid = 0
            self.session.add(new_obj)
            self.session.commit()
            return True
        return False

    def delete_data(self,pk):
        new_obj = self.session.query(News).get(pk)
        if new_obj:
            self.session.delete(new_obj)
            self.session.commit()
            return True
        else:
            return "Not Exist"

def test_add_one():
    obj = Ormtest()
    rs = obj.add_one()
    print(rs.id)

def test_get_one():
    obj = Ormtest()
    rs = obj.get_one(9)
    if rs:
        print("ID: {0}  Title: {1}".format(rs.id, rs.title))
    else:
        print('Not exist')

def test_get_more():
    obj = Ormtest()
    rs = obj.get_more()
    print(rs.count())
    if rs:
        for new_obj in rs:
            print("ID: {0}  Title: {1}".format(new_obj.id,new_obj.title))
    else:
        print("Not exist")

def test_update():
    obj = Ormtest()
    print(obj.update_data(2))

def test_delete():
    obj = Ormtest()
    print(obj.delete_data(9))


# test_add_one()
# test_get_one()
# test_get_more()
# test_update()
test_delete()