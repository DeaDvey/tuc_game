text=$(curl -s http://35.178.252.18/last-chat-message)
last_text=$(cat ./talking/last-message.txt)

if [ "$text" == "$last_text" ]; then
    exit
elif [ "$text" != "$last_text" ]; then
    echo -e -n "\n\n$text\n\n>> "
    echo "$text" > ./talking/last-message.txt
fi
