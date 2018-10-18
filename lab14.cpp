#include <iostream>
#include <string.h>
using namespace std;

//--------------------------------------------------------------------------------
class Node {
    public:
        // Constructors
        Node()
        {
            livingIndex = 0;
            pNext = NULL;
        }
    
        Node(int inputCityName, int data, Node *pNext)
        {
            this->cityName = inputCityName;
            this->livingIndex = data;
            this->pNext = pNext;
        }
    
        // Accessors and Setters
        string getCityName()
        {
            return cityName; 
        }
        int getLivingIndex()
        {
            return livingIndex; 
        }

        Node *getNext(){ 
            return pNext; 
        }

        void setCityName(string inputCityName)
        {
            cityName = inputCityName;
        }

        void setLivingIndex(int ind)
        {
            livingIndex = ind; 
        }

        void setNext( Node *pNext)
        { 
            this->pNext = pNext;
        }
    
    private:
        string cityName;
        int livingIndex;        // The data being stored at the node
        Node *pNext;     // Pointer to the next node
};

/*Display list in order reverse as input
For example: if city is enter in the below order
CHI 5
NY 4
DAL 7
END 1
It should be display as follow:
DAL 7
NY 4
CHI 5
*/
void displayList( Node *pHead)
{
    if (pHead != NULL){
        displayList(pHead->getNext());
        cout << pHead->getCityName() << " " << pHead->getLivingIndex() << endl;
    }
}

/*Display list in order same as input
For example: if city is enter in the below order
CHI 5
NY 4
DAL 7
END 1
It should be display as follow:
CHI 5
NY 4
DAL 7
*/
void displayListAsInput(Node *pHead)
{
    Node *pTemp = pHead;
    while (pTemp != NULL){
        cout << pTemp->getCityName() << " " << pTemp->getLivingIndex() << endl;
        pTemp = pTemp->getNext();
    }
}

//--------------------------------------------------------------------------------
int main()
{
    //int livIndex = 0;      // Used to store numbers read in
    char name[20];
    Node *pHead = NULL;  // head of linked list
    Node *pTemp;         // used in new node creation
    string tempCityName;
    int tempLivingIndex;
    
    cout << "Welcome to lab 14. Please enter a list of cities and their cost of living index" << endl;
    cout << "To end your input, enter the last item as \"end 1\"" << endl;
    
    //Write a loop to enter multiple cities with their cost of living Index
    pHead = new Node;
    pTemp = pHead;
    
    // First Input
    cin >> tempCityName >> tempLivingIndex;
    if (tempCityName != "end" || tempLivingIndex != 1){
        pTemp->setCityName(tempCityName);
        pTemp->setLivingIndex(tempLivingIndex);
    }
    
    while(true){
        cin >> tempCityName >> tempLivingIndex;
        if ((tempCityName == "end" || tempCityName == "END") && tempLivingIndex == 1){
            break;
        }
        pTemp->setNext(new Node);
        pTemp = pTemp->getNext();
        pTemp->setCityName(tempCityName);
        pTemp->setLivingIndex(tempLivingIndex);
    }
    
    cout << endl;
    pTemp = pHead;
    cout << "Display in reverse order same as input"<< endl;
    displayList(pTemp);
    cout << endl;
    cout << "Display in order same as input"<< endl;
    displayListAsInput(pTemp);
    
    return 0; 
}