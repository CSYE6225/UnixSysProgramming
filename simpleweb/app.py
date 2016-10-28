from flask import Flask
from redis import Redis
import os
import socket
app = Flask(__name__)
host=socket.gethostname()

@app.route('/')
def hello():
  try:
     redis = Redis(host='redis-master', port=6379, socket_connect_timeout=1)
     redis.incr('hits')
  except:
     return "Failed to connect to redis"
  return 'Hello World! - I have been seen %s times. My Hostname is %s' % (redis.get('hits'), host)

if __name__ == "__main__":
  app.run(host="0.0.0.0", port=8080)
