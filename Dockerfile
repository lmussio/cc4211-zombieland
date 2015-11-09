FROM ubuntu
MAINTAINER Leandro Duque Mussio

RUN apt-get update && \
    apt-get install -y cmake cron vim build-essential g++
RUN mkdir -p /start/zattack/
ADD crontask.sh /start/crontask.sh
ADD zattack/ /start/zattack/

WORKDIR /start/
ENTRYPOINT ["./crontask.sh"]
CMD ["1","5"]
