#!/bin/bash
SERVER_LIST="conf/server.txt"
readarray -t SERVERS < $SERVER_LIST

function getDiskSpace {
for server in ${SERVERS[@]}; do
		if [ $server == "localhost" ]; then
			rootInfo=`du -h /root 2>/dev/null`
			echo "The root disk space in $server is: "
			echo $rootInfo
			echo
		elif [ $server == "Ubuntu2204-CSIS3560" ]; then
			userNum=`ssh $server du -h /root 2>/dev/null` 
			echo "The root disk space in  $server is: "
			echo $rootInfo
			echo
		else
			echo "$server is not a valid one."
		fi
	done
}

