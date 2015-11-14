int Solution::largestRectangleArea(vector<int> &A) {
    int i=0,len=A.size(),left,right,maxarea=0,tp,areaWithtop;
    stack<int>s;
    
    while(i<len){
        if(s.empty() || A[s.top()]<=A[i])s.push(i++);
        else{
            tp = s.top();   //tp as smallest bar height
            s.pop();        // i right most index && below tp left most index
            areaWithtop = A[tp]*(s.empty() ? i:i-s.top()-1);
            if(maxarea<areaWithtop)maxarea = areaWithtop;
        }
    }
    
    while(!s.empty()){
        tp = s.top();
        s.pop();
        areaWithtop = A[tp]*(s.empty() ? i:i-s.top()-1);
        if(maxarea<areaWithtop)maxarea = areaWithtop;
    }
    
    return maxarea;
}
