//Patricia Antlitz - reflector
//Michael Earley - presenter
//Khiel Mantilla - recorder // Khiel wrote all notes
//Yan Ngo - manager

#undef debug
#include <iostream>
#include <list>
#include <string>
#include <map>
using namespace std;

template<typename T>
class BSTNode{
public:
    
    // Constructors, etc.
    BSTNode() : _data(0), _left(nullptr), _right(nullptr) {} // default constructor
    BSTNode(T data) : _left(nullptr), _right(nullptr) { _data = data; } // value constructor
    BSTNode(BSTNode&); // copy constructor
    ~BSTNode(); // destructor
    BSTNode& operator=(BSTNode&); // copy assignment operator
    // ***** Your group will define/implement the insert function
    // ***** at about line 89 below...
    void insert(const T& data);
    // Accessor and mutator functions
    BSTNode<T>* getLeft() const { return _left; }
    BSTNode<T>* getRight() const { return _right; }
    T& getData() const { return _data; }
    
    void setData(const T& data) { _data = data; }
    // Display functions used by operator<<.
    // ***** Your group will define/implement the pre & post display functions
    // ***** at about lines 114 & 127 below...
    void inOrderDisplay(ostream&) const;
    void preOrderDisplay(ostream&) const;
    void postOrderDisplay(ostream&) const;
    
    void listify(list<T>&) const;
    // The insertion operator below uses in-order display.
    // ***** Change the implementation of this insertion operator
    // ***** in order to switch to pre- or post-order display
    friend ostream& operator<< (ostream& out, const BSTNode<T>& b)
    
    { b.inOrderDisplay(out); return out; }
    
private:
    T _data;
    BSTNode<T>* _left;
    BSTNode<T>* _right;
    // private "helper" functions
    void addLeft(const T& data) { _left = new BSTNode(data); }
    void addRight(const T& data) { _right = new BSTNode(data); }
};

int main(void)
{
    BSTNode<int> iroot(100);
    iroot.insert(10);
    iroot.insert(20);
    iroot.insert(200);
    iroot.insert(300);
    
    cout << "iroot == " << iroot << endl;
    
    BSTNode<string> sroot("Sunday");
    
    sroot.insert("Monday");
    sroot.insert("Tuesday");
    sroot.insert("Wednesday");
    sroot.insert("Thursday");
    sroot.insert("Friday");
    sroot.insert("Saturday");
    
    cout << "sroot == " << sroot << endl;
    
    //Michael and Patricia implemented the code for
    //iroot - forward, reverse
    list<int> irootList;
    list<int>::iterator iteratorRoot;
    iroot.listify(irootList);
    
    cout << endl << "Creating irootList via iroot.listify" << endl;
    cout << endl << "irootList (forward iterator) == ";
    
    for (iteratorRoot = irootList.begin(); iteratorRoot != irootList.end(); ++iteratorRoot) {
        cout << (*iteratorRoot) << " ";
    }
    
    list<int>::reverse_iterator reverseI;
    cout << endl << "irootList (reverse iterator) == ";
    
    for (reverseI = irootList.rbegin(); reverseI != irootList.rend(); ++reverseI) {
        cout << (*reverseI) << " ";
    }
    
    //Khiel worked on the ranged for loop
    cout << endl << "irootList (ranged for loop) == ";
    
    for (int _data : irootList) {
        cout << _data << " ";
    }
    cout << endl << endl;
    
    //Yan and Michael created the sroot list
    list<string> srootList;
    list<string>::iterator iteratorS;
    sroot.listify(srootList);
    
    cout << "Creating srootList via sroot.listify" << endl;

    cout << endl << "srootList (forward iterator) == ";

    for (iteratorS = srootList.begin(); iteratorS != srootList.end(); ++iteratorS) {
        cout << (*iteratorS) << " ";
    }

    list<string>::reverse_iterator reverseS;

    cout << endl << "srootList (reverse iterator) == ";

    for (reverseS = srootList.rbegin(); reverseS != srootList.rend(); ++reverseS) {
        cout << (*reverseS) << " ";
    }

    cout << endl << "srootList (ranged for loop) == ";
    for (string _data : srootList) {
        cout << _data << " ";
    }

    //Khiel created and implemented the data/code for iroot4
    BSTNode<int> iroot4(1000);

    iroot4.insert(2000);
    iroot4.insert(3000);
    iroot4.insert(4000);
    iroot4.insert(5000);

    list<int> iroot4List;
    iroot4.listify(iroot4List);

    cout << endl << endl << "iroot4 == ";

    for (iteratorRoot = iroot4List.begin(); iteratorRoot != iroot4List.end(); ++iteratorRoot) {
        cout << (*iteratorRoot) << ", ";
    }

    cout << endl << endl;


    cout << "Creating iroot4List via iroot4.listify" << endl;
    map<string, list<int>> mi;

    mi.emplace("iroot4List", iroot4List);
    mi.emplace("irootList", irootList);

    //Patricia and Yan worked together to implement the map functionality
    cout << endl << "Contents of map<string, list<int>> mi (using ranged for loops): " << endl << "iroot4List: ";

    for (int _data : mi.at("iroot4List")) {
        cout << _data << " ";
    }

    cout << endl << "irootList: ";

    for (int _data : mi.at("irootList")) {
        cout << _data << " ";
    }
    cout << endl << endl;

    cout << "Using map index operator: " << endl;
    cout << "mi[\"irootList\"] == ";

    for (auto i : mi["irootList"]) {
        cout << i << " ";
    }
    cout << endl;

    cout << "mi[\"iroot4List\"] == ";

    for (auto i : mi["iroot4List"]) {
        cout << i << " ";
    }
    cout << endl;
    
#ifdef debug
    
    BSTNode<int> iroot2(iroot); // use copy constructor
    cout << "\nAfter copy constructor:\n";
    cout << "iroot2 == " << iroot2 << endl;
    
    BSTNode<int> iroot3;
    iroot3 = iroot2; // use copy assignment operator
    cout << "\nAfter copy assignment operator:\n";
    cout << "iroot3 == " << iroot3 << endl << endl;
    
#endif
    
    return 0;
}

template<typename T>
BSTNode<T>::BSTNode(BSTNode& b)
{
#ifdef debug
    cout << "BSTNode copy constructor called, _data == " << _data << endl;
#endif
    _data = b._data;
    
    _left = _right = nullptr;
    
    if (b._left != nullptr) _left = new BSTNode<T>(*b._left);
    
    if (b._right != nullptr) _right = new BSTNode<T>(*b._right);
}

template<typename T>
BSTNode<T>::~BSTNode()
{
#ifdef debug
    cout << "BSTNode destructor called, _data == " << _data << endl;
#endif
    delete _left;
    delete _right;
}

template<typename T>
BSTNode<T>& BSTNode<T>::operator=(BSTNode& b)
{
#ifdef debug
    cout << "BSTNode copy assignment operator: ";
#endif
    _data = b._data;
    _left = _right = nullptr;
    
    if (b._left != nullptr) _left = new BSTNode<T>(*b._left);
    
    if (b._right != nullptr) _right = new BSTNode<T>(*b._right);
    
    return *this;
}

//Patricia and Yan worked together on inset()
template<typename T>
void BSTNode<T>::insert(const T& data)
{
    BSTNode* newNode = new BSTNode<T>(data);
    
    if (data < _data)
    {
        if (_left != nullptr)
        {
            _left->insert(data);
        }
        else
        {
            _left = newNode;
        }
    }
    else
    {
        if (_right != nullptr)
        {
            _right->insert(data);
        }
        else
        {
            _right = newNode;
        }
    }
}

template<typename T>
void BSTNode<T>::inOrderDisplay(ostream& out) const
{
    if (_left != nullptr)
    {
        _left->inOrderDisplay(out);
        out << ", ";
    }
    
    out << _data;
    
    if (_right != nullptr)
    {
        out << ", ";
        _right->inOrderDisplay(out);
    }
}
/**
 * ***** Complete preOrderDisplay and postOrderDisplay below *****
 */
//Zach and Neitchie worked on preOrderDisplay
template<typename T>
void BSTNode<T>::preOrderDisplay(ostream& out) const
{
    out << _data;
    
    if (_left != nullptr)
    {
        out << ", ";
        _left->preOrderDisplay(out);
    }
    
    if (_right != nullptr)
    {
        out << ", ";
        _right->preOrderDisplay(out);
    }
}

//Neitchie and Yan worked on postOrderDisplay
template<typename T>
void BSTNode<T>::postOrderDisplay(ostream& out) const
{
    if (_left != nullptr)
    {
        _left->postOrderDisplay(out);
        out << ",";
    }
    
    if (_right != nullptr)
    {
        _right->postOrderDisplay(out);
        out << ", ";
    }
    out << _data;
}

//listify
template<typename T>
void BSTNode<T>::listify(list<T>& p) const
{
    //Patty identified the need to check the nodes were null
    //Michael and Yan worked on implementing it
    if (_left != nullptr)
    {
        _left->listify(p);
    }
    p.push_back(_data);
    
    if (_right != nullptr)
    {
        _right->listify(p);
    }
    return;
}
