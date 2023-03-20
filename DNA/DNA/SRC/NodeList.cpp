#include "includes.h"

template <typename T>/// type of data stored
struct NodeArrayOf{
  /*
  static:
  static unsigned int arrayamount = 1024;
  public:
  */
  T Data[30000];
  unsigned short datarange = 30000;

  NodeArrayOf *Past = NULL;
  NodeArrayOf *Next = NULL;

  T* get_pointer_at_index(int index){
    if(index>datarange){return &Data[index-datarange];}
    return &Data[index];
  }

  NodeArrayOf(NodeArrayOf *PrevioListNode){ // constructor sets pointer to past
     this->Past = PrevioListNode;
     this->Next = NULL;

     if(Past != NULL){
	Past->Next = this;
     }
  }

  NodeArrayOf* next_node(NodeArrayOf* index){ //returns pointer to next
    return index->Next;
  }

  NodeArrayOf* past_node(NodeArrayOf* index){  //returns pointer to past
    return index->Past;
  }


  NodeArrayOf* new_node(){
    
      this->Next = new NodeArrayOf<T>(this);

    return this->Next;  
  }

  void destroy(){ // should only be called in an tterration soon to be depecrated 
  delete this;
  }
};

