FROM debian:buster

RUN apt-get update && \
	apt-get -y install mariadb-client php7.3 php-fpm php-mysqli wget sudo dumb-init

RUN wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
	chmod +x wp-cli.phar && \
	sudo mv wp-cli.phar /usr/local/bin/wp && \
	mkdir -p /var/www/html && \
	wp core download --allow-root --path=/var/www/html

COPY ./conf/www.conf /etc/php/7.3/fpm/pool.d/www.conf
COPY ./tools /tmp

RUN chmod +x /tmp/script.sh
ENTRYPOINT ["/usr/bin/dumb-init", "--", "/tmp/script.sh"]