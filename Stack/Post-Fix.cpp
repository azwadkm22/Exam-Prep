    #include<bits/stdc++.h>
    using namespace std;

    #define debug(x) cout<<"debugging - "<<x<<endl;
    #define ull unsigned long long
    #define ll long long

    char problemLink[] = "";

    int precedence(char oprt)
    {
        if(oprt == '+' || oprt == '-')
        return 1;

        if(oprt == '*' || oprt == '/')
        return 2;

        if(oprt == '^')
        return 3;

        return -1;
    }

    double calc(double p1, double p2, char sign)
    {
        if(sign == '+')
        return p1+p2;

        if(sign == '-')
        return p2-p1;

        if(sign == '*')
        return p1*p2;

        if(sign == '/')
        {
            return p2/p1;
        }

        if(sign == '^')
        return pow(p1, p2);

        return -1;
    }

    int main()
    {
        string str;

        getline(cin, str);

        stack<char> st;
        vector<char> postfix;

        for(int i=0; i<str.length(); i++)
        {
            if(str[i] >= '0' && str[i] <= '9')
            {
                postfix.push_back(str[i]);
            }

            else if(str[i] == '(')
            {
                postfix.push_back(' ');
                st.push(str[i]);
            }

            else if(str[i] == ')')
            {
                postfix.push_back(' ');

                if(st.empty())
                {
                    cout<<"ERROR"<<endl;
                    return 0;
                }
                while(st.top() != '(')
                {
                    // postfix.push_back(' ');
                    postfix.push_back(st.top());
                    st.pop();
                }
                st.pop();
            }


            else if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '^')
            {
                postfix.push_back(' ');
                if(st.empty())
                    st.push(str[i]);

                else if(precedence(st.top()) >= precedence(str[i]))
                {
                    postfix.push_back(st.top());
                    st.pop();
                    st.push(str[i]);
                }
                else
                {
                    st.push(str[i]);
                }
            }
            else if(str[i] == ' ')
            {
                postfix.push_back(' ');
                continue;
            }
            else
            {
                // cout<<str[i]<<endl;
                cout<<"ERROR"<<endl;
                return 0;
            }
        }

        while(!st.empty())
        {
            if(st.top() == '(')
            {
                cout<<"ERROR"<<endl;
                return 0;

            }
            postfix.push_back(st.top());
            st.pop();
        }


        // for(int i=0; i<postfix.size(); i++)
        // {
        //     cout<<postfix[i];
        // }

        stack<double> result;
        double p1=0, p2=0;
        char sign;
        for(int i=0; i<postfix.size(); i++)
        {
            if(postfix[i] >= '0' && postfix[i] <= '9')
            {
                int number =0;
                for(number =0; i<postfix.size() && ( postfix[i] >= '0' && postfix[i] <= '9' ); )
                {
                    number = number*10 + postfix[i] - '0';
                    i++;
                }

                i--;
                result.push(number);
            }

            else if(postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '^')
            {
                sign = postfix[i];
                if(!result.empty())
                {
                    p1 = result.top();
                    result.pop();
                }
                if(!result.empty())
                {
                    p2 = result.top();
                    result.pop();
                }

                if(sign == '/' && p1 == 0)
                {
                    cout<<"ERROR"<<endl;
                    return 0;
                }

                p2 = calc(p1, p2, sign);


                result.push(p2);
            }
        }

        cout<<result.top()<<endl;

        return 0;
    }
