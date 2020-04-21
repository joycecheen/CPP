#ifndef NODE_H
#define NODE_H

class node{
 public:
  node(int valueN, int colorN, node* leftN, node* rightN, node* parentN);

  void setValue(int valueN);
  int getValue();
  void setColor(int colorN);
  int getColor();

  void setLeft(node* left);
  node* getLeft();
  void setRight(node* right);
  node* getRight();
  void setParent(node* parent);
  node* getParent();
  node* getGrandparent();
  node* getUncle();
  
 private:
  int color;
  int value;
  node* left;
  node* right;
  node* parent;

};

#endif
