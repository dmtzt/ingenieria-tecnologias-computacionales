#include <vector>
#include <queue>
#include <stack>
#include "NodeT.h"

using namespace std;

class BST {
  public:
    BST();

    void add(int data);
    bool search(int data);
    void remove(int data);

    void print(int x);
    int height();
    vector<int> ancestor(int n);
    int whatLevelAmI(int n);

    /*
     * PRO08 
     * 
    */
    int nearestRelative(int n, int m);
    BST(BST& bst);
    bool operator==(BST bst);
    stack<int> toStack();
    queue<int> toAscQueue();
    queue<int> toQueue(); 

  private:
    NodeT *root;
    int howManyChildren(NodeT *r);
    int pred(NodeT *r);
    int succ(NodeT *r);

    void preOrder(NodeT *r);
    void inOrder(NodeT *r);
    void postOrder(NodeT *r);

    int getHeight(NodeT* r);
    void getAncestor(vector<int>& v, NodeT* aux, int n);
    int getLevel(NodeT* aux, int n, int& realLevel);
    void printHelper(NodeT* aux, int n);

    int relativeHelper(NodeT* aux, int n, int m);
    void maxHelper(NodeT* aux, int& curr, int& width, int& max);
    void preOrderToStack(NodeT* r, stack<int>& s);
    void preOrderToAscQueue(NodeT* r, queue<int>& q);

    void levelByLevelHelper();
    void levelByLevel(queue<NodeT*>& nodes);
};


BST::BST() {
  root = NULL;
}


bool BST::search(int data) {
  NodeT *curr = root;
  while( curr != NULL ) {
    if ( curr->getData() == data ) {
      return true;
    }
    curr = ( curr->getData() > data ) ?
        curr->getLeft() : curr->getRight();
    // if ( curr->getData() > data ) {
    //   curr = curr->getLeft();
    // } else {
    //   curr = curr->getRight();
    // }
  }
  return false;
}


void BST::add(int data) {
  NodeT *curr = root;
  NodeT *father = NULL;

  while( curr != NULL ) {
    father = curr;
    curr = ( curr->getData() > data ) ?
        curr->getLeft() : curr->getRight();
  }

  if ( father == NULL ) {
    root = new NodeT(data);
  } else {
    if ( father->getData() > data ) {
      father->setLeft(new NodeT(data));
    } else {
      father->setRight(new NodeT(data));
    }

    // ((father->getData() > data) ? 
    //   father->setLeft(new NodeT(data)) :
    //   father->setRight(new NodeT(data)))
  }
}


void BST::remove(int data) {
  NodeT *curr = root;
  NodeT *father = NULL;

  while( curr != NULL && curr->getData() != data ) {
    father = curr;
    curr = ( curr->getData() > data ) ?
        curr->getLeft() : curr->getRight();
  }
  if ( curr == NULL ) {
    return;
  }
  int c = howManyChildren(curr);
  switch(c) {
    case 0:
      if ( father == NULL ) {
        root = NULL;
      } else {
        if ( father->getData() > data ) {
          father->setLeft(NULL);
        } else {
          father->setRight(NULL);
        }
      }
      delete curr;
      break;
    case 1:
      if ( father == NULL ) {
        if( curr->getLeft() != NULL ) {
          root = curr->getLeft();
        } else {
          root = curr->getRight();
        }
      } else {
        if ( father->getData() > data ) {
          if ( curr->getLeft() != NULL ) {
            father->setLeft(curr->getLeft());
          } else {
            father->setLeft(curr->getRight());
          }
        } else {
          if ( curr->getLeft() != NULL ) {
            father->setRight(curr->getLeft());
          } else {
            father->setRight(curr->getRight());
          }
        }
      }
      delete curr;
      break;
    case 2:
      int x = succ(curr);
      remove(x);
      curr->setData(x);
      break;
  }
}


int BST::howManyChildren(NodeT *r) {
  int cont = 0;
  if ( r->getLeft() != NULL ) {
    cont++;
  }
  if ( r->getRight() != NULL) {
    cont++;
  }
  return cont;
}


int BST::pred(NodeT *r) {
  NodeT *curr = r->getLeft();
  while( curr->getRight() != NULL ) {
    curr = curr->getRight();
  }
  return curr->getData();
}

int BST::succ(NodeT *r) {
  NodeT *curr = r->getRight();
  while( curr->getLeft() != NULL ) {
    curr = curr->getLeft();
  }
  return curr->getData();
}


void BST::preOrder(NodeT *r) {
  if ( r != NULL ) {
    cout << r->getData() << " ";
    preOrder(r->getLeft());
    preOrder(r->getRight());
  }
}


void BST::inOrder(NodeT *r) {
  if ( r != NULL ) {
    inOrder(r->getLeft());
    cout << r->getData() << " ";
    inOrder(r->getRight());
  }
}


void BST::postOrder(NodeT *r) {
  if ( r != NULL ) {
    postOrder(r->getLeft());
    postOrder(r->getRight());
    cout << r->getData() << " ";
  } 
}


/*
void BST::print(int x) {
  switch(x) {
    case 1: preOrder(root);
      break;
    case 2: inOrder(root);
      break;
    case 3: postOrder(root);
      break;
  }
  cout << endl;
}
*/

int BST::height()
{
    return getHeight(root);
}

int BST::getHeight(NodeT* aux)
{
    if (aux == NULL)
        return 0;

    int left = getHeight(aux->getLeft());
    int right = getHeight(aux->getRight());

    if (left > right)
        return left + 1;
    else
        return right + 1;    
}

vector<int> BST::ancestor(int n)
{
  vector<int> ancestors;
  
  getAncestor(ancestors, root, n);
  return ancestors;
}

void BST::getAncestor(vector<int>& v, NodeT* aux, int n)
{
  int data = aux->getData();

  if (data != n)
  {
    v.push_back(data);

      if (n > data)
        getAncestor(v, aux->getRight(), n);
      else if (n < data)
        getAncestor(v, aux->getLeft(), n);
  }
}

int BST::whatLevelAmI(int n)
{
  int realLevel = 0;
  int level = getLevel(root, n, realLevel);

  if (realLevel != level)
    return -1;
  else
    return level;
}

int getLevel(NodeT* aux, int n, int& realLevel)
{
  if (aux == NULL)
    return -1;

  if (n > aux->getData())
  {
    return 1 + getLevel(aux->getRight(), n, realLevel);
    realLevel++;
  } 
  else if (n < aux->getData())
  {
    return 1 + getLevel(aux->getLeft(), n, realLevel);
    realLevel++;
  }
  else 
    return 0;
}

void BST::print(int n)
{
  printHelper(root, n);
}

void BST::printHelper(NodeT* aux, int n)
{
  cout << aux->getData() << endl;

  if (n > aux->getData())
    printHelper(aux->getRight(), n);
  else if (n < aux->getData())
    printHelper(aux->getLeft(), n);
}

/*
 * PRO08 - Operaciones de BST (parte 2)
 * 
 * nearestRelative
 * copy constructor
 * operator==
 * toQueue
 * 
 * Helper functions:
 * relativeHelper -> nearestRelative
 * preOrderToStack -> toStack -> operator==
 * preOrderToAscQueue -> toAscQueue -> copy constructor
 * toStack -> toQueue
*/

int BST::nearestRelative(int n, int m)
{
  return relativeHelper(root, n, m);
}

int BST::relativeHelper(NodeT* aux, int n, int m)
{
  // If both numbers are less than the current value, travel to left node
  if(n < aux->getData() && m < aux->getData())
    return relativeHelper(aux->getLeft(), n ,m);
  // If both numbers are greater than the current value, travel to right node
  else if(n > aux->getData() && m > aux->getData())
    return relativeHelper(aux->getRight(), n ,m);
  // Else, the current value is the nearest relative
  else
    return aux->getData();  
}

void BST::preOrderToStack(NodeT* r, stack<int>& s)
{
  if (r != NULL) {
    s.push(r->getData());
    preOrderToStack(r->getLeft(), s);
    preOrderToStack(r->getRight(), s);
  }
}

stack<int> BST::toStack()
{
  stack<int> s;
  preOrderToStack(root, s);
  return s;
}

bool BST::operator==(BST bst)
{
  stack<int> s1 = this->toStack();
  stack<int> s2 = bst.toStack();

  if (s1.size() != s2.size())
    return false;
  else
  {
    while (s1.size() != 0)
    {
      if (s1.top() != s2.top())
        return false;

      s1.pop();
      s2.pop();
    }
  }

  return true;
}

void BST::preOrderToAscQueue(NodeT* r, queue<int>& q)
{
  if (r != NULL) {
    q.push(r->getData());
    preOrderToAscQueue(r->getLeft(), q);
    preOrderToAscQueue(r->getRight(), q);
  } 
}

queue<int> BST::toAscQueue()
{
  queue<int> q;
  preOrderToAscQueue(root, q);
  return q;
}

BST::BST(BST& bst)
{
  queue<int> s = bst.toQueue();

  while (s.size() != 0)
  {
    this->add(s.front());
    s.pop();
  }
}

queue<int> BST::toQueue()
{
  queue<int> q;
  stack<int> s = this->toStack();

  while (s.size() != 0)
  {
    q.push(s.top());
    s.pop();
  }
}

void BST::levelByLevelHelper()
{
  queue<NodeT*> nodes;
  nodes.push(root);

  levelByLevel(nodes);
}

void BST::levelByLevel(queue<NodeT*>& nodes)
{
  if (!nodes.empty())
  {
    NodeT* curr = nodes.front();
    nodes.pop();

    if(curr->getLeft() != NULL)
      nodes.push(curr->getLeft());
    if (curr->getRight() != NULL)
      nodes.push(curr->getRight());

    levelByLevel(nodes);
  }
}