#include<bits/stdc++.h>

using namespace std;
/*
	[[0,1],[1,0],[4,0],[0,4],[3,3],[2,4]], king = [0,0]
	,
	vector < vector <int> > queens = {{5,6},{7,7},{2,1},{0,7},{1,6},{5,1},{3,7},{0,3},{4,0},{1,2},{6,3},{5,0},{0,4},{2,2},{1,1},{6,4},{5,4},{0,0},{2,6},{4,5},{5,2},{1,4},{7,5},{2,3},{0,5},{4,2},{1,0},{2,7},{0,1},{4,6},{6,1},{0,6},{4,3},{1,7}} ;//
	vector <int> king = {3,4};

*/
int main () {
	
	vector < vector <int> > queens = {{5,6},{7,7},{2,1},{0,7},{1,6},{5,1},{3,7},{0,3},{4,0},{1,2},{6,3},{5,0},{0,4},{2,2},{1,1},{6,4},{5,4},{0,0},{2,6},{4,5},{5,2},{1,4},{7,5},{2,3},{0,5},{4,2},{1,0},{2,7},{0,1},{4,6},{6,1},{0,6},{4,3},{1,7}} ;//
	vector <int> king = {3,4};
        vector <int> rey = { king[1] + 1, king[0] + 1 } ;
        int lengthY = king[1];
        int lengthX = king[0] ;
        for ( vector <int> place : queens ) {
            if ( place[1] > lengthY ) {
                lengthY = place[1] ;
            }
            if ( place[0] > lengthX ) {
                lengthX = place[0] ;
            }
        }
        if ( lengthY > lengthX ) {
            lengthX = lengthY ;
        } else {
            lengthY = lengthX ;
        }
        
        vector < vector<int> > matrix (lengthY + 3, vector<int> ( lengthX + 3 , 0) );
    
        for ( int i = 0 ; i < lengthY + 3; i++) {
            matrix[i][0] = -1 ;
            matrix[i][lengthY + 2] = -1 ;
        }
        
        for ( int i = 0 ; i < lengthX + 3; i++) {
            matrix[0][i] = -1 ;
            matrix [ lengthX + 2 ] [ i ] = -1;
        }
        
        for (vector <int> queen : queens) {
            matrix[queen[0] + 1][queen[1] + 1] = 9;
        }
        matrix [king[0] + 1] [king[1] + 1] = 8;
        
        
        vector < vector <int> > answer;
        
        vector< int > xy;
        
        
        for ( int d = 0; d < 8; d++) {
            xy = { rey[0], rey[1] };
            while ( matrix[xy[1]][xy[0]] != -1 && matrix[xy[1]][xy[0]] != 9  ) {
                switch (d) {
                    case 0:// north west
                        xy[0] = xy[0] - 1;
                        xy[1] = xy[1] - 1;
                        break;
                    case 1:// north 
                        xy[1] = xy[1] - 1;
                        break;
                    case 2:// north east
                        xy[0] = xy[0] + 1;
                        xy[1] = xy[1] - 1;
                        break;
                    case 3:// east
                        xy[0] = xy[0] + 1;
                        break;
                    case 4:// south east
                        xy[0] = xy[0] + 1;
                        xy[1] = xy[1] + 1;
                        break;
                    case 5:// south
                        xy[1] = xy[1] + 1;
                        break;
                    case 6:
                        xy[0] = xy[0] - 1;
                        xy[1] = xy[1] + 1 ;
                        break;
                    default:
                        xy[0] = xy[0] - 1;
                        break;
                }
            }
            if ( matrix [ xy[ 1 ] ] [ xy [0] ] == 9 ) {
                answer.push_back( {
                    xy [ 1 ] - 1,
                    xy [ 0 ] - 1
                } ) ;
            }
        }
	
	

	
	//
	cout << " The answer is : { " ;
	for ( int i = 0 ; i < answer.size() ; i++ ) {
		cout << "{" << answer [i][1] << "," << answer [i][0] << "}" ;
		if ( i != answer.size() - 1) {
			cout << ", " ;
		}
	}
	cout << "\n";
	for (int i = 1; i < lengthY + 2; i++) {
		for ( int j = 1; j < lengthX + 2; j++) {
			cout << matrix[j][i] << " " ;
		}
		cout << " \n";
	}
	
	
	
	
	
	return 0;
}