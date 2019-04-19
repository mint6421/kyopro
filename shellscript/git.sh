#!/bin/sh

#このディレクトリ内で作られたファイルをgitに乗せる


RenameFile(){
  NewFile=~/git/codeforces/"$1"
  mkdir $NewFile

  for file in [a-z].cpp
  do
    cp "$file" "$NewFile"
  done

  cd $NewFile
  if [ $? != 0 ]; then
    echo "Can't Find File ! "
    exit
  fi

  for file in [a-z].cpp
  do
    NewName=`echo "$1${file%.*}"| tr "[a-z]" "[A-Z]"`
    NewName="${NewName}.cpp"
    echo $NewName
    mv "$file" "$NewName"
  done
}

AddGit(){
  cd ../../

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

RenameFile $1
AddGit

echo "./git.sh already finished ! "
