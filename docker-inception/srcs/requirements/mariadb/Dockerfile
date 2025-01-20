FROM debian:buster

RUN apt-get update && \
	apt-get -y install mariadb-server dumb-init

COPY ./conf/50-server.cnf /etc/mysql/mariadb.conf.d/
COPY ./tools /tmp

RUN chmod +x /tmp/script.sh

ENTRYPOINT ["/usr/bin/dumb-init", "--", "/tmp/script.sh"]