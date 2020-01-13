

#include<bits/stdc++.h>
using namespace std;
#define inf INT_MAX
#define INF LLONG_MAX
#define ll long long
#define ull unsigned long long
#define M (int)(1e9+7)
#define P pair<int,int>
#define FOR(i,m,n) for(int i=(int)m;i<(int)n;i++)
#define RFOR(i,m,n) for(int i=(int)m;i>=(int)n;i--)
#define rep(i,n) FOR(i,0,n)
#define rrep(i,n) RFOR(i,n,0)
#define all(a) a.begin(),a.end()
const int vx[4] = {0,1,0,-1};
const int vy[4] = {1,0,-1,0};
#define F first
#define S second
#define PB push_back
#define EB emplace_back
#define int ll
#define vi vector<int>
#define IP pair<int,P>
#define PI pair<P,int>
#define PP pair<P,P>
#define Yes(f){cout<<(f?"Yes":"No")<<endl;}
#define YES(f){cout<<(f?"YES":"NO")<<endl;}


const double EPS = 1e-9;

struct Point
{
  double x, y;

  Point() : x( 0 ), y( 0 ) {}
  Point( const double x, const double y ) : x( x ), y( y ) {}
  Point( const Point &a ) : x( a.x ), y( a.y ) {}

  Point operator + ( const Point &a ) const
  {
    return Point( x + a.x, y + a.y );
  }

  Point& operator += ( const Point &a ) 
  {
    x += a.x;
    y += a.y;

    return *this;
  }

  Point operator - ( const Point &a ) const
  {
    return Point( x + ( -a.x ), y + ( -a.y ) );
  }

  Point& operator -= ( const Point &a )
  {
    x -= a.x;
    y -= a.y;

    return *this;
  }

  Point operator * ( const double &a ) const
  {
    return Point( x * a, y * a );
  }

  Point& operator *= ( const double &a )
  {
    x *= a;
    y *= a;

    return *this;
  }

  Point operator / ( const double &a ) const
  {
    return Point( x / a, y / a );
  }

  Point& operator /= ( const double &a )
  {
    x /= a;
    y /= a;

    return *this;
  }

  bool operator < ( const Point &a ) const
  {
    return x == a.x ? y < a.y : x < a.x;
  }

  double abs() const
  {
    return sqrt( pow( x, 2. ) + pow( y, 2. ) );
  }
};

// 二点間の距離
double distance( const Point &a, const Point &b )
{
  return sqrt( pow( a.x - b.x, 2. ) + pow( a.y - b.y, 2. ) );
}

// 内積（ドット積）
double dot( const Point &a, const Point &b )
{
  return a.x * b.x + a.y * b.y;
}

// 外積（クロス積）
double cross( const Point &a, const Point &b )
{
  return a.x * b.y - a.y * b.x;
}

// 凸包を求める（ Graham Scan ）
vector< Point > convexHull( vector< Point > ps )
{
  const int N = ps.size();

  sort( all( ps ) );

  int k = 0;
  vector< Point > convex( N * 2 );

  for ( int i = 0; i < N; i++ )
  {
    while ( 2 <= k && cross( convex[ k - 1 ] - convex[ k - 2 ], ps[i] - convex[ k - 1 ] ) <= EPS )
    {
      k--;
    }

    convex[ k++ ] = ps[i];
  }

  for ( int i = N - 2, t = k; 0 <= i; i-- )
  {
    while ( t < k && cross( convex[ k - 1 ] - convex[ k - 2 ], ps[i] - convex[ k - 1 ] ) <= EPS )
    {
      k--;
    }

    convex[ k++ ] = ps[i];
  }

  convex.resize( k - 1 );

  return convex;
}

// 三角形の最小包含円を求める
double enclosing( Point A, Point B, Point C )
{
  double a = distance( B, C ), b = distance( C, A ), c = distance( A, B );
  
  if ( dot( B - A, C - A ) <= EPS ||
      dot( A - B, C - B ) <= EPS ||
      dot( A - C, B - C ) <= EPS ) // 内積が 0 以下 ⇔ 直角または鈍角の角がある
  {
    return max( a, max( b, c ) ) / 2;
  }
  else
  {
    double cosA = ( pow( b, 2. ) + pow( c, 2. ) - pow( a, 2. ) ) / ( 2 * b * c );
    double sinA = sin( acos( cosA ) );

    return abs( a / sinA ) / 2;
  }
}

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  int n;
  cin>>n;
  vector<Point> v;
  rep(i,n){
    double x,y;
    cin>>x>>y;
    v.PB(Point(x,y));
  }

  if(n==2){
    cout<<distance(v[0],v[1])/2<<endl;
    return 0;
  }

  double ans=0;
  rep(i,n){
    FOR(j,i+1,n){
      FOR(l,j+1,n){
        //cout<<enclosing(v[i],v[j],v[l])<<endl;
        ans=max(ans,enclosing(v[i],v[j],v[l]));
      }
    }
  }

  cout<<ans<<endl;


}
