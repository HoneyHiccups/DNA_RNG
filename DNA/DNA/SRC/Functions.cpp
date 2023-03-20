#include "includes.h"


namespace ofunc{
/*
	void printmesg(string string_input){
	
		std::cout<<string_input<<std::endl;
	
	}

*/

	//This is not working atm sad
	template <typename T>
	string format_int(T Nummber/*Only works with Postive atm*/){
    string str;


    str = to_string(Nummber);
    reverse(str.begin(), str.end());

    const char* str_c = str.c_str();

    constexpr int len = std::numeric_limits<T>::digits10 + 1;//int len = str.length();
    char arr[len+1];

	strcpy_s(arr, len+1, str_c);

	int newlen=((len+1)/3)+(len+1);
    char* newarr = new char[newlen];

    for (int i=0, x=0,ticker=0; !arr[i] == '\0';i++,x++){
	if (ticker == 3){
	    ticker = 0;
	    newarr[x] = ',';
	    i--;
	}else{newarr[x]=arr[i]; ticker++;}
    }

    string out(newarr);

    reverse(out.begin(), out.end());
	delete[] newarr;
    return out;
  }

	template <typename T>
	T sum(T A, T B){
	return A+B;
	}

	template <typename T>
	T sum(T A, T B, T C){
	return A+B+C;
	}

	template <typename T>
	T sum(T A, T B, T C, T D){
	return A+B+C+D;
	}

	template <typename T>
	T sum(T A, T B, T C, T D, T E){
	return A+B+C+D+E;
	}

	template <typename T>
	T sum(T A, T B, T C, T D, T E,T F){
	return A+B+C+D+E+F;
	}

	template <typename T>
	T sum(T A, T B, T C, T D, T E,T F,T G){
	return A+B+C+D+E+F+G;
	}

	template <typename T>
	T sum(T A, T B, T C, T D, T E,T F,T G, T H){
	return A+B+C+D+E+F+G+H;
	}
}