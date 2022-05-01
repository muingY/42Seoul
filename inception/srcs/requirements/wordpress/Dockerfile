FROM    debian:buster

RUN     apt-get update && \
        apt-get install -y php-fpm php-mysql curl dumb-init tar && \
        echo "listen = 9000" >> /etc/php/7.3/fpm/pool.d/www.conf && \
        curl -LO https://wordpress.org/latest.tar.gz && \
        tar xzvf latest.tar.gz

COPY    ./tools/init.sh /tmp
COPY    ./conf/wp-config.php /tmp

ENTRYPOINT ["/usr/bin/dumb-init"]

EXPOSE  9000

CMD     ["bash", "/tmp/init.sh"]
