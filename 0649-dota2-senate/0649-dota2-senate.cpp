class Solution {
public:
    string predictPartyVictory(string senate) {
        int rCount=0,dCount=0;
        int dFloatingBan=0,rFloatingBan=0;
        queue<char> q;
        for(char ch:senate)
        {
            q.push(ch);
            if(ch=='R') rCount++;
            else dCount++;
        }
        while(rCount and dCount)
        {
            char cur=q.front();
            q.pop();
            if(cur=='D')
            {
                if(dFloatingBan)
                {
                    dFloatingBan--;
                    dCount--;
                }
                else
                {
                    rFloatingBan++;
                    q.push('D');
                }
            }
            else
            {
                if(rFloatingBan)
                {
                    rFloatingBan--;
                    rCount--;
                }
                else
                {
                    dFloatingBan++;
                    q.push('R');
                }
            }
        }
        return rCount?"Radiant":"Dire";
    }
};