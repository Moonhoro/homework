public class SubstringMatch {
    private SubstringMatch(){}
public static int rabinKarp(String s,String t) {
    if (s.length() < t.length()) return -1;
    if (t.length() == 0) return 0;
    long thash = 0, MOD = (long) 1e9 + 7, B = 256;
    for (int i = 0; i < t.length(); i++)
        thash = (thash * B + t.charAt(i)) % MOD;
    long hash = 0, P = 1;
    for (int i = 0; i < t.length() - 1; i++) {
        P = P * B % MOD;
    }
    for (int i = 0; i < t.length() - 1; i++)
        hash = (hash * B + s.charAt(i)) % MOD;
    for (int i = t.length() - 1; i < s.length(); i++) {
        hash = (hash * B + s.charAt(i)) % MOD;
        if (hash == thash && equal(s, i - t.length() + 1,t))
            return i - t.length() + 1;
        hash = hash - (s.charAt(i - t.length() + 1) * P % MOD + MOD) % MOD;

    }
    return -1;
}
private static boolean equal(String s,int l,String t){
        for(int i=0;i<t.length();i++)
            if(t.charAt(i)!=s.charAt(i+l))return false;
        return  true;
}
}
