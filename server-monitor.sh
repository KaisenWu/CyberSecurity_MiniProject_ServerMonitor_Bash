#!/bin/bash

echo "Kaisen Wu 300341264"
echo "Script name: server-monitor_kwu41264.sh"

source inc/rootdisk-info.inc
source inc/user-info.inc

SERVER_LIST="conf/server.txt"
readarray -t SERVERS < $SERVER_LIST

function displayServers {
	echo "The servers are: ${SERVERS[@]}"
}

function menu {
	echo "
	Please Select:
	1) List of servers
	2) Display user info
	3) Display disk space
	4) Exit
	"
	read -p "Enter selection [1-4] > " REPLY

	case $REPLY in
		4)	echo "Thank you. Bye!"
			exit
			;;
		1)	displayServers; menu;;
		2)	getUserInfo; menu;;
		3)	getDiskSpace; menu;;
		*)	echo "Invalid entry" >&2;
			exit 1
			;;
	esac

}

menu

