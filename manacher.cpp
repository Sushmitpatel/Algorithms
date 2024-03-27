vector<int>manacher(string s){
  string temp="#";
  for(auto it:s){
    temp+=it;
    temp+='#';
  }
  int n=temp.length();
  vector<int>lps(n);
  int c=0;
  int r=0;
  for(int i=1;i<n;i++){
    //find the mirror index of i with respect to c
    int miror=c-(i-c);
    //if i is inside the right range then speed up the algo
    if(i<r){
    
      lps[i]=min(lps[miror],r-i);
    }
    while(i-lps[i]-1>=0 && i+lps[i]+1<n && temp[i+lps[i]+1]==temp[i-lps[i]-1]){
      lps[i]++;
    }
    //update the center and right boundary
    if(i+lps[i]>r){
      c=i;
      r=lps[i]+i;
    }
  }
  return lps;
}
