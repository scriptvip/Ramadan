#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename K, typename V, typename Comp = std::less<K>>
using ordered_map = tree<K, V, Comp, rb_tree_tag, tree_order_statistics_node_update>;
template <typename K, typename Comp = std::less<K>>
using ordered_set = ordered_map<K, null_type, Comp>;

template <typename K, typename V, typename Comp = std::less_equal<K>>
using ordered_multimap = tree<K, V, Comp, rb_tree_tag, tree_order_statistics_node_update>;
template <typename K, typename Comp = std::less_equal<K>>
using ordered_multiset = ordered_multimap<K, null_type, Comp>;

template < typename T = int > ostream& operator << (ostream &out, const vector < T > &v) { 
    for (const T &x : v) out << x << ' '; 
    return out;
}
template < typename T = int > istream& operator >> (istream &in, vector < T > &v) {
    for (auto &x : v) in >> x;
    return in;
}
#define Prfx_Sum(arr_A, arr_B) arr_B[i+1] = arr_A[i] + arr_B[i]
#define Prfx_Range(arr_B, l, r) arr_B[r]-arr_B[l-1]
#define sum_range_2D(I, J, K, L, A) A[K][L]-A[K][J-1]-A[I-1][L]+A[I-1][J-1]
#define cin(vec) for(auto& i : vec) cin >> i
#define cin_2d(vec, n, m) for(int i = 0; i < n; i++) for(int j = 0; j < m && cin >> vec[i][j]; j++);
#define cout(vec) for(auto& i : vec) cout << i << " "; cout << "\n";
#define cout_2d(vec, n, m) for(int i = 0; i < n; i++, cout << "\n") for(int j = 0; j < m && cout << vec[i][j] << " "; j++);
#define cout_map(mp) for(auto& [f, s] : mp) cout << f << "  " << s << "\n";
#define Time cerr <<"\nTaken_Time: "<<(float)clock()/CLOCKS_PER_SEC<<" Sc\n";
#define fixed(n) cout << fixed << setprecision(n)
#define gtln(str) getline (cin >> ws, str)
#define sumL_R(L,R) (R*(R+1)/2)-((L-1)*((L-1)+1)/2)
#define ceil(n, m) ((n / m) + (n % m ? 1 : 0))
#define ceil(n, m) ((n + m - 1) / m)
#define pr_queue(DT) priority_queue <DT, vector<DT>, greater<int>>
#define fill(vec, value) memset(vec, value, sizeof(vec));
#define Num_of_Digits(n) ((int)log10(n) + 1)
#define all(vec) vec.begin(),vec.end()
#define rall(vec) vec.rbegin(),vec.rend()
#define sz(x) int(x.size())
#define G_Test_Case size_t TC; cin >> TC; for(size_t T = 1; T <= TC; ++T)
#define TC int t; cin >> t; while(t--)
#define Pair pair < int, int >
#define ll long long
#define ull unsigned long long
#define NoDgt(n) ((int)log10(n)+1)
#define Mod  1'000'000'007
#define INF 2'000'000'000
#define EPS 1e-9
#define PI acos(-1)

// subsequence == 2^size -1
// subarrays == sum(size -1)
 
void Code(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
    #endif
}
    
template < typename T = int > vector < T > nextGreaterelement(vector < T >& nums) {
    int n = nums.size();
    vector < T > res(n);
    stack < int > st;
    for(int i = n - 1; i >= 0; i--){
        while(!st.empty() && nums[st.top()] <= nums[i]) st.pop();
        res[i] = (st.empty() ? -1 : nums[st.top()]);
        st.push(i);
    }
    return res;
}

template < typename T = int > vector < T > prevGreaterelement(vector < T >& nums) {
    int n = nums.size();
    vector < T > res(n);
    stack < int > st;
    for(int i = 0; i < n; i++){
        while(!st.empty() && nums[st.top()] <= nums[i]) st.pop();
        res[i] = (st.empty() ? -1 : nums[st.top()]);
        st.push(i);
    }
    return res;
}

template < typename T = int > vector < T > nextSmallerelement(vector < T >& nums) {
    int n = nums.size();
    vector < T > res(n);
    stack < int > st;
    for(int i = n - 1; i >= 0; i--){
        while(!st.empty() && nums[st.top()] >= nums[i]) st.pop();
        res[i] = (st.empty() ? -1 : nums[st.top()]);
        st.push(i);
    }
    return res;
}

template < typename T = int > vector < T > prevSmallerelement(vector < T >& nums) {
    int n = nums.size();
    vector < T > res(n);
    stack < int > st;
    for(int i = 0; i < n; i++){
        while(!st.empty() && nums[st.top()] >= nums[i]) st.pop();
        res[i] = (st.empty() ? -1 : nums[st.top()]);
        st.push(i);
    }
    return res;
}


bool BinSearch (vector <ll> &arr, ll n) {
    ll l = 0, r = arr.size() - 1;
    sort(all(arr));    
    while (l <= r) {
        ll m = l + ((r - l) >> 1);
        if (arr[m] == n) return true;
        (arr[m] > n ? r = m - 1 : l = m + 1);  
    }
    return false;
} 

ll UprBound (vector <ll> &arr, ll n) {  
    ll l = -1, r = arr.size();
    while (r > l + 1) {
        ll m = l + ((r - l) >> 1);
        arr[m] <= n ? l = m : r = m;
    }
    return arr[l + 1];
}

ll LwrBound (vector <ll> &arr, ll n) {
    ll l = -1, r = arr.size();
    while (r > l + 1) {
        ll m = l + ((r - l) >> 1);
        arr[m] >= n ? r = m : l = m;
    }
    return arr[r + 1];
}

vector < int > Halazona(vector < vector < int > > matrix) {  
    vector < int > result;
    int rows = matrix.size(), cols = matrix[0].size();
    int left = 0, right = cols-1, top = 0, bottom = rows-1;
    
    while (left <= right and top <= bottom) {
        for (int i = left; i <= right; i++) result.push_back(matrix[top][i]);
        top++;
        
        for (int i = top; i <= bottom; i++) result.push_back(matrix[i][right]);
        right--;
        
        if (top <= bottom) {
            for (int i = right; i >= left; i--) result.push_back(matrix[bottom][i]);           
            bottom--;
        }
        if (left <= right) {
            for (int i = bottom; i >= top; i--) result.push_back(matrix[i][left]);
            left++;
        }
    }
    return result;
}

vector < vector < int > > generate_halazona(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int left = 0, right = n-1, top = 0, bottom = n-1, num = 1;
        while (left <= right && top <= bottom) {
            for (int i = left; i <= right; i++) matrix[top][i] = num++;
            top++;
            for (int i = top; i <= bottom; i++) matrix[i][right] = num++;
            right--;
            if (top <= bottom) {
                for (int i = right; i >= left; i--) matrix[bottom][i] = num++;
                bottom--;
            }
            if (left <= right) {
                for (int i = bottom; i >= top; i--) matrix[i][left] = num++;
                left++;
            }
        }
        return matrix;
}

bool isPalindrome(string S) {
    for (int i = 0; i < S.size() / 2; i++) 
        if (S[i] != S[S.size() - i - 1]) return false;
    return true;
}


ll factorial(ll n) {
    if (n == 0)     return 1;
    return n * factorial(n - 1);
}


int day_of_week(int d, int m, int y) {
    static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
    y -= m < 3;
    return ( y + y / 4 - y / 100 + y / 400 + t[m - 1] + d) % 7;
    /*
        Start from Sunday To Saturday
        string array
    */
}

ll countOdd(ll L, ll R) {
 
    ll N = (R - L) / 2;
    if (R % 2 != 0 or L % 2 != 0) N += 1;
    return N;
}

bool Is_square(ll x){
    if (x >= 0) {
        ll sr = sqrt(x);
        return (sr * sr == x);
    }
    return false; /// neglect the (-)
}

bool IsPow_of_2(ll n) {
    if (n == 1) return false;
    while (n % 2 == 0) n /= 2;
    if (n == 1) return true;
    else return false;
}

vector < bool > is_prime;
void Seive(int n) {
    is_prime.assign(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for(ll i = 2; i <= sqrt(n); i++)
        if(is_prime[i]) 
            for(ll j = i * i; j <= n; j += i) 
                is_prime[j] = false;
}

// Greatest common divisors between two numbers

ll GCD(ll a, ll b){
    return (!b ? a : GCD(b, a % b));
}
    
// least common multiplication between two numbers

ll LCM(ll a, ll b){
    return a / GCD(a, b) * b;
}

// Get vector with the prime factors of number

vector < int > prime_factorizations (ll n) {
    vector < int > factors;
    while(not(n & 1)) factors.push_back(2), n /= 2;
    for(int i = 3; i <= sqrt(n); i += 2)
        while(n % i == 0) factors.push_back(i), n /= i;
    if(n > 2) factors.push_back(n);
    return factors;
}

// Get set with the prime factors of number

set <int> prime_factorization (ll n) {
    set < int > factors;
    while(not(n & 1)) factors.emplace(2), n /= 2;
    for(int i = 3; i <= sqrt(n); i += 2)
        while(n % i == 0) factors.emplace(i), n /= i;
    if (n > 2) factors.emplace(n);
    return factors;
}
// Combination

ll nCr (ll n, ll r) {
    if(r > n) return 0;
    ll p = 1, k = 1;
    if (n - r < r) r = n - r;
    // condition for minimum choose
    if(n < 1) return 0;
    while (r > 0){
        p *= n, k *= r;
        ll m = __gcd(p, k);
        p /= m, k /= m, n--, r--;        
    }
    return p;
}

double nCr(double n, double r) {
    if(r > n) return 0;
    if(r == 0) return 1;
    return n/r*nCr(n-1, r-1);
} // dont forget use fixed(0)

// Permutation

ll nPr(ll n, ll r){
    if(r > n) return 0;
    ll npr = 1;
    while(r-- > 0)
        npr *= n--;
    return npr;
}

// get a mod for big int

ll Big_Mod(string s, ll mod){
    ll res = 0;
    for(auto& c : s)
        res = (res * 10 + (c - '0')) % mod;
    return res;
}

// b power e in O(log(n))

ll Pow(ll b, ll e){
    ll power = 1;
    while(e) {
        if(e & 1) power *= b;
        e >>= 1, b *= b;
    }   return power;
}

// b power e % mod in O(log(n))

ll Pow_Mod(ll b, ll e, ll mod){
    ll power = 1;
    while(e){
        if(e & 1) power = ((power % mod) * (b % mod)) % mod;
        e >>= 1;
        b = ((b % mod) * (b % mod)) % mod;
    }
    return power % mod;
}

set <ll> SumSet(vector <ll> &arr) {
    size_t set_size = 2 << (ll)arr.size();
    set <ll> Sum_Set;     
    for (size_t cnt = 0; cnt < set_size; cnt++) {
        ll tmp = 0;
        for (size_t j = 0; j < arr.size(); j++)
            if (cnt & (1 << j)) tmp += arr[j];
        Sum_Set.emplace(tmp);
    }
    return Sum_Set;
}
    
// Get all subsequene of an string, array ... etc

set <string> PowSet(string &s) {
    size_t set_size = 2 << (ll)s.size();
    set <string> Pow_Set;     
    for (size_t cnt = 0; cnt < set_size; cnt++) {
        string tmp = "";
        for (size_t j = 0; j < s.size(); j++)
            if (cnt & (1 << j)) tmp += s[j];
        Pow_Set.emplace(tmp);
    }
    return Pow_Set;
}

set < vector < ll > > PowSet(vector < ll > &arr) {
    size_t set_size = 2 << (ll)arr.size();
    set <vector <ll>> Pow_Set;     
    for (size_t cnt = 0; cnt < set_size; cnt++) {
        vector <ll> tmp;
        for (size_t j = 0; j < arr.size(); j++)
            if (cnt & (1 << j)) tmp.emplace_back(arr[j]);
        Pow_Set.emplace(tmp);
    }
    return Pow_Set;
}

// Check if number is prime or not

bool Is_Prime(ll n) {
      if (n < 2 or (not(n & 1) and n != 2)) return false;
      for (int i = 3; i <= sqrt(n); i += 2)
            if (n % i == 0) return false;
      return true;
}

// get the number of divisors for n

int number_of_divisors(ll n){
    int divisors = 0;
    for(int i = 1; i < sqrt(n); i++)
        if(n % i == 0) divisors += 2;
    return divisors + (sqrt(n) == (int)sqrt(n));
}

// get Summation of divisors for n

ll sum_of_divisors(ll n) {
    ll sum_divisors = 0;
    for(int i = 1; i < sqrt(n); i++)
        if(n % i == 0) sum_divisors += ((n / i) + i);
    ll sq = sqrt(n);
    return sum_divisors + (sq * sq == n ? sq : 0);
}

// get vector with the divisors for n

vector < ll > Get_Divisors(ll n) {
    vector < ll > divisors;
    for(int i = 1; i < sqrt(n); i++)
        if(n % i == 0) divisors.emplace_back(i), divisors.emplace_back(n / i);
    if(sqrt(n) == int(sqrt(n))) divisors.emplace_back(sqrt(n));
    return divisors;
}

// print all permutation of an array

void Print_Permutation(vector < int >& nums){
    sort(all(nums));
    do {
        for(auto& i : nums) cout << i << " ";
        cout << "\n";
    } while(next_permutation(nums.begin(), nums.end()));
}

// print all permutation of a string

void Print_Permutation(string s){
    sort(all(s));
    do {
        cout << s << "\n";
    } while(next_permutation(s.begin(), s.end()));
}

// get the summation between two numbers or the summation between 1 and n

ll Summation_Range(ll r, ll l = 0){
    if(l > r) swap(l, r);
    return (r * (r + 1) / 2) - (l * (l - 1) / 2);
}

// Get how many number divisable by c between a and b

ll how_many_divisors(ll a, ll b, ll c){
    return (b / c) - ((a - 1) / c);
}

ll Summation(ll x){
return x * (x + 1) / 2;
}

// Get summation of numbers divisable by c between a and b

ll Summation_of_Devisors(ll a, ll b, ll c){
    ll right = Summation(b / c);
    ll left = Summation((a - 1) / c);
    return (right - left) * c;
}

// get logb(a)

double get_log(ll a, int b){
    return log(a) / log(b);
}

// Check if number power of another or not

bool is_power(ll number, int base = 2){
    return (get_log(number, base) - (ll) get_log(number, base) <= EPS);
}

// Distination Between two points

double dist(double x1, double y1, double x2, double y2){
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

// Check if it valid triangle with 3 length sides

bool is_triangle(ll a, ll b, ll c){
    return (a + b > c) && (a + c > b) && (b + c > a) && (a && b && c);
}

// Get Slope of two points

double slope(double x1, double y1, double x2, double y2){
    if(x2 == x1) return 0;
    return (y2 - y1) / (x2 - x1);
}

// Check if three points in the same line

bool is_same_line(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3){
    return (y2 - y1) * (x3 - x1) == (y3 - y1) * (x2 - x1);
}

// Convert Decimal to any base

string decimal_to_any_base(ll decimal, ll base){
    if(decimal == 0) return "0";
    string num = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string result;
    do{
        result.push_back(num[decimal % base]);
        decimal /= base;
    }while(decimal != 0);
    return string(result.rbegin(), result.rend());
}

// Convert any base to decimal

ll  any_base_to_decimal(string str, int base) {
    auto val = [](char c){
        return (c >= '0' && c <= '9' ? (int) c - '0' : (int) c - 'A' + 10);
    };
    ll len = sz(str), power = 1, num = 0, i;
    for (i = len - 1; i >= 0; i--) {
        num += val(str[i]) * power;
        power = power * base;
    }
    return num;
}
