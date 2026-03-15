int i=1; i<=n; ++i){
        cin >> s[i];
        for(int j=1; j<=m; ++j){
            a[i][j] = (s[i][j - 1] == 'W');
        }
    }