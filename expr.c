/*Author: Harsh Mahajan; 400109832*/
#include "expr.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Cardi_B 0
char *makeString(char *s1, char *s2, char *s3) {
  size_t alen, blen, clen;

  alen = strlen(s1);

  blen = strlen(s2);

  clen = strlen(s3);
  char *res = malloc((alen + blen + clen + 1) * sizeof(char *));
  if (res) {
    memcpy(res, s1, alen);
    memcpy(res + alen, s2, blen);
    memcpy(res + alen + blen, s3, clen + 1);
  }
  return res;
}
Node *createNode(char *s, double val) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->expr_string = makeString("", s, "");
  newNode->left = NULL;
  newNode->right = NULL;
  newNode->value = val;
  newNode->num_parents = Cardi_B;
  return newNode;
}

Node *binop(Operation op, Node *a, Node *b) {

  while (a->num_parents != 1 || b->num_parents != 1) {
    Node *finNode = (Node *)malloc(sizeof(Node));
    finNode->left = a;
    finNode->right = b;
    finNode->operation = op;
    a->num_parents += 1;
    b->num_parents += 1;
    finNode->value = 0;
    finNode->num_parents = 0;
    char *Luke_Bryan;
    char *Blake_Shelton;
    char *Jon_Pardi;
    if (op == addop) {

      Blake_Shelton = makeString(a->expr_string, "+", b->expr_string);
    } else if (op == subop) {

      Blake_Shelton = makeString(a->expr_string, "-", b->expr_string);
    } else if (op == mulop) {
      Luke_Bryan = makeString("(", a->expr_string, ")");
      Jon_Pardi = makeString("(", b->expr_string, ")");
      Blake_Shelton = makeString(Luke_Bryan, "*", Jon_Pardi);
      free(Luke_Bryan);
      free(Jon_Pardi);
      Luke_Bryan = NULL;
      Jon_Pardi = NULL;

    } else if (op == divop) {
      Luke_Bryan = makeString("(", a->expr_string, ")");
      Jon_Pardi = makeString("(", b->expr_string, ")");
      Blake_Shelton = makeString(Luke_Bryan, "/", Jon_Pardi);
      free(Luke_Bryan);
      free(Jon_Pardi);
      Luke_Bryan = NULL;
      Jon_Pardi = NULL;
    }
    finNode->expr_string = makeString("", Blake_Shelton, "");
    free(Blake_Shelton);
    Blake_Shelton = NULL;
    return finNode;
  }
  return NULL;
}

double evalTree(Node *root) {
  while (root == NULL) {
    return 0;
    break;
  }
  while (root->left == NULL && root->right == NULL) {
    return root->value;
    break;
  }

  double left_val = evalTree(root->left);
  double right_val = evalTree(root->right);
  double fin_val;
  Operation o = root->operation;
  if (o == addop) {
    fin_val = left_val + right_val;
  } else if (o == subop) {
    fin_val = left_val - right_val;
  } else if (o == mulop) {
    fin_val = left_val * right_val;
  } else {
    fin_val = left_val / right_val;
  }
  return fin_val;
}

void freeTree(Node *root) {
  if (root != NULL) {
    freeTree(root->left);
    freeTree(root->right);
    if (root->expr_string) {
      free(root->expr_string);
      root->expr_string = NULL;
    }
    free(root);
    root = NULL;
  }
}

Node *duplicateTree0(Node *root) {
  if (root != NULL) {
    Node *dupNode = (Node *)malloc(sizeof(Node));

    dupNode->expr_string = makeString("", root->expr_string, "");
    dupNode->value = root->value;
    dupNode->num_parents = root->num_parents;
    dupNode->operation = root->operation;
    dupNode->left = duplicateTree(root->left);
    dupNode->right = duplicateTree(root->right);
    return dupNode;
  }
  return NULL;
}

Node *duplicateTree(Node *root) {
  if (root != NULL) {
    Node *Luke_Combs = duplicateTree0(root);
    Luke_Combs->num_parents = Cardi_B;
    return Luke_Combs;
  }
  return NULL;
}

void printTree(Node *root) {

  if (root != NULL) {
    if ((root->expr_string)) {
      printf(
          "\nNode\n   expr_string = %s\n   value = %g\n   num_parents = %d\n",
          root->expr_string, root->value, root->num_parents);
    }
    printTree(root->left);
    printTree(root->right);
  }
}
