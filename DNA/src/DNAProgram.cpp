#include "includes.h"
#include "Classes_and_Functions.h"


template <typename T>
unsigned long long ittrate_node_setvals(NodeArrayOf<T>* node, int range,DNA* dnaptr);


template <typename T>
void ittrate_node_displaay(NodeArrayOf<T>* node, int range,DNA* dnaptr);

template <typename T>
unsigned long long ittrate_node_chain_size(NodeArrayOf<T>* node);

int main() {

    DNA dna;
    OrionFunctions func;
    cout<<"I am getting error"<<endl;
    unsigned long long index = 0;
    srand(time(NULL));

    NodeArrayOf<NucleotidesLink>* Node00 = new NodeArrayOf<NucleotidesLink>(NULL);
    NodeArrayOf<NucleotidesLink>* Node01 = new NodeArrayOf<NucleotidesLink>(Node00);
    NodeArrayOf<NucleotidesLink>* Node02 = new NodeArrayOf<NucleotidesLink>(Node01);
    NodeArrayOf<NucleotidesLink>* Node03 = new NodeArrayOf<NucleotidesLink>(Node02);
    NodeArrayOf<NucleotidesLink>* Node04 = new NodeArrayOf<NucleotidesLink>(Node03);
    NodeArrayOf<NucleotidesLink>* Node05 = new NodeArrayOf<NucleotidesLink>(Node04);
    NodeArrayOf<NucleotidesLink>* Node06 = new NodeArrayOf<NucleotidesLink>(Node05);
    NodeArrayOf<NucleotidesLink>* Node07 = new NodeArrayOf<NucleotidesLink>(Node06);
    NodeArrayOf<NucleotidesLink>* Node08 = new NodeArrayOf<NucleotidesLink>(Node07);
    NodeArrayOf<NucleotidesLink>* Node09 = new NodeArrayOf<NucleotidesLink>(Node08);
    NodeArrayOf<NucleotidesLink>* Node10 = new NodeArrayOf<NucleotidesLink>(Node09);
    NodeArrayOf<NucleotidesLink>* Node11 = new NodeArrayOf<NucleotidesLink>(Node10);
    NodeArrayOf<NucleotidesLink>* Node12 = new NodeArrayOf<NucleotidesLink>(Node11);
    NodeArrayOf<NucleotidesLink>* Node13 = new NodeArrayOf<NucleotidesLink>(Node12);
    NodeArrayOf<NucleotidesLink>* Node14 = new NodeArrayOf<NucleotidesLink>(Node13);
    NodeArrayOf<NucleotidesLink>* Node15 = new NodeArrayOf<NucleotidesLink>(Node14);
    NodeArrayOf<NucleotidesLink>* Node16 = new NodeArrayOf<NucleotidesLink>(Node15);
    NodeArrayOf<NucleotidesLink>* Node17 = new NodeArrayOf<NucleotidesLink>(Node16);
    NodeArrayOf<NucleotidesLink>* Node18 = new NodeArrayOf<NucleotidesLink>(Node17);
    NodeArrayOf<NucleotidesLink>* Node19 = new NodeArrayOf<NucleotidesLink>(Node18);
    NodeArrayOf<NucleotidesLink>* Node20 = new NodeArrayOf<NucleotidesLink>(Node19);
    NodeArrayOf<NucleotidesLink>* Node21 = new NodeArrayOf<NucleotidesLink>(Node20);
    NodeArrayOf<NucleotidesLink>* Node22 = new NodeArrayOf<NucleotidesLink>(Node21);
    NodeArrayOf<NucleotidesLink>* Node23 = new NodeArrayOf<NucleotidesLink>(Node22);
    NodeArrayOf<NucleotidesLink>* Node24 = new NodeArrayOf<NucleotidesLink>(Node23);
    NodeArrayOf<NucleotidesLink>* Node25 = new NodeArrayOf<NucleotidesLink>(Node24);


    index = ittrate_node_setvals<NucleotidesLink>(Node00,22,&dna);
    ittrate_node_displaay<NucleotidesLink>(Node00,1,&dna);


    cout<<func.format_int(index)<<" Links in the DNA Chain"<<endl;
    cout<<index<<" Links in the DNA Chain"<<endl;
    cout<<(ittrate_node_chain_size<NucleotidesLink>(Node00)/1024)<<" kbs of memory used to make chain"<<endl<<"enter number to exit"<<endl;
    cout<<"The size of the node is: "<<sizeof(Node17->Data)+sizeof(Node17)<<endl;
    //cout<<"Size of nunu is "<<sizeof(nunu)<<endl;
    cin>>index;
    return index;
}



template <typename T>
unsigned long long ittrate_node_setvals(NodeArrayOf<T>* node, int range,DNA* dnaptr){
  unsigned long long temp=0;
  for (int i=0; i<=range && node != nullptr; i++){

  for (int x=0; x<node->datarange && node != nullptr;x++){
      dnaptr->Nucleotideslink_Encode(node->get_pointer_at_index(x));
  }
  temp = temp+(node->datarange*15);
  node = node->Next;
  if(node == NULL){return temp;}
}
  return temp;
}

template <typename T>
void ittrate_node_displaay(NodeArrayOf<T>* node, int range,DNA* dnaptr){
  for (int i=0; i<=range && node != nullptr; i++){
      for (int x=0; x<node->datarange && node != nullptr;x++){
	  dnaptr->Nucleotideslink_Display(node->get_pointer_at_index(x));
      }
      node = node->Next;
      if(node == NULL){return;}
}
}


template <typename T>
unsigned long long ittrate_node_chain_size(NodeArrayOf<T>* node){
  unsigned long long size=0;
while(node != nullptr){
  size = sizeof(node)+sizeof(node->Data);
  node = node->next_node(node);
}

  return size;
}
