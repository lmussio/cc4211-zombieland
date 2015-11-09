#! /bin/bash
if [[ $UID != 0 ]]; then
    sudo $0 $*
    exit 0
fi
docker build -t lmussio/cc4211 .
cp ./zombieland /etc/init.d/
update-rc.d zombieland defaults 99
service zombieland start
