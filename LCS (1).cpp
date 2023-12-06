#include<bits/stdc++.h>
using namespace std;
int main () {
	
	string text1 = "abcde" ;
	
	string text2 = "ace" ;
	
	
	string text11 = text1 ;
	string text22 = text2 ;

	cout << "Ingrese la cadena 1  y la cadena 2 : " ;
	cin >> text1;
	
	// cout << "Ingrese la cadena 2 : " ;
	cin >> text2;
	




	int answer ;
	vector < vector<int> > dpTable;
	int rows = text2.size();
	int columns = text1.size();
	for ( int i = 0 ; i < rows; i++ ) {
		dpTable.push_back(vector<int> ( columns, 0 ));
	}
		
	for ( int i = 0 ; i <  rows ; i ++ ) {
		for ( int j = 0 ; j < columns ; j ++ ) {
			dpTable [ i ] [ j ] = 0 ;
		}
	}
	int row = 0, column = 0;
	if ( !( column == columns && row == rows ) ) {
		while ( !( column == columns &&  row == rows - 1) ) {
			if ( column == columns ) {
				column = 0;
				row++;

			}
			
			if ( column == 0 && row == 0 ) {
				dpTable [ 0 ] [ 0 ] = 0 ;
			} else {
				if ( column - 1 != -1 ) {
					if ( row - 1 != -1 ) {
						if ( column == 1 && row == 1 ) {
							if ( text1 [ 0 ] == text2 [ 0 ] ) {
								dpTable [ column ] [ row ] = 1;
							}
						} else {
							if ( dpTable [ row - 1 ] [ column ] > dpTable [ row ] [ column - 1] ) {
								dpTable [ row ] [ column ] = dpTable [ row - 1 ] [ column ] ;
							} else {
								dpTable [ row ] [ column ] = dpTable [ row ] [ column - 1 ] ;
							}
						}
					} else {
						dpTable [ row ] [ 0 ] = 0 ;
					}
					
					
				} else {
					dpTable [ 0 ] [ column ] = 0 ;
				}
			}
			
			if ( text1 [ column ] == text2 [ row ] ) {
				dpTable [ row ] [ column ] = dpTable [ row ] [ column ] + 1 ;
			}
			
			
			
			column++;

		}
		answer = dpTable[rows - 1][columns - 1] ;
	} else {
		answer = 0;
	}

	cout << "The answer is : " << answer << "\n\n\n" ;
	
	
	//cout << "Hola mundo\nThe final common subsequence calculeted were supposed to be : " << dpTable [ text1.size() - 1 ] [ text2.size() - 1 ] ;
	// Display the array
	cout << "  " ;
	for ( int j = 0; j < text1.size(); ++j ) {
		cout << text1 [ j ] << " " ;
	}
	cout << "\n" ;
    for (int i = 0; i < text2.size(); i++) {
		cout << text2 [ i ] << " ";
        for (int j = 0; j < text1.size(); j++) {
            std::cout << dpTable[i][j] << " ";
        }
        std::cout << std::endl;
    }
	return 0;
}