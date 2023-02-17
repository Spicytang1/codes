//확장 유클리드 알고리즘
//extended Euclidean alorithm
//given a,b, calculates x,y where ax+by=gcd(a,b)

//made by ChatGPT https://chat.openai.com/chat


int extended_gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    int gcd = extended_gcd(b, a % b, y, x);
    y -= (a / b) * x;

    return gcd;
}
