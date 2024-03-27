vector<int>fact(1e6+7);
void factorial(){
  fact[1]=1;
  for(int i=2;i<1e6+7;i++){
    fact[i]=(fact[i-1]*i)%mod;
  }
}
int power(int b,int e){
  if(e==0){
    return 1;
  }
  int temp=power(b,e/2);
  int ans=(temp*temp)%mod;
  if(e&1){
    ans=(ans*b)%mod;
  }
  return ans;
}
int modInv(int x){
  return power(x,mod-2);
}
int comb(int n,int r){
 int ans=(((fact[n]*modInv(fact[r]))%mod)*modInv(fact[n-r]))%mod;
 return ans;
}
