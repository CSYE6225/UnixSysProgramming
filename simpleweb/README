#Building a super simple web application on the cloud
We will build a Flask-based application. The Falsk app will connect a Redis server for write and read operations
###Launch a VM
###Install some packages
sudo apt-get -y install build-essential python-pip python-dev install tcl8.5

sudo pip install --upgrade pip

sudo pip install --upgrade virtualenv

sudo pip install Redis

sudo pip install Flask

sudo apt-get -y install python-virtualenv



####Install Redis server:
wget http://download.redis.io/releases/redis-stable.tar.gz

tar xzf redis-stable.tar.gz

cd redis-stable/

 make
 
 make test
 
 sudo make install
 
 cd utils
 
 sudo ./install_server.sh
 
 sudo service redis_6379 start
 
 ####Deploy a simple web app
 Create a Flask project
 
 mkdir ~/csye6225

cd csye6225

virtualenv venv

. venv/bin/activate

Copy the file hello.py to ~/csye6225

export FALSK_APP=hello.py

flask run --host=0.0.0.0

Try to go access your website (using the public IP you got from GCE). Also, pat attention to the port as well. Flask default is 5000.

