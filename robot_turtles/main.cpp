#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

int main(int argc, char** argv) {
	
	
	char map[8][8];
	char changed_map[8][8];
	int i, j, flag_row, flag_column;
	int k, move, l, direction=0, result;
	char root; 
	
	// if move is L, flag is 0
	// if move is R, flag is 1
	
	// if direction is up, value is 8
	// if direction is down, value is 2
	// if direction is left, value is 4
	// if direction is right, value is 6
	
	// if result is 0, it is bug
	// if result is 1 , it is diamond
	
	for( i = 0; i < 8; i++ ) {
		for( j = 0; j < 8; j++ ) {
			cout << i+1 << ".row" << " and ";
			cout << j+1 << ".column\n";
			cin >> map[ i ][ j ];
		}
	}

	map[7][0] = 'T';
		
	for( i = 0; i < 8; i++ ) {
		for( j = 0; j < 8; j++ ) {
			changed_map[ i ][ j ] = map[ i ][ j ];
		}
	}
	
	flag_row = 7;
	flag_column = 0;
	
	cout << "\nThis is your map that according to your values:\n";
	for(int a=0; a<8; a++)
    {
        for(int b=0; b<8; b++)
            cout<<" "<<map[a][b];
        cout<<"\n";
    }

	cout << "\nEnter your move count:\n";
	cin >> move;
	
	for( k = 0; k < move; k++ ) {
		
		cout << "\nEnter your root:\n";	
		cin >> root;
		
		if(k == 0)
		{
			if(root == 'F')
			{
				if(map[7][1] == '.')
				{
					changed_map[7][1] = 'T';
					changed_map[7][0] = '.';
					flag_row = 7;
					flag_column = 1;
					direction = 6;  //right
			    }
			    else if(map[7][1] == 'C')
			    {
			    	//BUG
			    	result = 0;
			    	break;
				}
				else if(map[7][1] == 'I')
			    {
			    	//BUG
			    	result = 0;
			    	break;
				}
				else if(map[7][1] == 'D')
			    {
			    	//DÝAMOND
			    	result = 1;
			    	break;
				}
			}
			else if(root == 'L')
			{
				direction = 8;
			}
			else if(root == 'R')
			{
				//RETURN BUG
				result = 0;
			    break;
			}
		}
		else
		{
			if(root == 'F')
			{
				
					if(direction == 2)
					{
						flag_row = flag_row + 1;
						
						if(flag_row > 7)
						{
							//RETURN BUG
							result = 0;
			    			break;	
						}
						else
						{
							if(changed_map[flag_row][flag_column] == '.'){
								changed_map[flag_row - 1][flag_column] = '.';							
								changed_map[flag_row][flag_column] = 'T';
							}
							else if(changed_map[flag_row][flag_column] == 'I'){
								//RETURN BUG
								result = 0;
				    			break;
							}
							else if(changed_map[flag_row][flag_column] == 'C'){
								//RETURN BUG
								result = 0;
				    			break;
							}
							else if(changed_map[flag_row][flag_column] == 'D'){
								//FOUND DIAMOND
								result = 1;
				    			break;
							}
						}
					}
					else if(direction == 4)
					{
						if(flag_column == 0)
						{
							//RETURN BUG
							result = 0;
			    			break;	
						}
						else
						{
							flag_column = flag_column - 1;
							
							if(changed_map[flag_row][flag_column] == '.'){
								changed_map[flag_row][flag_column + 1] = '.';
								changed_map[flag_row][flag_column] = 'T';
							}
							else if(changed_map[flag_row][flag_column] == 'I'){
								//RETURN BUG
								result = 0;
				    			break;
							}
							else if(changed_map[flag_row][flag_column] == 'C'){
								//RETURN BUG
								result = 0;
				    			break;
							}
							else if(changed_map[flag_row][flag_column] == 'D'){
								//FOUND DIAMOND
								result = 1;
				    			break;
							}
						}
					}
					else if(direction == 6)
					{
						flag_column = flag_column + 1;
						if(flag_column > 7)
						{
							//RETURN BUG
							result = 0;
			    			break;	
						}
						else
						{
							if(changed_map[flag_row][flag_column] == '.'){
								changed_map[flag_row][flag_column - 1] = '.';
								changed_map[flag_row][flag_column] = 'T';
							}
							else if(changed_map[flag_row][flag_column] == 'I'){
								//RETURN BUG
								result = 0;
				    			break;
							}
							else if(changed_map[flag_row][flag_column] == 'C'){
								//RETURN BUG
								result = 0;
				    			break;
							}
							else if(changed_map[flag_row][flag_column] == 'D'){
								//FOUND DIAMOND
								result = 1;
				    			break;
							}
						}
					}
					else if(direction == 8)
					{
						if(flag_row == 0)
						{
							//RETURN BUG
							result = 0;
			    			break;	
						}
						else
						{
							flag_row = flag_row - 1;
							if(changed_map[flag_row][flag_column] == '.'){
								changed_map[flag_row + 1][flag_column] = '.';
								changed_map[flag_row][flag_column] = 'T';
							}
							else if(changed_map[flag_row][flag_column] == 'I'){
								//RETURN BUG
								result = 0;
				    			break;
							}
							else if(changed_map[flag_row][flag_column] == 'C'){
								//RETURN BUG
								result = 0;
				    			break;
							}
							else if(changed_map[flag_row][flag_column] == 'D'){
								//FOUND DIAMOND
								result = 1;
				    			break;
							}
						}
					}
					
					
			}
			else if(root == 'L') // means rotate to left
			{
				 if(direction == 2)
					{
						direction = 6;
					}
					else if(direction == 4)
					{
						direction = 2;
					}
					else if(direction == 6)
					{
						direction = 8;
					}
					else if(direction == 8)
					{
						direction = 4;
					}
				
				
			}
			else if(root == 'R') // means rotate to right
			{
				  if(direction == 2)
					{
						direction = 4;
					}
					else if(direction == 4)
					{
						direction = 8;
					}
					else if(direction == 6)
					{
						direction = 2;
					}
					else if(direction == 8)
					{
						direction = 6;
					}
			}
			else if(root == 'X') 
			{
					if(direction == 2)
					{
						flag_row = flag_row + 1;
						
						if(flag_row > 7)
						{
							//RETURN BUG
							result = 0;
			    			break;	
						}
						else
						{
							if(changed_map[flag_row][flag_column] == '.'){
								//RETURN BUG
								result = 0;
				    			break;							
							}
							else if(changed_map[flag_row][flag_column] == 'I'){
								changed_map[flag_row][flag_column] = '.';
								flag_row = flag_row - 1;
							}
							else if(changed_map[flag_row][flag_column] == 'C'){
								//RETURN BUG
								result = 0;
				    			break;
							}
							else if(changed_map[flag_row][flag_column] == 'D'){
								//RETURN BUG
								result = 0;
				    			break;
							}
						}
					}
					else if(direction == 4)
					{
						if(flag_column == 0)
						{
							//RETURN BUG
							result = 0;
			    			break;	
						}
						else
						{
							flag_column = flag_column - 1;
							
							if(changed_map[flag_row][flag_column] == '.'){
									//RETURN BUG
									result = 0;
					    			break;
							}
							else if(changed_map[flag_row][flag_column] == 'I'){
								changed_map[flag_row][flag_column] = '.';
								flag_column = flag_column + 1;
							}
							else if(changed_map[flag_row][flag_column] == 'C'){
								//RETURN BUG
								result = 0;
				    			break;
							}
							else if(changed_map[flag_row][flag_column] == 'D'){
								//RETURN BUG
								result = 0;
				    			break;
							}
						}
					}
					else if(direction == 6)
					{
						flag_column = flag_column + 1;
						if(flag_column > 7)
						{
							//RETURN BUG
							result = 0;
			    			break;	
						}
						else
						{
							if(changed_map[flag_row][flag_column] == '.'){
								//RETURN BUG
								result = 0;
				    			break;
							}
							else if(changed_map[flag_row][flag_column] == 'I'){
								changed_map[flag_row][flag_column] = '.';
								flag_column = flag_column - 1;
							}
							else if(changed_map[flag_row][flag_column] == 'C'){
								//RETURN BUG
								result = 0;
				    			break;
							}
							else if(changed_map[flag_row][flag_column] == 'D'){
								//RETURN BUG
								result = 0;
				    			break;
							}
						}
					}
					else if(direction == 8)
					{
						if(flag_row == 0)
						{
							//RETURN BUG
							result = 0;
			    			break;	
						}
						else
						{
							flag_row = flag_row - 1;
							if(changed_map[flag_row][flag_column] == '.'){
								//RETURN BUG
								result = 0;
				    			break;
							}
							else if(changed_map[flag_row][flag_column] == 'I'){
								changed_map[flag_row][flag_column] = '.';
								flag_column = flag_column + 1;
							}
							else if(changed_map[flag_row][flag_column] == 'C'){
								//RETURN BUG
								result = 0;
				    			break;
							}
							else if(changed_map[flag_row][flag_column] == 'D'){
								//RETURN BUG
								result = 0;
				    			break;
							}
						}
					}
			}
			
		}
		
		cout << "\nThis is your map that according to your values:\n";
		for(int e=0; e<8; e++)
	    {
	        for(int d=0; d<8; d++)
	            cout<<" "<<changed_map[e][d];
	        cout<<"\n";
	    }
			
	}

	
	if(result == 0)
	{
		printf("Bug!");
	}
	else
		printf("Diamond!");
		
	
	return 0;
}
