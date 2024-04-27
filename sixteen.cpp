#include<iostream>
#include<vector>
#include<list>
#include<cmath>

using namespace std;

class puzzle{
protected:
	vector<vector<int> > who;
	vector<vector<bool> >posx;
	vector<vector<bool> > posy;
	vector<vector<bool> > posb;
	int size=16;
	vector<vector<int> > her;

public:
	puzzle(){
		for (int j=0;j<size;j++){
			vector<int> temp;
			vector <bool> dummy=standard();
			for (int i=0;i<size;i++){
				char dude;
				cin>>dude;
				int what;
				switch(dude){
					case '0':
						what=0;
						break;
					case '1':
						what=1;
						break;
					case '2':
						what=2;
						break;
					case '3':
						what=3;
						break;
					case '4':
						what=4;
						break;
					case '5':
						what=5;
						break;
					case '6':
						what=6;
						break;
					case '7':
						what=7;
						break;
					case '8':
						what=8;
						break;
					case '9':
						what=9;
						break;
					case 'A':
						what=10;
						break;
					case 'B':
						what=11;
						break;
					case 'C':
						what=12;
						break;
					case 'D':
						what=13;
						break;
					case 'E':
						what=14;
						break;
					case 'F':
						what=15;
						break;
					case 'G':
						what=16;
						break;
				}

				temp.push_back(what);
				if(what>0){
					dummy[what]=true;
				}
			}
			posx.push_back(dummy);
			who.push_back(temp);
		}
		column();
		block();
		intersect();	

	}

	void column(){
		for (int i=0;i<size;i++){
			vector<bool> temp=standard();
			for (int j=0;j<size;j++){
				if (who[j][i]>0){
					temp[who[j][i]]=true;
				}
			}
			posy.push_back(temp);
		}
		//return posy;
	}
	void row(){
		for (int i=0;i<size;i++){
			vector<bool> them=standard();
			for (int j=0;j<size;j++){
				if (who[i][j]>0){
					them[who[i][j]]=true;
				}
			}
			posx.push_back(them);
		}
		
	}
	
	vector<bool> standard(){
		vector<bool> kaiju;
		for (int i=1;i<=size+1;i++){
			kaiju.push_back(false);
		}
		return kaiju;
	}

	void print(){
		/// for printing you can use the same code as the constructor, case 16: cout<<g;
		for (int i=0;i<size;i++){
			for (int j=0;j<size;j++){
				
				//cout<<who[i][j];
				switch(who[i][j]){
					case 0:
						cout<<'0';
						break;
					case 1:
						cout<<'1';
						break;
					case 2:
						cout<<'2';
						break;
					case 3:
						cout<<'3';
						break;
					case 4:
						cout<<'4';
						break;
					case 5:
						cout<<'5';
						break;
					case 6:
						cout<<'6';
						break;
					case 7:
						cout<<'7';
						break;
					case 8:
						cout<<'8';
						break;
					case 9:
						cout<<'9';
						break;
					case 10:
						cout<<'A';
						break;
					case 11:
						cout<<'B';
						break;
					case 12:
						cout<<'C';
						break;
					case 13:
						cout<<'D';
						break;
					case 14:
						cout<<'E';
						break;
					case 15:
						cout<<'F';
						break;
					case 16:
						cout<<'G';
						break;
				}
				if (j!=15){
					cout<<' ';
				}
			}
			cout<<endl;
		}
		//cout<<endl;
	}
	void printher(){
		int count=0;
		/// for printing you can use the same code as the constructor, case 16: cout<<g;
		for (vector<int> hoe:her){
			for (int damn:hoe){
				count++;
				//cout<<who[i][j];
				switch(damn){
					case 0:
						cout<<'0'<<' ';
						break;
					case 1:
						cout<<'1'<<' ';
						break;
					case 2:
						cout<<'2'<<' ';
						break;
					case 3:
						cout<<'3'<<' ';
						break;
					case 4:
						cout<<'4'<<' ';
						break;
					case 5:
						cout<<'5'<<' ';
						break;
					case 6:
						cout<<'6'<<' ';
						break;
					case 7:
						cout<<'7'<<' ';
						break;
					case 8:
						cout<<'8'<<' ';
						break;
					case 9:
						cout<<'9'<<' ';
						break;
					case 10:
						cout<<'A'<<' ';
						break;
					case 11:
						cout<<'B'<<' ';
						break;
					case 12:
						cout<<'C'<<' ';
						break;
					case 13:
						cout<<'D'<<' ';
						break;
					case 14:
						cout<<'E'<<' ';
						break;
					case 15:
						cout<<'F'<<' ';
						break;
					case 16:
						cout<<'G'<<' ';
						break;
				}
				// if (j!=15){
				// 	cout<<' ';
				// }
			}
			cout<<endl;
			//count++;
			//cout<<count<<" wow"<<endl;
		}
		cout<<endl;
		cout<<' '<<count<<endl;
	}

	void block(){
		int low= sqrt(size);
		for (int i=0;i<size;i+=low){
			for(int j=0;j<size;j+=low){
				//block
				vector<bool> temp=standard();
				for (int p=0;p<low;p++){
					for (int m=0;m<low;m++){
						if (who[i+p][j+m]>0){
							temp[who[i+p][j+m]]=true;
						}
					}
					
				}
				posb.push_back(temp);
			}
		}
	}

	// vector<bool> inter(vector<bool> which,vector<bool> when,vector<bool> really){
	// 	vector<bool> it=standard();
	// 	for(int i=0;i<size;i++){
	// 		it[i]=which[i] & when[i] & really[i];
	// 	}
	// 	return it;
	// }

	void intersect(){
		
		for (int i=0;i<size;i++){
			for (int j=0;j<size;j++){
				if (who[i][j]==0){
					int dent;
					if ((i/4)==0){
						if ((j/4)==0){
							dent=0;
						}
						else if((j/4)==1){
							dent=1;
						}
						else if ((j/4)==2){
							dent=2;
						}
						else if((j/4)==3){
							dent=3;
						}
					}
					if ((i/4)==1){
						if ((j/4)==0){
							dent=4;
						}
						else if((j/4)==1){
							dent=5;
						}
						else if ((j/4)==2){
							dent=6;
						}
						else if((j/4)==3){
							dent=7;
						}
					}
					if ((i/4)==2){
						if ((j/4)==0){
							dent=8;
						}
						else if((j/4)==1){
							dent=9;
						}
						else if ((j/4)==2){
							dent=10;
						}
						else if((j/4)==3){
							dent=11;
						}
					}
					if ((i/4)==3){
						if ((j/4)==0){
							dent=12;
						}
						else if((j/4)==1){
							dent=13;
						}
						else if ((j/4)==2){
							dent=14;
						}
						else if((j/4)==3){
							dent=15;
						}
					}
					vector<int>stand;
					for (int u=1;u<=size;u++){
						if (not posy[j][u] && not posx[i][u]&&not posb[dent][u]){
							stand.push_back(u);
						}
					}
					if (stand.size()==1){
						who[i][j]=stand[0];
						//cout<<i<<' '<<j<<endl;
						posx.clear();
						posy.clear();
						posb.clear();
						her.clear();
						row();
						column();
						block();
						//cout<<posb.size()<<endl;
						//cout<<posy.size()<<endl;
						//cout<<posx.size()<<endl;
						intersect();
					}
					her.push_back(stand);
				}

			}

		}

	}


	bool solve(){
		for (int i=0;i<size;i++){
			for (int j=0;j<size;j++){
				int dent;
				if ((i/4)==0){
					if ((j/4)==0){
						dent=0;
					}
					else if((j/4)==1){
						dent=1;
					}
					else if ((j/4)==2){
						dent=2;
					}
					else if((j/4)==3){
						dent=3;
					}
				}
				if ((i/4)==1){
					if ((j/4)==0){
						dent=4;
					}
					else if((j/4)==1){
						dent=5;
					}
					else if ((j/4)==2){
						dent=6;
					}
					else if((j/4)==3){
						dent=7;
					}
				}
				if ((i/4)==2){
					if ((j/4)==0){
						dent=8;
					}
					else if((j/4)==1){
						dent=9;
					}
					else if ((j/4)==2){
						dent=10;
					}
					else if((j/4)==3){
						dent=11;
					}
				}
				if ((i/4)==3){
					if ((j/4)==0){
						dent=12;
					}
					else if((j/4)==1){
						dent=13;
					}
					else if ((j/4)==2){
						dent=14;
					}
					else if((j/4)==3){
						dent=15;
					}
				}
				
				if (who[i][j]==0){
					for (int u=1;u<17;u++){
						//if (posy[j][u]){cout<<"Well, Well, Well "<<u<<endl;}

						if (not posy[j][u] && not posx[i][u]&&not posb[dent][u]){
							who[i][j]=u;
							//print();
							posy[j][u]=true;
							posx[i][u]=true;
							posb[dent][u]=true;
							//print();
							if (solve()){
								return true;
							}
							else{
								who[i][j]=0;
								posy[j][u]=false;
								posx[i][u]=false;
								posb[dent][u]=false;
								
							}
							
							
							// else{
							// 	who[i][j]=0;
							// }
							//solve();
						}
						else{
							continue;
						}

					}
					//backtrack
					//who[i][j]=0;
					return false;
				}

			}

		}
		return true;
	}
	
	bool valid(){
		for (int i=0;i<size;i++){
			for (int j=0;j<size;j++){
				if (who[i][j]==0){
					return false;
				}
			}
		}
		return true;
	}

};

// class possible{
// protected:
// 	list<int *> poses;

// public:
// 	possible(puzzle what){

// 	}



// };
int main(){
	puzzle what;
	if (what.valid()){
		what.print();
	}
	else{
		cout<<"No Solution"<<endl;
	}
}
