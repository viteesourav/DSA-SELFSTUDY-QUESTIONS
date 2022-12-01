string lookandsay(int n)
{
    // Logic:
    /* 0. 1 -> one

    1. 11  --> one 1

    2. 21  --> two ones

    3. 1211 --> one 2 and one 1

    4. 111221 --> one 1 one 2 two 1.

    1 2 1 1
    0 1 2 3

    form this vector...
    vector -> {1, 1}, {2, 1}, {1, 2}

    then iterate it and append element in the string like...
    vector.value then vector.key for each index.

    NOTE: Char and Int are dependent on each other by ASCII Code.
    48 -> '0'    65 -> 'A'   97 -> 'a'
    49 -> '1'
    */
    // code here...
    // we will try to do a simple approach.
    // we will maintain one vector of pairs that will have keypairs for
    // each char in the string and its freq untill a different char comes.
    // then we will iterate the vector and append it in a string
    // like first the value and then the key.

    // testing code for the working part that creates the vector...
    //  string ans = "1211";
    //  int len = ans.length();
    //  char ch = ans[0];int count =0;
    //  vector<pair<char, char>> v;
    //  for(int i=0;i<len;i++) {
    //      if(ch == ans[i]) count++;
    //      else {
    //          int pt = count + 48;
    //          v.push_back(make_pair(ch, (char)pt));
    //          ch = ans[i]; count = 1;
    //      }
    //  }

    // for(auto pt : v) {
    //     cout<<pt.first<<" "<<pt.second<<endl;
    // }

    string ans = "1";
    if (n == 1)
        return ans;
    int temp = n;
    while (temp > 1)
    {
        // this part of the code will make a vector with pair of ele and its freq continuosly in a row...
        vector<pair<char, char>> v;
        int len = ans.length();
        char ch = ans[0];
        int count = 0;
        int i = 0;
        while (i < len)
        {
            if (ch == ans[i])
                count++;
            else
            {
                int pt = count + 48;
                v.push_back(make_pair(ch, (char)pt));
                ch = ans[i];
                count = 1;
            }
            i++;
        }
        // if there is only one type of char in the string eg: 1 or 11
        if (i == len && count != 0)
        {
            int pt = count + 48;
            v.push_back(make_pair(ch, (char)pt));
        }

        // here we will be forming the new required string..
        string str = "";
        for (auto pt : v)
        {
            str.push_back(pt.second); // freq first
            str.push_back(pt.first);  // then the char
        }
        cout << str << endl;
        ans = str; // updating the modified string to ans for the next iteration.
        temp--;
    }
    return "";
};