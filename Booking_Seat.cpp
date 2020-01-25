#include<iostream>
#include<fstream>
#include<string>
#define MAXSIZE 60

using namespace std;

struct seat{									//Create a Structure
	string rowNo;
	string type;
	string seats;
};

class flight{									//Create flight class 
	private:
		string fNo;								//Declare private varibles
		string Date_Time;
		string Dep_Airport;
		string Arr_Airport;
	
	public:
		seat array[60];							//Create structure array
		void setFNo(string a);					//Declare member functions
		void setDate_Time(string a);
		void setDep_Airport(string a);
		void setArr_Airport(string a);
		void setArray(string a, int j);
		string getFNo();
		string getDate_Time();
		string getDep_Airport();
		string getArr_Airport();
		void availableFlight();
};

int line_counter;								//Declare global variables
int arrayEcount[MAXSIZE];
int arrayBcount[MAXSIZE];
int flight_counter= 0;
int count[65];									//Create count array

void flight::setFNo(string a){					//Create set functions to set the data to class variables
	fNo = a;	}

void flight::setDate_Time(string a){
	Date_Time = a;	}

void flight::setDep_Airport(string a){
	Dep_Airport = a;	}

void flight::setArr_Airport(string a){
	Arr_Airport = a;	}

void flight::setArray(string a, int j){			//Create to seat structure array
	int spacePlaceArray[2];
	int pos=0;
	flight f;

	for(int i=0;i<a.length();i++){				//Space index get to spacePlaceArray
		if(a[i]==' '){
			spacePlaceArray[pos]=i;
			pos++;
		}
	}

	array[j].rowNo = a.substr(0,spacePlaceArray[0]);					//Call substr functions to fill the structure array
	array[j].type= a.substr(spacePlaceArray[0]+1, 1);
	array[j].seats= a.substr(spacePlaceArray[1]+1);
	//cout << array[j].rowNo << ends << array[j].type << ends << array[j].seats << endl;	
}

string flight::getFNo(){ 						//Create get functions to use private variables in class
	return fNo;		}

string flight::getDate_Time(){
	return Date_Time;	}

string flight::getDep_Airport(){
	return Dep_Airport;		}

string flight::getArr_Airport(){
	return Arr_Airport;		}

int main(){										//main function
	string str;
    fstream file1; 
    flight_counter = 0;
    file1.open("flights.txt",ios::in); 
    
	if(!file1.is_open()){
    	cout<<"cannot open the file"<<file1<<endl;
    	return false;
	}
	
    while (!file1.eof()){ 							//Getting a flight counter
        getline(file1,str);
        if(str.empty()){ 
    		flight_counter++;
		}
    } 
    file1.close();                                 //Close The File at first time
    
    ifstream file;   							   //File open at second time
	file.open("flights.txt");
	string line;
	
	flight f[flight_counter];
	int i=0;
	
	while(!file.eof()){
		getline(file, line);						//call getline function
		line_counter=1;
			while(!line.empty()){
				
				if(line_counter==1){
					f[i].setFNo(line);
				}
				else if(line_counter==2){
					f[i].setDate_Time(line);
				}
				else if(line_counter==3){
					f[i].setDep_Airport(line);
				}
				else if(line_counter==4){
					f[i].setArr_Airport(line);
				}
				else if(line_counter>4){
					f[i].setArray(line, line_counter-5);
				}
				
				getline(file, line);
				line_counter++;
				
			}
			count[i]=line_counter;
		i++;
	}
int e_count=0, b_count=0;
int E_arr[flight_counter], B_arr[flight_counter];
	for(int i=0; i<flight_counter; i++){
		for(int j=0; j<count[i]-5; j++){

			if(f[i].array[j].type=="B"){
				b_count= b_count + f[i].array[j].seats.length();
				B_arr[i]=b_count;
			}
			else if(f[i].array[j].type=="E"){
				e_count= e_count + f[i].array[j].seats.length();
				E_arr[i]=e_count;
			}
			
		}
			B_arr[i]= b_count;
			E_arr[i]= e_count;
			b_count=0;
			e_count=0;
//	cout<<E_arr[i]<<endl;
//	cout<<B_arr[i]<<endl;
	
	}
	
	///////////////////////////////////////////////////////////////////////////////////////////////////////
	
	int ch;
	string num;
	char sa;
	string raw, class_type; 
	int seats;
	while(ch!=5){
		
		cout << endl;
		/////////////////////////////////////////////////////////////////////////////////////////////
		
		/////////////////////////////////////////////////////////////////////////////////////////////
		cout << "\t<<<<[	Welcome to Virgin Airline!!!	]>>>>" << endl;
		cout << "\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl << endl;
		cout << "    --...You can booking tickets using this program...--"  << endl << endl;
		cout << "   1.Display available flights." << endl;
		cout << "   2.View flight." << endl;
		cout << "   3.Seat availability." << endl;
		cout << "   4.Seat booking." << endl;
		cout << "   5.End" << endl;
		cout << " Please enter your choice= ";
		cin >> ch;
		
		switch(ch){
			case 1:
				for(int k=0; k<flight_counter; k++){
					if(E_arr[k]==0 && B_arr[k]==0){
						return 0;
					}
					else{
						cout << " Flight Number:   " << f[k].getFNo() << endl;
						cout << " Depdate & time:   " << f[k].getDate_Time() << endl;
						cout << " Departure airport:   " << f[k].getDep_Airport() << endl;
						cout << " Arrival airport:   " << f[k].getArr_Airport() << endl;
						cout << " Number of sheets in E class= " << E_arr[k] << endl;
						cout << " Number of sheets in B class= " << B_arr[k] << endl;
						cout << "**************" << endl;
						for(int j=0; j<count[k]-5; j++){
							if(f[k].array[j].seats!="\0"){
								cout << f[k].array[j].rowNo << "  |  " << f[k].array[j].type << "  |  " << f[k].array[j].seats << endl;
							}
						}
						cout << endl;
						
					}
				} 
				break;
			case 2:
				int flag;
				flag=0;
				cout << " Please enter flight number= ";
				cin >> num;
				int c;
				for(int k=0; k<flight_counter; k++){
					if(num==f[k].getFNo()){
						flag=1;
						c= k;
					}
					else{
					}
				}
				if(flag==1){
					cout  << endl;
					cout << " Dep date & time: " << f[c].getDate_Time() << endl;
					cout << " Departure Airport: " << f[c].getDep_Airport() << endl;
					cout << " Arrival Airport: " << f[c].getArr_Airport() << endl;
					cout << " Number of sheets in E class= " << E_arr[c] << endl;
					cout << " Number of sheets in B class= " << B_arr[c] << endl;
					flag=0;
				}
				else{
					cout << "    ERROR!!!" << endl;
					cout << " This flight is not here.." << endl;
				}
				break;
			case 3:
				int flag2;
				flag2= 0;
				cout << " Please enter your flight number= ";
				cin >> num;
				cout << " Please enter number of seats required= ";
				cin >> seats;
				for(int k=0; k<flight_counter; k++){
					if(num==f[k].getFNo()){
						flag2 =1;
						c= k;
					}
					else{
					}
				}
				if(flag2==1){
					if(seats<=E_arr[c]+B_arr[c]){
							cout << endl << " Flight seats details:  " << endl;
							cout << "Number of seats in B class= " << B_arr[c] << endl;
							cout << "Number of seats in E class= " << E_arr[c] << endl;
							cout << " R:row no C:class S:seats" << endl;
							cout << "R  |  C  |  S" << endl;
						for(int j=0; j<count[c]-5; j++){
							if(f[c].array[j].seats!="\0"){
							cout << f[c].array[j].rowNo << "  |  " << f[c].array[j].type << "  |  " << f[c].array[j].seats << endl;
							}
						}
					}
					else{
						cout << "Sorry.. You cannot provide amount of seats you need." << endl;
					}
					flag2=0;
				}
				else{
					cout << "ERROR!!!" << endl;
					cout << "This flight is not here.." << endl;
				}
				break;
			case 4:{
			
				int flag3=0;
				int flag4=0;
				int flag5=0;
				int flag6=0;
				int flag7=0;
				int flag10=0;
				cout << "Please enter your flight number: ";
				cin >> num;
				int d;
				for(int k=0; k<flight_counter; k++){
					if(num==f[k].getFNo()){		
						flag3=1;			
						cout << "Please enter raw : ";
						cin >> raw;
						d=k;	
					for(int l=0; l<count[d]-5; l++){
						if(f[d].array[l].rowNo==raw ){
							flag5=1;                            				 //ROW
								cout << "Please enter Class : ";
								cin >>class_type;
							{
								if( f[d].array[l].type==class_type){
									flag6=1;	
									cout << "Please enter Seat : ";
									cin >>sa;									//type
									for(int k=0;k<8;k++){
										if(sa=='A'||sa=='B'||sa=='C'||sa=='D'||sa=='E'||sa=='F'){
											flag10= 1;
											if(f[d].array[l].seats[k]==sa){
												flag7=1;							//seat
												int pos=f[d].array[l].seats.find(sa);
												f[d].array[  l].seats.erase(pos,1);
												cout << "Booking Successful..." << endl;
												cout << "*************" << endl;
												if(class_type=="E")
													E_arr[d]=E_arr[d]-1;
												else if(class_type=="B")
													B_arr[d]=B_arr[d]-1;
											}
										}
									}
								}
							}
						}
					}
				}
			}
					if(flag3==0){
					    	cout<<"Wrong flight Number"<<endl;
					}
					else if(flag5==0){
					    	cout<<"Wrong Row Number"<<endl;
					}
					else if(flag6==0){
					    	cout<<"Wrong Class "<<endl;
					}
					else if(flag10==0){
							cout<<"Wrong seat.... Please enter a letter between A and F.!!" << endl;
					}
					else if(flag7==0){
					    	cout<<"This seat is not available...."<<endl;
					}
					
			break;
			
			}
			case 5:
			{
				ofstream file;
				file.open("flight_sample.dat", ofstream::out | ofstream::trunc);
				
				for(int i=0; i<flight_counter; i++){
					file << f[i].getFNo() << endl;
					file << f[i].getDate_Time() << endl;
					file << f[i].getDep_Airport() << endl;
					file << f[i].getArr_Airport() << endl;
					for(int j=0; j<count[i]-5; j++){
						if(!f[i].array[j].seats.empty()){
							file << f[i].array[j].rowNo << " " << f[i].array[j].type << " " << f[i].array[j].seats << endl;
						}
						else{
							continue;
						}
						
					}
					file << endl;
				}
				file.close();
				break;
			}
			
			default:
				cout << "Invalid input..." << endl;
				system("pause");
				break;
		}	}

	return 0;
}

