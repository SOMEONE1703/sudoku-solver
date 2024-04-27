#include<iostream>
#include<vector>
#include<list>
#include<cmath>
#include<chrono>

using namespace std;

class puzzle{
protected:
	vector<vector<int> > who;
	vector<vector<bool> >posx;
	vector<vector<bool> > posy;
	vector<vector<bool> > posb;
	int size=9;
	vector<vector<int> > her;

public:
	puzzle(){
		for (int j=0;j<size;j++){
			vector<int> temp;
			vector <bool> dummy=standard();
			for (int i=0;i<size;i++){
				int what;
				cin>>what;
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
		for (int i=0;i<size;i++){
			for (int j=0;j<size;j++){
				cout<<who[i][j];
				if (j!=8){
					cout<<' ';
				}
			}
			cout<<endl;
		}
		//cout<<endl;
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



	void intersect(){
		
		for (int i=0;i<size;i++){
			for (int j=0;j<size;j++){
				if (who[i][j]==0){
					int dent;
					if ((i/3)==0){
						if ((j/3)==0){
							dent=0;
						}
						else if((j/3)==1){
							dent=1;
						}
						else if ((j/3)==2){
							dent=2;
						}
					}
					if ((i/3)==1){
						if ((j/3)==0){
							dent=3;
						}
						else if((j/3)==1){
							dent=4;
						}
						else if ((j/3)==2){
							dent=5;
						}
					}
					if ((i/3)==2){
						if ((j/3)==0){
							dent=6;
						}
						else if((j/3)==1){
							dent=7;
						}
						else if ((j/3)==2){
							dent=8;
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

bool checkrc(int num,int currow,int currcol){
		for (int i=0;i<size;i++){
			if(who[currow][i]==num){
				return false;
			}
		}
		for (int i=0;i<size;i++){
			if(who[i][currcol]==num){
				return false;
			}
		}
		return true;
	}


	bool checkb(int num,int currow,int currcol){
		int low=sqrt(size);
	
		int offsetr=currow/low;
		int offsetc=currcol/low;
		for (int i=0;i<low;i++){
			for (int j=0;j<low;j++){
				if ((3*offsetr)+i==currow && (3*offsetc)+j==currcol){
					continue;
				}
				else if (who[(3*offsetr)+i][(3*offsetc)+j]==num){
					return false;
				}
			}
		}
		return true;
	}




	bool solve(){
		for (int i=0;i<size;i++){
			for (int j=0;j<size;j++){
				int dent;
					if ((i/3)==0){
						if ((j/3)==0){
							dent=0;
						}
						else if((j/3)==1){
							dent=1;
						}
						else if ((j/3)==2){
							dent=2;
						}
					}
					if ((i/3)==1){
						if ((j/3)==0){
							dent=3;
						}
						else if((j/3)==1){
							dent=4;
						}
						else if ((j/3)==2){
							dent=5;
						}
					}
					if ((i/3)==2){
						if ((j/3)==0){
							dent=6;
						}
						else if((j/3)==1){
							dent=7;
						}
						else if ((j/3)==2){
							dent=8;
						}
					}


				if (who[i][j]==0){
					for (int u=1;u<10;u++){
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

};





// };
int main(){
	puzzle what;
	//auto start = std::chrono::high_resolution_clock::now();
	if (what.solve()){
		what.print();
	}
	else{
		cout<<"No Solution"<<endl;
	}
	// auto finish = std::chrono::high_resolution_clock::now();
	// std::chrono::duration<double> elapsed = finish - start;
	// std::cout << "Elapsed time: " << elapsed.count() << " s\n";
}
