#include "includes.h"

struct OrionFunctions {

  template <typename T>
string format_int(T Nummber/*Only works with Postive tm*/){
    string str;


    str = to_string(Nummber);
    reverse(str.begin(), str.end());

    const char* str_c = str.c_str();

    int len = str.length();
    char arr[len+1];

    for (int i = 0; i < len; i++) {
        arr[i] = str_c[i];
    }
    arr[len] = '\0';
    char newarr[((len+1)/3)+(len+1)];

    for (int i=0, x=0,ticker=0; !arr[i] == '\0';i++,x++){
	if (ticker == 3){
	    ticker = 0;
	    newarr[x] = ',';
	    i--;
	}else{newarr[x]=arr[i]; ticker++;}
    }

    string out(newarr);

    reverse(out.begin(), out.end());

    return out;
  }

};
