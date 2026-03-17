t=0; pt<6; ++pt){
        for(int i=0; i<sz(s); ++i){
            pre[pt][i + 1] = pre[pt][i] + (s[i] != gen[pt][i]);
        }
    }