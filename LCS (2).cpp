#include<bits/stdc++.h>
using namespace std;

int dp(string text1, string text2, int index1, int index2, vector < vector < int > > * dpTable) {
	if ( index1 == 0 ) return 0 ;
	if ( index2 == 0 ) return 0 ;
	if ( ( *dpTable ) [ index2 ] [ index1 ] != -1 ) return ( *dpTable ) [ index2 ] [ index1 ] ;
	( *dpTable ) [ index2 ] [ index1 ] = 
		max (
			dp ( text1 , text2 , index1 - 1 , index2 , dpTable ) ,
			dp ( text1 , text2 , index1 , index2 - 1 , dpTable )
		) ;
	if ( text1 [ index1 - 1] == text2 [ index2 - 1 ] ) {
		( *dpTable ) [ index2 ] [ index1 ] += 1 ;
	}
	return ( *dpTable ) [ index2 ] [ index1 ] ;
}
int main () {
	string text1 = "bsbininm" ;
	string text2 = "jmjkbkjkv" ;
	//string text1 = "abcde" ;
	//string text2 = "ace" ;
	int length1 = text1.size();
	int length2 = text2.size();
	vector < vector<int> > dpTable ( 
		length2 + 1 ,
		vector < int > ( length1 + 1 , -1 )
	) ;

	int equal =  ( text1 [ length1 - 1] == text2 [ length2 - 1 ] ) ? 1 : 0 ;
	int answer = max(
		dp ( text1 , text2 , length1 - 1 , length2 , & dpTable ) ,
		dp ( text1 , text2 , length1 , length2 - 1 , & dpTable )
	) + equal ;
	dpTable [ length2 ] [ length1 ] = answer ;
	cout << "  ";
	for ( int j = 0; j < text1.size(); ++j ) {
		cout << text1 [ j ] << " " ;
	}
	cout << "\n" ;
    for (int i = 0; i < text2.size(); i++) {
		cout << text2 [ i ] << " ";
        for (int j = 0; j < text1.size(); j++) {
			std::cout << dpTable [ i + 1 ] [ j + 1 ]  << " ";
        }
        std::cout << std::endl;
    }
	return 0;
}