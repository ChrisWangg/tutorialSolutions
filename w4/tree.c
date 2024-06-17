#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *left;
    struct node *right;
};

int max(int a, int b) {
    return (a > b) ? a : b;
}
struct node *newNode(int value) {
    struct node *new = malloc(sizeof(struct node));
    new->value = value;
    new->left = NULL;
    new->right = NULL;
    return new;
} 

struct node *insertBst(struct node *root, int value) {
    if (root == NULL) {
        return newNode(value);
    }
    if (root->value > value) {
        root->left = insertBst(root->left, value);
    }
    if (root->value < value) {
        root->right = insertBst(root->right, value);
    }
    return root;
}

int countNodes(struct node *t) {
    if (t == NULL) {
        return 0;
    }
    return 1 + countNodes(t->left) + countNodes(t->right);
}

int countOdds(struct node *t) {
    if (t == NULL) return 0;
    if (t->value % 2 == 1) {
        return 1 + countOdds(t->left) + countOdds(t->right);
    }
    return countOdds(t->left) + countOdds(t->right);
}

int bstCountInternal(struct node *t) {
    if (t == NULL) return 0;
    if (t->left == NULL && t->right == NULL) return 0;
    return 1 + bstCountInternal(t->left) + bstCountInternal(t->right);
}

int bstHeight(struct node *t) {
    if (t == NULL) return -1;
    int lh = bstHeight(t->left);
    int rh = bstHeight(t->right);

    return max(lh, rh) + 1;
}
int bstNodeLevel(struct node *t, int key) { 
    if (t == NULL) {
		return -1;
	} else if (t->value == key) {
		return 0;
	} else if (key < t->value) {
		int level = bstNodeLevel(t->left, key);
		if (level == -1) return -1;
		return level + 1;
	} else {
		int level = bstNodeLevel(t->right, key);
		if (level == -1) return -1;
		return level + 1;
	}
}
int bstCountGreater(struct node *t, int val) { 
    if (t == NULL) {
		return 0;
	} else if (t->value > val) {
		return 1 + bstCountGreater(t->left, val) + bstCountGreater(t->right, val);
	} else {
		return bstCountGreater(t->right, val);
	}
}


int main(void) {
    struct node *t = NULL;
    t = insertBst(t, 2);
    t = insertBst(t, 1);
    t = insertBst(t, 3);
    printf("Count of nodes %d\n", countNodes(t));
    printf("Count of odd nodes %d\n", countOdds(t));
    printf("Count of internal nodes %d\n", bstCountInternal(t));
    printf("Height %d\n", bstHeight(t));
}