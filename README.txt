# Temperature-and-humidity
live visualization of temperature and humidity data and comparision of past data with present data using django and mysql


Requirements

pip install django==5.1.1
pip install pymysql
pip install serial
pip install pyserial
pip install twilio
pip install mysqlclient

Versions

mysql -version 15.1
python -version 3.12.4
django -version 5.1.1


Steps to follow:
1.Install all requirements above 
2.Create a twilio account and register one mobile number
3.Go to settings in django file and replace auth_token,account_sid,twilio number with your number
4.Go to views.py and give the correct port (for e.g:COM5) which was shown in your arudino ide
5.In views.py,under fetch_data give your registered mobile number to recieve message
6.In mysql -> create database : dht_11
7.Now in Terminal
	- Python manage.py makemigrations
	- Python manage.py migrate
	- Python manage.py runserver




