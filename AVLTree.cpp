#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *lchild;
    int data;
    int height; // height of a node
    struct Node *rchild;
} *root = NULL;

int NodeHeight(struct Node *p)
{
    int hl, hr;
    hl = p && p->lchild ? p->lchild->height:0;
    hr = p && p->rchild ? p->rchild->height:0;
    
    return hl > hr ? hl + 1: hr + 1;
}

int BalanceFactor(struct Node *p)
{
    int hl, hr;
    hl = p && p->lchild ? p->lchild->height:0;
    hr = p && p->rchild ? p->rchild->height:0;
    
    return hl - hr;
}

struct Node *LLrotation(struct Node *p)
{
    struct Node *pl = p->lchild;
    struct Node *plr = pl->rchild;
    
    pl->rchild = p;
    p->lchild = plr;
    
    // plr keeps height
    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);
    
    if (root == p)
    {
        root = pl;
    }
    
    return pl;
}

struct Node *LRrotation(struct Node *p)
{
    struct Node *pl = p->lchild;
    struct Node *plr = pl->rchild;

    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;

    plr->lchild = pl;
    plr->rchild = p;

    pl->height = NodeHeight(pl);
    p->height = NodeHeight(p);
    plr->height = NodeHeight(plr);

    if (root == p)
        root = plr;

    return plr;
}

struct Node *RRrotation(struct Node *p)
{
    struct Node *pr = p->rchild;
    struct Node *prl = pr->lchild;
    
    pr->lchild = p;
    p->rchild = prl;
    
    // prl keeps height
    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);
    
    if (root == p)
    {
        root = pr;
    }
    
    return pr;
}

struct Node *RLrotation(struct Node *p)
{
    struct Node *pr = p->rchild;
    struct Node *prl = pr->lchild;

    pr->lchild = prl->rchild;
    p->rchild = prl->lchild;

    prl->rchild = pr;
    prl->lchild = p;

    pr->height = NodeHeight(pr);
    p->height = NodeHeight(p);
    prl->height = NodeHeight(prl);

    if (root == p)
    {
        root = prl;
    }

    return prl;
}

struct Node *RInsert(struct Node *p, int key)
{
    if (p == NULL)
    {
        struct Node *t;
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = key;
        t->height = 1; // if leaf node, has height of 1
        t->lchild = t->rchild = NULL;
        return t;
    }
    
    if (key < p->data)
    {
        p->lchild = RInsert(p->lchild, key);
    }
    else if (key > p->data)
    {
        p->rchild = RInsert(p->rchild, key);
    }
    
    p->height = NodeHeight(p);
    
    if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1)
    {
        return LLrotation(p);
    }
    else if(BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1)
    {
        LRrotation(p);
    }
    else if(BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1)
    {
        RRrotation(p);
    }
    else if(BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 1)
    {
        RLrotation(p);
    }
    
    return p;
}

int main()
{
    root = RInsert(root, 10);
    RInsert(root, 5);
    RInsert(root, 2);
    printf("root: %d, rchild: %d, lchild: %d", root->data, root->rchild->data, root->lchild->data);
    
    return 0;
}