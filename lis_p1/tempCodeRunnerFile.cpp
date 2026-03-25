 > 0){
        if(s[u] == t[v]){
            res[len - 1] = s[u];
            u--;
            v--;
            len--;
        }else{
            if(dp[u][v - 1] > dp[u - 1][v]) v--;
            else                            u--;
        }
    }