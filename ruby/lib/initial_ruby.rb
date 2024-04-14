require 'net/http'
require 'uri'
require 'json'


def say_hello
  puts "Hello, Foxes!" * 3
end
say_hello()

def fib(n)
  if n < 2
    n
  else
    fib(n - 1) + fib(n - 2)
  end
end

puts fib(20)

def login(uri, username, password)
  header = {'Content-Type': 'text/json'}
  uri = URI.parse(uri)

  user = {
    "username": username,
    "password": password
  }

  http = Net::HTTP.new(uri.host, uri.port)
  http.use_ssl = true # For HTTPS
  request = Net::HTTP::Post.new(uri.request_uri, header)
  request.body = user.to_json
  response = http.request(request)
  puts response.body
end

username = "admin"
password = "success-password"
uri = "https://json-placeholder.mock.beeceptor.com/login"

login(uri, username, password)
