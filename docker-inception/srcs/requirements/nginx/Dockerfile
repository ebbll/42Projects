FROM debian:buster

RUN apt-get update && \
	apt-get -y install nginx openssl dumb-init && \
	openssl req -newkey rsa:4096 -nodes -x509 -keyout /etc/ssl/private/localhost.dev.key -out /etc/ssl/certs/localhost.dev.crt -days 365 -subj "/C=KR/ST=Seoul/L=Gangnam/O=42Seoul/OU=eunlee/CN=eunlee.42.fr"

COPY ./tools /tmp
COPY ./conf/default /etc/nginx/sites-available/default

RUN chmod +x /tmp/script.sh

EXPOSE 443

ENTRYPOINT ["/usr/bin/dumb-init", "--", "/tmp/script.sh"]
