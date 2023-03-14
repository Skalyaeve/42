FROM debian:buster

RUN apt -y update && apt -y upgrade && apt install -y nginx wget vim curl

COPY nginx.conf /etc/nginx/nginx.conf

COPY www /www

CMD ["nginx", "-g", "daemon off;"]