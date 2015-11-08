FROM ubuntu
MAINTAINER Leandro Duque Mussio

RUN apt-get update && \
    apt-get install -y cron vim
ADD crontask.sh /crontask.sh

VOLUME /tmp
CMD ["/crontask.sh"]
