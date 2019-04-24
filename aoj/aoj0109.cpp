#include<bits/stdc++.h>
using namespace std;
typedef string::const_iterator State;

int expression(State &begin);

int term(State &begin);

int factor(State &begin);

int number(State &begin);

void consume(State &begin,char expected);

int main(){
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    string s;
    cin>>s;
    State begin = s.begin();
    int ans=expression(begin);
    consume(begin,'=');
    cout<<ans<<endl;
  }

}


int number(State &begin){
  int ret = 0;

  while(isdigit(*begin)){
    ret *= 10;
    ret += *begin - '0';
    begin++;
  }
  return ret;
}


int factor(State &begin){
  if(*begin =='('){
    consume(begin,'(');
    int ret = expression(begin);
    consume(begin,')');
    return ret;
  }
  else{
    return number(begin);
  }
}


int term(State &begin){
  int ret = number(begin);

  for(;;){
    if(*begin =='*'){
      consume(begin,'*');
      ret *= factor(begin);
    }
    else if(*begin =='/'){
      consume(begin,'/');
      ret /= factor(begin);
    }
    else break;
  }

  return ret;
}


int expression(State &begin){
  int ret = term(begin);

  for(;;){
    if(*begin =='+'){
      consume(begin,'+');
      ret += term(begin);
    }
    else if(*begin =='-'){
      consume(begin,'-');
      ret -= term(begin);
    }
    else break;
  }
  return ret;
}



void consume(State &begin, char expected) {
  if (*begin == expected) {
    begin++;
  } else {
    cerr << "Expected '" << expected << "' but got '" << *begin << "'"
      << endl;
    cerr << "Rest string is '";
    while (*begin) {
      cerr << *begin++;
    }
    cerr << "'" << endl;
  }
}
