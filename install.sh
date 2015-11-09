#! /bin/bash
path=$( cd "$(dirname "${BASH_SOURCE}")" ; pwd -P )
cd "$path"
if [[ $UID != 0 ]]; then
    sudo ./install.sh
    exit 0
fi
docker build -t lmussio/cc4211 .
cp ./zombieland /etc/init.d/
update-rc.d zombieland defaults 99
service zombieland start
