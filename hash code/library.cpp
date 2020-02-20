#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef pair<ll,ll> lll;

const ll MOD = 1000000007;
const ll INF = 1e9+5;
const double eps = 1e-7;
const double PI = acos(-1.0);

#define FOR(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define RFOR(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
#define ull unsigned long long
#define deb(x )     cerr << #x << " = "<< x << endl;
#define endl    "\n"
#define coud(a,d) cout << fixed << showpoint << setprecision(d) << a;
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fill(x, y) memset(x, y, sizeof(y))
#define all(x) (x).begin(), (x).end()
#define bitcount(x) __builtin_popcount(x)
#define cps CLOCKS_PER_SEC
#define verify(x) if(x >= MOD) x -= MOD;

inline void debug_vi(vi a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
inline void debug_vll(vll a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
inline void print_case(int tn) {cout<<"Case #"<<tn<<": ";}

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

template<typename T>
using maxpq = priority_queue<T>;
/*----------------------------------------------------------------------*/

struct book {
    int id, score;
    vi libraries; // libraries containing a copy of this book.

    book(int _id, int _score) {
        id = _id;
        score = _score;
    }
};

struct library
{
    int id, signup_time, limit, num_books; // library id, time to signup and daily limit
    vector<int> books; // id of books in this library
    ll total_score;
    
    library(int _id, int tm, int lim, int _num_books) {
        id = _id; signup_time = tm; limit = lim; num_books = _num_books;
        total_score = 0;
    }
};

int days, l, b; // total
vector<book> books;
vector<library> libraries;
vi signup_order;
set<ii> available_books; // score and id of books for scanning.
int signup_idx, next_signup_time; // idx of library about to get signed up.
vector<bool> isScanned;
vector<bool> isSignedup;

// result variables
vector<vi> books_scanned; // books scanned by each library

// order of signup
bool comp(int aa, int bb) {
    library a = libraries[aa];
    library b = libraries[bb];
    ll ascore = a.num_books * a.limit / a.signup_time;
    ll bscore = b.num_books * b.limit / b.signup_time;
    return ascore > bscore;
}

void input() {
    cin>>b>>l>>days;
    
    isScanned.resize(b, false);
    isSignedup.resize(l, false);
    books_scanned.resize(l);
    
    FOR(i, 0, b) {
        int s; cin>>s;
        books.pb(book(i, s));   
    }
    
    FOR(i, 0, l) {
        int n,t,m;
        cin>>n>>t>>m;
        libraries.pb(library(i, t, m, n));
        signup_order.pb(i);
        
        int bid;
        FOR(j, 0, n) {
            cin>>bid;
            libraries[i].books.push_back(bid);
            libraries[i].total_score += (ll)books[bid].score;
            books[bid].libraries.push_back(i);
        }
    }
    
    sort(all(signup_order), comp);
}

void signup(library &lib) {
    for(int bs : lib.books) {
        if(!isScanned[bs]) {
            // cerr<<"Inserting book id: "<<bs<<" into available books"<<endl;
            available_books.insert({books[bs].score, bs});
        }
    }
    
    next_signup_time += lib.signup_time;
    signup_idx++;
}

ll total_score = 0;

void scan(int ls, int bs) {
    // cerr<<"Scanning book id: "<<bs<<" from library id: "<<ls<<endl;
    books_scanned[ls].pb(bs);
    total_score += books[bs].score;
}

void solve() {
    next_signup_time = 0, signup_idx = 0;
    
    FOR(curr_day, 0, days) {
        // scan the books
        vi counter(l);
        vii books_scanned_this_round;
        
        for(ii itr : available_books) {
            int bs = itr.ss;
            // cerr<<"Looking to scan book id: "<<bs<<endl;
            // vi ls;
          
            int ls = -1;
            for(int libs : books[bs].libraries) {
                if(isSignedup[libs] && counter[libs] < libraries[libs].limit) {
                    ls = libs; break;   
                }
                // ls.pb(libs);
            }
            if(ls == -1) continue;
            scan(ls, bs);
            counter[ls]++;
            isScanned[bs] = true;
            books_scanned_this_round.pb({itr.ff, bs});
        }
        
        for(auto bs : books_scanned_this_round) {
            available_books.erase(bs);
        }
        
        if(curr_day == next_signup_time && signup_idx < l) {
            // cerr<<"Signing up library id: "<<signup_order[signup_idx]<<" on day: "<<curr_day<<endl;
            signup(libraries[signup_order[signup_idx]]);
            isSignedup[signup_order[signup_idx]] = true;
        }
    }
}

void print() {
    vi res;
    FOR(i, 0, signup_idx) {
        if(books_scanned[signup_order[i]].size()) {
            res.pb(signup_order[i]);
        }
    }

    cout<<res.size()<<endl;
    FOR(i, 0, res.size()) {
        int ls = res[i];
        cout<<ls<<" "<<books_scanned[ls].size()<<endl;
        
        bool space = false;
        for(int bs : books_scanned[ls]) {
            if(space) cout<<" "; 
            cout << bs;
            space = true;
        }
        cout<<endl;
    }

    deb(total_score);
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    // freopen("f_libraries_of_xthe_world.txt", "r", stdin);
    // freopen("d.txt", "w", stdout);

    input();
    solve();
    print();
    return 0;
}

