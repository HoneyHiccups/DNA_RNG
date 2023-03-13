#include "includes.h"



 struct NucleotidesLink{
  unsigned short int encode[3] = {10000,10000,10000}; //the first digigt is to hold the the shape of the data, in adation for passing info that is not dna
  };


class DNA
{
private:

   char CONST_DNAMARKER[4] = {'G','C','A','T'};

   string dnabar0 = " =-------------= ";
   string dnabar1 = " -=============- ";
   string dnabar2 = " -============- ";
   string dnabar3 = " -===========- ";
   string Nucleotideslink_Decrypt(NucleotidesLink *Nucl){ // add an ipuut to change the formating function for filestream and c out
     string code = to_string(Nucl->encode[0])+to_string(Nucl->encode[1])+to_string(Nucl->encode[1]); char _switch_case;
     //char charmark0 = code[0]; char charmark1 = code[5]; char charmark2 = code[10];  // unsused atm but will soon be used to make sore
     string dnaprint; string out = "";
     for (int i = 0; i<=14; i++){  // code will always be a have a fixed length

	  if (i == 0 || i == 5 || i==10){
	      _switch_case = code[i]; //These index are shifted up
	      switch (_switch_case){ // {'G','C','A','T'}
				      //   1   2   3   4
		case '1':
		  dnaprint = "(G)"+dnabar0+"(C)\n";
		  break;
		case '2':
		  dnaprint = "(C)"+dnabar0+"(G)\n";
		  break;
		case '3':
		  dnaprint = "(A)"+dnabar0+"(T)\n";
		  break;
		case '4':
		  dnaprint = "(T)"+dnabar0+"(A)\n";
		  break;
		default:
		  dnaprint = "Big error in switch stament at DNA::Nucleotideslink_Decrypt??? Shifted up call? Switch broken? at index of: "+to_string(i) +"The char of switch";
		  break;
	      }
	     out = out+dnaprint;


	  }else{
	      _switch_case = code[i]; //   0   1  2    3
	      switch (_switch_case){ // {'G','C','A','T'}

		case '0':
		  dnaprint = "(G)"+dnabar1+"(C)\n";
		  break;
		case '1':
		  dnaprint = "(C)"+dnabar1+"(G)\n";
		  break;
		case '2':
		  dnaprint = "(A)"+dnabar1+"(T)\n";
		  break;
		case '3':
		  dnaprint = "(T)"+dnabar1+"(A)\n";
		  break;
		default:
		  dnaprint = "Big error in switch stament at DNA::Nucleotideslink_Decrypt??? Switch broken? at index of: "+to_string(i);
		  break;
	      }
	     out = out+dnaprint;
	  }
     }
     return out;
   }

public:

   void Nucleotideslink_Display(NucleotidesLink *Nucl){
     cout<<Nucleotideslink_Decrypt(Nucl);
   }


    void Nucleotideslink_Encode(NucleotidesLink *Nucl){
      unsigned short int temp = 0;

      for (int i = 0; i<3; i++){
	   temp = rand()%4; temp=temp*10000;	      //These lines are the code overrights the flags and function calls using these
	   Nucl->encode[i] = Nucl->encode[i] + temp;  // will remove the abilty to store function calls and flags that will be interpututed later
	   temp = rand()%4; temp=temp*1000;
	   Nucl->encode[i] = Nucl->encode[i] + temp;
	   temp = rand()%4; temp=temp*100;
	   Nucl->encode[i] = Nucl->encode[i] + temp;
	   temp = rand()%4; temp=temp*10;
	   Nucl->encode[i] = Nucl->encode[i] + temp;
	   temp = rand()%4; temp=temp*1;
	   Nucl->encode[i] = Nucl->encode[i] + temp;
	    //cout<<encode<<endl;
	   temp = 0;
	  }
    }


};

