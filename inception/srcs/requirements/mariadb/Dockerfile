FROM    debian:buster

COPY    ./tools/init.sh /tmp/
COPY    ./conf/my.cnf /tmp/
COPY    ./conf/wp-saved.sql /tmp/

RUN     apt-get update && \
        apt-get install -y mariadb-server mariadb-client dumb-init && \
        chmod 111 /tmp/init.sh && \
        mv ./tmp/my.cnf /etc/mysql/my.cnf && \
        chmod 0444 /etc/mysql/my.cnf

ENTRYPOINT ["/usr/bin/dumb-init"]

EXPOSE  3306

CMD     ["/tmp/init.sh"]
