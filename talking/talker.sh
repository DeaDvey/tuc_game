#!/bin/bash
input=$1
webpage=http://35.178.252.18/

#make sure that input has no spaces and instead it has %20
curl --data "chat-box=$1&press=Go" http://35.178.252.18/submit-chat
