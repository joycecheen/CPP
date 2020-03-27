#ifndef NODE_H
#define NODE_H

class node{
 public:
  node(int valueN, int colorN, node* leftN, node* rightN, node* parentN);
  void setValue(int valueN);
  void setColor(int colorN);
  void setLeft(node * leftN);
  void setRight(node * rightN);
  void setParent(node * parentN);
  
 private:
  int color;
  int value;
  node * left;
  node * right;
  node * parent;

};

#endif
