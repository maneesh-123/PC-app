long long int bin_exponentiation(long long int a, long long int n){
    if(n==0)
    return 1;


    long long int result= bin_exponentiation(a,n/2);


    if(n%2==0)
    return result*result;
    else
    return result*result*a;
}
