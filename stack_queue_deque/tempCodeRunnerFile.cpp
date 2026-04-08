
                int right = i;
    
                while(left - 1 >= 1 && hi[left - 1] >= hi[j])   left--;
                while(right + 1 <= n && hi[right + 1] >= hi[j]) right++;
    
                cout << left << " " << right << '\n';