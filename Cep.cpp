#include<iostream>
#include<fstream>
#include<cmath>
#include<string>
#include<unistd.h>
using namespace std ;

int statusofb = 1 ; //globle variables
int statusofO = 1  ;

///////////////////////////////class no 1 //////////////////////////////// 
class SignUpService{
//Members of class 
   protected:
	long long int ID ; 
	string  Password ; 
public:	
//Default Constructor 
	SignUpService(){
		ID= 0 ; 
		Password = "0" ; 
	}
//Function to get and save data in file 
void SetSignup(){
	fstream SignupFile1("Dataofcustomer.txt",ios::app) ; ;//File creatiion 
	fstream SignupFile("Dataofcustomer.txt",ios::in) ; ;//File input
	cout<<"Please Enter your ID Card no:" ; 
	jump:
	cin>>ID ;
	   long long Id ; 
		string password ; 
		
		while(!SignupFile.eof())
		{    
		     SignupFile >> Id >> password  ; 
			  if(ID==Id)
			{
				cout<<"This Acc already exists."<<endl  ;
				cout<<"Please try another  ID Card no:" ;
				
				goto jump ;
			}	 
		}
	 
	cout<<"Please Enter a password:";
	cin>>Password ;
	
	
	SignupFile1 << ID  << endl  << Password << endl  ; 
	cout<<"\t\t\t Thank You for signing up.You are now registered. "<<endl  ;
	
	 
	SignupFile.close() ;//File closed  
	SignupFile1.close() ;//File1  closed  
	
}			
};  

//////////////////////////////////////Inherited class//////////////////////// 
class LoginService:public SignUpService {
//all themembers of signup are inherited in this class 	
	
	public:
		
	void checkCustomer(){
	fstream businessbooked ;
    businessbooked.open("Businessbooked.txt" ,  ios::in) ; 
	fstream OrdinaryBooked;
    OrdinaryBooked.open("Ordinarybooked.txt" ,  ios::in) ; 
	
	string password ; 
	long long Id; 
	ifstream checkFile ;
	checkFile.open("Dataofcustomer.txt", ios::in) ;   //same file that stored our sign up data 
    int Attempts= 2 ; 
	for(int i=1  ; i<=3 ; i++){
	checkFile >> ID >> Password ;
	cout<< "\t\t\t Login menu" << endl ; 	
	cout<< "\t\t\t-------------" << endl<<endl <<endl  ; 	
	cout<<"Enter your ID:" ;
	cin>>Id ;
	if(Id==ID ){
	cout<<"Account Found."<<endl ;
	jump:
	cout<<"Enter your Password:" ;
	cin>>password  ; 
	if(password!=Password ){
		cout<<"Incorrect Password.Try Again:" ; 
		goto jump ;
	}
	else{
	cout<<"\t\t\t Succesfully loged in."<< endl << endl <<endl   ;
	sleep(1) ;  	
	system("CLS") ; 
jump1:
cout<<"\t\t\t Order Taxi Menu " << endl ; 
cout<<"\t\t\t -----------------"<<endl << endl ; 
cout<<"Which Type of Car do you want:"<< endl ; 
int classselect ; 
cout<<"\t\t\t *Press 1 for Business class."<<endl ; 
cout<<"\t\t\t *Press 2 for Ordinary class."<<endl ; 
jump4:
cout << "Choose either(1/2):" ; 
cin >> classselect ; 
if(classselect==1){
	cout<<"\n\nThe Business Class Detailes are fixed and are as follows:\n"; 
	char ch  ;
	ifstream showCarB ; 
	showCarB.open("showCarB.txt",ios::in) ; 
	showCarB.get(ch) ; 
	while(!showCarB.eof()){
		 cout<< ch ; 
		 showCarB.get(ch) ; 
	}
	
	string  ch1 ; 
	cout<<"\n\n Do you want to book Business class car(yes/no):" ;
	cin>>ch1 ;
	cout<< endl << endl ; 
	if(ch1=="yes" || ch1=="YES"){	
    	
		if( statusofb == 1  ){           
		cout<<"YOUR RIDE HAS BEEN BOOKED.ITS OWN OTS WAY  !"  << endl  ;
		char ch[35] ; 
		businessbooked.seekg(ios::beg) ;
		businessbooked.read(ch , 35) ; 
		cout<< ch  << endl ;
		cout<< "YOUR TOTAL BILL WILL BE CALCULATED AFTER THE RIDE ENDS.THANK YOU " << endl << endl  ;
	    businessbooked.seekg(35 , ios::beg ) ; 
        ::statusofb++   ; // changing globale variable   

	 }
        else if(statusofb == 2){               
        cout<<"YOUR RIDE HAS BEEN BOOKED.ITS OWN OTS WAY  !"  << endl ;
		businessbooked.seekg(35 , ios::beg) ;			 
        businessbooked.seekg(1 , ios::cur ) ;
    	char ch1[35] ;
	    businessbooked.read(ch1 , 35) ; 
		cout<< ch1  << endl ;
		cout<< "YOUR TOTAL BILL WILL BE CALCULATED AFTER THE RIDE ENDS.THANK YOU " << endl << endl  ;
    	 ::statusofb++   ; // changing globale variable   
   	 
}
else {  cout<<"Sorry no rides available for now try later or  try our other class !"<< endl  ; 

}
 	} 
		
	  else{             // This else is if customer say no instead of yes 
	   system("CLS") ; 
	   goto jump1; 
	  }

showCarB.close() ; 
}
else if(classselect==2){
	cout<<"The Ordinary Class Details are:"<< endl ; 
	char ch  ;
	ifstream showCarO ; 
	showCarO.open("showCarO.txt",ios::in) ; 
	showCarO.get(ch) ; 
	while(!showCarO.eof()){
		 cout<< ch ; 
		 showCarO.get(ch) ; 
	}
	
	string  ch1 ; 
	cout<<"\n\n Do you want to book ordinary class car(yes/no):" ;
	cin>>ch1 ;
	cout<< endl << endl ; 
	if(ch1=="yes" || ch1=="YES"){	
    	
		if( statusofO == 1  ){           
		cout<<"YOUR RIDE HAS BEEN BOOKED.ITS OWN OTS WAY  !"  << endl  ;
		char ch[35] ; 
		OrdinaryBooked.seekg(ios::beg) ;
	    OrdinaryBooked.read(ch , 35) ; 
		cout<< ch  << endl ;
		cout<< "YOUR TOTAL BILL WILL BE CALCULATED AFTER THE RIDE ENDS.THANK YOU " << endl << endl  ;
	    OrdinaryBooked.seekg(35 , ios::beg ) ; 
		::statusofO++ ; 
     
	 }
        else if(statusofO == 2){               
        cout<<"YOUR RIDE HAS BEEN BOOKED.ITS OWN OTS WAY  !"  << endl ;
		OrdinaryBooked.seekg(35 , ios::beg) ;			 
        OrdinaryBooked.seekg(1 , ios::cur ) ;
    	char ch1[35] ;
	    OrdinaryBooked.read(ch1 , 35) ; 
		cout<< ch1  << endl ;
		cout<< "YOUR TOTAL BILL WILL BE CALCULATED AFTER THE RIDE ENDS.THANK YOU " << endl << endl  ;
		::statusofO++ ; 
	    	 
}
  else { 
 cout<<"Sorry no rides available for now try later or  try our other class !"<< endl  ; 
}
 	} 
		
	  else{             // This else is if customer say no instead of yes 
	   system("CLS") ; 
	   goto jump1; 
	  }

showCarO.close() ; 

}	
else{
	cout<<"Incorrect no.Try again!"<< endl ; 
	goto jump4 ; 
}	
	 	
	
}
	   break ; 
      	}	
	else{
	cout<<"Account not found try another id."<<endl ; 
	cout<<"Attempts remaining:"<<Attempts --  <<endl ; 
	if(i==3)
	{
	cout<<"You must Sign up First!" << endl ; 
}
	
	}

} // far loop ends 
checkFile.close() ; 
}


};

//////////////////////////////main function//////////////////////////////////////////
int main(){
	system("color 70");
	cout<<endl << endl << endl << "\t\t\t WELCOME TO TAXI REGISTRATION SYSTEM "<<endl ; 
	cout<<"\t\t\t ------------------------------------" << endl<< endl  ; 
	cout<<"\t\t\t Loading..."<<endl ;
	sleep(2);
	system("CLS") ;
	int press ;
	SignUpService S;//Acc creation class object
	
do{  
	 
    system("CLS"); 
	cout<<"\t\t\t  Main Menu   " << endl ; 
 	cout<<"\t\t\t -------------" << endl ; 
 	cout<<endl <<endl  ; 
	cout<<"\t\t *Press 1  for sign up."<<endl ; 
	cout<<"\t\t *Press 2  for  log in if you have an account."<<endl ;  
	cout<<"\t\t *Press 3 for Exit."<<endl ;  
	cin>> press ; 
	switch(press){
	case 1:
	system("CLS") ; 
	cout<<"\t\t\t  Registration  menu!" << endl  ;
	cout<< "\t\t\t ---------------------" << endl << endl ; 	
	
	S.SetSignup() ;//calling function of class
	system("pause");	
 	break ; 
	case 2:
	system("CLS") ;
	LoginService L ;
	L.checkCustomer() ;
	sleep(1) ; 
	system("pause");	
	break ;
	}
}
while(press<3) ;
system("CLS") ; 
cout<<"PRESS ENTER TO EXIT ." << endl << endl ; 
	return 0 ; 
	
}
