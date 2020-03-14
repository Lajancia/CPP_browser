#include <iostream>
using namespace std;


const int MAX_SIZE=50;
class Web_browser{
	string addr_arr[MAX_SIZE];
	string addr_history[MAX_SIZE];

	int current;
	int length;
	int his;
public:
	Web_browser(){
		current=0;
		his=0;
	addr_arr[current]="http://ces.hufs.ac.kr";
	addr_history[current]="http://ces.hufs.ac.kr";
	length=1;
	cout<<get_current_addr()<<endl;
	}
	void go(string addr){

		his++;
		addr_history[his]=addr;
		if(addr!=addr_arr[current]){
		if( length<MAX_SIZE-1){

			current++;
		addr_arr[current]=addr;
		length++;//think
		while(length>current+1){
			length--;

		}
		cout<<addr_arr[current]<<endl;
	}
		}
		else cout<<addr_arr[current]<<endl;

	}
	void forward(){
		
		if(current<length-1){
		current++;
		cout<<addr_arr[current]<<endl;
	}
		else cout<<addr_arr[current]<<endl;
	
	}
	void backward(){
	

		if(current>=1){

		current--;
	cout<<addr_arr[current]<<endl;
	}
		else {

			cout<<addr_history[0]<<endl;


		}

		
	}
	void home(){
	
		his++;
				addr_history[his]=addr_arr[0];

	
				if( length<MAX_SIZE-1){
	
					current++;
				addr_arr[current]=addr_arr[0];
				length++;//think
				while(length>current+1){
					length--;

				}
				cout<<addr_arr[current]<<endl;
			}


		
	}

	void set_home(string add){
		addr_arr[0]=add;

	}
	void history(){


		if(his<=10){
			if(his==0){
				cout<<addr_history[0]<<endl;

			}

			else for(int i=0;i<=his;i++){
			cout<<addr_history[i]<<endl;
		}
		}
		else for(int i=his-9 ;i<=his;i++){
			cout<<addr_history[i]<<endl;

		}

	}

	string get_current_addr(){
		return addr_arr[current];
	}

};

int main(){
	Web_browser wb;
	string command;
	string addr;
	string EXITCMD="quit";

	while(cin>>command){
		if(command==EXITCMD){
			break;
		}
		else if(command=="go"){
			cin>>addr;
			wb.go(addr);
		}
		else if(command=="forward"){
			wb.forward();
		}
		else if(command=="backward"){
			wb.backward();
		}
		else if(command=="home"){
			wb.home();
		}
		else if(command=="set_home"){
			cin>>addr;
			wb.set_home(addr);
		}
		else if(command=="history"){
			wb.history();
		}


	}
	return 0;
}



