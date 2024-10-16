class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        int cura=0,curb=0,curc=0;
        int totalIterations=a+b+c;
        string res="";
        for(int i=0;i<totalIterations;i++){
            if((a>=b and a>=c and cura!=2) or (a>0 and(curb==2 or curc==2))){
                res+="a";
                a--;
                cura++;
                curb=0;
                curc=0;
            }else if((b>=a and b>=c and curb!=2) or (b>0 and (curc==2 or cura==2))){
                res+="b";
                b--;
                curb++;
                cura=0;
                curc=0;
            }else if((c>=a and c>=b and curc!=2) or (c>0 and (cura==2 or curb==2))){
                res+="c";
                c--;
                curc++;
                cura=0;
                curb=0;
            }
        }
        return res;
    }
};