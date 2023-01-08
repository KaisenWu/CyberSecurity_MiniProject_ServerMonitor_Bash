SERVER_LIST="conf/server.txt"
readarray -t SERVERS < $SERVER_LIST

function getUserNum {
	awk -F: '{ print $1 }' /etc/passwd | uniq | wc -l
}

function getUserList {
	awk -F: '{ print $1 }' /etc/passwd | uniq
}

function getUserInfo {
	for server in ${SERVERS[@]}; do
		if [ $server == "localhost" ]; then
			userNum=$(getUserNum)
			userList=$(getUserList)
			echo "There are $userNum users under $server."
			echo "The users list are as follows: "
			echo $userList
			echo
		elif [ $server == "Ubuntu2204-CSIS3560" ]; then
			userNum=`ssh $server cat /etc/passwd | awk -F: '{ print $1 }' | uniq | wc -l` 
			userList=`ssh $server cat /etc/passwd | awk -F: '{ print $1 }' | uniq`
			echo "There are $userNum users under $server."
			echo "The users list are as follows: "
			echo $userList
			echo
		else
			echo "$server is not a valid one."
		fi
	done
}


