#!/usr/bin/env bash

# the following forces apt-get to be entirely non-interactive
DEBIAN_FRONTEND=noninteractive apt-get -y -o Dpkg::Options::="--force-confdef" -o Dpkg::Options::="--force-confold" upgrade
apt-get update -y
apt-get install -y gcc
apt-get install -y gdb
apt-get install -y git
apt-get install -y make
apt-get install -y python
apt-get install -y valgrind

echo "cd /vagrant" >> /home/vagrant/.bashrc
