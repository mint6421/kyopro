#!/bin/sh

while true
do
  git add *
  git commit -m `date "+%Y/%m/%d"`

  Username=$(openssl rsautl -decrypt -inkey ~/.ssh/id_rsa -in ~/key/user.rsa)
  Password=$(openssl rsautl -decrypt -inkey ~/.ssh/id_rsa -in ~/key/pass.rsa)

  expect -c "
  spawn git push
  expect Username\ ; send $Username; send \r
  expect Password\ ; send $Password; send \r;
  expect eof
  "


  sleep 300

done

