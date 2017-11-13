#include "ofApp.h"
#include "Rule.h"
#include "Queue.h"
#include <fstream>
#include <iostream>

using namespace std;



/*
int ofApp::linearSearch(auto& Data, auto key)
{
  for(auto i = 0u; i < Data.size(); i++)
   {
     if (Data[i].getOfChar() == key)//key found
      return i;
  }
   return -1;//not found
}
*/

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// A function to implement bubble sort
void bubbleSort(auto& Data, auto key)
{
    int i, j;
    for (i = 0; i < key-1; i++)
        // Last i elements are already in place
        for (j = 0; j < key-i-1; j++)
            if (Data[j] > Data[j+1])
                swap(&Data[j], &Data[j+1]);
}

int ofApp::BinarySearch(auto& Data, auto key) {

    
int low = 0, high = Data.size()-1;
int mid;

while (low <= high) 
{ 
        mid = ((high + low)/2);
        if (Data[mid].getOfChar() == key)
        {
            
            return mid;
        }
            if (key < Data[mid].getOfChar()) 
        {
            
            high = mid - 1;
            
        }
        else 
        {

        low = mid + 1;

        }
        
        
    }
                        return -1;
}

void  ofApp::processAxiom()
{

 string str = "";//temporary string to hold "working" copy of axiom
 int where = -1; //store location in the "parallel" vectors fromChars and toStrings

    
    deque<Queue>axioms;
    axioms.push_back(axiom);
    
    for(auto ch = axioms.begin(); ch == axioms.end();)
     
  {
      
      //axioms.push_back(ch);
      where = BinarySearch(rules,axiom.front());//look for ch in fromChars vector
     
     if (where == -1)
     {
     
         
       str += axiom.front(); //ch was not found so its value is not changed in new string
     }
    else // ch was found in fromChars vector
     {
         
       str += rules[where].getToString();//replace ch with corresponding string
     }
  }//end for 

    
    axiom.enqueue(str);
    
}

//--------------------------------------------------------------
void ofApp::setup(){
    // Read input data
    getData();
   

    // Process the Axiom
    for (auto i = 0u; i < N; i++)//N times
      processAxiom();//replace chars in axiom with corresponding strings
}

//--------------------------------------------------------------
void ofApp::update(){

}
//--------------------------------------------------------------
void ofApp::draw(){

ofBackground(0);
ofTranslate(xpos,ypos);
    
    deque<Queue>axiom;

for (auto ch: axiom)//for each character in the axiom string 
{
    switch(ch.front())
    {

        case 'H':
        case 'G':
	case 'C': ofDrawLine(0,0,0,-length);
		  ofTranslate(0,-length);
		  break;

	case 'D': ofPushMatrix();
                  length-=change_len;
                  break;

	case 'E': ofPopMatrix();
                  length+=change_len;
                  break;

	case 'A': ofRotate(angle);break;
	case 'B': ofRotate(-angle);break;
    
    }// end switch
}//end for

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'a') 
	xpos+=10;

    if (key == 'd') 
	xpos-=10;

    if (key == 'w') 
	ypos+=10;

    if (key == 's') 
	ypos-=10;
}


//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

void ofApp::getData()
{
    auto name = std::getenv("myfile");
    auto filename = name? name: "input";

    ifstream in{filename};
    string str = "";
    char ch = '?';

    if(in)//file opened correctly
     {
       in>>length>>change_len>>angle;//no error checking (hope for the best)
       //in>>axiom.front();
       in>>R; 
       
      for(auto i = 0u; i < R; i++)
         {
           in>>ch>>str;//read a character and its replacement string
      
           //place them in "parallel" vectors     
            rules.push_back({ch,str});
         }
      
      in>>N;

     }else throw ifstream::failure("Error opening file: " + string{filename});   
}


