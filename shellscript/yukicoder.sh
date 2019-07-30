#!/bin/sh

#このディレクトリ内で作られたcppファイルをgit内のyukicoderディレクトリに乗せる


CopyFiles(){

  NewDir=~/git/yukicoder

  cp "$1" "$NewDir"


  cd $NewDir
}


AddGit(){
  cd ../

  git add *
  git commit -m "add new file"

  Username=$(openssl rsautl -decrypt -inkey ~/.ssh/id_rsa -in ~/key/user.rsa)
  Password=$(openssl rsautl -decrypt -inkey ~/.ssh/id_rsa -in ~/key/pass.rsa)

  expect -c "
  spawn git push
  expect Username\ ; send $Username; send \r
  expect Password\ ; send $Password; send \r;
  expect eof
  "

}

CopyFiles $1
AddGit

echo "./git.sh already finished ! "
