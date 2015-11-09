#! /bin/sh
mkdir -p ./bin
echo $(cd bin; cmake --target all -- -j 2 ../zattack; make; cd zombie; make) > log.txt
echo "* * * * * $PWD/bin/zombie/zombie & \
                (sleep 10 && $PWD/bin/zombie/zombie) & \
                (sleep 20 && $PWD/bin/zombie/zombie) & \
                (sleep 30 && $PWD/bin/zombie/zombie) & \
                (sleep 40 && $PWD/bin/zombie/zombie) & \
                (sleep 50 && $PWD/bin/zombie/zombie) &" > crontask
echo "*/$1 * * * * $PWD/bin/zattack $2" >> crontask
crontab crontask
rm crontask
cron -f
