/*
 *  Maximum Value Contiguous Subsequence.
 * Given a sequence of n real numbers A(1) ... A(n),
 * determine a contiguous subsequence A(i) ... A(j)
 * for which the sum of elements in the subsequence is maximized.
*/

#include <iostream>
using namespace std;

#define INF -9999

int max(int x, int y)
{
    return (x>y)?x:y;
}

int max(int x, int y, int z)
{
    return max(x, max(y, z));
}

int main()
{
    int n, ans;
    cin>>n;
    
    int dp[n], arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
        dp[i] = INF;
    }
    
    dp[0] = max(0, arr[0]);
    ans = 0;
    
    for(int i=1; i<n; i++)
    {
        dp[i] = max(dp[i-1] + arr[i], arr[i], 0);
        ans = max(ans, dp[i]);
    }
    
    cout<<endl<<ans<<endl;
    
    return 0;        
}
