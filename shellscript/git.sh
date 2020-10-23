#!/bin/sh

#このディレクトリ内で作られたcppファイルをgit内のcodeforcesディレクトリに乗せる


CopyFiles(){
  NewDir=~/git/codeforces/"$1"
  mkdir $NewDir

  for file in [a-z].cpp
  do
    cp "$file" "$NewDir"

    if [ $? != 0 ]; then
      echo "Can't copy File ! "
      exit
    fi

  done

  cd $NewDir
}

RenameFiles() {
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
  git commit -m `date "+%Y/%m/%d"`


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
RenameFiles $1
AddGit

echo "./git.sh already finished ! "
