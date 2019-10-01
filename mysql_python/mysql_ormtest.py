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
DB_session = sessionmaker(bind= engine)
news_obj = News(
            title= '标ge',
            content= '内容',
            types= '类型'
        )
DB_session = DB_session()
DB_session.add(news_obj)
DB_session.commit()
DB_session.close()