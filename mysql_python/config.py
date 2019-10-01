from sqlalchemy import create_engine
from sqlalchemy.ext.declarative import declarative_base
from sqlalchemy import Column,String,Integer,DateTime,Boolean
from sqlalchemy.orm import sessionmaker

HOSTNAME = 'localhost'
PORT = '3306'
DATABASE = 'tmall'
USERNAME = 'root'
PASSWORD = 'carr1998'
CHARSET = 'utf8'
db_url = "mysql+pymysql://{}:{}@{}:{}/{}?{}".format(USERNAME, PASSWORD,HOSTNAME, PORT, DATABASE,CHARSET)
engine = create_engine(db_url)
Base = declarative_base(engine)
# Integer  整数
# Float  浮点数
# Boolean  布尔值
# ForeignKey   外界
# Date/DateTime
# String  字段
class Product(Base):
    __tablename__ = 'product'
    id = Column(Integer,primary_key=True,autoincrement=True)
    title = Column(String(200),nullable=False)
    price = Column(Integer, nullable=False)
    deal = Column(String(10), nullable=False)
    image = Column(String(300), )
    shop = Column(String(100), )
    location = Column(String(300))
    create_time = Column(DateTime)

Product.metadata.create_all()
Session = sessionmaker(bind= engine)
session = Session()
