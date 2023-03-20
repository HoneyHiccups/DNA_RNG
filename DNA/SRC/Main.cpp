#include "includes.h"
#include "Classes_and_Functions.h"


// Dear ImGui: standalone example application for GLFW + OpenGL 3, using programmable pipeline
// (GLFW is a cross-platform general purpose library for handling windows, inputs, OpenGL/Vulkan/Metal graphics context creation, etc.)
// If you are new to Dear ImGui, read documentation from the docs/ folder + read the top of imgui.cpp.
// Read online: https://github.com/ocornut/imgui/tree/master/docs

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
//#include <stdio.h>
#define GL_SILENCE_DEPRECATION
#if defined(IMGUI_IMPL_OPENGL_ES2)
#include <GLES2/gl2.h>
#endif
#include <glfw3.h> // Will drag system OpenGL headers



template <typename T>
unsigned long long ittrate_node_setvals(NodeArrayOf<T>* node, int range,DNA* dnaptr);

template <typename T>
void ittrate_node_displaay(NodeArrayOf<T>* node, int range,DNA* dnaptr);

template <typename T>
unsigned long long ittrate_node_chain_size(NodeArrayOf<T>* node);

template <typename T>
void createnodes(NodeArrayOf<T>* node, int range);

template <typename T>
void destorynodes(NodeArrayOf<T>*& node, int range);

// Main code


int main(){


    DNA dna;
    cout<<"Creating Nodes"<<endl;
    unsigned long long index = 0;
    srand(time(NULL));
    
    NodeArrayOf<NucleotidesLink>* NODE_INDEX[1000];// create an array of 10 pointers to NodeArrayOf
    //NodeArrayOf<NucleotidesLink>** CONST_NODE_INDEX = new NodeArrayOf<NucleotidesLink>*[1000]; // this is the heap alloc 
    //not sure if I need to use that however I will allso need to destory the pointers if needed 
    // delteing the alloc memmory if need for the  dma//
    //for (int i = 0; i < 1000; i++) {delete CONST_NODE_INDEX[i];}delete[] CONST_NODE_INDEX;

    for (int i = 999; i>=0; i--){NODE_INDEX[i] = NULL;}
    
    //------------ TO DO -----------//
    //Some things that needed to be added is to clear the memory of the node network atm it dose not have a clear function
    //In addation I will be adding some gui interface to set how big of a node network the user woulf like
    //Then I will work on gui for displaying instead of using a cout function call 
    //Maybe stream imagines or maybe 3d not sure yet 
    
    
    NodeArrayOf<NucleotidesLink>* CurrentNode = new NodeArrayOf<NucleotidesLink>(NULL);
    

    for (int i = 0; i<600; i++){
        NODE_INDEX[i] = CurrentNode;  CurrentNode = CurrentNode->new_node();
       // odd that I am storing a an index of the bouble linked list, however it is just a reflection and 
       //is not to be completly acurete I will be using it as a bookmark function I will switch null when editing linked list
      // this will allow for accsing parts on the list quickly however in an inverted binaray search
          
    }
    





    index = ittrate_node_setvals<NucleotidesLink>(NODE_INDEX[0],1000,&dna);
    ittrate_node_displaay<NucleotidesLink>(NODE_INDEX[0],1,&dna);


    cout<<ofunc::format_int<unsigned long long>(index)<<" Links in the DNA Chain"<<endl;
    cout<<(ittrate_node_chain_size<NucleotidesLink>(NODE_INDEX[0])/1024)<<" kbs of memory used to make chain"<<endl<<"enter number to exit"<<endl;
    
    //for (int i = 0; i < 1000; i++) {delete CONST_NODE_INDEX[i];}delete[] CONST_NODE_INDEX;
    return 0;
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

template <typename T>
void createnodes(NodeArrayOf<T>* node, int range){
    node[0]= new NodeArrayOf<NucleotidesLink>(NULL);
    for(int i = 1; i <= range; i++ ){
        node[i]= new NodeArrayOf<NucleotidesLink>(node[i-1]);
    }
}

template <typename T>
void destorynodes(NodeArrayOf<T>*& node, int range){

    for(int i = range; i>= 0; i--){
    node->destroy();
    }
}

 